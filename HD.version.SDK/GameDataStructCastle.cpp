#include "GameDataStruct.h"

// 勝手に文字列を決めうちせずに、TENSHOU.EXE内のポインタ配列から引っ張るようにした方が、他者の改造への耐久力が増すかも。
static char nb6CastleTypeName[GAMEDATASTRUCT_CASTLETYPE_NUM][5] = {
	"城",
	"御坊",
	"寺",
	"御所",
	"館",
	"",
	"城"
};

// 城のタイプIDから具体的な文字列を得る
char *getCastleTypeName(int iCastleType) {
	if (iCastleType == 0x00) {
		return nb6CastleTypeName[0];
	}
	else if (iCastleType == 0x01) {
		return nb6CastleTypeName[1];
	}
	else if (iCastleType == 0x02) {
		return nb6CastleTypeName[2];
	}
	else if (iCastleType == 0x04) {
		return nb6CastleTypeName[3];
	}
	else if (iCastleType == 0x08) {
		return nb6CastleTypeName[4];
	}
	else if (iCastleType == 0x10) {
		return nb6CastleTypeName[5];
	}
	else if (iCastleType == 0x20) {
		return nb6CastleTypeName[6];
	}
	return "";
}


// 指定の軍団が所持している城の数。
int getGundanHasCastleNum(int iGundanID) {
	int iHasCastleCnt = 0;
	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
		for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
			// 軍団番号が一致するものをカウント
			if (iGundanID == nb6castle[iCastleID].attach - 1) {
				iHasCastleCnt++;
			}
		}
	}
	return iHasCastleCnt;
}

// 指定の大名が所持している城の数。
int getDaimyoHasCastleNum(int iDaimyoID) {
	int iHasCastleCnt = 0;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
			int iGundanID = nb6castle[iCastleID].attach - 1;

			if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
				// 大名番号が一致するものをカウント
				if (iDaimyoID == nb6gundan[iGundanID].attach - 1) {
					iHasCastleCnt++;
				}
			}
		}
	}
	return iHasCastleCnt;
}


// 城に所属する兵数を得る
int getCastleHeisuCnt(int iCastleID) {
	int iSoldierCnt = 0;
	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].castle - 1 == iCastleID) {
			if (nb6bushouname[i].State <= 2) { // 大名, 軍団長, 現役 でカウント
				iSoldierCnt += nb6bushou[i].soldier;
			}
		}
	}
	return iSoldierCnt;
}





//--------------MAINのグリッド系

// グリッドポジションクラス
GRID_POSITION::GRID_POSITION(int _x, int _y) {
	x = _x,
		y = _y;

	// 各隣接城は無い状態で初期化
	nw = 0xFFFF;
	no = 0xFFFF;
	ne = 0xFFFF;
	we = 0xFFFF;
	ea = 0xFFFF;
	sw = 0xFFFF;
	so = 0xFFFF;
	se = 0xFFFF;

}

// グリッド座標同志の減算。座標Ａ→座標Ｂのベクトルを求めるのに、通常、Ｂ－Ａをするだろうから。
GRID_VECTOR operator-(GRID_POSITION &p1, GRID_POSITION &p2) {
	GRID_VECTOR p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}

// 城ＩＤから、メイングリッド上のポジションを得る。左上グリッドが0,0。mapdataobgkのグリッドを見ればわかりやすい。
// １つのグリッドには、１つの城しかない。
GRID_POSITION getCastlePosInMainGrid(int iCastleID) {
	GRID_POSITION pos(0, 0);
	if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		int iGridX = (nb6castlemax[iCastleID].x + 1) / 5; // ０オリジンなので＋１して５で割る。Ｘ方向は１つのグリッドの中に５つの場所がある。
		int iGridY = (nb6castlemax[iCastleID].y + 1) / 3; // ０オリジンなので＋１して３で割る。Ｙ方向は１つのグリッドの中に３つの場所がある。

		pos.x = iGridX;
		pos.y = iGridY;

		// 隣接する城のＩＤも入れておく。
		for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
			int iFX = (nb6castlemax[iCastleID].x + 1) / 5; // ０オリジンなので＋１して５で割る。Ｘ方向は１つのグリッドの中に５つの場所がある。
			int iFY = (nb6castlemax[iCastleID].y + 1) / 3; // ０オリジンなので＋１して３で割る。Ｙ方向は１つのグリッドの中に３つの場所がある。

			if (iFX - pos.x == -1 && iFY - pos.y == -1) { // 北西
				pos.nw = iCastleID + 1;
			}
			else if (iFX - pos.x == 0 && iFY - pos.y == -1) { // 北
				pos.no = iCastleID + 1;
			}
			else if (iFX - pos.x == 1 && iFY - pos.y == -1) { // 北東
				pos.ne = iCastleID + 1;
			}
			else if (iFX - pos.x == -1 && iFY - pos.y == 0) { // 西
				pos.we = iCastleID + 1;
			}
			else if (iFX - pos.x == 1 && iFY - pos.y == 0) { // 東
				pos.ea = iCastleID + 1;
			}
			else if (iFX - pos.x == -1 && iFY - pos.y == 1) { // 南西
				pos.sw = iCastleID + 1;
			}
			else if (iFX - pos.x == 0 && iFY - pos.y == 1) { // 南
				pos.so = iCastleID + 1;
			}
			else if (iFX - pos.x == 1 && iFY - pos.y == 1) { // 南東
				pos.se = iCastleID + 1;
			}
		}

		return pos;
	}
	return pos;
}

// 指定の城に対して隣接している城のリストを得る
vector<int> getRinsetsuCastles(int iCastleID) {
	// まずは、指定城のグリッドの場所を得る
	GRID_POSITION CenterPos = getCastlePosInMainGrid(iCastleID);

	vector<int> RinsetsuCastles;

	// 隣接している城をベクトルに追加してゆく
	for (int iTargetID = 0; iTargetID < GAMEDATASTRUCT_CASTLE_NUM; iTargetID++) {
		// 自分自身はパス
		if (iCastleID == iTargetID) {
			continue;
		}

		GRID_POSITION TargetPos = getCastlePosInMainGrid(iTargetID);
		// 隣接している。
		if (abs(CenterPos.x - TargetPos.x) <= 1 && abs(CenterPos.y - TargetPos.y) <= 1) {
			RinsetsuCastles.push_back(iTargetID);
		}
	}
	return RinsetsuCastles;
}

