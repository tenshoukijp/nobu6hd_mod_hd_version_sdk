#include "GameDataStruct.h"

#include "GameDataStructBushouRelation.h"








/*
【口調】:
0 無口			 217 真田幸村・長宗我部元親・島津義久・忍者全員
1 礼儀正しい	 152 前田利家・明智光秀・立花宗茂・徳川光圀
2 粗暴			 119 柴田勝家・龍造寺隆信・可児才蔵・佐々木小次郎
3 高貴			 30 上杉憲政・今川義元・足利義晴・一条兼定
4 生意気		 180 伊達政宗・三好長慶・鈴木重秀・由比正雪
5 威厳			 143 織田信長・徳川家康・武田信玄・上杉謙信
6 饒舌			 145 豊臣秀吉・斎藤道三・松永久秀・足利義昭
7 一般			 314 本多忠勝・吉川元春・山中鹿之助・史実姫全員
*/


String^ ％自名％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID = 0xFFFF);


// 00（相手に敬意を払う必要がない場合の自称） 
String^ ％わし％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	// 家族の場合を先に判定する。
	String^ szIsFamilyMsg = ％自名％(i1st_BushouID, i2nd_BushouID, i3rd_BushouID);

	if (szIsFamilyMsg->Length > 0) {
		return szIsFamilyMsg;
	}

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わらわ 自女&自齢>35 
		if (nb6bushouname[i1st_BushouID].sex == 1 && getYearsOld(i1st_BushouID) > 35) {
			return "わらわ";

			// わたくし 自女  
		}
		else if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わたくし";

			// まろ 自口=3 
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "まろ";

			// わし 自身=0or1 and 自齢>35  (0==隠居, 1==大名)
		}
		else if ((nb6bushouname[i1st_BushouID].position == 0 || nb6bushouname[i1st_BushouID].position == 1) && getYearsOld(i1st_BushouID) > 35) {
			return "わし";

			// 俺 自口=2or4
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
			return "俺";

			// 私 自口=1 
		}
		else if (nb6bushou[i1st_BushouID].tone == 1) {
			return "私";

			// わし （他） 
		}
		else {
			return "わし";

		}
	}
	return "％わし％";
}



// 01（相手と親子・兄弟・夫婦にある場合の自称）
// 他のヘルパーなので、直接使わないこと!!
String^ ％自名％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 娘 相自親子&自齢<相齢&自女 
		if (is自分は相手の娘(i1st_BushouID, i2nd_BushouID)) {
			return "娘";

			// 父 自相親子&自齢>相齢&自男 
		}
		else if (is自分は相手の父(i1st_BushouID, i2nd_BushouID)) {
			return "父";

			// 母 自相親子&自齢>相齢&自女 
		}
		else if (is自分は相手の母(i1st_BushouID, i2nd_BushouID)) {
			return "母";

			// 弟 自相兄弟&自齢<相齢&自男 
		}
		else if (is自分は相手の弟(i1st_BushouID, i2nd_BushouID)) {
			return "弟";

			// 妹 自相兄弟&自齢<相齢&自女 
		}
		else if (is自分は相手の妹(i1st_BushouID, i2nd_BushouID)) {
			return "妹";

			// 兄 自相兄弟&自齢>相齢&自男
		}
		else if (is自分は相手の兄(i1st_BushouID, i2nd_BushouID)) {
			return "兄";

			// 姉 自相兄弟&自齢>相齢&自女
		}
		else if (is自分は相手の姉(i1st_BushouID, i2nd_BushouID)) {
			return "姉";

			// 夫 自相夫婦&自男
		}
		else if (is自分は相手の夫(i1st_BushouID, i2nd_BushouID)) {
			return "夫";

			// 妻 相自婦夫&自女
		}
		else if (is自分は相手の妻(i1st_BushouID, i2nd_BushouID)) {
			return "妻";
		}

	}
	return "";
}



// 02（その他の場合の自称） 
String^ ％私％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	// 家族の場合を先に判定する。
	String^ szIsFamilyMsg = ％自名％(i1st_BushouID, i2nd_BushouID, i3rd_BushouID);

	if (szIsFamilyMsg->Length > 0) {
		return szIsFamilyMsg;
	}

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わたくし 自女  
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わたくし";

			// まろ 自相血縁&自口=3 
		}
		else if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && nb6bushou[i1st_BushouID].tone == 3) {
			return "まろ";

			// わし 自相血縁&自齢>相齢&自齢>35
		}
		else if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) && getYearsOld(i1st_BushouID) > 35) {
			return "わし";

			// わし 自身=(0or1)&自齢>35  (0==隠居, 1==大名)
		}
		else if ((nb6bushouname[i1st_BushouID].position == 0 || nb6bushouname[i1st_BushouID].position == 1) && getYearsOld(i1st_BushouID) > 35) {
			return "わし";

			// 拙者 自職=1or3 (忍者か剣豪)
		}
		else if (nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
			return "拙者";

			// 拙僧 自職=4 (僧侶)
		}
		else if (nb6bushou[i1st_BushouID].job == 0x40) {
			return "拙僧";

			// 俺 自口=2
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "俺";

			// それがし 自口=5
		}
		else if (nb6bushou[i1st_BushouID].tone == 5) {
			return "それがし";

			// 私 （他） 
		}
		else {
			return "私";

		}
	}
	return "％私％";
}


// 03（所有形容詞）  
String^ ％我が％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// 私の 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "私の";
		}
		else {
			return "我が";
		}
	}
	return "％我が％";
}


