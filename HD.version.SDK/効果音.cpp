#include "GameDataStruct.h"


効果音ハンドル型 効果音情報型::Do_効果音再生(int 効果音音源) {
	if (0 <= 効果音音源 && 効果音音源 <= 列挙::効果音::効果音音源::雪) {
		FuncPlaySound(効果音音源);
		iSoundID++;
		return iSoundID;
	}
	return 0;
}
