#pragma once


// 正規化された大名の役職IDから元のIDを得る
int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue);

// 大名IDから正規化された役職IDを得る
int getNormalizedDaimyoPosition(int iDaimyoID);

// 軍団IDから正規化された役職IDを得る
int getNormalizedGundanPosition(int iGundanID);

// 大名の役職の付け替えを試みる
bool tryChangeDaimyoYakusyoku(int iDaimyoID, int iYakusyokuValue);

// 軍団の役職の付け替えを試みる
bool tryChangeGundanYakusyoku(int iGundanID, int iYakusyokuValue);
