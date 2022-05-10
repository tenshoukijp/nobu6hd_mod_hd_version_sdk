/*
ベースアドレス
00811000   56               PUSH ESI
*/


#include "GameDataStruct.h"


/*
ベース
00871000   56               PUSH ESI

00A11496   68 0CBFB400      PUSH NOBU6HD_.00B4BF0C                   ; ASCII "MOVIE\"
00A1149B   8BCF             MOV ECX,EDI
00A1149D   E8 3E49E6FF      CALL NOBU6HD_.00875DE0
00A114A2   8B14F5 18ECBD00  MOV EDX,DWORD PTR DS:[ESI*8+BDEC18]　　　←ESIがムービーの番号とも言える。
00A114A9   803A 00          CMP BYTE PTR DS:[EDX],0


00BDEC18  7C BE B4 00 00 00 00 00 88 BE B4 00 00 00 00 00
00BDEC28  98 BE B4 00 00 00 00 00 B0 BE B4 00 01 00 00 00
00BDEC38  B8 BE B4 00 01 00 00 00 C0 BE B4 00 00 00 00 00
00BDEC48  D0 BE B4 00 00 00 00 00 E0 BE B4 00 00 00 00 00
00BDEC58  FC BE B4 00 01 00 00 00 04 BF B4 00 01 00 00 00

*/

/*
*/
/*
00B4BE7C  4C 4F 47 4F 5F 4B 54 2E 4E 36 00 00 4C 4F 47 4F  LOGO_KT.N6..LOGO
00B4BE8C  5F 4B 4F 45 49 2E 4E 36 00 00 00 00 4C 4F 47 4F  _KOEI.N6....LOGO
00B4BE9C  5F 73 65 72 69 65 73 5F 4E 6F 62 5F 6A 70 6E 2E  _series_Nob_jpn.
00B4BEAC  4E 36 00 00 4F 50 2E 4E 36 00 00 00 53 52 2E 4E  N6..OP.N6...SR.N
00B4BEBC  36 00 00 00 4C 4F 47 4F 5F 4B 54 5F 4C 2E 4E 36  6...LOGO_KT_L.N6
00B4BECC  00 00 00 00 4C 4F 47 4F 5F 4B 4F 45 49 5F 4C 2E  ....LOGO_KOEI_L.
00B4BEDC  4E 36 00 00 4C 4F 47 4F 5F 73 65 72 69 65 73 5F  N6..LOGO_series_
00B4BEEC  4E 6F 62 5F 6A 70 6E 5F 4C 2E 4E 36 00 00 00 00  Nob_jpn_L.N6....
00B4BEFC  4F 50 5F 4C 2E 4E 36 00 53 52 5F 4C 2E 4E 36 00  OP_L.N6.SR_L.N6.
00B4BF0C  4D 4F 56 49 45 5C 00 00 42 47 4D 5C 00 00 00 00  MOVIE\..BGM\....
00B4BF1C  42 47 4D 30 30                                   BGM00
*/

static char szOnotherMOVIEFileName[MAX_PATH] = ""; // MOVIEのファイル名を変更する。


// BGMの番号が決定される時

