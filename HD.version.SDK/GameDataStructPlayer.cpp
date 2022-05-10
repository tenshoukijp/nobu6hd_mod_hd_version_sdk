#include "GameDataStruct.h"


// 対象の軍団IDがいずれかのプレイヤー勢力下の軍団である(最大８人)
// iTargetGundanIDには配列上の番号(attach-1の数)を渡すこと
bool isPlayerGundan(WORD iTargetGundanID) {

	if (iTargetGundanID >= GAMEDATASTRUCT_GUNDAN_NUM) {
		return false;
	}

	WORD iGundanID = 0;
	for (int iPG = 0; iPG<GAMEDATASTRUCT_PLAYERS8_NUM; iPG++) {
		// プレイヤーが担当している軍団のＩＤを確保
		iGundanID = nb6players8[iPG].gundan;

		// 0xFFFFならばプレイヤーではない
		if (iGundanID == 0xFFFF) {
			continue;
		}

		// プレイヤー担当の軍団の大名が、ターゲットとしている対象の軍団の大名と一致するならば、
		// それはプレイヤーの勢力下の軍団である。
		// どうもnb6player8のgundanの値は、内部管理のgundanの値よりも+1されているようである。
		// よってここでは-1する。
		if (iGundanID >= 1 && nb6gundan[iGundanID - 1].attach == nb6gundan[iTargetGundanID].attach) {
			return true;
		}
	}

	return false;
}

// 対象の武将IDがいずれかのプレイヤー勢力下の武将である
bool isPlayerBushou(WORD iTargetBushouID) {
	// 武将IDの範囲に収まっていること
	if (0 <= iTargetBushouID && iTargetBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// ターゲットの武将の軍団IDがプレイヤーの軍団であるかを返す
		return isPlayerGundan(nb6bushou[iTargetBushouID].gundan - 1);
	}
	else {
		return false;
	}
}

// 対象の大名IDがいずれかのプレイヤー担当の大名である
bool isPlayerDaimyo(WORD iTargetDaimyoID) {
	// 武将IDの範囲に収まっていること
	if (0 <= iTargetDaimyoID && iTargetDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		// ターゲットの武将の軍団IDがプレイヤーの軍団であるかを返す
		return isPlayerGundan(nb6daimyo[iTargetDaimyoID].gundan - 1);
	}
	else {
		return false;
	}
}


