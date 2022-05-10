#include "GameDataStruct.h"

// 武将の年齢を得る
int getYearsOld(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		return nb6year.year - nb6bushou[iBushouID].birth + 1;
	}
	return 0xFF;
}


// 足軽・騎馬・鉄砲・水軍の適正を数値で得る。(0=E,1=D,2=C,3=B,4=A,5=S)
int getBushouAptitude(int iBushouID, APTITUDE eAptitude) {
	if (eAptitude == APTITUDE_ASIGARU) {
		return nb6bushou[iBushouID].aptitudeasi;
	}
	else if (eAptitude == APTITUDE_KIBA) {
		return nb6bushou[iBushouID].aptitudekib;
	}
	else if (eAptitude == APTITUDE_TEPPOU) {
		// 鉄砲は２つのフィットフィールドに分かれてしまっているので、計算
		int ret = nb6bushou[iBushouID]._aptitudegun_lo << 2;
		ret += nb6bushou[iBushouID]._aptitudegun_hi;
		return ret;
	}
	else if (eAptitude == APTITUDE_SUIGUN) {
		return nb6bushou[iBushouID].aptitudesui;
	}
	return -1;
}



// 足軽・騎馬・鉄砲・水軍の適正を数値で設定する。(0=E,1=D,2=C,3=B,4=A,5=S)
void setBushouAptitude(int iBushouID, APTITUDE eAptitude, int iTekisei) {
	if (eAptitude == APTITUDE_ASIGARU) {
		nb6bushou[iBushouID].aptitudeasi = iTekisei;
	}
	else if (eAptitude == APTITUDE_KIBA) {
		nb6bushou[iBushouID].aptitudekib = iTekisei;
	}
	else if (eAptitude == APTITUDE_TEPPOU) {
		// 鉄砲は２つのフィットフィールドに分かれてしまっているので、計算
		nb6bushou[iBushouID]._aptitudegun_hi = iTekisei & 0x0003;  // 0b000000HH
		nb6bushou[iBushouID]._aptitudegun_lo = iTekisei >> 2;      // 0b00000L00
	}
	else if (eAptitude == APTITUDE_SUIGUN) {
		nb6bushou[iBushouID].aptitudesui = iTekisei;
	}
}



// 武将の独立値を得る
int getBushouIndependence(int iBushouID) {
	// 鉄砲は２つのフィットフィールドに分かれてしまっているので、計算
	int ret = nb6bushou[iBushouID]._independence_lo << 2;
	ret += nb6bushou[iBushouID]._independence_hi;
	return ret;
}

// 武将の独立値を設定する
void setBushouIndependence(int iBushouID, int iIndependence) {
	nb6bushou[iBushouID]._independence_hi = iIndependence & 0x0003;  // 0b000000HH
	nb6bushou[iBushouID]._independence_lo = iIndependence >> 2;      // 0b00000L00
}

// 武将の戦闘値
int getBushouBat(int iBushouID) {
	// 戦才×戦塾/2000が
	return int(nb6bushou[iBushouID].maxbat * (float(nb6bushou[iBushouID].expbat) / float(2000)));
}
// 武将の智謀値
int getBushouInt(int iBushouID) {
	// 戦才×戦塾/2000が
	return int(nb6bushou[iBushouID].maxint * (float(nb6bushou[iBushouID].expint) / float(2000)));
}
// 武将の政治値
int getBushouGov(int iBushouID) {
	// 戦才×戦塾/2000が
	return int(nb6bushou[iBushouID].maxgov * (float(nb6bushou[iBushouID].expgov) / float(2000)));
}


// 家宝などを含めない素の政治才能
int getBushouPureGovMax(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 政治増加タイプ：0 茶碗  1 茶壺  2 茶入  3 茶釜  4 花入  
			if (0 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 4) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇値
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int maxgov = nb6bushou[iBushouID].maxgov;
		return (maxgov - upparam) > 0 ? (maxgov - upparam) : 1;
	}
	else {
		return 0;
	}
}

// 家宝などを含めない素の戦闘才能
int getBushouPureBatMax(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 戦闘増加タイプ：5 刀剣  6 槍  7 具足  8 馬  9 鞍  A 陣羽織   
			if (5 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xA) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇地
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int maxbat = nb6bushou[iBushouID].maxbat;
		return (maxbat - upparam) > 0 ? (maxbat - upparam) : 1;
	}
	else {
		return 0;
	}
}

