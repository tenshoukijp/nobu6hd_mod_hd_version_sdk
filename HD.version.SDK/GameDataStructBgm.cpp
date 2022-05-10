#pragma once


#include "GameDataStruct.h"
#include "ManagedString.h"

static char szOverWriteBGMDir[MAX_PATH];

namespace Native {
	/*
	void On_�a�f�l�t�H���_�v����() {
		String^ managed_bgmdir = �V�ċL�N���X::On_�a�f�l�t�H���_�v����();
		string native_bgmdir = to_native_string(managed_bgmdir);

		// ���ۂɂ��̃f�B���N�g�������݂����
		if ( System::IO::Directory::Exists( to_managed_string(native_bgmdir) ) ) {

			// �������AHD.CustomMod�ŏ��������Ă�����
			if (native_bgmdir.size() > 0) {

				native_bgmdir += "\\"; // �Ō��\��t����B
				strcpy(szOverWriteBGMDir, native_bgmdir.c_str());

				// BGM\ �Ƃ���������ւ̃A�h���X���AszOverWriteBGMDir�̃A�h���X�ւƏ���������B
				int iBufferAddress = (int)szOverWriteBGMDir;

				// �Y���̃��W���[����𒴂��Ă�̂ł�����̃v���Z�X�������łȂ��Ƃ��܂������Ȃ��B
				WriteProcessMemory(GetCurrentProcess(), (LPVOID)nb6bgmdirptr, (LPVOID)&iBufferAddress, sizeof(int), NULL);
			}
		}
	}
	*/
}



/*

������BGM�������Ă���
009B1FC0   68 FCBEAE00      PUSH NOBU6HD_.00AEBEFC                   ; ASCII "BGM\"
009B1FC5   8BCE             MOV ECX,ESI
009B1FC7   81C7 98ECB700    ADD EDI,NOBU6HD_.00B7EC98
009B1FCD   E8 3E31E6FF      CALL NOBU6HD_.00815110
009B1FD2   FF77 04          PUSH DWORD PTR DS:[EDI+4]
009B1FD5   8BCE             MOV ECX,ESI
009B1FD7   E8 7431E6FF      CALL NOBU6HD_.00815150
009B1FDC   56               PUSH ESI
009B1FDD   E8 7E4A0000      CALL NOBU6HD_.009B6A60
009B1FE2   8B03             MOV EAX,DWORD PTR DS:[EBX]
*/


/*
00B7EC98  00 00 00 00 04 BF AE 00 00 00 00 00 00 00 00 00  ....��.........	�� ���̂��ꂼ�ꂪ�Ȕԍ��ƁA���ɂ���t�@�C�����ւ̃|�C���^
00B7ECA8  01 00 00 00 10 BF AE 00 01 00 00 00 00 00 00 00  ...��........
00B7ECB8  02 00 00 00 1C BF AE 00 01 00 00 00 00 00 00 00  ...��........
00B7ECC8  03 00 00 00 28 BF AE 00 01 00 00 00 00 00 00 00  ...(��........
00B7ECD8  04 00 00 00 34 BF AE 00 01 00 00 00 00 00 00 00  ...4��........
00B7ECE8  05 00 00 00 40 BF AE 00 01 00 00 00 00 00 00 00  ...@��........
00B7ECF8  06 00 00 00 4C BF AE 00 01 00 00 00 00 00 00 00  ...L��........
00B7ED08  07 00 00 00 58 BF AE 00 01 00 00 00 00 00 00 00  ...X��........
00B7ED18  08 00 00 00 64 BF AE 00 01 00 00 00 00 00 00 00  ...d��........
00B7ED28  09 00 00 00 70 BF AE 00 01 00 00 00 00 00 00 00  ....p��........
00B7ED38  0A 00 00 00 7C BF AE 00 01 00 00 00 00 00 00 00  ....|��........
00B7ED48  0B 00 00 00 88 BF AE 00 00 00 00 00 00 00 00 00  ...���.........

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