// 04～07 相手をさげすむ場合「以外」の二人称
String^ ％相手％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		/*
		* 04（相手と血縁関係にある場合の二人称）
		*/
		// 自相親子&自齢<相齢&相男
		if (is相手は自分の父(i1st_BushouID, i2nd_BushouID)) {
			return "父上";

			// 自相親子&自齢<相齢&相女
		}
		else if (is相手は自分の母(i1st_BushouID, i2nd_BushouID)) {
			return "母上";

			// 兄上 自相兄弟&自齢<相齢&相男 
		}
		else if (is相手は自分の兄(i1st_BushouID, i2nd_BushouID)) {
			return "兄上";

			// 姉上 自相兄弟&自齢<相齢&相女 
		}
		else if (is相手は自分の姉(i1st_BushouID, i2nd_BushouID)) {
			return "姉上";

			// あなた 自相夫婦&相男 
		}
		else if (is自分は相手の妻(i1st_BushouID, i2nd_BushouID)) {
			return "あなた";

			// (相名) 自相親子&自齢>相齢 (自分は相手の親である)
		}
		else if (is自分は相手の親(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (相名)殿 自相血縁&相=大名
		}
		else if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i2nd_BushouID].State == 0) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "殿";

			// (相名) 自相兄弟&自齢>相齢&相≠大名
		}
		else if (is自分は相手の兄(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i2nd_BushouID].State != 0) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (相名) 自相夫婦&相女 
		}
		else if (is自分は相手の夫(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (相名)殿 自相血縁
		}
		else if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "殿";

			/*
			*	05（自分が大名で相手がその家臣の場合の二人称）
			*/
			// ご隠居 自=大名&相身=0 
		}
		else if (is相手は自分の家臣(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i2nd_BushouID].position == 0) {
			return "ご隠居";

			// じい 自齢<相仕&自齢≦30&相齢≧50&相男
		}
		else if (is相手は自分の家臣(i1st_BushouID, i2nd_BushouID) &&
			(getYearsOld(i1st_BushouID) < nb6bushou[i2nd_BushouID].work) && getYearsOld(i1st_BushouID) <= 30 &&
			getYearsOld(i2nd_BushouID) >= 50 && nb6bushouname[i2nd_BushouID].sex == 0) {
			return "じい";
			// 猿 自=織田信長(=顔0)&相=豊臣秀吉(=顔5) 
		}
		else if (is相手は自分の家臣(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i1st_BushouID].number == 0 && nb6bushouname[i2nd_BushouID].number == 5) {
			return "猿";

			// (相名) （他） 
		}
		else if (is相手は自分の家臣(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			/*
			*	06（相手が自分の大名の場合の二人称）
			*/
			// 若 相齢<自仕&相齢≦30&自齢≧50&相男 
		}
		else if (is相手は自分の大名(i1st_BushouID, i2nd_BushouID) &&
			(getYearsOld(i2nd_BushouID) < nb6bushou[i1st_BushouID].work) && getYearsOld(i2nd_BushouID) <= 30 &&
			getYearsOld(i1st_BushouID) >= 50 && nb6bushouname[i2nd_BushouID].sex == 0) {
			return "若";

			// お館様 自口≠3&33%
		}
		else if (is相手は自分の大名(i1st_BushouID, i2nd_BushouID) && nb6bushou[i1st_BushouID].tone != 3 && rand() % 3 == 0) {
			return "お館様";

			// (相名)様 （他） 
		}
		else if (is相手は自分の大名(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "様";

			/*
			*	07（その他の場合の二人称）
			*/
			// (相名)殿 相身=1&自身=1 (1==大名)
		}
		else if (nb6bushouname[i2nd_BushouID].position == 1 && nb6bushouname[i1st_BushouID].position == 1) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "殿";

			// (相名)様 相身=1&自身≠1 
		}
		else if (nb6bushouname[i2nd_BushouID].position == 1 && nb6bushouname[i1st_BushouID].position != 1) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "様";

			// ご隠居 相身=0 
		}
		else if (nb6bushouname[i2nd_BushouID].position == 0) {
			return "ご隠居";

			// (相名) 自身≧相身(内部番号的には自身≦相身)&自齢≧相齢&自属=相属  (身分=0:隠居 1:大名 2:宿老 3:家老 …なので、番号が小さい方が強い)
		}
		else if (nb6bushouname[i1st_BushouID].position <= nb6bushouname[i2nd_BushouID].position &&
			getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID) && is自分と相手は同じ大名家所属(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (相姓)様 自身>相身+1(3階級自分が下の身分ということ)&自口≠4 
		}
		else if (nb6bushouname[i1st_BushouID].position > nb6bushouname[i2nd_BushouID].position + 1 &&
			nb6bushou[i1st_BushouID].tone != 4) {
			return gcnew String(nb6bushouname[i2nd_BushouID].familyname) + "様";

			// (相名)様 相女 
		}
		else if (nb6bushouname[i2nd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "様";

			// (相名)殿 （他） 
		}
		else {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "殿";
		}

	}
	return "％相手％";
}


// 08 相手をさげすむ場合の二人称
String^ ％罵倒相手％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// 小わっぱ 相男&相齢<18&自齢-相齢>5 
		if (nb6bushouname[i2nd_BushouID].sex == 0 && getYearsOld(i2nd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i2nd_BushouID) > 5) {
			return "小わっぱ";

			// 小娘 相女&相齢<18&自齢-相齢>5 
		}
		else if (nb6bushouname[i2nd_BushouID].sex == 1 && getYearsOld(i2nd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i2nd_BushouID) > 5) {
			return "小娘";

			// 青二才 相齢<30&自齢-相齢>20 
		}
		else if (getYearsOld(i2nd_BushouID) < 30 && getYearsOld(i1st_BushouID) - getYearsOld(i2nd_BushouID) > 20) {
			return "青二才";

			// 老いぼれ 相齢>60&相齢-自齢>20 
		}
		else if (getYearsOld(i2nd_BushouID) > 60 && getYearsOld(i2nd_BushouID) - getYearsOld(i1st_BushouID) > 20) {
			return "老いぼれ";

			// くそ坊主
		}
		else if (nb6bushou[i2nd_BushouID].job == 0x40) {
			return "くそ坊主";

			// えせ茶人
		}
		else if (nb6bushou[i2nd_BushouID].job == 0x20) {
			return "えせ茶人";

			// 伴天連
		}
		else if (nb6bushou[i2nd_BushouID].job != 0x90 && nb6bushou[i2nd_BushouID].job == 0x90) {
			return "伴天連";

		}
		else {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);
		}
	}
	return "％罵倒相手％";
}


