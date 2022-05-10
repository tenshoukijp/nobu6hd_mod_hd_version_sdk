#pragma once

using namespace System::Reflection;

public ref class ユーザークラス
{
public:
	static System::Reflection::Assembly^ asse;
	static System::Type^ masterType;

private:
	static bool isUserAsseError = false;
public:
	// ユーザーバージョンDLLがエラーだったか。
	static bool IsErrorUserVersionDLL();
};

