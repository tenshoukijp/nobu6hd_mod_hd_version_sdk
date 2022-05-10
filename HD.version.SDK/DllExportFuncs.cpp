#include <windows.h>
#include <process.h>

#include "const_def.h"
#include "HookFuncs.h"
#include "GameDataStruct.h"

#pragma data_seg (".HDVERSIONSEG")
int bViewingLauncher = 0;
#pragma data_seg()


extern BOOL CheckCurrentProcessHeapInfo();
extern BOOL CheckCurrentProcessBaseInfo();

// メインのゲーム画面になったら初めて実行。
// それまでは、何もしない。
void OnInitializeThread(void *) {


	if (!CheckCurrentProcessBaseInfo()) {
		Windows::Forms::MessageBox::Show("HD.versionの対象バージョンではありません。\n" "HD.versionは実行しません。");
		return;
	}

	// この記述必要!!
	デバッグ出力 << "チェックポイント1" << endl;

	// ランチャーの起動
	if (bViewingLauncher == 0) {
		if (::FindWindow(NOBU_6HD_LAUNCHER_WINDOW, NULL)) {
			天翔記クラス::__PRIVATE_ON_LNCH_WINDOW__();

			try {
				// ユーザークラスがエラー
				if (ユーザークラス::IsErrorUserVersionDLL()) {
					throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
				}

				//メソッドの情報を取得 
				MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_ランチャーウィンドウ起動時");
				if (!method) {
					throw gcnew Exception("ユーザー天翔記クラス My_ランチャーウィンドウ起動時 メソッド未実装");
				}

				デバッグ出力 << "ユーザー天翔記クラス::My_ランチャーウィンドウ起動時" << endl;

				// 引数無しで実行
				method->Invoke(nullptr, nullptr);
			}

			// エラーなので内部のものを実行する。
			catch (Exception^) {
				デバッグ出力 << "天翔記クラス::On_ランチャーウィンドウ起動時" << endl;
				天翔記クラス::On_ランチャーウィンドウ起動時();
			}


			bViewingLauncher = 1;

			// この記述必要!!
			デバッグ出力 << "チェックポイント2" << endl;

			return;
		}
	}

	デバッグ出力 << "チェックポイント3" << endl;

	// ゲームウィンドウの起動を待つ。
	while (TRUE) {
		if (::FindWindow(NOBU_6HD_GAMEMAIN_WINDOW, NULL)) {
			break;
		}
		Sleep(1);
	}

	// 各種の構造体へのポインタのアドレスを設定
	SetGameDataStructPointer();

	// ジャンプ関数達を全て登録
	RegisterFunctionsOfWriteAsmJumperAndReturn();

	// 天翔記自体の関数を利用出来るようにアセンブラで構築する。
	ReplaceWrapperCallFunctions();

	// BGMのディレクトリを上書き
	// Native::On_ＢＧＭフォルダ要求時();
	// OutputDebugString("On_ＢＧＭフォルダ要求時");

	// Movieのディレクトリを上書き
	// Native::On_ＭＯＶＩＥフォルダ要求時();
	// OutputDebugString("On_ＭＯＶＩＥフォルダ要求時");


	天翔記クラス::__PRIVATE_ON_GAME_WINDOW__();

	try {
		// ユーザークラスがエラー
		if (ユーザークラス::IsErrorUserVersionDLL()) {
			throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
		}

		//メソッドの情報を取得 
		MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_ゲームウィンドウ起動時");
		if (!method) {
			throw gcnew Exception("ユーザー天翔記クラス My_ゲームウィンドウ起動時 メソッド未実装");
		}

		デバッグ出力 << "ユーザー天翔記クラス::My_ランチャーウィンドウ起動時" << endl;

		// 引数無しで実行
		method->Invoke(nullptr, nullptr);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_ゲームウィンドウ起動時" << endl;
		天翔記クラス::On_ゲームウィンドウ起動時();
	}

	
	bViewingLauncher = 0;
}


void WINAPI OnInitialize(void *param) {
	// スレッドで実行
	_beginthread(OnInitializeThread, 0, NULL);
}


void WINAPI OnFinalize() {
	// ここは実行されない。何か解放系に近い場所のものをフックしておく必要がある。
}