// 09～0D 三名をさげすむ場合「以外」の三人称
String^ ％三名％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i3rd_BushouID && i3rd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		/*
		* 0A09（大名が血縁関係にある武将を指す場合の三人称）
		*/
		// 父上 自三親子&自齢<三齢&三男 (1==大名)
		if (nb6bushouname[i1st_BushouID].position == 1 && is相手は自分の父(i1st_BushouID, i3rd_BushouID)) {
			return "父上";

			// 母上 自三親子&自齢<三齢&三女
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is相手は自分の母(i1st_BushouID, i3rd_BushouID)) {
			return "母上";

			// 兄上 自三兄弟&自齢<三齢&三男
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is相手は自分の兄(i1st_BushouID, i3rd_BushouID)) {
			return "兄上";

			// 姉上 自三兄弟&自齢<三齢&三女
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is相手は自分の姉(i1st_BushouID, i3rd_BushouID)) {
			return "姉上";

			// 姉上 自三兄弟&自齢<三齢&三女
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is自分は相手の血縁(i1st_BushouID, i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (三名殿) 血縁関係
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is自分は相手の血縁(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "殿";

			// ご隠居 三身=0 
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && nb6bushouname[i3rd_BushouID].position == 0) {
			return "ご隠居";

			/*
			* 0A（血縁・夫婦関係にある大名を指す場合の三人称）
			*/
			// 父 自三親子&自齢<三齢&三男
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is相手は自分の父(i1st_BushouID, i3rd_BushouID)) {
			return "父";

			// 母 自三親子&自齢<三齢&三女
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is相手は自分の母(i1st_BushouID, i3rd_BushouID)) {
			return "母";

			// 兄 自三兄弟&自齢<三齢&三男
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is相手は自分の兄(i1st_BushouID, i3rd_BushouID)) {
			return "兄";

			// 姉 自三兄弟&自齢<三齢&三女
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is相手は自分の姉(i1st_BushouID, i3rd_BushouID)) {
			return "姉";

			// 弟 自三兄弟&自齢>三齢&三男
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is相手は自分の弟(i1st_BushouID, i3rd_BushouID)) {
			return "弟";

			// 妹 自三兄弟&自齢>三齢&三女
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is相手は自分の妹(i1st_BushouID, i3rd_BushouID)) {
			return "妹";

			// 家内 自三夫婦&相女
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is自分は相手の夫(i1st_BushouID, i3rd_BushouID)) {
			return "家内";

			// 夫 自三夫婦&相男
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is自分は相手の妻(i1st_BushouID, i3rd_BushouID)) {
			return "夫";

			// (三名) 自三血縁&自齢>相齢&三女 
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is自分は相手の血縁(i1st_BushouID, i3rd_BushouID) && getYearsOld(i1st_BushouID) > getYearsOld(i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (三名殿) 血縁関係
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is自分は相手の血縁(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "殿";

			/*
			* 0B（自分が大名であり、血縁関係ではない場合の三人称）
			*/
			// じい 自齢<三仕&自齢≦30&三齢≧50&？&三男 
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 &&
			(getYearsOld(i1st_BushouID) < nb6bushou[i3rd_BushouID].work) && getYearsOld(i1st_BushouID) <= 30 &&
			getYearsOld(i3rd_BushouID) >= 50 && nb6bushouname[i3rd_BushouID].sex == 0) {
			return "じい";

			// (三名) 自三血縁&自齢>相齢&三女 
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && nb6bushouname[i3rd_BushouID].position == 1 && getYearsOld(i1st_BushouID) > getYearsOld(i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (三名殿) 血縁関係
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && nb6bushouname[i3rd_BushouID].position == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "殿";

			/*
			*	0C（相手が自分の大名の場合の三人称）
			*/
			// 若 相齢<自仕&相齢≦30&自齢≧50&相男 
		}
		else if (is相手は自分の大名(i1st_BushouID, i3rd_BushouID) &&
			(getYearsOld(i3rd_BushouID) < nb6bushou[i1st_BushouID].work) && getYearsOld(i3rd_BushouID) <= 30 &&
			getYearsOld(i1st_BushouID) >= 50 && nb6bushouname[i3rd_BushouID].sex == 0) {
			return "若";

			// お館様 33%
		}
		else if (is相手は自分の大名(i1st_BushouID, i3rd_BushouID) && rand() % 3 == 0) {
			return "お館様";

			// (相名)様 （他） 
		}
		else if (is相手は自分の大名(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "様";

			/*
			* 0D（その他の場合の三人称）
			*/
			// 父 自三親子&自齢<三齢&三男
		}
		else if (is相手は自分の父(i1st_BushouID, i3rd_BushouID)) {
			return "父";

			// 母 自三親子&自齢<三齢&三女
		}
		else if (is相手は自分の母(i1st_BushouID, i3rd_BushouID)) {
			return "母";

			// 兄 自三兄弟&自齢<三齢&三男
		}
		else if (is相手は自分の兄(i1st_BushouID, i3rd_BushouID)) {
			return "兄";

			// 姉 自三兄弟&自齢<三齢&三女
		}
		else if (is相手は自分の姉(i1st_BushouID, i3rd_BushouID)) {
			return "姉";

			// 弟 自三兄弟&自齢>三齢&三男
		}
		else if (is相手は自分の弟(i1st_BushouID, i3rd_BushouID)) {
			return "弟";

			// 妹 自三兄弟&自齢>三齢&三女
		}
		else if (is相手は自分の妹(i1st_BushouID, i3rd_BushouID)) {
			return "妹";

			// 家内 自三夫婦&相女
		}
		else if (is自分は相手の夫(i1st_BushouID, i3rd_BushouID)) {
			return "家内";

			// 夫 自三夫婦&相男
		}
		else if (is自分は相手の妻(i1st_BushouID, i3rd_BushouID)) {
			return "夫";

			// (三名) 自三血縁&自齢>相齢&三女 
		}
		else if (is自分は相手の血縁(i1st_BushouID, i3rd_BushouID) && getYearsOld(i1st_BushouID) > getYearsOld(i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (三名殿) 血縁関係
		}
		else if (is自分は相手の血縁(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "殿";

			// (三名) 自身≧三身(内部番号的には自身≦三身)&自齢≧三齢&自属=三属  (身分=0:隠居 1:大名 2:宿老 3:家老 …なので、番号が小さい方が強い)
		}
		else if (nb6bushouname[i1st_BushouID].position <= nb6bushouname[i3rd_BushouID].position &&
			getYearsOld(i3rd_BushouID) >= getYearsOld(i3rd_BushouID) && is自分と相手は同じ大名家所属(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (三姓)様 自身>三身+1(3階級自分が下の身分ということ)&自口≠4 
		}
		else if (nb6bushouname[i1st_BushouID].position > nb6bushouname[i3rd_BushouID].position + 1 &&
			nb6bushou[i1st_BushouID].tone != 4) {
			return gcnew String(nb6bushouname[i3rd_BushouID].familyname) + "様";

			// (三名)様 三女 
		}
		else if (nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String( nb6bushouname[i3rd_BushouID].fastname) + "様";

			// (相名)殿 （他） 
		}
		else {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "殿";
		}

	}
	return "％三名％";
}




// 0E（第三者をさげすむ場合の三人称） 
String^ ％罵倒三名％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i3rd_BushouID && i3rd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// 小わっぱ 三男&三齢<18&自齢-三齢>5 
		if (nb6bushouname[i3rd_BushouID].sex == 0 && getYearsOld(i3rd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i3rd_BushouID) > 5) {
			return "小わっぱ";

			// 小娘 三女&三齢<18&自齢-三齢>5 
		}
		else if (nb6bushouname[i3rd_BushouID].sex == 1 && getYearsOld(i3rd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i3rd_BushouID) > 5) {
			return "小娘";

			// 青二才 三齢<30&自齢-三齢>20 
		}
		else if (getYearsOld(i3rd_BushouID) < 30 && getYearsOld(i1st_BushouID) - getYearsOld(i3rd_BushouID) > 20) {
			return "青二才";

			// 老いぼれ 三齢>60&三齢-自齢>20 
		}
		else if (getYearsOld(i3rd_BushouID) > 60 && getYearsOld(i3rd_BushouID) - getYearsOld(i1st_BushouID) > 20) {
			return "老いぼれ";

			// (三名) （他） 
		}
		else {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);
		}
	}
	return "％罵倒三名％";
}

























bool ％略記条件１％(int i1st_BushouID, int i2nd_BushouID) {

	// 自分が下、ということ。
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 自身>相身 (自分の身分の方が下ということ)
		if (nb6bushouname[i1st_BushouID].position > nb6bushouname[i2nd_BushouID].position) {
			return true;
		}
	}
	return false;
}

bool ％略記条件２％(int i1st_BushouID, int i2nd_BushouID) {

	// 血縁関係や、同じ釜の飯だが、自分が上、ということ。
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 自相血縁&自齢≧相齢 
		if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID)) {
			return true;
		}
		// 相手は自分の家臣
		if (is相手は自分の家臣(i1st_BushouID, i2nd_BushouID)) {
			return true;
		}
		// 同じ家に所属している & 自齢≧相齢 & 自身<相身(自分の方が身分が高い)
		if (is自分と相手は同じ大名家所属(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].position < nb6bushouname[i2nd_BushouID].position) {
			return true;
		}
	}
	return false;
}

