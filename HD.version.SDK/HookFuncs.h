#pragma once

extern void HookFuncs();
extern void ReplaceIATEntryInAllMods(PCSTR, PROC, PROC);

#define HOOKFUNC(dllname, funcname) pfnOrig = ::GetProcAddress(GetModuleHandleA(#dllname), #funcname); ReplaceIATEntryInAllMods(#dllname, pfnOrig, (PROC)Hook_ ## funcname);