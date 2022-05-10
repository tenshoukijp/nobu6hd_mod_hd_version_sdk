#pragma once

#include "GameDataStruct.h"

char szLastestRequestScenarioOriginalFileName[MAX_PATH] = ""; // 要求された元々のシナリオ系の最後のファイル名。現在の進行が何番目のスロット情報なのかの重要なカギ。
char szLastestRequestScenarioFileName[MAX_PATH] = "";

namespace Native {
	string On_ファイル要求時(string strFileName, int iBufAddress) {

		// シナリオファイル名であれば、「シナリオファイルが要求されている」として、後でシナリオファイルを保存しておく。
		bool isScenarioFile = false;
		if (strFileName.find("sndata") != string::npos && strFileName.find(".dat") != string::npos) {
			デバッグ出力 << strFileName << endl;
			isScenarioFile = true;
			// オリジナルのファイル名を取っておく。何番目のスロットにアクセスしたのかの重要な情報。
			strcpy(szLastestRequestScenarioOriginalFileName, strFileName.data());
		}

		String^ strManagedRet = "";
		
		try {
			// ユーザークラスがエラー
			if (ユーザークラス::IsErrorUserVersionDLL()) {
				throw gcnew Exception("ユーザー天翔記クラス クラス未実装");
			}

			// １つパラメータの型を配列に入れる 
			cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
			types[0] = System::String::typeid;

			//メソッドの情報を取得 
			MethodInfo^ method = ユーザークラス::masterType->GetMethod("My_データファイル読込直前", types);
			if (!method) {
				throw gcnew Exception("ユーザー天翔記クラス My_データファイル読込直前 メソッド未実装");
			}

			// １つのパラメタを実際に入れる
			cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
			prms[0] = to_managed_string(strFileName);

			デバッグ出力 << "ユーザー天翔記クラス::My_データファイル読込直前" << endl;

			// 引数無しで実行
			strManagedRet = (String^)method->Invoke(nullptr, prms);
		}

		// エラーなので内部のものを実行する。
		catch (Exception^) {
			デバッグ出力 << "天翔記クラス::On_データファイル読込直前" << endl;
			strManagedRet = 天翔記クラス::On_データファイル読込直前(to_managed_string(strFileName));
		}

		
		
		if (strManagedRet->Length > 0) {
			string strNativeRet = to_native_string(strManagedRet);
			strcpy((char *)iBufAddress, strNativeRet.data());

			// シナリオファイル要求のフラグが立っていれば、最後にアクセスしたシナリオファイル名として保存
			if (isScenarioFile) {
				strcpy(szLastestRequestScenarioFileName, strNativeRet.data());
			}
			return strNativeRet;
		}
		
		// シナリオファイル要求のフラグが立っていれば、最後にアクセスしたシナリオファイル名として保存
		if (isScenarioFile) {
			strcpy(szLastestRequestScenarioFileName, strFileName.data());
		}
		return strFileName;
	}
}