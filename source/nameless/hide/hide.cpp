/**
 * \brief   hide
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */


#include "hide.hpp"

#include <Windows.h>

#include <algorithm>
#include <iostream>
#include <ctime>
#include <random>

#include "../plugin/imports.hpp"

//--------------------------------------------------------------------------------------------------

std::string random_string(const unsigned int len)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"\"\';:?>.<,~`!@#$%^&*()/\\+=_-";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(len, 0);
	std::generate_n(str.begin(), len, randchar);
	return str;

}


unsigned int random_uint()
{
	std::default_random_engine rng(std::random_device{}());
	std::uniform_int_distribution<> dist(0, CHAR_MAX - 1);
	return dist(rng);
}


void get_all_pid_windows(DWORD dw_process_id, std::vector <HWND> &vh_wnds)
{
	HWND h_cur_wnd = nullptr;
	do
	{
		h_cur_wnd = FindWindowEx(nullptr, h_cur_wnd, nullptr, nullptr);
		DWORD check_process_id = 0;
		GetWindowThreadProcessId(h_cur_wnd, &check_process_id);
		if (check_process_id == dw_process_id)
		{
			vh_wnds.push_back(h_cur_wnd);
		}
	} while (h_cur_wnd != nullptr);
}

//--------------------------------------------------------------------------------------------------

void _hide::title_changer()
{
	std::string new_title = "";
	if (settings_.random_generation == true)
	{
		new_title = random_string(random_uint());
	}
	else
	{
		new_title = settings_.window_name;
	}

	std::vector <HWND> host_hwnds;

	get_all_pid_windows(GetCurrentProcessId(), host_hwnds);

	for (auto i : host_hwnds)
	{
		SetWindowTextA(i, new_title.c_str());
	}
}

DWORD _hide::thread_loop()
{
	while (this->status)
	{
		title_changer();
		Sleep(settings_.refresh_rate_ms);
	}
	return this->status;
}

DWORD _hide::thread_handler(void* param)
{
	_hide* _this = (_hide*)param;
	return _this->thread_loop();
}

//--------------------------------------------------------------------------------------------------

void _hide::set_settings(_settings settings)
{
	settings_ = std::move(settings);
}

//--------------------------------------------------------------------------------------------------

bool _hide::enable()
{
	this->status = true;
	DWORD thread_id;
	if ((this->h_thread_ = CreateThread(nullptr, 0, thread_handler, (void*) this, 0, &thread_id)) == nullptr)
	{
		return false;
	}
	return this->status;
}

bool _hide::disable()
{
	this->status = false;
	return CloseHandle(this->h_thread_);
}
