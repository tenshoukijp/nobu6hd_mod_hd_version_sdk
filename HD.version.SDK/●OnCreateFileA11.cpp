#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA11 = NULL;

static void OnTenshouExeCreateFileA11Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA11;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA11);
	�f�o�b�O�o�� << "CreateFileA11" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00A3DF95   6A 00            PUSH 0
00A3DF97   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA11 �Ə��������Ă����ۂ̏���
00A3DF9C   6A 03            PUSH 3
00A3DF9E   6A 00            PUSH 0
00A3DFA0   6A 00            PUSH 0
00A3DFA2   68 00000040      PUSH 40000000
00A3DFA7   FF75 08          PUSH DWORD PTR SS:[EBP+8]
00A3DFAA   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00A3DFB0   8BC8             MOV ECX,EAX

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA11 = 0xA3DF97 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA11�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA11 = 0xA3DF9C - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA11() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA11, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA11Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA11
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA11() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA11,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA11,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA11	    // �����ւƖ߂�
		);
}


