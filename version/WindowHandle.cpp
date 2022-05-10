#include <windows.h>

//------------------------------------------------
// �v���Z�XID �� HWND �ւ̕ϊ�
// ����:�v���Z�XID
// �߂�l: HWND �������� NULL
//------------------------------------------------
HWND GetWindowHandleFromProcessId(const DWORD TargetID) {
	HWND hWnd = GetTopWindow(NULL);
	do {
		if (GetWindowLong(hWnd, GWL_HWNDPARENT) != 0 || !IsWindowVisible(hWnd)) {
			continue;
		}
		DWORD ProcessID;
		GetWindowThreadProcessId(hWnd, &ProcessID);
		if (TargetID == ProcessID) {
			return hWnd;
		}
	} while ((hWnd = GetNextWindow(hWnd, GW_HWNDNEXT)) != NULL);

	return NULL;
}


//------------------------------------------------
// ���݂̃E�B���h�E�n���h���𓾂�
//------------------------------------------------
HWND GetCurrentWindowHandle() {
	// ���s���̃v���Z�XID�𓾂�
	DWORD pID = GetCurrentProcessId();
	// �v���Z�XID�˃E�B���h�E�n���h��
	HWND hWnd = GetWindowHandleFromProcessId(pID);
	return hWnd;
}
