/*
BGM�e�[�u��
*/
/*
�x�[�X�A�h���X
00871000   56               PUSH ESI

00A120F0   68 14BFB400      PUSH NOBU6HD_.00B4BF14                   ; ASCII "BGM\"
00A120F5   8BCE             MOV ECX,ESI
00A120F7   81C7 98ECBD00    ADD EDI,NOBU6HD_.00BDEC98				�� �eBGM�t�@�C�����n�̍\���̂ւ̃|�C���^
00A120FD   E8 0E30E6FF      CALL NOBU6HD_.00875110
00A12102   FF77 04          PUSH DWORD PTR DS:[EDI+4]
00A12105   8BCE             MOV ECX,ESI


009B1FC5   8BCE             MOV ECX,ESI
009B1FC7   81C7 98ECB700    ADD EDI,NOBU6HD_.00B7EC98
009B1FCD   E8 3E31E6FF      CALL NOBU6HD_.00815110
*/
/*
00BDEC98  00 00 00 00 1C BF B4 00 00 00 00 00 00 00 00 00  ....�� BGM�ԍ���BGM������ւ̃|�C���^�ƁA�g�p�t���O
00BDECA8  01 00 00 00 28 BF B4 00 01 00 00 00 00 00 00 00
00BDECB8  02 00 00 00 34 BF B4 00 01 00 00 00 00 00 00 00
00BDECC8  03 00 00 00 40 BF B4 00 01 00 00 00 00 00 00 00
00BDECD8  04 00 00 00 4C BF B4 00 01 00 00 00 00 00 00 00
00BDECE8  05 00 00 00 58 BF B4 00 01 00 00 00 00 00 00 00
00BDECF8  06 00 00 00 64 BF B4 00 01 00 00 00 00 00 00 00
00BDED08  07 00 00 00 70 BF B4 00 01 00 00 00 00 00 00 00
00BDED18  08 00 00 00 7C BF B4 00 01 00 00 00 00 00 00 00
00BDED28  09 00 00 00 88 BF B4 00 01 00 00 00 00 00 00 00
00BDED38  0A 00 00 00 94 BF B4 00 01 00 00 00 00 00 00 00
00BDED48  0B 00 00 00 A0 BF B4 00 00 00 00 00 00 00 00 00

00B4BF1C  42 47 4D 30 30 2E 6B 76 73 00 00 00 42 47 4D 30  BGM00.kvs...BGM0
00B4BF2C  31 2E 6B 76 73 00 00 00 42 47 4D 30 32 2E 6B 76  1.kvs...BGM02.kv
00B4BF3C  73 00 00 00 42 47 4D 30 33 2E 6B 76 73 00 00 00  s...BGM03.kvs...
00B4BF4C  42 47 4D 30 34 2E 6B 76 73 00 00 00 42 47 4D 30  BGM04.kvs...BGM0
00B4BF5C  35 2E 6B 76 73 00 00 00 42 47 4D 30 36 2E 6B 76  5.kvs...BGM06.kv
00B4BF6C  73 00 00 00 42 47 4D 30 37 2E 6B 76 73 00 00 00  s...BGM07.kvs...
00B4BF7C  42 47 4D 30 38 2E 6B 76 73 00 00 00 42 47 4D 30  BGM08.kvs...BGM0
00B4BF8C  39 2E 6B 76 73 00 00 00 42 47 4D 31 30 2E 6B 76  9.kvs...BGM10.kv
00B4BF9C  73 00 00 00 42 47 4D 31 31 2E 6B 76 73 00 00 00  s...BGM11.kvs...
*/

