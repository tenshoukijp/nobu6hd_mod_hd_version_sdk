#include "GameDataStruct.h"

void 音楽情報型::Do_ＢＧＭ再生(int ＢＧＭ番号) {
	if (0 <= ＢＧＭ番号 && ＢＧＭ番号 <= 列挙::音楽::ＢＧＭ番号::夢幻の彼方) {
		FuncPlayBGM(ＢＧＭ番号, true); // 95の頃のプログラムが内部で走ってるので+1する必要がある。
	}
}