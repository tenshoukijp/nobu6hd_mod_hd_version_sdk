#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA06 = NULL;

static void OnTenshouExeCreateFileA06Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA06;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA06);
	�f�o�b�O�o�� << "CreateFileA06" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
0089387A   6A 00            PUSH 0
0089387C   6A 40            PUSH 40
0089387E   6A 03            PUSH 3
00893880   6A 00            PUSH 0
00893882   6A 03            PUSH 3
00893884   68 00000080      PUSH 80000000
�������� JMP TSMod.OnTSExeCreateFileA06 �Ə��������Ă����ۂ̏���
00893889   50               PUSH EAX
0089388A   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00893890   8BD8             MOV EBX,EAX
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA06 = 0x893884 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA06�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA06 = 0x893889 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA06() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA06, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80000000

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA06Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA06
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA06() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA06,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA06,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA06	    // �����ւƖ߂�
	);
}


