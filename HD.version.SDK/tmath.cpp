

/**
 * 0.5�𑫂��Ă���؂�̂Ă邱�Ƃŏ����_�ȉ����l�̌ܓ�����
 * @param[in] x �l�̌ܓ����s�����������_��
 * @return �l�̌ܓ��̌���
 */
int round�s�������t(double a) {
    return int(a+.5-(a<0)); 
}

double round�s�񕪂̈�z�����t(double a) {
    double b = a * 2;
	b = round�s�������t(b+.5-(b<0));
	return b/2;
}
