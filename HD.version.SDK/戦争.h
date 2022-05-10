#pragma once

#include "戦争_ターン.h"
#include "戦争_気象.h"
#include "戦争_ヘックス.h"

public ref class 戦争情報型 {
public:
	気象情報型^ 気象;

	ヘックス情報型^ ヘックス;

	戦争ターン情報型^ ターン;

	property bool Is_戦争中 {
		bool get();
	}
	property bool Is_野戦中 {
		bool get();
	}
	property bool Is_籠城戦中 {
		bool get();
	}
};



public ref class 戦争開始パラメタ型 {
public:
	int 守備側軍団番号;		// 守備側の軍団番号
	int 攻撃側軍団番号;		// 攻めた側の軍団番号
};


