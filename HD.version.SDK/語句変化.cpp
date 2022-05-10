#include "GameDataStruct.h"

#include "GameDataStructBushouRelation.h"








/*
�y�����z:
0 ����			 217 �^�c�K���E���@�䕔���e�E���Ë`�v�E�E�ґS��
1 ��V������	 152 �O�c���ƁE���q���G�E���ԏ@�΁E�������
2 �e�\			 119 �ēc���ƁE���������M�E���ˑ��E���X�؏����Y
3 ���M			 30 �㐙�����E����`���E�����`���E�������
4 ���ӋC		 180 �ɒB���@�E�O�D���c�E��؏d�G�E�R�䐳��
5 �Ќ�			 143 �D�c�M���E����ƍN�E���c�M���E�㐙���M
6 �`��			 145 �L�b�G�g�E�֓����O�E���i�v�G�E�����`��
7 ���			 314 �{�������E�g�쌳�t�E�R�����V���E�j���P�S��
*/


String^ ��������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID = 0xFFFF);


// 00�i����Ɍh�ӂ𕥂��K�v���Ȃ��ꍇ�̎��́j 
String^ ���킵��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	// �Ƒ��̏ꍇ���ɔ��肷��B
	String^ szIsFamilyMsg = ��������(i1st_BushouID, i2nd_BushouID, i3rd_BushouID);

	if (szIsFamilyMsg->Length > 0) {
		return szIsFamilyMsg;
	}

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���� ����&����>35 
		if (nb6bushouname[i1st_BushouID].sex == 1 && getYearsOld(i1st_BushouID) > 35) {
			return "����";

			// �킽���� ����  
		}
		else if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�킽����";

			// �܂� ����=3 
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "�܂�";

			// �킵 ���g=0or1 and ����>35  (0==�B��, 1==�喼)
		}
		else if ((nb6bushouname[i1st_BushouID].position == 0 || nb6bushouname[i1st_BushouID].position == 1) && getYearsOld(i1st_BushouID) > 35) {
			return "�킵";

			// �� ����=2or4
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
			return "��";

			// �� ����=1 
		}
		else if (nb6bushou[i1st_BushouID].tone == 1) {
			return "��";

			// �킵 �i���j 
		}
		else {
			return "�킵";

		}
	}
	return "���킵��";
}



// 01�i����Ɛe�q�E�Z��E�v�w�ɂ���ꍇ�̎��́j
// ���̃w���p�[�Ȃ̂ŁA���ڎg��Ȃ�����!!
String^ ��������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� �����e�q&����<����&���� 
		if (is�����͑���̖�(i1st_BushouID, i2nd_BushouID)) {
			return "��";

			// �� �����e�q&����>����&���j 
		}
		else if (is�����͑���̕�(i1st_BushouID, i2nd_BushouID)) {
			return "��";

			// �� �����e�q&����>����&���� 
		}
		else if (is�����͑���̕�(i1st_BushouID, i2nd_BushouID)) {
			return "��";

			// �� �����Z��&����<����&���j 
		}
		else if (is�����͑���̒�(i1st_BushouID, i2nd_BushouID)) {
			return "��";

			// �� �����Z��&����<����&���� 
		}
		else if (is�����͑���̖�(i1st_BushouID, i2nd_BushouID)) {
			return "��";

			// �Z �����Z��&����>����&���j
		}
		else if (is�����͑���̌Z(i1st_BushouID, i2nd_BushouID)) {
			return "�Z";

			// �o �����Z��&����>����&����
		}
		else if (is�����͑���̎o(i1st_BushouID, i2nd_BushouID)) {
			return "�o";

			// �v �����v�w&���j
		}
		else if (is�����͑���̕v(i1st_BushouID, i2nd_BushouID)) {
			return "�v";

			// �� �����w�v&����
		}
		else if (is�����͑���̍�(i1st_BushouID, i2nd_BushouID)) {
			return "��";
		}

	}
	return "";
}



// 02�i���̑��̏ꍇ�̎��́j 
String^ ������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	// �Ƒ��̏ꍇ���ɔ��肷��B
	String^ szIsFamilyMsg = ��������(i1st_BushouID, i2nd_BushouID, i3rd_BushouID);

	if (szIsFamilyMsg->Length > 0) {
		return szIsFamilyMsg;
	}

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �킽���� ����  
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�킽����";

			// �܂� ��������&����=3 
		}
		else if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && nb6bushou[i1st_BushouID].tone == 3) {
			return "�܂�";

			// �킵 ��������&����>����&����>35
		}
		else if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) && getYearsOld(i1st_BushouID) > 35) {
			return "�킵";

			// �킵 ���g=(0or1)&����>35  (0==�B��, 1==�喼)
		}
		else if ((nb6bushouname[i1st_BushouID].position == 0 || nb6bushouname[i1st_BushouID].position == 1) && getYearsOld(i1st_BushouID) > 35) {
			return "�킵";

			// �َ� ���E=1or3 (�E�҂�����)
		}
		else if (nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
			return "�َ�";

			// �ّm ���E=4 (�m��)
		}
		else if (nb6bushou[i1st_BushouID].job == 0x40) {
			return "�ّm";

			// �� ����=2
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "��";

			// ���ꂪ�� ����=5
		}
		else if (nb6bushou[i1st_BushouID].tone == 5) {
			return "���ꂪ��";

			// �� �i���j 
		}
		else {
			return "��";

		}
	}
	return "������";
}


// 03�i���L�`�e���j  
String^ ���䂪��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// ���� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "����";
		}
		else {
			return "�䂪";
		}
	}
	return "���䂪��";
}


