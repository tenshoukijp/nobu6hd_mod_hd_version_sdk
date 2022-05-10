#include "GameDataStruct.h"

// 現在のゲーム進行中の年数を得る。
int getYearAD() {
	return nb6year.year + getStartYearAD();
}


// ゲームの開始年。デフォルトは1454年である。
constexpr int getStartYearAD() {
	return 1454;
}


// 現在のゲーム進行中の季節を得る
static char szSeasonName[5][3] = { "春", "夏", "秋", "冬", "無" };
char* getSeasonName() {
	char season = nb6year.season;

	if (0 <= season && season <= 3) {
		return szSeasonName[season];
	}
	return szSeasonName[4];
}
