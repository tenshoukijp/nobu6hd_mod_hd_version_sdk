
/*
戦争開始

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

戦争開始時に通過するポイント
009730D1   77 09            JA SHORT NOBU6HD_.009730DC
009730D3   66:890D E067BD00 MOV WORD PTR DS:[BD67E0],CX
009730DA   5D               POP EBP
009730DB   C3               RETN
*/


#include "GameDataStruct.h"

static void OnTenshouExeBattleStartExecute() {
	// 経過ターン数をリセット
	iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;

	デバッグ出力 << "戦争開始" << endl;
	戦争開始パラメタ型^ param = gcnew 戦争開始パラメタ型();
	int iCastleID = GetWarCenterCastle();
	param->攻撃側軍団番号 = nb6turn.gundan - 1;			   // 戦争で直接攻撃側になるのは、ターンの軍団の人だけ
	param->守備側軍団番号 = nb6castle[iCastleID].attach - 1; // 攻撃される側は、その城の軍団番号
	if (param->守備側軍団番号 >= 0xFFFE) { param->守備側軍団番号 = 0xFFFF; }

	try {
		// ユーザークラスがエラー
		if (ユーザークラス::IsErrorUserVersionDLL()) {
			throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
		}

		//２つパラメータの型を配列に入れる 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(2);
		types[0] = int::typeid;
		types[1] = 戦争開始パラメタ型::typeid;

		//メソッドの情報を取得 
		MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_戦争開始時", types);
		if (!method) {
			throw gcnew Exception("ユーザー天翔記クラス My_戦争開始時");
		}

		//２つのパラメタを実際に入れる
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(2);
		prms[0] = iCastleID;
		prms[1] = param;

		デバッグ出力 << "ユーザー天翔記クラス::My_戦争開始時" << endl;

		// 引数無しで実行
		method->Invoke(nullptr, prms);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_戦争開始時" << endl;
		天翔記クラス::On_戦争開始時(iCastleID, param);
	}

}


/*

ベース
00871000   56               PUSH ESI


009730D1   77 09            JA SHORT NOBU6HD_.009730DC
009730D3   66:890D E067BD00 MOV WORD PTR DS:[BD67E0],CX  ← 戦争開始時に、城のIDを入れる場所
└ここを JMP TSMod.OnTSExeBattleStart と書き換えてやる実際の処理。7バイトの書き換え
009730DA   5D               POP EBP
009730DB   C3               RETN
*/

/*
00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF だと戦争していない、FFFF以外だと、戦場の中心となっている「城番号」が入っている。
00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (攻城戦の時は、横が0x12=18,  縦が0x10=16)
*/
static int pTenshouExeJumpFromToOnTenshouExeBattleStart = 0x9730D3 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeBattleStartへとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeBattleStart = 0x9730DA - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																			   // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOFTemp = 0;
																			   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeBattleStart() {
	// スタックにためておく
	__asm {		// eaxを一時的に使って、上の0xB767E0相当の値を入れる
		mov iEAXOFTemp, eax
		mov eax, nb6battle_center_castle

		// 元々の処理をここに記述
		MOV WORD PTR DS : [eax], CX

		// eaxを戻す。
		mov eax, iEAXOFTemp


		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeBattleStartExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeBattleStart
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeBattleStart() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeBattleStart,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeBattleStart,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeBattleStart,	    // ここへと戻る
		7													// 7バイト
	);
}


