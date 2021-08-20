/**
 * \brief   plugin - hooks
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

//--------------------------------------------------------------------------------------------------

#include "hooks.hpp"
#include "imports.hpp"

//--------------------------------------------------------------------------------------------------

void __stdcall hooks::main_menu::on_selected()
{
}

//--------------------------------------------------------------------------------------------------

BOOL __stdcall hooks::memory_view::on_selected(UINT_PTR* disassembleraddress, UINT_PTR* selected_disassembler_address, UINT_PTR* hexviewaddress)
{
	return TRUE;
}

//--------------------------------------------------------------------------------------------------

BOOL __stdcall hooks::address_list::on_selected(PADDRESSLIST_RECORD SelectedRecord)
{
	return TRUE;
}

//--------------------------------------------------------------------------------------------------

void __stdcall hooks::process_watcher::on_selected(ULONG processid, ULONG peprocess, BOOL Created)
{
}

//--------------------------------------------------------------------------------------------------

void __stdcall hooks::pointer_assignment::on_selected(int reserved)
{
}

//--------------------------------------------------------------------------------------------------

int __stdcall hooks::debug_event::on_selected(LPDEBUG_EVENT DebugEvent)
{
	return 0;
}

//--------------------------------------------------------------------------------------------------

BOOL __stdcall hooks::disassembler_context::on_selected(ULONG* selectedAddress)
{
	return TRUE;
}

BOOL __stdcall hooks::disassembler_context::on_popup(UINT_PTR selectedAddress, char** addressofname, BOOL* show)
{
	return TRUE;
}

//--------------------------------------------------------------------------------------------------

void __stdcall hooks::disassembler_line::on_selected(UINT_PTR address, char** addressStringPointer, char** bytestringpointer, char** opcodestringpointer, char** specialstringpointer, ULONG* textcolor)
{
}

//--------------------------------------------------------------------------------------------------

void __stdcall hooks::auto_assembler::on_selected(char** line, AutoAssemblerPhase phase, int id)
{
}
