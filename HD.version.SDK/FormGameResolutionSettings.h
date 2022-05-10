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

	// ラベル
	Label^ lblResolution;
	// 解像度のリストボックス
	ListBox^ lboxResolution;

	// 全て設定のボタン
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
		lblResolution->Text = "ゲーム時に以下の画面解像度に切替:";
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
		btnAllSetting->Text = "設定を保存";
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
		// このプロジェクトのアセンブリのタイプを取得。
		System::Reflection::Assembly^ prj_assebmly = GetType()->Assembly;
		System::Resources::ResourceManager^ r = gcnew System::Resources::ResourceManager(String::Format("{0}.SemiFullScreenMod", prj_assebmly->GetName()->Name), prj_assebmly);

		System::Drawing::Icon^ iconform = (System::Drawing::Icon^)(r->GetObject("icon"));
		this->Icon = iconform;

	}

	void SetDisplayResolutions() {
		static DEVMODE devmode;          // ディスプレイモード

		char sz[100];
		for (int index = 0; TRUE; index++) {
			// 列挙
			if (!EnumDisplaySettings(NULL, index, &devmode)) {
				break;
			}

			if (devmode.dmBitsPerPel >= 16 && devmode.dmPelsWidth >= 1024 && devmode.dmPelsHeight >= 720) { // 1024以下は出す必要がない
				wsprintf(sz, " %4d x %4d", devmode.dmPelsWidth, devmode.dmPelsHeight);

				// 文字列で連結したものをキー、幅・高さの構造体を値として格納。mapを使うのは、EnumDisplaySettingsでは同じ解像度がたくさん出てくるため。
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

		// ちょっと格納方法にしくったか・・・
		// パースしたものと同じものを選択
		BOOL isExist = false;
		for (int i = 0; i < lboxResolution->Items->Count; i++) {
			String^ key = (String^)lboxResolution->Items[i];

			Point^ ptResolution = (Point ^)htResolution[key];
			// if ( ptResolution->X == param.ScreenW && map_resolution[sz].y == param.ScreenH) {
				lboxResolution->SelectedIndex = i;
			// }
		}

		// 選択されたものが存在しなかったら、現在のデスクトップ解像度と同じものを選択する。
		// (これは絶対に選ばれるはずだが･･･)
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
			iSelectedIndex = lboxResolution->Items->Count - 1; // ありえないはずだが、万が一の時は、最後の要素の番号とする。
		}
		String^ key = (String^)lboxResolution->Items[iSelectedIndex];
		char sz[100];
		wsprintf(sz, "%s", key);
		// int w = map_resolution[sz].x;
		// int h = map_resolution[sz].y;
	}



};
