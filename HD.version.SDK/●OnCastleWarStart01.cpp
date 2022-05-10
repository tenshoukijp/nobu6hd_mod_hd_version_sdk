
/*

籠城戦切り替え時に切り替わる度に呼ばれる

この時のベースアドレス
00871000   56               PUSH ESI

0095FC98   69C0 60030000              IMUL EAX,EAX,360
0095FC9E   05 28080000                ADD EAX,828
0095FCA3   C705 F867BD00 12000000     MOV DWORD PTR DS:[BD67F8],12
0095FCAD   C705 FC67BD00 10000000     MOV DWORD PTR DS:[BD67FC],10
0095FCB7   C705 0468BD00 20010000     MOV DWORD PTR DS:[BD6804],120
0095FCC1   50                         PUSH EAX


*/


#include "GameDataStruct.h"

extern int isFieldWarOrCastleWar;
static void OnTenshouExeCastleWarStart01Execute() {
	isFieldWarOrCastleWar = warstatus::城表示突入前;
	デバッグ出力 << "CastleWarStart01 籠城戦有効化直前:" << endl;
	// 戦争開始パラメタ型^ param = gcnew 戦争開始パラメタ型();
	// int iCastleID = GetWarCenterCastle();
	// 天翔記クラス::On_戦争開始時(iCastleID, param);
}

/*
この時のベースアドレス
00871000   56               PUSH ESI

0095FC98   69C0 60030000              IMUL EAX,EAX,360
0095FC9E   05 28080000                ADD EAX,828
0095FCA3   C705 F867BD00 12000000     MOV DWORD PTR DS:[BD67F8],12    籠城戦の横ます
└ここを JMP TSMod.OnTSExeCastleWarStart01 と書き換えてやる実際の処理。10バイトの書き換え
0095FCAD   C705 FC67BD00 10000000     MOV DWORD PTR DS:[BD67FC],10    籠城戦の縦マス		
0095FCB7   C705 0468BD00 20010000     MOV DWORD PTR DS:[BD6804],120   籠城戦の縦ｘ横マス	
0095FCC1   50                         PUSH EAX
*/

/*
ベース
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  ・O・
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=経過ターン数と[02]=天気  0x29=41とは野戦の横のHEX数のこと  0x12の時は攻籠戦のHEX数の横のマス数である18のこと。
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
*/

static int pTenshouExeJumpFromToOnTenshouExeCastleWarStart01 = 0x95FCA3 - 0x870000; // 関数はこのアドレスから、OnTenshouExeCastleWarStart01へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCastleWarStart01 = 0x95FCAD - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w

static int iEAXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCastleWarStart01() {
	// スタックにためておく
	__asm {

		mov iEAXOFTemp, eax
		mov eax, nb6hex_xy

		// 元々の処理をここに記述
		MOV DWORD PTR DS : [eax], 0x12

		// eaxを戻す。
		mov eax, iEAXOFTemp

		
		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCastleWarStart01Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCastleWarStart01
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCastleWarStart01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCastleWarStart01,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCastleWarStart01,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCastleWarStart01,	    // ここへと戻る
		10													// 10バイト
		);
}