int ％略記条件Ｔ％(int i1st_BushouID, int i2nd_BushouID) {
	// 相手の武将がいないのであれば、1となる。
	if (i2nd_BushouID == 0xFFFF) {
		return 1;
	}

	// 略記条件２を満たす。(同じ釜の飯でかつ、自分が上)
	else if (％略記条件２％(i1st_BushouID, i2nd_BushouID)) {
		return 1;
	}
	// 略記条件１を満たす。(自分が下)
	else if (％略記条件１％(i1st_BushouID, i2nd_BushouID)) {
		return 2;
	}
	// 略記条件１も略記条件２も満たさない(自分の方が身分は上)
	else {
		// それ以外
		return 3;
	}
}



// ～です ～だ ～じゃ
String^ ％です％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// です 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "です";

				// だ 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "だ";

				// じゃ （他） 
			}
			else {
				return "じゃ";
			}

			// Group B
		}
		else {
			// です （他） 
			return "です";
		}
	}

	return "％です％";
}



// ～ですか ～でござるか ～か
String^ ％ですか％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ですか 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ですか";

				// か （他） 
			}
			else {
				return "か";
			}

			// Group B
		}
		else {
			// ですか 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ですか";

				// でござるか 自口=5 || 自職=1or3(忍者or剣豪)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "でござるか";

				// ですか （他） 
			}
			else {
				return "ですか";
			}
		}
	}

	return "％ですか％";
}



// でしょう ～じゃろう ～であろう ～だろう
String^ ％でしょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// でしょう 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "でしょう";

				// であろう 自口=3 || 自口=1 || 自口=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 3 || nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "であろう";

				// だろう 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "だろう";

				// じゃろう (他)
			}
			else {
				return "じゃろう";
			}

			// Group B
		}
		else {
			// でしょう
			return "でしょう";
		}
	}

	return "％でしょう％";
}



// ～でした ～じゃった ～であった ～だった
String^ ％でした％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// でした 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "でした";

				// であった 自口=3 || 自口=1 || 自口=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 3 || nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "であった";

				// だった 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "だった";

				// じゃった (他)
			}
			else {
				return "じゃった";
			}

			// Group B
		}
		else {
			// でした
			return "でした";
		}
	}

	return "％でした％";
}



// ～あります ～ございます ～ござる ～ある ～おじゃる
String^ ％あります％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// あります 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "あります";

				// おじゃる 自口=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "おじゃる";

				// ある (他)
			}
			else {
				return "ある";
			}

			// Group B
		}
		else {
			// あります 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "あります";

				// ござる 自口=5 || 自職=1or3(忍者or剣豪)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "ござる";

				// あります 自相=同じ大名家所属 
			}
			else if (is自分と相手は同じ大名家所属(i1st_BushouID, i2nd_BushouID)) {
				return "あります";

				// ございます （他） 
			}
			else {
				return "ございます";

			}
		}
	}

	return "％あります％";
}


// ～ありません ～ございません ～ござらぬ ～ない ～おじゃらぬ ～ありませぬ
String^ ％ありません％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ありませぬ 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ありませぬ";

				// おじゃらぬ 自口=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "おじゃらぬ";

				// ない (他)
			}
			else {
				return "ない";
			}

			// Group B
		}
		else {
			// ありませぬ 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ありませぬ";

				// ござらぬ 自口=5 || 自職=1or3(忍者or剣豪)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "ござらぬ";

				// ありません 自相=同じ大名家所属 
			}
			else if (is自分と相手は同じ大名家所属(i1st_BushouID, i2nd_BushouID)) {
				return "あります";

				// ございません （他） 
			}
			else {
				return "ございます";

			}
		}
	}

	return "％ありません％";
}




// ～します ～いたす ～する
String^ ％します％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// します 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "します";

				// する 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "する";

				// いたす (他)
			}
			else {
				return "いたす";
			}

			// Group B
		}
		else {
			// いたす 自口=5 || 自男
			if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushouname[i1st_BushouID].sex == 0) {
				return "いたす";

				// します (他)
			}
			else {
				return "します";
			}
		}
	}

	return "％します％";
}

// ～しません ～いたさぬ ～せぬ ～せん ～しませぬ
String^ ％しません％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// しませぬ 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "しませぬ";

				// せん 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "せん";

				// せぬ (他)
			}
			else {
				return "せぬ";
			}

			// Group B
		}
		else {
			// しませぬ 自口=1 || 自口=3 || 自女
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "しませぬ";

				// いたさぬ 自口=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 5) {
				return "いたさぬ";

				// しません (他)
			}
			else {
				return "しません";
			}
		}
	}

	return "％しません％";
}



// ～しましょう ～いたそう ～しよう
String^ ％しましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// しましょう 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "しましょう";

				// しよう 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "しよう";

				// いたそう (他)
			}
			else {
				return "いたそう";
			}

			// Group B
		}
		else {
			// いたそう 自口=5 || 自男
			if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushouname[i1st_BushouID].sex == 0) {
				return "いたそう";

				// しましょう (他)
			}
			else {
				return "しましょう";
			}
		}
	}

	return "％しましょう％";
}



// ～いましょう ～おう  (言いましょうなど)
String^ ％いましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// いましょう 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "いましょう";

				// おう (他)
			}
			else {
				return "おう";
			}

			// Group B
		}
		else {
			// いましょう (他)
			return "いましょう";
		}
	}

	return "％いましょう％";
}



// ～きましょう ～こう  (行きましょうなど)
String^ ％きましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// きましょう 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "きましょう";

				// こう (他)
			}
			else {
				return "こう";
			}

			// Group B
		}
		else {
			// きましょう (他)
			return "きましょう";
		}
	}

	return "％きましょう％";
}


