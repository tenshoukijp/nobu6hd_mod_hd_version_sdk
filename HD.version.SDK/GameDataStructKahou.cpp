#include "GameDataStruct.h"

// 家宝を武将にアタッチする。元々別武将が持っていた場合は、元の武将から指定した武将へとアタッチが変わる。
// 能力値の変更を伴う。商人に戻す場合は、0xFFFFを指定すること。
bool ReAttachKahou(int iKahouID, int iNewBushouID) {
	if (!(0 <= iKahouID && iKahouID < GAMEDATASTRUCT_KAHOU_NUM)) {
		return false;
	}

	// 消失は降ろす
	nb6kahou[iKahouID].bLost = false;
	// 未登場は降ろす。
	nb6kahou[iKahouID].bMitojo = false;

	int iOldBushouID = nb6kahou[iKahouID].attach - 1;
	// 本人だ。何もする必要がない。
	if (iOldBushouID == iNewBushouID) {
		return true;
	}
	// 元々商人が持っていて、新たな指定も商人だ。何もする必要がない。
	if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE) {
		return true;
	}

	// 政治増加タイプ：0 茶碗  1 茶壺  2 茶入  3 茶釜  4 花入  
	if (0 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 4) {

		// 元の武将の政治能力の素値
		int iOldBushouPureGovMax = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureGovMax = getBushouPureGovMax(iOldBushouID);
			// 不正な番号は商人ということにする。
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureGovMax = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureGovMax = getBushouPureGovMax(iNewBushouID);

			// 不正な番号は商人ということにする。
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// 対象の家宝の所持者を変更する。
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouGovMaxUpByKahou = getBushouGovMaxUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].maxgov = iOldBushouPureGovMax + iOldBushouGovMaxUpByKahou;
		}

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouGovMaxUpByKahou = getBushouGovMaxUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].maxgov = iNewBushouPureGovMax + iNewBushouGovMaxUpByKahou;
		}

		// 戦闘増加タイプ：5 刀剣  6 槍  7 具足  8 馬  9 鞍  A 陣羽織   
	}
	else if (5 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xA) {

		// 元の武将の政治能力の素値
		int iOldBushouPureBatMax = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureBatMax = getBushouPureBatMax(iOldBushouID);
			// 不正な番号は商人ということにする。
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureBatMax = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureBatMax = getBushouPureBatMax(iNewBushouID);

			// 不正な番号は商人ということにする。
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// 対象の家宝の所持者を変更する。
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouBatMaxUpByKahou = getBushouBatMaxUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].maxbat = iOldBushouPureBatMax + iOldBushouBatMaxUpByKahou;
		}

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouBatMaxUpByKahou = getBushouBatMaxUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].maxbat = iNewBushouPureBatMax + iNewBushouBatMaxUpByKahou;
		}


		// 智謀増加タイプ：B 巻子本  C 明朝綴本
	}
	else if (0xB <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xC) {

		// 元の武将の政治能力の素値
		int iOldBushouPureIntMax = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureIntMax = getBushouPureIntMax(iOldBushouID);
			// 不正な番号は商人ということにする。
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureIntMax = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureIntMax = getBushouPureIntMax(iNewBushouID);

			// 不正な番号は商人ということにする。
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// 対象の家宝の所持者を変更する。
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouIntMaxUpByKahou = getBushouIntMaxUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].maxint = iOldBushouPureIntMax + iOldBushouIntMaxUpByKahou;
		}

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouIntMaxUpByKahou = getBushouIntMaxUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].maxint = iNewBushouPureIntMax + iNewBushouIntMaxUpByKahou;
		}

		// 野望増加タイプ：D 香木  E 地球儀  F 南蛮時計  10 水墨画  11 十字架  12 聖書  13 玉手箱  14 ビードロ杯  15 遠眼鏡  16 ルソン壺  17 煙草
	}
	else if (0xD <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0x17) {

		// 元の武将の政治能力の素値
		int iOldBushouPureAmbition = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureAmbition = getBushouPureAmbition(iOldBushouID);
			// 不正な番号は商人ということにする。
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureAmbition = 0;
		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureAmbition = getBushouPureAmbition(iNewBushouID);

			// 不正な番号は商人ということにする。
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// 対象の家宝の所持者を変更する。
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouAmbitionUpByKahou = getBushouAmbitionUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].ambition = iOldBushouPureAmbition + iOldBushouAmbitionUpByKahou;
		}

		// 新しい指定の武将は正規の武将であり、商人ではない。
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouAmbitionUpByKahou = getBushouAmbitionUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].ambition = iNewBushouPureAmbition + iNewBushouAmbitionUpByKahou;
		}

	}

	return true;
}


