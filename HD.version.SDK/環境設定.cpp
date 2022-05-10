#include "GameDataStruct.h"


int 環境設定情報型::自動メッセージ送り::get() {
	return nb6settings_ingame.message_speed;
}

int 環境設定情報型::他国の戦争::get() {
	return nb6settings_ingame.others_war;
}

int 環境設定情報型::自国の戦争::get() {
	return nb6settings_ingame.myself_war;
}

int 環境設定情報型::音楽音量::get() {
	return nb6settings_ingame.bgm_volume;
}

int 環境設定情報型::効果音音量::get() {
	return nb6settings_ingame.se_volume;
}

int 環境設定情報型::年号表示::get() {
	return nb6settings_ingame.gengo;
}

int 環境設定情報型::ウィンドウモード::get() {
	return nb6settings_ingame.screen;
}

環境解像度型^ 環境設定情報型::画面サイズ::get() {
	環境解像度型^ resolution = gcnew 環境解像度型();
	resolution->Ｘ = nb6settings_ingame.width;
	resolution->Ｙ = nb6settings_ingame.height;
	return resolution;
}

int 環境設定情報型::右クリックキャンセル::get() {
	return nb6settings_ingame.r_clk_cancel;
}

int 環境設定情報型::静観終了キー::get() {
	return nb6settings_ingame.seikan_key;
}

int 環境設定情報型::自動セーブ::get() {
	return nb6settings_ingame.message_speed;
}
