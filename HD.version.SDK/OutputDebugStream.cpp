#include "�f�o�b�O�o��.h"

#include "ManagedString.h"

using namespace System;

char szBuf�f�o�b�O�o��[4096] = "";

// �f�o�b�O�X�g���[���̃V���O���g���ϐ�(cout�̗ނƓ���)
�f�o�b�O�o�͌^ �f�o�b�O�o��;


// String^ �^���f�o�b�O�o�͂ɑΉ�������B
�f�o�b�O�o�͌^& operator << (�f�o�b�O�o�͌^& os, String^ managed_message) {
	string msg = to_native_string(managed_message);
	os << msg;
	return os;
}
