#include "GameDataStruct.h"



/*
�x�[�X
00871000   56               PUSH ESI

���ł̌o�߃^�[����
References in NOBU6HD_:.text to 00BD67EA..00BD67EA
Address    Disassembly                               Comment
00973040   MOV DWORD PTR DS:[BD67EA],0               DS:[00BD67EA]=0000000D  �� �����Ƀ^�[�����̒l���N���A���Ă���B
00973090   MOV EAX,DWORD PTR DS:[BD67EA]             [00BD67EA]=0000000D
00973176   MOV DWORD PTR DS:[BD67EA],EAX                                     �� �����Ƀ^�[�����̒l���������Ă���B

0097316F   CC               INT3
00973170   55               PUSH EBP
00973171   8BEC             MOV EBP,ESP
00973173   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
00973176   A3 EA67BD00      MOV DWORD PTR DS:[BD67EA],EAX    �� �^�[�����̑��
0097317B   5D               POP EBP
0097317C   C3               RETN
* /

/*
�x�[�X
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  �E�O�E
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=�o�߃^�[������[02]=�V�C  0x29=41�Ƃ͖��̉���HEX���̂���  0x12�̎��͍U�Đ��HEX���̉��̃}�X���ł���18�̂��ƁB
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
*/


int iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;

BOOL isCountValidOfChangeFieldWarTurnExecute = FALSE;
static void OnTenshouExeChangeFieldWarTurnExecute() {

	if (isCountValidOfChangeFieldWarTurnExecute) {
		�f�o�b�O�o�� << "���^�[���̕ω�:" << iFieldTurnOfChangeFieldWarTurnExecute << endl;

		try {
			// ���[�U�[�N���X���G���[
			if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
			}

			//�P�p�����[�^�̌^��z��ɓ���� 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
			types[0] = int::typeid;

			//���\�b�h�̏����擾 
			MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�푈_�c��^�[���ύX��", types);
			if (!method) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X My_�푈_�c��^�[���ύX�� ���\�b�h������");
			}

			//�P�̃p�����^�����ۂɓ����
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
			prms[0] = getFieldTurnInBattle();

			�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�푈_�c��^�[���ύX��" << endl;

			// �Ԃ�l�����Ŏ��s
			method->Invoke(nullptr, prms);
		}

		// �G���[�Ȃ̂œ����̂��̂����s����B
		catch (Exception^) {
			�f�o�b�O�o�� << "�V�ċL�N���X::On_�푈_�c��^�[���ύX��" << endl;
			�V�ċL�N���X::On_�푈_�c��^�[���ύX��(getFieldTurnInBattle());
		}


	}

}

/*
�x�[�X
00871000   56               PUSH ESI

0097316F   CC               INT3
00973170   55               PUSH EBP
00973171   8BEC             MOV EBP,ESP
00973173   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
00973176   A3 EA67BD00      MOV DWORD PTR DS:[BD67EA],EAX    �� �^�[�����̑��
�������� JMP TSMod.OnTSExeChangeFieldWarTurn �Ə��������Ă����ۂ̏����B
0097317B   5D               POP EBP
0097317C   C3               RETN
*/
static int pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurn = 0x973176 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeChangeFieldWarTurn�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurn = 0x97317B - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																					  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEBXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeFieldWarTurn() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		// ebx�Ԏ؂�
		mov iEBXOFTemp, ebx
		mov ebx, nb6battle_field_turn

		// ���X�̏����������ɋL�q
		MOV DWORD PTR DS : [ebx], eax

		// ebx�߂�
		mov ebx, iEBXOFTemp

		mov iFieldTurnOfChangeFieldWarTurnExecute, eax  // ����^�[�����Ȃ̂ŕۑ����Ă���

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeFieldWarTurnExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurn
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeChangeFieldWarTurn() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeFieldWarTurn,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurn,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurn	    // �����ւƖ߂�
		);
}



