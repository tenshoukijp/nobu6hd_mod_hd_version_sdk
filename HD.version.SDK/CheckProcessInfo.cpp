#include <windows.h>


#include "GameDataStruct.h"
#include "ManagedProcess.h"
#include "const_def.h"

BOOL CheckCurrentProcessBaseInfo() {
	/*
	static char szExecFullPath[MAX_PATH] = "";
	GetModuleFileName(NULL, szExecFullPath, sizeof(szExecFullPath));
	HANDLE hExecModule = GetModuleHandle(szExecFullPath);
	char ssz[100] = "";
	wsprintf(ssz, "%x", hExecModule);
	OutputDebugString(ssz);
	*/

	// アプリの実行フルパス
	String^ exeFullPath = System::Windows::Forms::Application::ExecutablePath;

	// ベース名だけ
	String^ exeBaseName = System::IO::Path::GetFileNameWithoutExtension(exeFullPath);

	GlobalVariable::pCurrentProcessBaseAddress = (int)Tool::Process::GetProcessBaseAddress(exeBaseName);
	// デバッグ出力 << hex << GlobalVariable::pCurrentProcessBaseAddress << endl;

	int b = 0;
	b = (int)Tool::Process::GetProcessEntryPointAddress(exeBaseName);
	// デバッグ出力 << hex << b << endl;

	int iVersion = (int)Tool::Process::GetProcessFileVersionInt(exeBaseName);
	// デバッグ出力 << dec << iVersion << endl;

	if (iVersion == NOBU_6HD_TARGET_VERSION) {
		return TRUE;
	}

	return FALSE;
}