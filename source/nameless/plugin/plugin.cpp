/**
 * \brief   plugin - imports
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

//--------------------------------------------------------------------------------------------------

#include "plugin.hpp"
#include "details.hpp"

#include "ini/INIReader.h"

//--------------------------------------------------------------------------------------------------

bool _plugin::setup()
{
	INIReader reader(PLUGIN_NAME ".ini");

	if (reader.ParseError() != 0)
	{
		return false;
	}

	settings.random_generation = reader.GetBoolean("settings", "random_generation", true);
	settings.refresh_rate_ms = reader.GetInteger("settings", "refresh_rate_ms", 1500);
	settings.window_name = reader.Get("settings", "window_name", "Firefox");

	return true;
}

bool _plugin::main_menu(MAINMENUPLUGIN_INIT main_menu)
{
	const int main_menu_id = exported.RegisterFunction(plugin_id, ptMainMenu, &main_menu);
	main_menu_ids.push_back(main_menu_id);
	return (main_menu_id > -1) ? true : false;
}

bool _plugin::memory_view(MEMORYVIEWPLUGIN_INIT memory_view)
{
	const int memory_view_id = exported.RegisterFunction(plugin_id, ptMemoryView, &memory_view);
	memory_view_ids.push_back(memory_view_id);
	return (memory_view_id > -1) ? true : false;
}

bool _plugin::address_list(ADDRESSLISTPLUGIN_INIT address_list)
{
	const int address_list_id = exported.RegisterFunction(plugin_id, ptAddressList, &address_list);
	address_list_ids.push_back(address_list_id);
	return (address_list_id > -1) ? true : false;
}

bool _plugin::process_watcher(PROCESSWATCHERPLUGIN_INIT process_watcher)
{
	const int process_watcher_id = exported.RegisterFunction(plugin_id, ptProcesswatcherEvent, &process_watcher);
	process_watcher_ids.push_back(process_watcher_id);
	return (process_watcher_id > -1) ? true : false;
}

bool _plugin::pointer_assignment(POINTERREASSIGNMENTPLUGIN_INIT pointer_assignment)
{
	const int pointer_assignment_id = exported.RegisterFunction(plugin_id, ptFunctionPointerchange, &pointer_assignment);
	pointer_assignment_ids.push_back(pointer_assignment_id);
	return (pointer_assignment_id > -1) ? true : false;
}

bool _plugin::debug_event(DEBUGEVENTPLUGIN_INIT debug_event)
{
	const int debug_event_id = exported.RegisterFunction(plugin_id, ptOnDebugEvent, &debug_event);
	debug_event_ids.push_back(debug_event_id);
	return (debug_event_id > -1) ? true : false;
}

bool _plugin::disassembler_context(DISASSEMBLERCONTEXT_INIT disassembler_context)
{
	const int disassembler_context_id = exported.RegisterFunction(plugin_id, ptDisassemblerContext, &disassembler_context);
	disassembler_context_ids.push_back(disassembler_context_id);
	return (disassembler_context_id > -1) ? true : false;
}

bool _plugin::disassembler_line(DISASSEMBLERLINEPLUGIN_INIT disassembler_line)
{
	const int disassembler_line_id = exported.RegisterFunction(plugin_id, ptDisassemblerRenderLine, &disassembler_line);
	disassembler_line_ids.push_back(disassembler_line_id);
	return (disassembler_line_id > -1) ? true : false;
}

bool _plugin::auto_assembler(AUTOASSEMBLERPLUGIN_INIT auto_assembler)
{
	const int auto_assembler_id = exported.RegisterFunction(plugin_id, ptAutoAssembler, &auto_assembler);
	auto_assembler_ids.push_back(auto_assembler_id);
	return (auto_assembler_id > -1) ? true : false;
}

bool _plugin::unregister()
{
	for (int i : main_menu_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	main_menu_ids.clear();
	//
	for (int i : memory_view_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	memory_view_ids.clear();
	//
	for (int i : address_list_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	address_list_ids.clear();
	//
	for (int i : process_watcher_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	process_watcher_ids.clear();
	//
	for (int i : pointer_assignment_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	pointer_assignment_ids.clear();
	//
	for (int i : debug_event_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	debug_event_ids.clear();
	//
	for (int i : disassembler_context_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	disassembler_context_ids.clear();
	//
	for (int i : disassembler_line_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	disassembler_line_ids.clear();
	//
	for (int i : auto_assembler_ids)
	{
		exported.UnregisterFunction(plugin_id, i);
	}
	auto_assembler_ids.clear();
	//
	return true;
}