// 家宝などを含めない素の智謀才能
int getBushouPureIntMax(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 智謀増加タイプ：B 巻子本  C 明朝綴本
			if (0xB <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xC) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇地
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int maxint = nb6bushou[iBushouID].maxint;
		return (maxint - upparam) > 0 ? (maxint - upparam) : 1;
	}
	else {
		return 0;
	}
}

// 家宝などを含めない素の野望
int getBushouPureAmbition(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 野望増加タイプ：D 香木  E 地球儀  F 南蛮時計  10 水墨画  11 十字架  12 聖書  13 玉手箱  14 ビードロ杯  15 遠眼鏡  16 ルソン壺  17 煙草
			if (0xD <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0x17) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇地
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int ambition = nb6bushou[iBushouID].ambition;
		return (ambition - upparam) > 0 ? (ambition - upparam) : 1;
	}
	else {
		return 0;
	}
}

// 官位などを含めない素の魅力
int getBushouPureCharm(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKaniID = 0; iKaniID < GAMEDATASTRUCT_KANI_NUM; iKaniID++) {
			// 持ち主と指定武将が一致した
			if (nb6kani[iKaniID].attach == iBushouID + 1) {
				// 今までで最大の上昇地
				if (nb6kani[iKaniID].param > upparam) {
					upparam = nb6kani[iKaniID].param;
				}
			}
		}

		int charm = nb6bushou[iBushouID].charm;
		return (charm - upparam) > 0 ? (charm - upparam) : 1;
	}
	else {
		return 0;
	}
}



// 家宝による政治の上げ幅
int getBushouGovMaxUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 政治増加タイプ：0 茶碗  1 茶壺  2 茶入  3 茶釜  4 花入  
			if (0 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 4) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇値
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}

// 家宝による戦闘の上げ幅
int getBushouBatMaxUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 戦闘増加タイプ：5 刀剣  6 槍  7 具足  8 馬  9 鞍  A 陣羽織   
			if (5 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xA) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇地
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}

// 家宝による智謀の上げ幅
int getBushouIntMaxUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 智謀増加タイプ：B 巻子本  C 明朝綴本
			if (0xB <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xC) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇地
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		return upparam;
	}
	else {
		return 0;
	}
}

// 家宝による野望の上げ幅
int getBushouAmbitionUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// 野望増加タイプ：D 香木  E 地球儀  F 南蛮時計  10 水墨画  11 十字架  12 聖書  13 玉手箱  14 ビードロ杯  15 遠眼鏡  16 ルソン壺  17 煙草
			if (0xD <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0x17) {
				// 持ち主と指定武将が一致した
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// 今までで最大の上昇地
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}


