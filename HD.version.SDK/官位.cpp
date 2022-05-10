#include "GameDataStruct.h"


���ʏ��^::���ʏ��^(int i�ԍ�)
{
	iKaniID = i�ԍ�;
}


String^ ���ʏ��^::���ʖ�::get() {
	return gcnew String(nb6kani[iKaniID].name);
}
void ���ʏ��^::���ʖ�::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 12) {
		strcpy(nb6kani[iKaniID].name, native_value.c_str());
	}
}

int ���ʏ��^::���L�����ԍ�::get()
{
	int attr = nb6kani[iKaniID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void ���ʏ��^::���L�����ԍ�::set(int value)
{
	int iNewBushouID = value;
	ReAttachKani(iKaniID, value);
}



int ���ʏ��^::�ʊK::get() {
	return nb6kani[iKaniID].rank;
}

void ���ʏ��^::�ʊK::set(int value) {
	if (��::����::�ʊK::����� <= value && value < ��::����::�ʊK::�����ʏ�) {

		// ������ύX����̂ň�x�ƕ���O��
		int iBushouID = nb6kani[iKaniID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		// ����Ɉ�U�߂�
		ReAttachKani(iKaniID, 0xFFFF);

		nb6kani[iKaniID].rank = value;

		// ���̐l���ɕt������
		ReAttachKani(iKaniID, iBushouID);

	}
}

String^ ���ʏ��^::�ʊK��::get() {
	int rank = nb6kani[iKaniID].rank;
	return gcnew String(getKaniTypeName(rank));
}

int ���ʏ��^::����::get() {
	return nb6kani[iKaniID].param;
}

void ���ʏ��^::����::set(int value) {
	if (0 <= value && value < LIMIT_CHAR_MAX) {

		int iBushouID = nb6kani[iKaniID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		// ����Ɉ�U�߂�
		ReAttachKani(iKaniID, 0xFFFF);

		nb6kani[iKaniID].param = value;

		// ���̐l���ɕt������
		ReAttachKani(iKaniID, iBushouID);
	}
}



���ʃ��X�g���^::���ʃ��X�g���^() {
	�z�� = gcnew List<���ʏ��^^>();
	�z��->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_KANI_NUM; i++)
	{
		�z��->Add(gcnew ���ʏ��^(i));
	}

}


int ���ʃ��X�g���^::Find_���ʔԍ�(String^ ���ʖ�) {

	for (int i = 0; i < GAMEDATASTRUCT_KANI_NUM; i++) {
		if (���ʖ� == gcnew String(nb6kani[i].name)) {
			return i;
		}
	}

	return 0xFFFF;
}

