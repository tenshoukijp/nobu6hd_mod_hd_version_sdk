#include "GameDataStruct.h"

#include "OnFileRequest.h"

// ����CreateFileA�̂P�Ԗڂł́A��ɁA�u���b�Z�[�W�n�t�@�C���̓ǂݍ��݁v�u�V�i���I�t�@�C���̓ǂݍ��݁v���s����B

static int pFileNameOfCreateFileA03 = NULL;

static void OnTenshouExeCreateFileA03Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA03;
	Native::On_�t�@�C���v����(string(szFileName), pFileNameOfCreateFileA03);
	�f�o�b�O�o�� << "CreateFileA03" << szFileName << endl;
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

���̎���CreateFileA�̂P�Ԗڕt�߂̃j�[���j�b�N

00872066   6A 00            PUSH 0
00872068   68 80000000      PUSH 80
�������� JMP TSMod.OnTSExeCreateFileA03 �Ə��������Ă����ۂ̏���
0087206D   6A 02            PUSH 2
0087206F   6A 00            PUSH 0
00872071   6A 01            PUSH 1
00872073   68 00000040      PUSH 40000000
00872078   FF75 0C          PUSH DWORD PTR SS:[EBP+C]
0087207B   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00872081   8945 F0          MOV DWORD PTR SS:[EBP-10],EAX
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA03 = 0x872068 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeCreateFileA03�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA03 = 0x87206D - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOfTemp = 0; // EAX�p�̈ꎞ�ϐ�

						   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA03() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0xC] // eax�̒l���A�t�@�C�����ւ̃|�C���^
		mov pFileNameOfCreateFileA03, eax   // eax������Ă���

		mov eax, iEAXOfTemp // eax�����ւƖ߂��B

							// ���X���������
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA03Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA03
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCreateFileA03() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA03,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCreateFileA03,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA03	    // �����ւƖ߂�
		);
}


