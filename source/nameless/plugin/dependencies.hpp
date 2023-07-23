/**
 * \brief   plugin - dependencies
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

#pragma once

//--------------------------------------------------------------------------------------------------

#include "ce/cepluginsdk.h"

#include <cstdio>
#include <vector>
#include <string>
#include <iterator>

#define CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <TlHelp32.h>
#include <windowsx.h>
#include <wincrypt.h>
#include <winnt.h>
#include <intrin.h>
#include <malloc.h>
#include <tchar.h>

#define STRSAFE_NO_DEPRECATE
#include <strsafe.h>
#include <Psapi.h>

//--------------------------------------------------------------------------------------------------

#ifdef _WIN64
#pragma comment(lib, "ce/lua53-64.lib")
#pragma comment(lib, "Psapi.lib")
#else //x86
#pragma comment(lib, "ce/lua53-32.lib")
#pragma comment(lib, "Psapi.lib")
#endif
