/**
 * \brief   plugin - hooks
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

namespace hooks
{
	namespace main_menu
	{
		// CEP_PLUGINTYPE5
		void __stdcall on_selected(void);
	}

	namespace memory_view
	{
		// CEP_PLUGINTYPE1
		BOOL __stdcall on_selected(UINT_PTR *disassembleraddress, UINT_PTR *selected_disassembler_address, UINT_PTR *hexviewaddress);
	}

	namespace address_list
	{
		// CEP_PLUGINTYPE0
		BOOL __stdcall on_selected(PADDRESSLIST_RECORD SelectedRecord);
	}

	namespace process_watcher
	{
		// CEP_PLUGINTYPE3
		void __stdcall on_selected(ULONG processid, ULONG peprocess, BOOL Created);
	}

	namespace pointer_assignment
	{
		// CEP_PLUGINTYPE4
		void __stdcall on_selected(int reserved);
	}

	namespace debug_event
	{
		// CEP_PLUGINTYPE2
		int __stdcall on_selected(LPDEBUG_EVENT DebugEvent);
	}

	namespace disassembler_context
	{
		// CEP_PLUGINTYPE6
		BOOL __stdcall on_selected(ULONG *selectedAddress);
		// CEP_PLUGINTYPE6ONPOPUP
		BOOL __stdcall on_popup(UINT_PTR selectedAddress, char **addressofname, BOOL *show);
	}

	namespace disassembler_line
	{
		// CEP_PLUGINTYPE7
		void __stdcall on_selected(UINT_PTR address, char **addressStringPointer, char **bytestringpointer, char **opcodestringpointer, char **specialstringpointer, ULONG *textcolor);
	}

	namespace auto_assembler
	{
		// CEP_PLUGINTYPE8
		void __stdcall on_selected(char **line, AutoAssemblerPhase phase, int id);
	}
}