/*
�x�[�X�A�h���X
00871000   56               PUSH ESI


���̓������EDI��������[EBX+4]���Ȕԍ����ς�����ۂɋȔԍ�������͗l
00A120D1   6A 00            PUSH 0
00A120D3   50               PUSH EAX
00A120D4   8BCE             MOV ECX,ESI
00A120D6   E8 7539E6FF      CALL NOBU6HD_.00875A50
00A120DB   833B 00          CMP DWORD PTR DS:[EBX],0
00A120DE   75 44            JNZ SHORT NOBU6HD_.00A12124
00A120E0   57               PUSH EDI
00A120E1   8B7B 04          MOV EDI,DWORD PTR DS:[EBX+4]
00A120E4   85FF             TEST EDI,EDI
00A120E6   78 34            JS SHORT NOBU6HD_.00A1211C
00A120E8   83FF 0C          CMP EDI,0C
00A120EB   7D 2F            JGE SHORT NOBU6HD_.00A1211C
00A120ED   C1E7 04          SHL EDI,4
00A120F0   68 14BFB400      PUSH NOBU6HD_.00B4BF14                   ; ASCII "BGM\"
00A120F5   8BCE             MOV ECX,ESI
00A120F7   81C7 98ECBD00    ADD EDI,NOBU6HD_.00BDEC98
00A120FD   E8 0E30E6FF      CALL NOBU6HD_.00875110
00A12102   FF77 04          PUSH DWORD PTR DS:[EDI+4]  �� ������EBX+4����E���Ă��Ă���̂ŁAEBX+4�ɔԍ��������������Ă�͗l
00A12105   8BCE             MOV ECX,ESI
00A12107   E8 4430E6FF      CALL NOBU6HD_.00875150
00A1210C   56               PUSH ESI
00A1210D   E8 6E4A0000      CALL NOBU6HD_.00A16B80
00A12112   8B03             MOV EAX,DWORD PTR DS:[EBX]
00A12114   83C4 04          ADD ESP,4
00A12117   5F               POP EDI
00A12118   5E               POP ESI
00A12119   5B               POP EBX
00A1211A   5D               POP EBP
00A1211B   C3               RETN


*/


/*
*/
/*
00AEBEF0  2E 4E 36 00 4D 4F 56 49 45 5C 00 00 42 47 4D 5C.N6.MOVIE\..BGM\
00AEBF00  00 00 00 00 42 47 4D 30 30 2E 6B 76 73 00 00 00  ....BGM00.kvs...
00AEBF10  42 47 4D 30 31 2E 6B 76 73 00 00 00 42 47 4D 30  BGM01.kvs...BGM0
00AEBF20  32 2E 6B 76 73 00 00 00 42 47 4D 30 33 2E 6B 76  2.kvs...BGM03.kv
00AEBF30  73 00 00 00 42 47 4D 30 34 2E 6B 76 73 00 00 00  s...BGM04.kvs...
00AEBF40  42 47 4D 30 35 2E 6B 76 73 00 00 00 42 47 4D 30  BGM05.kvs...BGM0
00AEBF50  36 2E 6B 76 73 00 00 00 42 47 4D 30 37 2E 6B 76  6.kvs...BGM07.kv
00AEBF60  73 00 00 00 42 47 4D 30 38 2E 6B 76 73 00 00 00  s...BGM08.kvs...
00AEBF70  42 47 4D 30 39 2E 6B 76 73 00 00 00 42 47 4D 31  BGM09.kvs...BGM1
00AEBF80  30 2E 6B 76 73 00 00 00 42 47 4D 31 31 2E 6B 76  0.kvs...BGM11.kv
*/



#include "GameDataStruct.h"

static char szOnotherBGMFileName[MAX_PATH] = ""; // BGM�̃t�@�C������ύX����B
int iLastCallFuncBGMLocation = 0x2D; // �f�t�H���g�̍ŏ��̋Ȃ̍Đ��ꏊ

// BGM�̔ԍ������肳��鎞

static int iEBXOfBGMPlayingNumberDecide = 0;

