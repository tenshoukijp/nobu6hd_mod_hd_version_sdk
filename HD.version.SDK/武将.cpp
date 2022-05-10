#include "GameDataStruct.h"

#include "GameDataStructBushouRelation.h"

•«î•ñŒ^::•«î•ñŒ^(int i”Ô†)
{
	iBushouID = i”Ô†;

	í‘ˆ = gcnew í‘ˆ•«î•ñŒ^(i”Ô†);
}

String^ •«î•ñŒ^::–¼š::get()
{
	return gcnew String(nb6bushouname[iBushouID].familyname);
}

void •«î•ñŒ^::–¼š::set(String^ value)
{
	string str_native = to_native_string(value);
	// ‘SŠp‚S•¶šˆÈ‰º
	if ( str_native.size() <= 8 ) {
		strcpy(nb6bushouname[iBushouID].familyname, str_native.c_str());
	}
}

String^ •«î•ñŒ^::–¼‘O::get()
{
	return gcnew String(nb6bushouname[iBushouID].fastname);
}

void •«î•ñŒ^::–¼‘O::set(String^ value)
{
	string str_native = to_native_string(value);
	// ‘SŠp‚S•¶šˆÈ‰º
	if (str_native.size() <= 8) {
		strcpy(nb6bushouname[iBushouID].fastname, str_native.c_str());
	}
}

String^ •«î•ñŒ^::©–¼::get()
{
	return gcnew String(nb6bushouname[iBushouID].familyname) + gcnew String(nb6bushouname[iBushouID].fastname);
}


int •«î•ñŒ^::«•Ê::get()
{
	return nb6bushouname[iBushouID].sex;
}

void •«î•ñŒ^::«•Ê::set(int value)
{
	if (0 <= value && value <= 1)
	{
		nb6bushouname[iBushouID].sex = value;
	}
}


int •«î•ñŒ^::—ñ“`”Ô†::get()
{
	return nb6bushouname[iBushouID].number;
}

void •«î•ñŒ^::—ñ“`”Ô†::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushouname[iBushouID].number = value;
	}
}

int •«î•ñŒ^::·Š·Šç”Ô†::get()
{
	return nb6bushouname[iBushouID].face;
}

void •«î•ñŒ^::·Š·Šç”Ô†::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushouname[iBushouID].face = value;
	}
}

int •«î•ñŒ^::Œ³­¡Ë”\::get()
{
	return getBushouPureGovMax(iBushouID);
}

int •«î•ñŒ^::­¡Ë”\::get()
{
	return nb6bushou[iBushouID].maxgov;
}

void •«î•ñŒ^::­¡Ë”\::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxgov = value;
	}
}

int •«î•ñŒ^::Œ³í“¬Ë”\::get()
{
	return getBushouPureBatMax(iBushouID);
}


int •«î•ñŒ^::í“¬Ë”\::get()
{
	return nb6bushou[iBushouID].maxbat;
}

void •«î•ñŒ^::í“¬Ë”\::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxbat = value;
	}
}

int •«î•ñŒ^::Œ³’q–dË”\::get()
{
	return getBushouPureIntMax(iBushouID);
}

int •«î•ñŒ^::’q–dË”\::get()
{
	return nb6bushou[iBushouID].maxint;
}

void •«î•ñŒ^::’q–dË”\::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxint = value;
	}
}


int •«î•ñŒ^::­¡n—û::get()
{
	return nb6bushou[iBushouID].expgov;
}

void •«î•ñŒ^::­¡n—û::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expgov = value;
	}
}

int •«î•ñŒ^::í“¬n—û::get()
{
	return nb6bushou[iBushouID].expbat;
}

void •«î•ñŒ^::í“¬n—û::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expbat = value;
	}
}


int •«î•ñŒ^::’q–dn—û::get()
{
	return nb6bushou[iBushouID].expint;
}

void •«î•ñŒ^::’q–dn—û::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expint = value;
	}
}

