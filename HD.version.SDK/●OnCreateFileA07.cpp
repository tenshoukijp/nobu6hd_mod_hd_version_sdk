#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA07 = NULL;

static void OnTenshouExeCreateFileA07Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA07;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA07);
	�f�o�b�O�o�� << "CreateFileA07" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N
008EFDA8   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA07 �Ə��������Ă����ۂ̏���
008EFDAD   6A 03            PUSH 3
008EFDAF   6A 00            PUSH 0
008EFDB1   6A 00            PUSH 0
008EFDB3   68 00000080      PUSH 80000000
008EFDB8   50               PUSH EAX
008EFDB9   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
008EFDBF   6A 00            PUSH 0
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA07 = 0x8EFDA8 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA07�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA07 = 0x8EFDAD - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA07() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA07, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA07Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA07
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA07() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA07,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA07,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA07	    // �����ւƖ߂�
	);
}


