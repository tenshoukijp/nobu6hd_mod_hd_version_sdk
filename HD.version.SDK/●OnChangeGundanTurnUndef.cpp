#include "GameDataStruct.h"

/*
軍団ターンを0xFFFFといったように、誰のターンでも無いものへと切り替えた時

この時のベースアドレス
00871000   56               PUSH ESI

0099BCFC   CC               INT3
0099BCFD   CC               INT3
0099BCFE   CC               INT3
0099BCFF   CC               INT3
0099BD00   B8 FFFF0000      MOV EAX,0FFFF
0099BD05   66:A3 DFF8BC00   MOV WORD PTR DS:[BCF8DF],AX			← ここ。FFFFとなる。
0099BD0B   C3               RETN


00BCF8DD  19 00 [23] 00 FF FF 1D 00 01 00 39 00 25 00 31 00
00BCF8ED  34 00 02 00 08 00 23 00 30 00 12 00 14 00 28 00
00BCF8FD  0A 00 1B 00 0D 00 1A 00 03 00 04 00 11 00 32 00
*/




static void OnTenshouExeChangeGundanTurnUndefExecute() {

	try {
		// ユーザークラスがエラー
		if (ユーザークラス::IsErrorUserVersionDLL()) {
			throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
		}

		//１つパラメータの型を配列に入れる 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
		types[0] = int::typeid;

		//メソッドの情報を取得 
		MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_戦略_軍団ターン変更時", types);
		if (!method) {
			throw gcnew Exception("ユーザー天翔記クラス My_戦略_軍団ターン変更時 メソッド未実装");
		}

		//１つのパラメタを実際に入れる
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
		prms[0] = 0xFFFF;

		デバッグ出力 << "ユーザー天翔記クラス::My_戦略_軍団ターン変更時" << endl;

		// 返り値無しで実行
		method->Invoke(nullptr, prms);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_戦略_軍団ターン変更時" << endl;
		天翔記クラス::On_戦略_軍団ターン変更時(0xFFFF);
	}

}

/*
この時のベースアドレス
00871000   56               PUSH ESI

0099BCFC   CC               INT3
0099BCFD   CC               INT3
0099BCFE   CC               INT3
0099BCFF   CC               INT3
0099BD00   B8 FFFF0000      MOV EAX,0FFFF
0099BD05   66:A3 DFF8BC00   MOV WORD PTR DS:[BCF8DF],AX			← ここ。FFFFとなる。 6バイト書き換え
└ここを JMP TSMod.OnTSExeChangeGundanTurnUndef と書き換えてやる実際の処理
0099BD0B   C3               RETN

*/
static int pTenshouExeJumpFromToOnTenshouExeChangeGundanTurnUndef = 0x99BD05 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeChangeGundanTurnUndefへとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurnUndef = 0x99BD0B - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																						 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOFTemp = 0;
																						 // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeGundanTurnUndef() {
	// スタックにためておく
	__asm {
		// eax間借り
		mov iEAXOFTemp, eax
		mov eax, nb6turn_gundan_ptr

		// 元々の処理をここに記述
		MOV WORD PTR DS : [eax], AX

		// eax戻す
		mov eax, iEAXOFTemp

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeGundanTurnUndefExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurnUndef
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeChangeGundanTurnUndef() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeGundanTurnUndef,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeChangeGundanTurnUndef,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurnUndef,	    // ここへと戻る
		6															// 6バイト書き換え
		);
}