int •«î•ñŒ^::­¡“K«::get()
{
	return nb6bushou[iBushouID].aptitudegov;
}

void •«î•ñŒ^::­¡“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::­¡“K«::‚`)
	{
		nb6bushou[iBushouID].aptitudegov = value;
	}
}

int •«î•ñŒ^::í“¬“K«::get()
{
	return nb6bushou[iBushouID].aptitudebat;
}

void •«î•ñŒ^::í“¬“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::í“¬“K«::‚`)
	{
		nb6bushou[iBushouID].aptitudebat = value;
	}
}

int •«î•ñŒ^::’q–d“K«::get()
{
	return nb6bushou[iBushouID].aptitudeint;
}

void •«î•ñŒ^::’q–d“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::’q–d“K«::‚`)
	{
		nb6bushou[iBushouID].aptitudeint = value;
	}
}

int •«î•ñŒ^::­¡’l::get()
{
	return getBushouGov(iBushouID);
}

int •«î•ñŒ^::í“¬’l::get()
{
	return getBushouBat(iBushouID);
}

int •«î•ñŒ^::’q–d’l::get()
{
	return getBushouInt(iBushouID);
}



int •«î•ñŒ^::‘«Œy“K«::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_ASIGARU);
}

void •«î•ñŒ^::‘«Œy“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::‘«Œy“K«::‚r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_ASIGARU, value);
	}
}

int •«î•ñŒ^::‹R”n“K«::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_KIBA);
}

void •«î•ñŒ^::‹R”n“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::‹R”n“K«::‚r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_KIBA, value);
	}
}

int •«î•ñŒ^::“S–C“K«::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_TEPPOU);
}

void •«î•ñŒ^::“S–C“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::“S–C“K«::‚r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_TEPPOU, value);
	}
}

int •«î•ñŒ^::…ŒR“K«::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_SUIGUN);
}

void •«î•ñŒ^::…ŒR“K«::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::…ŒR“K«::‚r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_SUIGUN, value);
	}
}

int •«î•ñŒ^::Œ³–£—Í::get()
{
	return getBushouPureCharm(iBushouID);
}

int •«î•ñŒ^::–£—Í::get()
{
	return nb6bushou[iBushouID].charm;
}

void •«î•ñŒ^::–£—Í::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].charm = value;
	}
}

int •«î•ñŒ^::Œ³–ì–]::get()
{
	return getBushouPureAmbition(iBushouID);
}

int •«î•ñŒ^::–ì–]::get()
{
	return nb6bushou[iBushouID].ambition;
}

void •«î•ñŒ^::–ì–]::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].ambition = value;
	}
}

int •«î•ñŒ^::’‰½::get()
{
	return nb6bushou[iBushouID].loyal;
}

void •«î•ñŒ^::’‰½::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].loyal = value;
	}
}

int •«î•ñŒ^::ŒMŒ÷::get()
{
	return nb6bushou[iBushouID].merits;
}

void •«î•ñŒ^::ŒMŒ÷::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].merits = value;
	}
}


int •«î•ñŒ^::ŒŒ‹Ø”Ô†::get()
{
	return nb6bushou[iBushouID].blood;
}

void •«î•ñŒ^::ŒŒ‹Ø”Ô†::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].blood = value;
	}
}

int •«î•ñŒ^::Š‘®‘å–¼”Ô†::get()
{
	int attr = nb6bushou[iBushouID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int •«î•ñŒ^::Š‘®ŒR’c”Ô†::get()
{
	int attr = nb6bushou[iBushouID].gundan;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int •«î•ñŒ^::Š‘®é”Ô†::get()
{
	int attr = nb6bushou[iBushouID].castle;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int •«î•ñŒ^::“à‰æ‘å–¼”Ô†::get()
{
	int attr = nb6bushou[iBushouID].rise;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void •«î•ñŒ^::“à‰æ‘å–¼”Ô†::set(int value)
{
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6bushou[iBushouID].rise = value + 1;
	}
	else if (value == 0xFFFF) {
		nb6bushou[iBushouID].rise = 0xFFFF;
	}
}


int •«î•ñŒ^::•ºm::get()
{
	return nb6bushou[iBushouID].soldier;
}

int •«î•ñŒ^::Å‘å•ºm::get()
{
	int position = nb6bushouname[iBushouID].position;
	if (—ñ‹“::•«::g•ª::‰B‹ <= position && position <= —ñ‹“::•«::g•ª::‘«Œy“ª) {
		return nb6soldier_max[position].soldiermax;
	}
	return 0;
}

void •«î•ñŒ^::•ºm::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].soldier = value;
	}
}

int •«î•ñŒ^::ŒP—û::get()
{
	return nb6bushou[iBushouID].training;
}

void •«î•ñŒ^::ŒP—û::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].training = value;
	}
}

int •«î•ñŒ^::m‹C::get()
{
	return nb6bushou[iBushouID].solloyal;
}

void •«î•ñŒ^::m‹C::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].solloyal = value;
	}
}

int •«î•ñŒ^::•º‰È::get()
{
	return nb6bushou[iBushouID].form;
}

void •«î•ñŒ^::•º‰È::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].form = value;
	}
}

int •«î•ñŒ^::mŠ¯”N”::get()
{
	return nb6bushou[iBushouID].work;
}

void •«î•ñŒ^::mŠ¯”N”::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].work = value;
	}
}

int •«î•ñŒ^::¶”N::get()
{
	return GAMEDATASTRUCT_TENSHOUKI_GANNEN + nb6bushou[iBushouID].birth - 1;
}

void •«î•ñŒ^::¶”N::set(int value)
{
	if (GAMEDATASTRUCT_TENSHOUKI_GANNEN <= value && value <= GAMEDATASTRUCT_TENSHOUKI_GANNEN + LIMIT_BYTE_MAX)
	{
		int birth = value - GAMEDATASTRUCT_TENSHOUKI_GANNEN + 1;
		nb6bushou[iBushouID].birth = birth;
	}
}

int •«î•ñŒ^::”N—î::get()
{
	return getYearsOld(iBushouID);
}


int •«î•ñŒ^::e—ñ“`”Ô†::get()
{
	return nb6bushou[iBushouID].parent;
}