// 官位による魅力の上げ幅
int getBushouCharmUpByKani(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // 上昇値
		for (int iKaniID = 0; iKaniID < GAMEDATASTRUCT_KANI_NUM; iKaniID++) {
			// 持ち主と指定武将が一致した
			if (nb6kani[iKaniID].attach == iBushouID + 1) {
				// 今までで最大の上昇地
				if (nb6kani[iKaniID].param > upparam) {
					upparam = nb6kani[iKaniID].param;
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}




// 顔IDから武将IDを求める。失敗時は0xFFFF
int getBushouIDFromFaceID(int iFaceID) {
	for (int iBushouID = 0; iBushouID<GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
		if (nb6bushouname[iBushouID].number == iFaceID) {
			return iBushouID;
		}
	}
	return 0xFFFF;
}


// 指定武将の伴侶のiBushouIDを得る。伴侶が居ない場合には、0xFFFFが返ってくる。
int getHanryoBushouID(int iBushouID) {

	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 指定の武将の伴侶情報
		int iBushouIDSpouse = nb6bushou[iBushouID].spouse; //

														   // 結婚していない
		if (iBushouIDSpouse == 0xFF) {
			return 0xFFFF;
		}

		int iTsumaBushouID = iBushouIDSpouse + 500;

		// 伴侶の番号が自分自身だったら、自分は妻側の立場
		if (iTsumaBushouID == iBushouID) {
			for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
				// 自分自身以外で、同じ伴侶番号を持ってるのが、伴侶の武将
				if (i != iBushouID &&  nb6bushou[i].spouse == iBushouIDSpouse) {
					return i;
				}
			}
			return 0xFFFF;

			// 自分は夫側。妻にも同じ番号が設定されているか確認。
		}
		else {
			if (nb6bushou[iTsumaBushouID].spouse == iBushouIDSpouse) {
				return iTsumaBushouID;
				// なぜか設定されていない…。改造等でデータ壊れている。
			}
			else {
				return 0xFFFF;
			}
		}
	}
	else {
		return 0xFFFF;
	}
}

// 姫(他の武将の妻含む)を、指定の武将と結婚させる、同盟関係等は一切操作されない。
bool setHimeMarriage(int iHimeID, int iOttoID, BOOL withKodokuDeath) {

	// 同一人物。アウト。
	if (iHimeID == iOttoID) { return false; }

	// 夫と姫が規定の範囲に入っていなければアウト
	if (0 <= iOttoID && iOttoID < GAMEDATASTRUCT_BUSHOU_NUM &&
		500 <= iHimeID && iHimeID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// もし姫側のＩＤの武将が、姫でないならば、アウト
		if (nb6bushouname[iHimeID].State != 5) { // 
			return false;
		}

		int _new_spouse = iHimeID - 500; // 妻に入るべき値は、姫武将番号【配列用】-500

										 // すでに両者は夫婦である、何もする必要が無い。
		if (nb6bushou[iOttoID].spouse == _new_spouse &&  nb6bushou[iHimeID].spouse == _new_spouse) {
			return true;
		}

		// 夫側がすでに結婚しているか、結婚していたら離婚
		int _otto_old_spouse = nb6bushou[iOttoID].spouse; //
														  // 離婚
		setHimeDivorce(_otto_old_spouse + 500, withKodokuDeath);

		nb6bushouname[iHimeID].State = 5; // 天蓋孤独処理で死亡したかもしれないので姫に戻す。

		int _tuma_old_spouse = nb6bushou[iHimeID].spouse; //
		setHimeDivorce(_tuma_old_spouse + 500, withKodokuDeath);

		nb6bushouname[iHimeID].State = 5; // 天蓋孤独処理で死亡したかもしれないので姫に戻す。

										  // 身が綺麗になったので改めて結婚
		nb6bushou[iOttoID].spouse = _new_spouse;
		nb6bushou[iHimeID].spouse = _new_spouse;

		// 旧大名家を覚えておいて
		int OldDaimyoID = nb6bushou[iHimeID].attach;

		// 夫側の大名の方に身を寄せる
		nb6bushou[iHimeID].attach = nb6bushou[iOttoID].attach;

		// 名字を夫のもので上書きする。
		strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iOttoID].familyname);

		// 結果、大名家が変化したのであれば、士官年数もリセット
		if (OldDaimyoID != nb6bushou[iHimeID].attach) {
			nb6bushou[iHimeID].work = 0;
		}

		return true;
	}

	return false;
}


