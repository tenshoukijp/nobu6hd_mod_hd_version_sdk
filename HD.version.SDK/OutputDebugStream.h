#pragma once

#include <windows.h>
#include <stdio.h>
#include <string>
#include <istream>
#include <ostream>
#include <sstream>
#include <tchar.h>

#include "ManagedString.h"


using namespace std;
using namespace System;

/*
デバッグ出力のためのテンプレート
①printf(format, ...)にそっくりな記法

　デバッグ出力( "%s", 元メッセージ.c_str() );

②cout << ... にそっくりな記法

  デバッグ出力 << a << ":" << b << (int)c << endl;

  この両方を｢デバッグ出力｣というシングルトン(前提の)インスタンスでサポートするためのクラスや宣言
*/



// ｢C4996」のワーニングの発生するコードがあっても、コンパイル時には出力されなくなる。
#pragma warning(push)
#pragma warning(disable:4996)

// OutputDebugStringへとフォーマット(printf)形式を利用して出力する。
extern char szBufデバッグ出力[4096];


// VC++ で STLport だと using std::char_traits; みたいなのが必要かも
template <typename Ch_T, typename Tr_T = std::char_traits<Ch_T> >
class basic_dbg_streambuf : public std::basic_stringbuf<Ch_T, Tr_T> {
public:
	basic_dbg_streambuf() {
#ifndef STDX_DSTREAM_BUFFERING
		setbuf(0, 0);
#endif
	}

	virtual ~basic_dbg_streambuf() {
		sync();
	}

protected:
	int sync(void) {
		dbg_out(str().c_str());
		pbump(static_cast<int>(pbase() - pptr()));
		return 0;
	}

	void dbg_out(const Ch_T*);
};

template <>
inline void basic_dbg_streambuf<char>::dbg_out(const char *str) {

	::OutputDebugStringA(str);
}

template <>
inline void basic_dbg_streambuf<wchar_t>::dbg_out(const wchar_t *str) {

	::OutputDebugStringW(str);
}

template <typename Ch_T, typename Tr_T = std::char_traits<Ch_T> >
class basic_dbg_ostream : public std::basic_ostream<Ch_T, Tr_T> {
public:
	basic_dbg_ostream() : std::basic_ostream<Ch_T, Tr_T>(new basic_dbg_streambuf<Ch_T, Tr_T>()) {
	}

	virtual ~basic_dbg_ostream() {
		delete rdbuf();
	}

};


using dbg_streambuf = basic_dbg_streambuf<_TCHAR>;
using デバッグ出力型 = basic_dbg_ostream<_TCHAR>;

extern デバッグ出力型 デバッグ出力;

// String^ 型をデバッグ出力に対応させる。
extern デバッグ出力型& operator << (デバッグ出力型& os, String^ managed_message);

// 以上「C4996」のワーニングの発生するコードがあっても、コンパイル時には出力されなくなる。
#pragma warning(pop)

