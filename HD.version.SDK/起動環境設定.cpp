#include "GameDataStruct.h"


�N�����ݒ���^::�N�����ݒ���^() {
	regkey = Microsoft::Win32::Registry::CurrentUser->CreateSubKey(R"(Software\KoeiTecmo\Nobu6HD\Configs)");
}


�N�����ݒ���^::~�N�����ݒ���^() {
	this->!�N�����ݒ���^();
}

�N�����ݒ���^::!�N�����ݒ���^() {
	regkey->Close();
}

int �N�����ݒ���^::�E�B���h�E���[�h::get() {
	return (int)regkey->GetValue("WINDOW_MODE");
}

void �N�����ݒ���^::�E�B���h�E���[�h::set(int value) {
	if (0 <= value && value <= ��::�N�����ݒ�::�E�B���h�E���[�h::�E�B���h�E) {
		regkey->SetValue("WINDOW_MODE", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int �N�����ݒ���^::�N�����j�^�[::get() {
	return (int)regkey->GetValue("ADAPTER_NO");
}

void �N�����ݒ���^::�N�����j�^�[::set(int value) {
	int iScreenCnt = 0;
	for each (auto screen in System::Windows::Forms::Screen::AllScreens) {
		iScreenCnt++;
	}

	if (0 <= value && value <= iScreenCnt) {
		try {
			regkey->SetValue("ADAPTER_NO", value, Microsoft::Win32::RegistryValueKind::DWord);
		}
		catch (Exception^ e) {
			System::Windows::Forms::MessageBox::Show(e->Message);
		}
	}
}

���𑜓x�^^ �N�����ݒ���^::��ʃT�C�Y::get() {
	int width = (int)regkey->GetValue("WIDTH");
	int height = (int)regkey->GetValue("HEIGHT");
	���𑜓x�^^ resolution = gcnew ���𑜓x�^();
	resolution->�w = width;
	resolution->�x = height;
	return resolution;
}

void �N�����ݒ���^::��ʃT�C�Y::set(���𑜓x�^^ value) {
	
	regkey->SetValue("WIDTH", value->�w, Microsoft::Win32::RegistryValueKind::DWord);
	regkey->SetValue("HEIGHT", value->�x, Microsoft::Win32::RegistryValueKind::DWord);
}


int �N�����ݒ���^::���[�r�[::get() {
	return (int)regkey->GetValue("MOVIE_PLAY");
}

void �N�����ݒ���^::���[�r�[::set(int value) {
	if (0 <= value && value <= ��::�N�����ݒ�::���[�r�[::����) {
		regkey->SetValue("MOVIE_PLAY", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int �N�����ݒ���^::�a�f�l::get() {
	return (int)regkey->GetValue("INITIALIZE_BGM");
}

void �N�����ݒ���^::�a�f�l::set(int value) {
	if (0 <= value && value <= ��::�N�����ݒ�::�a�f�l::����) {
		regkey->SetValue("INITIALIZE_BGM", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int �N�����ݒ���^::���ʉ�::get() {
	return (int)regkey->GetValue("INITIALIZE_SE");
}

void �N�����ݒ���^::���ʉ�::set(int value) {
	if (0 <= value && value <= ��::�N�����ݒ�::���ʉ�::����) {
		regkey->SetValue("INITIALIZE_SE", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int �N�����ݒ���^::�J�[�\�����[�h::get() {
	return (int)regkey->GetValue("HW_CURSOR");
}

void �N�����ݒ���^::�J�[�\�����[�h::set(int value) {
	if (0 <= value && value <= ��::�N�����ݒ�::�J�[�\�����[�h::Software) {
		regkey->SetValue("HW_CURSOR", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}