// 指定の姫を離婚させる。
bool setHimeDivorce(int iHimeID, BOOL withKodokuDeath) {

	// 夫と姫が規定の範囲に入っていなければアウト
	if (500 <= iHimeID && iHimeID < GAMEDATASTRUCT_BUSHOU_NUM) {


		// もし姫側のＩＤの武将が、姫でないならば、アウト
		if (nb6bushouname[iHimeID].State != 5) {
			return false;
		}

		int _tuma_spouse = nb6bushou[iHimeID].spouse; //

													  // 元々結婚していない。
		if (_tuma_spouse == 0xFF) {
			return false;
		}

		// 両者の結婚情報をクリア
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
			// 夫もしくは妻である
			if (nb6bushou[iBushouID].spouse == _tuma_spouse) {
				// 離婚
				nb6bushou[iBushouID].spouse = 0xFF;
				// 夫と妻2人両方とも値を0xFFにする必要があるので、breakしないこと。
				// ついでにデータにゴミが入っている場合でもクリア
			}
		}


		// 旧大名家を覚えておいて
		int OldDaimyoID = nb6bushou[iHimeID].attach;

		// 以下の身元引受人系の処理は、プログラム側で出来るだけやっておこうという趣旨。
		// 仮にここで適切な大名に帰属転移できなかったとしても、天翔記のプログラム本体が次季節時には、適切な大名に帰属させる処理を行う。

		// 離婚したので所属大名を変更する必要性がある。まず、親が大名をしているかどうか。
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// 大名のうち…
			if (nb6bushouname[iBushouID].State == 0) { // 大名

													   // 自分の親が大名やってる。
				if (nb6bushou[iHimeID].parent < 5000) {
					// その大名は姫の親
					if (nb6bushouname[iBushouID].number == nb6bushou[iHimeID].parent) {

						// そこに身を寄せる
						nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

						strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);
						break;
					}
				}
			}
		}


		// 親が大名をやっていなくとも、親が同じ人(即ち兄弟姉妹)が大名をやっているかどうか。
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// 大名のうち…
			if (nb6bushouname[iBushouID].State == 0) { // 大名

													   // 親が同じだ。
				if (nb6bushou[iHimeID].parent < 5000) {
					if (nb6bushou[iBushouID].parent == nb6bushou[iHimeID].parent) {

						// そこに身を寄せる
						nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

						strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);
						break;
					}
				}
			}
		}

		// 親兄弟が大名やっていなくても、一門が大名をやっているのではないか。
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// 大名のうち…
			if (nb6bushouname[iBushouID].State == 0) { // 大名

													   // 親が同じだ。
				if (nb6bushou[iHimeID].blood != 0xFF) {
					if (nb6bushou[iBushouID].blood == nb6bushou[iHimeID].blood) {

						// そこに身を寄せる
						nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

						strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);
						break;
					}
				}
			}
		}

		bool isTengaiKodoku = true;
		// 大名でなくとも、親がどこかにいるのではないか？
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// 自分の親
			if (nb6bushou[iHimeID].parent < 5000) {
				if (nb6bushouname[iBushouID].number == nb6bushou[iHimeID].parent) {

					// そこに身を寄せる
					nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

					strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);

					// 身よりが居たので天蓋孤独ではない
					isTengaiKodoku = false;
					break;
				}
			}
		}

		// 大名でなくとも、親が同じ人(即ち兄弟姉妹)がどこかにいるのではないか？
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// 親が同じだ。
			if (nb6bushou[iHimeID].parent < 5000) {
				if (nb6bushou[iBushouID].parent == nb6bushou[iHimeID].parent) {

					// そこに身を寄せる
					nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

					strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);

					// 身よりが居たので天蓋孤独ではない
					isTengaiKodoku = false;
					break;
				}
			}
		}


		// 結果、大名家が変化したのであれば、士官年数もリセット
		if (OldDaimyoID != nb6bushou[iHimeID].attach) {
			nb6bushou[iHimeID].work = 0;
		}

		if (withKodokuDeath) {
			if (isTengaiKodoku) {
				nb6bushouname[iHimeID].State = 7; // 天蓋孤独になったら死亡とする。
			}
		}

		return true;
	}

	return false;
}




// State 現役 → State 浪人へ
bool setGenekiToRounin(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushouname[iBushouID].State == 2) { // 現役武将の場合だけ処理をする。

												   // 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = nb6bushou[iBushouID].castle - 1;
			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
				if (nb6castle[iCastleID].master == 0xFFFF) { return false; } // リンクリストが壊れているのか城に誰も所属していない。何もしない。return;

																			 // メモリ上の値変更
				{
					nb6bushouname[iBushouID].State = 4; // 状態を浪人とする。

					nb6bushouname[iBushouID].position = 6; // 身分を足軽とする。

					nb6bushou[iBushouID].attach = 0xFFFF; // 大名に所属しない。
					nb6bushou[iBushouID].gundan = 0xFFFF; // 軍団に所属しない。
					nb6bushou[iBushouID].loyal = 50; // 忠誠を50とする。
					nb6bushou[iBushouID].work = 0; // 仕官年数を0とする。

					nb6bushou[iBushouID].rise = 0xFFFF; // 内応先をなしとする。
					nb6bushou[iBushouID].bRise = 0; // 内応なし。

					nb6bushou[iBushouID].soldier = 0; // 兵数を0とする。
					nb6bushou[iBushouID].training = 0; // 訓練を0とする。
					nb6bushou[iBushouID].solloyal = 0; // 兵忠を0とする。
					nb6bushou[iBushouID].form = 0; // 足軽隊とする。

					nb6bushou[iBushouID].merits = 0; // 勲功を0とする。
				}

				/* 　自分
				↓
				○-●-○-○

				というのを

				○-○-○

				とする。
				*/


				// 浪人にしたい武将は、いま城主だ
				if (nb6castle[iCastleID].master - 1 == iBushouID) {
					nb6castle[iCastleID].master = nb6bushou[iBushouID].next; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// 自分が城主ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// 自分ではなく、次の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// 自分のnextは有効な武将だ。
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// １つ後の人の前のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// 自分ではなく、前の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}


				/* 　

				○-○

				というのを

				●-○-○

				とする。
				*/

				// 浪人としてみなした時、自分のnextは、現在浪人リストの先頭の人
				nb6bushou[iBushouID].next = nb6castle[iCastleID].ronin; // 現在の先頭の人を自分の次の人に

																		// nextが有効な武将ならば…
				if (0 < nb6castle[iCastleID].ronin && nb6castle[iCastleID].ronin <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// 次の人のprevを自分に
					nb6bushou[nb6castle[iCastleID].ronin - 1].prev = iBushouID + 1;

				}
				nb6bushou[iBushouID].prev = 0xFFFF; // prevは居ない

				nb6castle[iCastleID].ronin = iBushouID + 1; // 城の浪人の先頭を自分にする。

				return true;

			}
		}
	}

	return false;
}


