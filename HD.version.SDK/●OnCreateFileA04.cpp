#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA04 = NULL;

static void OnTenshouExeCreateFileA04Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA04;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA04);
	�f�o�b�O�o�� << "CreateFileA04" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI


���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00872029   53               PUSH EBX
0087202A   57               PUSH EDI
0087202B   56               PUSH ESI
0087202C   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA04 �Ə��������Ă����ۂ̏���
00872031   6A 03            PUSH 3
00872033   56               PUSH ESI
00872034   6A 01            PUSH 1
00872036   68 00000080      PUSH 80000000
0087203B   50               PUSH EAX
0087203C   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00872042   8B7D 1C          MOV EDI,DWORD PTR SS:[EBP+1C]

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA04 = 0x87202C - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA04�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA04 = 0x872031 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA04() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA04, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA04Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA04
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA04() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA04,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA04,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA04	    // �����ւƖ߂�
		);
}


