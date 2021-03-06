#pragma once

#include "武将列挙.h"

public ref class 武将情報型
{

protected:
	int iBushouID;

public:
	武将情報型(int i番号);

	property int 番号 {
		int get() { return iBushouID; }
	}

	property String^ 名字
	{
		String^ get();
		void set(String^ value);
	}

	property String^ 名前
	{
		String^ get();
		void set(String^ value);
	}

	property String^ 姓名
	{
		String^ get();
	}

	/// <summary>列挙</summary>
	property int 性別
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 列伝番号
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙 + ix</summary>
	property int 差換顔番号
	{
		int get();
		void set(int value);
	}

	property int 政治才能
	{
		int get();
		void set(int value);
	}
	property int 元政治才能
	{
		int get();
	}
	property int 戦闘才能
	{
		int get();
		void set(int value);
	}
	property int 元戦闘才能
	{
		int get();
	}

	property int 智謀才能
	{
		int get();
		void set(int value);
	}
	property int 元智謀才能
	{
		int get();
	}

	property int 政治熟練
	{
		int get();
		void set(int value);
	}

	property int 戦闘熟練
	{
		int get();
		void set(int value);
	}

	property int 智謀熟練
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 政治適性
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 戦闘適性
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 智謀適性
	{
		int get();
		void set(int value);
	}

	property int 政治値
	{
		int get();
	}
	
	property int 戦闘値
	{
		int get();
	}

	property int 智謀値
	{
		int get();
	}

	/// <summary>列挙</summary>
	property int 足軽適性
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 騎馬適性
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 鉄砲適性
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 水軍適性
	{
		int get();
		void set(int value);
	}

	property int 魅力
	{
		int get();
		void set(int value);
	}

	property int 元魅力
	{
		int get();
	}

	property int 野望
	{
		int get();
		void set(int value);
	}
	property int 元野望
	{
		int get();
	}

	property int 忠誠
	{
		int get();
		void set(int value);
	}

	property int 勲功
	{
		int get();
		void set(int value);
	}

	property int 血筋番号
	{
		int get();
		void set(int value);
	}

	property int 所属大名番号
	{
		int get();
	}

	property int 所属軍団番号
	{
		int get();
	}

	/// <summary>ix or 列挙</summary>
	property int 所属城番号
	{
		int get();
	}

	property int 内応先大名番号
	{
		int get();
		void set(int value);
	}

	property int 兵士
	{
		int get();
		void set(int value);
	}

	property int 最大兵士
	{
		int get();
	}

	property int 訓練
	{
		int get();
		void set(int value);
	}

	property int 士気
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 兵科
	{
		int get();
		void set(int value);
	}

	property int 士官年数
	{
		int get();
		void set(int value);
	}

	property int 生年
	{
		int get();
		void set(int value);
	}

	property int 年齢
	{
		int get();
	}

	property int 親列伝番号
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 思考
	{
		int get();
		void set(int value);
	}

	property int 義理
	{
		int get();
		void set(int value);
	}

	property int 相性
	{
		int get();
		void set(int value);
	}

	property bool 技能一喝
	{
		bool get();
		void set(bool value);
	}
	property bool 技能暗殺
	{
		bool get();
		void set(bool value);
	}
	property bool 技能流出
	{
		bool get();
		void set(bool value);
	}
	property bool 技能煽動
	{
		bool get();
		void set(bool value);
	}
	property bool 技能流言
	{
		bool get();
		void set(bool value);
	}
	property bool 技能弁舌
	{
		bool get();
		void set(bool value);
	}
	property bool 技能焼討
	{
		bool get();
		void set(bool value);
	}
	property bool 技能挑発
	{
		bool get();
		void set(bool value);
	}

	/// <summary>列挙</summary>
	property int 職業
	{
		int get();
		void set(int value);
	}

	property bool 大砲
	{
		bool get();
		void set(bool value);
	}

	property bool 騎馬鉄砲
	{
		bool get();
		void set(bool value);
	}

	property bool 鉄甲船
	{
		bool get();
		void set(bool value);
	}

	property int 寿命
	{
		int get();
		void set(int value);
	}

	property int 勇猛
	{
		int get();
		void set(int value);
	}

	property int 独立
	{
		int get();
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 口調
	{
		int get();
		void set(int value);
	}

	property bool 行動済
	{
		bool get();
		void set(bool value);
	}

	property bool 内応状態
	{
		bool get();
		void set(bool value);
	}

	property bool 遺恨状態
	{
		bool get();
		void set(bool value);
	}

	property bool 会見済
	{
		bool get();
		void set(bool value);
	}

	/// <summary>列挙</summary>
	property int 状態
	{
		int get();

		// 現役⇔浪人 のみ
		void set(int value);
	}

	/// <summary>列挙</summary>
	property int 身分
	{
		int get();
		void set(int value);
	}

	bool Do_城主();

	bool Do_転居(int 城番号);

	property int 伴侶武将番号
	{
		int get();
	}

	bool Do_結婚(int 相手武将番号);
	bool Do_離婚();

	int Get_相性差(int 相手武将番号);

	/// <summary>プレイヤの支配下にある武将</summary>
	property bool Is_プレイヤ麾下武将 {
		bool get();
	}

	/// <summary>プレイヤが直接操作している武将</summary>
	property bool Is_プレイヤ担当武将 {
		bool get();
	}

	bool Is_自分は相手の娘(int 相手武将番号);
	bool Is_自分は相手の息子(int 相手武将番号);
	bool Is_自分は相手の子(int 相手武将番号);
	bool Is_自分は相手の親(int 相手武将番号);
	bool Is_自分は相手の父(int 相手武将番号);
	bool Is_相手は自分の父(int 相手武将番号);
	bool Is_自分は相手の母(int 相手武将番号);
	bool Is_相手は自分の母(int 相手武将番号);
	bool Is_自分は相手の弟(int 相手武将番号);
	bool Is_相手は自分の弟(int 相手武将番号);
	bool Is_自分は相手の妹(int 相手武将番号);
	bool Is_相手は自分の妹(int 相手武将番号);
	bool Is_自分は相手の兄(int 相手武将番号);
	bool Is_相手は自分の兄(int 相手武将番号);
	bool Is_自分は相手の姉(int 相手武将番号);
	bool Is_相手は自分の姉(int 相手武将番号);

	bool Is_自分と相手は兄弟(int 相手武将番号);
	bool Is_自分と相手は姉妹(int 相手武将番号);
	bool Is_自分と相手は姉弟(int 相手武将番号);
	bool Is_自分と相手は兄妹(int 相手武将番号);
	bool Is_自分は相手の夫(int 相手武将番号);
	bool Is_自分は相手の妻(int 相手武将番号);
	bool Is_自分は相手の血縁(int 相手武将番号);
	bool Is_相手は自分の家臣(int 相手武将番号);
	bool Is_相手は自分の大名(int 相手武将番号);
	bool Is_自分と相手は同じ大名家所属(int 相手武将番号);

	ref class 戦争武将情報型 {
	protected:
		int iBushouID;
	public:
		戦争武将情報型(int i番号) { iBushouID = i番号; }

		/// <summary>列挙</summary>
		property int 参戦立場 {
			int get();
		}

		/// <summary>列挙</summary>
		property int 混乱状態 {
			int get();
		}

		property bool 退却済 {
			bool get();
		}

		property bool 行動済 {
			bool get();
		}

		property int 機動力 {
			int get();
			void set(int value);
		}

		property bool 出陣中 {
			bool get();
		}

		property bool 出陣中_表示戦場 {
			bool get();
		}

		property ヘックス位置型^ ヘックス位置 {
			ヘックス位置型^  get();
		}

	};
	
	戦争武将情報型 ^戦争;
};



public ref class 武将リスト情報型
{
public:
	武将リスト情報型();

	List<武将情報型^>^ 配列;

	int Find_武将番号(int 列伝番号);
	int Find_武将番号(String^ 姓名);

	ref class 戦争武将リスト情報型 {
	public:
		property List<int>^ 出陣中_武将番号リスト {
			List<int>^ get();
		}

		property List<int>^ 出陣中_表示戦場_武将番号リスト{
			List<int>^ get();
		}
	};
	
	戦争武将リスト情報型^ 戦争;
};
