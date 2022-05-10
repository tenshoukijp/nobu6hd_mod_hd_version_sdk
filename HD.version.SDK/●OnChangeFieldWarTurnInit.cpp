#include "GameDataStruct.h"



/*
ベース
00871000   56               PUSH ESI

戦場での経過ターン数
References in NOBU6HD_:.text to 00BD67EA..00BD67EA
Address    Disassembly                               Comment
00973040   MOV DWORD PTR DS:[BD67EA],0               DS:[00BD67EA]=0000000D  ← ここにターン数の値をクリアしている。
00973090   MOV EAX,DWORD PTR DS:[BD67EA]             [00BD67EA]=0000000D
00973176   MOV DWORD PTR DS:[BD67EA],EAX                                     ← ここにターン数の値が代入されている。

0097303F   CC                                    INT3
00973040   C705 EA67BD00 00000000                MOV DWORD PTR DS:[BD67EA],0
0097304A   C3                                    RETN
0097304B   CC                                    INT3

* /

/*
ベース
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  ・O・
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=経過ターン数と[02]=天気  0x29=41とは野戦の横のHEX数のこと  0x12の時は攻籠戦のHEX数の横のマス数である18のこと。
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
*/





static void OnTenshouExeChangeFieldWarTurnInitExecute() {
	デバッグ出力 << "野戦ターンの初期化" << endl;
	// 天翔記クラス::On_軍団ターン変更《戦略画面》(0xFFFF);

}

/*
この時のベースアドレス
00871000   56               PUSH ESI

00973040   C705 EA67BD00 00000000                MOV DWORD PTR DS:[BD67EA],0
└ここを JMP TSMod.OnTSExeChangeFieldWarTurnInit と書き換えてやる実際の処理。10バイトの書き換え
0097304A   C3                                    RETN
*/
static int pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurnInit = 0x973040 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeChangeFieldWarTurnInitへとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurnInit = 0x97304A - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																						  // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeFieldWarTurnInit() {
	// スタックにためておく
	__asm {
		// eax間借り
		mov iEAXOFTemp, eax
		mov eax, nb6battle_field_turn

		// 元々の処理をここに記述
		MOV DWORD PTR DS : [eax], 0

		// eax戻す
		mov eax, iEAXOFTemp

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeFieldWarTurnInitExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurnInit
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeChangeFieldWarTurnInit() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeFieldWarTurnInit,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurnInit,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurnInit,	    // ここへと戻る
		10															    // 10バイト書き換え
		);
}



