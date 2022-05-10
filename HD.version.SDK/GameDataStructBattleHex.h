#pragma once

#include <windows.h>


struct HEX_XY {
	int cols;
	int rows;
};


// ヘックスの座標軸系。Ｘ→ Ｙ↓　で値が増加していく。
struct HEX_POSITION {
	HEX_POSITION(double _x, double _y) : x(_x), y(_y) {}
	HEX_POSITION() : x(0), y(0) {}
	double x;
	double y;
};

// フィールドの方向ベクトル。Ｘ→ Ｙ↓　で値が増加していく。
struct HEX_VECTOR {
	HEX_VECTOR(double _x, double _y) : x(_x), y(_y) {}
	HEX_VECTOR() : x(0), y(0) {}
	double x;
	double y;
};

// フィールド座標同志の減算。座標Ａ→座標Ｂのベクトルを求めるのに、通常、Ｂ－Ａをするだろうから。
HEX_VECTOR operator-(HEX_POSITION &p1, HEX_POSITION &p2);




#define GAMEDATASTRUCT_FIELD_HEX_COLS			41	// 野戦のHEXの横の数
#define GAMEDATASTRUCT_FIELD_HEX_ROWS			24	// 野戦のHEXの縦の数

const int GAMEDATASTRUCT_FIELD_HEX_CENTER_X = 20;
const int GAMEDATASTRUCT_FIELD_HEX_CENTER_Y = 12;

namespace FIELD_HEX_ROLE {
	enum { 枠外 = 0x00, 平地 = 0x1, 道 = 0x2, 湿地 = 0x3, 荒れ地 = 0x4, 森 = 0x5, 低山 = 0x6, 中山 = 0x7, 高山 = 0x8, 川 = 0x9, 橋 = 0xA, 海 = 0xB, 湖 = 0xB, 城 = 0xC /*２個連続*/ };
}

// 野戦時のヘックスの役割のバイト列
union NB6FIELD_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41桁、24行として見た場合;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};

// 野戦時のユニットのマップ内のポジション
union NB6FIELD_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41桁、24行として見た場合;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};


// あるヘックス場所のチップの役割(FIELD_HEX_ROLE)を得る
int GetFieldHexRole(double x, double y);
int GetFieldHexRole(HEX_POSITION p);

// 逆に設定する。(といっても、設定したとしても、絵が変わらないので上手くいかないが)
void SetFieldHexRole(double x, double y, int eHexRole);
void SetFieldHexRole(HEX_POSITION p, int eHexRole);



// あるヘックス場所の高さ
int GetCastleHexHigh(double x, double y);
int GetCastleHexHigh(HEX_POSITION p);


// あるヘックス場所の高さ
int GetFieldHexHigh(double x, double y);
int GetFieldHexHigh(HEX_POSITION p);


#define GAMEDATASTRUCT_CASTLE_HEX_COLS			18	// 攻城戦のHEXの横の数
#define GAMEDATASTRUCT_CASTLE_HEX_ROWS			16	// 攻城戦のHEXの縦の数

const int GAMEDATASTRUCT_CASTLE_HEX_CENTER_X = 9;
const int GAMEDATASTRUCT_CASTLE_HEX_CENTER_Y = 8;

namespace CASTLE_HEX_ROLE {
	enum { 枠外 = 0x00, 城内平地 = 0x10, 城内整地 = 0x11, 城外平地 = 0x12, 森 = 0x13, 堀 = 0x14, 海 = 0x14, 湖 = 0x14, 堀橋 = 0x15, 城壁 = 0x16, 閉門 = 0x17, 開門 = 0x18, 櫓 = 0x19, 柵 = 0x1A, 本丸 = 0x1B };
}

// 戦闘画面の城内ヘックスの役割のバイト列
union NB6CASTLE_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18桁、16行として見た場合;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// 戦闘画面の城内ヘックスの高さのバイト列
union NB6CASTLE_HEX_HIGH {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18桁、16行として見た場合;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// 城攻時のユニットのマップ内のポジション
union NB6CASTLE_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// バイト列のインデックスとしてみた場合
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18桁、16行として見た場合;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};


// あるヘックス場所のチップの役割(CASTLE_HEX_ROLE)を得る
int GetCastleHexRole(double x, double y);
int GetCastleHexRole(HEX_POSITION p);



// 指定の武将ＩＤの武将がどこにいるのか？ 居ない場合、p(x=0xFF, y=0xFF) が返ってくる。
HEX_POSITION GetFieldHexUnitPos(int iBushouID);

// 指定の武将ＩＤの武将がどこにいるのか？ 居ない場合、p(x=0xFF, y=0xFF) が返ってくる。
HEX_POSITION GetCastleHexUnitPos(int iBushouID);



// ヘックス間隔の取得。p1→p2まで何枡移動する必要があるのか(全ての枡は行けるものと仮定する)
int getHexDistance(HEX_POSITION p1, HEX_POSITION p2);


// フィールドヘックスの座標→普通の３次元座標(左手デカルト・音と同じへ)
D3D_POSITION FieldHexPos_To_WorldPos(HEX_POSITION p);

// 普通の３次元座標(左手デカルト)→フィールドヘックスの座標へ
HEX_POSITION WorldPos_To_FieldHexPos(D3D_POSITION p);

// 城ヘックスの座標→普通の３次元座標(左手デカルト・音と同じへ)
D3D_POSITION CastleHexPos_To_WorldPos(HEX_POSITION p);

// 普通の３次元座標(左手デカルト)→城ヘックスの座標へ
HEX_POSITION WorldPos_To_CastleHexPos(D3D_POSITION p);






namespace FIRE_HEX_ROLE {
	enum { 無し = 0x00, 炎上 = 0x01 };
}

// あるヘックス場所のチップの炎状態
int GetFireHexRole(double x, double y);
int GetFireHexRole(HEX_POSITION p);





// ヘックスのＡ点とＢ点の間にあるチップのアレイを返す。
vector<int> RoleArrayOfBetweenPosToPos(HEX_POSITION pos1, HEX_POSITION pos2);


