#include "GameDataStruct.h"

void �_�C�A���O���^::Show_�m�F_����(String^ ���b�Z�[�W) {
	string native_message = to_native_string(���b�Z�[�W);
	FuncConfirmDialogCenter((char *)native_message.c_str());
}

void �_�C�A���O���^::Show_�m�F_����(String^ ���b�Z�[�W) {
	string native_message = to_native_string(���b�Z�[�W);
	FuncConfirmDialogBottom((char *)native_message.c_str());
}

void �_�C�A���O���^::Show_���_����(String^ ���b�Z�[�W) {
	string native_message = to_native_string(���b�Z�[�W);
	FuncInfoDialogBottom((char *)native_message.c_str());
}

int �_�C�A���O���^::Show_���s�����_����(String^ ���b�Z�[�W) {
	string native_message = to_native_string(���b�Z�[�W);
	int ret = FuncOkCancelDialog((char *)native_message.c_str());
	return ret;
}
