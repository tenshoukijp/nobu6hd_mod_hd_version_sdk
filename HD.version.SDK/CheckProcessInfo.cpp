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

	// �A�v���̎��s�t���p�X
	String^ exeFullPath = System::Windows::Forms::Application::ExecutablePath;

	// �x�[�X������
	String^ exeBaseName = System::IO::Path::GetFileNameWithoutExtension(exeFullPath);

	GlobalVariable::pCurrentProcessBaseAddress = (int)Tool::Process::GetProcessBaseAddress(exeBaseName);
	// �f�o�b�O�o�� << hex << GlobalVariable::pCurrentProcessBaseAddress << endl;

	int b = 0;
	b = (int)Tool::Process::GetProcessEntryPointAddress(exeBaseName);
	// �f�o�b�O�o�� << hex << b << endl;

	int iVersion = (int)Tool::Process::GetProcessFileVersionInt(exeBaseName);
	// �f�o�b�O�o�� << dec << iVersion << endl;

	if (iVersion == NOBU_6HD_TARGET_VERSION) {
		return TRUE;
	}

	return FALSE;
}