/**
 * \brief   plugin - exports
 * \author  dovezp
 * \contact https://github.com/dovezp
 * \version 2020/OCT/24
 * \license BSD 3-Clause "New" or "Revised" License
 */

//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#ifdef _WIN64
#pragma comment(linker, "/EXPORT:CEPlugin_GetVersion=?CEPlugin_GetVersion@@YAHPEAU_PluginVersion@@H@Z")
#pragma comment(linker, "/EXPORT:CEPlugin_InitializePlugin=?CEPlugin_InitializePlugin@@YAHPEAU_ExportedFunctions@@H@Z")
#pragma comment(linker, "/EXPORT:CEPlugin_DisablePlugin=?CEPlugin_DisablePlugin@@YAHXZ")
#else //x86
#pragma comment(linker, "/EXPORT:CEPlugin_GetVersion=?CEPlugin_GetVersion@@YGHPAU_PluginVersion@@H@Z")
#pragma comment(linker, "/EXPORT:CEPlugin_InitializePlugin=?CEPlugin_InitializePlugin@@YGHPAU_ExportedFunctions@@H@Z")
#pragma comment(linker, "/EXPORT:CEPlugin_DisablePlugin=?CEPlugin_DisablePlugin@@YGHXZ")
#endif

//--------------------------------------------------------------------------------------------------

