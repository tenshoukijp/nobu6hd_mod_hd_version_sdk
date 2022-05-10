#include "GameDataStruct.h"

/*
戦争終了もしくは、戦争ではない状態とする。

00871000   56               PUSH ESI

References in NOBU6HD_:.text to 00BD67E0..00BD67E0
Address    Disassembly                               Comment
00973025   MOV WORD PTR DS:[BD67E0],AX				← ここはクリアの場
00973070   MOV AX,WORD PTR DS:[BD67E0]               [00BD67E0]=005A
009730D3   MOV WORD PTR DS:[BD67E0],CX				← ここは戦争開始時に中心点の城番号が入る場所

00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF だと戦争していない、FFFF以外だと、戦場の中心となっている「城番号」が入っている。
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (攻城戦の時は、横が0x12=18,  縦が0x10=16)

00BD67DA  95 00 A0 4F 95 00 [5A 00] 14 00 00 00 05 00 00 00
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 [29: 00
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .

ベース
00871000   56               PUSH ESI

00973020   B8 FFFF0000      MOV EAX,0FFFF
00973025   66:A3 E067BD00   MOV WORD PTR DS:[BD67E0],AX
0097302B   C3               RETN

*/


extern BOOL isCountValidOfChangeFieldWarTurnExecute;


static void OnTenshouExeBattleClearExecute() {
	// 野戦か籠城戦かの情報を降ろす
	isFieldWarOrCastleWar = -1;
	isCountValidOfChangeFieldWarTurnExecute = FALSE;

	// 経過ターン数をリセット
	iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;


	if ( IsDoingWar() ) {

		try {
			// ユーザークラスがエラー
			if (ユーザークラス::IsErrorUserVersionDLL()) {
				throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
			}

			//メソッドの情報を取得 
			MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_戦争終了時");
			if (!method) {
				throw gcnew Exception("ユーザー天翔記クラス My_戦争終了時 メソッド未実装");
			}

			デバッグ出力 << "ユーザー天翔記クラス::My_戦争終了時" << endl;

			// 引数無しで実行
			method->Invoke(nullptr, nullptr);
		}

		// エラーなので内部のものを実行する。
		catch (Exception^) {
			デバッグ出力 << "天翔記クラス::On_戦争終了時" << endl;
			天翔記クラス::On_戦争終了時();
		}


		デバッグ出力 << "戦争終了" << endl;
	}
	else {
		デバッグ出力 << "戦闘前のクリア" << endl;
	}
}

/*
ベース
00871000   56               PUSH ESI

00973020   B8 FFFF0000      MOV EAX,0FFFF
00973025   66:A3 E067BD00   MOV WORD PTR DS:[BD67E0],AX
└ここを JMP TSMod.OnTSExeBattleClear と書き換えてやる実際の処理。7バイトの書き換え
0097302B   C3               RETN

00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF だと戦争していない、FFFF以外だと、戦場の中心となっている「城番号」が入っている。
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (攻城戦の時は、横が0x12=18,  縦が0x10=16)

00BD67DA  95 00 A0 4F 95 00 [5A 00] 14 00 00 00 05 00 00 00
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 [29: 00
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .

*/
static int pTenshouExeJumpFromToOnTenshouExeBattleClear = 0x973025 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeBattleClearへとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeBattleClear = 0x97302B - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
												
static int iEBXOFTemp = 0;
																			 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeBattleClear() {
	// スタックにためておく
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeBattleClearExecute();

	// スタックに引き出す
	__asm {

		POPFD
		POPAD

		// eaxを一時的に使って、上の0xB767E0相当の値を入れる
		mov iEBXOFTemp, ebx
		mov ebx, nb6battle_center_castle

		// 元々の処理をここに記述
		MOV WORD PTR DS : [ebx], AX

		// eaxを戻す。
		mov ebx, iEBXOFTemp


		jmp pTenshouExeRetnBacktoOnTenshouExeBattleClear
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeBattleClear() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeBattleClear,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeBattleClear,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeBattleClear,	    // ここへと戻る
		6												// 7バイト
		);
}