// 04�`07 ������������ޏꍇ�u�ȊO�v�̓�l��
String^ �����聓(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		/*
		* 04�i����ƌ����֌W�ɂ���ꍇ�̓�l�́j
		*/
		// �����e�q&����<����&���j
		if (is����͎����̕�(i1st_BushouID, i2nd_BushouID)) {
			return "����";

			// �����e�q&����<����&����
		}
		else if (is����͎����̕�(i1st_BushouID, i2nd_BushouID)) {
			return "���";

			// �Z�� �����Z��&����<����&���j 
		}
		else if (is����͎����̌Z(i1st_BushouID, i2nd_BushouID)) {
			return "�Z��";

			// �o�� �����Z��&����<����&���� 
		}
		else if (is����͎����̎o(i1st_BushouID, i2nd_BushouID)) {
			return "�o��";

			// ���Ȃ� �����v�w&���j 
		}
		else if (is�����͑���̍�(i1st_BushouID, i2nd_BushouID)) {
			return "���Ȃ�";

			// (����) �����e�q&����>���� (�����͑���̐e�ł���)
		}
		else if (is�����͑���̐e(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (����)�a ��������&��=�喼
		}
		else if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i2nd_BushouID].State == 0) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�a";

			// (����) �����Z��&����>����&�����喼
		}
		else if (is�����͑���̌Z(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i2nd_BushouID].State != 0) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (����) �����v�w&���� 
		}
		else if (is�����͑���̕v(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (����)�a ��������
		}
		else if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�a";

			/*
			*	05�i�������喼�ő��肪���̉Ɛb�̏ꍇ�̓�l�́j
			*/
			// ���B�� ��=�喼&���g=0 
		}
		else if (is����͎����̉Ɛb(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i2nd_BushouID].position == 0) {
			return "���B��";

			// ���� ����<���d&���30&���50&���j
		}
		else if (is����͎����̉Ɛb(i1st_BushouID, i2nd_BushouID) &&
			(getYearsOld(i1st_BushouID) < nb6bushou[i2nd_BushouID].work) && getYearsOld(i1st_BushouID) <= 30 &&
			getYearsOld(i2nd_BushouID) >= 50 && nb6bushouname[i2nd_BushouID].sex == 0) {
			return "����";
			// �� ��=�D�c�M��(=��0)&��=�L�b�G�g(=��5) 
		}
		else if (is����͎����̉Ɛb(i1st_BushouID, i2nd_BushouID) && nb6bushouname[i1st_BushouID].number == 0 && nb6bushouname[i2nd_BushouID].number == 5) {
			return "��";

			// (����) �i���j 
		}
		else if (is����͎����̉Ɛb(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			/*
			*	06�i���肪�����̑喼�̏ꍇ�̓�l�́j
			*/
			// �� ����<���d&���30&���50&���j 
		}
		else if (is����͎����̑喼(i1st_BushouID, i2nd_BushouID) &&
			(getYearsOld(i2nd_BushouID) < nb6bushou[i1st_BushouID].work) && getYearsOld(i2nd_BushouID) <= 30 &&
			getYearsOld(i1st_BushouID) >= 50 && nb6bushouname[i2nd_BushouID].sex == 0) {
			return "��";

			// ���ٗl ������3&33%
		}
		else if (is����͎����̑喼(i1st_BushouID, i2nd_BushouID) && nb6bushou[i1st_BushouID].tone != 3 && rand() % 3 == 0) {
			return "���ٗl";

			// (����)�l �i���j 
		}
		else if (is����͎����̑喼(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�l";

			/*
			*	07�i���̑��̏ꍇ�̓�l�́j
			*/
			// (����)�a ���g=1&���g=1 (1==�喼)
		}
		else if (nb6bushouname[i2nd_BushouID].position == 1 && nb6bushouname[i1st_BushouID].position == 1) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�a";

			// (����)�l ���g=1&���g��1 
		}
		else if (nb6bushouname[i2nd_BushouID].position == 1 && nb6bushouname[i1st_BushouID].position != 1) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�l";

			// ���B�� ���g=0 
		}
		else if (nb6bushouname[i2nd_BushouID].position == 0) {
			return "���B��";

			// (����) ���g�����g(�����ԍ��I�ɂ͎��g�����g)&�������&����=����  (�g��=0:�B�� 1:�喼 2:�h�V 3:�ƘV �c�Ȃ̂ŁA�ԍ�����������������)
		}
		else if (nb6bushouname[i1st_BushouID].position <= nb6bushouname[i2nd_BushouID].position &&
			getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID) && is�����Ƒ���͓����喼�Ə���(i1st_BushouID, i2nd_BushouID)) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);

			// (����)�l ���g>���g+1(3�K�����������̐g���Ƃ�������)&������4 
		}
		else if (nb6bushouname[i1st_BushouID].position > nb6bushouname[i2nd_BushouID].position + 1 &&
			nb6bushou[i1st_BushouID].tone != 4) {
			return gcnew String(nb6bushouname[i2nd_BushouID].familyname) + "�l";

			// (����)�l ���� 
		}
		else if (nb6bushouname[i2nd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�l";

			// (����)�a �i���j 
		}
		else {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname) + "�a";
		}

	}
	return "�����聓";
}


// 08 ������������ޏꍇ�̓�l��
String^ ���l�|���聓(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// ������� ���j&����<18&����-����>5 
		if (nb6bushouname[i2nd_BushouID].sex == 0 && getYearsOld(i2nd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i2nd_BushouID) > 5) {
			return "�������";

			// ���� ����&����<18&����-����>5 
		}
		else if (nb6bushouname[i2nd_BushouID].sex == 1 && getYearsOld(i2nd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i2nd_BushouID) > 5) {
			return "����";

			// ��� ����<30&����-����>20 
		}
		else if (getYearsOld(i2nd_BushouID) < 30 && getYearsOld(i1st_BushouID) - getYearsOld(i2nd_BushouID) > 20) {
			return "���";

			// �V���ڂ� ����>60&����-����>20 
		}
		else if (getYearsOld(i2nd_BushouID) > 60 && getYearsOld(i2nd_BushouID) - getYearsOld(i1st_BushouID) > 20) {
			return "�V���ڂ�";

			// �����V��
		}
		else if (nb6bushou[i2nd_BushouID].job == 0x40) {
			return "�����V��";

			// �������l
		}
		else if (nb6bushou[i2nd_BushouID].job == 0x20) {
			return "�������l";

			// ���V�A
		}
		else if (nb6bushou[i2nd_BushouID].job != 0x90 && nb6bushou[i2nd_BushouID].job == 0x90) {
			return "���V�A";

		}
		else {
			return gcnew String(nb6bushouname[i2nd_BushouID].fastname);
		}
	}
	return "���l�|���聓";
}


