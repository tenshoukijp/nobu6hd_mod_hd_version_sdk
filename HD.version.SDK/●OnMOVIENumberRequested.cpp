/*
�x�[�X�A�h���X
00811000   56               PUSH ESI
*/


#include "GameDataStruct.h"


/*
�x�[�X
00871000   56               PUSH ESI

00A11496   68 0CBFB400      PUSH NOBU6HD_.00B4BF0C                   ; ASCII "MOVIE\"
00A1149B   8BCF             MOV ECX,EDI
00A1149D   E8 3E49E6FF      CALL NOBU6HD_.00875DE0
00A114A2   8B14F5 18ECBD00  MOV EDX,DWORD PTR DS:[ESI*8+BDEC18]�@�@�@��ESI�����[�r�[�̔ԍ��Ƃ�������B
00A114A9   803A 00          CMP BYTE PTR DS:[EDX],0


00BDEC18  7C BE B4 00 00 00 00 00 88 BE B4 00 00 00 00 00
00BDEC28  98 BE B4 00 00 00 00 00 B0 BE B4 00 01 00 00 00
00BDEC38  B8 BE B4 00 01 00 00 00 C0 BE B4 00 00 00 00 00
00BDEC48  D0 BE B4 00 00 00 00 00 E0 BE B4 00 00 00 00 00
00BDEC58  FC BE B4 00 01 00 00 00 04 BF B4 00 01 00 00 00

*/

/*
*/
/*
00B4BE7C  4C 4F 47 4F 5F 4B 54 2E 4E 36 00 00 4C 4F 47 4F  LOGO_KT.N6..LOGO
00B4BE8C  5F 4B 4F 45 49 2E 4E 36 00 00 00 00 4C 4F 47 4F  _KOEI.N6....LOGO
00B4BE9C  5F 73 65 72 69 65 73 5F 4E 6F 62 5F 6A 70 6E 2E  _series_Nob_jpn.
00B4BEAC  4E 36 00 00 4F 50 2E 4E 36 00 00 00 53 52 2E 4E  N6..OP.N6...SR.N
00B4BEBC  36 00 00 00 4C 4F 47 4F 5F 4B 54 5F 4C 2E 4E 36  6...LOGO_KT_L.N6
00B4BECC  00 00 00 00 4C 4F 47 4F 5F 4B 4F 45 49 5F 4C 2E  ....LOGO_KOEI_L.
00B4BEDC  4E 36 00 00 4C 4F 47 4F 5F 73 65 72 69 65 73 5F  N6..LOGO_series_
00B4BEEC  4E 6F 62 5F 6A 70 6E 5F 4C 2E 4E 36 00 00 00 00  Nob_jpn_L.N6....
00B4BEFC  4F 50 5F 4C 2E 4E 36 00 53 52 5F 4C 2E 4E 36 00  OP_L.N6.SR_L.N6.
00B4BF0C  4D 4F 56 49 45 5C 00 00 42 47 4D 5C 00 00 00 00  MOVIE\..BGM\....
00B4BF1C  42 47 4D 30 30                                   BGM00
*/

static char szOnotherMOVIEFileName[MAX_PATH] = ""; // MOVIE�̃t�@�C������ύX����B


// BGM�̔ԍ������肳��鎞

