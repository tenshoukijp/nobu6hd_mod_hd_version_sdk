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

0097316F   CC               INT3
00973170   55               PUSH EBP
00973171   8BEC             MOV EBP,ESP
00973173   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
00973176   A3 EA67BD00      MOV DWORD PTR DS:[BD67EA],EAX    ← ターン数の代入
0097317B   5D               POP EBP
0097317C   C3               RETN
* /

/*
ベース
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  ・O・
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=経過ターン数と[02]=天気  0x29=41とは野戦の横のHEX数のこと  0x12の時は攻籠戦のHEX数の横のマス数である18のこと。
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
*/


int iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;

BOOL isCountValidOfChangeFieldWarTurnExecute = FALSE;
static void OnTenshouExeChangeFieldWarTurnExecute() {

	if (isCountValidOfChangeFieldWarTurnExecute) {
		デバッグ出力 << "野戦ターンの変化:" << iFieldTurnOfChangeFieldWarTurnExecute << endl;

		try {
			// ユーザークラスがエラー
			if (ユーザークラス::IsErrorUserVersionDLL()) {
				throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
			}

			//１つパラメータの型を配列に入れる 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
			types[0] = int::typeid;

			//メソッドの情報を取得 
			MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_戦争_残りターン変更時", types);
			if (!method) {
				throw gcnew Exception("ユーザー天翔記クラス My_戦争_残りターン変更時 メソッド未実装");
			}

			//１つのパラメタを実際に入れる
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
			prms[0] = getFieldTurnInBattle();

			デバッグ出力 << "ユーザー天翔記クラス::My_戦争_残りターン変更時" << endl;

			// 返り値無しで実行
			method->Invoke(nullptr, prms);
		}

		// エラーなので内部のものを実行する。
		catch (Exception^) {
			デバッグ出力 << "天翔記クラス::On_戦争_残りターン変更時" << endl;
			天翔記クラス::On_戦争_残りターン変更時(getFieldTurnInBattle());
		}


	}

}

/*
ベース
00871000   56               PUSH ESI

0097316F   CC               INT3
00973170   55               PUSH EBP
00973171   8BEC             MOV EBP,ESP
00973173   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
00973176   A3 EA67BD00      MOV DWORD PTR DS:[BD67EA],EAX    ← ターン数の代入
└ここを JMP TSMod.OnTSExeChangeFieldWarTurn と書き換えてやる実際の処理。
0097317B   5D               POP EBP
0097317C   C3               RETN
*/
static int pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurn = 0x973176 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeChangeFieldWarTurnへとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurn = 0x97317B - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																					  // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEBXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeFieldWarTurn() {
	// スタックにためておく
	__asm {
		// ebx間借り
		mov iEBXOFTemp, ebx
		mov ebx, nb6battle_field_turn

		// 元々の処理をここに記述
		MOV DWORD PTR DS : [ebx], eax

		// ebx戻す
		mov ebx, iEBXOFTemp

		mov iFieldTurnOfChangeFieldWarTurnExecute, eax  // これターン数なので保存しておく

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeFieldWarTurnExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurn
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeChangeFieldWarTurn() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeFieldWarTurn,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurn,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurn	    // ここへと戻る
		);
}



