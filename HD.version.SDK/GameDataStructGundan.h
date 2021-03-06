#pragma once

/*			軍団情報(21*214)

[21バイト]

0-1	前の軍団
2-3 後ろの軍団
4-5	居城名ナンバー
6-7	軍団長ナンバー(武将名前テーブルの順番)
8-9	大名
10	行動力
11-12	金
13-14	米
15-16	騎馬
17-18	鉄砲
19	？
20	aaaabbbb A 役職 B 軍団番号
0 無し 1 征夷大将軍 2 管領 3 関東管領 4 奥州探題 5 西国探題 6 九州探題 7 羽州探題 ⇒ getNormalizedGundanPosition

*/
struct NB6GUNDAN
{
	WORD prev;		//前の軍団
	WORD next;		//後ろの軍団
	WORD residence;	//居城名ナンバー
	WORD leader;	//軍団長ナンバー(武将名前テーブルの順番)
	WORD attach;	//所属(大名) (大名番号テーブルの順番)
	byte act;		//行動力
	WORD money;		//金
	WORD rise;		//米
	WORD horse;		//馬
	WORD gun;		//鉄砲
	byte _undef;	//must 0?
	byte number : 4;	//1-8 ⇒ 軍団番号
	byte position : 4;//役職  (0 無し 1 征夷大将軍 2 管領 3 関東管領 4 奥州探題 5 西国探題 6 九州探題 7 羽州探題) ⇒ getNormalizedGundanPosition
};


/// 現在(その瞬間)、天翔記に存在する軍団の「軍団番号【配列用】」をリストで得る。
vector<int> getValidGundanList();

// 同じ大名に属する軍団番号【配列用】のリストを得る
vector<int> getGovernedGundanList(int iDaimyoID);

// 軍団に所属する武将リストを得る
vector<int> getGundanBushouList(int iGundanID);

// 軍団に所属する兵数を得る
int getGundanHeisuCnt(int iGundanID);

// とある大名勢力の統治軍団割りあて番号リストを得る。
vector<int> getGovernedGundanWariateNumList(int iDaimyoID);

// とある大名配下の軍団下にある軍団「未」割当番号のリストを得る。
vector<int> getNotGovernedGundanWariateNumList(int iDaimyoID);

// 軍団任命番号の変更(入替)を試みる。失敗すればfalse
bool tryChangeGundanWariateNum(int iGundanID, int iNewWariateNum);

// 指定の軍団の所属する大名を勢力を越えて、変更する。
bool setGundanReAttachDaimyo(int iGundanID, int iNewDaimyoID);

