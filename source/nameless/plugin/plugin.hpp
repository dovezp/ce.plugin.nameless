/**
 * \brief   plugin - imports
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

//--------------------------------------------------------------------------------------------------

#pragma once

#include "imports.hpp"
#include "settings.hpp"

#include <ce/cepluginsdk.h>

//--------------------------------------------------------------------------------------------------

class _plugin : public imports
{
public:
	_plugin(): status(false), settings()
	{}

	bool status;
	_settings settings;

	// setup
	bool setup();

	// register / unregister plugin
	bool main_menu(MAINMENUPLUGIN_INIT main_menu);
	bool memory_view(MEMORYVIEWPLUGIN_INIT memory_view);
	bool address_list(ADDRESSLISTPLUGIN_INIT address_list);
	bool process_watcher(PROCESSWATCHERPLUGIN_INIT process_watcher);
	bool pointer_assignment(POINTERREASSIGNMENTPLUGIN_INIT pointer_assignment);
	bool debug_event(DEBUGEVENTPLUGIN_INIT  debug_event);
	bool disassembler_context(DISASSEMBLERCONTEXT_INIT disassembler_context);
	bool disassembler_line(DISASSEMBLERLINEPLUGIN_INIT disassembler_line);
	bool auto_assembler(AUTOASSEMBLERPLUGIN_INIT auto_assembler);
	bool unregister();
};