void •«î•ñŒ^::e—ñ“`”Ô†::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].parent = value;
	}
}


int •«î•ñŒ^::vl::get()
{
	return nb6bushou[iBushouID].algo;
}

void •«î•ñŒ^::vl::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].algo = value;
	}
}

int •«î•ñŒ^::‹`—::get()
{
	return nb6bushou[iBushouID].duty;
}

void •«î•ñŒ^::‹`—::set(int value)
{
	if (0 <= value && value <= 15)
	{
		nb6bushou[iBushouID].duty = value;
	}
}

int •«î•ñŒ^::‘Š«::get()
{
	return nb6bushou[iBushouID].affinity;
}

void •«î•ñŒ^::‘Š«::set(int value)
{
	if (0 <= value && value <= 15)
	{
		nb6bushou[iBushouID].affinity = value;
	}
}


bool •«î•ñŒ^::‹Z”\ˆêŠ…::get()
{
	return nb6bushou[iBushouID].tech_ikkatsu;
}

void •«î•ñŒ^::‹Z”\ˆêŠ…::set(bool value)
{
	nb6bushou[iBushouID].tech_ikkatsu = value;
}

bool •«î•ñŒ^::‹Z”\ˆÃE::get()
{
	return nb6bushou[iBushouID].tech_ansatsu;
}

void •«î•ñŒ^::‹Z”\ˆÃE::set(bool value)
{
	nb6bushou[iBushouID].tech_ansatsu = value;
}

bool •«î•ñŒ^::‹Z”\—¬o::get()
{
	return nb6bushou[iBushouID].tech_ryusyutsu;
}

void •«î•ñŒ^::‹Z”\—¬o::set(bool value)
{
	nb6bushou[iBushouID].tech_ryusyutsu = value;
}

bool •«î•ñŒ^::‹Z”\ø“®::get()
{
	return nb6bushou[iBushouID].tech_sendou;
}

void •«î•ñŒ^::‹Z”\ø“®::set(bool value)
{
	nb6bushou[iBushouID].tech_sendou = value;
}

bool •«î•ñŒ^::‹Z”\—¬Œ¾::get()
{
	return nb6bushou[iBushouID].tech_ryugen;
}

void •«î•ñŒ^::‹Z”\—¬Œ¾::set(bool value)
{
	nb6bushou[iBushouID].tech_ryugen = value;
}

bool •«î•ñŒ^::‹Z”\•Ùã::get()
{
	return nb6bushou[iBushouID].tech_benzetsu;
}

void •«î•ñŒ^::‹Z”\•Ùã::set(bool value)
{
	nb6bushou[iBushouID].tech_benzetsu = value;
}

bool •«î•ñŒ^::‹Z”\Ä“¢::get()
{
	return nb6bushou[iBushouID].tech_yakiuchi;
}

void •«î•ñŒ^::‹Z”\Ä“¢::set(bool value)
{
	nb6bushou[iBushouID].tech_yakiuchi = value;
}

bool •«î•ñŒ^::‹Z”\’§”­::get()
{
	return nb6bushou[iBushouID].tech_chohatsu;
}

void •«î•ñŒ^::‹Z”\’§”­::set(bool value)
{
	nb6bushou[iBushouID].tech_chohatsu = value;
}

int •«î•ñŒ^::E‹Æ::get()
{
	return nb6bushou[iBushouID].job;
}

void •«î•ñŒ^::E‹Æ::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::E‹Æ::‘m—µ)
	{
		nb6bushou[iBushouID].job = value;
	}
}

bool •«î•ñŒ^::‘å–C::get()
{
	return nb6bushou[iBushouID].biggun;
}

void •«î•ñŒ^::‘å–C::set(bool value)
{
	nb6bushou[iBushouID].biggun = value;
}

bool •«î•ñŒ^::‹R”n“S–C::get()
{
	return nb6bushou[iBushouID].horsegun;
}

void •«î•ñŒ^::‹R”n“S–C::set(bool value)
{
	nb6bushou[iBushouID].horsegun = value;
}

bool •«î•ñŒ^::“Sb‘D::get()
{
	return nb6bushou[iBushouID].steelship;
}

void •«î•ñŒ^::“Sb‘D::set(bool value)
{
	nb6bushou[iBushouID].steelship = value;
}

int •«î•ñŒ^::õ–½::get()
{
	return nb6bushou[iBushouID].job;
}

void •«î•ñŒ^::õ–½::set(int value)
{
	if (0 <= value && value <= 7)
	{
		nb6bushou[iBushouID].life = value;
	}
}

int •«î•ñŒ^::—E–Ò::get()
{
	return nb6bushou[iBushouID].job;
}

void •«î•ñŒ^::—E–Ò::set(int value)
{
	if (0 <= value && value <= 7)
	{
		nb6bushou[iBushouID].brave = value;
	}
}

int •«î•ñŒ^::“Æ—§::get()
{
	return getBushouIndependence(iBushouID);
}

void •«î•ñŒ^::“Æ—§::set(int value)
{
	if (0 <= value && value <= 7)
	{
		setBushouIndependence(iBushouID, value);
	}
}

int •«î•ñŒ^::Œû’²::get()
{
	return nb6bushou[iBushouID].tone;
}

void •«î•ñŒ^::Œû’²::set(int value)
{
	if (0 <= value && value <= —ñ‹“::•«::Œû’²::ˆê”Ê)
	{
		nb6bushou[iBushouID].tone = value;
	}
}


bool •«î•ñŒ^::s“®Ï::get()
{
	return nb6bushou[iBushouID].bEnd;
}

void •«î•ñŒ^::s“®Ï::set(bool value)
{
	nb6bushou[iBushouID].bEnd = value;
}

bool •«î•ñŒ^::“à‰ó‘Ô::get()
{
	return nb6bushou[iBushouID].bRise;
}

void •«î•ñŒ^::“à‰ó‘Ô::set(bool value)
{
	nb6bushou[iBushouID].bRise = value;
}

bool •«î•ñŒ^::ˆâ¦ó‘Ô::get()
{
	return nb6bushou[iBushouID].grudge;
}

void •«î•ñŒ^::ˆâ¦ó‘Ô::set(bool value)
{
	nb6bushou[iBushouID].grudge = value;
}

bool •«î•ñŒ^::‰ïŒ©Ï::get()
{
	return nb6bushou[iBushouID].kaiken;
}

void •«î•ñŒ^::‰ïŒ©Ï::set(bool value)
{
	nb6bushou[iBushouID].kaiken = value;
}

int •«î•ñŒ^::ó‘Ô::get()
{
	// íê‚Åí€‚ğ‚µ‚Ä‚¢‚Ä‚à€–S‚Ìó‘Ô‚ğ•Ô‚µ‚Ä‚¨‚­
	if (nb6bushouname[iBushouID].battleDeath) {
		return —ñ‹“::•«::ó‘Ô::€–S;
	}

	return nb6bushouname[iBushouID].State;
}

void •«î•ñŒ^::ó‘Ô::set(int value)
{
	// Œ»–ğ‚Å‚ğ˜Ql‚É‚·‚é
	if (nb6bushouname[iBushouID].State == —ñ‹“::•«::ó‘Ô::Œ»–ğ && value== —ñ‹“::•«::ó‘Ô::˜Ql) {

		setGenekiToRounin(iBushouID);
	}

	// ˜Ql‚ğŒ»–ğ‚É‚·‚é
	else if (nb6bushouname[iBushouID].State == —ñ‹“::•«::ó‘Ô::˜Ql && value == —ñ‹“::•«::ó‘Ô::Œ»–ğ) {

		setRouninToGeneki(iBushouID);
	}

}



int •«î•ñŒ^::g•ª::get()
{
	return nb6bushouname[iBushouID].position;
}

void •«î•ñŒ^::g•ª::set(int value)
{
	// ŒR’c’·‚à‚µ‚­‚ÍŒ»–ğ‚Å‚ ‚éB
	if (nb6bushouname[iBushouID].State == —ñ‹“::•«::ó‘Ô::ŒR’c’· || nb6bushouname[iBushouID].State == —ñ‹“::•«::ó‘Ô::Œ»–ğ) {

		if (—ñ‹“::•«::g•ª::h˜V <= value && value <= —ñ‹“::•«::g•ª::‘«Œy“ª) {
			nb6bushouname[iBushouID].State = value;
		}
	}
}


bool •«î•ñŒ^::Do_éå() {
	return setGenekiToJyosyu(iBushouID);
}

bool •«î•ñŒ^::Do_“]‹(int é”Ô†) {
	if (0 <= é”Ô† && é”Ô† < GAMEDATASTRUCT_CASTLE_NUM) {
		return setBushouTransport(iBushouID, é”Ô†);
	}
	else {
		return false;
	}
}

int •«î•ñŒ^::”º—µ•«”Ô†::get() {
	return getHanryoBushouID(iBushouID);
}

bool •«î•ñŒ^::Do_Œ‹¥(int ‘Šè•«”Ô†) {
	if (0 <= ‘Šè•«”Ô† && ‘Šè•«”Ô† < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iOtto = -1;
		int iHime = -1;
		// ‘Šè•«”Ô†‚ª•P
		if (nb6bushouname[‘Šè•«”Ô†].State == —ñ‹“::•«::ó‘Ô::•P) {
			iHime = ‘Šè•«”Ô†;
			iOtto = iBushouID;
			setHimeMarriage(iHime, iOtto, true);
		}
		// ©•ª‚ª•P
		else if(nb6bushouname[iBushouID].State == —ñ‹“::•«::ó‘Ô::•P) {
			iHime = iBushouID;
			iOtto = ‘Šè•«”Ô†;
			setHimeMarriage(iHime, iOtto, true);
		}
		else {
			return false;
		}
		
	}

	return false;

}

bool •«î•ñŒ^::Do_—£¥() {
	int iHime = -1;
	// ©•ª‚ª•P
	if (nb6bushouname[iBushouID].State == —ñ‹“::•«::ó‘Ô::•P) {
		iHime = iBushouID;
		setHimeDivorce(iHime, true);
	}
	// ©•ª‚Í•P‚Å‚Í‚È‚¢B
	else if (nb6bushouname[iBushouID].State != —ñ‹“::•«::ó‘Ô::•P) {
		// È‚Í‹‚È‚¢B
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

int •«î•ñŒ^::Get_‘Š«·(int ‘Šè•«”Ô†) {
	if (0 <= ‘Šè•«”Ô† && ‘Šè•«”Ô† < GAMEDATASTRUCT_BUSHOU_NUM) {
		return getBushouAishoDiff(iBushouID, ‘Šè•«”Ô†);
	}
	else {
		return 8; // Åˆ«‚Ì‘Š«·‚ğ•Ô‚µ‚Ä‚¨‚­B
	}
}

bool •«î•ñŒ^::Is_ƒvƒŒƒCƒ„Ÿ€‰º•«::get() {
	return isPlayerBushou(iBushouID);
}

bool •«î•ñŒ^::Is_ƒvƒŒƒCƒ„’S“–•«::get() {
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

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì–º(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì–º(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì‘§q(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì‘§q(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ìq(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ìq(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ìe(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ìe(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì•ƒ(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì•ƒ(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ì•ƒ(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ì•ƒ(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì•ê(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì•ê(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ì•ê(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ì•ê(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì’í(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì’í(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ì’í(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ì’í(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì–…(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì–…(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ì–…(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ì–…(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚ÌŒZ(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚ÌŒZ(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚ÌŒZ(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚ÌŒZ(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ìo(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ìo(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ìo(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ìo(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Æ‘Šè‚ÍŒZ’í(int ‘Šè•«”Ô†) {
	return is©•ª‚Æ‘Šè‚ÍŒZ’í(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Æ‘Šè‚Ío–…(int ‘Šè•«”Ô†) {
	return is©•ª‚Æ‘Šè‚Ío–…(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Æ‘Šè‚Ío’í(int ‘Šè•«”Ô†) {
	return is©•ª‚Æ‘Šè‚Ío’í(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Æ‘Šè‚ÍŒZ–…(int ‘Šè•«”Ô†) {
	return is©•ª‚Æ‘Šè‚ÍŒZ–…(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚Ì•v(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚Ì•v(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚ÌÈ(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚ÌÈ(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Í‘Šè‚ÌŒŒ‰(int ‘Šè•«”Ô†) {
	return is©•ª‚Í‘Šè‚ÌŒŒ‰(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ì‰Æb(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ì‰Æb(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_‘Šè‚Í©•ª‚Ì‘å–¼(int ‘Šè•«”Ô†) {
	return is‘Šè‚Í©•ª‚Ì‘å–¼(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::Is_©•ª‚Æ‘Šè‚Í“¯‚¶‘å–¼‰ÆŠ‘®(int ‘Šè•«”Ô†) {
	return is©•ª‚Æ‘Šè‚Í“¯‚¶‘å–¼‰ÆŠ‘®(iBushouID, ‘Šè•«”Ô†);
}

bool •«î•ñŒ^::í‘ˆ•«î•ñŒ^::‘Ş‹pÏ::get()
{
	return nb6bushouname[iBushouID].battleRetreat;
}

int •«î•ñŒ^::í‘ˆ•«î•ñŒ^::Qí—§ê::get() {
	return GetWarStandPointTheBushou(iBushouID);
}

int •«î•ñŒ^::í‘ˆ•«î•ñŒ^::¬—ó‘Ô::get() {
	return GetKonranStatus(iBushouID);
}

bool •«î•ñŒ^::í‘ˆ•«î•ñŒ^::s“®Ï::get() {
	if (IsActionEndInBattle(iBushouID)) {
		return true;
	}
	return false;
}

int •«î•ñŒ^::í‘ˆ•«î•ñŒ^::‹@“®—Í::get() {
	return GetBushouMovePower(iBushouID);
}

void •«î•ñŒ^::í‘ˆ•«î•ñŒ^::‹@“®—Í::set(int value) {
	if ( 0 <= value && value < 100 ) {
		SetBushouMovePower(iBushouID, value);
	}
}


bool •«î•ñŒ^::í‘ˆ•«î•ñŒ^::ow’†::get() {
	vector<int> list = GetSyutujinBushouArray();
	for each (int iBID in list) {
		if (iBID == iBushouID) {
			return true;
		}
	}
	return false;
}

bool •«î•ñŒ^::í‘ˆ•«î•ñŒ^::ow’†_•\¦íê::get() {
	vector<int> list = GetCurMapSyutujinBushouArray();
	for each (int iBID in list) {
		if (iBID == iBushouID) {
			return true;
		}
	}
	return false;
}

ƒwƒbƒNƒXˆÊ’uŒ^^ •«î•ñŒ^::í‘ˆ•«î•ñŒ^::ƒwƒbƒNƒXˆÊ’u::get() {
	ƒwƒbƒNƒXˆÊ’uŒ^^ pos = gcnew ƒwƒbƒNƒXˆÊ’uŒ^();
	if (Is_FieldWar()) {
		HEX_POSITION p = GetFieldHexUnitPos(iBushouID);
		pos->‚w = p.x;
		pos->‚x = p.y;
	}
	else {
		pos->‚w = 0xFFFF;
		pos->‚x = 0xFFFF;
	}

	return pos;
}


•«ƒŠƒXƒgî•ñŒ^::•«ƒŠƒXƒgî•ñŒ^() {

	”z—ñ = gcnew List<•«î•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_BUSHOU_NUM; i++)
	{
		”z—ñ->Add(gcnew •«î•ñŒ^(i));
	}

	í‘ˆ = gcnew í‘ˆ•«ƒŠƒXƒgî•ñŒ^();
}

int •«ƒŠƒXƒgî•ñŒ^::Find_•«”Ô†(int —ñ“`”Ô†) {
	int iBushouID = getBushouIDFromFaceID(—ñ“`”Ô†);
	return iBushouID;
}

int •«ƒŠƒXƒgî•ñŒ^::Find_•«”Ô†(String^ ©–¼) {

	for (int i = 0; i < GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (©–¼ == gcnew String(nb6bushouname[i].familyname) + gcnew String(nb6bushouname[i].fastname) ) {
			return i;
		}
	}

	return 0xFFFF;
}

List<int>^ •«ƒŠƒXƒgî•ñŒ^::í‘ˆ•«ƒŠƒXƒgî•ñŒ^::ow’†_•«”Ô†ƒŠƒXƒg::get() {
	vector<int> list = GetSyutujinBushouArray();
	List<int>^ m_list = gcnew List<int>();
	for each (int iBID in list) {
		m_list->Add(iBID);
	}
	return m_list;
}

List<int>^ •«ƒŠƒXƒgî•ñŒ^::í‘ˆ•«ƒŠƒXƒgî•ñŒ^::ow’†_•\¦íê_•«”Ô†ƒŠƒXƒg::get() {
	vector<int> list = GetCurMapSyutujinBushouArray();
	List<int>^ m_list = gcnew List<int>();
	for each (int iBID in list) {
		m_list->Add(iBID);
	}
	return m_list;
}

