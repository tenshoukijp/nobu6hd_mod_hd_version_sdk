#include <windows.h>

#include "HookFuncs.h"

void HookFuncsGdi32() {
	PROC pfnOrig;
}

/*
CALL DWORD PTR DS : [<&GDI32.CreateCompatibleDC>]      GDI32.CreateCompatibleDC
CALL DWORD PTR DS : [<&GDI32.ExtTextOutA>]             GDI32.ExtTextOutA
CALL DWORD PTR DS : [<&GDI32.GetDIBits>]               GDI32.GetDIBits
CALL DWORD PTR DS : [<&GDI32.GetObjectA>]              GDI32.GetObjectA
CALL DWORD PTR DS : [<&GDI32.GetStockObject>]          GDI32.GetStockObject
*/