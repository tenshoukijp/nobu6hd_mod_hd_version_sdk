
/*

戦争開始時とほぼ同じようなタイミングで読み込まれる。

この時のベースアドレス
00811000   56               PUSH ESI

008FDC7C   C705 D0DBB800 00000000                          MOV DWORD PTR DS : [B8DBD0], 0
008FDC86   C705 F867B700 29000000                          MOV DWORD PTR DS : [B767F8], 29		← 野戦の横マス
008FDC90   C705 FC67B700 18000000                          MOV DWORD PTR DS : [B767FC], 18	　　← 野戦の縦マス
008FDC9A   C705 0068B700 03000000                          MOV DWORD PTR DS : [B76800], 3
008FDCA4   C705 0468B700 D8030000                          MOV DWORD PTR DS : [B76804], 3D8
008FDCAE   C705 C8DBB800 FFFF0000                          MOV DWORD PTR DS : [B8DBC8], 0FFFF
*/


#include "GameDataStruct.h"

static void OnTenshouExeFieldWarStart01Execute() {
	デバッグ出力 << "FieldWarStart01 野戦マップ読込時" << endl;
	// 戦争開始パラメタ型^ param = gcnew 戦争開始パラメタ型();
	// int iCastleID = GetWarCenterCastle();
	// 天翔記クラス::On_戦争開始時(iCastleID, param);
}

/*
この時のベースアドレス
00871000   56               PUSH ESI

0095DCCC   C705 D8DBBE00 00000000        MOV DWORD PTR DS:[BEDBD8],0
0095DCD6   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29   ← 野戦の横マス
└ここを JMP TSMod.OnTSExeFieldWarStart01 と書き換えてやる実際の処理。10バイトの書き換え
0095DCE0   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18   ← 野戦の縦マス
0095DCEA   C705 0068BD00 03000000        MOV DWORD PTR DS:[BD6800],3
0095DCF4   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8      ← 0x29 x 0x18のこと
0095DCFE   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095DD08   E8 B32A0300                   CALL NOBU6HD_.009907C0
0095DD0D   A3 A4DBBE00                   MOV DWORD PTR DS:[BEDBA4],EAX

ベース
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29]  [17]=経過ターン数と[02]=天気  0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..　(攻城戦の時は、横が0x12=18,  縦が0x10=16)
*/

static int pTenshouExeJumpFromToOnTenshouExeFieldWarStart01 = 0x95DCD6 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeFieldWarStart01へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeFieldWarStart01 = 0x95DCE0 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w

static int iEAXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeFieldWarStart01() {
	// スタックにためておく
	__asm {
		mov iEAXOFTemp, eax
		mov eax, nb6hex_xy

		// 元々の処理をここに記述
		MOV DWORD PTR DS : [eax], 0x29

		// eaxを戻す。
		mov eax, iEAXOFTemp

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeFieldWarStart01Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeFieldWarStart01
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeFieldWarStart01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeFieldWarStart01,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeFieldWarStart01,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeFieldWarStart01,	    // ここへと戻る
		10													// 10バイト
		);
}


