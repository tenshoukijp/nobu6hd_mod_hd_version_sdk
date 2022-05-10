#pragma once

#include <windows.h>
#include <string>

using namespace std;

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections;

ref class FormGameResolutionSettings : public Form {

public:
	static Form^ form;

private:

	// ���x��
	Label^ lblResolution;
	// �𑜓x�̃��X�g�{�b�N�X
	ListBox^ lboxResolution;

	// �S�Đݒ�̃{�^��
	Button^ btnAllSetting;

	Hashtable^ htResolution;

public:
	FormGameResolutionSettings() {
		return;
		htResolution = gcnew Hashtable();

		this->Height = 280;
		this->Width = 300;
		this->MaximizeBox = false;

		this->FormBorderStyle = ::FormBorderStyle::FixedSingle;
		this->ShowInTaskbar = false;

//		SetFormIcon();

		lblResolution = gcnew Label();
		lblResolution->Text = "�Q�[�����Ɉȉ��̉�ʉ𑜓x�ɐؑ�:";
		lblResolution->Left = 10;
		lblResolution->Top = 10;
		lblResolution->Width = this->ClientSize.Width - 20;
		lblResolution->Height = 15;

		lboxResolution = gcnew ListBox();
		lboxResolution->Left = 10;
		lboxResolution->Top = 30;
		lboxResolution->Height = 147;
		lboxResolution->Width = 120;
		lboxResolution->Font = gcnew System::Drawing::Font("MS Gothic", 10);

		btnAllSetting = gcnew Button();
		btnAllSetting->Text = "�ݒ��ۑ�";
		btnAllSetting->Height = 30;
		btnAllSetting->Width = 100;
		btnAllSetting->Top = 195;
		btnAllSetting->Left = (this->ClientSize.Width - btnAllSetting->Width) / 2;

		btnAllSetting->Click += gcnew EventHandler(this, &FormGameResolutionSettings::btnAllSetting_Click);


		this->Controls->Add(lblResolution);
		this->Controls->Add(lboxResolution);
		this->Controls->Add(btnAllSetting);

		// SetDisplayResolutions();
	}

	void ReadGameResolution() {

	}

	void SetFormIcon() {
		// ���̃v���W�F�N�g�̃A�Z���u���̃^�C�v���擾�B
		System::Reflection::Assembly^ prj_assebmly = GetType()->Assembly;
		System::Resources::ResourceManager^ r = gcnew System::Resources::ResourceManager(String::Format("{0}.SemiFullScreenMod", prj_assebmly->GetName()->Name), prj_assebmly);

		System::Drawing::Icon^ iconform = (System::Drawing::Icon^)(r->GetObject("icon"));
		this->Icon = iconform;

	}

	void SetDisplayResolutions() {
		static DEVMODE devmode;          // �f�B�X�v���C���[�h

		char sz[100];
		for (int index = 0; TRUE; index++) {
			// ��
			if (!EnumDisplaySettings(NULL, index, &devmode)) {
				break;
			}

			if (devmode.dmBitsPerPel >= 16 && devmode.dmPelsWidth >= 1024 && devmode.dmPelsHeight >= 720) { // 1024�ȉ��͏o���K�v���Ȃ�
				wsprintf(sz, " %4d x %4d", devmode.dmPelsWidth, devmode.dmPelsHeight);

				// ������ŘA���������̂��L�[�A���E�����̍\���̂�l�Ƃ��Ċi�[�Bmap���g���̂́AEnumDisplaySettings�ł͓����𑜓x����������o�Ă��邽�߁B
				Point^ rs;
				rs->X = devmode.dmPelsWidth;
				rs->Y = devmode.dmPelsHeight;
				String^ key = gcnew String(sz);
				htResolution[key] = rs;
			}

			index++;
		}

		for each ( String^ key in htResolution ) {
			lboxResolution->Items->Add( key );
		}

		// ������Ɗi�[���@�ɂ����������E�E�E
		// �p�[�X�������̂Ɠ������̂�I��
		BOOL isExist = false;
		for (int i = 0; i < lboxResolution->Items->Count; i++) {
			String^ key = (String^)lboxResolution->Items[i];

			Point^ ptResolution = (Point ^)htResolution[key];
			// if ( ptResolution->X == param.ScreenW && map_resolution[sz].y == param.ScreenH) {
				lboxResolution->SelectedIndex = i;
			// }
		}

		// �I�����ꂽ���̂����݂��Ȃ�������A���݂̃f�X�N�g�b�v�𑜓x�Ɠ������̂�I������B
		// (����͐�΂ɑI�΂��͂��������)
		if (lboxResolution->SelectedIndex < 0) {
			for (int i = 0; i < lboxResolution->Items->Count; i++) {
				String^ key = (String^)lboxResolution->Items[i];
				Point^ ptResolution = (Point ^)htResolution[key];
				if (ptResolution->X == System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width &&
				 	ptResolution->Y == System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height) {
					lboxResolution->SelectedIndex = i;
				}
			}
		}

	}

	void btnAllSetting_Click(Object^ o, EventArgs^ e) {

		int iSelectedIndex = lboxResolution->SelectedIndex;
		if (iSelectedIndex < 0) {
			iSelectedIndex = lboxResolution->Items->Count - 1; // ���肦�Ȃ��͂������A������̎��́A�Ō�̗v�f�̔ԍ��Ƃ���B
		}
		String^ key = (String^)lboxResolution->Items[iSelectedIndex];
		char sz[100];
		wsprintf(sz, "%s", key);
		// int w = map_resolution[sz].x;
		// int h = map_resolution[sz].y;
	}



};