// State 浪人 → State 現役へ
bool setRouninToGeneki(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		if (nb6bushouname[iBushouID].State == 4) { // 浪人武将の場合だけ処理をする。
												   // 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = nb6bushou[iBushouID].castle - 1;
			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {

				if (nb6castle[iCastleID].ronin == 0xFFFF) { return false; } // リンクリストが壊れているのか浪人が誰も居ないことになっちゃってる。何もしない。return;
				if (nb6castle[iCastleID].attach == 0xFFFF) { return false; } // 該当の城がどこの軍団にも所属していない場合、浪人を現役とは出来ない。
																			 // なぜなら、それは大名化することを意味するから。
				int iAttachGundanID = nb6castle[iCastleID].attach - 1;
				int iAttachDaimyoID = -1;
				if (0 <= iAttachGundanID && iAttachGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
					iAttachDaimyoID = nb6gundan[iAttachGundanID].attach - 1;
				}
				else {
					return false;
				}
				if (!(0 <= iAttachDaimyoID && iAttachDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM)) {
					return false;
				}

				// 現在の城の城主から、リンクリストを辿っていく
				int iLinkEndBusyouID = nb6castle[iCastleID].master;
				int iSafetyCnt = 0;
				while (true) {
					// セーフティカウントが暴走している。
					if (iSafetyCnt > GAMEDATASTRUCT_BUSHOU_NUM) {
						return false;
					}

					// 城主が居ないならば、終わり
					if (iLinkEndBusyouID == 0xFFFF) {
						break;
					}

					// 現在の武将の、nextが有効ではなければ、現在の武将が最後の人。終わり。
					if (nb6bushou[iLinkEndBusyouID - 1].next == 0xFFFF) {
						break;

						// 現在の人が有効である。
					}
					else {
						// リンクリストを次の人とする。
						if (0 < iLinkEndBusyouID && iLinkEndBusyouID <= GAMEDATASTRUCT_BUSHOU_NUM) {
							iLinkEndBusyouID = nb6bushou[iLinkEndBusyouID - 1].next;
						}
					}
				}

				// メモリ上の値変更
				{
					nb6bushouname[iBushouID].State = 2; // 状態を現役とする。

					nb6bushou[iBushouID].attach = iAttachDaimyoID + 1; // 大名に所属する。
					nb6bushou[iBushouID].gundan = iAttachGundanID + 1; // 軍団に所属する。
					nb6bushou[iBushouID].loyal = 50; // 忠誠を50とする。

					nb6bushou[iBushouID].rise = 0xFFFF; // 内応先をなしとする。
					nb6bushou[iBushouID].bRise = 0; // 内応なし。

					nb6bushou[iBushouID].soldier = 0; // 兵数を0とする。
					nb6bushou[iBushouID].training = 0; // 訓練を0とする。
					nb6bushou[iBushouID].solloyal = 0; // 兵忠を0とする。
					nb6bushou[iBushouID].form = 0; // 足軽隊とする。

					nb6bushouname[iBushouID].position = 6; // 身分を足軽とする。
					//------------------------------------------------------
				}

				/* 　自分
				↓
				○-●-○-○

				というのを

				○-○-○

				とする。
				*/


				// 現役にしたい武将は、いま先頭だ
				if (nb6castle[iCastleID].ronin - 1 == iBushouID) {
					nb6castle[iCastleID].ronin = nb6bushou[iBushouID].next; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// 自分が先頭ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// 自分ではなく、次の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// 自分のnextは有効な武将だ。
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// １つ後の人の前のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// 自分ではなく、前の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}


				/* 　

				○-○

				というのを

				○-○-●

				とする。
				*/


				// 自分は現役として一番最後にくっつく。自分のnextは居ない
				nb6bushou[iBushouID].next = 0xFFFF;

				// もし自分は、現役になるとともに、城主にもなるべきならば…
				if (iLinkEndBusyouID == 0xFFFF) {
					nb6bushou[iBushouID].prev = 0xFFFF; // 自分の前の人は居ない

					nb6castle[iCastleID].master = iBushouID + 1; // 城主は自分

																 // 武将リンクリストの一番最後にぶら下がるべき。
				}
				else {

					nb6bushou[iLinkEndBusyouID - 1].next = iBushouID + 1; // リンクリストの最後のnextを自分に

					nb6bushou[iBushouID].prev = iLinkEndBusyouID; // 自分の前の人は、城のリンクリストの最後の人物
				}
				return true;

			}
		}
	}

	return false;
}


