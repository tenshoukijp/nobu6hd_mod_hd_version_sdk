#include "ユーザークラス.h"

using namespace System;
using namespace System::Reflection;

bool ユーザークラス::IsErrorUserVersionDLL()
{
	// もうすでにチェックしたことがある。エラーならそのまま
	if (isUserAsseError)
	{
		return isUserAsseError;
	}

	// アセンブリ読み込みをトライ
	try
	{
		asse = System::Reflection::Assembly::LoadFrom("User.version.dll");
	}

	// アセンブリではない
	catch (...)
	{
		isUserAsseError = true;
	}

	if (isUserAsseError)
	{
		return isUserAsseError;
	}

	masterType = asse->GetType("ユーザー天翔記クラス");
	if (masterType == nullptr)
	{
		isUserAsseError = true;
	}

	if (isUserAsseError)
	{
		return isUserAsseError;
	}

	// ここまで来れば、とりあえずアセンブリとしては、ぞんざいし、「ユーザー天翔記クラス」も読めた
	return false;
}