// 09�`0D �O�����������ޏꍇ�u�ȊO�v�̎O�l��
String^ ���O����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i3rd_BushouID && i3rd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		/*
		* 0A09�i�喼�������֌W�ɂ��镐�����w���ꍇ�̎O�l�́j
		*/
		// ���� ���O�e�q&����<�O��&�O�j (1==�喼)
		if (nb6bushouname[i1st_BushouID].position == 1 && is����͎����̕�(i1st_BushouID, i3rd_BushouID)) {
			return "����";

			// ��� ���O�e�q&����<�O��&�O��
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is����͎����̕�(i1st_BushouID, i3rd_BushouID)) {
			return "���";

			// �Z�� ���O�Z��&����<�O��&�O�j
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is����͎����̌Z(i1st_BushouID, i3rd_BushouID)) {
			return "�Z��";

			// �o�� ���O�Z��&����<�O��&�O��
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is����͎����̎o(i1st_BushouID, i3rd_BushouID)) {
			return "�o��";

			// �o�� ���O�Z��&����<�O��&�O��
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is�����͑���̌���(i1st_BushouID, i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (�O���a) �����֌W
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && is�����͑���̌���(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "�a";

			// ���B�� �O�g=0 
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && nb6bushouname[i3rd_BushouID].position == 0) {
			return "���B��";

			/*
			* 0A�i�����E�v�w�֌W�ɂ���喼���w���ꍇ�̎O�l�́j
			*/
			// �� ���O�e�q&����<�O��&�O�j
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is����͎����̕�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �� ���O�e�q&����<�O��&�O��
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is����͎����̕�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �Z ���O�Z��&����<�O��&�O�j
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is����͎����̌Z(i1st_BushouID, i3rd_BushouID)) {
			return "�Z";

			// �o ���O�Z��&����<�O��&�O��
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is����͎����̎o(i1st_BushouID, i3rd_BushouID)) {
			return "�o";

			// �� ���O�Z��&����>�O��&�O�j
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is����͎����̒�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �� ���O�Z��&����>�O��&�O��
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is����͎����̖�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �Ɠ� ���O�v�w&����
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is�����͑���̕v(i1st_BushouID, i3rd_BushouID)) {
			return "�Ɠ�";

			// �v ���O�v�w&���j
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is�����͑���̍�(i1st_BushouID, i3rd_BushouID)) {
			return "�v";

			// (�O��) ���O����&����>����&�O�� 
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is�����͑���̌���(i1st_BushouID, i3rd_BushouID) && getYearsOld(i1st_BushouID) > getYearsOld(i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (�O���a) �����֌W
		}
		else if (nb6bushouname[i3rd_BushouID].position == 1 && is�����͑���̌���(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "�a";

			/*
			* 0B�i�������喼�ł���A�����֌W�ł͂Ȃ��ꍇ�̎O�l�́j
			*/
			// ���� ����<�O�d&���30&�O�50&�H&�O�j 
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 &&
			(getYearsOld(i1st_BushouID) < nb6bushou[i3rd_BushouID].work) && getYearsOld(i1st_BushouID) <= 30 &&
			getYearsOld(i3rd_BushouID) >= 50 && nb6bushouname[i3rd_BushouID].sex == 0) {
			return "����";

			// (�O��) ���O����&����>����&�O�� 
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && nb6bushouname[i3rd_BushouID].position == 1 && getYearsOld(i1st_BushouID) > getYearsOld(i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (�O���a) �����֌W
		}
		else if (nb6bushouname[i1st_BushouID].position == 1 && nb6bushouname[i3rd_BushouID].position == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "�a";

			/*
			*	0C�i���肪�����̑喼�̏ꍇ�̎O�l�́j
			*/
			// �� ����<���d&���30&���50&���j 
		}
		else if (is����͎����̑喼(i1st_BushouID, i3rd_BushouID) &&
			(getYearsOld(i3rd_BushouID) < nb6bushou[i1st_BushouID].work) && getYearsOld(i3rd_BushouID) <= 30 &&
			getYearsOld(i1st_BushouID) >= 50 && nb6bushouname[i3rd_BushouID].sex == 0) {
			return "��";

			// ���ٗl 33%
		}
		else if (is����͎����̑喼(i1st_BushouID, i3rd_BushouID) && rand() % 3 == 0) {
			return "���ٗl";

			// (����)�l �i���j 
		}
		else if (is����͎����̑喼(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "�l";

			/*
			* 0D�i���̑��̏ꍇ�̎O�l�́j
			*/
			// �� ���O�e�q&����<�O��&�O�j
		}
		else if (is����͎����̕�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �� ���O�e�q&����<�O��&�O��
		}
		else if (is����͎����̕�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �Z ���O�Z��&����<�O��&�O�j
		}
		else if (is����͎����̌Z(i1st_BushouID, i3rd_BushouID)) {
			return "�Z";

			// �o ���O�Z��&����<�O��&�O��
		}
		else if (is����͎����̎o(i1st_BushouID, i3rd_BushouID)) {
			return "�o";

			// �� ���O�Z��&����>�O��&�O�j
		}
		else if (is����͎����̒�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �� ���O�Z��&����>�O��&�O��
		}
		else if (is����͎����̖�(i1st_BushouID, i3rd_BushouID)) {
			return "��";

			// �Ɠ� ���O�v�w&����
		}
		else if (is�����͑���̕v(i1st_BushouID, i3rd_BushouID)) {
			return "�Ɠ�";

			// �v ���O�v�w&���j
		}
		else if (is�����͑���̍�(i1st_BushouID, i3rd_BushouID)) {
			return "�v";

			// (�O��) ���O����&����>����&�O�� 
		}
		else if (is�����͑���̌���(i1st_BushouID, i3rd_BushouID) && getYearsOld(i1st_BushouID) > getYearsOld(i3rd_BushouID) && nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (�O���a) �����֌W
		}
		else if (is�����͑���̌���(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "�a";

			// (�O��) ���g���O�g(�����ԍ��I�ɂ͎��g���O�g)&����O��&����=�O��  (�g��=0:�B�� 1:�喼 2:�h�V 3:�ƘV �c�Ȃ̂ŁA�ԍ�����������������)
		}
		else if (nb6bushouname[i1st_BushouID].position <= nb6bushouname[i3rd_BushouID].position &&
			getYearsOld(i3rd_BushouID) >= getYearsOld(i3rd_BushouID) && is�����Ƒ���͓����喼�Ə���(i1st_BushouID, i3rd_BushouID)) {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);

			// (�O��)�l ���g>�O�g+1(3�K�����������̐g���Ƃ�������)&������4 
		}
		else if (nb6bushouname[i1st_BushouID].position > nb6bushouname[i3rd_BushouID].position + 1 &&
			nb6bushou[i1st_BushouID].tone != 4) {
			return gcnew String(nb6bushouname[i3rd_BushouID].familyname) + "�l";

			// (�O��)�l �O�� 
		}
		else if (nb6bushouname[i3rd_BushouID].sex == 1) {
			return gcnew String( nb6bushouname[i3rd_BushouID].fastname) + "�l";

			// (����)�a �i���j 
		}
		else {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname) + "�a";
		}

	}
	return "���O����";
}




// 0E�i��O�҂��������ޏꍇ�̎O�l�́j 
String^ ���l�|�O����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i3rd_BushouID && i3rd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// ������� �O�j&�O��<18&����-�O��>5 
		if (nb6bushouname[i3rd_BushouID].sex == 0 && getYearsOld(i3rd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i3rd_BushouID) > 5) {
			return "�������";

			// ���� �O��&�O��<18&����-�O��>5 
		}
		else if (nb6bushouname[i3rd_BushouID].sex == 1 && getYearsOld(i3rd_BushouID) < 18 && getYearsOld(i1st_BushouID) - getYearsOld(i3rd_BushouID) > 5) {
			return "����";

			// ��� �O��<30&����-�O��>20 
		}
		else if (getYearsOld(i3rd_BushouID) < 30 && getYearsOld(i1st_BushouID) - getYearsOld(i3rd_BushouID) > 20) {
			return "���";

			// �V���ڂ� �O��>60&�O��-����>20 
		}
		else if (getYearsOld(i3rd_BushouID) > 60 && getYearsOld(i3rd_BushouID) - getYearsOld(i1st_BushouID) > 20) {
			return "�V���ڂ�";

			// (�O��) �i���j 
		}
		else {
			return gcnew String(nb6bushouname[i3rd_BushouID].fastname);
		}
	}
	return "���l�|�O����";
}

























bool �����L�����P��(int i1st_BushouID, int i2nd_BushouID) {

	// ���������A�Ƃ������ƁB
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���g>���g (�����̐g���̕������Ƃ�������)
		if (nb6bushouname[i1st_BushouID].position > nb6bushouname[i2nd_BushouID].position) {
			return true;
		}
	}
	return false;
}

