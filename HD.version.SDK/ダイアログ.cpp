#include "GameDataStruct.h"

void ダイアログ情報型::Show_確認_中央(String^ メッセージ) {
	string native_message = to_native_string(メッセージ);
	FuncConfirmDialogCenter((char *)native_message.c_str());
}

void ダイアログ情報型::Show_確認_下部(String^ メッセージ) {
	string native_message = to_native_string(メッセージ);
	FuncConfirmDialogBottom((char *)native_message.c_str());
}

void ダイアログ情報型::Show_情報_中央(String^ メッセージ) {
	string native_message = to_native_string(メッセージ);
	FuncInfoDialogBottom((char *)native_message.c_str());
}

int ダイアログ情報型::Show_実行か取消_中央(String^ メッセージ) {
	string native_message = to_native_string(メッセージ);
	int ret = FuncOkCancelDialog((char *)native_message.c_str());
	return ret;
}