// ～しましょう ～そう  (？… ％しましょう％の方が良いか)
String^ ％しましょう２％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// そう (他)
			return "そう";

			// Group B
		}
		else {
			// しましょう (他)
			return "しましょう";
		}
	}

	return "％しましょう２％";
}



// ～ちましょう ～とう  (待ちましょうなど)
String^ ％ちましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// とう (他)
			return "とう";

			// Group B
		}
		else {
			// ちましょう (他)
			return "ちましょう";
		}
	}

	return "％ちましょう％";
}


// 29 ～みましょう ～もう  (攻め込みましょうなど)
String^ ％みましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// もう (他)
			return "もう";

			// Group B
		}
		else {
			// みましょう (他)
			return "みましょう";
		}
	}

	return "％ちましょう％";
}


// ～ましょう ～よう  (その他の一般パターン。立てましょうなど)
String^ ％ましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ましょう 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ましょう";

				// よう (他)
			}
			else {
				return "よう";
			}

			// Group B
		}
		else {
			// ましょう (他)
			return "ましょう";
		}
	}

	return "％ましょう％";
}



// ～りましょう ～ろう  (参りましょうなど)
String^ ％りましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// りましょう 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "りましょう";

				// ろう (他)
			}
			else {
				return "ろう";
			}

			// Group B
		}
		else {
			// りましょう (他)
			return "りましょう";
		}
	}

	return "％りましょう％";
}


// ～ぎましょう ～ごう  (急ぎましょうなど)
String^ ％ぎましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ごう (他)
			return "ごう";

			// Group B
		}
		else {
			// ぎましょう (他)
			return "ぎましょう";
		}
	}

	return "％ぎましょう％";
}


// ～びましょう ～ぼう　(遊びましょうなど)
String^ ％びましょう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ぼう (他)
			return "ぼう";

			// Group B
		}
		else {
			// びましょう (他)
			return "びましょう";
		}
	}

	return "％びましょう％";
}



// 35 ～います ～ござる ～おる ～いる ～おじゃる ～おります
String^ ％います％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// おります 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "おります";

				// おじゃらぬ 自口=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "おじゃる";

				// いる 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "いる";

				// おる (他)
			}
			else {
				return "おる";
			}

			// Group B
		}
		else {
			// おります 自口=1 or 自口=3 or 自女 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "おります";

				// ござる 自口=5 || 自職=1or3(忍者or剣豪)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "ござる";

				// います (他） 
			}
			else {
				return "います";

			}
		}
	}

	return "％います％";
}



// 37 ～いません ～ござらぬ ～おらぬ ～おらん ～おじゃらぬ ～おりませぬ
String^ ％いません％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// おりませぬ 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "おりませぬ";

				// おじゃらぬ 自口=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "おじゃらぬ";

				// おらん 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "おらん";

				// おらぬ (他)
			}
			else {
				return "おらぬ";
			}

			// Group B
		}
		else {
			// おりませぬ 自口=1 or 自口=3 or 自女 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "おりませぬ";

				// ござらぬ 自口=5 || 自職=1or3(忍者or剣豪)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "ござらぬ";

				// いません (他） 
			}
			else {
				return "いません";

			}
		}
	}

	return "％いません％";
}



// 39 ～いました ～ござった ～おった ～いた ～おじゃった ～おりました
String^ ％いました％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// おりました 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "おりました";

				// おじゃった 自口=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "おじゃった";

				// いた 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "いた";

				// おった (他)
			}
			else {
				return "おった";
			}

			// Group B
		}
		else {
			// おりました 自口=1 or 自口=3 or 自女 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "おりました";

				// ござった 自口=5 || 自職=1or3(忍者or剣豪)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "ござった";

				// いました (他） 
			}
			else {
				return "いました";

			}
		}
	}

	return "％いました％";
}



// ～ます ～る ～ります
String^ ％ます％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ます 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ます";

				// る (他)
			}
			else {
				return "る";
			}

			// Group B
		}
		else {

			// ます 自相=同じ大名家所属 
			if (is自分と相手は同じ大名家所属(i1st_BushouID, i2nd_BushouID)) {
				return "ます";

				// ります（他） 
			}
			else {
				return "ります";

			}
		}
	}

	return "％ます％";
}



// ～りません ～らぬ
String^ ％りません％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// りません 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "りません";

				// らぬ (他)
			}
			else {
				return "らぬ";
			}

			// Group B
		}
		else {

			// りません（他） 
			return "りません";
		}
	}

	return "％りません％";
}


// ～ません ～ぬ ～ねえ ～ませぬ
String^ ％ません％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ませぬ 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ませぬ";

				// ねえ 自口=2 && 自身<=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 && nb6bushouname[i2nd_BushouID].position <= 3) {
				return "ねえ";

				// ぬ (他)
			}
			else {
				return "ぬ";
			}

			// Group B
		}
		else {
			// ませぬ 自口=1 || 自口=5
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "ませぬ";

				// ません (他） 
			}
			else {
				return "ません";

			}
		}
	}

	return "％ません％";
}



// ～ました ～た
String^ ％ました％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ました 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ました";

				// た (他)
			}
			else {
				return "た";
			}

			// Group B
		}
		else {

			// ました (他） 
			return "ました";

		}
	}

	return "％ました％";
}



// ～りました ～った
String^ ％りました％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// りました 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "りました";

				// った (他)
			}
			else {
				return "った";
			}

			// Group B
		}
		else {

			// りました (他） 
			return "りました";

		}
	}

	return "％りました％";
}



// ～ませんでした ～なかった
String^ ％ませんでした％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ませんでした 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ませんでした";

				// なかった (他)
			}
			else {
				return "なかった";
			}

			// Group B
		}
		else {

			// ませんでした (他） 
			return "ませんでした";

		}
	}

	return "％ませんでした％";
}



// ～思います ～存じます ～思う
String^ ％思います％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// 思います 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "思います";

				// 思う (他)
			}
			else {
				return "思う";
			}

			// Group B
		}
		else {

			// 存じます 自口=1 or 自口=3 or 自女
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "存じます";

				// 思います (他)
			}
			else {
				return "思います";
			}

		}
	}

	return "％思います％";
}


// ～参りました ～参上しました ～参った
String^ ％参りました％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// 参りました 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "参りました";

				// 参った (他)
			}
			else {
				return "参った";
			}

			// Group B
		}
		else {

			// 参りました 自女
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "参りました";

				// 参上しました 自口=1 or 自口=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "参上しました";

				// 参りました (他)
			}
			else {
				return "参りました";
			}

		}
	}

	return "％参りました％";
}



// ～くだされ ～下さい ～くれ
String^ ％くだされ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// 下さい 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "下さい";

				// くれ (他)
			}
			else {
				return "くれ";
			}

			// Group B
		}
		else {

			// 下さい 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "下さい";

				// くだされ (他)
			}
			else {
				return "くだされ";
			}

		}
	}

	return "％くだされ％";
}



