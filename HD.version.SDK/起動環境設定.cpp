#include "GameDataStruct.h"


起動環境設定情報型::起動環境設定情報型() {
	regkey = Microsoft::Win32::Registry::CurrentUser->CreateSubKey(R"(Software\KoeiTecmo\Nobu6HD\Configs)");
}


起動環境設定情報型::~起動環境設定情報型() {
	this->!起動環境設定情報型();
}

起動環境設定情報型::!起動環境設定情報型() {
	regkey->Close();
}

int 起動環境設定情報型::ウィンドウモード::get() {
	return (int)regkey->GetValue("WINDOW_MODE");
}

void 起動環境設定情報型::ウィンドウモード::set(int value) {
	if (0 <= value && value <= 列挙::起動環境設定::ウィンドウモード::ウィンドウ) {
		regkey->SetValue("WINDOW_MODE", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int 起動環境設定情報型::起動モニター::get() {
	return (int)regkey->GetValue("ADAPTER_NO");
}

void 起動環境設定情報型::起動モニター::set(int value) {
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

環境解像度型^ 起動環境設定情報型::画面サイズ::get() {
	int width = (int)regkey->GetValue("WIDTH");
	int height = (int)regkey->GetValue("HEIGHT");
	環境解像度型^ resolution = gcnew 環境解像度型();
	resolution->Ｘ = width;
	resolution->Ｙ = height;
	return resolution;
}

void 起動環境設定情報型::画面サイズ::set(環境解像度型^ value) {
	
	regkey->SetValue("WIDTH", value->Ｘ, Microsoft::Win32::RegistryValueKind::DWord);
	regkey->SetValue("HEIGHT", value->Ｙ, Microsoft::Win32::RegistryValueKind::DWord);
}


int 起動環境設定情報型::ムービー::get() {
	return (int)regkey->GetValue("MOVIE_PLAY");
}

void 起動環境設定情報型::ムービー::set(int value) {
	if (0 <= value && value <= 列挙::起動環境設定::ムービー::あり) {
		regkey->SetValue("MOVIE_PLAY", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int 起動環境設定情報型::ＢＧＭ::get() {
	return (int)regkey->GetValue("INITIALIZE_BGM");
}

void 起動環境設定情報型::ＢＧＭ::set(int value) {
	if (0 <= value && value <= 列挙::起動環境設定::ＢＧＭ::あり) {
		regkey->SetValue("INITIALIZE_BGM", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int 起動環境設定情報型::効果音::get() {
	return (int)regkey->GetValue("INITIALIZE_SE");
}

void 起動環境設定情報型::効果音::set(int value) {
	if (0 <= value && value <= 列挙::起動環境設定::効果音::あり) {
		regkey->SetValue("INITIALIZE_SE", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}

int 起動環境設定情報型::カーソルモード::get() {
	return (int)regkey->GetValue("HW_CURSOR");
}

void 起動環境設定情報型::カーソルモード::set(int value) {
	if (0 <= value && value <= 列挙::起動環境設定::カーソルモード::Software) {
		regkey->SetValue("HW_CURSOR", value, Microsoft::Win32::RegistryValueKind::DWord);
	}
}


