#include "GameDataStruct.h"

#include "GameDataStructBushouRelation.h"

武将情報型::武将情報型(int i番号)
{
	iBushouID = i番号;

	戦争 = gcnew 戦争武将情報型(i番号);
}

String^ 武将情報型::名字::get()
{
	return gcnew String(nb6bushouname[iBushouID].familyname);
}

void 武将情報型::名字::set(String^ value)
{
	string str_native = to_native_string(value);
	// 全角４文字以下
	if ( str_native.size() <= 8 ) {
		strcpy(nb6bushouname[iBushouID].familyname, str_native.c_str());
	}
}

String^ 武将情報型::名前::get()
{
	return gcnew String(nb6bushouname[iBushouID].fastname);
}

void 武将情報型::名前::set(String^ value)
{
	string str_native = to_native_string(value);
	// 全角４文字以下
	if (str_native.size() <= 8) {
		strcpy(nb6bushouname[iBushouID].fastname, str_native.c_str());
	}
}

String^ 武将情報型::姓名::get()
{
	return gcnew String(nb6bushouname[iBushouID].familyname) + gcnew String(nb6bushouname[iBushouID].fastname);
}


int 武将情報型::性別::get()
{
	return nb6bushouname[iBushouID].sex;
}

void 武将情報型::性別::set(int value)
{
	if (0 <= value && value <= 1)
	{
		nb6bushouname[iBushouID].sex = value;
	}
}


int 武将情報型::列伝番号::get()
{
	return nb6bushouname[iBushouID].number;
}

void 武将情報型::列伝番号::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushouname[iBushouID].number = value;
	}
}

int 武将情報型::差換顔番号::get()
{
	return nb6bushouname[iBushouID].face;
}

void 武将情報型::差換顔番号::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushouname[iBushouID].face = value;
	}
}

int 武将情報型::元政治才能::get()
{
	return getBushouPureGovMax(iBushouID);
}

int 武将情報型::政治才能::get()
{
	return nb6bushou[iBushouID].maxgov;
}

void 武将情報型::政治才能::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxgov = value;
	}
}

int 武将情報型::元戦闘才能::get()
{
	return getBushouPureBatMax(iBushouID);
}


int 武将情報型::戦闘才能::get()
{
	return nb6bushou[iBushouID].maxbat;
}

void 武将情報型::戦闘才能::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxbat = value;
	}
}

int 武将情報型::元智謀才能::get()
{
	return getBushouPureIntMax(iBushouID);
}

int 武将情報型::智謀才能::get()
{
	return nb6bushou[iBushouID].maxint;
}

void 武将情報型::智謀才能::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxint = value;
	}
}


int 武将情報型::政治熟練::get()
{
	return nb6bushou[iBushouID].expgov;
}

void 武将情報型::政治熟練::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expgov = value;
	}
}

int 武将情報型::戦闘熟練::get()
{
	return nb6bushou[iBushouID].expbat;
}

void 武将情報型::戦闘熟練::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expbat = value;
	}
}


int 武将情報型::智謀熟練::get()
{
	return nb6bushou[iBushouID].expint;
}

void 武将情報型::智謀熟練::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expint = value;
	}
}

int 武将情報型::政治適性::get()
{
	return nb6bushou[iBushouID].aptitudegov;
}

void 武将情報型::政治適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::政治適性::Ａ)
	{
		nb6bushou[iBushouID].aptitudegov = value;
	}
}

int 武将情報型::戦闘適性::get()
{
	return nb6bushou[iBushouID].aptitudebat;
}

void 武将情報型::戦闘適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::戦闘適性::Ａ)
	{
		nb6bushou[iBushouID].aptitudebat = value;
	}
}

int 武将情報型::智謀適性::get()
{
	return nb6bushou[iBushouID].aptitudeint;
}

void 武将情報型::智謀適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::智謀適性::Ａ)
	{
		nb6bushou[iBushouID].aptitudeint = value;
	}
}

