#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA12 = NULL;

static void OnTenshouExeCreateFileA12Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA12;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA12);
	�f�o�b�O�o�� << "CreateFileA12" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N

00A5721B   6A 00            PUSH 0
00A5721D   6A 00            PUSH 0
00A5721F   6A 03            PUSH 3
00A57221   6A 00            PUSH 0
00A57223   6A 01            PUSH 1
00A57225   68 00000080      PUSH 80000000
�������� JMP TSMod.OnTSExeCreateFileA12 �Ə��������Ă����ۂ̏���
00A5722A   53               PUSH EBX
00A5722B   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00A57231   8BD8             MOV EBX,EAX



*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA12 = 0xA57225 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA12�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA12 = 0xA5722A - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA12() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, ebx // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA12, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80000000

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA12Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA12
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA12() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA12,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA12,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA12	    // �����ւƖ߂�
		);
}


