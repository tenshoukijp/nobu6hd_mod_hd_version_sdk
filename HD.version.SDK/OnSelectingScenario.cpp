
#include "GameDataStruct.h"

void On_SelectingScenario(char *szScenarioFileName) {
	�f�o�b�O�o�� << "�V�i���I�I���֐�:" << szScenarioFileName << endl;

	try {
		// ���[�U�[�N���X���G���[
		if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
		}

		// �P�p�����[�^�̌^��z��ɓ���� 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
		types[0] = System::String::typeid;

		//���\�b�h�̏����擾 
		MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�V�i���I�I�𒼌�", types);
		if (!method) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X My_�V�i���I�I�𒼌� ���\�b�h������");
		}

		// �P�̃p�����^�����ۂɓ����
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
		prms[0] = gcnew String(szScenarioFileName);

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�V�i���I�I�𒼌�" << endl;

		// ���������Ŏ��s
		method->Invoke(nullptr, prms);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_�V�i���I�I�𒼌�" << endl;
		�V�ċL�N���X::On_�V�i���I�I�𒼌�(gcnew String(szScenarioFileName));
	}
	
}
