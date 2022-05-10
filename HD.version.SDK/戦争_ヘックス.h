#pragma once

#include "戦争_ヘックス列挙.h"

public ref class ヘックス情報型 {
public:
};


public ref class ヘックス位置型 : public Ｄ２Ｄ位置型 {
public:
	ヘックス位置型(double Ｘ位置, double Ｙ位置) {
		this->Ｘ = Ｘ位置;
		this->Ｙ = Ｙ位置;
	}
	ヘックス位置型() {
		this->Ｘ = 0;
		this->Ｙ = 0;
	}

	property int 役割 {
		int get();
	}

	property int 高さ {
		int get();
	}

	property int 炎上 {
		int get();
	}
};

public ref class ヘックスベクトル型 : public Ｄ２Ｄベクトル型 {
public:
	ヘックスベクトル型(double Ｘ成分, double Ｙ成分) {
		this->Ｘ = Ｘ成分;
		this->Ｙ = Ｙ成分;
	}
	ヘックスベクトル型() {
		this->Ｘ = 0;
		this->Ｙ = 0;
	}

	property int 間隔 {
		int get();
	}
};

ヘックスベクトル型^ operator-(ヘックス位置型^ p1, ヘックス位置型^ p2);