bool �����L�����Q��(int i1st_BushouID, int i2nd_BushouID) {

	// �����֌W��A�������̔т����A��������A�Ƃ������ƁB
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ��������&������� 
		if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID)) {
			return true;
		}
		// ����͎����̉Ɛb
		if (is����͎����̉Ɛb(i1st_BushouID, i2nd_BushouID)) {
			return true;
		}
		// �����Ƃɏ������Ă��� & ������� & ���g<���g(�����̕����g��������)
		if (is�����Ƒ���͓����喼�Ə���(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].position < nb6bushouname[i2nd_BushouID].position) {
			return true;
		}
	}
	return false;
}

int �����L�����s��(int i1st_BushouID, int i2nd_BushouID) {
	// ����̕��������Ȃ��̂ł���΁A1�ƂȂ�B
	if (i2nd_BushouID == 0xFFFF) {
		return 1;
	}

	// ���L�����Q�𖞂����B(�������̔тł��A��������)
	else if (�����L�����Q��(i1st_BushouID, i2nd_BushouID)) {
		return 1;
	}
	// ���L�����P�𖞂����B(��������)
	else if (�����L�����P��(i1st_BushouID, i2nd_BushouID)) {
		return 2;
	}
	// ���L�����P�����L�����Q���������Ȃ�(�����̕����g���͏�)
	else {
		// ����ȊO
		return 3;
	}
}



// �`�ł� �`�� �`����
String^ ���ł���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �ł� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�ł�";

				// �� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "��";

				// ���� �i���j 
			}
			else {
				return "����";
			}

			// Group B
		}
		else {
			// �ł� �i���j 
			return "�ł�";
		}
	}

	return "���ł���";
}



// �`�ł��� �`�ł����邩 �`��
String^ ���ł�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �ł��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�ł���";

				// �� �i���j 
			}
			else {
				return "��";
			}

			// Group B
		}
		else {
			// �ł��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�ł���";

				// �ł����邩 ����=5 || ���E=1or3(�E��or����)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "�ł����邩";

				// �ł��� �i���j 
			}
			else {
				return "�ł���";
			}
		}
	}

	return "���ł�����";
}



// �ł��傤 �`����낤 �`�ł��낤 �`���낤
String^ ���ł��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {

	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �ł��傤 ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�ł��傤";

				// �ł��낤 ����=3 || ����=1 || ����=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 3 || nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "�ł��낤";

				// ���낤 ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "���낤";

				// ����낤 (��)
			}
			else {
				return "����낤";
			}

			// Group B
		}
		else {
			// �ł��傤
			return "�ł��傤";
		}
	}

	return "���ł��傤��";
}



// �`�ł��� �`������� �`�ł����� �`������
String^ ���ł�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �ł��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�ł���";

				// �ł����� ����=3 || ����=1 || ����=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 3 || nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "�ł�����";

				// ������ ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "������";

				// ������� (��)
			}
			else {
				return "�������";
			}

			// Group B
		}
		else {
			// �ł���
			return "�ł���";
		}
	}

	return "���ł�����";
}



// �`����܂� �`�������܂� �`������ �`���� �`�������
String^ ������܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ����܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂�";

				// ������� ����=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "�������";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {
			// ����܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂�";

				// ������ ����=5 || ���E=1or3(�E��or����)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "������";

				// ����܂� ����=�����喼�Ə��� 
			}
			else if (is�����Ƒ���͓����喼�Ə���(i1st_BushouID, i2nd_BushouID)) {
				return "����܂�";

				// �������܂� �i���j 
			}
			else {
				return "�������܂�";

			}
		}
	}

	return "������܂���";
}


// �`����܂��� �`�������܂��� �`������� �`�Ȃ� �`�������� �`����܂���
String^ ������܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ����܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂���";

				// �������� ����=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "��������";

				// �Ȃ� (��)
			}
			else {
				return "�Ȃ�";
			}

			// Group B
		}
		else {
			// ����܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂���";

				// ������� ����=5 || ���E=1or3(�E��or����)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "�������";

				// ����܂��� ����=�����喼�Ə��� 
			}
			else if (is�����Ƒ���͓����喼�Ə���(i1st_BushouID, i2nd_BushouID)) {
				return "����܂�";

				// �������܂��� �i���j 
			}
			else {
				return "�������܂�";

			}
		}
	}

	return "������܂���";
}




// �`���܂� �`������ �`����
String^ �����܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "���܂�";

				// ���� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "����";

				// ������ (��)
			}
			else {
				return "������";
			}

			// Group B
		}
		else {
			// ������ ����=5 || ���j
			if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushouname[i1st_BushouID].sex == 0) {
				return "������";

				// ���܂� (��)
			}
			else {
				return "���܂�";
			}
		}
	}

	return "�����܂���";
}

// �`���܂��� �`�������� �`���� �`���� �`���܂���
String^ �����܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "���܂���";

				// ���� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "����";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {
			// ���܂��� ����=1 || ����=3 || ����
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "���܂���";

				// �������� ����=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 5) {
				return "��������";

				// ���܂��� (��)
			}
			else {
				return "���܂���";
			}
		}
	}

	return "�����܂���";
}



// �`���܂��傤 �`�������� �`���悤
String^ �����܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���܂��傤 ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "���܂��傤";

				// ���悤 ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "���悤";

				// �������� (��)
			}
			else {
				return "��������";
			}

			// Group B
		}
		else {
			// �������� ����=5 || ���j
			if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushouname[i1st_BushouID].sex == 0) {
				return "��������";

				// ���܂��傤 (��)
			}
			else {
				return "���܂��傤";
			}
		}
	}

	return "�����܂��傤��";
}



// �`���܂��傤 �`����  (�����܂��傤�Ȃ�)
String^ �����܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���܂��傤 ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "���܂��傤";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {
			// ���܂��傤 (��)
			return "���܂��傤";
		}
	}

	return "�����܂��傤��";
}



// �`���܂��傤 �`����  (�s���܂��傤�Ȃ�)
String^ �����܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���܂��傤 ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "���܂��傤";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {
			// ���܂��傤 (��)
			return "���܂��傤";
		}
	}

	return "�����܂��傤��";
}


// �`���܂��傤 �`����  (�H�c �����܂��傤���̕����ǂ���)
String^ �����܂��傤�Q��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���� (��)
			return "����";

			// Group B
		}
		else {
			// ���܂��傤 (��)
			return "���܂��傤";
		}
	}

	return "�����܂��傤�Q��";
}



// �`���܂��傤 �`�Ƃ�  (�҂��܂��傤�Ȃ�)
String^ �����܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �Ƃ� (��)
			return "�Ƃ�";

			// Group B
		}
		else {
			// ���܂��傤 (��)
			return "���܂��傤";
		}
	}

	return "�����܂��傤��";
}


