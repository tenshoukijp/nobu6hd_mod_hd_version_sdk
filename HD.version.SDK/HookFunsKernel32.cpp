#include <windows.h>

#include "HookFuncs.h"

//----------------------------------------------------------------
// user32.dll系のフック関数
//----------------------------------------------------------------
static HMODULE hTargetDLL = GetModuleHandleA("kernel32.dll");

using PFNCREATEFILEA = HANDLE (WINAPI *) (LPCTSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE);
	//----------------------------------------------------------------
static PFNCREATEFILEA pfnOrigCreateFileA = (PFNCREATEFILEA)GetProcAddress(hTargetDLL, "CreateFileA");

/*
次のオブジェクトを作成するか開き、そのオブジェクトをアクセスするために利用できるハンドルを返します。
?コンソール
?通信リソース
?ディレクトリ（開くだけで作成は不可能）
?ファイル
?メールスロット
?パイプ
*/
HANDLE Hook_CreateFileA(
	LPCTSTR lpFileName,                         // ファイル名
	DWORD dwDesiredAccess,                      // アクセスモード
	DWORD dwShareMode,                          // 共有モード
	LPSECURITY_ATTRIBUTES lpSecurityAttributes, // セキュリティ記述子
	DWORD dwCreationDisposition,                // 作成方法
	DWORD dwFlagsAndAttributes,                 // ファイル属性
	HANDLE hTemplateFile)                       // テンプレートファイルのハンドル	
{
	// 元のものを呼び出す
	HANDLE nResult = pfnOrigCreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	return nResult;
}


void HookFuncsKernel32() {
	PROC pfnOrig;
}

