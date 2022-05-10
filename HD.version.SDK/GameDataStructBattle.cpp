#include "GameDataStruct.h"


HEX_VECTOR operator-(HEX_POSITION &p1, HEX_POSITION &p2) {
	HEX_VECTOR p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}


// あるヘックス場所のチップの役割(FIELD_HEX_ROLE)を得る
int GetFieldHexRole(double x, double y) {
	// 座標値は妥当な範囲か？
	if (0 <= x && x <= GAMEDATASTRUCT_FIELD_HEX_COLS && 0 <= y && y <= GAMEDATASTRUCT_FIELD_HEX_ROWS) {
		// yを座標実値にして、整数化
		int _y = round《整数化》(y);
		// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// xを最も近い値の整数化
		int _x = round《整数化》(x);
		// ０より小さくなることもあるので０に
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_FIELD_HEX_COLS) { _x = GAMEDATASTRUCT_FIELD_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_FIELD_HEX_ROWS) { _y = GAMEDATASTRUCT_FIELD_HEX_ROWS - 1; }
		// 該当の場所にあるチップの役割番号(FIELD_HEX_ROLE)を返す
		return nb6field_hex_role.pos_y[_y].pos_x[_x];
	}
	else {
		return -1;
	}
}

int GetFieldHexRole(HEX_POSITION p) {
	return GetFieldHexRole(p.x, p.y);
}




// 逆に設定する。(といっても、設定したとしても、絵が変わらないので上手くいかないが)
void SetFieldHexRole(double x, double y, int eHexRole) {
	// 座標値は妥当な範囲か？
	if (0 <= x && x< GAMEDATASTRUCT_FIELD_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_FIELD_HEX_ROWS) {
		// yを座標実値にして、整数化
		int _y = round《整数化》(y);
		// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// xを最も近い値の整数化
		int _x = round《整数化》(x);
		// ０より小さくなることもあるので０に
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_FIELD_HEX_COLS) { _x = GAMEDATASTRUCT_FIELD_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_FIELD_HEX_ROWS) { _y = GAMEDATASTRUCT_FIELD_HEX_ROWS - 1; }
		// 該当の場所のチップの役割番号(FIELD_HEX_ROLE)を設定する。
		nb6field_hex_role.pos_y[_y].pos_x[_x] = eHexRole;
	}
}

void SetFieldHexRole(HEX_POSITION p, int eHexRole) {
	SetFieldHexRole(p.x, p.y, eHexRole);
}




// あるヘックス場所のチップの高さを得る
int GetFieldHexHigh(double x, double y) {
	int role = GetFieldHexRole(x, y);
	if (role == FIELD_HEX_ROLE::川 || FIELD_HEX_ROLE::湖 || FIELD_HEX_ROLE::海) {
		return 0;
	}
	else if (role == FIELD_HEX_ROLE::低山) {
		return 2;
	}
	else if (role == FIELD_HEX_ROLE::中山) {
		return 3;
	}
	else if (role == FIELD_HEX_ROLE::高山) {
		return 4;
	}
	else {
		return 1;
	}
}

int GetFieldHexHigh(HEX_POSITION p) {
	return GetFieldHexHigh(p.x, p.y);
}






// あるヘックス場所のチップの役割(CASTLE_HEX_ROLE)を得る
int GetCastleHexRole(double x, double y) {
	// 座標値は妥当な範囲か？
	if (0 <= x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
		// yを座標実値にして、整数化
		int _y = round《整数化》(y);
		// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// xを最も近い値の整数化
		int _x = round《整数化》(x);
		// ０より小さくなることもあるので０に
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_CASTLE_HEX_COLS) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS - 1; }
		// 該当の場所にあるチップの役割番号(CASTLE_HEX_ROLE)を返す
		return nb6castle_hex_role.pos_y[_y].pos_x[_x];
	}
	else {
		return -1;
	}
}


int GetCastleHexRole(HEX_POSITION p) {
	return GetCastleHexRole(p.x, p.y);
}