bool _setBushouTransportRonin(int iBushouID, int iNewCastleID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		if (nb6bushouname[iBushouID].State == 4) { // 浪人武将の場合だけ処理をする。
												   // 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = nb6bushou[iBushouID].castle - 1;

			if (iCastleID == iNewCastleID) { return true; } // 引っ越し先が同じだったら何もする必要はなく成功したとみなす。

			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {

				if (nb6castle[iCastleID].ronin == 0xFFFF) { return false; } // リンクリストが壊れているのか浪人が誰も居ないことになっちゃってる。何もしない。return;

																			// メモリ上の値変更
				{
					// 所属居城を転送先に変更する。
					nb6bushou[iBushouID].castle = iNewCastleID + 1;
				}

				/* 　自分
				↓
				○-●-○-○

				というのを

				○-○-○

				とする。
				*/


				// 転送したい武将は、いま先頭だ
				if (nb6castle[iCastleID].ronin - 1 == iBushouID) {
					nb6castle[iCastleID].ronin = nb6bushou[iBushouID].next; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// 自分が先頭ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// 自分ではなく、次の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// 自分のnextは有効な武将だ。
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// １つ後の人の前のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// 自分ではなく、前の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}

				/* 　

				○-○

				というのを

				●-○-○

				とする。
				*/

				// 浪人としてみなした時、自分のnextは、現在浪人リストの先頭の人
				nb6bushou[iBushouID].next = nb6castle[iNewCastleID].ronin; // 転送先の現在の先頭の人を自分の次の人に

																		   // nextが有効な武将ならば…
				if (0 < nb6castle[iNewCastleID].ronin && nb6castle[iNewCastleID].ronin <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// 次の人のprevを自分に
					nb6bushou[nb6castle[iNewCastleID].ronin - 1].prev = iBushouID + 1;
				}
				nb6bushou[iBushouID].prev = 0xFFFF; // prevは居ない

				nb6castle[iNewCastleID].ronin = iBushouID + 1; // 城の浪人の先頭を自分にする。

				return true;
			}
		}
	}

	return false;
}