int 武将情報型::政治値::get()
{
	return getBushouGov(iBushouID);
}

int 武将情報型::戦闘値::get()
{
	return getBushouBat(iBushouID);
}

int 武将情報型::智謀値::get()
{
	return getBushouInt(iBushouID);
}



int 武将情報型::足軽適性::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_ASIGARU);
}

void 武将情報型::足軽適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::足軽適性::Ｓ)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_ASIGARU, value);
	}
}

int 武将情報型::騎馬適性::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_KIBA);
}

void 武将情報型::騎馬適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::騎馬適性::Ｓ)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_KIBA, value);
	}
}

int 武将情報型::鉄砲適性::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_TEPPOU);
}

void 武将情報型::鉄砲適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::鉄砲適性::Ｓ)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_TEPPOU, value);
	}
}

int 武将情報型::水軍適性::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_SUIGUN);
}

void 武将情報型::水軍適性::set(int value)
{
	if (0 <= value && value <= 列挙::武将::水軍適性::Ｓ)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_SUIGUN, value);
	}
}

int 武将情報型::元魅力::get()
{
	return getBushouPureCharm(iBushouID);
}

int 武将情報型::魅力::get()
{
	return nb6bushou[iBushouID].charm;
}

void 武将情報型::魅力::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].charm = value;
	}
}

int 武将情報型::元野望::get()
{
	return getBushouPureAmbition(iBushouID);
}

int 武将情報型::野望::get()
{
	return nb6bushou[iBushouID].ambition;
}

void 武将情報型::野望::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].ambition = value;
	}
}

int 武将情報型::忠誠::get()
{
	return nb6bushou[iBushouID].loyal;
}

void 武将情報型::忠誠::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].loyal = value;
	}
}

int 武将情報型::勲功::get()
{
	return nb6bushou[iBushouID].merits;
}

void 武将情報型::勲功::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].merits = value;
	}
}


int 武将情報型::血筋番号::get()
{
	return nb6bushou[iBushouID].blood;
}

void 武将情報型::血筋番号::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].blood = value;
	}
}

int 武将情報型::所属大名番号::get()
{
	int attr = nb6bushou[iBushouID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 武将情報型::所属軍団番号::get()
{
	int attr = nb6bushou[iBushouID].gundan;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 武将情報型::所属城番号::get()
{
	int attr = nb6bushou[iBushouID].castle;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 武将情報型::内応先大名番号::get()
{
	int attr = nb6bushou[iBushouID].rise;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void 武将情報型::内応先大名番号::set(int value)
{
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6bushou[iBushouID].rise = value + 1;
	}
	else if (value == 0xFFFF) {
		nb6bushou[iBushouID].rise = 0xFFFF;
	}
}


int 武将情報型::兵士::get()
{
	return nb6bushou[iBushouID].soldier;
}

int 武将情報型::最大兵士::get()
{
	int position = nb6bushouname[iBushouID].position;
	if (列挙::武将::身分::隠居 <= position && position <= 列挙::武将::身分::足軽頭) {
		return nb6soldier_max[position].soldiermax;
	}
	return 0;
}

void 武将情報型::兵士::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].soldier = value;
	}
}

int 武将情報型::訓練::get()
{
	return nb6bushou[iBushouID].training;
}

void 武将情報型::訓練::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].training = value;
	}
}

int 武将情報型::士気::get()
{
	return nb6bushou[iBushouID].solloyal;
}

void 武将情報型::士気::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].solloyal = value;
	}
}

int 武将情報型::兵科::get()
{
	return nb6bushou[iBushouID].form;
}

void 武将情報型::兵科::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].form = value;
	}
}

int 武将情報型::士官年数::get()
{
	return nb6bushou[iBushouID].work;
}

void 武将情報型::士官年数::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].work = value;
	}
}

int 武将情報型::生年::get()
{
	return GAMEDATASTRUCT_TENSHOUKI_GANNEN + nb6bushou[iBushouID].birth - 1;
}

