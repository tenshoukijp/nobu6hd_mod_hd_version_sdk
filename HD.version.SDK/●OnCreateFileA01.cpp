#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA01 = NULL;


static void OnTenshouExeCreateFileA01Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA01;
	Native::On_�t�@�C���v����( string(szFileName), pFileNameOfCreateFileA01);
	�f�o�b�O�o�� << "CreateFileA01" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
00A3DCD0   56               PUSH ESI
00A3DCD1   6A 00            PUSH 0
00A3DCD3   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA01 �Ə��������Ă����ۂ̏���
00A3DCD8   50               PUSH EAX
00A3DCD9   6A 00            PUSH 0
00A3DCDB   52               PUSH EDX
00A3DCDC   51               PUSH ECX
00A3DCDD   FF75 08          PUSH DWORD PTR SS:[EBP+8] �� ����EBP+8�̕]���������g���A�t�@�C�����ւ̃|�C���^
00A3DCE0   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00A3DCE6   8B75 10          MOV ESI,DWORD PTR SS:[EBP+10]

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA01 = 0xA3DCD3 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA01�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA01 = 0xA3DCD8 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																					  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA01() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA01, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

		// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA01Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA01
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA01,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA01,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA01	    // �����ւƖ߂�
	);
}