bool setBushouTransport(int iBushouID, int iNewCastleID) {

	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 今の居城と新しい居城
		int iCastleID = nb6bushou[iBushouID].castle - 1;
		if (iCastleID == iNewCastleID) { return true; } // 今居る場所と、転居先が同じなら何もする必要はない。

														// 浪人の場合は移転するだけ
		if (nb6bushouname[iBushouID].State == 4) { // 浪人武将の場合だけ処理をする。
			return _setBushouTransportRonin(iBushouID, iNewCastleID);

			// 現役の場合は、浪人化してから、移転して、また(可能であれば)現役に戻す。
			// 未統治城だと浪人のまま移転することとなる。
		}
		else if (nb6bushouname[iBushouID].State == 2) { // 現役武将である
			int _merits = nb6bushou[iBushouID].merits;
			int _work = nb6bushou[iBushouID].work;
			int _position = nb6bushouname[iBushouID].position;
			int _loyal = nb6bushou[iBushouID].loyal;
			int _soldier = nb6bushou[iBushouID].soldier;
			int _training = nb6bushou[iBushouID].training;
			int _solloyal = nb6bushou[iBushouID].solloyal;
			int _form = nb6bushou[iBushouID].form;
			int _attach = nb6bushou[iBushouID].attach;
			int _rise = nb6bushou[iBushouID].rise;
			int _bRise = nb6bushou[iBushouID].bRise;

			// 一端、浪人にして
			bool isRouninka = setGenekiToRounin(iBushouID);
			if (!isRouninka) { return false; }

			// 位置移動
			bool isTranska = _setBushouTransportRonin(iBushouID, iNewCastleID);
			if (!isTranska) { return false; }

			bool isGenekika = setRouninToGeneki(iBushouID);
			// 現役にできなかったらそのまま浪人として終わる。(未支配城とかだと、そのまま浪人のままとなる。)
			if (!isGenekika) { return false; }

			// 元々現役なので、浪人化する前の値で復元するものを戻す。
			nb6bushou[iBushouID].merits = _merits; // 勲功
			nb6bushouname[iBushouID].position = _position; // 身分
			nb6bushou[iBushouID].loyal = _loyal; // 忠誠
			nb6bushou[iBushouID].soldier = _soldier; // 兵数
			nb6bushou[iBushouID].training = _training; // 訓練
			nb6bushou[iBushouID].solloyal = _solloyal; // 士気
			nb6bushou[iBushouID].form = _form; // 兵態

											   // 転居前と転居後で大名が変化していない場合のみ、士官年数や内応系も元の値を復元
			if (_attach == nb6bushou[iBushouID].attach) {
				nb6bushou[iBushouID].work = _work; // 仕官年数
				nb6bushou[iBushouID].rise = _rise; // 内応先
				nb6bushou[iBushouID].bRise = _bRise; // 内応状態
			}
			else {
				nb6bushou[iBushouID].grudge = 0; // 大名が変わった場合、恨みは消す
			}

		}
	}
	return false;
}


// 現役をその城の城主とする。
// 特定の「現役」の武将を、その城の城主にする。
// 元の城主が「軍団長」や「大名」だと、その人物の立場となる。
bool setGenekiToJyosyu(int iBushouID) {

	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		//0大名,1軍長,2現役
		if (nb6bushouname[iBushouID].State == 2) { // 現役武将の場合だけ処理をする。

												   // 該当武将の居城がちゃんとした情報が格納されている。(ユーザー改造等によって壊れていない)
			int iCastleID = nb6bushou[iBushouID].castle - 1;

			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {

				if (nb6castle[iCastleID].master == 0xFFFF) { return false; } // リンクリストが壊れているのか城に誰も所属していない。何もしない。return;

																			 // ここまで来たら城主が居るので…
				int iJyosyuBushouID = nb6castle[iCastleID].master - 1;

				// 指定武将がすでに城主なら何もしなくても城主である。
				if (iBushouID == iJyosyuBushouID) { return true; }

				// 城主は居るが(改造等で)おかしな破たんデータになっていたら、何もしない。
				if (!(0 <= iJyosyuBushouID && iJyosyuBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
					return false;
				}

				//0大名,1軍長,2現役

				// 城主が現役でも軍団長でもないならば(大名)、何もしない。入れ替えると変なことになる。
				// 現役ならば
				if (nb6bushouname[iJyosyuBushouID].State == 2) {

					; // 特に何もしない
					  // 軍団長ならば
				}
				else if (nb6bushouname[iJyosyuBushouID].State == 1) {
					// 今の軍団長を現役とする
					nb6bushouname[iJyosyuBushouID].State = 2; // 現役とする

															  // 逆に指定武将を軍団長化する
					nb6bushouname[iBushouID].State = 1; // 軍団長
					int iGundanID = nb6bushou[iJyosyuBushouID].gundan - 1;
					// 決して要らぬ判定のはずであるが一応
					if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
						// 軍団情報の軍団長の番号を、指定の武将にする。
						nb6gundan[iGundanID].leader = iBushouID + 1;
					}
					// 大名ならば…
				}
				else if (nb6bushouname[iJyosyuBushouID].State == 0) {
					// 今の大名を現役とする
					nb6bushouname[iJyosyuBushouID].State = 2;
					// 大名だった人の身分を宿老とする。
					nb6bushouname[iJyosyuBushouID].position = 2; //(隠居=0, 大名=1, 宿老=2, 家老=3, 部将=4, 侍大将=5, 足軽頭=6)
																 // 逆に指定武将を大名とする
					nb6bushouname[iBushouID].State = 0;
					nb6bushouname[iBushouID].position = 1;

					int iGundanID = nb6bushou[iJyosyuBushouID].gundan - 1;
					int iDaimyoID = nb6bushou[iJyosyuBushouID].attach - 1;
					// 決して要らぬ判定のはずであるが一応
					if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
						// 軍団情報の軍団長の番号を、指定の武将にする。
						nb6gundan[iGundanID].leader = iBushouID + 1;
					}
					if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
						// nb6daimyoの大名の番号を、指定の武将にする。
						nb6daimyo[iDaimyoID].attach = iBushouID + 1;
					}

				}
				else {
					return false;
				}




				/*城情報の武将リスト

				　 　自分
				   ↓
				   ○-●-○-○

				   というのを

				   ○-○-○

				   とする。
				   */


				   // パージしたい武将は、いま城主だ
				if (nb6castle[iCastleID].master - 1 == iBushouID) {
					nb6castle[iCastleID].master = nb6bushou[iBushouID].next; // 自分のnextを城主にする。
				}

				// 自分のprevは有効な武将だ。
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// 自分が城主ではない武将で、
					// １つ前の人の次のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// 自分ではなく、次の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// 自分のnextは有効な武将だ。
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// １つ後の人の前のリンク先が自分自身の場合
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// 自分ではなく、前の人へと繋ぎかえる。
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}



				/* 城情報の城主リスト　

				○-○

				というのを

				●-○-○

				とする。
				*/

				// 自分が城主となるので、自分の次の人を、今の城主の人とする。
				int iJosyu = nb6castle[iCastleID].master;
				nb6bushou[iBushouID].next = iJosyu; // 現在の先頭の人を自分の次の人に

													// nextが有効な武将ならば…
				if (0 < iJosyu && iJosyu <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// 次の人のprevを自分に
					nb6bushou[iJosyu - 1].prev = iBushouID + 1;
				}

				nb6bushou[iBushouID].prev = 0xFFFF; // 本人が先頭になるので、prevは居ない

													// そして最後に自分を城主に
				nb6castle[iCastleID].master = iBushouID + 1; // 城の城主を自分にする。

				return true;
			}
		}
	}

	return false;
}