void 武将情報型::生年::set(int value)
{
	if (GAMEDATASTRUCT_TENSHOUKI_GANNEN <= value && value <= GAMEDATASTRUCT_TENSHOUKI_GANNEN + LIMIT_BYTE_MAX)
	{
		int birth = value - GAMEDATASTRUCT_TENSHOUKI_GANNEN + 1;
		nb6bushou[iBushouID].birth = birth;
	}
}

int 武将情報型::年齢::get()
{
	return getYearsOld(iBushouID);
}


int 武将情報型::親列伝番号::get()
{
	return nb6bushou[iBushouID].parent;
}

void 武将情報型::親列伝番号::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].parent = value;
	}
}


int 武将情報型::思考::get()
{
	return nb6bushou[iBushouID].algo;
}

void 武将情報型::思考::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].algo = value;
	}
}

int 武将情報型::義理::get()
{
	return nb6bushou[iBushouID].duty;
}

void 武将情報型::義理::set(int value)
{
	if (0 <= value && value <= 15)
	{
		nb6bushou[iBushouID].duty = value;
	}
}

int 武将情報型::相性::get()
{
	return nb6bushou[iBushouID].affinity;
}

void 武将情報型::相性::set(int value)
{
	if (0 <= value && value <= 15)
	{
		nb6bushou[iBushouID].affinity = value;
	}
}


bool 武将情報型::技能一喝::get()
{
	return nb6bushou[iBushouID].tech_ikkatsu;
}

void 武将情報型::技能一喝::set(bool value)
{
	nb6bushou[iBushouID].tech_ikkatsu = value;
}

bool 武将情報型::技能暗殺::get()
{
	return nb6bushou[iBushouID].tech_ansatsu;
}

void 武将情報型::技能暗殺::set(bool value)
{
	nb6bushou[iBushouID].tech_ansatsu = value;
}

bool 武将情報型::技能流出::get()
{
	return nb6bushou[iBushouID].tech_ryusyutsu;
}

void 武将情報型::技能流出::set(bool value)
{
	nb6bushou[iBushouID].tech_ryusyutsu = value;
}

bool 武将情報型::技能煽動::get()
{
	return nb6bushou[iBushouID].tech_sendou;
}

void 武将情報型::技能煽動::set(bool value)
{
	nb6bushou[iBushouID].tech_sendou = value;
}

bool 武将情報型::技能流言::get()
{
	return nb6bushou[iBushouID].tech_ryugen;
}

void 武将情報型::技能流言::set(bool value)
{
	nb6bushou[iBushouID].tech_ryugen = value;
}

bool 武将情報型::技能弁舌::get()
{
	return nb6bushou[iBushouID].tech_benzetsu;
}

void 武将情報型::技能弁舌::set(bool value)
{
	nb6bushou[iBushouID].tech_benzetsu = value;
}

bool 武将情報型::技能焼討::get()
{
	return nb6bushou[iBushouID].tech_yakiuchi;
}

void 武将情報型::技能焼討::set(bool value)
{
	nb6bushou[iBushouID].tech_yakiuchi = value;
}

bool 武将情報型::技能挑発::get()
{
	return nb6bushou[iBushouID].tech_chohatsu;
}

void 武将情報型::技能挑発::set(bool value)
{
	nb6bushou[iBushouID].tech_chohatsu = value;
}

int 武将情報型::職業::get()
{
	return nb6bushou[iBushouID].job;
}

void 武将情報型::職業::set(int value)
{
	if (0 <= value && value <= 列挙::武将::職業::僧侶)
	{
		nb6bushou[iBushouID].job = value;
	}
}

bool 武将情報型::大砲::get()
{
	return nb6bushou[iBushouID].biggun;
}

void 武将情報型::大砲::set(bool value)
{
	nb6bushou[iBushouID].biggun = value;
}

