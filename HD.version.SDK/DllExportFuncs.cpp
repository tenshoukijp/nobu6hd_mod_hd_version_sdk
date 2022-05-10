#include <windows.h>
#include <process.h>

#include "const_def.h"
#include "HookFuncs.h"
#include "GameDataStruct.h"

#pragma data_seg (".HDVERSIONSEG")
int bViewingLauncher = 0;
#pragma data_seg()


extern BOOL CheckCurrentProcessHeapInfo();
extern BOOL CheckCurrentProcessBaseInfo();

// ���C���̃Q�[����ʂɂȂ����珉�߂Ď��s�B
// ����܂ł́A�������Ȃ��B
void OnInitializeThread(void *) {


	if (!CheckCurrentProcessBaseInfo()) {
		Windows::Forms::MessageBox::Show("HD.version�̑Ώۃo�[�W�����ł͂���܂���B\n" "HD.version�͎��s���܂���B");
		return;
	}

	// ���̋L�q�K�v!!
	�f�o�b�O�o�� << "�`�F�b�N�|�C���g1" << endl;

	// �����`���[�̋N��
	if (bViewingLauncher == 0) {
		if (::FindWindow(NOBU_6HD_LAUNCHER_WINDOW, NULL)) {
			�V�ċL�N���X::__PRIVATE_ON_LNCH_WINDOW__();

			try {
				// ���[�U�[�N���X���G���[
				if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
					throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
				}

				//���\�b�h�̏����擾 
				MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�����`���[�E�B���h�E�N����");
				if (!method) {
					throw gcnew Exception("���[�U�[�V�ċL�N���X My_�����`���[�E�B���h�E�N���� ���\�b�h������");
				}

				�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�����`���[�E�B���h�E�N����" << endl;

				// ���������Ŏ��s
				method->Invoke(nullptr, nullptr);
			}

			// �G���[�Ȃ̂œ����̂��̂����s����B
			catch (Exception^) {
				�f�o�b�O�o�� << "�V�ċL�N���X::On_�����`���[�E�B���h�E�N����" << endl;
				�V�ċL�N���X::On_�����`���[�E�B���h�E�N����();
			}


			bViewingLauncher = 1;

			// ���̋L�q�K�v!!
			�f�o�b�O�o�� << "�`�F�b�N�|�C���g2" << endl;

			return;
		}
	}

	�f�o�b�O�o�� << "�`�F�b�N�|�C���g3" << endl;

	// �Q�[���E�B���h�E�̋N����҂B
	while (TRUE) {
		if (::FindWindow(NOBU_6HD_GAMEMAIN_WINDOW, NULL)) {
			break;
		}
		Sleep(1);
	}

	// �e��̍\���̂ւ̃|�C���^�̃A�h���X��ݒ�
	SetGameDataStructPointer();

	// �W�����v�֐��B��S�ēo�^
	RegisterFunctionsOfWriteAsmJumperAndReturn();

	// �V�ċL���̂̊֐��𗘗p�o����悤�ɃA�Z���u���ō\�z����B
	ReplaceWrapperCallFunctions();

	// BGM�̃f�B���N�g�����㏑��
	// Native::On_�a�f�l�t�H���_�v����();
	// OutputDebugString("On_�a�f�l�t�H���_�v����");

	// Movie�̃f�B���N�g�����㏑��
	// Native::On_�l�n�u�h�d�t�H���_�v����();
	// OutputDebugString("On_�l�n�u�h�d�t�H���_�v����");


	�V�ċL�N���X::__PRIVATE_ON_GAME_WINDOW__();

	try {
		// ���[�U�[�N���X���G���[
		if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
		}

		//���\�b�h�̏����擾 
		MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�Q�[���E�B���h�E�N����");
		if (!method) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X My_�Q�[���E�B���h�E�N���� ���\�b�h������");
		}

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�����`���[�E�B���h�E�N����" << endl;

		// ���������Ŏ��s
		method->Invoke(nullptr, nullptr);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_�Q�[���E�B���h�E�N����" << endl;
		�V�ċL�N���X::On_�Q�[���E�B���h�E�N����();
	}

	
	bViewingLauncher = 0;
}


void WINAPI OnInitialize(void *param) {
	// �X���b�h�Ŏ��s
	_beginthread(OnInitializeThread, 0, NULL);
}


void WINAPI OnFinalize() {
	// �����͎��s����Ȃ��B��������n�ɋ߂��ꏊ�̂��̂��t�b�N���Ă����K�v������B
}