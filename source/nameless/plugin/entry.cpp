/**
 * \brief   plugin - entry
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

//--------------------------------------------------------------------------------------------------

#include "exports.hpp"
#include "plugin.hpp"
#include "details.hpp"
#include "hooks.hpp"
#include "../hide/hide.hpp"
#include "dependencies.hpp"

//--------------------------------------------------------------------------------------------------

extern _plugin plugin{};
extern _hide hide{};

//--------------------------------------------------------------------------------------------------

extern BOOL __stdcall CEPlugin_GetVersion(PPluginVersion pv, int size_of_plugin_version)
{
	pv->version = CESDK_VERSION;
	pv->pluginname = PLUGIN_DESCRIPTION;
	return TRUE;
}

extern BOOL __stdcall CEPlugin_InitializePlugin(PExportedFunctions ef, int plugin_id)
{
	plugin.plugin_id = plugin_id;
	plugin.exported = *ef;

	if (plugin.plugin_id == -1)
	{
		return FALSE;
	}

	if (plugin.exported.sizeofExportedFunctions != sizeof(imports::exported))
	{
		return FALSE;
	}

	if (!plugin.setup())
	{
		return FALSE;
	}

	//

	hide.set_settings(plugin.settings);

	if (!hide.enable())
	{
		hide.disable();
		return FALSE;
	}

	//

	plugin.status = true;
	return TRUE;
}

extern BOOL __stdcall CEPlugin_DisablePlugin(void)
{
	plugin.status = false;
	plugin.unregister();
	//

	hide.disable();

	//
	return TRUE;
}

//--------------------------------------------------------------------------------------------------

BOOL APIENTRY DllMain(HANDLE h_module, DWORD  ul_reason_for_call, LPVOID lp_reserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		return TRUE;
	}
	default:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	{
		break;
	}
	}

	return TRUE;
}
