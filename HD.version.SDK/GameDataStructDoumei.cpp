#include "GameDataStruct.h"

//----------------------------------------------------------------------------------

// �`�喼(�O�n�܂�ł̔z��p�w��)�Ƃa�喼�Ƃ̓����֌W�j
// 004CF213  05 55 55 55 95    �Ƃ���̂́A004CF213 [0 5 5 5 5 5 5 5 9 5] �Ƃ����悤��1�ԖځA2�ԖځA3�Ԗڂ̑���c�Ƃ��������ƂȂ�B  
// ��������E�������͂ǂ��ɂ���̂��Ƃ����ƁA2�l�̑g�ݍ��킹�̂����A�傫�����̑喼�ԍ��p�̓����\���̂ɓ����Ă���B
// �Ⴆ�΁A�喼�ԍ�21��25�Ƃ���ƁA�F�D����21�Ԃ̕���25�Ԗڂɓ����Ă���A�����⍥���́A25�Ԃ̕���21�Ԗڂɓ����Ă���Ƃ����킯���B


// ����getDoumeiKankei�����ŋ��܂�l�́A���̔z���INDEX�ł��邽�߁A������g���Ď��ۂ̒l�ɒ����B
static int YuukouValueArray[] = { 0, 10, 20, 30, 40, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 0xFFFF };


static byte* getYuukouKannkeiPointer(int& iDaimyoA_ID, int& iDaimyoB_ID) {

	// �͈̓`�F�b�N
	if (0 <= iDaimyoA_ID && iDaimyoA_ID < GAMEDATASTRUCT_DAIMYO_NUM &&
		0 <= iDaimyoB_ID && iDaimyoB_ID < GAMEDATASTRUCT_DAIMYO_NUM) {
	}
	else {
		return NULL;
	}

	// �喼�`�Ƒ喼�a�ŁA�喼�`�̕����l���傫���ꍇ�A����ւ���B
	// �Ȃ��Ȃ�F�D�֌W�̒l�́A�喼�`�����������̑g�ݍ��킹�e�[�u���ɓ����Ă��āA�喼�`���傫�����̑g�ݍ��킹�e�[�u���ɂ͍����⓯���̒l�������Ă��邩��B
	if (iDaimyoA_ID > iDaimyoB_ID) {
		// �Q����ւ�
		iDaimyoA_ID ^= iDaimyoB_ID;
		iDaimyoB_ID ^= iDaimyoA_ID;
		iDaimyoA_ID ^= iDaimyoB_ID;
	}

	byte *p = (byte *)nb6doumei;

	// �ȉ�2�l�̑喼�h�c���A�����֌W�l�������Ă��郁�����̃A�h���X�����߂�
	p += iDaimyoA_ID * (GAMEDATASTRUCT_DAIMYO_NUM / 2); // �������P�̂`�喼������A�a�喼�ւ̓������P�o�C�g�ŕ\������Ă���΁A
														// �V�Q�喼����̂ŁA�V�Q�o�C�g�ŕ\�������B
														// �Ƃ��낪���ۂɂ́A4�r�b�g�ŕ\�������̂ŁA
														// �P�̑喼�ɂԂ牺����\���̃f�[�^�Ƃ��ẮA�����̂R�U�o�C�g�ł���B

	p += iDaimyoB_ID / 2;									 // ��Ɠ������R�ƂȂ�B�P�̑喼��(�����֌W�\����)�̒��ł�
															 // �P�̑���喼�Ƃ̓����l�Ɏg���Ă���͔̂��o�C�g�B
															 // ����ă|�C���^�̈ʒu�Ƃ��ẮA/2 ���Ă����A����������ŁA��ŉ��Z��U�蕪����B

	return p;
}


int getYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// �Y���̗F�D�֌W��񂪑��݂���A�h���X�𓾂�B�`�Ƃa�͒l����������邩������Ȃ��B���ӁB
	byte *p = getYuukouKannkeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return 0;

	// �A�h���X�͋��܂������A�P�̃A�h���X��1�o�C�g���ɂ́A�Q�̑喼�������Ă���B
	// �喼�ԍ��������Ȃ��ʌ��A�����Ȃ牺�ʌ��ł���B
	int YuukouIX = 0;
	// ����喼��������
	if (iDaimyoB_ID % 2 == 0) {								 // �����ł���΁A�㔼���̃r�b�g�Ƃ́�����[0 5] �̂���[0]��Ԃ�
		YuukouIX = (*p) >> 4;

		// ����喼�����										 // ��ł���΁A�������̃r�b�g�Ƃ́�����[0 5] �̂���[5]��Ԃ�
	}
	else {
		YuukouIX = 0x0F & (*p);
	}

	return YuukouValueArray[YuukouIX];
}

