#pragma once

#include "国列挙.h"

public ref class 国情報型 {
protected:
	int iChimeiID;
public:
	国情報型(int i番号);

	property int 番号 {
		int get() { return iChimeiID; }
	}

	property String^ 国名 {
		String^ get();
		void set(String^ value);
	}

	property List<int>^ 所属城番号リスト {
		List<int>^ get();
	}

};


public ref class 国リスト情報型
{
public:
	国リスト情報型();

	List<国情報型^>^ 配列;
};

