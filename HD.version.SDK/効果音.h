#pragma once

#include "効果音列挙.h"

#define 効果音ハンドル型 int

public ref class 効果音情報型 {
protected:
	static 効果音ハンドル型 iSoundID = 0;
public:

	/// <summary>列挙</summary>
	効果音ハンドル型 Do_効果音再生(int 効果音音源);

};

