#pragma once


// ³‹K‰»‚³‚ê‚½‘å–¼‚Ì–ğEID‚©‚çŒ³‚ÌID‚ğ“¾‚é
int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue);

// ‘å–¼ID‚©‚ç³‹K‰»‚³‚ê‚½–ğEID‚ğ“¾‚é
int getNormalizedDaimyoPosition(int iDaimyoID);

// ŒR’cID‚©‚ç³‹K‰»‚³‚ê‚½–ğEID‚ğ“¾‚é
int getNormalizedGundanPosition(int iGundanID);

// ‘å–¼‚Ì–ğE‚Ì•t‚¯‘Ö‚¦‚ğ‚İ‚é
bool tryChangeDaimyoYakusyoku(int iDaimyoID, int iYakusyokuValue);

// ŒR’c‚Ì–ğE‚Ì•t‚¯‘Ö‚¦‚ğ‚İ‚é
bool tryChangeGundanYakusyoku(int iGundanID, int iYakusyokuValue);
