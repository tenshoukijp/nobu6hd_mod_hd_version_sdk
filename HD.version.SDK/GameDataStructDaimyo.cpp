#include "GameDataStruct.h"


// 全有効大名のリストを返す。ターン大名自身も入ってるので注意。
vector<int> getDaimyoList(BOOL isIncludeTurnDaimyo) {
	vector<int> list;
	for (int iDaimyoID = 0; iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM; iDaimyoID++) {
		// ターン大名は含まない
		if (!isIncludeTurnDaimyo) {
			// ターン大名ならパス
			if (iDaimyoID == nb6turn.daimyo - 1) {
				continue;
			}
		}
		// ちゃんと武将が納めている大名家のみ
		if (nb6daimyo[iDaimyoID].attach != 0xFFFF) {
			list.push_back(iDaimyoID);
		}
	}
	return list;
}




int DaimyoHasCastleArray[GAMEDATASTRUCT_DAIMYO_NUM] = { 0 }; // 各々の大名が持つ城数

															 //最大勢力(最も持ち城数が多い)大名を得る
int GetMaximumInfluenceDaimyo() {
	// まず、一応呼ばれる度にリセット
	for (int iDaimyoID = 0; iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM; iDaimyoID++) {
		DaimyoHasCastleArray[iDaimyoID] = 0;
	}

	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		// 所属大名番号に従って、カウントを増やしてゆく。
		int iGundanID = nb6castle[iCastleID].attach - 1;
		if (iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) { // 誰にも所属してない城はこの条件で弾かれる
			int iDaimyoID = nb6gundan[iGundanID].attach - 1;
			DaimyoHasCastleArray[iDaimyoID]++;
		}
	}

	// 最大の城持ちの大名IDを探す
	int iMaximumInfluenceDaimyoID = 0;

	// 比較相手なので1スタートで良い
	for (int iDaimyoID = 1; iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM; iDaimyoID++) {
		if (DaimyoHasCastleArray[iDaimyoID] > DaimyoHasCastleArray[iMaximumInfluenceDaimyoID]) {
			iMaximumInfluenceDaimyoID = iDaimyoID;
		}
	}

	return iMaximumInfluenceDaimyoID;
}

