#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA02 = NULL;

static void OnTenshouExeCreateFileA02Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA02;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA02);
	�f�o�b�O�o�� << "CreateFileA02" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00871826   56               PUSH ESI
00871827   57               PUSH EDI
00871828   6A 00            PUSH 0
0087182A   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA02 �Ə��������Ă����ۂ̏���
0087182F   6A 03            PUSH 3
00871831   6A 00            PUSH 0
00871833   6A 01            PUSH 1
00871835   68 00000080      PUSH 80000000
0087183A   50               PUSH EAX
0087183B   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00871841   8BF8             MOV EDI,EAX

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA02 = 0x87182A - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA02�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA02 = 0x87182F - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA02() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA02, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA02Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA02
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA02() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA02,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA02,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA02	    // �����ւƖ߂�
		);
}


