
/*

野戦マップ読込時!!
戦争が始まって、野戦マップの画面へと実際に変わり始めた時に、ここを通過する。


この時のベースアドレス
00871000   56               PUSH ESI

0095F120   C705 D8DBBE00 00000000        MOV DWORD PTR DS:[BEDBD8],0
0095F12A   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
0095F134   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095F13E   C705 0068BD00 03000000        MOV DWORD PTR DS:[BD6800],3
0095F148   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095F152   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095F15C   E8 5F160300                   CALL NOBU6HD_.009907C0

*/


#include "GameDataStruct.h"

extern BOOL isCountValidOfChangeFieldWarTurnExecute;

static void OnTenshouExeFieldWarStart02Execute() {
	isFieldWarOrCastleWar = warstatus::野戦表示突入前; //野戦が始まった。出陣前
	isCountValidOfChangeFieldWarTurnExecute = TRUE;

	デバッグ出力 << "FieldWarStart02 野戦マップ読込時" << endl;
	
	try {
		// ユーザークラスがエラー
		if (ユーザークラス::IsErrorUserVersionDLL()) {
			throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
		}

		//メソッドの情報を取得 
		MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_戦争参加勢力決定直後");
		if (!method) {
			throw gcnew Exception("ユーザー天翔記クラス My_戦争参加勢力決定直後 メソッド未実装");
		}

		デバッグ出力 << "ユーザー天翔記クラス::My_戦争参加勢力決定直後" << endl;

		// 引数無しで実行
		method->Invoke(nullptr, nullptr);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_戦争参加勢力決定直後" << endl;
		天翔記クラス::On_戦争参加勢力決定直後();
	}


}

/*
この時のベースアドレス
00871000   56               PUSH ESI

0095F120   C705 D8DBBE00 00000000        MOV DWORD PTR DS:[BEDBD8],0
0095F12A   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
└ここを JMP TSMod.OnTSExeFieldWarStart02 と書き換えてやる実際の処理。10バイトの書き換え
0095F134   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095F13E   C705 0068BD00 03000000        MOV DWORD PTR DS:[BD6800],3
0095F148   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095F152   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095F15C   E8 5F160300                   CALL NOBU6HD_.009907C0


00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29]  [17]=経過ターン数と[02]=天気  0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..　(攻城戦の時は、横が0x12=18,  縦が0x10=16)
*/


static int pTenshouExeJumpFromToOnTenshouExeFieldWarStart02 = 0x95F12A - 0x870000;   // 関数はこのアドレスから、OnTenshouExeFieldWarStart02へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeFieldWarStart02 = 0x95F134 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w

static int iEAXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeFieldWarStart02() {
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

	
	OnTenshouExeFieldWarStart02Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeFieldWarStart02
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeFieldWarStart02() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeFieldWarStart02,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeFieldWarStart02,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeFieldWarStart02,	    // ここへと戻る
		10													// 10バイト
		);
}