static int iESIOfMOVIEPlayingNumberDecide = 0;
static void OnTenshouExeMOVIEPlayingNumberDecideExecute() {
	
	// MOVIE�̃t�@�C�����̏����f�t�H���g�ɖ߂��B
	memcpy(nb6movietable, nb6moviedefault, sizeof(nb6moviedefault));

	if (iESIOfMOVIEPlayingNumberDecide > 0) {
		int iMOVIENum = iESIOfMOVIEPlayingNumberDecide;
		�f�o�b�O�o�� << dec << iMOVIENum << endl;
		char *szDefaultFileName = (char *)nb6moviedefault[iMOVIENum].iMOVIEFileNameAddress;

		// �f�o�b�O�o�� << "MOVIEPlayingNumberDecide:" << dec << iMOVIENum << endl;
		// �f�o�b�O�o�� << "MOVIEPlayingFileName:" << hex << szDefaultFileName << endl;

		// �V�ċL�N���X�ւ̖₢���킹
		String^ strManagedMOVIENewerFileName = "";
		
		
		try {
			// ���[�U�[�N���X���G���[
			if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
			}

			//�Q�p�����[�^�̌^��z��ɓ���� 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(2);
			types[0] = int::typeid;
			types[1] = System::String::typeid;

			//���\�b�h�̏����擾 
			MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�l�n�u�h�d�Đ����O", types);
			if (!method) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X My_�l�n�u�h�d�Đ����O ���\�b�h������");
			}

			//�Q�̃p�����^�����ۂɓ����
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(2);
			prms[0] = iMOVIENum;
			prms[1] = gcnew String(szDefaultFileName);

			�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�l�n�u�h�d�Đ����O" << endl;

			// ���������Ŏ��s
			strManagedMOVIENewerFileName = (String^)method->Invoke(nullptr, prms);
		}

		// �G���[�Ȃ̂œ����̂��̂����s����B
		catch (Exception^) {
			�f�o�b�O�o�� << "�V�ċL�N���X::On_�l�n�u�h�d�Đ����O" << endl;
			strManagedMOVIENewerFileName = �V�ċL�N���X::On_�l�n�u�h�d�Đ����O(iMOVIENum, gcnew String(szDefaultFileName));
		}
		
		

		// �L���ȃt�@�C�������Ԃ���Ă�����A���̃t�@�C�����ւ̃|�C���^���w���悤�Ƀe�[�u���̊Y���ԍ��̃t�@�C�����|�C���^��ύX����B
		if (strManagedMOVIENewerFileName->Length > 0) {
			string nativeFileName = to_native_string(strManagedMOVIENewerFileName);
			strcpy(szOnotherMOVIEFileName, nativeFileName.c_str());

			// �Đ��̑S�̃e�[�u���̒��ŁA���ꂩ��Đ����悤�Ƃ���t�@�C�����ւ̃|�C���^�ɏ�̃o�b�t�@�̃A�h���X�����Ă��܂��B
			nb6movietable[iMOVIENum].iMOVIEFileNameAddress = (int)szOnotherMOVIEFileName;


		}
	}
	else {
		// �f�o�b�O�o�� << "MOVIEPlayingNumberDecide" << dec << "BGM����" << endl;
	}
}


/*
�x�[�X

00871000   56               PUSH ESI

00A11496   68 0CBFB400      PUSH NOBU6HD_.00B4BF0C                   ; ASCII "MOVIE\"
00A1149B   8BCF             MOV ECX,EDI
00A1149D   E8 3E49E6FF      CALL NOBU6HD_.00875DE0
�������� JMP TSMod.OnTSExeMOVIEPlayingNumberDecide �Ə��������Ă����ۂ̏���
00A114A2   8B14F5 18ECBD00  MOV EDX,DWORD PTR DS:[ESI*8+BDEC18]�@�@�@��ESI�����[�r�[�̔ԍ��Ƃ�������B
00A114A9   803A 00          CMP BYTE PTR DS:[EDX],0
*/
static int pTenshouExeJumpFromToOnTenshouExeMOVIEPlayingNumberDecide = 0xA1149D - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeMOVIEPlayingNumberDecide�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeMOVIEPlayingNumberDecide = 0x875DE0 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeMOVIEPlayingNumberDecide = 0xA114A2 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																							// ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeMOVIEPlayingNumberDecide() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		mov iESIOfMOVIEPlayingNumberDecide, ESI          // ���[�r�[�̔ԍ��̕ۑ�
														 // ���X�̏���
		call pTenshouExeCallFuncToOnTenshouExeMOVIEPlayingNumberDecide

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeMOVIEPlayingNumberDecideExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeMOVIEPlayingNumberDecide
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeMOVIEPlayingNumberDecide() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeMOVIEPlayingNumberDecide,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeMOVIEPlayingNumberDecide,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeMOVIEPlayingNumberDecide	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeMOVIEPlayingNumberDecide
		);

}


