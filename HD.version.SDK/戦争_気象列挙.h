#pragma once

// 天気情報を得る《戦場限定》 0:晴れ 1:曇り 2:雨 3:雪
namespace 列挙 {
	namespace 戦争 {
		namespace 気象 {
			public ref class 天候 {
			public:
				static const int 晴れ = 0;
				static const int 曇り = 1;
				static const int 雨 = 2;
				static const int 雪 = 3;
			};
		}
	}
}

