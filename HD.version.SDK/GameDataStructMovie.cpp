#pragma once


#include "GameDataStruct.h"
#include "ManagedString.h"

static char szOverWriteMOVIEDir[MAX_PATH];

namespace Native {
	/*
	void On_�l�n�u�h�d�t�H���_�v����() {

		String^ managed_moviedir = �V�ċL�N���X::On_�l�n�u�h�d�t�H���_�v����();
		string native_moviedir = to_native_string(managed_moviedir);

		// ���ۂɂ��̃f�B���N�g�������݂����
		if (System::IO::Directory::Exists(to_managed_string(native_moviedir))) {

			// �������AHD.CustomMod�ŏ��������Ă�����
			if (native_moviedir.size() > 0) {

				native_moviedir += "\\"; // �Ō��\��t����B
				strcpy(szOverWriteMOVIEDir, native_moviedir.c_str());

				// MOVIE\ �Ƃ���������ւ̃A�h���X���AszOverWriteMOVIEDir�̃A�h���X�ւƏ���������B
				int iBufferAddress = (int)szOverWriteMOVIEDir;

				// �Y���̃��W���[����𒴂��Ă�̂ł�����̃v���Z�X�������łȂ��Ƃ��܂������Ȃ��B
				WriteProcessMemory(GetCurrentProcess(), (LPVOID)nb6moviedirptr, (LPVOID)&iBufferAddress, sizeof(int), NULL);
			}
		}
	}
	*/
}