// 29 �`�݂܂��傤 �`����  (�U�ߍ��݂܂��傤�Ȃ�)
String^ ���݂܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���� (��)
			return "����";

			// Group B
		}
		else {
			// �݂܂��傤 (��)
			return "�݂܂��傤";
		}
	}

	return "�����܂��傤��";
}


// �`�܂��傤 �`�悤  (���̑��̈�ʃp�^�[���B���Ă܂��傤�Ȃ�)
String^ ���܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �܂��傤 ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�܂��傤";

				// �悤 (��)
			}
			else {
				return "�悤";
			}

			// Group B
		}
		else {
			// �܂��傤 (��)
			return "�܂��傤";
		}
	}

	return "���܂��傤��";
}



// �`��܂��傤 �`�낤  (�Q��܂��傤�Ȃ�)
String^ ����܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ��܂��傤 ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "��܂��傤";

				// �낤 (��)
			}
			else {
				return "�낤";
			}

			// Group B
		}
		else {
			// ��܂��傤 (��)
			return "��܂��傤";
		}
	}

	return "����܂��傤��";
}


// �`���܂��傤 �`����  (�}���܂��傤�Ȃ�)
String^ �����܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���� (��)
			return "����";

			// Group B
		}
		else {
			// ���܂��傤 (��)
			return "���܂��傤";
		}
	}

	return "�����܂��傤��";
}


// �`�т܂��傤 �`�ڂ��@(�V�т܂��傤�Ȃ�)
String^ ���т܂��傤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �ڂ� (��)
			return "�ڂ�";

			// Group B
		}
		else {
			// �т܂��傤 (��)
			return "�т܂��傤";
		}
	}

	return "���т܂��傤��";
}



// 35 �`���܂� �`������ �`���� �`���� �`������� �`����܂�
String^ �����܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ����܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂�";

				// �������� ����=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "�������";

				// ���� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "����";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {
			// ����܂� ����=1 or ����=3 or ���� 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂�";

				// ������ ����=5 || ���E=1or3(�E��or����)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "������";

				// ���܂� (���j 
			}
			else {
				return "���܂�";

			}
		}
	}

	return "�����܂���";
}



// 37 �`���܂��� �`������� �`����� �`����� �`�������� �`����܂���
String^ �����܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ����܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂���";

				// �������� ����=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "��������";

				// ����� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "�����";

				// ����� (��)
			}
			else {
				return "�����";
			}

			// Group B
		}
		else {
			// ����܂��� ����=1 or ����=3 or ���� 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂���";

				// ������� ����=5 || ���E=1or3(�E��or����)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "�������";

				// ���܂��� (���j 
			}
			else {
				return "���܂���";

			}
		}
	}

	return "�����܂���";
}



// 39 �`���܂��� �`�������� �`������ �`���� �`��������� �`����܂���
String^ �����܂�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ����܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂���";

				// ��������� ����=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 3) {
				return "���������";

				// ���� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "����";

				// ������ (��)
			}
			else {
				return "������";
			}

			// Group B
		}
		else {
			// ����܂��� ����=1 or ����=3 or ���� 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "����܂���";

				// �������� ����=5 || ���E=1or3(�E��or����)
			}
			else if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushou[i1st_BushouID].job == 0x10 || nb6bushou[i1st_BushouID].job == 0x30) {
				return "��������";

				// ���܂��� (���j 
			}
			else {
				return "���܂���";

			}
		}
	}

	return "�����܂�����";
}



// �`�܂� �`�� �`��܂�
String^ ���܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�܂�";

				// �� (��)
			}
			else {
				return "��";
			}

			// Group B
		}
		else {

			// �܂� ����=�����喼�Ə��� 
			if (is�����Ƒ���͓����喼�Ə���(i1st_BushouID, i2nd_BushouID)) {
				return "�܂�";

				// ��܂��i���j 
			}
			else {
				return "��܂�";

			}
		}
	}

	return "���܂���";
}



// �`��܂��� �`���
String^ ����܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ��܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "��܂���";

				// ��� (��)
			}
			else {
				return "���";
			}

			// Group B
		}
		else {

			// ��܂���i���j 
			return "��܂���";
		}
	}

	return "����܂���";
}


// �`�܂��� �`�� �`�˂� �`�܂���
String^ ���܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�܂���";

				// �˂� ����=2 && ���g<=3
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 && nb6bushouname[i2nd_BushouID].position <= 3) {
				return "�˂�";

				// �� (��)
			}
			else {
				return "��";
			}

			// Group B
		}
		else {
			// �܂��� ����=1 || ����=5
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "�܂���";

				// �܂��� (���j 
			}
			else {
				return "�܂���";

			}
		}
	}

	return "���܂���";
}



// �`�܂��� �`��
String^ ���܂�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�܂���";

				// �� (��)
			}
			else {
				return "��";
			}

			// Group B
		}
		else {

			// �܂��� (���j 
			return "�܂���";

		}
	}

	return "���܂�����";
}



// �`��܂��� �`����
String^ ����܂�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ��܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "��܂���";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {

			// ��܂��� (���j 
			return "��܂���";

		}
	}

	return "����܂�����";
}



// �`�܂���ł��� �`�Ȃ�����
String^ ���܂���ł�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �܂���ł��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�܂���ł���";

				// �Ȃ����� (��)
			}
			else {
				return "�Ȃ�����";
			}

			// Group B
		}
		else {

			// �܂���ł��� (���j 
			return "�܂���ł���";

		}
	}

	return "���܂���ł�����";
}



// �`�v���܂� �`�����܂� �`�v��
String^ ���v���܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �v���܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�v���܂�";

				// �v�� (��)
			}
			else {
				return "�v��";
			}

			// Group B
		}
		else {

			// �����܂� ����=1 or ����=3 or ����
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "�����܂�";

				// �v���܂� (��)
			}
			else {
				return "�v���܂�";
			}

		}
	}

	return "���v���܂���";
}


// �`�Q��܂��� �`�Q�サ�܂��� �`�Q����
String^ ���Q��܂�����(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �Q��܂��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�Q��܂���";

				// �Q���� (��)
			}
			else {
				return "�Q����";
			}

			// Group B
		}
		else {

			// �Q��܂��� ����
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�Q��܂���";

				// �Q�サ�܂��� ����=1 or ����=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 5) {
				return "�Q�サ�܂���";

				// �Q��܂��� (��)
			}
			else {
				return "�Q��܂���";
			}

		}
	}

	return "���Q��܂�����";
}



// �`�������� �`������ �`����
String^ ���������ꁓ(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ������ ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "������";

				// ���� (��)
			}
			else {
				return "����";
			}

			// Group B
		}
		else {

			// ������ ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "������";

				// �������� (��)
			}
			else {
				return "��������";
			}

		}
	}

	return "���������ꁓ";
}



