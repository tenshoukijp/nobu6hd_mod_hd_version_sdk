/*----------------------------------------------------------------*
HOOK系宣言
*----------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////
// APIフック
/////////////////////////////////////////////////////////////////////

#define WIN32_LEAN_AND_MEAN
#define STRICT

#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <dbghelp.h>
#include <mmsystem.h>
#include <shellapi.h>


// ImageDirectoryEntryToData
#pragma comment(lib, "dbghelp.lib")



// ひとつのモジュールに対してAPIフックを行う関数
static void ReplaceIATEntryInOneMod(
	PCSTR pszModuleName,
	PROC pfnCurrent,
	PROC pfnNew,
	HMODULE hmodCaller)
{
	ULONG ulSize;
	PIMAGE_IMPORT_DESCRIPTOR pImportDesc;
	pImportDesc = (PIMAGE_IMPORT_DESCRIPTOR)ImageDirectoryEntryToData(
		hmodCaller, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &ulSize);

	if (pImportDesc == NULL)
		return;

	while (pImportDesc->Name) {
		PSTR pszModName = (PSTR)((PBYTE)hmodCaller + pImportDesc->Name);
		if (lstrcmpiA(pszModName, pszModuleName) == 0)
			break;
		pImportDesc++;
	}

	if (pImportDesc->Name == 0)
		return;

	PIMAGE_THUNK_DATA pThunk = (PIMAGE_THUNK_DATA)
		((PBYTE)hmodCaller + pImportDesc->FirstThunk);

	while (pThunk->u1.Function) {
		PROC *ppfn = (PROC*)&pThunk->u1.Function;
		BOOL fFound = (*ppfn == pfnCurrent);
		if (fFound) {
			DWORD dwDummy;
			VirtualProtect(ppfn, sizeof(ppfn), PAGE_EXECUTE_READWRITE, &dwDummy);
			WriteProcessMemory(
				GetCurrentProcess(), ppfn, &pfnNew, sizeof(pfnNew), NULL);
			return;
		}
		pThunk++;
	}
	return;
}

// すべてのモジュールに対してAPIフックを行う関数
void ReplaceIATEntryInAllMods(
	PCSTR pszModuleName,
	PROC pfnCurrent,
	PROC pfnNew)
{
	// モジュールリストを取得
	HANDLE hModuleSnap = CreateToolhelp32Snapshot(
		TH32CS_SNAPMODULE, GetCurrentProcessId());
	if (hModuleSnap == INVALID_HANDLE_VALUE)
		return;

	MODULEENTRY32 me;
	me.dwSize = sizeof(me);
	BOOL bModuleResult = Module32First(hModuleSnap, &me);
	// それぞれのモジュールに対してReplaceIATEntryInOneModを実行
	while (bModuleResult) {
		ReplaceIATEntryInOneMod(pszModuleName, pfnCurrent, pfnNew, me.hModule);
		bModuleResult = Module32Next(hModuleSnap, &me);
	}
	CloseHandle(hModuleSnap);
}

//------------------------------------------------------------------------------------------------------------------------------


/*----------------------------------------------------------------*
HOOK系処理
*----------------------------------------------------------------*/
extern void HookFuncsUser32();
extern void HookFuncsKernel32();
extern void HookFuncsGdi32();
void HookFuncs() {

	static bool isHookFunctions = false;
	if (!isHookFunctions) {
		isHookFunctions = true;
	}

	HookFuncsUser32();
	HookFuncsKernel32();
	HookFuncsGdi32();

}

