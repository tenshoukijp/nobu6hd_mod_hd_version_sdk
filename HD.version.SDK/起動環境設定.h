#pragma once

#include "起動環境設定列挙.h"

public ref class 起動環境設定情報型 {
protected:
	Microsoft::Win32::RegistryKey^ regkey;
public:
	起動環境設定情報型();
	~起動環境設定情報型();
	!起動環境設定情報型();

	/// <summary>列挙</summary>
	property int ウィンドウモード {
		int get();
		void set(int value);
	}

	property 環境解像度型^ 画面サイズ {
		環境解像度型^ get();
		void set(環境解像度型^ value);
	}

	property int 起動モニター {
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int ムービー {
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int ＢＧＭ {
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 効果音 {
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int カーソルモード {
		int get();
		void set(int value);
	}

};