// �`���݂܂��� �`�\����Ȃ� �`���܂� �`���܂� �`���߂�Ȃ���
String^ �����݂܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ���߂�Ȃ��� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "���߂�Ȃ���";

				// ���܂� ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "���܂�";

				// ���܂� (��)
			}
			else {
				return "���܂�";
			}

			// Group B
		}
		else {
			// �\����Ȃ� ����=5 or ���j 
			if (nb6bushou[i1st_BushouID].tone == 5 || nb6bushouname[i1st_BushouID].sex == 0) {
				return "�\����Ȃ�";

				// ���݂܂��� (���j 
			}
			else {
				return "���݂܂���";

			}
		}
	}

	return "�����݂܂���";
}

// �`�肢�܂� �`���肢������ �`�肨�� �`�肤 �`���肢���܂�
String^ ���肢�܂���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// �肢�܂� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "�肢�܂�";

				// �肤 ����=2 || ����=4
			}
			else if (nb6bushou[i1st_BushouID].tone == 2 || nb6bushou[i1st_BushouID].tone == 4) {
				return "�肤";

				// �肨�� (��)
			}
			else {
				return "�肨��";
			}

			// Group B
		}
		else {
			// ���肵�܂� ����=1 or ����=3 or ���� 
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "���肢���܂�";

				// ���肢������ ����=5
			}
			else if (nb6bushou[i1st_BushouID].tone == 5) {
				return "���肢������";

				// �肢�܂� (���j 
			}
			else {
				return "�肢�܂�";

			}
		}
	}

	return "���肢�܂���";
}



// �`�悢 �`��낵��
String^ ���悢��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���L�����s�̂ǂꂪ���Ă͂܂邩�H �ǂ�ɂ����Ă͂܂�Ȃ������痪�L�����x�łǂ��炩�ɓ��Ă͂܂�B
		int Group = �����L�����s��(i1st_BushouID, i2nd_BushouID);

		// Group A
		if (Group == 1) {

			// ��낵�� ���� 
			if (nb6bushouname[i1st_BushouID].sex == 1) {
				return "��낵��";

				// �悢 (��)
			}
			else {
				return "�悢";
			}

			// Group B
		}
		else {

			// ��낵�� ����=1 or ����=3 or ����
			if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
				return "��낵��";

				// �悢 (��)
			}
			else {
				return "�悢";
			}

		}
	}

	return "���悢��";
}









// �`�� �`��
String^ �����i�P�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "�����i�P�j��";
}




// �`�� �`�Ȃ�
String^ �����i�Q�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �Ȃ� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�Ȃ�";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "�����i�Q�j��";
}





// �`�� �`��
String^ �����i�R�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "�����i�R�j��";
}



// �`�� �`������
String^ �����i�S�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ������ ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "������";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "�����i�S�j��";
}





// �`�� �`�� �`���� �`��
String^ �����i�P�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// ���� ����=3  
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "����";

			// �� ����=2&���g=1
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && nb6bushouname[i1st_BushouID].position == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "�����i�P�j��";
}




// �`�� �`�� �`���� �`���
String^ �����i�Q�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ��� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "���";

			// ���� ����=3  
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "����";

			// �� ����=2&���g=1
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && nb6bushouname[i1st_BushouID].position == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "�����i�Q�j��";
}







// �`�� �`��
String^ ���ȁi�P�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "���ȁi�P�j��";
}





// �`�� �`��
String^ ���ȁi�Q�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "���ȁi�Q�j��";
}




// �`(����) �`��
String^ ����i�P�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// (����) �i���j 
		}
		else {
			return "";
		}
	}

	return "����i�P�j��";
}




// �`�� �`�킢
String^ ����i�Q�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// �킢 ����=2&���50 
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && getYearsOld(i1st_BushouID) >= 50) {
			return "�킢";

			// �� �i���j 
		}
		else {
			return "��";

		}
	}

	return "����i�Q�j";
}






// �`�Ȃ� �`�̂� �`�˂� 
String^ ���Ȃ���(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �˂� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�˂�";

			// �̂� ����=2&���50 
		}
		else if (nb6bushou[i1st_BushouID].tone == 2 && getYearsOld(i1st_BushouID) >= 50) {
			return "�̂�";

			// �Ȃ� �i���j 
		}
		else {
			return "�Ȃ�";

		}
	}

	return "���Ȃ���";
}






// �`�� �`(����)
String^ �����i�P�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// (����) ��������&������� 
		if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID)) {
			return "";

			// �� �i���j 
		}
		else {
			return "��";

		}
	}

	return "�����i�P�j��";
}




// �`�� �`(����)
String^ �����i�Q�j��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// (����) ��������&������� 
		if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) >= getYearsOld(i2nd_BushouID)) {
			return "";

			// �� ����=1or3or���� 
		}
		else if (nb6bushou[i1st_BushouID].tone == 1 || nb6bushou[i1st_BushouID].tone == 3 || nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

		}
		else {
			return "";
		}
	}

	return "�����i�Q�j��";
}







// �͂͂� �ӂӂ� ������ ���͂� ��͂� �ӂ� ���ӂ� ���ق� 
String^ ���͂͂́�(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���ق� ����&���25 
		if (nb6bushouname[i1st_BushouID].sex == 1 && getYearsOld(i1st_BushouID) >= 25) {
			return "���ق�";

			// ���ӂ� ����
		}
		else if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "���ӂ�";

			// ��͂� ����=2
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "��͂�";

			// �ӂ� ����=0
		}
		else if (nb6bushou[i1st_BushouID].tone == 0) {
			return "�ӂ�";

			// ���͂� ���20 
		}
		else if (getYearsOld(i1st_BushouID) <= 20) {
			return "���͂�";

			// ������ ���B�ȉ�&���큅50
		}
		else if (nb6bushou[i1st_BushouID].aptitudebat <= 1 && getBushouBat(i1st_BushouID) <= 50) {
			return "������";

			// �ӂӂ� ���B�ȉ�
		}
		else if (nb6bushou[i1st_BushouID].aptitudebat <= 1) {
			return "�ӂӂ�";

			// �͂͂� �i���j 
		}
		else {
			return "�͂͂�";
		}
	}

	return "���͂͂́�";
}



// �`�� �`��
String^ ������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "������";
}




// ���ނ� �܂� 
String^ �����ނށ�(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �܂� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�܂�";

			// ���ނ� �i���j 
		}
		else {
			return "���ނ�";
		}
	}

	return "�����ނށ�";
}



// ���� �܂�
String^ ��������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �܂� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�܂�";

			// ���� �i���j 
		}
		else {
			return "����";
		}
	}

	return "��������";
}




// �܂�ʁc �������낭����܂��� 
String^ ���܂�ʁ�(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �������낭����܂��� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�������낭����܂���";

			// �܂�ʁc �i���j 
		}
		else {
			return "�܂�ʁc";
		}
	}

	return "���܂�ʁc��";
}




// ��� �� 
String^ �������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "��";

			// ��� �i���j 
		}
		else {
			return "���";
		}
	}

	return "�������";
}




// �� �Ă�
String^ ������(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �Ă� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�Ă�";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "������";
}





// �� ���� 
String^ ���ꁓ(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���� ����<����  
		if (getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID)) {
			return "����";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "���ꁓ";
}






