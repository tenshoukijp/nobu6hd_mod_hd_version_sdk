#include "GameDataStruct.h"

//----------------------------------------------------------------------------------

// Ａ大名(０始まりでの配列用指定)とＢ大名との同盟関係）
// 004CF213  05 55 55 55 95    とあるのは、004CF213 [0 5 5 5 5 5 5 5 9 5] というように1番目、2番目、3番目の相手…という感じとなる。  
// 一方同盟・婚姻情報はどこにあるのかというと、2人の組み合わせのうち、大きい方の大名番号用の同じ構造体に入っている。
// 例えば、大名番号21と25とすると、友好情報は21番の方の25番目に入っており、同盟や婚姻は、25番の方の21番目に入っているというわけだ。


// 下のgetDoumeiKankei内部で求まる値は、この配列のINDEXであるため、これを使って実際の値に直す。
static int YuukouValueArray[] = { 0, 10, 20, 30, 40, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 0xFFFF };


static byte* getYuukouKannkeiPointer(int& iDaimyoA_ID, int& iDaimyoB_ID) {

	// 範囲チェック
	if (0 <= iDaimyoA_ID && iDaimyoA_ID < GAMEDATASTRUCT_DAIMYO_NUM &&
		0 <= iDaimyoB_ID && iDaimyoB_ID < GAMEDATASTRUCT_DAIMYO_NUM) {
	}
	else {
		return NULL;
	}

	// 大名Ａと大名Ｂで、大名Ａの方が値が大きい場合、入れ替える。
	// なぜなら友好関係の値は、大名Ａが小さい方の組み合わせテーブルに入っていて、大名Ａが大きい方の組み合わせテーブルには婚姻や同盟の値が入っているから。
	if (iDaimyoA_ID > iDaimyoB_ID) {
		// ２つ入れ替え
		iDaimyoA_ID ^= iDaimyoB_ID;
		iDaimyoB_ID ^= iDaimyoA_ID;
		iDaimyoA_ID ^= iDaimyoB_ID;
	}

	byte *p = (byte *)nb6doumei;

	// 以下2人の大名ＩＤより、同盟関係値が入っているメモリのアドレスを求める
	p += iDaimyoA_ID * (GAMEDATASTRUCT_DAIMYO_NUM / 2); // もしも１つのＡ大名あたり、Ｂ大名への同盟が１バイトで表現されていれば、
														// ７２大名いるので、７２バイトで表現される。
														// ところが実際には、4ビットで表現されるので、
														// １つの大名にぶら下がる構造体データとしては、半分の３６バイトである。

	p += iDaimyoB_ID / 2;									 // 上と同じ理由となる。１つの大名の(同盟関係構造体)の中でも
															 // １つの相手大名との同盟値に使われているのは半バイト。
															 // よってポインタの位置としては、/2 しておき、偶数か奇数かで、後で演算を振り分ける。

	return p;
}


int getYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// 該当の友好関係情報が存在するアドレスを得る。ＡとＢは値が交換されるかもしれない。注意。
	byte *p = getYuukouKannkeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return 0;

	// アドレスは求まったが、１つのアドレスの1バイト内には、２つの大名が入っている。
	// 大名番号が偶数なら上位桁、偶数なら下位桁である。
	int YuukouIX = 0;
	// 相手大名が偶数だ
	if (iDaimyoB_ID % 2 == 0) {								 // 偶数であれば、上半分のビットとの＆結果[0 5] のうち[0]を返す
		YuukouIX = (*p) >> 4;

		// 相手大名が奇数だ										 // 奇数であれば、下半分のビットとの＆結果[0 5] のうち[5]を返す
	}
	else {
		YuukouIX = 0x0F & (*p);
	}

	return YuukouValueArray[YuukouIX];
}

// 友好関係値をセットする。
void setYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID, int iValue) {

	// 該当の友好関係情報が存在するアドレスを得る。ＡとＢは値が交換されるかもしれない。注意。
	byte *p = getYuukouKannkeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return;


	// 負数はヤヴァイので友好関係値として０を指定したものとする。100オーバーも100にしとく。
	if (iValue < 0) { iValue = 0; }
	if (iValue > 100) { iValue = 100; }

	int YuukouIX = 0;
	// セットしたい友好関係値と、友好関係値の配列を比較して、もっとも近い切捨て値のindexを求める。
	// 例えば友好関係値として53というように指定されても、そのような値には出来ないので、50とするわけだ。
	// そして50は、YuukouValueArrayのindex==5に存在する。この5のような値を求めたい。
	for (int i = 0; i < sizeof(YuukouValueArray) / sizeof(YuukouValueArray[0]); i++) {
		if (iValue < YuukouValueArray[i]) {

			YuukouIX = i - 1;	// 値が超えたので、１つ前のindexにしとく。

			if (YuukouIX < 0) { YuukouIX = 0; }  // 理論上ありえないが、何足すかわからんので一応。
			break;
		}
	}

	// アドレスは求まったが、１つのアドレスの1バイト内には、２つの大名が入っている。
	// 大名番号が偶数なら上位桁、偶数なら下位桁である。
	// 相手大名が偶数だ
	if (iDaimyoB_ID % 2 == 0) {								 // 偶数であれば、上半分のビットとの＆結果[0 5] のうち[0]を返す
		YuukouIX = YuukouIX << 4;
		// 上位バイトはYuukouIXをシフトしたものを、下位バイトは下位バイトの部分だけ抽出で
		*p = YuukouIX | (0x0F & (*p));

		// 相手大名が奇数だ										 // 奇数であれば、下半分のビットとの＆結果[0 5] のうち[5]を返す
	}
	else {
		// 上位バイトはそのまま採用で、下位バイトは、YuukouIXそのままで。
		*p = (0xF0 & (*p)) | YuukouIX;
	}
}