/*

	CALL DWORD PTR DS : [<&ADVAPI32.CryptAcquireContextA>  advapi32.CryptAcquireContextA
	CALL DWORD PTR DS : [<&ADVAPI32.CryptCreateHash>]      advapi32.CryptCreateHash
	CALL DWORD PTR DS : [<&ADVAPI32.CryptDestroyHash>]     advapi32.CryptDestroyHash
	CALL DWORD PTR DS : [<&ADVAPI32.CryptGetHashParam>]    advapi32.CryptGetHashParam
	CALL DWORD PTR DS : [<&ADVAPI32.CryptHashData>]        advapi32.CryptHashData
	CALL DWORD PTR DS : [<&ADVAPI32.CryptImportKey>]       advapi32.CryptImportKey
	CALL DWORD PTR DS : [<&ADVAPI32.CryptReleaseContext>]  advapi32.CryptReleaseContext
	CALL DWORD PTR DS : [<&ADVAPI32.CryptVerifySignatureA  advapi32.CryptVerifySignatureA
	CALL DWORD PTR DS : [<&ADVAPI32.AllocateAndInitialize  advapi32.AllocateAndInitializeSid
	CALL DWORD PTR DS : [<&ADVAPI32.EqualSid>]             advapi32.EqualSid
	CALL DWORD PTR DS : [<&ADVAPI32.FreeSid>]              advapi32.FreeSid

	CALL DWORD PTR DS : [<&CRYPT32.CryptBinaryToStringA>]  CRYPT32.CryptBinaryToStringA
	CALL DWORD PTR DS : [<&CRYPT32.CryptStringToBinaryA>]  CRYPT32.CryptStringToBinaryA


	CALL DWORD PTR DS : [<&KERNEL32.AreFileApisANSI>]      KERNELBA.AreFileApisANSI
	CALL DWORD PTR DS : [<&KERNEL32.CloseHandle>]          KERNELBA.CloseHandle
	CALL DWORD PTR DS : [<&KERNEL32.CreateDirectoryA>]     KERNELBA.CreateDirectoryA
	CALL DWORD PTR DS : [<&KERNEL32.CreateEventA>]         KERNELBA.CreateEventA
	CALL DWORD PTR DS : [<&KERNEL32.CreateEventW>]         KERNELBA.CreateEventW
	CALL DWORD PTR DS : [<&KERNEL32.CreateMutexA>]         KERNELBA.CreateMutexA
	CALL DWORD PTR DS : [<&KERNEL32.CreateSemaphoreW>]     KERNELBA.CreateSemaphoreW
	CALL DWORD PTR DS : [<&KERNEL32.DebugBreak>]           KERNELBA.DebugBreak
	CALL DWORD PTR DS : [<&KERNEL32.DeleteFileA>]          KERNELBA.DeleteFileA
	CALL DWORD PTR DS : [<&KERNEL32.DuplicateHandle>]      KERNELBA.DuplicateHandle
	CALL DWORD PTR DS : [<&KERNEL32.FatalAppExitA>]        KERNELBA.FatalAppExitA
	CALL DWORD PTR DS : [<&KERNEL32.FileTimeToLocalFileTi  KERNELBA.FileTimeToLocalFileTime
	CALL DWORD PTR DS : [<&KERNEL32.FileTimeToSystemTime>  KERNELBA.FileTimeToSystemTime
	CALL DWORD PTR DS : [<&KERNEL32.FindClose>]            KERNELBA.FindClose
	CALL DWORD PTR DS : [<&KERNEL32.FindFirstFileA>]       KERNELBA.FindFirstFileA
	CALL DWORD PTR DS : [<&KERNEL32.FindNextFileA>]        KERNELBA.FindNextFileA
	CALL DWORD PTR DS : [<&KERNEL32.FlushFileBuffers>]     KERNELBA.FlushFileBuffers
	CALL DWORD PTR DS : [<&KERNEL32.FreeLibrary>]          gameover.5CD10050
	CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryA>]         gameover.5CD10210
	CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryExW>]       gameover.5CD103B0
	CALL DWORD PTR DS : [<&KERNEL32.LoadLibraryW>]         gameover.5CD10460
	CALL DWORD PTR DS : [<&KERNEL32.GetACP>]               KERNELBA.GetACP
	CALL DWORD PTR DS : [<&KERNEL32.GetCommandLineA>]      KERNELBA.GetCommandLineA
	CALL DWORD PTR DS : [<&KERNEL32.GetConsoleCP>]         KERNELBA.GetConsoleCP
	CALL DWORD PTR DS : [<&KERNEL32.GetConsoleMode>]       KERNELBA.GetConsoleMode
	CALL DWORD PTR DS : [<&KERNEL32.GetDiskFreeSpaceA>]    KERNELBA.GetDiskFreeSpaceA
	CALL DWORD PTR DS : [<&KERNEL32.GetDiskFreeSpaceExA>]  KERNELBA.GetDiskFreeSpaceExA
	CALL DWORD PTR DS : [<&KERNEL32.GetDriveTypeA>]        KERNELBA.GetDriveTypeA
	CALL DWORD PTR DS : [<&KERNEL32.GetDriveTypeW>]        KERNELBA.GetDriveTypeW
	CALL DWORD PTR DS : [<&KERNEL32.GetEnvironmentStrings  KERNELBA.GetEnvironmentStringsW
	CALL DWORD PTR DS : [<&KERNEL32.GetFileAttributesA>]   KERNELBA.GetFileAttributesA
	CALL DWORD PTR DS : [<&KERNEL32.GetFileSize>]          KERNELBA.GetFileSize
	CALL DWORD PTR DS : [<&KERNEL32.GetFileSizeEx>]        KERNELBA.GetFileSizeEx
	CALL DWORD PTR DS : [<&KERNEL32.GetFileTime>]          KERNELBA.GetFileTime
	CALL DWORD PTR DS : [<&KERNEL32.GetFileType>]          KERNELBA.GetFileType
	CALL DWORD PTR DS : [<&KERNEL32.GetFullPathNameA>]     KERNELBA.GetFullPathNameA
	CALL DWORD PTR DS : [<&KERNEL32.GetFullPathNameW>]     KERNELBA.GetFullPathNameW
	CALL DWORD PTR DS : [<&KERNEL32.GetLastError>]         KERNELBA.GetLastError
	CALL DWORD PTR DS : [<&KERNEL32.GetLocalTime>]         KERNELBA.GetLocalTime
	CALL DWORD PTR DS : [<&KERNEL32.GetOEMCP>]             KERNELBA.GetOEMCP
	CALL DWORD PTR DS : [<&KERNEL32.GetProcessHeap>]       KERNELBA.GetProcessHeap
	CALL DWORD PTR DS : [<&KERNEL32.GetStartupInfoW>]      KERNELBA.GetStartupInfoW
	CALL DWORD PTR DS : [<&KERNEL32.GetSystemDefaultLangI  KERNELBA.GetSystemDefaultLangID
	CALL DWORD PTR DS : [<&KERNEL32.GetSystemDefaultUILan  KERNELBA.GetSystemDefaultUILanguage
	CALL DWORD PTR DS : [<&KERNEL32.GetSystemInfo>]        KERNELBA.GetSystemInfo
	CALL DWORD PTR DS : [<&KERNEL32.GetSystemTime>]        KERNELBA.GetSystemTime
	CALL DWORD PTR DS : [<&KERNEL32.GetSystemTimeAsFileTi  KERNELBA.GetSystemTimeAsFileTime
	CALL DWORD PTR DS : [<&KERNEL32.GetTempPathA>]         KERNELBA.GetTempPathA
	CALL DWORD PTR DS : [<&KERNEL32.GetUserDefaultLCID>]   KERNELBA.GetUserDefaultLCID
	CALL DWORD PTR DS : [<&KERNEL32.GetVolumeInformationA  KERNELBA.GetVolumeInformationA
	CALL DWORD PTR DS : [<&ole32.CoFreeUnusedLibraries>]   combase.CoFreeUnusedLibraries
	CALL DWORD PTR DS : [<&ole32.CoInitialize>]            ole32.CoInitialize
	CALL DWORD PTR DS : [<&ole32.CoInitializeEx>]          combase.CoInitializeEx
	CALL DWORD PTR DS : [<&ole32.CoInitializeSecurity>]    combase.CoInitializeSecurity
	CALL DWORD PTR DS : [<&ole32.CoSetProxyBlanket>]       combase.CoSetProxyBlanket
	CALL DWORD PTR DS : [<&ole32.CoTaskMemAlloc>]          combase.CoTaskMemAlloc
	CALL DWORD PTR DS : [<&ole32.CoTaskMemFree>]           combase.CoTaskMemFree
	CALL DWORD PTR DS : [<&ole32.CoUninitialize>]          combase.CoUninitialize
	CALL DWORD PTR DS : [<&ole32.CreateStreamOnHGlobal>]   combase.CreateStreamOnHGlobal
	CALL DWORD PTR DS : [<&ole32.CoCreateInstance>]        gameover.5CD0FCC0

	CALL <JMP.&d3dx9_43.D3DXGetShaderConstantTable>      d3dx9_43.D3DXGetShaderConstantTable
	CALL <JMP.&d3dx9_43.D3DXMatrixInverse>               d3dx9_43.D3DXMatrixInverse
	CALL <JMP.&d3dx9_43.D3DXMatrixMultiply>              d3dx9_43.D3DXMatrixMultiply
	CALL <JMP.&d3dx9_43.D3DXMatrixRotationAxis>          d3dx9_43.D3DXMatrixRotationAxis
	CALL <JMP.&d3dx9_43.D3DXSaveSurfaceToFileA>          d3dx9_43.D3DXSaveSurfaceToFileA
	CALL <JMP.&d3d9.Direct3DCreate9>                     d3d9.Direct3DCreate9

	CALL <JMP.&IPHLPAPI.GetIfTable>                      IPHLPAPI.GetIfTable
	CALL DWORD PTR DS : [<&WININET.HttpEndRequestA>]       WININET.HttpEndRequestA
	CALL DWORD PTR DS : [<&WININET.HttpOpenRequestA>]      WININET.HttpOpenRequestA
	CALL DWORD PTR DS : [<&WININET.HttpQueryInfoA>]        WININET.HttpQueryInfoA
	CALL DWORD PTR DS : [<&WININET.HttpSendRequestA>]      WININET.HttpSendRequestA
	CALL DWORD PTR DS : [<&WININET.HttpSendRequestExA>]    WININET.HttpSendRequestExA
	CALL <JMP.&IMM32.ImmGetCandidateListA>               IMM32.ImmGetCandidateListA
	CALL <JMP.&IMM32.ImmGetCompositionStringA>           IMM32.ImmGetCompositionStringA
	CALL <JMP.&IMM32.ImmGetContext>                      IMM32.ImmGetContext
	CALL <JMP.&IMM32.ImmGetConversionStatus>             IMM32.ImmGetConversionStatus
	CALL <JMP.&IMM32.ImmGetOpenStatus>                   IMM32.ImmGetOpenStatus
	CALL <JMP.&IMM32.ImmNotifyIME>                       IMM32.ImmNotifyIME
	CALL <JMP.&IMM32.ImmReleaseContext>                  IMM32.ImmReleaseContext
	CALL <JMP.&IMM32.ImmSetCompositionStringA>           IMM32.ImmSetCompositionStringA
	CALL <JMP.&IMM32.ImmSetConversionStatus>             IMM32.ImmSetConversionStatus
	CALL <JMP.&IMM32.ImmSetOpenStatus>                   IMM32.ImmSetOpenStatus
	CALL DWORD PTR DS : [<&WININET.InternetAttemptConnect  WININET.InternetAttemptConnect
	CALL DWORD PTR DS : [<&WININET.InternetCloseHandle>]   WININET.InternetCloseHandle
	CALL DWORD PTR DS : [<&WININET.InternetConnectA>]      WININET.InternetConnectA
	CALL DWORD PTR DS : [<&WININET.InternetCrackUrlA>]     WININET.InternetCrackUrlA
	CALL DWORD PTR DS : [<&WININET.InternetOpenA>]         WININET.InternetOpenA
	CALL DWORD PTR DS : [<&WININET.InternetReadFile>]      WININET.InternetReadFile
	CALL DWORD PTR DS : [<&WININET.InternetSetOptionA>]    WININET.InternetSetOptionA
	CALL DWORD PTR DS : [<&WININET.InternetSetStatusCallb  WININET.InternetSetStatusCallbackA
	CALL DWORD PTR DS : [<&WININET.InternetWriteFile>]     WININET.InternetWriteFile
	CALL DWORD PTR DS : [<&USER32.OffsetRect>]             USER32.OffsetRect
	CALL DWORD PTR DS : [<&OLEAUT32.#418>]                 OLEAUT32.OleLoadPicture
	CALL DWORD PTR DS : [<&ADVAPI32.OpenProcessToken>]     advapi32.OpenProcessToken
	CALL DWORD PTR DS : [<&KERNEL32.InitializeCriticalSec  KERNELBA.InitializeCriticalSectionAndSpi
	CALL DWORD PTR DS : [<&KERNEL32.InitializeCriticalSec  KERNELBA.InitializeCriticalSectionEx
	CALL DWORD PTR DS : [<&KERNEL32.InitOnceExecuteOnce>]  KERNELBA.InitOnceExecuteOnce
	CALL DWORD PTR DS : [<&KERNEL32.LocalFileTimeToFileTi  KERNELBA.LocalFileTimeToFileTime
	CALL DWORD PTR DS : [<&KERNEL32.OutputDebugStringA>]   KERNELBA.OutputDebugStringA
	CALL DWORD PTR DS : [<&KERNEL32.OutputDebugStringW>]   KERNELBA.OutputDebugStringW
	CALL DWORD PTR DS : [<&SHLWAPI.PathFileExistsA>]       shlwapi.PathFileExistsA
	CALL DWORD PTR DS : [<&KERNEL32.RaiseException>]       KERNELBA.RaiseException
	CALL DWORD PTR DS : [<&KERNEL32.ReadConsoleW>]         KERNELBA.ReadConsoleW
	CALL DWORD PTR DS : [<&KERNEL32.ReadFile>]             KERNELBA.ReadFile
	CALL DWORD PTR DS : [<&ADVAPI32.RegCloseKey>]          advapi32.RegCloseKey
	CALL DWORD PTR DS : [<&ADVAPI32.RegCreateKeyExA>]      advapi32.RegCreateKeyExA
	CALL DWORD PTR DS : [<&ADVAPI32.RegDeleteKeyA>]        advapi32.RegDeleteKeyA
	CALL DWORD PTR DS : [<&ADVAPI32.RegDeleteValueA>]      advapi32.RegDeleteValueA
	CALL DWORD PTR DS : [<&ADVAPI32.RegEnumKeyExA>]        advapi32.RegEnumKeyExA
	CALL DWORD PTR DS : [<&ADVAPI32.RegEnumValueA>]        advapi32.RegEnumValueA
	CALL DWORD PTR DS : [<&ADVAPI32.RegFlushKey>]          advapi32.RegFlushKey
	CALL DWORD PTR DS : [<&ADVAPI32.RegOpenKeyExA>]        advapi32.RegOpenKeyExA
	CALL DWORD PTR DS : [<&ADVAPI32.RegQueryValueExA>]     advapi32.RegQueryValueExA
	CALL DWORD PTR DS : [<&ADVAPI32.RegSetValueExA>]       advapi32.RegSetValueExA
	CALL DWORD PTR DS : [<&KERNEL32.ReleaseMutex>]         KERNELBA.ReleaseMutex
	CALL DWORD PTR DS : [<&KERNEL32.ReleaseSemaphore>]     KERNELBA.ReleaseSemaphore
	CALL DWORD PTR DS : [<&KERNEL32.RemoveDirectoryA>]     KERNELBA.RemoveDirectoryA
	CALL DWORD PTR DS : [<&KERNEL32.ResetEvent>]           KERNELBA.ResetEvent
	CALL DWORD PTR DS : [<&KERNEL32.HeapAlloc>]            ntdll.RtlAllocateHeap
	CALL DWORD PTR DS : [<&KERNEL32.DecodePointer>]        ntdll.RtlDecodePointer
	CALL DWORD PTR DS : [<&KERNEL32.DeleteCriticalSection  ntdll.RtlDeleteCriticalSection
	CALL DWORD PTR DS : [<&KERNEL32.EncodePointer>]        ntdll.RtlEncodePointer
	CALL DWORD PTR DS : [<&KERNEL32.EnterCriticalSection>  ntdll.RtlEnterCriticalSection
	CALL DWORD PTR DS : [<&KERNEL32.ExitThread>]           ntdll.RtlExitUserThread
	CALL DWORD PTR DS : [<&KERNEL32.InitializeCriticalSec  ntdll.RtlInitializeCriticalSection
	CALL DWORD PTR DS : [<&KERNEL32.LeaveCriticalSection>  ntdll.RtlLeaveCriticalSection
	CALL DWORD PTR DS : [<&KERNEL32.HeapReAlloc>]          ntdll.RtlReAllocateHeap
	CALL DWORD PTR DS : [<&KERNEL32.SetLastError>]         ntdll.RtlSetLastWin32Error
	CALL DWORD PTR DS : [<&KERNEL32.HeapSize>]             ntdll.RtlSizeHeap
	CALL DWORD PTR DS : [<&KERNEL32.RtlUnwind>]            ntdll.RtlUnwind
	CALL <JMP.&KERNEL32.RtlUnwind>                       KERNEL32.RtlUnwind
	CALL DWORD PTR DS : [<&GDI32.SelectObject>]            GDI32.SelectObject
	CALL DWORD PTR DS : [<&GDI32.SetBkColor>]              GDI32.SetBkColor
	CALL DWORD PTR DS : [<&KERNEL32.SetConsoleCtrlHandler  KERNELBA.SetConsoleCtrlHandler
	CALL DWORD PTR DS : [<&KERNEL32.SetCurrentDirectoryA>  KERNEL32.SetCurrentDirectoryA
	CALL DWORD PTR DS : [<&KERNEL32.SetCurrentDirectoryW>  KERNEL32.SetCurrentDirectoryW
	CALL DWORD PTR DS : [<&KERNEL32.SetEndOfFile>]         KERNELBA.SetEndOfFile
	CALL DWORD PTR DS : [<&KERNEL32.SetEnvironmentVariabl  KERNEL32.SetEnvironmentVariableA
	CALL DWORD PTR DS : [<&KERNEL32.SetEvent>]             KERNELBA.SetEvent
	CALL DWORD PTR DS : [<&KERNEL32.SetFileAttributesA>]   KERNELBA.SetFileAttributesA
	CALL DWORD PTR DS : [<&KERNEL32.SetFilePointer>]       KERNELBA.SetFilePointer
	CALL DWORD PTR DS : [<&KERNEL32.SetFilePointerEx>]     KERNELBA.SetFilePointerEx
	CALL DWORD PTR DS : [<&KERNEL32.SetFileTime>]          KERNELBA.SetFileTime
	CALL DWORD PTR DS : [<&KERNEL32.SetStdHandle>]         KERNEL32.SetStdHandle
	CALL DWORD PTR DS : [<&KERNEL32.SetThreadExecutionSta  KERNEL32.SetThreadExecutionState
	CALL DWORD PTR DS : [<&KERNEL32.SetThreadPriority>]    KERNEL32.SetThreadPriority
	CALL DWORD PTR DS : [<&KERNEL32.SetUnhandledException  KERNEL32.SetUnhandledExceptionFilter
	CALL DWORD PTR DS : [<&SHELL32.SHGetMalloc>]           SHELL32.SHGetMalloc
	CALL DWORD PTR DS : [<&SHELL32.SHGetPathFromIDListA>]  SHELL32.SHGetPathFromIDListA
	CALL DWORD PTR DS : [<&SHELL32.SHGetSpecialFolderLoca  SHELL32.SHGetSpecialFolderLocation
	CALL DWORD PTR DS : [<&KERNEL32.SignalObjectAndWait>]  KERNEL32.SignalObjectAndWait
	CALL DWORD PTR DS : [<&KERNEL32.Sleep>]                KERNELBA.Sleep
	CALL DWORD PTR DS : [<&KERNEL32.SleepEx>]              KERNELBA.SleepEx
	CALL DWORD PTR DS : [<&steam_api.SteamAPI_Init>]       steam_ap.SteamAPI_Init
	CALL DWORD PTR DS : [<&steam_api.SteamAPI_RestartAppI  steam_ap.SteamAPI_RestartAppIfNecessary
	CALL DWORD PTR DS : [<&steam_api.SteamAPI_Shutdown>]   steam_ap.SteamAPI_Shutdown
	CALL DWORD PTR DS : [<&steam_api.SteamApps>]           steam_ap.SteamApps
	CALL DWORD PTR DS : [<&steam_api.SteamClient>]         steam_ap.SteamClient
	CALL DWORD PTR DS : [<&steam_api.SteamRemoteStorage>]  steam_ap.SteamRemoteStorage
	CALL DWORD PTR DS : [<&GDI32.StretchDIBits>]           GDI32.StretchDIBits
	CALL DWORD PTR DS : [<&KERNEL32.SuspendThread>]        KERNEL32.SuspendThread
	CALL DWORD PTR DS : [<&KERNEL32.SwitchToThread>]       KERNELBA.SwitchToThread
	CALL DWORD PTR DS : [<&OLEAUT32.#2>]                   OLEAUT32.SysAllocString
	CALL DWORD PTR DS : [<&OLEAUT32.#4>]                   OLEAUT32.SysAllocStringLen
	CALL DWORD PTR DS : [<&OLEAUT32.#6>]                   OLEAUT32.SysFreeString
	CALL DWORD PTR DS : [<&KERNEL32.SystemTimeToFileTime>  KERNEL32.SystemTimeToFileTime
	CALL DWORD PTR DS : [<&KERNEL32.TerminateProcess>]     KERNEL32.TerminateProcess
	CALL DWORD PTR DS : [<&KERNEL32.TerminateThread>]      KERNEL32.TerminateThread
	CALL DWORD PTR DS : [<&WINMM.timeBeginPeriod>]         WINMM.timeBeginPeriod
	CALL DWORD PTR DS : [<&WINMM.timeEndPeriod>]           WINMM.timeEndPeriod
	CALL DWORD PTR DS : [<&WINMM.timeGetTime>]             KERNEL32.timeGetTime
	CALL DWORD PTR DS : [<&WINMM.timeKillEvent>]           WINMM.timeKillEvent
	CALL DWORD PTR DS : [<&WINMM.timeSetEvent>]            WINMM.timeSetEvent
	CALL DWORD PTR DS : [<&KERNEL32.UnhandledExceptionFil  KERNEL32.UnhandledExceptionFilter
	CALL DWORD PTR DS : [<&OLEAUT32.#9>]                   OLEAUT32.VariantClear
	CALL DWORD PTR DS : [<&OLEAUT32.#8>]                   OLEAUT32.VariantInit
	CALL DWORD PTR DS : [<&KERNEL32.VerifyVersionInfoA>]   KERNEL32.VerifyVersionInfoA
	CALL DWORD PTR DS : [<&KERNEL32.VirtualAlloc>]         KERNEL32.VirtualAlloc
	CALL DWORD PTR DS : [<&KERNEL32.VirtualFree>]          KERNEL32.VirtualFree
	CALL DWORD PTR DS : [<&KERNEL32.WaitForMultipleObject  KERNELBA.WaitForMultipleObjects
	CALL DWORD PTR DS : [<&KERNEL32.WaitForSingleObject>]  KERNELBA.WaitForSingleObject
	CALL DWORD PTR DS : [<&KERNEL32.WideCharToMultiByte>]  KERNEL32.WideCharToMultiByte
	CALL WININET.7443CB1C                                WININET.7443CB1C
	CALL DWORD PTR DS : [<&KERNEL32.WriteConsoleW>]        KERNELBA.WriteConsoleW
	CALL DWORD PTR DS : [<&KERNEL32.WriteFile>]            KERNELBA.WriteFile
	CALL DWORD PTR DS : [<&KERNEL32.WritePrivateProfileSt  KERNEL32.WritePrivateProfileStringA
	CALL DWORD PTR DS : [<&USER32.WinHelpA>]               USER32.WinHelpA
	CALL DWORD PTR DS : [<&USER32.wsprintfA>]              USER32.wsprintfA
	CALL DWORD PTR DS : [<&USER32.wvsprintfA>]             USER32.wvsprintfA
}

*/