bool 武将情報型::騎馬鉄砲::get()
{
	return nb6bushou[iBushouID].horsegun;
}

void 武将情報型::騎馬鉄砲::set(bool value)
{
	nb6bushou[iBushouID].horsegun = value;
}

bool 武将情報型::鉄甲船::get()
{
	return nb6bushou[iBushouID].steelship;
}

void 武将情報型::鉄甲船::set(bool value)
{
	nb6bushou[iBushouID].steelship = value;
}

int 武将情報型::寿命::get()
{
	return nb6bushou[iBushouID].job;
}

void 武将情報型::寿命::set(int value)
{
	if (0 <= value && value <= 7)
	{
		nb6bushou[iBushouID].life = value;
	}
}

int 武将情報型::勇猛::get()
{
	return nb6bushou[iBushouID].job;
}

void 武将情報型::勇猛::set(int value)
{
	if (0 <= value && value <= 7)
	{
		nb6bushou[iBushouID].brave = value;
	}
}

int 武将情報型::独立::get()
{
	return getBushouIndependence(iBushouID);
}

void 武将情報型::独立::set(int value)
{
	if (0 <= value && value <= 7)
	{
		setBushouIndependence(iBushouID, value);
	}
}

int 武将情報型::口調::get()
{
	return nb6bushou[iBushouID].tone;
}

void 武将情報型::口調::set(int value)
{
	if (0 <= value && value <= 列挙::武将::口調::一般)
	{
		nb6bushou[iBushouID].tone = value;
	}
}


bool 武将情報型::行動済::get()
{
	return nb6bushou[iBushouID].bEnd;
}

void 武将情報型::行動済::set(bool value)
{
	nb6bushou[iBushouID].bEnd = value;
}

bool 武将情報型::内応状態::get()
{
	return nb6bushou[iBushouID].bRise;
}

void 武将情報型::内応状態::set(bool value)
{
	nb6bushou[iBushouID].bRise = value;
}

bool 武将情報型::遺恨状態::get()
{
	return nb6bushou[iBushouID].grudge;
}

void 武将情報型::遺恨状態::set(bool value)
{
	nb6bushou[iBushouID].grudge = value;
}

bool 武将情報型::会見済::get()
{
	return nb6bushou[iBushouID].kaiken;
}

void 武将情報型::会見済::set(bool value)
{
	nb6bushou[iBushouID].kaiken = value;
}

int 武将情報型::状態::get()
{
	// 戦場で戦死をしていても死亡の状態を返しておく
	if (nb6bushouname[iBushouID].battleDeath) {
		return 列挙::武将::状態::死亡;
	}

	return nb6bushouname[iBushouID].State;
}

void 武将情報型::状態::set(int value)
{
	// 現役でを浪人にする
	if (nb6bushouname[iBushouID].State == 列挙::武将::状態::現役 && value== 列挙::武将::状態::浪人) {

		setGenekiToRounin(iBushouID);
	}

	// 浪人を現役にする
	else if (nb6bushouname[iBushouID].State == 列挙::武将::状態::浪人 && value == 列挙::武将::状態::現役) {

		setRouninToGeneki(iBushouID);
	}

}



int 武将情報型::身分::get()
{
	return nb6bushouname[iBushouID].position;
}

void 武将情報型::身分::set(int value)
{
	// 軍団長もしくは現役である。
	if (nb6bushouname[iBushouID].State == 列挙::武将::状態::軍団長 || nb6bushouname[iBushouID].State == 列挙::武将::状態::現役) {

		if (列挙::武将::身分::宿老 <= value && value <= 列挙::武将::身分::足軽頭) {
			nb6bushouname[iBushouID].State = value;
		}
	}
}


bool 武将情報型::Do_城主() {
	return setGenekiToJyosyu(iBushouID);
}

bool 武将情報型::Do_転居(int 城番号) {
	if (0 <= 城番号 && 城番号 < GAMEDATASTRUCT_CASTLE_NUM) {
		return setBushouTransport(iBushouID, 城番号);
	}
	else {
		return false;
	}
}

