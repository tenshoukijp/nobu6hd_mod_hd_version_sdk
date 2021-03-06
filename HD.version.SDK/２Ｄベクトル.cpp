#include "GameDataStruct.h"

//比較演算子
bool Ｄ２Ｄ位置型::operator==(const Ｄ２Ｄ位置型^ v) {
	return (Ｘ == v->Ｘ) && (Ｙ == v->Ｙ);
}
bool Ｄ２Ｄ位置型::operator!=(const Ｄ２Ｄ位置型^ v) {
	return (Ｘ != v->Ｘ) || (Ｙ != v->Ｙ);
}
//代入演算子
Ｄ２Ｄ位置型^ Ｄ２Ｄ位置型::operator=(const Ｄ２Ｄ位置型^ v) {
	this->Ｘ = v->Ｘ;
	this->Ｙ = v->Ｙ;
	return this;
}



//*----------------------メンバ関数の実装--------------------------*//
Ｄ２Ｄベクトル型::Ｄ２Ｄベクトル型() { Ｘ = Ｙ = 0; }
Ｄ２Ｄベクトル型::Ｄ２Ｄベクトル型(double Ｘ成分, double Ｙ成分) {
	this->Ｘ = Ｘ成分;
	this->Ｙ = Ｙ成分;
}
Ｄ２Ｄベクトル型::Ｄ２Ｄベクトル型(Ｄ２Ｄ位置型^ pos) {
	this->Ｘ = pos->Ｘ;
	this->Ｙ = pos->Ｙ;
}

//代入演算子
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator=(Ｄ２Ｄベクトル型^ v) {
	this->Ｘ = v->Ｘ;
	this->Ｙ = v->Ｙ;
	return this;
}
//単項演算子
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator+=(Ｄ２Ｄベクトル型^ v) {
	this->Ｘ += v->Ｘ;
	this->Ｙ += v->Ｙ;
	return this;
}
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator-=(Ｄ２Ｄベクトル型^ v) {
	this->Ｘ -= v->Ｘ;
	this->Ｙ -= v->Ｙ;
	return this;
}
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator*=(double k) {
	this->Ｘ *= k;
	this->Ｙ *= k;
	return this;
}
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator/=(double k) {
	this->Ｘ /= k;
	this->Ｙ /= k;
	return this;
}
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator+() {		//+Ｄ２Ｄベクトル型
	return this;
}
Ｄ２Ｄベクトル型^ Ｄ２Ｄベクトル型::operator-() {		//-Ｄ２Ｄベクトル型
	return gcnew Ｄ２Ｄベクトル型(-Ｘ, -Ｙ);
}
//添え字演算子
double Ｄ２Ｄベクトル型::operator[](int i) {
	if (i == 0) {
		return Ｘ;
	}
	else if (i == 1) {
		return Ｙ;
	}
	else {
		return Ｘ;
	}
}
//比較演算子
bool Ｄ２Ｄベクトル型::operator==(Ｄ２Ｄベクトル型^ v) {
	return (Ｘ == v->Ｘ) && (Ｙ == v->Ｙ);
}
bool Ｄ２Ｄベクトル型::operator!=(Ｄ２Ｄベクトル型^ v) {
	return (Ｘ != v->Ｘ) || (Ｙ != v->Ｙ);
}
//べクトルの長さ
double Ｄ２Ｄベクトル型::長さ::get() {
	return System::Math::Pow((double)(Ｘ*Ｘ + Ｙ*Ｙ), (double)0.5f);
}
//正規化(単位ベクトル化)
void Ｄ２Ｄベクトル型::正規化() {
	if (長さ == 0) {
		デバッグ出力 << "長さが０のベクトル(=方向が無いベクトル)を単位ベクトル化しようとしました。無限０除算でエラーとなります。" << endl;
		this->Ｘ = 0;
		this->Ｙ = 0;
	}
	else {
		this->Ｘ /= 長さ;
		this->Ｙ /= 長さ;
	}
}
//*----------------------グローバル関数の実装--------------------------*//
//二項演算子の定義
//Ｄ２Ｄベクトル型+Ｄ２Ｄベクトル型
Ｄ２Ｄベクトル型^ operator+(Ｄ２Ｄベクトル型^ u, Ｄ２Ｄベクトル型^ v) {
	Ｄ２Ｄベクトル型^ w = gcnew Ｄ２Ｄベクトル型();
	w->Ｘ = u->Ｘ + v->Ｘ;
	w->Ｙ = u->Ｙ + v->Ｙ;
	return w;
}
//Ｄ２Ｄベクトル型-Ｄ２Ｄベクトル型
Ｄ２Ｄベクトル型^ operator-(Ｄ２Ｄベクトル型^ u, Ｄ２Ｄベクトル型^ v) {
	Ｄ２Ｄベクトル型^ w = gcnew Ｄ２Ｄベクトル型();
	w->Ｘ = u->Ｘ - v->Ｘ;
	w->Ｙ = u->Ｙ - v->Ｙ;
	return w;
}
//double*Ｄ２Ｄベクトル型
Ｄ２Ｄベクトル型^ operator*(double k, Ｄ２Ｄベクトル型^ v) {
	return gcnew Ｄ２Ｄベクトル型(k*v->Ｘ, k*v->Ｙ);
}
//Ｄ２Ｄベクトル型*double
Ｄ２Ｄベクトル型^ operator*(Ｄ２Ｄベクトル型^ v, double k) {
	return gcnew Ｄ２Ｄベクトル型(v->Ｘ*k, v->Ｙ*k);
}
//Ｄ２Ｄベクトル型/double
Ｄ２Ｄベクトル型^ operator/(Ｄ２Ｄベクトル型^ v, double k) {
	return gcnew Ｄ２Ｄベクトル型(v->Ｘ / k, v->Ｙ / k);
}
//内積 Ｄ２Ｄベクトル型*Ｄ２Ｄベクトル型
double operator*(Ｄ２Ｄベクトル型^ u, Ｄ２Ｄベクトル型^ v) {
	return u->Ｘ*v->Ｘ + u->Ｙ*v->Ｙ;
}

//外積 Ｄ２Ｄベクトル型%Ｄ２Ｄベクトル型
double operator%(Ｄ２Ｄベクトル型^ u, Ｄ２Ｄベクトル型^ v) {
	Ｄ２Ｄベクトル型^ w = gcnew Ｄ２Ｄベクトル型();
	return u->Ｘ*v->Ｙ - u->Ｙ*v->Ｘ;
}

//２つのベクトルのなす角
double 角度(Ｄ２Ｄベクトル型^ u, Ｄ２Ｄベクトル型^ v) {
	double cos = u*v / (u->長さ*v->長さ);
	return double(System::Math::Acos(cos) / System::Math::PI * 180);
}

//２点間座標の差
Ｄ２Ｄベクトル型^ operator-(Ｄ２Ｄ位置型^ p1, Ｄ２Ｄ位置型^ p2) {
	Ｄ２Ｄベクトル型^ v = gcnew Ｄ２Ｄベクトル型();
	v->Ｘ = p1->Ｘ - p2->Ｘ;
	v->Ｙ = p1->Ｙ - p2->Ｙ;
	return v;
}

