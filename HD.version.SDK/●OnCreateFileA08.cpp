#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA08 = NULL;

static void OnTenshouExeCreateFileA08Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA08;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA08);
	�f�o�b�O�o�� << "CreateFileA08" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00990F43   56               PUSH ESI
00990F44   6A 00            PUSH 0
00990F46   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA08 �Ə��������Ă����ۂ̏���
00990F4B   6A 01            PUSH 1
00990F4D   6A 00            PUSH 0
00990F4F   6A 00            PUSH 0
00990F51   68 000000C0      PUSH C0000000
00990F56   FF75 08          PUSH DWORD PTR SS:[EBP+8]
00990F59   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA08 = 0x990F46 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA08�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA08 = 0x990F4B - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA08() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA08, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA08Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA08
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA08() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA08,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA08,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA08	    // �����ւƖ߂�
	);
}


