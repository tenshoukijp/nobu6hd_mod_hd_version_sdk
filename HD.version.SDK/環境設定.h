#pragma once

#include "環境設定列挙.h"

public ref class 環境解像度型 {
public:
	環境解像度型() {}
	環境解像度型(int Ｘ, int Ｙ) { this->Ｘ = Ｘ; this->Ｙ = Ｙ; }
	int Ｘ;
	int Ｙ;
};


public ref class 環境設定情報型 {
public:
	/// <summary>列挙</summary>
	property int 自動メッセージ送り {
		int get();
	}

	/// <summary>列挙</summary>
	property int 他国の戦争 {
		int get();
	}

	/// <summary>列挙</summary>
	property int 自国の戦争 {
		int get();
	}

	/// <summary>value or 列挙</summary>
	property int 音楽音量 {
		int get();
	}

	/// <summary>value or 列挙</summary>
	property int 効果音音量 {
		int get();
	}

	/// <summary>列挙</summary>
	property int 年号表示 {
		int get();
	}

	/// <summary>列挙</summary>
	property int ウィンドウモード {
		int get();
	}

	property 環境解像度型^ 画面サイズ {
		環境解像度型^ get();
	}

	/// <summary>列挙</summary>
	property int 右クリックキャンセル {
		int get();
	}

	/// <summary>列挙</summary>
	property int 静観終了キー {
		int get();
	}

	/// <summary>列挙</summary>
	property int 自動セーブ {
		int get();
	}
};


