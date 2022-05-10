#include "GameDataStruct.h"

#include "OnWriteFukidashiMessage.h"
#include "OnSelectingScenario.h"
#include "OnFileRequest.h"

static void OnTenshouExeWriteFukidashiMessage01Execute() {

	char *str = (char *)nb6fukidashi_msg_ptr;
	// デバッグ出力 << str << endl;
	// デバッグ出力 << "メッセージ" << endl;

	// シナリオ選択のメッセージだ
	if (strcmp(str, "プレイする勢力を選択してください") == 0) {
		デバッグ出力 << "シナリオ選択" << endl;
		On_SelectingScenario(szLastestRequestScenarioFileName);
	}

	噴出メッセージパラメタ型^ param = gcnew 噴出メッセージパラメタ型();

	param->第１人称_武将番号 = nb6fukidashi_relate_persons.i1stPersonID < 0xFFFF ? int(nb6fukidashi_relate_persons.i1stPersonID - 1) : 0xFFFF;
	param->第２人称_武将番号 = nb6fukidashi_relate_persons.i2ndPersonID < 0xFFFF ? int(nb6fukidashi_relate_persons.i2ndPersonID - 1) : 0xFFFF;
	param->第３人称_武将番号 = nb6fukidashi_relate_persons.i3rdPersonID < 0xFFFF ? int(nb6fukidashi_relate_persons.i3rdPersonID - 1) : 0xFFFF;

	String^ strReWrite = "";
		
	try {
		// ユーザークラスがエラー
		if (ユーザークラス::IsErrorUserVersionDLL()) {
			throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
		}

		//２つパラメータの型を配列に入れる 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(2);
		types[0] = System::String::typeid;
		types[1] = 噴出メッセージパラメタ型::typeid;

		//メソッドの情報を取得 
		MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_噴出メッセージ直前", types);
		if (!method) {
			throw gcnew Exception("ユーザー天翔記クラス My_噴出メッセージ直前 メソッド未実装");
		}

		//２つのパラメタを実際に入れる
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(2);
		prms[0] = gcnew String(str);
		prms[1] = param;

		デバッグ出力 << "ユーザー天翔記クラス::My_噴出メッセージ直前" << endl;

		// 引数無しで実行
		strReWrite = (String^)method->Invoke(nullptr, prms);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_噴出メッセージ直前" << endl;
		strReWrite = 天翔記クラス::On_噴出メッセージ直前(gcnew String(str), param);
	}



	if (strReWrite->Length > 1) { // 改行だけなどの間違いをフィルダー
		string strNativeReWriteMessage = to_native_string(strReWrite);
		if (strNativeReWriteMessage.size() > 1) { // 改行だけなどの間違いをフィルダー
			strcpy((char *)nb6fukidashi_msg_ptr, strNativeReWriteMessage.c_str());
		}
	}

}

/*
この時のベースアドレス
00871000   56               PUSH ESI

00991776   A3 6074BF00      MOV DWORD PTR DS:[BF7460],EAX
0099177B   C602 00          MOV BYTE PTR DS:[EDX],0
0099177E   890D 8C74BF00    MOV DWORD PTR DS:[BF748C],ECX
00991784   B8 781EBF00      MOV EAX,NOBU6HD_.00BF1E78
└ここを JMP TSMod.OnTSExeWriteFukidashiMessage01 と書き換えてやる実際の処理
00991789   5E               POP ESI


00BF1E78  89 BD 82 F0 82 B7 82 E9 82 A9 82 CD 0A 8C 5A 8F  何をするかは.兄・
00BF1E88  E3 82 CC 0A 90 53 8E 9F 91 E6 00 82 E7 82 AD 82  繧ﾌ.心次第.らく・
00BF1E98  A8 91 D2 82 BF 82 AD 82 BE 82 B3 82 A2 00 00 00  ｨ待ちください...
00BF1EA8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00BF1EB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................


*/
static int pTenshouExeJumpFromToOnTenshouExeWriteFukidashiMessage01 = 0x991784 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeWriteFukidashiMessage01へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeWriteFukidashiMessage01 = 0x991789 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																														 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。

																														 // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeWriteFukidashiMessage01() {
	// スタックにためておく
	__asm {
		// 元々の処理をここに記述
		MOV EAX, nb6fukidashi_msg_ptr

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeWriteFukidashiMessage01Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeWriteFukidashiMessage01
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeWriteFukidashiMessage01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeWriteFukidashiMessage01,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeWriteFukidashiMessage01,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeWriteFukidashiMessage01	    // ここへと戻る
		);
}


