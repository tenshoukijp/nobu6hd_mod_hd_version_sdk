#include "GameDataStruct.h"


�ƕ���^::�ƕ���^(int i�ԍ�)
{
	iKahouID = i�ԍ�;
}

String^ �ƕ���^::����::get() {
	return gcnew String(nb6kahou[iKahouID].name);
}

void �ƕ���^::����::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 12) {
		strcpy(nb6kahou[iKahouID].name, native_value.c_str());
	}
}

int �ƕ���^::���::get() {
	return nb6kahou[iKahouID].type;
}

void �ƕ���^::���::set(int value) {
	if (��::�ƕ�::���::���q <= value && value <= ��::�ƕ�::���::��������) {
		// ��ނ�ύX����̂ň�x�ƕ���O��
		int iBushouID = nb6kahou[iKahouID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		ReAttachKahou(iKahouID, 0xFFFF);

		nb6kahou[iKahouID].type = value;
											   // ���̐l���ɕt������
		ReAttachKahou(iKahouID, iBushouID);
	}
}

int �ƕ���^::�摜::get() {
	return nb6kahou[iKahouID].face;
}

void �ƕ���^::�摜::set(int value) {
	if (��::�ƕ�::�摜::���q <= value && value <= ��::�ƕ�::�摜::����) {
		nb6kahou[iKahouID].face = value;
	}
}

// ���O�����]���Ă�̂ŁA���΂̒l�B
bool �ƕ���^::�o��::get() {
	// ���o��Ȃ�Afalse
	if (nb6kahou[iKahouID].bMitojo) {
		return false;
	}
	else {
		return true;
	}
}

void �ƕ���^::�o��::set(bool value) {
	// �o��̐ݒ�Ȃ�
	if (value) {
		nb6kahou[iKahouID].bMitojo = false;
	}
	else {
		nb6kahou[iKahouID].bMitojo = true;
	}
}


bool �ƕ���^::����::get() {
	return nb6kahou[iKahouID].bLost;
}

void �ƕ���^::����::set(bool value) {
	nb6kahou[iKahouID].bLost = value;
}

int �ƕ���^::���L�����ԍ�::get()
{
	int attr = nb6kahou[iKahouID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void �ƕ���^::���L�����ԍ�::set(int value)
{
	int iNewBushouID = value;
	ReAttachKahou(iKahouID, value);
}

int �ƕ���^::����::get() {
	int value = nb6kahou[iKahouID].param;
	if (1 <= value && value < 10) {
		return 11 - value; // �㏸�l���傫���قǁA�����̐��l�͏������B
	}
	return 0xFFFF; // ���Z�b�e�B���O
}

void �ƕ���^::����::set(int value) {
	if (1 <= value && value < 10) {
		// ������ύX����̂ň�x�ƕ���O��
		int iBushouID = nb6kahou[iKahouID].attach-1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		ReAttachKahou(iKahouID, 0xFFFF);

		nb6kahou[iKahouID].param = 11 - value; // �������������قǁA�㏸�l�͑傫��

		// ���̐l���ɕt������
		ReAttachKahou(iKahouID, iBushouID);
	}
}

int �ƕ���^::����::get() {
	return nb6kahou[iKahouID].param;
}

void �ƕ���^::����::set(int value) {
	if (1 <= value && value < 10) {

		// ������ύX����̂ň�x�ƕ���O��
		int iBushouID = nb6kahou[iKahouID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		ReAttachKahou(iKahouID, 0xFFFF);

		nb6kahou[iKahouID].param = value;

		// ���̐l���ɕt������
		ReAttachKahou(iKahouID, iBushouID);
	}
}



�ƕ󃊃X�g���^::�ƕ󃊃X�g���^() {
	�z�� = gcnew List<�ƕ���^^>();
	�z��->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_KAHOU_NUM; i++)
	{
		�z��->Add(gcnew �ƕ���^(i));
	}
}


int �ƕ󃊃X�g���^::Find_�ƕ�ԍ�(String^ ����) {

	for (int i = 0; i < GAMEDATASTRUCT_KAHOU_NUM; i++) {
		if (���� == gcnew String(nb6kahou[i].name)) {
			return i;
		}
	}

	return 0xFFFF;
}


