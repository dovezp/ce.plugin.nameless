/**
 * \brief   plugin - imports
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "dependencies.hpp"

//--------------------------------------------------------------------------------------------------

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define _THIS_ ((HINSTANCE)&__ImageBase)

//--------------------------------------------------------------------------------------------------

class imports
{
public:
	imports() : plugin_id(-1),
				main_menu_ids(),
				memory_view_ids(),
				address_list_ids(),
				process_watcher_ids(),
				pointer_assignment_ids(),
				debug_event_ids(),
				disassembler_context_ids(),
				disassembler_line_ids(),
				auto_assembler_ids(),
				exported()
	{
	}

	int plugin_id;
	std::vector<int> main_menu_ids;
	std::vector<int> memory_view_ids;
	std::vector<int> address_list_ids;
	std::vector<int> process_watcher_ids;
	std::vector<int> pointer_assignment_ids;
	std::vector<int> debug_event_ids;
	std::vector<int> disassembler_context_ids;
	std::vector<int> disassembler_line_ids;
	std::vector<int> auto_assembler_ids;

	ExportedFunctions exported;
};

//--------------------------------------------------------------------------------------------------
