#include "GameDataStruct.h"

//”äŠr‰‰Zq
bool ‚c‚Q‚cˆÊ’uŒ^::operator==(const ‚c‚Q‚cˆÊ’uŒ^^ v) {
	return (‚w == v->‚w) && (‚x == v->‚x);
}
bool ‚c‚Q‚cˆÊ’uŒ^::operator!=(const ‚c‚Q‚cˆÊ’uŒ^^ v) {
	return (‚w != v->‚w) || (‚x != v->‚x);
}
//‘ã“ü‰‰Zq
‚c‚Q‚cˆÊ’uŒ^^ ‚c‚Q‚cˆÊ’uŒ^::operator=(const ‚c‚Q‚cˆÊ’uŒ^^ v) {
	this->‚w = v->‚w;
	this->‚x = v->‚x;
	return this;
}



//*----------------------ƒƒ“ƒoŠÖ”‚ÌÀ‘•--------------------------*//
‚c‚Q‚cƒxƒNƒgƒ‹Œ^::‚c‚Q‚cƒxƒNƒgƒ‹Œ^() { ‚w = ‚x = 0; }
‚c‚Q‚cƒxƒNƒgƒ‹Œ^::‚c‚Q‚cƒxƒNƒgƒ‹Œ^(double ‚w¬•ª, double ‚x¬•ª) {
	this->‚w = ‚w¬•ª;
	this->‚x = ‚x¬•ª;
}
‚c‚Q‚cƒxƒNƒgƒ‹Œ^::‚c‚Q‚cƒxƒNƒgƒ‹Œ^(‚c‚Q‚cˆÊ’uŒ^^ pos) {
	this->‚w = pos->‚w;
	this->‚x = pos->‚x;
}

//‘ã“ü‰‰Zq
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator=(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	this->‚w = v->‚w;
	this->‚x = v->‚x;
	return this;
}
//’P€‰‰Zq
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator+=(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	this->‚w += v->‚w;
	this->‚x += v->‚x;
	return this;
}
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator-=(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	this->‚w -= v->‚w;
	this->‚x -= v->‚x;
	return this;
}
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator*=(double k) {
	this->‚w *= k;
	this->‚x *= k;
	return this;
}
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator/=(double k) {
	this->‚w /= k;
	this->‚x /= k;
	return this;
}
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator+() {		//+‚c‚Q‚cƒxƒNƒgƒ‹Œ^
	return this;
}
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator-() {		//-‚c‚Q‚cƒxƒNƒgƒ‹Œ^
	return gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^(-‚w, -‚x);
}
//“Y‚¦š‰‰Zq
double ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator[](int i) {
	if (i == 0) {
		return ‚w;
	}
	else if (i == 1) {
		return ‚x;
	}
	else {
		return ‚w;
	}
}
//”äŠr‰‰Zq
bool ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator==(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	return (‚w == v->‚w) && (‚x == v->‚x);
}
bool ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::operator!=(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	return (‚w != v->‚w) || (‚x != v->‚x);
}
//‚×ƒNƒgƒ‹‚Ì’·‚³
double ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::’·‚³::get() {
	return System::Math::Pow((double)(‚w*‚w + ‚x*‚x), (double)0.5f);
}
//³‹K‰»(’PˆÊƒxƒNƒgƒ‹‰»)
void ‚c‚Q‚cƒxƒNƒgƒ‹Œ^::³‹K‰»() {
	if (’·‚³ == 0) {
		ƒfƒoƒbƒOo—Í << "’·‚³‚ª‚O‚ÌƒxƒNƒgƒ‹(=•ûŒü‚ª–³‚¢ƒxƒNƒgƒ‹)‚ğ’PˆÊƒxƒNƒgƒ‹‰»‚µ‚æ‚¤‚Æ‚µ‚Ü‚µ‚½B–³ŒÀ‚OœZ‚ÅƒGƒ‰[‚Æ‚È‚è‚Ü‚·B" << endl;
		this->‚w = 0;
		this->‚x = 0;
	}
	else {
		this->‚w /= ’·‚³;
		this->‚x /= ’·‚³;
	}
}
//*----------------------ƒOƒ[ƒoƒ‹ŠÖ”‚ÌÀ‘•--------------------------*//
//“ñ€‰‰Zq‚Ì’è‹`
//‚c‚Q‚cƒxƒNƒgƒ‹Œ^+‚c‚Q‚cƒxƒNƒgƒ‹Œ^
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ operator+(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ w = gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^();
	w->‚w = u->‚w + v->‚w;
	w->‚x = u->‚x + v->‚x;
	return w;
}
//‚c‚Q‚cƒxƒNƒgƒ‹Œ^-‚c‚Q‚cƒxƒNƒgƒ‹Œ^
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ operator-(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ w = gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^();
	w->‚w = u->‚w - v->‚w;
	w->‚x = u->‚x - v->‚x;
	return w;
}
//double*‚c‚Q‚cƒxƒNƒgƒ‹Œ^
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ operator*(double k, ‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	return gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^(k*v->‚w, k*v->‚x);
}
//‚c‚Q‚cƒxƒNƒgƒ‹Œ^*double
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ operator*(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v, double k) {
	return gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^(v->‚w*k, v->‚x*k);
}
//‚c‚Q‚cƒxƒNƒgƒ‹Œ^/double
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ operator/(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v, double k) {
	return gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^(v->‚w / k, v->‚x / k);
}
//“àÏ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^*‚c‚Q‚cƒxƒNƒgƒ‹Œ^
double operator*(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	return u->‚w*v->‚w + u->‚x*v->‚x;
}

//ŠOÏ ‚c‚Q‚cƒxƒNƒgƒ‹Œ^%‚c‚Q‚cƒxƒNƒgƒ‹Œ^
double operator%(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ w = gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^();
	return u->‚w*v->‚x - u->‚x*v->‚w;
}

//‚Q‚Â‚ÌƒxƒNƒgƒ‹‚Ì‚È‚·Šp
double Šp“x(‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v) {
	double cos = u*v / (u->’·‚³*v->’·‚³);
	return double(System::Math::Acos(cos) / System::Math::PI * 180);
}

//‚Q“_ŠÔÀ•W‚Ì·
‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ operator-(‚c‚Q‚cˆÊ’uŒ^^ p1, ‚c‚Q‚cˆÊ’uŒ^^ p2) {
	‚c‚Q‚cƒxƒNƒgƒ‹Œ^^ v = gcnew ‚c‚Q‚cƒxƒNƒgƒ‹Œ^();
	v->‚w = p1->‚w - p2->‚w;
	v->‚x = p1->‚x - p2->‚x;
	return v;
}

