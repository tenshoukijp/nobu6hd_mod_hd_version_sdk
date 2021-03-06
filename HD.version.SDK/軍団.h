#pragma once

#include "役職列挙.h"
#include "軍団列挙.h"

public ref class 軍団情報型 {
protected:
	int iGundanID;
public:
	軍団情報型() {}
	軍団情報型(int i番号);

	property int 番号 {
		int get() { return iGundanID; }
	}

	/// <summary>ix or 列挙</summary>
	property int 所属城番号 {
		int get();
	}

	property int 軍団長_武将番号 {
		int get();
	}

	property int 所属大名番号 {
		int get();
	}

	property int 行動力 {
		int get();
		void set(int value);
	}

	property int 金 {
		int get();
		void set(int value);
	}

	property int 米 {
		int get();
		void set(int value);
	}

	property int 馬 {
		int get();
		void set(int value);
	}

	property int 鉄砲 {
		int get();
		void set(int value);
	}

	property int 兵士 {
		int get();
	}

	/// <summary>１〜８の番号のこと</summary>
	property int 任命番号 {
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 役職 {
		int get();
		void set(int value);
	}

	property List<int>^ 麾下武将番号リスト {
		List<int>^ get();
	}

	property List<int>^ 麾下城番号リスト {
		List<int>^ get();
	}

	/// <summary>プレイヤの支配下にある軍団</summary>
	property bool Is_プレイヤ麾下軍団 {
		bool get();
	}

	/// <summary>プレイヤが直接操作している軍団</summary>
	property bool Is_プレイヤ担当軍団 {
		bool get();
	}

	bool Do_所属大名変更(int 大名番号);


	ref class 戦争軍団情報型 {
	protected:
		int iGundanID;
	public:
		戦争軍団情報型(int i番号) { iGundanID = i番号; }

		property int 総大将_武将番号 {
			int get();
		}

		/// <summary>列挙</summary>
		property int 参戦立場 {
			int get();
		}

	};
	
	戦争軍団情報型^ 戦争;
};


public ref class 軍団リスト情報型
{
public:
	軍団リスト情報型();

	List<軍団情報型^>^ 配列;

	property List<int>^ 有効軍団番号リスト{
		List<int>^ get();
	}

	ref class 戦争軍団リスト情報型 {
	public:
		property List<int>^ 参戦軍団番号リスト {
			List<int>^ get();
		}
	};
	
	戦争軍団リスト情報型 ^戦争;

};

