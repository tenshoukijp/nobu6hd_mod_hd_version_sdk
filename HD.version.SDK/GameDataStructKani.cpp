#include "GameDataStruct.h"

//----------------------------------------------------------------------------------

static char* nb6kanitypelist[GAMEDATASTRUCT_KANITYPE_NUM] = {
	"正一位",
	"従一位",
	"正二位",
	"従二位",
	"正三位",
	"従三位",
	"正四位上",
	"正四位下",
	"従四位上",
	"従四位下",
	"正五位上",
	"正五位下",
	"従五位上",
	"従五位下",
	"正六位上",
	"正六位下",
	"従六位上",
	"従六位下",
	"正七位上",
	"正七位下",
	"従七位上",
	"従七位下",
	"正八位上",
};

char* getKaniTypeName(byte type) {
	return nb6kanitypelist[type];
}

// 官位を武将にアタッチする。元々別武将が持っていた場合は、元の武将から指定した武将へとアタッチが変わる。
// 能力値の変更を伴う。朝廷に戻す場合は、0xFFFFを指定すること。
bool ReAttachKani(int iKaniID, int iNewBushouID) {
	if (!(0 <= iKaniID && iKaniID < GAMEDATASTRUCT_KANI_NUM)) {
		return false;
	}

	int iOldBushouID = nb6kani[iKaniID].attach - 1;
	// 本人だ。何もする必要がない。
	if (iOldBushouID == iNewBushouID) {
		return true;
	}
	// 元々朝廷が持っていて、新たな指定も朝廷だ。何もする必要がない。
	if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE) {
		return true;
	}


	// 元の武将の政治能力の素値
	int iOldBushouPureCharm = 0;
	// 新しい指定の武将は正規の武将であり、朝廷ではない。
	if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		iOldBushouPureCharm = getBushouPureCharm(iOldBushouID);
		// 不正な番号は朝廷ということにする。
	}
	else {
		iOldBushouID = 0xFFFF;
	}

	int iNewBushouPureCharm = 0;
	// 新しい指定の武将は正規の武将であり、朝廷ではない。
	if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		iNewBushouPureCharm = getBushouPureCharm(iNewBushouID);

		// 不正な番号は朝廷ということにする。
	}
	else {
		iNewBushouID = 0xFFFF;
	}

	// 対象の家宝の所持者を変更する。
	nb6kani[iKaniID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

	// 元の武将は正規の武将であり、朝廷ではない。
	if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iOldBushouCharmUpByKani = getBushouCharmUpByKani(iOldBushouID);
		nb6bushou[iOldBushouID].charm = iOldBushouPureCharm + iOldBushouCharmUpByKani;
	}

	// 新しい指定の武将は正規の武将であり、朝廷ではない。
	if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iNewBushouCharmUpByKani = getBushouCharmUpByKani(iNewBushouID);
		nb6bushou[iNewBushouID].charm = iNewBushouPureCharm + iNewBushouCharmUpByKani;
	}

	return true;
}
