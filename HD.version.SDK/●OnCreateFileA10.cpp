#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA10 = NULL;

static void OnTenshouExeCreateFileA10Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA10;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA10);
	�f�o�b�O�o�� << "CreateFileA10" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00991149   6A 00            PUSH 0
0099114B   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA10 �Ə��������Ă����ۂ̏���
00991150   6A 03            PUSH 3
00991152   6A 00            PUSH 0
00991154   6A 00            PUSH 0
00991156   50               PUSH EAX
00991157   FF75 08          PUSH DWORD PTR SS:[EBP+8]
0099115A   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00991160   5D               POP EBP

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA10 = 0x99114B - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA10�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA10 = 0x991150 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA10() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA10, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA10Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA10
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA10() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA10,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA10,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA10	    // �����ւƖ߂�
		);
}


