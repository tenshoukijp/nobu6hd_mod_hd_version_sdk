/*
�x�[�X�A�h���X
00871000   56               PUSH ESI

00995F66   68 00200000      PUSH 2000
00995F6B   E8 305C0000      CALL NOBU6HD_.0099BBA0
00995F70   E8 BBF7FFFF      CALL NOBU6HD_.00995730
00995F75   57               PUSH EDI
*/

#include "GameDataStruct.h"

extern BOOL isCountValidOfChangeFieldWarTurnExecute;


void OnTenshouExeWarScreenEndExecute() {
	// ��킩�ď�킩�̏����~�낷
	isFieldWarOrCastleWar = -1;
	isCountValidOfChangeFieldWarTurnExecute = FALSE;

	// �o�߃^�[���������Z�b�g
	iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;

	�f�o�b�O�o�� << "�푈��ʏI���E�ߗ��O" << endl;
}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

00995F66   68 00200000      PUSH 2000
00995F6B   E8 305C0000      CALL NOBU6HD_.0099BBA0
�������� JMP TSMod.OnTSExeWarScreenEnd �Ə��������Ă����ۂ̏���
00995F70   E8 BBF7FFFF      CALL NOBU6HD_.00995730
00995F75   57               PUSH EDI
*/
static int pTenshouExeJumpFromToOnTenshouExeWarScreenEnd = 0x995F6B - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeWarScreenEnd�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeWarScreenEnd = 0x99BBA0 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeWarScreenEnd = 0x995F70 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																				// ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeWarScreenEnd() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		call pTenshouExeCallFuncToOnTenshouExeWarScreenEnd

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeWarScreenEndExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeWarScreenEnd
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeWarScreenEnd() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeWarScreenEnd,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeWarScreenEnd,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeWarScreenEnd	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeWarScreenEnd
		);

}


