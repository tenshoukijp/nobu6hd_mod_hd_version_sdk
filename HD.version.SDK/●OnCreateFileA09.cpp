#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA09 = NULL;

static void OnTenshouExeCreateFileA09Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA09;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA09);
	�f�o�b�O�o�� << "CreateFileA09" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00990F85   6A 00            PUSH 0
00990F87   6A 20            PUSH 20
00990F89   6A 05            PUSH 5
00990F8B   6A 00            PUSH 0
00990F8D   6A 00            PUSH 0
00990F8F   68 000000C0      PUSH C0000000
�������� JMP TSMod.OnTSExeCreateFileA09 �Ə��������Ă����ۂ̏���
00990F94   FF75 08          PUSH DWORD PTR SS:[EBP+8]
00990F97   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00990F9D   5E               POP ESI
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA09 = 0x990F8F - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA09�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA09 = 0x990F94 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA09() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA09, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0xC0000000

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA09Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA09
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA09() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA09,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA09,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA09	    // �����ւƖ߂�
	);
}