// �F�D�֌W�l���Z�b�g����B
void setYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID, int iValue) {

	// �Y���̗F�D�֌W��񂪑��݂���A�h���X�𓾂�B�`�Ƃa�͒l����������邩������Ȃ��B���ӁB
	byte *p = getYuukouKannkeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return;


	// �����̓����@�C�̂ŗF�D�֌W�l�Ƃ��ĂO���w�肵�����̂Ƃ���B100�I�[�o�[��100�ɂ��Ƃ��B
	if (iValue < 0) { iValue = 0; }
	if (iValue > 100) { iValue = 100; }

	int YuukouIX = 0;
	// �Z�b�g�������F�D�֌W�l�ƁA�F�D�֌W�l�̔z����r���āA�����Ƃ��߂��؎̂Ēl��index�����߂�B
	// �Ⴆ�ΗF�D�֌W�l�Ƃ���53�Ƃ����悤�Ɏw�肳��Ă��A���̂悤�Ȓl�ɂ͏o���Ȃ��̂ŁA50�Ƃ���킯���B
	// ������50�́AYuukouValueArray��index==5�ɑ��݂���B����5�̂悤�Ȓl�����߂����B
	for (int i = 0; i < sizeof(YuukouValueArray) / sizeof(YuukouValueArray[0]); i++) {
		if (iValue < YuukouValueArray[i]) {

			YuukouIX = i - 1;	// �l���������̂ŁA�P�O��index�ɂ��Ƃ��B

			if (YuukouIX < 0) { YuukouIX = 0; }  // ���_�゠�肦�Ȃ����A���������킩���̂ňꉞ�B
			break;
		}
	}

	// �A�h���X�͋��܂������A�P�̃A�h���X��1�o�C�g���ɂ́A�Q�̑喼�������Ă���B
	// �喼�ԍ��������Ȃ��ʌ��A�����Ȃ牺�ʌ��ł���B
	// ����喼��������
	if (iDaimyoB_ID % 2 == 0) {								 // �����ł���΁A�㔼���̃r�b�g�Ƃ́�����[0 5] �̂���[0]��Ԃ�
		YuukouIX = YuukouIX << 4;
		// ��ʃo�C�g��YuukouIX���V�t�g�������̂��A���ʃo�C�g�͉��ʃo�C�g�̕����������o��
		*p = YuukouIX | (0x0F & (*p));

		// ����喼�����										 // ��ł���΁A�������̃r�b�g�Ƃ́�����[0 5] �̂���[5]��Ԃ�
	}
	else {
		// ��ʃo�C�g�͂��̂܂܍̗p�ŁA���ʃo�C�g�́AYuukouIX���̂܂܂ŁB
		*p = (0xF0 & (*p)) | YuukouIX;
	}
}

static byte* getDoumeiKankeiPointer(int& iDaimyoA_ID, int& iDaimyoB_ID) {

	// �͈̓`�F�b�N
	if (0 <= iDaimyoA_ID && iDaimyoA_ID < GAMEDATASTRUCT_DAIMYO_NUM &&
		0 <= iDaimyoB_ID && iDaimyoB_ID < GAMEDATASTRUCT_DAIMYO_NUM) {
	}
	else {
		return NULL;
	}

	// �喼�`�Ƒ喼�a�ŁA�喼�`�̕����l���������ꍇ�A����ւ���B
	// �Ȃ��Ȃ瓯���֌W�̒l�́A�喼�`���傫�����̑g�ݍ��킹�e�[�u���ɓ����Ă��邩��B
	if (iDaimyoA_ID < iDaimyoB_ID) {
		// �Q����ւ�
		iDaimyoA_ID ^= iDaimyoB_ID;
		iDaimyoB_ID ^= iDaimyoA_ID;
		iDaimyoA_ID ^= iDaimyoB_ID;
	}


	byte *p = (byte *)nb6doumei;

	// �ȉ�2�l�̑喼�h�c���A�����֌W�l�������Ă��郁�����̃A�h���X�����߂�
	p += iDaimyoA_ID * (GAMEDATASTRUCT_DAIMYO_NUM / 2); // �������P�̂`�喼������A�a�喼�ւ̓������P�o�C�g�ŕ\������Ă���΁A
														// �V�Q�喼����̂ŁA�V�Q�o�C�g�ŕ\�������B
														// �Ƃ��낪���ۂɂ́A4�r�b�g�ŕ\�������̂ŁA
														// �P�̑喼�ɂԂ牺����\���̃f�[�^�Ƃ��ẮA�����̂R�U�o�C�g�ł���B

	p += iDaimyoB_ID / 2;									 // ��Ɠ������R�ƂȂ�B�P�̑喼��(�����֌W�\����)�̒��ł�
															 // �P�̑���喼�Ƃ̓����l�Ɏg���Ă���͔̂��o�C�g�B
															 // ����ă|�C���^�̈ʒu�Ƃ��ẮA/2 ���Ă����A����������ŁA��ŉ��Z��U�蕪����B
	return p;
}

int isDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// �Y���̓����֌W��񂪑��݂���A�h���X�𓾂�B�`�Ƃa�͒l����������邩������Ȃ��B���ӁB
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return 0;

	// �A�h���X�͋��܂������A�P�̃A�h���X��1�o�C�g���ɂ́A�Q�̑喼�������Ă���B
	// �喼�ԍ��������Ȃ��ʌ��A�����Ȃ牺�ʌ��ł���B
	// ����喼��������
	if (iDaimyoB_ID % 2 == 0) {								 // �����ł���΁A�㔼���̃r�b�g
		return 0x10 & (*p);
		// ����喼�����										 // ��ł���΁A�������̃r�b�g
	}
	else {
		return 0x01 & (*p);
	}
}
int isKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// �Y���̍����֌W��񂪑��݂���A�h���X�𓾂�(�����Ɠ����ꏊ)�B�`�Ƃa�͒l����������邩������Ȃ��B���ӁB
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return 0;

	// �A�h���X�͋��܂������A�P�̃A�h���X��1�o�C�g���ɂ́A�Q�̑喼�������Ă���B
	// �喼�ԍ��������Ȃ��ʌ��A�����Ȃ牺�ʌ��ł���B

	if (iDaimyoB_ID % 2 == 0) {								 // �����ł���΁A�㔼���̃r�b�g
		return (0x20 & (*p)) > 0;							 // �Q�Ƃ̔�r�ł͊ԈႤ��������Ȃ��̂ŁA�ꉞBOOL���ۂ����Ă����B
															 // ����喼�����										 // ��ł���΁A�������̃r�b�g
	}
	else {
		return (0x02 & (*p)) > 0;							 // �Q�Ƃ̔�r�ł͊ԈႤ��������Ȃ��̂ŁA�ꉞBOOL���ۂ����Ă����B
	}
}

void setDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// �Y���̓����֌W��񂪑��݂���A�h���X�𓾂�B�`�Ƃa�͒l����������邩������Ȃ��B���ӁB
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return;

	// �A�h���X�͋��܂������A�P�̃A�h���X��1�o�C�g���ɂ́A�Q�̑喼�������Ă���B
	// �喼�ԍ��������Ȃ��ʌ��A�����Ȃ牺�ʌ��ł���B
	// ����喼��������
	if (iDaimyoB_ID % 2 == 0) {								 // �����ł���΁A�㔼���̃r�b�g
		*p = *p | 0x10;
		// ����喼�����										 // ��ł���΁A�������̃r�b�g
	}
	else {
		*p = *p | 0x01;
	}
}


void setKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID) {

	// �Y���̍����֌W��񂪑��݂���A�h���X�𓾂�(�����Ɠ����ꏊ)�B�`�Ƃa�͒l����������邩������Ȃ��B���ӁB
	byte *p = getDoumeiKankeiPointer(iDaimyoA_ID, iDaimyoB_ID);
	if (!p) return;

	// �A�h���X�͋��܂������A�P�̃A�h���X��1�o�C�g���ɂ́A�Q�̑喼�������Ă���B
	// �喼�ԍ��������Ȃ��ʌ��A�����Ȃ牺�ʌ��ł���B
	// ����喼��������
	if (iDaimyoB_ID % 2 == 0) {								 // �����ł���΁A�㔼���̃r�b�g
		*p = *p | 0x20;
		// ����喼�����										 // ��ł���΁A�������̃r�b�g
	}
	else {
		*p = *p | 0x02;
	}
}

