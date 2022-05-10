
#include "GeometryMath.h"





// ����A1x, A1y �� A2x, A2y  ��  ����B1x, B1y �� B2x, B2y  �Ƃ� �Փ˂��邩�ǂ����B
bool LineAndLine( double A1x, double A1y, double A2x, double A2y, double B1x, double B1y, double B2x, double B2y ){
	{
		const double baseX = B2x - B1x;
		const double baseY = B2y - B1y;
		const double sub1X = A1x - B1x;
		const double sub1Y = A1y - B1y;
		const double sub2X = A2x - B1x;
		const double sub2Y = A2y - B1y;

		const double bs1 = baseX * sub1Y - baseY * sub1X;
		const double bs2 = baseX * sub2Y - baseY * sub2X;
		const double re = bs1 * bs2;
		if( re > 0 ){
			return false;
		}
	}
	{
		const double baseX = A2x - A1x;
		const double baseY = A2y - A1y;
		const double sub1X = B1x - A1x;
		const double sub1Y = B1y - A1y;
		const double sub2X = B2x - A1x;
		const double sub2Y = B2y - A1y;

		const double bs1 = baseX * sub1Y - baseY * sub1X;
		const double bs2 = baseX * sub2Y - baseY * sub2X;
		const double re = bs1 * bs2;
		if( re > 0 ){
			return false;
		}
	}
	return true;
}

// �l�p�`�Ɛ����Ƃ̏Փ˂̔���
bool RectAndLine( double left, double top, double right, double bottom, double x1, double y1, double x2, double y2 ){
	if( LineAndLine( left, top, right, top, x1, y1, x2, y2 ) ){ return true; 	}
	if( LineAndLine( right, top, right, bottom, x1, y1, x2, y2 ) ){ return true; }
	if( LineAndLine( right, bottom, left, bottom, x1, y1, x2, y2 ) ){ return true; }
	if( LineAndLine( left, bottom, left, top, x1, y1, x2, y2 ) ){ return true; }

	return false;
}



/*-----------------------------------------------------------------
	���Wpos �ɍł��߂� ����ab��̍��W ���v�Z
  -----------------------------------------------------------------*/
D3D_POSITION GetClosePosToLine( D3D_POSITION pos, D3D_POSITION a, D3D_POSITION b) {

	if ( a == b ) { // a==b�B���Ȃ킿�������\�z���Ă��Ȃ��B
		return a;
	}
	// ��������ȍ~�� b-a �ɂ͒��������邱�Ƃ��ۏႳ��Ă���B

	D3D_VECTOR lineVec = D3D_VECTOR( b - a );
	lineVec.normalize(); // �P�ʃx�N�g����

	double dotA = lineVec * (pos-a); // ����
	if ( dotA < 0 ) {
		return a;
	}

	double dotB = (lineVec * -1) * (pos-b); // ����
	if ( dotB < 0 ) {
		return b;
	}

	D3D_VECTOR ret = D3D_VECTOR(a) + D3D_VECTOR(lineVec * dotA);
	return D3D_POSITION(ret.x, ret.y, ret.z);
}


/*-----------------------------------------------------------------
	���Wpos �� ����ab �Ƃ̋������v�Z
  -----------------------------------------------------------------*/
double GetDistanceToLine( D3D_POSITION pos, D3D_POSITION a, D3D_POSITION b) {
	D3D_POSITION close_pos = GetClosePosToLine(pos, a, b);
	D3D_VECTOR vclose_pos(close_pos-pos);
	return vclose_pos.length();
}



