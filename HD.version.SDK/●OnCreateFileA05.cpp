#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA05 = NULL;

static void OnTenshouExeCreateFileA05Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA05;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA05);
	�f�o�b�O�o�� << "CreateFileA05" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N

00872D06   56               PUSH ESI
00872D07   6A 00            PUSH 0
00872D09   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA05 �Ə��������Ă����ۂ̏���
00872D0E   6A 02            PUSH 2
00872D10   6A 00            PUSH 0
00872D12   6A 01            PUSH 1
00872D14   68 00000040      PUSH 40000000
00872D19   53               PUSH EBX
00872D1A   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00872D20   8BF0             MOV ESI,EAX
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA05 = 0x872D09 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA05�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA05 = 0x872D0E - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA05() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, ebx // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA05, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA05Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA05
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA05() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA05,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA05,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA05	    // �����ւƖ߂�
	);
}


