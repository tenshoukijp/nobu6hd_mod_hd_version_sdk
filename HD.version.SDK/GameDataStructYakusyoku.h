#pragma once


// ���K�����ꂽ�喼�̖�EID���猳��ID�𓾂�
int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue);

// �喼ID���琳�K�����ꂽ��EID�𓾂�
int getNormalizedDaimyoPosition(int iDaimyoID);

// �R�cID���琳�K�����ꂽ��EID�𓾂�
int getNormalizedGundanPosition(int iGundanID);

// �喼�̖�E�̕t���ւ������݂�
bool tryChangeDaimyoYakusyoku(int iDaimyoID, int iYakusyokuValue);

// �R�c�̖�E�̕t���ւ������݂�
bool tryChangeGundanYakusyoku(int iGundanID, int iYakusyokuValue);
