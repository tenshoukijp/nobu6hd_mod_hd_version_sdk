#pragma once


/*
プレイヤーの担当軍団(大名番号ではなく軍団番号)
*/
struct NB6PLAYERS8
{
	WORD gundan;
};



// 対象の軍団IDがいずれかのプレイヤー勢力下の軍団である(最大８人)
bool isPlayerGundan( WORD iTargetGundanID );

// 対象の武将IDがいずれかのプレイヤー勢力下の武将である
bool isPlayerBushou( WORD iTargetBushouID );

// 対象の大名IDがいずれかのプレイヤー担当の大名である
bool isPlayerDaimyo( WORD iTargetDaimyoID );