// あるヘックス場所のチップの高さを得る
int GetCastleHexHigh(double x, double y) {
	// 座標値は妥当な範囲か？
	if (0 <= x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
		// yを座標実値にして、整数化
		int _y = round《整数化》(y);
		// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// xを最も近い値の整数化
		int _x = round《整数化》(x);
		// ０より小さくなることもあるので０に
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_CASTLE_HEX_COLS) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS - 1; }
		// 該当の場所にあるチップの役割番号(CASTLE_HEX_ROLE)を返す
		return nb6castle_hex_high.pos_y[_y].pos_x[_x];
	}
	else {
		return -1;
	}
}

int GetCastleHexHigh(HEX_POSITION p) {
	return GetCastleHexHigh(p.x, p.y);
}



/* 下で右１バイトが１の所は炎が付いている
004D4DAA                          10 10 10 10 10 10 10 10          
004D4DBA  10 00 00 00 00 00 00 00 00 10 10 10 11 98 90 10  ........・
004D4DCA  10 10 10 00 00 00 00 00 00 00 00 10 10 10 10 90  ........・
004D4DDA  90 90 10 10 10 10 00 00 00 00 00 00 00 10 10 10  瑞.......
004D4DEA  10 91 90 10 10 10 10 00 00 00 00 00 00 00 00 00  草.........
004D4DFA  10 10 10 11 10 10 10 10 10 00 00 00 00 00 00 00  .......
004D4E0A  00 00 10 10 11 11 11 10 10 10 00 00 00 00 00 00  ........
004D4E1A  00 00 00 00 00 10 10 10 11 10 10 10 00 00 00 00  .........
004D4E2A  00 00 00 00 00 00 00 10 10 10 10 10 10 00 00 00  ..........
*/
// あるヘックス場所のチップの炎の役割(CASTLE_HEX_ROLE)を得る
// 炎が付いている所は、右の１バイトが1になる。
int GetFireHexRole(double x, double y) {
	// 座標値は妥当な範囲か？
	if (0 <= x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
		// yを座標実値にして、整数化
		int _y = round《整数化》(y);
		// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"半HEX"多い値がxに入ってくるため。
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// xを最も近い値の整数化
		int _x = round《整数化》(x);
		// ０より小さくなることもあるので０に
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_CASTLE_HEX_COLS) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS - 1; }
		// 該当の場所にあるチップの役割番号(CASTLE_HEX_ROLE)を返す
		return (nb6fire_hex_role.pos_y[_y].pos_x[_x] & 0xF) == 1;
	}
	else {
		return -1;
	}
}


int GetFireHexRole(HEX_POSITION p) {
	return GetFireHexRole(p.x, p.y);
}


// フィールドヘックスの座標→普通の３次元座標(左手デカルト・音と同じへ)
D3D_POSITION FieldHexPos_To_WorldPos(HEX_POSITION p) {
	D3D_POSITION p_real;
	p_real.x = p.x - GAMEDATASTRUCT_FIELD_HEX_CENTER_X;
	p_real.z = (p.y - GAMEDATASTRUCT_FIELD_HEX_CENTER_Y) * (sqrt(3.0f) / 2.0f) * -1; // sin60°
	if (p_real.z == 0) { p_real.z = 0; } // アホみたいだが、"-0"とならないようにする。

										 // yの高さを決めるにあたって、低山なら1, 中山なら2, 高山なら3とする。
	int iHexRole = GetFieldHexRole(p.x, p.y);

	if (iHexRole == FIELD_HEX_ROLE::高山) {
		p_real.y = 3;
	}
	else if (iHexRole == FIELD_HEX_ROLE::中山) {
		p_real.y = 2;
	}
	else if (iHexRole == FIELD_HEX_ROLE::低山) {
		p_real.y = 1;
	}
	else {
		p_real.y = 0;
	}
	return p_real;
}

