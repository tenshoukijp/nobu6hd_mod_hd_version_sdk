#pragma once

#include "城列挙.h"

#include "城位置.h"

public ref class 城情報型 {
protected:
	int iCastleID;
public:
	城情報型(int i番号);

	property int 番号 {
		int get() { return iCastleID; }
	}

	property String^ 城名 {
		String^ get();
		void set(String^);
	}

	property String^ 城称 {
		String^ get();
	}

	// 城名+城称
	property String^ 城名称 {
		String^ get();
	}

	property int 城主_武将番号 {
		int get();
	}

	property int 所属軍団番号 {
		int get();
	}

	property List<int>^ 麾下武将番号リスト {
		List<int>^ get();
	}

	// 軍団長の本城もしくは大名の本城
	property bool Is_軍団長本城 {
		bool get();
	}

	// 大名の本城
	property bool Is_大名本城 {
		bool get();
	}

	property int 城郭 {
		int get();
		void set(int value);
	}

	property int 石高 {
		int get();
		void set(int value);
	}

	property int 最大石高 {
		int get();
		void set(int value);
	}

	property int 商業 {
		int get();
		void set(int value);
	}

	property int 最大商業 {
		int get();
		void set(int value);
	}

	property int 人口 {
		int get();
		void set(int value);
	}

	property int 民忠 {
		int get();
		void set(int value);
	}


	property int 徴兵可 {
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 兵質 {
		int get();
		void set(int value);
	}

	property int 兵士 {
		int get();
	}

	property bool 鍛冶 {
		bool get();
		void set(bool value);
	}

	property bool 馬産地 {
		bool get();
		void set(bool value);
	}

	property bool 港 {
		bool get();
		void set(bool value);
	}

	property bool 国際港 {
		bool get();
		void set(bool value);
	}

	property bool 銀山 {
		bool get();
		void set(bool value);
	}

	property bool 金山 {
		bool get();
		void set(bool value);
	}

	property bool 巨城 {
		bool get();
		void set(bool value);
	}

	property bool 一揆扇動 {
		bool get();
		void set(bool value);
	}

	/// <summary>列挙</summary>
	property int 城絵背景 {
		int get();
		void set(int value);
	}

	/// <summary>ix or 列挙</summary>
	property int 所属国番号 {
		int get();
	}

	/// <summary>ix or 列挙</summary>
	property int 所属県番号 {
		int get();
	}

	property 城位置型^ 位置 {
		城位置型^ get();
		void set(城位置型^ value);
	}

	property 城グリッド位置型^ グリッド位置 {
		城グリッド位置型^ get();
	}

	bool Is_隣接(int 城Ｂ番号);

	property List<int>^ 隣接城番号リスト {
		List<int>^ get();
	};
	property List<int>^ 経路隣接城番号リスト {
		List<int>^ get();
	}

};




public ref class 城リスト情報型
{
public:
	城リスト情報型();

	List<城情報型^>^ 配列;

	List<int>^ Get_経路上の城番号リスト(int 開始城番号, int 目的城番号);
	List<int>^ Get_経路上の城番号リスト(int 開始城番号, int 目的城番号, List<int>^ 経路構築除去城番号リスト);
};

