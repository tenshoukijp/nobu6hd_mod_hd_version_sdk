#pragma once

using namespace System::Reflection;

public ref class ���[�U�[�N���X
{
public:
	static System::Reflection::Assembly^ asse;
	static System::Type^ masterType;

private:
	static bool isUserAsseError = false;
public:
	// ���[�U�[�o�[�W����DLL���G���[���������B
	static bool IsErrorUserVersionDLL();
};