// 普通の３次元座標(左手デカルト)→フィールドヘックスの座標へ
HEX_POSITION WorldPos_To_FieldHexPos(D3D_POSITION p) {
	HEX_POSITION p_hex;
	p_hex.x = round《整数化》(p.x + GAMEDATASTRUCT_FIELD_HEX_CENTER_X);
	p_hex.y = round《二分の一吸着化》((2.0f / sqrt(3.0f)) * (p.z) * -1 + GAMEDATASTRUCT_FIELD_HEX_CENTER_Y);
	return p_hex;
}

// 城ヘックスの座標→普通の３次元座標(左手デカルト・音と同じへ)
D3D_POSITION CastleHexPos_To_WorldPos(HEX_POSITION p) {
	D3D_POSITION p_real;
	p_real.x = p.x - GAMEDATASTRUCT_CASTLE_HEX_CENTER_X;
	p_real.z = (p.y - GAMEDATASTRUCT_CASTLE_HEX_CENTER_Y) * (sqrt(3.0f) / 2.0f) * -1; // sin60°
	if (p_real.z == 0) { p_real.z = 0; } // アホみたいだが、"-0"とならないようにする。

										 // yの高さを決めるにあたって城の高さ情報を当てはめる。
	int iHexHigh = GetCastleHexHigh(p.x, p.y);
	p_real.y = iHexHigh;
	return p_real;
}

// 普通の３次元座標(左手デカルト)→城ヘックスの座標へ
HEX_POSITION WorldPos_To_CastleHexPos(D3D_POSITION p) {
	HEX_POSITION p_hex;
	p_hex.x = round《整数化》(p.x + GAMEDATASTRUCT_CASTLE_HEX_CENTER_X);
	p_hex.y = round《二分の一吸着化》((2.0f / sqrt(3.0f)) * (p.z) * -1 + GAMEDATASTRUCT_CASTLE_HEX_CENTER_Y);
	return p_hex;
}


// ヘックス間隔の取得。p1→p2まで何枡移動する必要があるのか(全ての枡は行けるものと仮定する)
int getHexDistance(HEX_POSITION p1, HEX_POSITION p2) {
	double ax = double(abs(p1.x - p2.x));
	double ay = double(abs(p1.y - p2.y));
	if (p1.y == p2.y) { // 同じ行に居るならば…
		return round《整数化》(ax);
	}
	else if (ax * 2 <= ay) { // 2点間のX座標の差が2点間のY座標の差の半分以下の場合、Y座標の移動だけで該当ポイントまで到達できる。
		return round《整数化》(ay);
	}
	else {
		// Xの差 + Yの差 - Yの差の半分
		return round《整数化》(ax + ay - 0.5*ay);
	}
}




// 現在出陣しているiBushouIDの一覧を得る。
vector<int> GetSyutujinBushouArray() {
	vector<int> bArray;

	// 戦場にいる武将から条件を満たすものの移動残量を増やす。
	for (int i = 0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == 0xFFFF) { continue; } // 0xFFFFだとそのスロットに武将は居ない。次の人
		if (nb6bushou_hex_unit_info[i].bushou > GAMEDATASTRUCT_BUSHOU_NUM) { continue; } // ここで範囲保障しておいてあげる。次の人

		int iBushouID = nb6bushou_hex_unit_info[i].bushou - 1;

		if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			// 戦死や退却していない
			if (nb6bushouname[iBushouID].battleDeath == 0 && nb6bushouname[iBushouID].battleRetreat == 0) {
				bArray.push_back(iBushouID);
			}
		}
	}

	return bArray;
}

