
#include <windows.h>
#include <VersionHelpers.h>

#include "version.h"
#include "process.h"

#include "WindowHandle.h"



HMODULE hTSHDVersionDLL = NULL;

PFNONINITIALIZE p_OnInitialize = NULL;
PFNONFINALIZE   p_OnFinalize   = NULL;

// 現在のウィンドウハンドルが、確かに天翔記HDのものかどうかをチェック
static bool IsMatchCurrentProgram() {

	// ゲームランチャーからゲーム本体かどちらかのウィンドウがあるはず。
	HWND hWndNobu6HDHandle = NULL;

	if (!hWndNobu6HDHandle) { hWndNobu6HDHandle = ::FindWindow(NOBU_6HD_LAUNCHER_WINDOW, NULL); }
	if (!hWndNobu6HDHandle) { hWndNobu6HDHandle = ::FindWindow(NOBU_6HD_GAMEMAIN_WINDOW, NULL); }

	HWND hWndCurrentHandle = GetCurrentWindowHandle();
	if (hWndNobu6HDHandle == hWndCurrentHandle) {
		return true;
	}
	else {
		return false;
	}
}

// TSHD.version.dllの読み込みと、OnInitializeメソッドの実行
static bool LoadTSHDVersionDLL() {

	hTSHDVersionDLL = LoadLibrary("HD.version.dll");
	// 存在しない
	if (!hTSHDVersionDLL) {
		// OutputDebugString("HD.version.dllが存在しない。");
		return false;
	}

	p_OnInitialize = (PFNONINITIALIZE)GetProcAddress(hTSHDVersionDLL, "OnInitialize");
	p_OnFinalize = (PFNONFINALIZE)GetProcAddress(hTSHDVersionDLL, "OnFinalize");
	if (!p_OnInitialize) {
		// OutputDebugString("p_OnFinalizeが存在しない。");
		return false;
	}

	p_OnInitialize(NULL);
	return true;
}

void OnInitialize() {


	// このメソッドが一度実行されたかどうか
	static bool isCalledOnInitialize = false;

	// もう実行済みなら何もしない
	if (isCalledOnInitialize) {
		return;
	}

	// 実行済みにする。
	isCalledOnInitialize = true;

	// このdllを呼び出してるのは、本当にターゲットとしているゲーム？
	if (!IsMatchCurrentProgram()) {
		return;
	}

	LoadTSHDVersionDLL();
}

__declspec(naked) void WINAPI d_GetFileVersionInfoA() {
	_asm {
		call OnInitialize
		jmp p_GetFileVersionInfoA
	}
}
__declspec(naked) void WINAPI d_GetFileVersionInfoByHandle()	{ _asm { jmp p_GetFileVersionInfoByHandle } }
__declspec(naked) void WINAPI d_GetFileVersionInfoExA()			{ _asm { jmp p_GetFileVersionInfoExA }		}
__declspec(naked) void WINAPI d_GetFileVersionInfoExW()			{ _asm { jmp p_GetFileVersionInfoExW }		}
__declspec(naked) void WINAPI d_GetFileVersionInfoSizeA()		{ _asm { jmp p_GetFileVersionInfoSizeA }	}
__declspec(naked) void WINAPI d_GetFileVersionInfoSizeExA()		{ _asm { jmp p_GetFileVersionInfoSizeExA }	}
__declspec(naked) void WINAPI d_GetFileVersionInfoSizeExW()		{ _asm { jmp p_GetFileVersionInfoSizeExW }	}
__declspec(naked) void WINAPI d_GetFileVersionInfoSizeW()		{ _asm { jmp p_GetFileVersionInfoSizeW }	}
__declspec(naked) void WINAPI d_GetFileVersionInfoW()			{ _asm { jmp p_GetFileVersionInfoW }		}
__declspec(naked) void WINAPI d_VerFindFileA()					{ _asm { jmp p_VerFindFileA }				}
__declspec(naked) void WINAPI d_VerFindFileW()					{ _asm { jmp p_VerFindFileW }				}
__declspec(naked) void WINAPI d_VerInstallFileA()				{ _asm { jmp p_VerInstallFileA }			}
__declspec(naked) void WINAPI d_VerInstallFileW()				{ _asm { jmp p_VerInstallFileW }			}
__declspec(naked) void WINAPI d_VerLanguageNameA()				{ _asm { jmp p_VerLanguageNameA }			}
__declspec(naked) void WINAPI d_VerLanguageNameW()				{ _asm { jmp p_VerLanguageNameW }			}
__declspec(naked) void WINAPI d_VerQueryValueA()				{ _asm { jmp p_VerQueryValueA }				}
__declspec(naked) void WINAPI d_VerQueryValueW()				{ _asm { jmp p_VerQueryValueW }				}