int 武将情報型::伴侶武将番号::get() {
	return getHanryoBushouID(iBushouID);
}

bool 武将情報型::Do_結婚(int 相手武将番号) {
	if (0 <= 相手武将番号 && 相手武将番号 < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iOtto = -1;
		int iHime = -1;
		// 相手武将番号が姫
		if (nb6bushouname[相手武将番号].State == 列挙::武将::状態::姫) {
			iHime = 相手武将番号;
			iOtto = iBushouID;
			setHimeMarriage(iHime, iOtto, true);
		}
		// 自分が姫
		else if(nb6bushouname[iBushouID].State == 列挙::武将::状態::姫) {
			iHime = iBushouID;
			iOtto = 相手武将番号;
			setHimeMarriage(iHime, iOtto, true);
		}
		else {
			return false;
		}
		
	}

	return false;

}

bool 武将情報型::Do_離婚() {
	int iHime = -1;
	// 自分が姫
	if (nb6bushouname[iBushouID].State == 列挙::武将::状態::姫) {
		iHime = iBushouID;
		setHimeDivorce(iHime, true);
	}
	// 自分は姫ではない。
	else if (nb6bushouname[iBushouID].State != 列挙::武将::状態::姫) {
		// 妻は居ない。
		if (nb6bushou[iBushouID].spouse == 0xFF) {
			return false;
		}

		iHime = nb6bushou[iBushouID].spouse + 500;
		if (0 <= iHime && iHime < GAMEDATASTRUCT_BUSHOU_NUM) {
			setHimeDivorce(iHime, true);
		}
	}

	return false;

}

int 武将情報型::Get_相性差(int 相手武将番号) {
	if (0 <= 相手武将番号 && 相手武将番号 < GAMEDATASTRUCT_BUSHOU_NUM) {
		return getBushouAishoDiff(iBushouID, 相手武将番号);
	}
	else {
		return 8; // 最悪の相性差を返しておく。
	}
}

bool 武将情報型::Is_プレイヤ麾下武将::get() {
	return isPlayerBushou(iBushouID);
}

bool 武将情報型::Is_プレイヤ担当武将::get() {
	int iGundanID = nb6bushou[iBushouID].gundan - 1;
	if ( 0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM ) {
		int number = nb6gundan[iGundanID].number;
		if (number == 1) {
			return isPlayerBushou(iBushouID);
		}
		return false;
	}
	return false;
}