static void OnTenshouExeBGMPlayingNumberDecideExecute() {
	// BGM�̃t�@�C�����̏����f�t�H���g�ɖ߂��B
	memcpy(nb6bgmtable, nb6bgmdefault, sizeof(nb6bgmdefault));

	if (iEBXOfBGMPlayingNumberDecide > 0) {
		BYTE *pBGMNO = (BYTE *)iEBXOfBGMPlayingNumberDecide;
		int iBGMNum = *(pBGMNO+4);

		char *szDefaultFileName = (char *)nb6bgmdefault[iBGMNum].iBGMFileNameAddress;

		// �V�ċL�N���X�ւ̖₢���킹
		String^ strManagedBGMNewerFileName = "";
		
		try {
			// ���[�U�[�N���X���G���[
			if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
			}

			//�R�p�����[�^�̌^��z��ɓ���� 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(3);
			types[0] = int::typeid;
			types[1] = int::typeid;
			types[2] = System::String::typeid;

			//���\�b�h�̏����擾 
			MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�a�f�l�Đ����O", types);
			if (!method) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X My_�a�f�l�Đ����O ���\�b�h������");
			}

			//�R�̃p�����^�����ۂɓ����
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(3);
			prms[0] = iBGMNum;
			prms[1] = iLastCallFuncBGMLocation;
			prms[2] = gcnew String(szDefaultFileName);

			�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�a�f�l�Đ����O" << endl;

			// ���������Ŏ��s
			strManagedBGMNewerFileName = (String^)method->Invoke(nullptr, prms);
		}

		// �G���[�Ȃ̂œ����̂��̂����s����B
		catch (Exception^) {
			�f�o�b�O�o�� << "�V�ċL�N���X::On_�a�f�l�Đ����O" << endl;
			strManagedBGMNewerFileName = �V�ċL�N���X::On_�a�f�l�Đ����O(iBGMNum, iLastCallFuncBGMLocation, gcnew String(szDefaultFileName));
		}
		

		// �L���ȃt�@�C�������Ԃ���Ă�����A���̃t�@�C�����ւ̃|�C���^���w���悤�Ƀe�[�u���̊Y���ԍ��̃t�@�C�����|�C���^��ύX����B
		if (strManagedBGMNewerFileName->Length > 0 ) {
			string nativeFileName = to_native_string(strManagedBGMNewerFileName);
			strcpy(szOnotherBGMFileName, nativeFileName.c_str() );

			// �Đ��̑S�̃e�[�u���̒��ŁA���ꂩ��Đ����悤�Ƃ���t�@�C�����ւ̃|�C���^�ɏ�̃o�b�t�@�̃A�h���X�����Ă��܂��B
			nb6bgmtable[iBGMNum].iBGMFileNameAddress = (int)szOnotherBGMFileName;

		}

		�f�o�b�O�o�� << "BGMPlayingNumberDecide:" << dec << iBGMNum << endl;
		�f�o�b�O�o�� << "BGMPlayingNumberDecide:" << szDefaultFileName << endl;
	}
	else {
		�f�o�b�O�o�� << "BGMPlayingNumberDecide:" << "BGM����" << endl;
	}
}


/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

00A120D1   6A 00            PUSH 0
00A120D3   50               PUSH EAX
00A120D4   8BCE             MOV ECX,ESI
00A120D6   E8 7539E6FF      CALL NOBU6HD_.00875A50
�������� JMP TSMod.OnTSExeBGMPlayingNumberDecide �Ə��������Ă����ۂ̏���
00A120DB   833B 00          CMP DWORD PTR DS:[EBX],0
00A120DE   75 44            JNZ SHORT NOBU6HD_.00A12124
00A120E0   57               PUSH EDI
*/
static int pTenshouExeJumpFromToOnTenshouExeBGMPlayingNumberDecide = 0xA120D6 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeBGMPlayingNumberDecide�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeBGMPlayingNumberDecide = 0x875A50 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeBGMPlayingNumberDecide = 0xA120DB - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																						  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeBGMPlayingNumberDecide() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEBXOfBGMPlayingNumberDecide, ebx; // �Ȕԍ��������Ă���|�C���^�A�h���X�Ǝv����B

		// ���X�̏���
		call pTenshouExeCallFuncToOnTenshouExeBGMPlayingNumberDecide

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeBGMPlayingNumberDecideExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeBGMPlayingNumberDecide
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeBGMPlayingNumberDecide() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeBGMPlayingNumberDecide,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeBGMPlayingNumberDecide,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeBGMPlayingNumberDecide	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeBGMPlayingNumberDecide
	);

}


