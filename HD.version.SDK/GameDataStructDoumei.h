#pragma once


// Ａ大名(０始まりでの配列用指定)とＢ大名との友好値
int getYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID);

// Ａ大名(０始まりでの配列用指定)とＢ大名との友好値をセットする。
void setYuukouKankei(int iDaimyoA_ID, int iDaimyoB_ID, int iValue);

// Ａ大名(０始まりでの配列用指定)とＢ大名との同盟関係 同盟していれば１が返り、していなければ０が返る）
int isDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID);

// Ａ大名(０始まりでの配列用指定)とＢ大名との婚姻関係 婚姻していれば２が返り、していなければ０が返る）
int isKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID);

void setDoumeiKankei(int iDaimyoA_ID, int iDaimyoB_ID);
void setKoninKankei(int iDaimyoA_ID, int iDaimyoB_ID);

