#include "GameDataStruct.h"


//”äŠr‰‰Zq
bool ‚c‚R‚cˆÊ’uŒ^::operator==(‚c‚R‚cˆÊ’uŒ^^ v) {
	return (‚w == v->‚w) && (‚x == v->‚x) && (‚y == v->‚y);
}
bool ‚c‚R‚cˆÊ’uŒ^::operator!=(‚c‚R‚cˆÊ’uŒ^^ v) {
	return (‚w != v->‚w) || (‚x != v->‚x) || (‚y != v->‚y);
}
//‘ã“ü‰‰Zq
‚c‚R‚cˆÊ’uŒ^^ ‚c‚R‚cˆÊ’uŒ^::operator=(‚c‚R‚cˆÊ’uŒ^^ v) {
	this->‚w = v->‚w;
	this->‚x = v->‚x;
	this->‚y = v->‚y;
	return this;
}



//*----------------------ƒƒ“ƒoŠÖ”‚ÌÀ‘•--------------------------*//
‚c‚R‚cƒxƒNƒgƒ‹Œ^::‚c‚R‚cƒxƒNƒgƒ‹Œ^() { ‚w = ‚x = ‚y = 0; }
‚c‚R‚cƒxƒNƒgƒ‹Œ^::‚c‚R‚cƒxƒNƒgƒ‹Œ^(double ‚w¬•ª, double ‚x¬•ª, double ‚y¬•ª) {
	this->‚w = ‚w¬•ª;
	this->‚x = ‚x¬•ª;
	this->‚y = ‚y¬•ª;
}
‚c‚R‚cƒxƒNƒgƒ‹Œ^::‚c‚R‚cƒxƒNƒgƒ‹Œ^(‚c‚R‚cˆÊ’uŒ^^ pos) {
	this->‚w = pos->‚w;
	this->‚x = pos->‚x;
	this->‚y = pos->‚y;
}
//‘ã“ü‰‰Zq
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator=(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	this->‚w = v->‚w;
	this->‚x = v->‚x;
	this->‚y = v->‚y;
	return this;
}
//’P€‰‰Zq
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator+=(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	this->‚w += v->‚w;
	this->‚x += v->‚x;
	this->‚y += v->‚y;
	return this;
}
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator-=(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	this->‚w -= v->‚w;
	this->‚x -= v->‚x;
	this->‚y -= v->‚y;
	return this;
}
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator*=(double k) {
	this->‚w *= k;
	this->‚x *= k;
	this->‚y *= k;
	return this;
}
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator/=(double k) {
	this->‚w /= k;
	this->‚x /= k;
	this->‚y /= k;
	return this;
}
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator+() {		//+‚c‚R‚cƒxƒNƒgƒ‹Œ^
	return this;
}
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator-() {		//-‚c‚R‚cƒxƒNƒgƒ‹Œ^
	return gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^(-‚w, -‚x, -‚y);
}
//“Y‚¦š‰‰Zq
double ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator[](int i) {
	if (i == 0) {
		return ‚w;
	}
	else if (i == 1) {
		return ‚x;
	}
	else if (i == 2) {
		return ‚y;
	}
	else {
		return ‚w;
	}
}
//”äŠr‰‰Zq
bool ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator==(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	return (‚w == v->‚w) && (‚x == v->‚x) && (‚y == v->‚y);
}
bool ‚c‚R‚cƒxƒNƒgƒ‹Œ^::operator!=(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	return (‚w != v->‚w) || (‚x != v->‚x) || (‚y != v->‚y);
}
//‚×ƒNƒgƒ‹‚Ì’·‚³
double ‚c‚R‚cƒxƒNƒgƒ‹Œ^::’·‚³::get() {
	return System::Math::Pow((double)(‚w*‚w + ‚x*‚x + ‚y*‚y), (double)0.5f);
}
//³‹K‰»(’PˆÊƒxƒNƒgƒ‹‰»)
void ‚c‚R‚cƒxƒNƒgƒ‹Œ^::³‹K‰»() {
	if (’·‚³ == 0) {
		ƒfƒoƒbƒOo—Í << "’·‚³‚ª‚O‚ÌƒxƒNƒgƒ‹(=•ûŒü‚ª–³‚¢ƒxƒNƒgƒ‹)‚ğ’PˆÊƒxƒNƒgƒ‹‰»‚µ‚æ‚¤‚Æ‚µ‚Ü‚µ‚½B–³ŒÀ‚OœZ‚ÅƒGƒ‰[‚Æ‚È‚è‚Ü‚·B" << endl;
		this->‚w = 0;
		this->‚x = 0;
		this->‚y = 0;
	}
	else {
		this->‚w /= ’·‚³;
		this->‚x /= ’·‚³;
		this->‚y /= ’·‚³;
	}
}
//*----------------------ƒOƒ[ƒoƒ‹ŠÖ”‚ÌÀ‘•--------------------------*//
//“ñ€‰‰Zq‚Ì’è‹`
//‚c‚R‚cƒxƒNƒgƒ‹Œ^+‚c‚R‚cƒxƒNƒgƒ‹Œ^
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator+(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	‚c‚R‚cƒxƒNƒgƒ‹Œ^^ w = gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^();
	w->‚w = u->‚w + v->‚w;
	w->‚x = u->‚x + v->‚x;
	w->‚y = u->‚y + v->‚y;
	return w;
}
//‚c‚R‚cƒxƒNƒgƒ‹Œ^-‚c‚R‚cƒxƒNƒgƒ‹Œ^
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator-(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	‚c‚R‚cƒxƒNƒgƒ‹Œ^^ w = gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^();
	w->‚w = u->‚w - v->‚w;
	w->‚x = u->‚x - v->‚x;
	w->‚y = u->‚y - v->‚y;
	return w;
}
//double*‚c‚R‚cƒxƒNƒgƒ‹Œ^
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator*(double k, ‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	return gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^(k*v->‚w, k*v->‚x, k*v->‚y);
}
//‚c‚R‚cƒxƒNƒgƒ‹Œ^*double
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator*(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v, double k) {
	return gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^(v->‚w*k, v->‚x*k, v->‚y*k);
}
//‚c‚R‚cƒxƒNƒgƒ‹Œ^/double
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator/(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v, double k) {
	return gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^(v->‚w / k, v->‚x / k, v->‚y / k);
}
//“àÏ ‚c‚R‚cƒxƒNƒgƒ‹Œ^*‚c‚R‚cƒxƒNƒgƒ‹Œ^
double operator*(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	return u->‚w*v->‚w + u->‚x*v->‚x + u->‚y*v->‚y;
}
//ŠOÏ ‚c‚R‚cƒxƒNƒgƒ‹Œ^%‚c‚R‚cƒxƒNƒgƒ‹Œ^
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator%(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	‚c‚R‚cƒxƒNƒgƒ‹Œ^^ w = gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^();
	w->‚w = u->‚x*v->‚y - u->‚y*v->‚x;
	w->‚x = u->‚y*v->‚w - u->‚w*v->‚y;
	w->‚y = u->‚w*v->‚x - u->‚x*v->‚w;
	return w;
}

//‚Q‚Â‚ÌƒxƒNƒgƒ‹‚Ì‚È‚·Šp
double Šp“x(‚c‚R‚cƒxƒNƒgƒ‹Œ^^ u, ‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v) {
	double cos = u*v / (u->’·‚³*v->’·‚³);
	return double(System::Math::Acos(cos) / System::Math::PI * 180);
}

//‚Q“_ŠÔÀ•W‚Ì·
‚c‚R‚cƒxƒNƒgƒ‹Œ^^ operator-(‚c‚R‚cˆÊ’uŒ^^ p1, ‚c‚R‚cˆÊ’uŒ^^ p2) {
	‚c‚R‚cƒxƒNƒgƒ‹Œ^^ v = gcnew ‚c‚R‚cƒxƒNƒgƒ‹Œ^();
	v->‚w = p1->‚w - p2->‚w;
	v->‚x = p1->‚x - p2->‚x;
	v->‚y = p1->‚y - p2->‚y;
	return v;
}