// ���񂺂悤 ����悤 ���񂺂܂��傤 
String^ �����񂺂悤��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���񂺂܂��傤 ��������&����<���� 
		if (is�����͑���̌���(i1st_BushouID, i2nd_BushouID) && getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID)) {
			return "���񂺂܂��傤";

			// ���񂺂܂��傤 ����  
		}
		else if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "���񂺂܂��傤";

			// ����悤
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "����悤";

			// ���񂺂悤 �i���j 
		}
		else {
			return "���񂺂悤";
		}
	}

	return "�����񂺂悤��";
}


// �ꑰ �e�q �o�� �o�� �Z�� �v�w �Z�� �o�� �o�� �Z�� 
String^ ���ꑰ��(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (is�����͑���̐e(i1st_BushouID, i2nd_BushouID)) {
			return "�e�q";

			// �Z��
		}
		else if (is�����Ƒ���͌Z��(i1st_BushouID, i2nd_BushouID)) {
			return "�Z��";

			// �o��
		}
		else if (is�����Ƒ���͎o��(i1st_BushouID, i2nd_BushouID)) {
			return "�o��";

			// �o��
		}
		else if (is�����Ƒ���͎o��(i1st_BushouID, i2nd_BushouID)) {
			return "�o��";

			// �Z�� 
		}
		else if (is�����Ƒ���͌Z��(i1st_BushouID, i2nd_BushouID)) {
			return "�Z��";

		}
		else if (is�����͑���̕v(i1st_BushouID, i2nd_BushouID)) {
			return "�v�w";

		}
		else if (is�����͑���̍�(i1st_BushouID, i2nd_BushouID)) {
			return "�v�w";

		}
		else {
			return "�ꑰ";

		}
	}

	return "���ꑰ��";
}




// �ł����� �����A�͂͂� �ł�����邼�� �ł��� 
String^ ���ł����道(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �ł��� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "���񂺂܂��傤";

			// �����A�͂͂� ����=2
		}
		else if (nb6bushou[i1st_BushouID].tone == 2) {
			return "�����A" + ���͂͂́�(i1st_BushouID, i2nd_BushouID, i3rd_BushouID);

			// �ł�����邼�� ����=3 
		}
		else if (nb6bushou[i1st_BushouID].tone == 3) {
			return "�ł�����邼��";

			// �ł����� �i���j 
		}
		else {
			return "�ł�����";
		}
	}

	return "���ł����道";
}




// ���� ���܂��� 
String^ �����ȁ�(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���܂��� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "���܂���";


			// ���� �i���j 
		}
		else {
			return "����";
		}
	}

	return "�����ȁ�";
}





// �Ă݂� �Ȃ���
String^ ���Ă݂恓(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �Ȃ��� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�Ȃ���";

			// �Ă݂� �i���j 
		}
		else {
			return "�Ă݂�";
		}
	}

	return "���Ă݂恓";
}



// �� �܂�
String^ ���恓(int i1st_BushouID, int i2nd_BushouID, int i3rd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �܂� ���� 
		if (nb6bushouname[i1st_BushouID].sex == 1) {
			return "�܂�";

			// �� �i���j 
		}
		else {
			return "��";
		}
	}

	return "���恓";
}












// 00�i����Ɍh�ӂ𕥂��K�v���Ȃ��ꍇ�̎��́j 
String^ ���ω����^::�킵(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���킵��(i1st, i2nd, i3rd);
}

// 02�i���̑��̏ꍇ�̎��́j 
String^ ���ω����^::��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::������(i1st, i2nd, i3rd);
}

// 03�i���L�`�e���j  
String^ ���ω����^::�䂪(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���䂪��(i1st, i2nd, i3rd);
}

// 04�`07 ������������ޏꍇ�u�ȊO�v�̓�l��
String^ ���ω����^::����(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����聓(i1st, i2nd, i3rd);
}

// 08 ������������ޏꍇ�̓�l��
String^ ���ω����^::�l�|����(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���l�|���聓(i1st, i2nd, i3rd);
}

// 09�`0D �O�����������ޏꍇ�u�ȊO�v�̎O�l��
String^ ���ω����^::�O��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���O����(i1st, i2nd, i3rd);
}

// 0E�i��O�҂��������ޏꍇ�̎O�l�́j 
String^ ���ω����^::�l�|�O��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���l�|�O����(i1st, i2nd, i3rd);
}



// 0F �`�ł� �`�� ����
String^ ���ω����^::�ł�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ł���(i1st, i2nd, i3rd);
}

// 11 �`�ł��� �`�ł����邩 �`��
String^ ���ω����^::�ł���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ł�����(i1st, i2nd, i3rd);
}
// 13 �`�ł��傤 �`����낤 �`�ł��낤 �`���낤
String^ ���ω����^::�ł��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ł��傤��(i1st, i2nd, i3rd);
}
// 15 �`�ł��� �`������� �`�ł����� �`������
String^ ���ω����^::�ł���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ł�����(i1st, i2nd, i3rd);
}

// 17 �`����܂� �`�������܂� �`������ �`���� �`�������
String^ ���ω����^::����܂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::������܂���(i1st, i2nd, i3rd);
}

// 19 �`����܂��� �`�������܂��� �`������� �`�Ȃ� �`�������� �`����܂���
String^ ���ω����^::����܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::������܂���(i1st, i2nd, i3rd);
}

// 1B �`���܂� �`������ �`����
String^ ���ω����^::���܂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂���(i1st, i2nd, i3rd);
}

// 1D �`���܂��� �`�������� �`���� �`���� �`���܂���
String^ ���ω����^::���܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂���(i1st, i2nd, i3rd);
}
// 1F �`���܂��傤 �`�������� �`���悤
String^ ���ω����^::���܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂��傤��(i1st, i2nd, i3rd);
}


// 21 �`���܂��傤 �`����  (�����܂��傤�Ȃ�)
String^ ���ω����^::���܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂��傤��(i1st, i2nd, i3rd);
}

// 23 �`���܂��傤 �`����  (�s���܂��傤�Ȃ�)
String^ ���ω����^::���܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂��傤��(i1st, i2nd, i3rd);
}

// 25 �`���܂��傤 �`����  (�H�c �����܂��傤���̕����ǂ���)
String^ ���ω����^::���܂��傤�Q(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂��傤�Q��(i1st, i2nd, i3rd);
}

// 27 �`���܂��傤 �`�Ƃ�  (�҂��܂��傤�Ȃ�)
String^ ���ω����^::���܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂��傤��(i1st, i2nd, i3rd);
}

// 29 �`�݂܂��傤 �`����  (�U�ߍ��݂܂��傤�Ȃ�)
String^ ���ω����^::�݂܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���݂܂��傤��(i1st, i2nd, i3rd);
}

// 2B �`�܂��傤 �`�悤  (���̑��̈�ʃp�^�[���B���Ă܂��傤�Ȃ�)
String^ ���ω����^::�܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���܂��傤��(i1st, i2nd, i3rd);
}

