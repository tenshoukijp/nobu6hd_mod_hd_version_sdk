#include <algorithm>
#include "GameDataStruct.h"

using namespace std;


// とある大名勢力の統治軍団番号リストを得る。
vector<int> getGovernedGundanList(int iDaimyoID) {
	// それ以外は何も入れずに返す。
	vector<int> list;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// 該当の大名ＩＤに属する軍団をリストに加える
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				list.push_back(iGundanID);
			}
		}
	}

	return list;
}

// 軍団に所属する武将リストを得る
vector<int> getGundanBushouList(int iGundanID) {
	// それ以外は何も入れずに返す。
	vector<int> list;

	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].gundan - 1 == iGundanID) {
			if (nb6bushouname[i].State <= 2) { // 大名, 軍団長, 現役 でカウント
				list.push_back(i);
			}
		}
	}
	return list;
}

/// 現在(その瞬間)、天翔記に存在する軍団の「軍団番号【配列用】」をリストで得る。
vector<int> getValidGundanList() {
	vector<int> list;

	// 該当の大名ＩＤに属する軍団をリストに加える
	for (int iGundanID = 0; iGundanID < GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
		if (nb6gundan[iGundanID].leader != 0xFFFF) {
			list.push_back(iGundanID);
		}
	}

	return list;
}


// 軍団に所属する兵数を得る
int getGundanHeisuCnt(int iGundanID) {
	int iSoldierCnt = 0;
	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].gundan - 1 == iGundanID) {
			if (nb6bushouname[i].State <= 2) { // 大名, 軍団長, 現役 でカウント
				iSoldierCnt += nb6bushou[i].soldier;
			}
		}
	}
	return iSoldierCnt;
}

// とある大名勢力の統治軍団割りあて番号リストを得る。
vector<int> getGovernedGundanWariateNumList(int iDaimyoID) {
	// それ以外は何も入れずに返す。
	vector<int> list;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// 該当の大名ＩＤに属する軍団をリストに加える
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				list.push_back(nb6gundan[iGundanID].number);
			}
		}
	}

	std::sort(list.begin(), list.end());//昇順ソート

	return list;
}



// とある大名配下の軍団下にある軍団「未」割当番号のリストを得る。
vector<int> getNotGovernedGundanWariateNumList(int iDaimyoID) {

	// 割り当てられてるものに、１を入れる
	int wariate_array[8] = { 0,0,0,0,0,0,0,0 };

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// 該当の大名ＩＤに属する軍団をリストに加える
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				int g = nb6gundan[iGundanID].number;
				if (1 <= g && g <= 8) {
					// 割り当てられてるものに、１を入れる
					wariate_array[g - 1] = 1;
				}
			}
		}
	}

	vector<int> list;
	for (int ix = 0; ix<8; ix++) {
		if (wariate_array[ix] == 0) { // 軍団割当がなければ
			list.push_back(ix + 1);
		}
	}

	std::sort(list.begin(), list.end());//昇順ソート

	return list;
}

// 軍団任命番号の変更(入替)を試みる。失敗すればfalse
bool tryChangeGundanWariateNum(int iGundanID, int iNewWariateNum) {

	// 第１軍団は大名自身。変更は無理。
	if (nb6gundan[iGundanID].number == 1) {
		return false;
	}

	if (!(1 <= iNewWariateNum && iNewWariateNum <= 8) ) {
		return false;
	}

	// 自分の軍団の大名のID
	int iDaimyoID = nb6gundan[iGundanID].attach - 1;

	// 大名麾下で空きスロットとなっている任命番号一覧
	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		vector<int> sameDaimyoGundanList = getGovernedGundanList(iDaimyoID);
		int iOldNinmeiNum = nb6gundan[iGundanID].number; // 今までの任命番号

														 // 別軍団が指定の軍団を利用しているならば、自分の軍団番号をその軍団に差し上げる。
		for each (int iGID in sameDaimyoGundanList) {
			// すでに別軍団で利用されているならば
			if (nb6gundan[iGID].number == iNewWariateNum) {
				nb6gundan[iGID].number = iOldNinmeiNum;
				break;
			}
		}

		// 自分は指定の軍団番号となる。
		nb6gundan[iGundanID].number = iNewWariateNum;

		return true;
	}

	return false;

}


