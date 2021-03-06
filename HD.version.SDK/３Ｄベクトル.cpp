#include "GameDataStruct.h"


//比較演算子
bool Ｄ３Ｄ位置型::operator==(Ｄ３Ｄ位置型^ v) {
	return (Ｘ == v->Ｘ) && (Ｙ == v->Ｙ) && (Ｚ == v->Ｚ);
}
bool Ｄ３Ｄ位置型::operator!=(Ｄ３Ｄ位置型^ v) {
	return (Ｘ != v->Ｘ) || (Ｙ != v->Ｙ) || (Ｚ != v->Ｚ);
}
//代入演算子
Ｄ３Ｄ位置型^ Ｄ３Ｄ位置型::operator=(Ｄ３Ｄ位置型^ v) {
	this->Ｘ = v->Ｘ;
	this->Ｙ = v->Ｙ;
	this->Ｚ = v->Ｚ;
	return this;
}



//*----------------------メンバ関数の実装--------------------------*//
Ｄ３Ｄベクトル型::Ｄ３Ｄベクトル型() { Ｘ = Ｙ = Ｚ = 0; }
Ｄ３Ｄベクトル型::Ｄ３Ｄベクトル型(double Ｘ成分, double Ｙ成分, double Ｚ成分) {
	this->Ｘ = Ｘ成分;
	this->Ｙ = Ｙ成分;
	this->Ｚ = Ｚ成分;
}
Ｄ３Ｄベクトル型::Ｄ３Ｄベクトル型(Ｄ３Ｄ位置型^ pos) {
	this->Ｘ = pos->Ｘ;
	this->Ｙ = pos->Ｙ;
	this->Ｚ = pos->Ｚ;
}
//代入演算子
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator=(Ｄ３Ｄベクトル型^ v) {
	this->Ｘ = v->Ｘ;
	this->Ｙ = v->Ｙ;
	this->Ｚ = v->Ｚ;
	return this;
}
//単項演算子
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator+=(Ｄ３Ｄベクトル型^ v) {
	this->Ｘ += v->Ｘ;
	this->Ｙ += v->Ｙ;
	this->Ｚ += v->Ｚ;
	return this;
}
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator-=(Ｄ３Ｄベクトル型^ v) {
	this->Ｘ -= v->Ｘ;
	this->Ｙ -= v->Ｙ;
	this->Ｚ -= v->Ｚ;
	return this;
}
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator*=(double k) {
	this->Ｘ *= k;
	this->Ｙ *= k;
	this->Ｚ *= k;
	return this;
}
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator/=(double k) {
	this->Ｘ /= k;
	this->Ｙ /= k;
	this->Ｚ /= k;
	return this;
}
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator+() {		//+Ｄ３Ｄベクトル型
	return this;
}
Ｄ３Ｄベクトル型^ Ｄ３Ｄベクトル型::operator-() {		//-Ｄ３Ｄベクトル型
	return gcnew Ｄ３Ｄベクトル型(-Ｘ, -Ｙ, -Ｚ);
}
//添え字演算子
double Ｄ３Ｄベクトル型::operator[](int i) {
	if (i == 0) {
		return Ｘ;
	}
	else if (i == 1) {
		return Ｙ;
	}
	else if (i == 2) {
		return Ｚ;
	}
	else {
		return Ｘ;
	}
}
//比較演算子
bool Ｄ３Ｄベクトル型::operator==(Ｄ３Ｄベクトル型^ v) {
	return (Ｘ == v->Ｘ) && (Ｙ == v->Ｙ) && (Ｚ == v->Ｚ);
}
bool Ｄ３Ｄベクトル型::operator!=(Ｄ３Ｄベクトル型^ v) {
	return (Ｘ != v->Ｘ) || (Ｙ != v->Ｙ) || (Ｚ != v->Ｚ);
}
//べクトルの長さ
double Ｄ３Ｄベクトル型::長さ::get() {
	return System::Math::Pow((double)(Ｘ*Ｘ + Ｙ*Ｙ + Ｚ*Ｚ), (double)0.5f);
}
//正規化(単位ベクトル化)
void Ｄ３Ｄベクトル型::正規化() {
	if (長さ == 0) {
		デバッグ出力 << "長さが０のベクトル(=方向が無いベクトル)を単位ベクトル化しようとしました。無限０除算でエラーとなります。" << endl;
		this->Ｘ = 0;
		this->Ｙ = 0;
		this->Ｚ = 0;
	}
	else {
		this->Ｘ /= 長さ;
		this->Ｙ /= 長さ;
		this->Ｚ /= 長さ;
	}
}
//*----------------------グローバル関数の実装--------------------------*//
//二項演算子の定義
//Ｄ３Ｄベクトル型+Ｄ３Ｄベクトル型
Ｄ３Ｄベクトル型^ operator+(Ｄ３Ｄベクトル型^ u, Ｄ３Ｄベクトル型^ v) {
	Ｄ３Ｄベクトル型^ w = gcnew Ｄ３Ｄベクトル型();
	w->Ｘ = u->Ｘ + v->Ｘ;
	w->Ｙ = u->Ｙ + v->Ｙ;
	w->Ｚ = u->Ｚ + v->Ｚ;
	return w;
}
//Ｄ３Ｄベクトル型-Ｄ３Ｄベクトル型
Ｄ３Ｄベクトル型^ operator-(Ｄ３Ｄベクトル型^ u, Ｄ３Ｄベクトル型^ v) {
	Ｄ３Ｄベクトル型^ w = gcnew Ｄ３Ｄベクトル型();
	w->Ｘ = u->Ｘ - v->Ｘ;
	w->Ｙ = u->Ｙ - v->Ｙ;
	w->Ｚ = u->Ｚ - v->Ｚ;
	return w;
}
//double*Ｄ３Ｄベクトル型
Ｄ３Ｄベクトル型^ operator*(double k, Ｄ３Ｄベクトル型^ v) {
	return gcnew Ｄ３Ｄベクトル型(k*v->Ｘ, k*v->Ｙ, k*v->Ｚ);
}
//Ｄ３Ｄベクトル型*double
Ｄ３Ｄベクトル型^ operator*(Ｄ３Ｄベクトル型^ v, double k) {
	return gcnew Ｄ３Ｄベクトル型(v->Ｘ*k, v->Ｙ*k, v->Ｚ*k);
}
//Ｄ３Ｄベクトル型/double
Ｄ３Ｄベクトル型^ operator/(Ｄ３Ｄベクトル型^ v, double k) {
	return gcnew Ｄ３Ｄベクトル型(v->Ｘ / k, v->Ｙ / k, v->Ｚ / k);
}
//内積 Ｄ３Ｄベクトル型*Ｄ３Ｄベクトル型
double operator*(Ｄ３Ｄベクトル型^ u, Ｄ３Ｄベクトル型^ v) {
	return u->Ｘ*v->Ｘ + u->Ｙ*v->Ｙ + u->Ｚ*v->Ｚ;
}
//外積 Ｄ３Ｄベクトル型%Ｄ３Ｄベクトル型
Ｄ３Ｄベクトル型^ operator%(Ｄ３Ｄベクトル型^ u, Ｄ３Ｄベクトル型^ v) {
	Ｄ３Ｄベクトル型^ w = gcnew Ｄ３Ｄベクトル型();
	w->Ｘ = u->Ｙ*v->Ｚ - u->Ｚ*v->Ｙ;
	w->Ｙ = u->Ｚ*v->Ｘ - u->Ｘ*v->Ｚ;
	w->Ｚ = u->Ｘ*v->Ｙ - u->Ｙ*v->Ｘ;
	return w;
}

//２つのベクトルのなす角
double 角度(Ｄ３Ｄベクトル型^ u, Ｄ３Ｄベクトル型^ v) {
	double cos = u*v / (u->長さ*v->長さ);
	return double(System::Math::Acos(cos) / System::Math::PI * 180);
}

//２点間座標の差
Ｄ３Ｄベクトル型^ operator-(Ｄ３Ｄ位置型^ p1, Ｄ３Ｄ位置型^ p2) {
	Ｄ３Ｄベクトル型^ v = gcnew Ｄ３Ｄベクトル型();
	v->Ｘ = p1->Ｘ - p2->Ｘ;
	v->Ｙ = p1->Ｙ - p2->Ｙ;
	v->Ｚ = p1->Ｚ - p2->Ｚ;
	return v;
}