// 現在表示されているマップ限定で、出陣しているiBushouIDの一覧を得る。
vector<int> GetCurMapSyutujinBushouArray() {
	vector<int> bArray;

	if (Is_CastleWar()) {
		for (int i = 0; i<GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS; i++) {
			int iBango = nb6castle_hex_unit_pos.index[i];
			if (1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM) {
				if (nb6bushou_hex_unit_info[iBango - 1].bushou != 0xFFFF) {
					int iBushouID = nb6bushou_hex_unit_info[iBango - 1].bushou - 1;

					if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
						// 戦死や退却していない
						if (nb6bushouname[iBushouID].battleDeath == 0 && nb6bushouname[iBushouID].battleRetreat == 0) {
							bArray.push_back(iBushouID);
						}
					}
				}
			}
		}
	}
	if (Is_FieldWar()) {
		for (int i = 0; i<GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS; i++) {
			int iBango = nb6field_hex_unit_pos.index[i];
			if (1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM) {
				if (nb6bushou_hex_unit_info[iBango - 1].bushou != 0xFFFF) {
					int iBushouID = nb6bushou_hex_unit_info[iBango - 1].bushou - 1;

					if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
						// 戦死や退却していない
						if (nb6bushouname[iBushouID].battleDeath == 0 && nb6bushouname[iBushouID].battleRetreat == 0) {
							bArray.push_back(iBushouID);
						}
					}
				}
			}
		}
	}
	return bArray;
}


// 指定の武将ＩＤの武将がどこにいるのか？ 居ない場合、p(x=0xFFFF, y=0xFFFF) が返ってくる。
HEX_POSITION GetFieldHexUnitPos(int iBushouID) {

	HEX_POSITION pos(0xFFFF, 0xFFFF);

	if (!(0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
		return pos;
	}
	if (!Is_FieldWar()) {
		return pos;
	}

	// 戦場にいる武将から条件を満たすものの移動残量を増やす。
	for (int i = 0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == 0xFFFF) { continue; } // 0xFFFFだとそのスロットに武将は居ない。次の人
		if (nb6bushou_hex_unit_info[i].bushou > GAMEDATASTRUCT_BUSHOU_NUM) { continue; } //

																						 // 探してる武将が、表示中の野戦に居た!!
		if (iBushouID == nb6bushou_hex_unit_info[i].bushou - 1) {
			int x = nb6bushou_hex_unit_info[i].pos_x;
			int y = nb6bushou_hex_unit_info[i].pos_y;

			if (x == 0xFFFF) {
				return pos;
			}

			// yを座標実値にして、整数化
			pos.y = y;

			// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"座標を0.5分右にずらす。
			if (y % 2 == 1) {
				pos.x = x + 0.5;
			}
			else {
				pos.x = x;
			}

			return pos;
		}
	}

	return pos;
}




// 指定の武将ＩＤの武将がどこにいるのか？ 居ない場合、p(x=0xFFFF, y=0xFFFF) が返ってくる。
HEX_POSITION GetCastleHexUnitPos(int iBushouID) {


	HEX_POSITION pos(0xFFFF, 0xFFFF);

	if (!(0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
		return pos;
	}
	if (!Is_CastleWar()) {
		return pos;
	}

	// 戦場にいる武将から条件を満たすものの移動残量を増やす。
	for (int i = 0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == 0xFFFF) { continue; } // 0xFFFFだとそのスロットに武将は居ない。次の人
		if (nb6bushou_hex_unit_info[i].bushou > GAMEDATASTRUCT_BUSHOU_NUM) { continue; } //

																						 // 探してる武将が、表示中の攻城戦闘に居た!!
		if (iBushouID == nb6bushou_hex_unit_info[i].bushou - 1) {
			int x = nb6bushou_hex_unit_info[i].pos_x;
			int y = nb6bushou_hex_unit_info[i].pos_y;

			if (x == 0xFFFF) {
				return pos;
			}

			// yを座標実値にして、整数化
			pos.y = y;

			// 野戦の偶数行目か奇数行目かで、半身ずらす。偶数行なら、"座標を0.5分右にずらす。
			if (y % 2 == 1) {
				pos.x = x + 0.5;
			}
			else {
				pos.x = x;
			}

			return pos;
		}
	}

	return pos;
}


