#pragma once

#include <windows.h>





struct NB6BUSHOU_HEX_UNIT_INFO {
	WORD bushou;					// 武将番号。1大きい数の方。武将番号に治すには-1すること。
	WORD junban;					// この値はターン順番。戦争において、この数値が若い軍団から順番が回るということ。
	int	 pos_x;						// 行内におけるpos_x。捕まったり、退却したりして、戦場から居なくなると、0xFFFF
	int	 pos_y;						// 行内におけるpos_y。捕まったり、退却したりして、戦場から居なくなると、0xFFFF
	BYTE movepower;					// 移動力残量。0x1～0xFぐらいの数値が入っている。
	WORD _undef2;					// 不明2 ユニット存在してるのはFFFF、していないのは
	BYTE _undef3;					// 不明1
	BYTE _undef4;					// 不明1
	BYTE _undef5;					// 不明1
	WORD _what1;					// 何か意味がありそう。1～8ぐらいの数値が入っている。
	WORD _undef6;					// ほぼ0x0000
	WORD _undef7;					// ほぼ0xFFFF
	BYTE konran : 4;					// 1=通常混乱 2=大混乱 3=挑発
	BYTE bEnd : 4;					// 行動済フラグ。0x2=行動済み, 0x0=未行動
	BYTE _what4;					// 何か意味がありそう。存在してる武将は、｢0x2｣が多い
	WORD _what5;					// 何か意味がありそう。存在してる武将は、｢0x70｣が多い
	int	 _undef8;					// 不明
};

// 指定武将が戦場において、行動済みかどうか
BOOL IsActionEndInBattle(int iBushouID);


namespace KONRAN_STATUS {
	enum { 無し = 0, 混乱 = 1, 大混乱 = 2, 挑発 = 3 };
}
// 対象の武将が混乱しているか。
int GetKonranStatus(int iBushouID);
// 対象の武将を混乱させる。(描画が伴わない)


// 移動力残量を得る
int GetBushouMovePower(int iBushouID);

// 移動力残量を設定する
int SetBushouMovePower(int iBushouID, int iMovePower);


// 戦争時に関わっている「大名・軍団・総大将・[攻め手・受け手・中立]」情報
struct NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO {
	WORD daimyo;		// 大名番号
	WORD gundan;		// 軍団番号
	WORD soudaisho;		// 総大将の武将番号
	WORD group;			// 何番が攻側か、受側か、などは、不定。あくまでも、戦闘開始時の攻め側大名と同じグループが攻め側の援軍、受側の大名と同じグループが受側、それ以外が中立である。
	WORD _undef;		// 特になにもなし。must 0000
};

// 結局戦っているのはどこの大名なのか？
struct NB6WAR_BATTLE_DAIMYO_INFO {
	int defend_gundan;	// 直接守備側の軍団番号
	int attack_gundan;	// 直接攻撃側の軍団番号
	int defend_daimyo;  // 直接守備側の大名番号
	int attack_daimyo;  // 直接攻撃側の大名番号
};


// 戦争に出陣しているiBushouIDの一覧を得る。
vector<int> GetSyutujinBushouArray();

// 現在表示されているマップ限定で、出陣しているiBushouIDの一覧を得る。
vector<int> GetCurMapSyutujinBushouArray();





// 現在進行中の戦争に関わっているiDaimyoIDのリスト。(出陣しているかどうかは関係ない)
vector<int> GetCurWarJointDaimyoIDList();

// 現在進行中の戦争に関わっているiGundanIDのリスト。(出陣しているかどうかは関係ない)
vector<int> GetCurWarJointGundanIDList();



namespace WarStandPoint {
	//	   不明          直接攻撃側   直接守備側   攻撃側の援軍　      守備側の援軍　　中立軍 
	enum { unknown = 0, attack = 1, defend = 2, attack_enngun = 3, defend_enngun = 4, chuuritsu = 5 };
};

// 該当の軍団の戦場における立場を返す(不明=0, 直接攻める側=1, 直接守る側=2, 攻める側の援軍=3, 守る側の援軍=4, 中立軍=5)
int GetWarStandPointTheGundan(int iGundanID);

// 該当の武将の戦場における立場を返す(不明=0, 直接攻める側=1, 直接守る側=2, 攻める側の援軍=3, 守る側の援軍=4, 中立軍=5)
int GetWarStandPointTheBushou(int iBushouID);

// 現在の戦において、指定軍団の総大将(軍団長や大名のことではなく、戦場においての該当軍団の総大将。
int GetWarSoudaishoTheGundan(int iGundanID);


