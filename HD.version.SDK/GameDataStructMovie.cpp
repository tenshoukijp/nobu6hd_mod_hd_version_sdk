#pragma once


#include "GameDataStruct.h"
#include "ManagedString.h"

static char szOverWriteMOVIEDir[MAX_PATH];

namespace Native {
	/*
	void On_ＭＯＶＩＥフォルダ要求時() {

		String^ managed_moviedir = 天翔記クラス::On_ＭＯＶＩＥフォルダ要求時();
		string native_moviedir = to_native_string(managed_moviedir);

		// 実際にそのディレクトリが存在すれば
		if (System::IO::Directory::Exists(to_managed_string(native_moviedir))) {

			// もしも、HD.CustomModで書き換えていたら
			if (native_moviedir.size() > 0) {

				native_moviedir += "\\"; // 最後に\を付ける。
				strcpy(szOverWriteMOVIEDir, native_moviedir.c_str());

				// MOVIE\ という文字列へのアドレスを、szOverWriteMOVIEDirのアドレスへと書き換える。
				int iBufferAddress = (int)szOverWriteMOVIEDir;

				// 該当のモジュール域を超えてるのでこちらのプロセスメモリでないとうまくいかない。
				WriteProcessMemory(GetCurrentProcess(), (LPVOID)nb6moviedirptr, (LPVOID)&iBufferAddress, sizeof(int), NULL);
			}
		}
	}
	*/
}