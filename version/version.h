#pragma once

#include <windows.h>

#include "const_def.h"

extern FARPROC p_GetFileVersionInfoA;
extern FARPROC p_GetFileVersionInfoByHandle;
extern FARPROC p_GetFileVersionInfoExA;
extern FARPROC p_GetFileVersionInfoExW;
extern FARPROC p_GetFileVersionInfoSizeA;
extern FARPROC p_GetFileVersionInfoSizeExA;
extern FARPROC p_GetFileVersionInfoSizeExW;
extern FARPROC p_GetFileVersionInfoSizeW;
extern FARPROC p_GetFileVersionInfoW;
extern FARPROC p_VerFindFileA;
extern FARPROC p_VerFindFileW;
extern FARPROC p_VerInstallFileA;
extern FARPROC p_VerInstallFileW;
extern FARPROC p_VerLanguageNameA;
extern FARPROC p_VerLanguageNameW;
extern FARPROC p_VerQueryValueA;
extern FARPROC p_VerQueryValueW;

using PFNONINITIALIZE = void (WINAPI *)(void *);
extern PFNONINITIALIZE p_OnInitialize;

using PFNONFINALIZE = void (WINAPI *)();
extern PFNONFINALIZE p_OnFinalize;

extern HMODULE hTSHDVersionDLL;
