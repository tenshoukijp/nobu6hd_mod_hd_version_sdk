#pragma once


/// <summary>
/// �Q�c�ʒu�i������Position��Point�Ƃ������T�O)�̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v�B</para>
/// <para>���A
/// <code>
/// �c�Q�c�x�N�g���^ v = p2 - p1
/// </code>
/// </para>
/// <para>�Ƃ����悤�ɁA�`�n�_����a�n�_���������ƂŁA�P�̕����x�N�g���ƂȂ�܂��B</para>
/// </summary>
public ref class �c�Q�c�ʒu�^ {
public:
	double �w;  // �w�ʒu
	double �x;  // �x�ʒu

	/// <summary>
	/// �w�ʒu�A�x�ʒu���w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w�ʒu">�w�ʒu</param>
	/// <param name="�x�ʒu">�x�ʒu</param>
	�c�Q�c�ʒu�^(double �w�ʒu, double �x�ʒu) : �w(�w�ʒu), �x(�x�ʒu) {}

	/// <summary>
	/// ���_�ʒu�̃R���X�g���N�^�B
	/// </summary>
	�c�Q�c�ʒu�^() : �w(0), �x(0) {}

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�c�Q�c�ʒu�^^ operator=(const �c�Q�c�ʒu�^^ v);

	bool operator==(const �c�Q�c�ʒu�^^ v); // == ��r���Z�q
	bool operator!=(const �c�Q�c�ʒu�^^ v); // != ��r���Z�q
};



/// <summary>
/// �Q�c�x�N�g���̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v</para>
/// </summary>
public ref class �c�Q�c�x�N�g���^ {
public:

	double �w;  // �w����
	double �x;  // �x����

	/// <summary>
	/// �S�Ă̐������O�̃R���X�g���N�^�B
	/// </summary>
	�c�Q�c�x�N�g���^();


	/// <summary>
	/// �w�����A�x�����A�y�������w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w����">�w����</param>
	/// <param name="�x����">�x����</param>
	�c�Q�c�x�N�g���^(double �w����, double �x����);

	/// <summary>
	/// �ʒu�^�v�f�����̂܂܃x�N�g����
	/// </summary>
	�c�Q�c�x�N�g���^(�c�Q�c�ʒu�^^ pos);

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator=(�c�Q�c�x�N�g���^^ v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�c�Q�c�x�N�g���^^ operator+=(�c�Q�c�x�N�g���^^ v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�c�Q�c�x�N�g���^^ operator-=(�c�Q�c�x�N�g���^^ v);

	/// <summary>
	/// �x�N�g����k�{��
	/// </summary>
	�c�Q�c�x�N�g���^^ operator*=(double k);

	/// <summary>
	/// �x�N�g����k���̈��
	/// </summary>
	�c�Q�c�x�N�g���^^ operator/=(double k);

	/// <summary>
	/// �P����+(�v���X)
	/// </summary>
	�c�Q�c�x�N�g���^^ operator+();

	/// <summary>
	/// �P����+(�}�C�i�X)
	/// </summary>
	�c�Q�c�x�N�g���^^ operator-();

	/// <summary>
	/// �Y�������Z�q�B0==�w�����A1==�x���� �̂��ƁB
	/// </summary>
	double operator[](int i);

	bool operator==(�c�Q�c�x�N�g���^^ v); // == ��r���Z�q
	bool operator!=(�c�Q�c�x�N�g���^^ v); // != ��r���Z�q

	/// <summary>
	/// �׃N�g���̒���
	/// </summary>
	property double ���� {
		double get();
	}

	/// <summary>
	/// �P�ʃx�N�g���ւ̐��K���B
	/// <para>�����O���ƒP�ʃx�N�g���ɏo���Ȃ��̂Œ���</para>
	/// </summary>
	void ���K��();
};

/// <summary>
/// �x�N�g�����Z
/// </summary>
�c�Q�c�x�N�g���^^ operator+(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v);

/// <summary>
/// �x�N�g�����Z
/// </summary>
�c�Q�c�x�N�g���^^ operator-(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�c�Q�c�x�N�g���^^ operator*(double k, �c�Q�c�x�N�g���^^ v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�c�Q�c�x�N�g���^^ operator*(�c�Q�c�x�N�g���^^ v, double k);

/// <summary>
/// �x�N�g����k���̈��
/// </summary>
�c�Q�c�x�N�g���^^ operator/(�c�Q�c�x�N�g���^^ v, double k);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ�����
/// </summary>
double operator*(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��O��
/// </summary>
double operator%(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��p�x
/// </summary>
double �p�x(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v);

/// <summary>
/// �Q�_�ԍ��W�̍�
/// </summary>
�c�Q�c�x�N�g���^^ operator-(�c�Q�c�ʒu�^^ p1, �c�Q�c�ʒu�^^ p2);
