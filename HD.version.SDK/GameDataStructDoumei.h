#pragma once


// �`�喼(�O�n�܂�ł̔z��p�w��)�Ƃa�喼�Ƃ̗F�D�l
int getYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID);

// �`�喼(�O�n�܂�ł̔z��p�w��)�Ƃa�喼�Ƃ̗F�D�l���Z�b�g����B
void setYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID, int iValue);

// �`�喼(�O�n�܂�ł̔z��p�w��)�Ƃa�喼�Ƃ̓����֌W �������Ă���΂P���Ԃ�A���Ă��Ȃ���΂O���Ԃ�j
int isDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID);

// �`�喼(�O�n�܂�ł̔z��p�w��)�Ƃa�喼�Ƃ̍����֌W �������Ă���΂Q���Ԃ�A���Ă��Ȃ���΂O���Ԃ�j
int isKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID);

void setDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID);
void setKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID);

