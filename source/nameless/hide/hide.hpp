/**
 * \brief   hide
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */


#pragma once

#include "../plugin/settings.hpp"

#include <Windows.h>

#include <utility>

//

class _hide
{
private:
	HANDLE h_thread_;
	_settings settings_;

	void title_changer();
	DWORD thread_loop();

	static DWORD WINAPI thread_handler(void* param);


public:
	bool status = false;

	_hide(_settings settings): h_thread_(nullptr), settings_(std::move(settings)) {}
	_hide() : h_thread_(nullptr), settings_() {}

	void set_settings(_settings settings);

	bool enable();
	bool disable();
};
