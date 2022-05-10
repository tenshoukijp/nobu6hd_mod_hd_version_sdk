#pragma once

namespace 列挙 {
	namespace 起動環境設定 {


		public ref class ウィンドウモード {
		public:
			static const int フルスクリーン = 0;
			static const int ウィンドウ = 1;
		};

		public ref class ムービー {
		public:
			static const int なし = 0;
			static const int あり = 1;
		};

		public ref class ＢＧＭ {
		public:
			static const int なし = 0;
			static const int あり = 1;
		};

		public ref class 効果音 {
		public:
			static const int なし = 0;
			static const int あり = 1;
		};

		public ref class カーソルモード {
		public:
			static const int DirectX = 0;
			static const int Hardware = 1;
			static const int Software = 2;
		};

	}
}