// 現在進行中の戦争に関わっているiDaimyoIDのリスト。(出陣しているかどうかは関係ない)
vector<int> GetCurWarJointDaimyoIDList() {
	vector<int> list;
	if (Is_FieldWar() || Is_CastleWar()) {
		// 参加大名番号を検索して、
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {

			int iDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1;
			// 範囲内であれば、リストに追加
			if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
				// 該当の値がすでにlist内にあるか
				vector<int>::iterator  iter = std::find(list.begin(), list.end(), iDaimyoID);
				// 存在しなければ…
				if (iter == list.end()) {
					// 追加
					list.push_back(iDaimyoID);
				}
			}
		}
	}


	return list;
}

// 現在進行中の戦争に関わっているiGundanIDのリスト。(出陣しているかどうかは関係ない)
vector<int> GetCurWarJointGundanIDList() {
	vector<int> list;
	if (Is_FieldWar() || Is_CastleWar()) {
		// 参加大名番号を検索して、
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {

			int iGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1;
			// 範囲内であれば、リストに追加
			if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
				list.push_back(iGundanID);
			}
		}
	}

	return list;
}




// 該当の軍団の戦場における立場を返す(直接守る側=0, 直接攻める側=1, 攻める側の援軍=3, 守る側の援軍=4, 中立軍=5)
int GetWarStandPointTheGundan(int iGundanID) {

	if (!(0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM)) {
		return WarStandPoint::unknown;
	}

	// enum { unknown = -1,  攻撃親軍 = 1,  攻撃子軍 = 5,  守備親軍=0, 守備子軍 = 4, 中立親軍=2, 中立子軍=6, 攻撃援軍親軍=1, 攻撃援軍子軍=5, 守備援軍親軍=0, 守備援軍子軍=4 };

	if (Is_FieldWar() || Is_CastleWar()) {

		//--------------------------------- 直接攻撃側、もしくは、直接防御側であれば、戦争開始パラメタからはじき出せる
		// 指定の軍団の大名ID
		int iDaimyoID = nb6gundan[iGundanID].attach - 1;

		// 攻撃側の軍団の大名ID
		int iAttackDaimyoID = -1;
		int iAttackGundanID = -1;
		if (0 <= nb6war_battle_daimyo_info.attack_gundan - 1 && nb6war_battle_daimyo_info.attack_gundan - 1 < GAMEDATASTRUCT_GUNDAN_NUM) {
			iAttackDaimyoID = nb6war_battle_daimyo_info.attack_daimyo - 1;
			iAttackGundanID = nb6war_battle_daimyo_info.attack_gundan - 1;
		}

		// 守備側の軍団の大名ID
		int iDefendDaimyoID = -1;
		int iDefendGundanID = -1;
		if (0 <= nb6war_battle_daimyo_info.defend_gundan - 1 && nb6war_battle_daimyo_info.defend_gundan - 1 < GAMEDATASTRUCT_GUNDAN_NUM) {
			iDefendDaimyoID = nb6war_battle_daimyo_info.defend_daimyo - 1;
			iDefendGundanID = nb6war_battle_daimyo_info.defend_gundan - 1;
		}

		// 指定の軍団の大名は直接攻撃の大名
		if (iDaimyoID == iAttackDaimyoID) {
			return WarStandPoint::attack; // 直接攻撃側
		}
		// 指定の軍団の大名は直接守備の大名
		else if (iDaimyoID == iDefendDaimyoID) {
			return WarStandPoint::defend; // 直接防御側
		}

		//--------------------------------- それ以外の場合は、WAR_JOINT_DAIMYO_HEX_GROUP_INFO 系の情報から辿っていく

		// 参加大名番号を検索して、攻撃側のグループID、守備側のグループIDを出す。
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {
			// 援軍や中立軍かチェック
			int JoinGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1; // 参加軍団ID
			int JoinDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1; // 参加大名ID
																					   // 指定の軍団と同じ軍団IDである場合のみ値を返す。
			if (iGundanID == JoinGundanID) {

				// 指定の軍団の大名は直接攻撃の大名
				if (JoinDaimyoID == iAttackDaimyoID) {
					return WarStandPoint::attack; // 直接攻撃側
				}
				// 指定の軍団の大名は直接守備の大名
				else if (JoinDaimyoID == iDefendDaimyoID) {
					return WarStandPoint::defend; // 直接防御側
				}

				// 2か6なら中立軍。2が中立の親軍で、6が中立の子軍
				else if (nb6war_joint_daimyo_hex_group_info[ix].group == 2 || nb6war_joint_daimyo_hex_group_info[ix].group == 6) {
					// 中立軍
					return WarStandPoint::chuuritsu;
				}
				// 1か5なら援軍の攻撃軍。1が援軍の親軍で、5が援軍の子軍
				else if (nb6war_joint_daimyo_hex_group_info[ix].group == 1 || nb6war_joint_daimyo_hex_group_info[ix].group == 5) {
					// 援軍の攻撃軍
					return WarStandPoint::attack_enngun;
				}
				// 0か4なら援軍の守備軍。0が援軍の親軍で、4が援軍の子軍
				else if (nb6war_joint_daimyo_hex_group_info[ix].group == 0 || nb6war_joint_daimyo_hex_group_info[ix].group == 4) {
					// 援軍の守備軍
					return WarStandPoint::defend_enngun;
				}
			}
		}
	}

	return WarStandPoint::unknown; // 不明
}

