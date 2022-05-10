#include <windows.h>
#include <tlhelp32.h>
#include <map>

using namespace std;

map<int, size_t> mapCurrentProcessHeapInfo;

// 現在のプロセスのヒープリストをmapHeapListに格納する。
int CheckCurrentProcessHeapInfo() {
	int iProcessID = GetCurrentProcessId();

	HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPHEAPLIST, iProcessID);

	if (hSnapshot == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	HEAPLIST32 heaplist;
	heaplist.dwSize = sizeof(HEAPLIST32);;

	if (Heap32ListFirst(hSnapshot, &heaplist)) {
		do {
			HEAPENTRY32 heapentry;
			heapentry.dwSize = sizeof(HEAPENTRY32);

			if (Heap32First(&heapentry, heaplist.th32ProcessID, heaplist.th32HeapID)) {
				do {
					mapCurrentProcessHeapInfo[heapentry.dwAddress] = heapentry.dwBlockSize; // そのアドレスと確保サイズ

				} while ( Heap32Next(&heapentry) );
			}
			
		} while ( Heap32ListNext(hSnapshot, &heaplist) );
	}
	::CloseHandle(hSnapshot);

	return TRUE;
}
