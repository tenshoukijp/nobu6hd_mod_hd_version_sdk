#include "GameDataStruct.h"


int ���ݒ���^::�������b�Z�[�W����::get() {
	return nb6settings_ingame.message_speed;
}

int ���ݒ���^::�����̐푈::get() {
	return nb6settings_ingame.others_war;
}

int ���ݒ���^::�����̐푈::get() {
	return nb6settings_ingame.myself_war;
}

int ���ݒ���^::���y����::get() {
	return nb6settings_ingame.bgm_volume;
}

int ���ݒ���^::���ʉ�����::get() {
	return nb6settings_ingame.se_volume;
}

int ���ݒ���^::�N���\��::get() {
	return nb6settings_ingame.gengo;
}

int ���ݒ���^::�E�B���h�E���[�h::get() {
	return nb6settings_ingame.screen;
}

���𑜓x�^^ ���ݒ���^::��ʃT�C�Y::get() {
	���𑜓x�^^ resolution = gcnew ���𑜓x�^();
	resolution->�w = nb6settings_ingame.width;
	resolution->�x = nb6settings_ingame.height;
	return resolution;
}

int ���ݒ���^::�E�N���b�N�L�����Z��::get() {
	return nb6settings_ingame.r_clk_cancel;
}

int ���ݒ���^::�ÊϏI���L�[::get() {
	return nb6settings_ingame.seikan_key;
}

int ���ݒ���^::�����Z�[�u::get() {
	return nb6settings_ingame.message_speed;
}