// ～すみません ～申し訳ない ～すまぬ ～すまん ～ごめんなさい
String^ ％すみません％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ごめんなさい 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "ごめんなさい";

				// すまん 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "すまん";

				// すまぬ (他)
			}
			else {
				return "すまぬ";
			}

			// Group B
		}
		else {
			// 申し訳ない 自口=5 or 自男 
			if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushouname[i1st_BushouID].sex == 0) {
				return "申し訳ない";

				// すみません (他） 
			}
			else {
				return "すみません";

			}
		}
	}

	return "％すみません％";
}

// ～願います ～お願いいたす ～願おう ～願う ～お願いします
String^ ％願います％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// 願います 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "願います";

				// 願う 自口=2 || 自口=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "願う";

				// 願おう (他)
			}
			else {
				return "願おう";
			}

			// Group B
		}
		else {
			// お願します 自口=1 or 自口=3 or 自女 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "お願いします";

				// お願いいたす 自口=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 5) {
				return "お願いいたす";

				// 願います (他） 
			}
			else {
				return "願います";

			}
		}
	}

	return "％願います％";
}



// ～よい ～よろしい
String^ ％よい％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// 略記条件Ｔのどれがあてはまるか？ どれにもあてはまらなかったら略記条件Ｙでどちらかに当てはまる。
		int Group = ％略記条件Ｔ％(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// よろしい 自女 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "よろしい";

				// よい (他)
			}
			else {
				return "よい";
			}

			// Group B
		}
		else {

			// よろしい 自口=1 or 自口=3 or 自女
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "よろしい";

				// よい (他)
			}
			else {
				return "よい";
			}

		}
	}

	return "％よい％";
}









// ～か ～ね
String^ ％か（１）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ね 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "ね";

			// か （他） 
		}
		else {
			return "か";
		}
	}

	return "％か（１）％";
}




// ～か ～なの
String^ ％か（２）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// なの 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "なの";

			// か （他） 
		}
		else {
			return "か";
		}
	}

	return "％か（２）％";
}





// ～か ～わ
String^ ％か（３）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わ";

			// か （他） 
		}
		else {
			return "か";
		}
	}

	return "％か（３）％";
}



// ～か ～かしら
String^ ％か（４）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// かしら 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "かしら";

			// か （他） 
		}
		else {
			return "か";
		}
	}

	return "％か（４）％";
}





// ～ぞ ～ぜ ～ぞよ ～わ
String^ ％ぞ（１）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わ";

			// ぞよ 自口=3  
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "ぞよ";

			// ぜ 自口=2&自身=1
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && nb6bushouname[i1st_BushouID].position == 1) {
			return "ぜ";

			// ぞ （他） 
		}
		else {
			return "ぞ";
		}
	}

	return "％ぞ（１）％";
}




// ～ぞ ～ぜ ～ぞよ ～わよ
String^ ％ぞ（２）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わよ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わよ";

			// ぞよ 自口=3  
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "ぞよ";

			// ぜ 自口=2&自身=1
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && nb6bushouname[i1st_BushouID].position == 1) {
			return "ぜ";

			// ぞ （他） 
		}
		else {
			return "ぞ";
		}
	}

	return "％ぞ（２）％";
}







// ～な ～わ
String^ ％な（１）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わ";

			// な （他） 
		}
		else {
			return "な";
		}
	}

	return "％な（１）％";
}





// ～な ～ね
String^ ％な（２）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ね 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "ね";

			// な （他） 
		}
		else {
			return "な";
		}
	}

	return "％な（２）％";
}




// ～(無し) ～わ
String^ ％わ（１）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わ";

			// (無し) （他） 
		}
		else {
			return "";
		}
	}

	return "％わ（１）％";
}




// ～わ ～わい
String^ ％わ（２）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// わ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "わ";

			// わい 自口=2&自齢≧50 
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && getYearsOld(i1st_BushouID) >= 50) {
			return "わい";

			// わ （他） 
		}
		else {
			return "わ";

		}
	}

	return "％わ（２）";
}






// ～なあ ～のお ～ねえ 
String^ ％なあ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ねえ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "ねえ";

			// のお 自口=2&自齢≧50 
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && getYearsOld(i1st_BushouID) >= 50) {
			return "のお";

			// なあ （他） 
		}
		else {
			return "なあ";

		}
	}

	return "％なあ％";
}






// ～お ～(無し)
String^ ％お（１）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// (無し) 自相血縁&自齢≧相齢 
		if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID)) {
			return "";

			// お （他） 
		}
		else {
			return "お";

		}
	}

	return "％お（１）％";
}




// ～お ～(無し)
String^ ％お（２）％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// (無し) 自相血縁&自齢≧相齢 
		if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID)) {
			return "";

			// お 自口=1or3or自女 
		}
		else if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
			return "お";

		}
		else {
			return "";
		}
	}

	return "％お（２）％";
}







// ははは ふふふ くくく あはは わはは ふっ うふふ おほほ 
String^ ％ははは％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// おほほ 自女&自齢≧25 
		if (nb6bushouname[i1st_BushouID].sex == 1 && getYearsOld(i1st_BushouID) >= 25) {
			return "おほほ";

			// うふふ 自女
		}
		else if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "うふふ";

			// わはは 自口=2
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "わはは";

			// ふっ 自口=0
		}
		else if (nb6bushou[i1st_BushouID].tone == 0) {
			return "ふっ";

			// あはは 自齢≦20 
		}
		else if (getYearsOld(i1st_BushouID) <= 20) {
			return "あはは";

			// くくく 戦才B以下&自戦≦50
		}
		else if (nb6bushou[i1st_BushouID].aptitudebat <= 1 && getBushouBat(i1st_BushouID) <= 50) {
			return "くくく";

			// ふふふ 戦才B以下
		}
		else if (nb6bushou[i1st_BushouID].aptitudebat <= 1) {
			return "ふふふ";

			// ははは （他） 
		}
		else {
			return "ははは";
		}
	}

	return "％ははは％";
}



// ～い ～き
String^ ％い％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// き 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "き";

			// い （他） 
		}
		else {
			return "い";
		}
	}

	return "％い％";
}




// うむむ まあ 
String^ ％うむむ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// まあ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "まあ";

			// うむむ （他） 
		}
		else {
			return "うむむ";
		}
	}

	return "％うむむ％";
}



// おお まあ
String^ ％おお％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// まあ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "まあ";

			// おお （他） 
		}
		else {
			return "おお";
		}
	}

	return "％おお％";
}




// つまらぬ… おもしろくありません 
String^ ％つまらぬ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// おもしろくありません 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "おもしろくありません";

			// つまらぬ… （他） 
		}
		else {
			return "つまらぬ…";
		}
	}

	return "％つまらぬ…％";
}




