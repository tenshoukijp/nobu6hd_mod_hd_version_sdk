#pragma pack(1)

#include "2DDirectString.h"

// ベクトルを文字列化するが、東西南北系（８方位）で文字列化。
string get８方位文字列(D2D_VECTOR v) {

	if ( v.length() == 0 ) {
		return "無方位";
	}

	double inner = -1; // 真逆からのスタート
	string dir = "";

	//　８つの方向の「単位ベクトル」を用意して、「最寄り城からのベクトル」との内積が最大のものをい採用する。
	// 単位ベクトル同志の内積が１に近いほど（すなわち大きいほど）ということは、２つのベクトルの方向は同じ方向である。
	// 逆に言えば真逆であるほど最少（すなわち-1)に近づく。
	D2D_VECTOR i(0,-1); // 北と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "北";
	}

	i = D2D_VECTOR(0,1); // 南と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "南";
	}

	i = D2D_VECTOR(1,0); // 東と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "東";
	}

	i = D2D_VECTOR(-1,0); // 西と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "西";
	}

	i = D2D_VECTOR(1,-1); // 東北と比較
	i.normalize(); // 単位ベクトル化
	if ( i * v > inner) {
		inner = i * v;
		dir = "北東";
	}

	i = D2D_VECTOR(-1,-1); // 西北と比較
	i.normalize(); // 単位ベクトル化
	if ( i * v > inner) {
		inner = i * v;
		dir = "北西";
	}

	i = D2D_VECTOR(1,1); // 東南と比較
	i.normalize(); // 単位ベクトル化
	if ( i * v > inner) {
		inner = i * v;
		dir = "南東";
	}

	i = D2D_VECTOR(-1,1); // 西南と比較
	i.normalize(); // 単位ベクトル化
	if ( i * v > inner) {
		inner = i * v;
		dir = "南西";
	}

	return dir;
}



// ベクトルを文字列化するが、東西南北系（４方位）で文字列化。
string get４方位文字列(D2D_VECTOR v) {

	if ( v.length() == 0 ) {
		return "無方位";
	}

	double inner = -1; // 内積。一番大きいものを探す。真逆からのスタート
	string dir = "";

	//　４つの方向の「単位ベクトル」を用意して、「最寄り城からのベクトル」との内積が最大のものをい採用する。
	// 単位ベクトル同志の内積が１に近いほど（すなわち大きいほど）ということは、２つのベクトルの方向は同じ方向である。
	// 逆に言えば真逆であるほど最少（すなわち-1)に近づく。
	D2D_VECTOR i(0,-1); // 北と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "北";
	}

	i = D2D_VECTOR(0,1); // 南と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "南";
	}

	i = D2D_VECTOR(1,0); // 東と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "東";
	}

	i = D2D_VECTOR(-1,0); // 西と比較
	if ( i * v > inner) {
		inner = i * v;
		dir = "西";
	}

	return dir;
}
