#pragma once

#include "GameDataStruct.h"


using namespace System;
using namespace System::Collections::Generic;

#include "配列範囲.h"
#include "２Ｄベクトル.h"
#include "３Ｄベクトル.h"
#include "噴出メッセージ.h"
#include "戦争.h"
#include "武将.h"
#include "暦.h"
#include "大名.h"
#include "軍団.h"
#include "家宝.h"
#include "官位.h"
#include "城.h"
#include "国.h"
#include "県.h"
#include "語句変化.h"
#include "音楽.h"
#include "演出.h"
#include "効果音.h"
#include "ダイアログ.h"

#include "環境設定.h"
#include "起動環境設定.h"

#include "戦略.h"
#include "戦争.h"

#include "デバッグ出力.h"

#include "ユーザークラス.h"





public ref class 天翔記クラス
{
public:
	static 武将リスト情報型^ 武将;
	static 軍団リスト情報型^ 軍団;
	static 大名リスト情報型^ 大名;

	static 家宝リスト情報型^ 家宝;
	static 官位リスト情報型^ 官位;

	static 城リスト情報型^ 城;
	static 国リスト情報型^ 国;
	static 県リスト情報型^ 県;

	static 暦情報型^ 暦;

	static 戦略情報型^ 戦略;
	static 戦争情報型^ 戦争;

	static 音楽情報型^ 音楽;
	static 演出情報型^ 演出;
	static 効果音情報型^ 効果音;
	static ダイアログ情報型^ ダイアログ;

	static 語句変化情報型^ 語句変化;

	static 環境設定情報型^ 環境設定;
	static 起動環境設定情報型^ 起動環境設定;


public:

	static void __PRIVATE_ON_LNCH_WINDOW__();
	static void __PRIVATE_ON_GAME_WINDOW__();

	static void On_ランチャーウィンドウ起動時();

	static void On_ゲームウィンドウ起動時();

	static String^ On_データファイル読込直前(String^ 元ファイル名);

	static String^ On_ＢＧＭ再生直前(int ＢＧＭ番号, int ＢＧＭシーン番号, String^ 元ファイル名);

	static String^ On_ＭＯＶＩＥ再生直前(int ＭＯＶＩＥ番号, String^ 元ファイル名);

	static void On_シナリオ選択直後(String^ シナリオファイル名);

	static String^ On_噴出メッセージ直前(String^ 元メッセージ, 噴出メッセージパラメタ型^ パラメタ);

	static void On_戦略_軍団ターン変更時(int 軍団番号);

	static void On_戦争開始時(int 城番号, 戦争開始パラメタ型^ パラメタ);

	static void On_戦争参加勢力決定直後();

	static void On_戦争_残りターン変更時(int 残りターン数);

	static void On_戦争終了時();
};