bool 武将情報型::Is_自分は相手の娘(int 相手武将番号) {
	return is自分は相手の娘(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の息子(int 相手武将番号) {
	return is自分は相手の息子(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の子(int 相手武将番号) {
	return is自分は相手の子(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の親(int 相手武将番号) {
	return is自分は相手の親(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の父(int 相手武将番号) {
	return is自分は相手の父(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の父(int 相手武将番号) {
	return is相手は自分の父(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の母(int 相手武将番号) {
	return is自分は相手の母(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の母(int 相手武将番号) {
	return is相手は自分の母(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の弟(int 相手武将番号) {
	return is自分は相手の弟(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の弟(int 相手武将番号) {
	return is相手は自分の弟(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の妹(int 相手武将番号) {
	return is自分は相手の妹(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の妹(int 相手武将番号) {
	return is相手は自分の妹(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の兄(int 相手武将番号) {
	return is自分は相手の兄(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の兄(int 相手武将番号) {
	return is相手は自分の兄(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の姉(int 相手武将番号) {
	return is自分は相手の姉(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の姉(int 相手武将番号) {
	return is相手は自分の姉(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分と相手は兄弟(int 相手武将番号) {
	return is自分と相手は兄弟(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分と相手は姉妹(int 相手武将番号) {
	return is自分と相手は姉妹(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分と相手は姉弟(int 相手武将番号) {
	return is自分と相手は姉弟(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分と相手は兄妹(int 相手武将番号) {
	return is自分と相手は兄妹(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の夫(int 相手武将番号) {
	return is自分は相手の夫(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の妻(int 相手武将番号) {
	return is自分は相手の妻(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分は相手の血縁(int 相手武将番号) {
	return is自分は相手の血縁(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の家臣(int 相手武将番号) {
	return is相手は自分の家臣(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_相手は自分の大名(int 相手武将番号) {
	return is相手は自分の大名(iBushouID, 相手武将番号);
}

bool 武将情報型::Is_自分と相手は同じ大名家所属(int 相手武将番号) {
	return is自分と相手は同じ大名家所属(iBushouID, 相手武将番号);
}

bool 武将情報型::戦争武将情報型::退却済::get()
{
	return nb6bushouname[iBushouID].battleRetreat;
}

int 武将情報型::戦争武将情報型::参戦立場::get() {
	return GetWarStandPointTheBushou(iBushouID);
}

int 武将情報型::戦争武将情報型::混乱状態::get() {
	return GetKonranStatus(iBushouID);
}

bool 武将情報型::戦争武将情報型::行動済::get() {
	if (IsActionEndInBattle(iBushouID)) {
		return true;
	}
	return false;
}

int 武将情報型::戦争武将情報型::機動力::get() {
	return GetBushouMovePower(iBushouID);
}

void 武将情報型::戦争武将情報型::機動力::set(int value) {
	if ( 0 <= value && value < 100 ) {
		SetBushouMovePower(iBushouID, value);
	}
}


bool 武将情報型::戦争武将情報型::出陣中::get() {
	vector<int> list = GetSyutujinBushouArray();
	for each (int iBID in list) {
		if (iBID == iBushouID) {
			return true;
		}
	}
	return false;
}

bool 武将情報型::戦争武将情報型::出陣中_表示戦場::get() {
	vector<int> list = GetCurMapSyutujinBushouArray();
	for each (int iBID in list) {
		if (iBID == iBushouID) {
			return true;
		}
	}
	return false;
}

ヘックス位置型^ 武将情報型::戦争武将情報型::ヘックス位置::get() {
	ヘックス位置型^ pos = gcnew ヘックス位置型();
	if (Is_FieldWar()) {
		HEX_POSITION p = GetFieldHexUnitPos(iBushouID);
		pos->Ｘ = p.x;
		pos->Ｙ = p.y;
	}
	else {
		pos->Ｘ = 0xFFFF;
		pos->Ｙ = 0xFFFF;
	}

	return pos;
}


武将リスト情報型::武将リスト情報型() {

	配列 = gcnew List<武将情報型^>();
	配列->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_BUSHOU_NUM; i++)
	{
		配列->Add(gcnew 武将情報型(i));
	}

	戦争 = gcnew 戦争武将リスト情報型();
}

int 武将リスト情報型::Find_武将番号(int 列伝番号) {
	int iBushouID = getBushouIDFromFaceID(列伝番号);
	return iBushouID;
}

int 武将リスト情報型::Find_武将番号(String^ 姓名) {

	for (int i = 0; i < GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (姓名 == gcnew String(nb6bushouname[i].familyname) + gcnew String(nb6bushouname[i].fastname) ) {
			return i;
		}
	}

	return 0xFFFF;
}

List<int>^ 武将リスト情報型::戦争武将リスト情報型::出陣中_武将番号リスト::get() {
	vector<int> list = GetSyutujinBushouArray();
	List<int>^ m_list = gcnew List<int>();
	for each (int iBID in list) {
		m_list->Add(iBID);
	}
	return m_list;
}

List<int>^ 武将リスト情報型::戦争武将リスト情報型::出陣中_表示戦場_武将番号リスト::get() {
	vector<int> list = GetCurMapSyutujinBushouArray();
	List<int>^ m_list = gcnew List<int>();
	for each (int iBID in list) {
		m_list->Add(iBID);
	}
	return m_list;
}