// やっ し 
String^ ％やっ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// し 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "し";

			// やっ （他） 
		}
		else {
			return "やっ";
		}
	}

	return "％やっ％";
}




// ち てし
String^ ％ち％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// てし 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "てし";

			// ち （他） 
		}
		else {
			return "ち";
		}
	}

	return "％ち％";
}





// れ られよ 
String^ ％れ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// られよ 自齢<相齢  
		if (getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID)) {
			return "られよ";

			// れ （他） 
		}
		else {
			return "れ";
		}
	}

	return "％れ％";
}






// しんぜよう くれよう しんぜましょう 
String^ ％しんぜよう％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// しんぜましょう 自相血縁&自齢<相齢 
		if (is自分は相手の血縁(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID)) {
			return "しんぜましょう";

			// しんぜましょう 自女  
		}
		else if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "しんぜましょう";

			// くれよう
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "くれよう";

			// しんぜよう （他） 
		}
		else {
			return "しんぜよう";
		}
	}

	return "％しんぜよう％";
}


// 一族 親子 姉妹 姉弟 兄妹 夫婦 兄弟 姉妹 姉弟 兄妹 
String^ ％一族％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (is自分は相手の親(i1st_BushouID, i2nd_BushouID)) {
			return "親子";

			// 兄弟
		}
		else if (is自分と相手は兄弟(i1st_BushouID, i2nd_BushouID)) {
			return "兄弟";

			// 姉妹
		}
		else if (is自分と相手は姉妹(i1st_BushouID, i2nd_BushouID)) {
			return "姉妹";

			// 姉弟
		}
		else if (is自分と相手は姉弟(i1st_BushouID, i2nd_BushouID)) {
			return "姉弟";

			// 兄妹 
		}
		else if (is自分と相手は兄妹(i1st_BushouID, i2nd_BushouID)) {
			return "兄妹";

		}
		else if (is自分は相手の夫(i1st_BushouID, i2nd_BushouID)) {
			return "夫婦";

		}
		else if (is自分は相手の妻(i1st_BushouID, i2nd_BushouID)) {
			return "夫婦";

		}
		else {
			return "一族";

		}
	}

	return "％一族％";
}




// でござる だぞ、ははは でおじゃるぞえ ですわ 
String^ ％でござる％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ですわ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "しんぜましょう";

			// だぞ、ははは 自口=2
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "だぞ、" + ％ははは％(i1st_BushouID, i2nd_BushouID, i3rd_BushouID);

			// でおじゃるぞえ 自口=3 
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "でおじゃるぞえ";

			// でござる （他） 
		}
		else {
			return "でござる";
		}
	}

	return "％でござる％";
}




// すな しますな 
String^ ％すな％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// しますな 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "しますな";


			// すな （他） 
		}
		else {
			return "すな";
		}
	}

	return "％すな％";
}





// てみよ なさい
String^ ％てみよ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// なさい 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "なさい";

			// てみよ （他） 
		}
		else {
			return "てみよ";
		}
	}

	return "％てみよ％";
}



// よ ませ
String^ ％よ％(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ませ 自女 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "ませ";

			// よ （他） 
		}
		else {
			return "よ";
		}
	}

	return "％よ％";
}












// 00（相手に敬意を払う必要がない場合の自称） 
String^ 語句変化情報型::わし(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％わし％(i1st, i2nd, i3rd);
}

// 02（その他の場合の自称） 
String^ 語句変化情報型::私(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％私％(i1st, i2nd, i3rd);
}

// 03（所有形容詞）  
String^ 語句変化情報型::我が(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％我が％(i1st, i2nd, i3rd);
}

// 04～07 相手をさげすむ場合「以外」の二人称
String^ 語句変化情報型::相手(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％相手％(i1st, i2nd, i3rd);
}

// 08 相手をさげすむ場合の二人称
String^ 語句変化情報型::罵倒相手(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％罵倒相手％(i1st, i2nd, i3rd);
}

// 09～0D 三名をさげすむ場合「以外」の三人称
String^ 語句変化情報型::三名(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％三名％(i1st, i2nd, i3rd);
}

// 0E（第三者をさげすむ場合の三人称） 
String^ 語句変化情報型::罵倒三名(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％罵倒三名％(i1st, i2nd, i3rd);
}



// 0F ～です ～だ じゃ
String^ 語句変化情報型::です(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％です％(i1st, i2nd, i3rd);
}

// 11 ～ですか ～でござるか ～か
String^ 語句変化情報型::ですか(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ですか％(i1st, i2nd, i3rd);
}
// 13 ～でしょう ～じゃろう ～であろう ～だろう
String^ 語句変化情報型::でしょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％でしょう％(i1st, i2nd, i3rd);
}
// 15 ～でした ～じゃった ～であった ～だった
String^ 語句変化情報型::でした(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％でした％(i1st, i2nd, i3rd);
}

// 17 ～あります ～ございます ～ござる ～ある ～おじゃる
String^ 語句変化情報型::あります(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％あります％(i1st, i2nd, i3rd);
}

// 19 ～ありません ～ございません ～ござらぬ ～ない ～おじゃらぬ ～ありませぬ
String^ 語句変化情報型::ありません(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ありません％(i1st, i2nd, i3rd);
}

// 1B ～します ～いたす ～する
String^ 語句変化情報型::します(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％します％(i1st, i2nd, i3rd);
}

// 1D ～しません ～いたさぬ ～せぬ ～せん ～しませぬ
String^ 語句変化情報型::しません(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％しません％(i1st, i2nd, i3rd);
}
// 1F ～しましょう ～いたそう ～しよう
String^ 語句変化情報型::しましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％しましょう％(i1st, i2nd, i3rd);
}


// 21 ～いましょう ～おう  (言いましょうなど)
String^ 語句変化情報型::いましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％いましょう％(i1st, i2nd, i3rd);
}

// 23 ～きましょう ～こう  (行きましょうなど)
String^ 語句変化情報型::きましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％きましょう％(i1st, i2nd, i3rd);
}

// 25 ～しましょう ～そう  (？… ％しましょう％の方が良いか)
String^ 語句変化情報型::しましょう２(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％しましょう２％(i1st, i2nd, i3rd);
}

// 27 ～ちましょう ～とう  (待ちましょうなど)
String^ 語句変化情報型::ちましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ちましょう％(i1st, i2nd, i3rd);
}

// 29 ～みましょう ～もう  (攻め込みましょうなど)
String^ 語句変化情報型::みましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％みましょう％(i1st, i2nd, i3rd);
}

// 2B ～ましょう ～よう  (その他の一般パターン。立てましょうなど)
String^ 語句変化情報型::ましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ましょう％(i1st, i2nd, i3rd);
}

