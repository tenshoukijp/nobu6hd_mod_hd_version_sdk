#pragma once

void 天翔記クラス::__PRIVATE_ON_LNCH_WINDOW__() {
	起動環境設定 = gcnew 起動環境設定情報型();
}

void 天翔記クラス::__PRIVATE_ON_GAME_WINDOW__() {
	武将 = gcnew 武将リスト情報型();
	軍団 = gcnew 軍団リスト情報型();
	大名 = gcnew 大名リスト情報型();

	家宝 = gcnew 家宝リスト情報型();
	官位 = gcnew 官位リスト情報型();

	城 = gcnew 城リスト情報型();
	国 = gcnew 国リスト情報型();
	県 = gcnew 県リスト情報型();

	戦略 = gcnew 戦略情報型();
	戦争 = gcnew 戦争情報型();

	暦 = gcnew 暦情報型();

	音楽 = gcnew 音楽情報型();
	演出 = gcnew 演出情報型();
	効果音 = gcnew 効果音情報型();

	ダイアログ = gcnew ダイアログ情報型();

	語句変化 = gcnew 語句変化情報型();

	環境設定 = gcnew 環境設定情報型();
	起動環境設定 = gcnew 起動環境設定情報型();
}
