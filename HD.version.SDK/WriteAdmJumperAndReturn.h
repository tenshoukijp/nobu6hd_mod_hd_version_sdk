#pragma once

#define EXPORT_AND_NAKED __declspec(dllexport) __declspec(naked)

void WriteAsmJumperAndReturn(int NakedFunctionAddress, int &FromJump, int&GoToJump, int iCopyByte = 5);
void WriteAsmJumperAndFunc(int&CallFunc);

// �ȉ���S�ēo�^����֐�
void RegisterFunctionsOfWriteAsmJumperAndReturn();

// �V�ċL�����̊֐����̂��̂𗘗p����B
void ReplaceWrapperCallFunctions();