// 指定の軍団の所属する大名を勢力を越えて、変更する。
bool setGundanReAttachDaimyo(int iGundanID, int iNewDaimyoID) {

	// 新大名が正当ではない。
	if (!(0 <= iNewDaimyoID && iNewDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM)) {
		return false;
	}

	// 軍団が全部埋まっているならば、
	vector<int> glist = getGovernedGundanWariateNumList(iNewDaimyoID);
	if (glist.size() == 8) { // 軍団は全部埋まっている
							 // 何もできない
		return false;
	}

	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {

		// 指定の軍団が現在所属している大名番号を求める
		int iDaimyoID = nb6gundan[iGundanID].attach - 1;
		// 新所属先の大名が、今所属している大名であれば、何もすることはない。
		if (iDaimyoID == iNewDaimyoID) {
			return true;
		}

		// 軍団割り当て番号が１番は大名自身。これは固定。この場合、何もせず失敗とする。
		if (nb6gundan[iGundanID].number == 1) {
			return false;
		}

		// 現在、新大名に所属していて、nextが0xFFFFになっている軍団が、ぶら下がるべきリンクリストの最後だ。
		// ぶら下がることが出来るか、事前にチェックしておく。
		int iLinkEndGundanID = -1;
		for (int iCurGundanID = 0; iCurGundanID < GAMEDATASTRUCT_GUNDAN_NUM; iCurGundanID++) {
			// 
			int iCurDaimyoID = nb6gundan[iCurGundanID].attach - 1;

			// 指定の新大名に所属しているならば、
			if (iCurDaimyoID == iNewDaimyoID) {
				// 次の軍団が無いのであれば、そいつが最終軍団番号
				if (nb6gundan[iCurGundanID].next == 0xFFFF) {
					iLinkEndGundanID = iCurGundanID + 1;
				}

			}

		}

		// それが範囲に入っていないならば、新大名の軍団リンクリストは、改造か何かしらないが情報が壊れている。
		// 処理終了
		if (!(0 < iLinkEndGundanID && iLinkEndGundanID <= GAMEDATASTRUCT_GUNDAN_NUM)) {
			return false;
		}

		/* 　自軍団
		↓
		○-●-○-○

		というのを

		○-○-○

		とする。
		*/

		int iPrevID = nb6gundan[iGundanID].prev;
		int iNextID = nb6gundan[iGundanID].next;

		// 自分のprevは有効な軍団だ。
		if (0 < iPrevID && iPrevID <= GAMEDATASTRUCT_GUNDAN_NUM) {

			// 自分が先頭ではない軍団で、
			// １つ前の軍団の次のリンク先が自軍団の場合
			if (iPrevID != 0xFFFF && nb6gundan[(iPrevID - 1)].next == iGundanID + 1) {
				// 自軍団ではなく、次の軍団へと繋ぎかえる。
				nb6gundan[(iPrevID - 1)].next = iNextID;
			}
		}

		// 自分のnextは有効な軍団だ。
		if (0 < iNextID && iNextID <= GAMEDATASTRUCT_GUNDAN_NUM) {
			// １つ後の軍団の前のリンク先が自軍団の場合
			if (iNextID != 0xFFFF && nb6gundan[(iNextID - 1)].prev == iGundanID + 1) {
				// 自軍団ではなく、前の軍団へと繋ぎかえる。
				nb6gundan[(iNextID - 1)].prev = iPrevID;
			}
		}


		/* 　

		○-○

		というのを

		○-○-●

		とする。
		*/



		nb6gundan[iLinkEndGundanID - 1].next = iGundanID + 1; // リンクリストの最後の軍団のnextを自軍団に

		nb6gundan[iGundanID].prev = iLinkEndGundanID; // 自軍団の前の軍団は、軍団のリンクリストの最後の軍団

													  // 自軍団は、軍団リストの一番最後にくっつく。自軍団のnextは居ない
		nb6gundan[iGundanID].next = 0xFFFF; // 

											// メモリ書き換え
		{
			nb6gundan[iGundanID].number = 8; // 元の番号というわけにはいかないので、万が一のために、とりあえず、最も高い確率で空いてるセーフなものを取る

			vector<int> milist = getNotGovernedGundanWariateNumList(iNewDaimyoID);
			if (milist.size() > 0) {
				nb6gundan[iGundanID].number = milist[0]; // 空番号の最初のものを放り込む
			}

			nb6gundan[iGundanID].attach = iNewDaimyoID + 1;
		}

		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
			// 指定の軍団に所属している武将は、全て、新大名に所属を変更する。
			if (nb6bushou[iBushouID].gundan == iGundanID + 1) {
				nb6bushou[iBushouID].attach = iNewDaimyoID + 1;
				nb6bushou[iBushouID].work = 0; // 士官年数リセット
				nb6bushou[iBushouID].rise = 0xFFFF; // 内応先リセット
				nb6bushou[iBushouID].bRise = 0; // 内応状態なし
				nb6bushou[iBushouID].grudge = 0; // 遺恨なし
			}
		}

		return true;

	}

	return false;
}