// 2D ～りましょう ～ろう  (参りましょうなど)
String^ 語句変化情報型::りましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％りましょう％(i1st, i2nd, i3rd);
}

// 31 ～ぎましょう ～ごう  (急ぎましょうなど)
String^ 語句変化情報型::ぎましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ぎましょう％(i1st, i2nd, i3rd);
}

// 33 ～びましょう ～ぼう　(遊びましょうなど)
String^ 語句変化情報型::びましょう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％びましょう％(i1st, i2nd, i3rd);
}


// 35 ～います ～ござる ～おる ～いる ～おじゃる ～おります
String^ 語句変化情報型::います(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％います％(i1st, i2nd, i3rd);
}

// 37 ～いません ～ござらぬ ～おらぬ ～おらん ～おじゃらぬ ～おりませぬ
String^ 語句変化情報型::いません(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％いません％(i1st, i2nd, i3rd);
}

// 39 ～いました ～ござった ～おった ～いた ～おじゃった ～おりました
String^ 語句変化情報型::いました(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％いました％(i1st, i2nd, i3rd);
}

// 3B ～ます ～る ～ります
String^ 語句変化情報型::ます(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ます％(i1st, i2nd, i3rd);
}

// 3D ～りません ～らぬ
String^ 語句変化情報型::りません(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％りません％(i1st, i2nd, i3rd);
}

// 3F ～ません ～ぬ ～ねえ ～ませぬ
String^ 語句変化情報型::ません(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ません％(i1st, i2nd, i3rd);
}

// 41 ～ました ～た
String^ 語句変化情報型::ました(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ました％(i1st, i2nd, i3rd);
}

// 43 ～りました ～った
String^ 語句変化情報型::りました(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％りました％(i1st, i2nd, i3rd);
}

// 45 ～ませんでした ～なかった
String^ 語句変化情報型::ませんでした(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ませんでした％(i1st, i2nd, i3rd);
}

// 47 ～思います ～存じます ～思う
String^ 語句変化情報型::思います(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％思います％(i1st, i2nd, i3rd);
}

// 49 ～参りました ～参上しました ～参った
String^ 語句変化情報型::参りました(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％参りました％(i1st, i2nd, i3rd);
}

// 4B ～くだされ ～下さい ～くれ
String^ 語句変化情報型::くだされ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％くだされ％(i1st, i2nd, i3rd);
}

// 4D ～すみません ～申し訳ない ～すまぬ ～すまん ～ごめんなさい
String^ 語句変化情報型::すみません(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％すみません％(i1st, i2nd, i3rd);
}

// 4F ～願います ～お願いいたす ～願おう ～願う ～お願いします
String^ 語句変化情報型::願います(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％願います％(i1st, i2nd, i3rd);
}

// 51 ～よい ～よろしい
String^ 語句変化情報型::よい(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％よい％(i1st, i2nd, i3rd);
}






// ～か ～ね
String^ 語句変化情報型::か_１(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％か（１）％(i1st, i2nd, i3rd);
}

// ～か ～なの
String^ 語句変化情報型::か_２(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％か（２）％(i1st, i2nd, i3rd);
}

// ～か ～わ
String^ 語句変化情報型::か_３(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％か（３）％(i1st, i2nd, i3rd);
}

// ～か ～かしら
String^ 語句変化情報型::か_４(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％か（４）％(i1st, i2nd, i3rd);
}

// ～ぞ ～ぜ ～ぞよ ～わ
String^ 語句変化情報型::ぞ_１(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ぞ（１）％(i1st, i2nd, i3rd);
}

// ～ぞ ～ぜ ～ぞよ ～わよ
String^ 語句変化情報型::ぞ_２(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ぞ（２）％(i1st, i2nd, i3rd);
}

// ～な ～わ
String^ 語句変化情報型::な_１(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％な（１）％(i1st, i2nd, i3rd);
}

// ～な ～ね
String^ 語句変化情報型::な_２(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％な（２）％(i1st, i2nd, i3rd);
}

// ～(無し) ～わ
String^ 語句変化情報型::わ_１(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％わ（１）％(i1st, i2nd, i3rd);
}

// ～わ ～わい
String^ 語句変化情報型::わ_２(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％わ（２）％(i1st, i2nd, i3rd);
}

// ～なあ ～のお ～ねえ 
String^ 語句変化情報型::なあ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％なあ％(i1st, i2nd, i3rd);
}

// ～お ～(無し)
String^ 語句変化情報型::お_１(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％お（１）％(i1st, i2nd, i3rd);
}

// ～お ～(無し)
String^ 語句変化情報型::お_２(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％お（２）％(i1st, i2nd, i3rd);
}

// ははは ふふふ くくく あはは わはは ふっ うふふ おほほ 
String^ 語句変化情報型::ははは(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ははは％(i1st, i2nd, i3rd);
}

// ～い ～き
String^ 語句変化情報型::い(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％い％(i1st, i2nd, i3rd);
}

// うむむ まあ 
String^ 語句変化情報型::うむむ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％うむむ％(i1st, i2nd, i3rd);
}

// おお まあ
String^ 語句変化情報型::おお(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％おお％(i1st, i2nd, i3rd);
}

// つまらぬ… おもしろくありません 
String^ 語句変化情報型::つまらぬ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％つまらぬ％(i1st, i2nd, i3rd);
}

// やっ し 
String^ 語句変化情報型::やっ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％やっ％(i1st, i2nd, i3rd);
}

// ち てし
String^ 語句変化情報型::ち(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％ち％(i1st, i2nd, i3rd);
}

// れ られよ 
String^ 語句変化情報型::れ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％れ％(i1st, i2nd, i3rd);
}

// しんぜよう くれよう しんぜましょう 
String^ 語句変化情報型::しんぜよう(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％しんぜよう％(i1st, i2nd, i3rd);
}

// 一族 親子 姉妹 姉弟 兄妹 夫婦 兄弟 姉妹 姉弟 兄妹 
String^ 語句変化情報型::一族(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％一族％(i1st, i2nd, i3rd);
}

// でござる だぞ、ははは でおじゃるぞえ ですわ 
String^ 語句変化情報型::でござる(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％でござる％(i1st, i2nd, i3rd);
}

// すな しますな 
String^ 語句変化情報型::すな(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％すな％(i1st, i2nd, i3rd);
}

// てみよ なさい
String^ 語句変化情報型::てみよ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％てみよ％(i1st, i2nd, i3rd);
}

// よ ませ
String^ 語句変化情報型::よ(噴出メッセージパラメタ型^ パラメタ) {
	int i1st = パラメタ->第１人称_武将番号;
	int i2nd = パラメタ->第２人称_武将番号;
	int i3rd = パラメタ->第３人称_武将番号;
	return ::％よ％(i1st, i2nd, i3rd);
}



