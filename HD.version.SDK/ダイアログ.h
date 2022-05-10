#pragma once

#include "ダイアログ列挙.h"

public ref class ダイアログ情報型 {
public:
	void Show_確認_中央(String^ メッセージ);
	void Show_確認_下部(String^ メッセージ);
	void Show_情報_中央(String^ メッセージ);
	int  Show_実行か取消_中央(String^ メッセージ);
};

