#include "デバッグ出力.h"

#include "ManagedString.h"

using namespace System;

char szBufデバッグ出力[4096] = "";

// デバッグストリームのシングルトン変数(coutの類と同じ)
デバッグ出力型 デバッグ出力;


// String^ 型をデバッグ出力に対応させる。
デバッグ出力型& operator << (デバッグ出力型& os, String^ managed_message) {
	string msg = to_native_string(managed_message);
	os << msg;
	return os;
}
