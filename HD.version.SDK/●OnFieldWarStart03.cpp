
/*
野戦マップへの切り替え時!!
毎ターンの切り替わり時にここを通過する。
★★ここは重要!!

この時のベースアドレス
00871000   56               PUSH ESI

0095FC66   75 2B                         JNZ SHORT NOBU6HD_.0095FC93
0095FC68   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
0095FC72   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095FC7C   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095FC86   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095FC90   50                            PUSH EAX
0095FC91   EB 2F                         JMP SHORT NOBU6HD_.0095FCC2
*/


#include "GameDataStruct.h"

static void OnTenshouExeFieldWarStart03Execute() {
	isFieldWarOrCastleWar = warstatus::野戦ターン時; //野戦で入力可能となった。
	デバッグ出力 << "FieldWarStart03 野戦マップ有効化直前" << endl;
	// 戦争開始パラメタ型^ param = gcnew 戦争開始パラメタ型();
	// int iCastleID = GetWarCenterCastle();
	// 天翔記クラス::On_戦争開始時(iCastleID, param);
}

/*
この時のベースアドレス
00871000   56               PUSH ESI

0095FC68   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
└ここを JMP TSMod.OnTSExeFieldWarStart03 と書き換えてやる実際の処理。10バイトの書き換え
0095FC72   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095FC7C   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095FC86   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095FC90   50                            PUSH EAX


00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29]  [17]=経過ターン数と[02]=天気  0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..　(攻城戦の時は、横が0x12=18,  縦が0x10=16)
*/


static int pTenshouExeJumpFromToOnTenshouExeFieldWarStart03 = 0x95FC68 - 0x870000; // 関数はこのアドレスから、OnTenshouExeFieldWarStart03へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeFieldWarStart03 = 0x95FC72 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w

static int iEAXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeFieldWarStart03() {
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

	
	OnTenshouExeFieldWarStart03Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeFieldWarStart03
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeFieldWarStart03() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeFieldWarStart03,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeFieldWarStart03,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeFieldWarStart03,	    // ここへと戻る
		10													// 10バイト
	);
}


