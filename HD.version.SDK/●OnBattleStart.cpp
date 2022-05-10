
/*
�푈�J�n

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

�푈�J�n���ɒʉ߂���|�C���g
009730D1   77 09            JA SHORT NOBU6HD_.009730DC
009730D3   66:890D E067BD00 MOV WORD PTR DS:[BD67E0],CX
009730DA   5D               POP EBP
009730DB   C3               RETN
*/


#include "GameDataStruct.h"

static void OnTenshouExeBattleStartExecute() {
	// �o�߃^�[���������Z�b�g
	iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;

	�f�o�b�O�o�� << "�푈�J�n" << endl;
	�푈�J�n�p�����^�^^ param = gcnew �푈�J�n�p�����^�^();
	int iCastleID = GetWarCenterCastle();
	param->�U�����R�c�ԍ� = nb6turn.gundan - 1;			   // �푈�Œ��ڍU�����ɂȂ�̂́A�^�[���̌R�c�̐l����
	param->������R�c�ԍ� = nb6castle[iCastleID].attach - 1; // �U������鑤�́A���̏�̌R�c�ԍ�
	if (param->������R�c�ԍ� >= 0xFFFE) { param->������R�c�ԍ� = 0xFFFF; }

	try {
		// ���[�U�[�N���X���G���[
		if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
		}

		//�Q�p�����[�^�̌^��z��ɓ���� 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(2);
		types[0] = int::typeid;
		types[1] = �푈�J�n�p�����^�^::typeid;

		//���\�b�h�̏����擾 
		MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�푈�J�n��", types);
		if (!method) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X My_�푈�J�n��");
		}

		//�Q�̃p�����^�����ۂɓ����
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(2);
		prms[0] = iCastleID;
		prms[1] = param;

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�푈�J�n��" << endl;

		// ���������Ŏ��s
		method->Invoke(nullptr, prms);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_�푈�J�n��" << endl;
		�V�ċL�N���X::On_�푈�J�n��(iCastleID, param);
	}

}


/*

�x�[�X
00871000   56               PUSH ESI


009730D1   77 09            JA SHORT NOBU6HD_.009730DC
009730D3   66:890D E067BD00 MOV WORD PTR DS:[BD67E0],CX  �� �푈�J�n���ɁA���ID������ꏊ
�������� JMP TSMod.OnTSExeBattleStart �Ə��������Ă����ۂ̏����B7�o�C�g�̏�������
009730DA   5D               POP EBP
009730DB   C3               RETN
*/

/*
00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF ���Ɛ푈���Ă��Ȃ��AFFFF�ȊO���ƁA���̒��S�ƂȂ��Ă���u��ԍ��v�������Ă���B
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (�U���̎��́A����0x12=18,  �c��0x10=16)
*/
static int pTenshouExeJumpFromToOnTenshouExeBattleStart = 0x9730D3 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeBattleStart�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeBattleStart = 0x9730DA - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																			   // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOFTemp = 0;
																			   // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeBattleStart() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {		// eax���ꎞ�I�Ɏg���āA���0xB767E0�����̒l������
		mov iEAXOFTemp, eax
		mov eax, nb6battle_center_castle

		// ���X�̏����������ɋL�q
		MOV WORD PTR DS : [eax], CX

		// eax��߂��B
		mov eax, iEAXOFTemp


		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeBattleStartExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeBattleStart
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeBattleStart() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeBattleStart,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeBattleStart,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeBattleStart,	    // �����ւƖ߂�
		7													// 7�o�C�g
	);
}


