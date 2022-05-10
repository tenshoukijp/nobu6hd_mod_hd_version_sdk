#pragma once

#include "GameDataStruct.h"

char szLastestRequestScenarioOriginalFileName[MAX_PATH] = ""; // �v�����ꂽ���X�̃V�i���I�n�̍Ō�̃t�@�C�����B���݂̐i�s�����Ԗڂ̃X���b�g���Ȃ̂��̏d�v�ȃJ�M�B
char szLastestRequestScenarioFileName[MAX_PATH] = "";

namespace Native {
	string On_�t�@�C���v����(string strFileName, int iBufAddress) {

		// �V�i���I�t�@�C�����ł���΁A�u�V�i���I�t�@�C�����v������Ă���v�Ƃ��āA��ŃV�i���I�t�@�C����ۑ����Ă����B
		bool isScenarioFile = false;
		if (strFileName.find("sndata") != string::npos && strFileName.find(".dat") != string::npos) {
			�f�o�b�O�o�� << strFileName << endl;
			isScenarioFile = true;
			// �I���W�i���̃t�@�C����������Ă����B���Ԗڂ̃X���b�g�ɃA�N�Z�X�����̂��̏d�v�ȏ��B
			strcpy(szLastestRequestScenarioOriginalFileName, strFileName.data());
		}

		String^ strManagedRet = "";
		
		try {
			// ���[�U�[�N���X���G���[
			if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
			}

			// �P�p�����[�^�̌^��z��ɓ���� 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
			types[0] = System::String::typeid;

			//���\�b�h�̏����擾 
			MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�f�[�^�t�@�C���Ǎ����O", types);
			if (!method) {
				throw gcnew Exception("���[�U�[�V�ċL�N���X My_�f�[�^�t�@�C���Ǎ����O ���\�b�h������");
			}

			// �P�̃p�����^�����ۂɓ����
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
			prms[0] = to_managed_string(strFileName);

			�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�f�[�^�t�@�C���Ǎ����O" << endl;

			// ���������Ŏ��s
			strManagedRet = (String^)method->Invoke(nullptr, prms);
		}

		// �G���[�Ȃ̂œ����̂��̂����s����B
		catch (Exception^) {
			�f�o�b�O�o�� << "�V�ċL�N���X::On_�f�[�^�t�@�C���Ǎ����O" << endl;
			strManagedRet = �V�ċL�N���X::On_�f�[�^�t�@�C���Ǎ����O(to_managed_string(strFileName));
		}

		
		
		if (strManagedRet->Length > 0) {
			string strNativeRet = to_native_string(strManagedRet);
			strcpy((char *)iBufAddress, strNativeRet.data());

			// �V�i���I�t�@�C���v���̃t���O�������Ă���΁A�Ō�ɃA�N�Z�X�����V�i���I�t�@�C�����Ƃ��ĕۑ�
			if (isScenarioFile) {
				strcpy(szLastestRequestScenarioFileName, strNativeRet.data());
			}
			return strNativeRet;
		}
		
		// �V�i���I�t�@�C���v���̃t���O�������Ă���΁A�Ō�ɃA�N�Z�X�����V�i���I�t�@�C�����Ƃ��ĕۑ�
		if (isScenarioFile) {
			strcpy(szLastestRequestScenarioFileName, strFileName.data());
		}
		return strFileName;
	}
}