static byte* getDoumeiKankeiPointer(int& iDaimyoA_ID, int& iDaimyoB_ID) {

	// 範囲チェック
	if (0 <= iDaimyoA_ID && iDaimyoA_ID < GAMEDATASTRUCT_DAIMYO_NUM &&
		0 <= iDaimyoB_ID && iDaimyoB_ID < GAMEDATASTRUCT_DAIMYO_NUM) {
	}
	else {
		return NULL;
	}

	// 大名Ａと大名Ｂで、大名Ａの方が値が小さい場合、入れ替える。
	// なぜなら同盟関係の値は、大名Ａが大きい方の組み合わせテーブルに入っているから。
	if (iDaimyoA_ID < iDaimyoB_ID) {
		// ２つ入れ替え
		iDaimyoA_ID ^= iDaimyoB_ID;
		iDaimyoB_ID ^= iDaimyoA_ID;
		iDaimyoA_ID ^= iDaimyoB_ID;
	}


	byte *p = (byte *)nb6doumei;

	// 以下2人の大名ＩＤより、同盟関係値が入っているメモリのアドレスを求める
	p += iDaimyoA_ID * (GAMEDATASTRUCT_DAIMYO_NUM / 2); // もしも１つのＡ大名あたり、Ｂ大名への同盟が１バイトで表現されていれば、
														// ７２大名いるので、７２バイトで表現される。
														// ところが実際には、4ビットで表現されるので、
														// １つの大名にぶら下がる構造体データとしては、半分の３６バイトである。

	p += iDaimyoB_ID / 2;									 // 上と同じ理由となる。１つの大名の(同盟関係構造体)の中でも
															 // １つの相手大名との同盟値に使われているのは半バイト。
															 // よってポインタの位置としては、/2 しておき、偶数か奇数かで、後で演算を振り分ける。
	return p;
}

int isDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// 該当の同盟関係情報が存在するアドレスを得る。ＡとＢは値が交換されるかもしれない。注意。
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return 0;

	// アドレスは求まったが、１つのアドレスの1バイト内には、２つの大名が入っている。
	// 大名番号が偶数なら上位桁、偶数なら下位桁である。
	// 相手大名が偶数だ
	if (iDaimyoB_ID % 2 == 0) {								 // 偶数であれば、上半分のビット
		return 0x10 & (*p);
		// 相手大名が奇数だ										 // 奇数であれば、下半分のビット
	}
	else {
		return 0x01 & (*p);
	}
}
int isKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// 該当の婚姻関係情報が存在するアドレスを得る(同盟と同じ場所)。ＡとＢは値が交換されるかもしれない。注意。
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return 0;

	// アドレスは求まったが、１つのアドレスの1バイト内には、２つの大名が入っている。
	// 大名番号が偶数なら上位桁、偶数なら下位桁である。

	if (iDaimyoB_ID % 2 == 0) {								 // 偶数であれば、上半分のビット
		return (0x20 & (*p)) > 0;							 // ２との比較では間違うかもしれないので、一応BOOLっぽくしておく。
															 // 相手大名が奇数だ										 // 奇数であれば、下半分のビット
	}
	else {
		return (0x02 & (*p)) > 0;							 // ２との比較では間違うかもしれないので、一応BOOLっぽくしておく。
	}
}

void setDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// 該当の同盟関係情報が存在するアドレスを得る。ＡとＢは値が交換されるかもしれない。注意。
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return;

	// アドレスは求まったが、１つのアドレスの1バイト内には、２つの大名が入っている。
	// 大名番号が偶数なら上位桁、偶数なら下位桁である。
	// 相手大名が偶数だ
	if (iDaimyoB_ID % 2 == 0) {								 // 偶数であれば、上半分のビット
		*p = *p | 0x10;
		// 相手大名が奇数だ										 // 奇数であれば、下半分のビット
	}
	else {
		*p = *p | 0x01;
	}
}


void setKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// 該当の婚姻関係情報が存在するアドレスを得る(同盟と同じ場所)。ＡとＢは値が交換されるかもしれない。注意。
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return;

	// アドレスは求まったが、１つのアドレスの1バイト内には、２つの大名が入っている。
	// 大名番号が偶数なら上位桁、偶数なら下位桁である。
	// 相手大名が偶数だ
	if (iDaimyoB_ID % 2 == 0) {								 // 偶数であれば、上半分のビット
		*p = *p | 0x20;
		// 相手大名が奇数だ										 // 奇数であれば、下半分のビット
	}
	else {
		*p = *p | 0x02;
	}
}