static int iESIOfMOVIEPlayingNumberDecide = 0;
static void OnTenshouExeMOVIEPlayingNumberDecideExecute() {
	
	// MOVIEのファイル名の情報をデフォルトに戻す。
	memcpy(nb6movietable, nb6moviedefault, sizeof(nb6moviedefault));

	if (iESIOfMOVIEPlayingNumberDecide > 0) {
		int iMOVIENum = iESIOfMOVIEPlayingNumberDecide;
		デバッグ出力 << dec << iMOVIENum << endl;
		char *szDefaultFileName = (char *)nb6moviedefault[iMOVIENum].iMOVIEFileNameAddress;

		// デバッグ出力 << "MOVIEPlayingNumberDecide:" << dec << iMOVIENum << endl;
		// デバッグ出力 << "MOVIEPlayingFileName:" << hex << szDefaultFileName << endl;

		// 天翔記クラスへの問い合わせ
		String^ strManagedMOVIENewerFileName = "";
		
		
		try {
			// ユーザークラスがエラー
			if (ユーザークラス::IsErrorUserVersionDLL()) {
				throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
			}

			//２つパラメータの型を配列に入れる 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(2);
			types[0] = int::typeid;
			types[1] = System::String::typeid;

			//メソッドの情報を取得 
			MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_ＭＯＶＩＥ再生直前", types);
			if (!method) {
				throw gcnew Exception("ユーザー天翔記クラス My_ＭＯＶＩＥ再生直前 メソッド未実装");
			}

			//２つのパラメタを実際に入れる
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(2);
			prms[0] = iMOVIENum;
			prms[1] = gcnew String(szDefaultFileName);

			デバッグ出力 << "ユーザー天翔記クラス::My_ＭＯＶＩＥ再生直前" << endl;

			// 引数無しで実行
			strManagedMOVIENewerFileName = (String^)method->Invoke(nullptr, prms);
		}

		// エラーなので内部のものを実行する。
		catch (Exception^) {
			デバッグ出力 << "天翔記クラス::On_ＭＯＶＩＥ再生直前" << endl;
			strManagedMOVIENewerFileName = 天翔記クラス::On_ＭＯＶＩＥ再生直前(iMOVIENum, gcnew String(szDefaultFileName));
		}
		
		

		// 有効なファイル名が返されていたら、そのファイル名へのポインタを指すようにテーブルの該当番号のファイル名ポインタを変更する。
		if (strManagedMOVIENewerFileName->Length > 0) {
			string nativeFileName = to_native_string(strManagedMOVIENewerFileName);
			strcpy(szOnotherMOVIEFileName, nativeFileName.c_str());

			// 再生の全体テーブルの中で、これから再生しようとするファイル名へのポインタに上のバッファのアドレスを入れてしまう。
			nb6movietable[iMOVIENum].iMOVIEFileNameAddress = (int)szOnotherMOVIEFileName;


		}
	}
	else {
		// デバッグ出力 << "MOVIEPlayingNumberDecide" << dec << "BGM無効" << endl;
	}
}


/*
ベース

00871000   56               PUSH ESI

00A11496   68 0CBFB400      PUSH NOBU6HD_.00B4BF0C                   ; ASCII "MOVIE\"
00A1149B   8BCF             MOV ECX,EDI
00A1149D   E8 3E49E6FF      CALL NOBU6HD_.00875DE0
└ここを JMP TSMod.OnTSExeMOVIEPlayingNumberDecide と書き換えてやる実際の処理
00A114A2   8B14F5 18ECBD00  MOV EDX,DWORD PTR DS:[ESI*8+BDEC18]　　　←ESIがムービーの番号とも言える。
00A114A9   803A 00          CMP BYTE PTR DS:[EDX],0
*/
static int pTenshouExeJumpFromToOnTenshouExeMOVIEPlayingNumberDecide = 0xA1149D - 0x870000;   // 関数はこのアドレスから、OnTenshouExeMOVIEPlayingNumberDecideへとジャンプしてくる。
static int pTenshouExeCallFuncToOnTenshouExeMOVIEPlayingNumberDecide = 0x875DE0 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
static int pTenshouExeRetnBacktoOnTenshouExeMOVIEPlayingNumberDecide = 0xA114A2 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																							// この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
EXPORT_AND_NAKED void WINAPI OnTenshouExeMOVIEPlayingNumberDecide() {
	// スタックにためておく
	__asm {

		mov iESIOfMOVIEPlayingNumberDecide, ESI          // ムービーの番号の保存
														 // 元々の処理
		call pTenshouExeCallFuncToOnTenshouExeMOVIEPlayingNumberDecide

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeMOVIEPlayingNumberDecideExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeMOVIEPlayingNumberDecide
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeMOVIEPlayingNumberDecide() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeMOVIEPlayingNumberDecide,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeMOVIEPlayingNumberDecide,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeMOVIEPlayingNumberDecide	    // ここへと戻る
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeMOVIEPlayingNumberDecide
		);

}