/*
	CALL DWORD PTR DS : [<&KERNEL32.CreateFileA>]          KERNELBA.CreateFileA

	CALL DWORD PTR DS : [<&KERNEL32.CompareStringEx>]      KERNEL32.CompareStringEx
	CALL DWORD PTR DS : [<&KERNEL32.CopyFileA>]            KERNEL32.CopyFileA

	CALL DWORD PTR DS : [<&KERNEL32.CreateSemaphoreA>]     KERNEL32.CreateSemaphoreA
	CALL DWORD PTR DS : [<&KERNEL32.CreateThread>]         KERNEL32.CreateThread
	CALL DWORD PTR DS : [<&KERNEL32.DeviceIoControl>]      KERNEL32.DeviceIoControl
	CALL DWORD PTR DS : [<&KERNEL32.EnumSystemLocalesEx>]  KERNEL32.EnumSystemLocalesEx
	CALL DWORD PTR DS : [<&KERNEL32.ExitProcess>]          KERNEL32.ExitProcess
	CALL DWORD PTR DS : [<&KERNEL32.FlsAlloc>]             KERNEL32.FlsAlloc
	CALL DWORD PTR DS : [<&KERNEL32.FlsFree>]              KERNEL32.FlsFree
	CALL DWORD PTR DS : [<&KERNEL32.FlsGetValue>]          KERNEL32.FlsGetValue
	CALL DWORD PTR DS : [<&KERNEL32.FlsSetValue>]          KERNEL32.FlsSetValue
	CALL DWORD PTR DS : [<&KERNEL32.FormatMessageA>]       KERNEL32.FormatMessageA
	CALL DWORD PTR DS : [<&KERNEL32.FreeEnvironmentString  KERNEL32.FreeEnvironmentStringsW
	CALL DWORD PTR DS : [<&KERNEL32.GetCPInfo>]            KERNEL32.GetCPInfo
	CALL DWORD PTR DS : [<&KERNEL32.GetCurrentDirectoryA>  KERNEL32.GetCurrentDirectoryA
	CALL DWORD PTR DS : [<&KERNEL32.GetCurrentDirectoryW>  KERNEL32.GetCurrentDirectoryW
	CALL DWORD PTR DS : [<&KERNEL32.GetCurrentProcess>]    KERNEL32.GetCurrentProcess
	CALL DWORD PTR DS : [<&KERNEL32.GetCurrentThread>]     KERNEL32.GetCurrentThread
	CALL DWORD PTR DS : [<&KERNEL32.GetCurrentThreadId>]   KERNEL32.GetCurrentThreadId
	CALL DWORD PTR DS : [<&KERNEL32.GetDateFormatEx>]      KERNEL32.GetDateFormatEx
	CALL DWORD PTR DS : [<&KERNEL32.GetExitCodeThread>]    KERNEL32.GetExitCodeThread
	CALL DWORD PTR DS : [<&KERNEL32.GetLocaleInfoEx>]      KERNEL32.GetLocaleInfoEx
	CALL DWORD PTR DS : [<&KERNEL32.GetModuleFileNameA>]   KERNEL32.GetModuleFileNameA
	CALL DWORD PTR DS : [<&KERNEL32.GetModuleFileNameW>]   KERNEL32.GetModuleFileNameW
	CALL DWORD PTR DS : [<&KERNEL32.GetModuleHandleA>]     KERNEL32.GetModuleHandleA
	CALL DWORD PTR DS : [<&KERNEL32.GetModuleHandleExW>]   KERNEL32.GetModuleHandleExW
	CALL DWORD PTR DS : [<&KERNEL32.GetModuleHandleW>]     KERNEL32.GetModuleHandleW
	CALL DWORD PTR DS : [<&KERNEL32.GetPrivateProfileIntA  KERNEL32.GetPrivateProfileIntA
	CALL DWORD PTR DS : [<&KERNEL32.GetPrivateProfileStri  KERNEL32.GetPrivateProfileStringA
	CALL DWORD PTR DS : [<&KERNEL32.GetProcAddress>]       KERNEL32.GetProcAddress
	CALL DWORD PTR DS : [<&KERNEL32.GetStdHandle>]         KERNEL32.GetStdHandle
	CALL DWORD PTR DS : [<&KERNEL32.GetStringTypeW>]       KERNEL32.GetStringTypeW
	CALL DWORD PTR DS : [<&KERNEL32.GetSystemDirectoryA>]  KERNEL32.GetSystemDirectoryA
	CALL DWORD PTR DS : [<&KERNEL32.GetThreadPriority>]    KERNEL32.GetThreadPriority
	CALL DWORD PTR DS : [<&KERNEL32.GetTickCount>]         KERNEL32.GetTickCount
	CALL DWORD PTR DS : [<&KERNEL32.GetTickCount64>]       KERNEL32.GetTickCount64
	CALL DWORD PTR DS : [<&KERNEL32.GetTimeFormatEx>]      KERNEL32.GetTimeFormatEx
	CALL DWORD PTR DS : [<&KERNEL32.GetTimeZoneInformatio  KERNEL32.GetTimeZoneInformation
	CALL DWORD PTR DS : [<&KERNEL32.GetUserDefaultLocaleN  KERNEL32.GetUserDefaultLocaleName
	CALL DWORD PTR DS : [<&KERNEL32.GetVersionExA>]        KERNEL32.GetVersionExA
	CALL DWORD PTR DS : [<&KERNEL32.GlobalAlloc>]          KERNEL32.GlobalAlloc
	CALL DWORD PTR DS : [<&KERNEL32.GlobalFree>]           KERNEL32.GlobalFree
	CALL DWORD PTR DS : [<&KERNEL32.GlobalLock>]           KERNEL32.GlobalLock
	CALL DWORD PTR DS : [<&KERNEL32.GlobalMemoryStatus>]   KERNEL32.GlobalMemoryStatus
	CALL DWORD PTR DS : [<&KERNEL32.GlobalUnlock>]         KERNEL32.GlobalUnlock
	CALL DWORD PTR DS : [<&KERNEL32.HeapFree>]             KERNEL32.HeapFree
	CALL DWORD PTR DS : [<&KERNEL32.HeapQueryInformation>  KERNEL32.HeapQueryInformation

	CALL DWORD PTR DS : [<&KERNEL32.InterlockedCompareExc  KERNEL32.InterlockedCompareExchange
	CALL DWORD PTR DS : [<&KERNEL32.InterlockedDecrement>  KERNEL32.InterlockedDecrement
	CALL DWORD PTR DS : [<&KERNEL32.InterlockedExchange>]  KERNEL32.InterlockedExchange
	CALL DWORD PTR DS : [<&KERNEL32.InterlockedExchangeAd  KERNEL32.InterlockedExchangeAdd
	CALL DWORD PTR DS : [<&KERNEL32.InterlockedIncrement>  KERNEL32.InterlockedIncrement
	CALL DWORD PTR DS : [<&KERNEL32.IsDebuggerPresent>]    KERNELBA.IsDebuggerPresent
	CALL <JMP.&KERNEL32.IsProcessorFeaturePresent>       KERNEL32.IsProcessorFeaturePresent
	CALL DWORD PTR DS : [<&KERNEL32.IsValidCodePage>]      KERNEL32.IsValidCodePage
	CALL DWORD PTR DS : [<&KERNEL32.IsValidLocaleName>]    KERNEL32.IsValidLocaleName
	CALL DWORD PTR DS : [<&KERNEL32.LCMapStringEx>]        KERNEL32.LCMapStringEx
	CALL DWORD PTR DS : [<&KERNEL32.LocalFree>]            KERNEL32.LocalFree
	CALL DWORD PTR DS : [<&KERNEL32.MoveFileA>]            KERNEL32.MoveFileA
	CALL DWORD PTR DS : [<&KERNEL32.MulDiv>]               KERNEL32.MulDiv
	CALL DWORD PTR DS : [<&KERNEL32.MultiByteToWideChar>]  KERNEL32.MultiByteToWideChar
	CALL DWORD PTR DS : [<&KERNEL32.PulseEvent>]           KERNEL32.PulseEvent
	CALL DWORD PTR DS : [<&KERNEL32.QueryPerformanceCount  KERNEL32.QueryPerformanceCounter
	CALL DWORD PTR DS : [<&KERNEL32.QueryPerformanceFrequ  KERNEL32.QueryPerformanceFrequency
	CALL DWORD PTR DS : [<&KERNEL32.ResumeThread>]         KERNEL32.ResumeThread

*/