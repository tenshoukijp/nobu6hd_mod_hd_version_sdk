#include <windows.h>

#include "version.h"

FARPROC p_GetFileVersionInfoA;
FARPROC p_GetFileVersionInfoByHandle;
FARPROC p_GetFileVersionInfoExA;
FARPROC p_GetFileVersionInfoExW;
FARPROC p_GetFileVersionInfoSizeA;
FARPROC p_GetFileVersionInfoSizeExA;
FARPROC p_GetFileVersionInfoSizeExW;
FARPROC p_GetFileVersionInfoSizeW;
FARPROC p_GetFileVersionInfoW;
FARPROC p_VerFindFileA;
FARPROC p_VerFindFileW;
FARPROC p_VerInstallFileA;
FARPROC p_VerInstallFileW;
FARPROC p_VerLanguageNameA;
FARPROC p_VerLanguageNameW;
FARPROC p_VerQueryValueA;
FARPROC p_VerQueryValueW;


BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	static HINSTANCE hOrigVersionDLL = NULL;

	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:

			// システムの方にある、本物のversionのdllハンドル確保
			static char pathsysdirname[MAX_PATH];
			GetSystemDirectory(pathsysdirname, MAX_PATH);
			static char versionpathname[MAX_PATH];
			wsprintf(versionpathname,"%s\\version.dll", pathsysdirname);
			hOrigVersionDLL = LoadLibrary(versionpathname);
			if (hOrigVersionDLL == NULL) {
				return FALSE;
			}
			// 各関数確保
			p_GetFileVersionInfoA = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoA");
			p_GetFileVersionInfoByHandle = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoByHandle");
			p_GetFileVersionInfoExA = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoExA");
			p_GetFileVersionInfoExW = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoExW");
			p_GetFileVersionInfoSizeA = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoSizeA");
			p_GetFileVersionInfoSizeExA = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoSizeExA");
			p_GetFileVersionInfoSizeExW = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoSizeExW");
			p_GetFileVersionInfoSizeW = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoSizeW");
			p_GetFileVersionInfoW = GetProcAddress(hOrigVersionDLL, "GetFileVersionInfoW");
			p_VerFindFileA = GetProcAddress(hOrigVersionDLL, "VerFindFileA");
			p_VerFindFileW = GetProcAddress(hOrigVersionDLL, "VerFindFileW");
			p_VerInstallFileA = GetProcAddress(hOrigVersionDLL, "VerInstallFileA");
			p_VerInstallFileW = GetProcAddress(hOrigVersionDLL, "VerInstallFileW");
			p_VerLanguageNameA = GetProcAddress(hOrigVersionDLL, "VerLanguageNameA");
			p_VerLanguageNameW = GetProcAddress(hOrigVersionDLL, "VerLanguageNameW");
			p_VerQueryValueA = GetProcAddress(hOrigVersionDLL, "VerQueryValueA");
			p_VerQueryValueW = GetProcAddress(hOrigVersionDLL, "VerQueryValueW");
			break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:

		p_OnFinalize();
		FreeLibrary(hTSHDVersionDLL);
		FreeLibrary(hOrigVersionDLL);

		break;
	default:
		break;
	}
	return TRUE;
}
