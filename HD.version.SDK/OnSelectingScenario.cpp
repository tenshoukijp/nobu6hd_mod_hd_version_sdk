
#include "GameDataStruct.h"

void On_SelectingScenario(char *szScenarioFileName) {
	デバッグ出力 << "シナリオ選択関数:" << szScenarioFileName << endl;

	try {
		// ユーザークラスがエラー
		if (ユーザークラス::IsErrorUserVersionDLL()) {
			throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
		}

		// １つパラメータの型を配列に入れる 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
		types[0] = System::String::typeid;

		//メソッドの情報を取得 
		MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_シナリオ選択直後", types);
		if (!method) {
			throw gcnew Exception("ユーザー天翔記クラス My_シナリオ選択直後 メソッド未実装");
		}

		// １つのパラメタを実際に入れる
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
		prms[0] = gcnew String(szScenarioFileName);

		デバッグ出力 << "ユーザー天翔記クラス::My_シナリオ選択直後" << endl;

		// 引数無しで実行
		method->Invoke(nullptr, prms);
	}

	// エラーなので内部のものを実行する。
	catch (Exception^) {
		デバッグ出力 << "天翔記クラス::On_シナリオ選択直後" << endl;
		天翔記クラス::On_シナリオ選択直後(gcnew String(szScenarioFileName));
	}
	
}
