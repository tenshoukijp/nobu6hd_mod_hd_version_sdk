#pragma once

#define EXPORT_AND_NAKED __declspec(dllexport) __declspec(naked)

void WriteAsmJumperAndReturn(int NakedFunctionAddress, int &FromJump, int&GoToJump, int iCopyByte = 5);
void WriteAsmJumperAndFunc(int&CallFunc);

// 以下を全て登録する関数
void RegisterFunctionsOfWriteAsmJumperAndReturn();

// 天翔記内部の関数そのものを利用する。
void ReplaceWrapperCallFunctions();

