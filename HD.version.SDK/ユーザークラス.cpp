#include "���[�U�[�N���X.h"

using namespace System;
using namespace System::Reflection;

bool ���[�U�[�N���X::IsErrorUserVersionDLL()
{
	// �������łɃ`�F�b�N�������Ƃ�����B�G���[�Ȃ炻�̂܂�
	if (isUserAsseError)
	{
		return isUserAsseError;
	}

	// �A�Z���u���ǂݍ��݂��g���C
	try
	{
		asse = System::Reflection::Assembly::LoadFrom("User.version.dll");
	}

	// �A�Z���u���ł͂Ȃ�
	catch (...)
	{
		isUserAsseError = true;
	}

	if (isUserAsseError)
	{
		return isUserAsseError;
	}

	masterType = asse->GetType("���[�U�[�V�ċL�N���X");
	if (masterType == nullptr)
	{
		isUserAsseError = true;
	}

	if (isUserAsseError)
	{
		return isUserAsseError;
	}

	// �����܂ŗ���΁A�Ƃ肠�����A�Z���u���Ƃ��ẮA���񂴂����A�u���[�U�[�V�ċL�N���X�v���ǂ߂�
	return false;
}