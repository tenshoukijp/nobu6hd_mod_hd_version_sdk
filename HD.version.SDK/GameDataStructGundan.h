#pragma once

/*			ŒR’cî•ñ(21*214)

[21ƒoƒCƒg]

0-1	‘O‚ÌŒR’c
2-3 Œã‚ë‚ÌŒR’c
4-5	‹é–¼ƒiƒ“ƒo[
6-7	ŒR’c’·ƒiƒ“ƒo[(•«–¼‘Oƒe[ƒuƒ‹‚Ì‡”Ô)
8-9	‘å–¼
10	s“®—Í
11-12	‹à
13-14	•Ä
15-16	‹R”n
17-18	“S–C
19	H
20	aaaabbbb A –ğE B ŒR’c”Ô†
0 –³‚µ 1 ªˆÎ‘å«ŒR 2 ŠÇ—Ì 3 ŠÖ“ŒŠÇ—Ì 4 ‰œB’T‘è 5 ¼‘’T‘è 6 ‹ãB’T‘è 7 ‰HB’T‘è Ë getNormalizedGundanPosition

*/
struct NB6GUNDAN
{
	WORD prev;		//‘O‚ÌŒR’c
	WORD next;		//Œã‚ë‚ÌŒR’c
	WORD residence;	//‹é–¼ƒiƒ“ƒo[
	WORD leader;	//ŒR’c’·ƒiƒ“ƒo[(•«–¼‘Oƒe[ƒuƒ‹‚Ì‡”Ô)
	WORD attach;	//Š‘®(‘å–¼) (‘å–¼”Ô†ƒe[ƒuƒ‹‚Ì‡”Ô)
	byte act;		//s“®—Í
	WORD money;		//‹à
	WORD rise;		//•Ä
	WORD horse;		//”n
	WORD gun;		//“S–C
	byte _undef;	//must 0?
	byte number : 4;	//1-8 Ë ŒR’c”Ô†
	byte position : 4;//–ğE  (0 –³‚µ 1 ªˆÎ‘å«ŒR 2 ŠÇ—Ì 3 ŠÖ“ŒŠÇ—Ì 4 ‰œB’T‘è 5 ¼‘’T‘è 6 ‹ãB’T‘è 7 ‰HB’T‘è) Ë getNormalizedGundanPosition
};


/// Œ»İ(‚»‚ÌuŠÔ)A“VãÄ‹L‚É‘¶İ‚·‚éŒR’c‚ÌuŒR’c”Ô†y”z—ñ—pzv‚ğƒŠƒXƒg‚Å“¾‚éB
vector<int> getValidGundanList();

// “¯‚¶‘å–¼‚É‘®‚·‚éŒR’c”Ô†y”z—ñ—pz‚ÌƒŠƒXƒg‚ğ“¾‚é
vector<int> getGovernedGundanList(int iDaimyoID);

// ŒR’c‚ÉŠ‘®‚·‚é•«ƒŠƒXƒg‚ğ“¾‚é
vector<int> getGundanBushouList(int iGundanID);

// ŒR’c‚ÉŠ‘®‚·‚é•º”‚ğ“¾‚é
int getGundanHeisuCnt(int iGundanID);

// ‚Æ‚ ‚é‘å–¼¨—Í‚Ì“¡ŒR’cŠ„‚è‚ ‚Ä”Ô†ƒŠƒXƒg‚ğ“¾‚éB
vector<int> getGovernedGundanWariateNumList(int iDaimyoID);

// ‚Æ‚ ‚é‘å–¼”z‰º‚ÌŒR’c‰º‚É‚ ‚éŒR’cu–¢vŠ„“–”Ô†‚ÌƒŠƒXƒg‚ğ“¾‚éB
vector<int> getNotGovernedGundanWariateNumList(int iDaimyoID);

// ŒR’c”C–½”Ô†‚Ì•ÏX(“ü‘Ö)‚ğ‚İ‚éB¸”s‚·‚ê‚Îfalse
bool tryChangeGundanWariateNum(int iGundanID, int iNewWariateNum);

// w’è‚ÌŒR’c‚ÌŠ‘®‚·‚é‘å–¼‚ğ¨—Í‚ğ‰z‚¦‚ÄA•ÏX‚·‚éB
bool setGundanReAttachDaimyo(int iGundanID, int iNewDaimyoID);

