#include "GameDataStruct.h"

/*
�푈�I���������́A�푈�ł͂Ȃ���ԂƂ���B

00871000   56               PUSH ESI

References in NOBU6HD_:.text to 00BD67E0..00BD67E0
Address    Disassembly                               Comment
00973025   MOV WORD PTR DS:[BD67E0],AX				�� �����̓N���A�̏�
00973070   MOV AX,WORD PTR DS:[BD67E0]               [00BD67E0]=005A
009730D3   MOV WORD PTR DS:[BD67E0],CX				�� �����͐푈�J�n���ɒ��S�_�̏�ԍ�������ꏊ

00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF ���Ɛ푈���Ă��Ȃ��AFFFF�ȊO���ƁA���̒��S�ƂȂ��Ă���u��ԍ��v�������Ă���B
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (�U���̎��́A����0x12=18,  �c��0x10=16)

00BD67DA  95 00 A0 4F 95 00 [5A 00] 14 00 00 00 05 00 00 00
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 [29: 00
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .

�x�[�X
00871000   56               PUSH ESI

00973020   B8 FFFF0000      MOV EAX,0FFFF
00973025   66:A3 E067BD00   MOV WORD PTR DS:[BD67E0],AX
0097302B   C3               RETN

*/


extern BOOL isCountValidOfChangeFieldWarTurnExecute;


static void OnTenshouExeBattleClearExecute() {
	// ��킩�ď�킩�̏����~�낷
	isFieldWarOrCastleWar = -1;
	isCountValidOfChangeFieldWarTurnExecute = FALSE;

	// �o�߃^�[���������Z�b�g
	iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;


	if ( IsDoingWar() ) {

		try {
			// ���[�U�[�N���X���G���[
			if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
			}

			//���\�b�h�̏����擾 
			MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�푈�I����");
			if (!method) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X My_�푈�I���� ���\�b�h������");
			}

			�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�푈�I����" << endl;

			// ���������Ŏ��s
			method->Invoke(nullptr, nullptr);
		}

		// �G���[�Ȃ̂œ����̂��̂����s����B
		catch (Exception^) {
			�f�o�b�O�o�� << "�V�ċL�N���X::On_�푈�I����" << endl;
			�V�ċL�N���X::On_�푈�I����();
		}


		�f�o�b�O�o�� << "�푈�I��" << endl;
	}
	else {
		�f�o�b�O�o�� << "�퓬�O�̃N���A" << endl;
	}
}

/*
�x�[�X
00871000   56               PUSH ESI

00973020   B8 FFFF0000      MOV EAX,0FFFF
00973025   66:A3 E067BD00   MOV WORD PTR DS:[BD67E0],AX
�������� JMP TSMod.OnTSExeBattleClear �Ə��������Ă����ۂ̏����B7�o�C�g�̏�������
0097302B   C3               RETN

00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF ���Ɛ푈���Ă��Ȃ��AFFFF�ȊO���ƁA���̒��S�ƂȂ��Ă���u��ԍ��v�������Ă���B
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (�U���̎��́A����0x12=18,  �c��0x10=16)

00BD67DA  95 00 A0 4F 95 00 [5A 00] 14 00 00 00 05 00 00 00
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 [29: 00
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .

*/
static int pTenshouExeJumpFromToOnTenshouExeBattleClear = 0x973025 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeBattleClear�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeBattleClear = 0x97302B - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
												
static int iEBXOFTemp = 0;
																			 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeBattleClear() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeBattleClearExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {

		POPFD
		POPAD

		// eax���ꎞ�I�Ɏg���āA���0xB767E0�����̒l������
		mov iEBXOFTemp, ebx
		mov ebx, nb6battle_center_castle

		// ���X�̏����������ɋL�q
		MOV WORD PTR DS : [ebx], AX

		// eax��߂��B
		mov ebx, iEBXOFTemp


		jmp pTenshouExeRetnBacktoOnTenshouExeBattleClear
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeBattleClear() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeBattleClear,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeBattleClear,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeBattleClear,	    // �����ւƖ߂�
		6												// 7�o�C�g
		);
}