// 相性の輪配列。(計算用)
static int arrayAisho[32] = { 8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7 };

// A武将とB武将の相性の差分を得る
// 最小0(相性最高) 最大8(相性最悪)
static int getAishoDiff(int iAishoA, int iAishoB) {

	// まず、A武将の相性位置を中央から取る
	int iAAishoIXInArray = 0;
	for (int iAishoID = 8; iAishoID<8 + GAMEDATASTRUCT_AISHOU_NUM; iAishoID++) {
		// Aの相性値を見つけたら、そこがAの位置
		if (arrayAisho[iAishoID] == iAishoA) {
			iAAishoIXInArray = iAishoID;
		}
	}

	// 不正な数字の場合は、相性差は最も悪いものとする。
	if (iAAishoIXInArray == 0) { return 8; }

	// B武将の相性位置はA武将の-8からスタート
	int iBAishoIXInArray = 0;
	for (int iAishoID = iAAishoIXInArray - 8; iAishoID<iAAishoIXInArray + 8; iAishoID++) {
		// Aの相性値を見つけたら、そこがAの位置
		if (arrayAisho[iAishoID] == iAishoB) {
			iBAishoIXInArray = iAishoID;
		}
	}

	// 不正な数字の場合は、相性差は最も悪いものとする。
	if (iBAishoIXInArray == 0) { return 8; }

	// ２つの相性の位置の差分が相性差
	return abs(iBAishoIXInArray - iAAishoIXInArray);
}


/*
* 2人の武将IDから相性の違いを得る。
* 最小0(相性最高) 最大8(相性最悪)
*/
int getBushouAishoDiff(int iBushouAID, int iBushouBID) {
	// 武将Aも武将Bも範囲内に収まっている
	if (0 <= iBushouAID && iBushouAID < GAMEDATASTRUCT_BUSHOU_NUM && 0 <= iBushouBID && iBushouBID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// 武将の相性の差を返す
		return getAishoDiff(nb6bushou[iBushouAID].affinity, nb6bushou[iBushouBID].affinity);
	}
	// 一番悪い値を返しておく
	else {
		return 8;
	}
}






