#include "GameDataStruct.h"

/*
軍団ターンを切り替えた時

ベース
この時のベースアドレス
00871000   56               PUSH ESI


0099C26C   0F46D0           CMOVBE EDX,EAX
0099C26F   66:8915 DFF8BC00 MOV WORD PTR DS:[BCF8DF],DX			← ここに軍団番号が入ってるはず
0099C276   5E               POP ESI
0099C277   5D               POP EBP
0099C278   C3               RETN



00BCF8DD  19 00 [23] 00 FF FF 1D 00 01 00 39 00 25 00 31 00 
00BCF8ED  34 00 02 00 08 00 23 00 30 00 12 00 14 00 28 00  
00BCF8FD  0A 00 1B 00 0D 00 1A 00 03 00 04 00 11 00 32 00 

*/


WORD iGundanIDOfChangeGundanTurnExecute = 0xFFFF;

static void OnTenshouExeChangeGundanTurnExecute() {
	int iGundanID = (int)iGundanIDOfChangeGundanTurnExecute - 1;
	if (iGundanID >= 0xFFFE) {
		iGundanID = 0xFFFF;
	}

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
		prms[0] = iGundanID;

		デバッグ出力 << "ユーザー天翔記クラス::My_戦略_軍団ターン変更時" << endl;

		// 返り値無しで実行
		method->Invoke(nullptr, prms);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_戦略_軍団ターン変更時" << endl;
		天翔記クラス::On_戦略_軍団ターン変更時(iGundanID);

	}


}

/*
この時のベースアドレス
00871000   56               PUSH ESI


0099C26C   0F46D0           CMOVBE EDX,EAX
0099C26F   66:8915 DFF8BC00 MOV WORD PTR DS:[BCF8DF],DX			← ここに軍団番号が入ってるはず
└ここを JMP TSMod.OnTSExeChangeGundanTurn と書き換えてやる実際の処理
0099C276   5E               POP ESI
0099C277   5D               POP EBP
0099C278   C3               RETN

*/
static int pTenshouExeJumpFromToOnTenshouExeChangeGundanTurn = 0x99C26F - 0x870000;   // 関数はこのアドレスから、OnTenshouExeChangeGundanTurnへとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurn = 0x99C276 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																					// この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOFTemp = 0;
// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeGundanTurn() {
	// スタックにためておく
	__asm {
		// eax間借り
		mov iEAXOFTemp, eax
		mov eax, nb6turn_gundan_ptr

		// 元々の処理をここに記述
		MOV WORD PTR DS : [eax], DX

		// eax戻す
		mov eax, iEAXOFTemp

		// 軍団番号の保存
		mov iGundanIDOfChangeGundanTurnExecute, DX;

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeGundanTurnExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurn
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeChangeGundanTurn() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeGundanTurn,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeChangeGundanTurn,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurn,	    // ここへと戻る
		7														// 7バイト書き換え
		);
}


