#pragma once

public ref class 演出情報型 {
public:
	void Do_フェイドアウト();
	void Do_フェイドイン();

	/// <summary>ix or 列挙</summary>
	bool Do_カメラ移動(int 城番号);
};