#include "GameDataStruct.h"

#include "OnWriteFukidashiMessage.h"
#include "OnSelectingScenario.h"
#include "OnFileRequest.h"

static void OnTenshouExeWriteFukidashiMessage01Execute() {

	char *str = (char *)nb6fukidashi_msg_ptr;
	// �f�o�b�O�o�� << str << endl;
	// �f�o�b�O�o�� << "���b�Z�[�W" << endl;

	// �V�i���I�I���̃��b�Z�[�W��
	if (strcmp(str, "�v���C���鐨�͂�I�����Ă�������") == 0) {
		�f�o�b�O�o�� << "�V�i���I�I��" << endl;
		On_SelectingScenario(szLastestRequestScenarioFileName);
	}

	���o���b�Z�[�W�p�����^�^^ param = gcnew ���o���b�Z�[�W�p�����^�^();

	param->��P�l��_�����ԍ� = nb6fukidashi_relate_persons.i1stPersonID < 0xFFFF ? int(nb6fukidashi_relate_persons.i1stPersonID - 1) : 0xFFFF;
	param->��Q�l��_�����ԍ� = nb6fukidashi_relate_persons.i2ndPersonID < 0xFFFF ? int(nb6fukidashi_relate_persons.i2ndPersonID - 1) : 0xFFFF;
	param->��R�l��_�����ԍ� = nb6fukidashi_relate_persons.i3rdPersonID < 0xFFFF ? int(nb6fukidashi_relate_persons.i3rdPersonID - 1) : 0xFFFF;

	String^ strReWrite = "";
		
	try {
		// ���[�U�[�N���X���G���[
		if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
		}

		//�Q�p�����[�^�̌^��z��ɓ���� 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(2);
		types[0] = System::String::typeid;
		types[1] = ���o���b�Z�[�W�p�����^�^::typeid;

		//���\�b�h�̏����擾 
		MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_���o���b�Z�[�W���O", types);
		if (!method) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X My_���o���b�Z�[�W���O ���\�b�h������");
		}

		//�Q�̃p�����^�����ۂɓ����
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(2);
		prms[0] = gcnew String(str);
		prms[1] = param;

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_���o���b�Z�[�W���O" << endl;

		// ���������Ŏ��s
		strReWrite = (String^)method->Invoke(nullptr, prms);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_���o���b�Z�[�W���O" << endl;
		strReWrite = �V�ċL�N���X::On_���o���b�Z�[�W���O(gcnew String(str), param);
	}



	if (strReWrite->Length > 1) { // ���s�����Ȃǂ̊ԈႢ���t�B���_�[
		string strNativeReWriteMessage = to_native_string(strReWrite);
		if (strNativeReWriteMessage.size() > 1) { // ���s�����Ȃǂ̊ԈႢ���t�B���_�[
			strcpy((char *)nb6fukidashi_msg_ptr, strNativeReWriteMessage.c_str());
		}
	}

}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

00991776   A3 6074BF00      MOV DWORD PTR DS:[BF7460],EAX
0099177B   C602 00          MOV BYTE PTR DS:[EDX],0
0099177E   890D 8C74BF00    MOV DWORD PTR DS:[BF748C],ECX
00991784   B8 781EBF00      MOV EAX,NOBU6HD_.00BF1E78
�������� JMP TSMod.OnTSExeWriteFukidashiMessage01 �Ə��������Ă����ۂ̏���
00991789   5E               POP ESI


00BF1E78  89 BD 82 F0 82 B7 82 E9 82 A9 82 CD 0A 8C 5A 8F  �������邩��.�Z�E
00BF1E88  E3 82 CC 0A 90 53 8E 9F 91 E6 00 82 E7 82 AD 82  ��.�S����.�炭�E
00BF1E98  A8 91 D2 82 BF 82 AD 82 BE 82 B3 82 A2 00 00 00  ��҂���������...
00BF1EA8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00BF1EB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................


*/
static int pTenshouExeJumpFromToOnTenshouExeWriteFukidashiMessage01 = 0x991784 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeWriteFukidashiMessage01�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeWriteFukidashiMessage01 = 0x991789 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																														 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B

																														 // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeWriteFukidashiMessage01() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		// ���X�̏����������ɋL�q
		MOV EAX, nb6fukidashi_msg_ptr

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeWriteFukidashiMessage01Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeWriteFukidashiMessage01
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeWriteFukidashiMessage01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeWriteFukidashiMessage01,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeWriteFukidashiMessage01,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeWriteFukidashiMessage01	    // �����ւƖ߂�
		);
}


