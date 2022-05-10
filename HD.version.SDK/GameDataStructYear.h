#pragma once

#include <windows.h>

#include "GetWarekiFromYMD.h"


////////////////////////////////////////////////////////////////////////////
// NB6 天翔記
/*
[年号情報(3*1)]

0-1		年数(1454からの経過数)
2		季節(0=春,1=夏,2=秋,3=冬)
*/
struct NB6YEAR
{
	WORD year;			// 年数(1454からの経過数)	 ⇒ ここ直接ではなく、getYearADで得ること
	char season;		// 季節(0=春,1=夏,2=秋,3=冬) ⇒ ここ直接ではなくgetSeasonNameで得ること
};



// 1454年からの差分となっている年を西暦に直す
int getYearAD();

// ゲームの開始年。デフォルトは1454年
constexpr int getStartYearAD();


// 現在の季節名を得る
char* getSeasonName();



