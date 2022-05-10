#include "GameDataStruct.h"

void 演出情報型::Do_フェイドアウト() {
	FuncFadeOut();
}

void 演出情報型::Do_フェイドイン() {
	FuncFadeIn();
}

bool 演出情報型::Do_カメラ移動(int 城番号) {
	if (0 <= 城番号 && 城番号 < GAMEDATASTRUCT_CASTLE_NUM) {
		FuncMoveCamera(城番号);
		return true;
	}
	return false;
}