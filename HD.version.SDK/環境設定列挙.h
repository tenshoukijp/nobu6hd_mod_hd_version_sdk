#pragma once

namespace 列挙 {
	namespace 環境設定 {

		public ref class 自動メッセージ送り {
		public:
			static const int 無効 = 0;
			static const int 低速 = 2;
			static const int 中速 = 3;
			static const int 高速 = 4;
			static const int 最速 = 5;
		};

		public ref class 他国の戦争 {
		public:
			static const int 見る = 0;
			static const int 任意 = 1;
			static const int 見ない = 2;
		};

		public ref class 自国の戦争 {
		public:
			static const int 見る = 0;
			static const int 第１軍団 = 1;
			static const int 任意 = 2;
		};

		public ref class 音楽音量 {
		public:
			static const int 消音 = 0;
			static const int バー１ = 10;
			static const int バー２ = 20;
			static const int バー３ = 30;
			static const int バー４ = 40;
			static const int バー５ = 50;
			static const int バー６ = 60;
			static const int バー７ = 70;
			static const int バー８ = 80;
			static const int バー９ = 90;
			static const int バー10 = 100;
		};

		public ref class 効果音音量 {
		public:
			static const int 消音 = 0;
			static const int バー１ = 10;
			static const int バー２ = 20;
			static const int バー３ = 30;
			static const int バー４ = 40;
			static const int バー５ = 50;
			static const int バー６ = 60;
			static const int バー７ = 70;
			static const int バー８ = 80;
			static const int バー９ = 90;
			static const int バー10 = 100;
		};

		public ref class 年号表示 {
		public:
			static const int 元号 = 0;
			static const int 西暦 = 1;
		};


		public ref class ウィンドウモード {
		public:
			static const int ウィンドウ = 1;
			static const int フルスクリーン = 0;
		};

		public ref class 右クリックキャンセル {
		public:
			static const int 無効 = 0;
			static const int 有効 = 1;
		};

		public ref class 静観終了キー {
		public:
			static const int Ｓｐａｃｅ = 0;
			static const int Ｔａｂ = 1;
		};

		public ref class 自動セーブ {
		public:
			static const int 有効 = 1;
			static const int 無効 = 0;
		};
	}
}