// 該当の武将の戦場における立場を返す(不明=0, 直接攻める側=1, 直接守る側=2, 攻める側の援軍=3, 守る側の援軍=4, 中立軍=5)
int GetWarStandPointTheBushou(int iBushouID) {

	// 範囲チェック
	if (!(0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
		return WarStandPoint::unknown;
	}

	// 該当武将の軍団ID入手
	int iGundanID = nb6bushou[iBushouID].gundan - 1;
	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
		return GetWarStandPointTheGundan(iGundanID);
	}

	return WarStandPoint::unknown;
}

// 現在の戦において、指定軍団の総大将(軍団長や大名のことではなく、戦場においての該当軍団の総大将。
int GetWarSoudaishoTheGundan(int iGundanID) {
	if (!(0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM)) {
		return 0xFFFF;
	}

	if (Is_FieldWar() || Is_CastleWar()) {
		// 参加大名番号を検索して、攻撃側のグループID、守備側のグループIDを出す。
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {

			int iJointGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1;

			// 指定の軍団を見つけた。
			if (iGundanID == iJointGundanID) {
				// 武将番号(+1の方)の範囲に収まっている。
				if (0 < nb6war_joint_daimyo_hex_group_info[ix].soudaisho && nb6war_joint_daimyo_hex_group_info[ix].soudaisho <= GAMEDATASTRUCT_BUSHOU_NUM) {
					return nb6war_joint_daimyo_hex_group_info[ix].soudaisho - 1;
					// 武将番号の範囲に収まっていないということは、大名や軍団は決まっているが、総大将が決まっていない。ユニット配置前だと総大将が決まらないので、このような値となる。
				}
				else {
					return 0xFFFF;
				}
			}
		}
	}

	return 0xFFFF;
}



// 指定武将が戦場において、行動済みかどうか
BOOL IsActionEndInBattle(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
			if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
				if (nb6bushou_hex_unit_info[i].bEnd == 0x2) { // 行動済である。
					return TRUE;
				}
				else {
					return FALSE;
				}
				break;
			}
		}
	}
	return FALSE;
}


// 対象の武将が混乱しているか。
int GetKonranStatus(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
			if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
				return nb6bushou_hex_unit_info[i].konran;
			}
		}
	}
	return KONRAN_STATUS::無し;
}


int GetBushouMovePower(int iBushouID) {

	// 移動力を若干回復
	for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
			return nb6bushou_hex_unit_info[i].movepower;
		}
	}
	return 0xFFFF;
}


int SetBushouMovePower(int iBushouID, int iMovePower) {

	// 移動力を若干回復
	for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
			nb6bushou_hex_unit_info[i].movepower = iMovePower;
			break;
		}
	}
	return 0xFFFF;
}