// 2D �`��܂��傤 �`�낤  (�Q��܂��傤�Ȃ�)
String^ ���ω����^::��܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::����܂��傤��(i1st, i2nd, i3rd);
}

// 31 �`���܂��傤 �`����  (�}���܂��傤�Ȃ�)
String^ ���ω����^::���܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂��傤��(i1st, i2nd, i3rd);
}

// 33 �`�т܂��傤 �`�ڂ��@(�V�т܂��傤�Ȃ�)
String^ ���ω����^::�т܂��傤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���т܂��傤��(i1st, i2nd, i3rd);
}


// 35 �`���܂� �`������ �`���� �`���� �`������� �`����܂�
String^ ���ω����^::���܂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂���(i1st, i2nd, i3rd);
}

// 37 �`���܂��� �`������� �`����� �`����� �`�������� �`����܂���
String^ ���ω����^::���܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂���(i1st, i2nd, i3rd);
}

// 39 �`���܂��� �`�������� �`������ �`���� �`��������� �`����܂���
String^ ���ω����^::���܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����܂�����(i1st, i2nd, i3rd);
}

// 3B �`�܂� �`�� �`��܂�
String^ ���ω����^::�܂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���܂���(i1st, i2nd, i3rd);
}

// 3D �`��܂��� �`���
String^ ���ω����^::��܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::����܂���(i1st, i2nd, i3rd);
}

// 3F �`�܂��� �`�� �`�˂� �`�܂���
String^ ���ω����^::�܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���܂���(i1st, i2nd, i3rd);
}

// 41 �`�܂��� �`��
String^ ���ω����^::�܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���܂�����(i1st, i2nd, i3rd);
}

// 43 �`��܂��� �`����
String^ ���ω����^::��܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::����܂�����(i1st, i2nd, i3rd);
}

// 45 �`�܂���ł��� �`�Ȃ�����
String^ ���ω����^::�܂���ł���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���܂���ł�����(i1st, i2nd, i3rd);
}

// 47 �`�v���܂� �`�����܂� �`�v��
String^ ���ω����^::�v���܂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���v���܂���(i1st, i2nd, i3rd);
}

// 49 �`�Q��܂��� �`�Q�サ�܂��� �`�Q����
String^ ���ω����^::�Q��܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���Q��܂�����(i1st, i2nd, i3rd);
}

// 4B �`�������� �`������ �`����
String^ ���ω����^::��������(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���������ꁓ(i1st, i2nd, i3rd);
}

// 4D �`���݂܂��� �`�\����Ȃ� �`���܂� �`���܂� �`���߂�Ȃ���
String^ ���ω����^::���݂܂���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����݂܂���(i1st, i2nd, i3rd);
}

// 4F �`�肢�܂� �`���肢������ �`�肨�� �`�肤 �`���肢���܂�
String^ ���ω����^::�肢�܂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���肢�܂���(i1st, i2nd, i3rd);
}

// 51 �`�悢 �`��낵��
String^ ���ω����^::�悢(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���悢��(i1st, i2nd, i3rd);
}






// �`�� �`��
String^ ���ω����^::��_�P(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�P�j��(i1st, i2nd, i3rd);
}

// �`�� �`�Ȃ�
String^ ���ω����^::��_�Q(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�Q�j��(i1st, i2nd, i3rd);
}

// �`�� �`��
String^ ���ω����^::��_�R(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�R�j��(i1st, i2nd, i3rd);
}

// �`�� �`������
String^ ���ω����^::��_�S(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�S�j��(i1st, i2nd, i3rd);
}

// �`�� �`�� �`���� �`��
String^ ���ω����^::��_�P(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�P�j��(i1st, i2nd, i3rd);
}

// �`�� �`�� �`���� �`���
String^ ���ω����^::��_�Q(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�Q�j��(i1st, i2nd, i3rd);
}

// �`�� �`��
String^ ���ω����^::��_�P(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ȁi�P�j��(i1st, i2nd, i3rd);
}

// �`�� �`��
String^ ���ω����^::��_�Q(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ȁi�Q�j��(i1st, i2nd, i3rd);
}

// �`(����) �`��
String^ ���ω����^::��_�P(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::����i�P�j��(i1st, i2nd, i3rd);
}

// �`�� �`�킢
String^ ���ω����^::��_�Q(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::����i�Q�j��(i1st, i2nd, i3rd);
}

// �`�Ȃ� �`�̂� �`�˂� 
String^ ���ω����^::�Ȃ�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���Ȃ���(i1st, i2nd, i3rd);
}

// �`�� �`(����)
String^ ���ω����^::��_�P(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�P�j��(i1st, i2nd, i3rd);
}

// �`�� �`(����)
String^ ���ω����^::��_�Q(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����i�Q�j��(i1st, i2nd, i3rd);
}

// �͂͂� �ӂӂ� ������ ���͂� ��͂� �ӂ� ���ӂ� ���ق� 
String^ ���ω����^::�͂͂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���͂͂́�(i1st, i2nd, i3rd);
}

// �`�� �`��
String^ ���ω����^::��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::������(i1st, i2nd, i3rd);
}

// ���ނ� �܂� 
String^ ���ω����^::���ނ�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����ނށ�(i1st, i2nd, i3rd);
}

// ���� �܂�
String^ ���ω����^::����(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::��������(i1st, i2nd, i3rd);
}

// �܂�ʁc �������낭����܂��� 
String^ ���ω����^::�܂��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���܂�ʁ�(i1st, i2nd, i3rd);
}

// ��� �� 
String^ ���ω����^::���(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�������(i1st, i2nd, i3rd);
}

// �� �Ă�
String^ ���ω����^::��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::������(i1st, i2nd, i3rd);
}

// �� ���� 
String^ ���ω����^::��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ꁓ(i1st, i2nd, i3rd);
}

// ���񂺂悤 ����悤 ���񂺂܂��傤 
String^ ���ω����^::���񂺂悤(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����񂺂悤��(i1st, i2nd, i3rd);
}

// �ꑰ �e�q �o�� �o�� �Z�� �v�w �Z�� �o�� �o�� �Z�� 
String^ ���ω����^::�ꑰ(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ꑰ��(i1st, i2nd, i3rd);
}

// �ł����� �����A�͂͂� �ł�����邼�� �ł��� 
String^ ���ω����^::�ł�����(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���ł����道(i1st, i2nd, i3rd);
}

// ���� ���܂��� 
String^ ���ω����^::����(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::�����ȁ�(i1st, i2nd, i3rd);
}

// �Ă݂� �Ȃ���
String^ ���ω����^::�Ă݂�(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���Ă݂恓(i1st, i2nd, i3rd);
}

// �� �܂�
String^ ���ω����^::��(���o���b�Z�[�W�p�����^�^^ �p�����^) {
	int i1st = �p�����^->��P�l��_�����ԍ�;
	int i2nd = �p�����^->��Q�l��_�����ԍ�;
	int i3rd = �p�����^->��R�l��_�����ԍ�;
	return ::���恓(i1st, i2nd, i3rd);
}



