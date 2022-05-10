#pragma once

public ref class 城位置型 {
public:
	int Ｘ;
	int Ｙ;
	城位置型(int _x, int _y);
	城位置型() : Ｘ(0), Ｙ(0) {}
};

public ref class 城グリッド位置型 {
public:
	int Ｘ;
	int Ｙ;
	城グリッド位置型(int _x, int _y);
	城グリッド位置型() : Ｘ(0), Ｙ(0) {}
};


public ref class 城グリッドベクトル型 {
public:
	int Ｘ;
	int Ｙ;
	城グリッドベクトル型(int Ｘ成分, int Ｙ成分) : Ｘ(Ｘ成分), Ｙ(Ｙ成分) {}
	城グリッドベクトル型() : Ｘ(0), Ｙ(0) {}
};

城グリッドベクトル型^ operator-(城グリッド位置型^ p1, 城グリッド位置型^ p2);
