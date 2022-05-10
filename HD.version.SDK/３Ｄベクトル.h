#pragma once


// ���ʂ̂c�R�c�x�N�g���^�B

/// <summary>
/// �R�c�ʒu�i������3DPosition�Ƃ������T�O)�̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v</para>
/// <para>���A
/// <code>
/// �c�R�c�x�N�g���^ v = p2 - p1
/// </code>
/// </para>
/// <para>�Ƃ����悤�ɁA�`�n�_����a�n�_���������ƂŁA�P�̕����x�N�g���ƂȂ�܂��B</para>
/// </summary>
public ref class �c�R�c�ʒu�^ {
public:

	double �w;  // �w�ʒu
	double �x;  // �x�ʒu
	double �y;  // �y�ʒu

	/// <summary>
	/// �w�ʒu�A�x�ʒu�A�y�ʒu���w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w�ʒu">�w�ʒu</param>
	/// <param name="�x�ʒu">�x�ʒu</param>
	/// <param name="�y�ʒu">�y�ʒu</param>
	�c�R�c�ʒu�^(double �w�ʒu, double �x�ʒu, double �y�ʒu) : �w(�w�ʒu), �x(�x�ʒu), �y(�y�ʒu) {}

	/// <summary>
	/// ���_�ʒu�̃R���X�g���N�^�B
	/// </summary>
	�c�R�c�ʒu�^() : �w(0), �x(0), �y(0) {}

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�c�R�c�ʒu�^^ operator=(�c�R�c�ʒu�^^ v);

	bool operator==(�c�R�c�ʒu�^^ v); // == ��r���Z�q
	bool operator!=(�c�R�c�ʒu�^^ v); // != ��r���Z�q
};


/// <summary>
/// �R�c�x�N�g���̃N���X�B
/// <para>������r���Z�q�Ƃ��ẮA �u==�v�Ɓu!=�v</para>
/// </summary>
public ref class �c�R�c�x�N�g���^ {
public:

	double �w;  // �w����
	double �x;  // �x����
	double �y;  // �y����

	/// <summary>
	/// �S�Ă̐������O�̃R���X�g���N�^�B
	/// </summary>
	�c�R�c�x�N�g���^();

	/// <summary>
	/// �w�����A�x�����A�y�������w�肷��R���X�g���N�^
	/// </summary>
	/// <param name="�w����">�w����</param>
	/// <param name="�x����">�x����</param>
	/// <param name="�y����">�y����</param>
	�c�R�c�x�N�g���^(double �w����, double �x����, double �y����);

	/// <summary>
	/// �ʒu�^�v�f�����̂܂܃x�N�g����
	/// </summary>
	�c�R�c�x�N�g���^(�c�R�c�ʒu�^^ pos);

	/// <summary>
	/// �R�s�[�R���X�g���N�^�����B
	/// </summary>
	�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator=(�c�R�c�x�N�g���^^ v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�c�R�c�x�N�g���^^ operator+=(�c�R�c�x�N�g���^^ v);

	/// <summary>
	/// �x�N�g�����Z
	/// </summary>
	�c�R�c�x�N�g���^^ operator-=(�c�R�c�x�N�g���^^ v);

	/// <summary>
	/// �x�N�g����k�{��
	/// </summary>
	�c�R�c�x�N�g���^^ operator*=(double k);

	/// <summary>
	/// �x�N�g����k���̈��
	/// </summary>
	�c�R�c�x�N�g���^^ operator/=(double k);

	/// <summary>
	/// �P����+(�v���X)
	/// </summary>
	�c�R�c�x�N�g���^^ operator+();

	/// <summary>
	/// �P����+(�}�C�i�X)
	/// </summary>
	�c�R�c�x�N�g���^^ operator-();

	/// <summary>
	/// �Y�������Z�q�B0==�w�����A1==�x�����A2==�y���� �̂��ƁB
	/// </summary>
	double operator[](int i);

	bool operator==(�c�R�c�x�N�g���^^ v); // == ��r���Z�q
	bool operator!=(�c�R�c�x�N�g���^^ v); // != ��r���Z�q

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
�c�R�c�x�N�g���^^ operator+(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v);

/// <summary>
/// �x�N�g�����Z
/// </summary>
�c�R�c�x�N�g���^^ operator-(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�c�R�c�x�N�g���^^ operator*(double k, �c�R�c�x�N�g���^^ v);

/// <summary>
/// �x�N�g����k�{��
/// </summary>
�c�R�c�x�N�g���^^ operator*(�c�R�c�x�N�g���^^ v, double k);

/// <summary>
/// �x�N�g����k���̈��
/// </summary>
�c�R�c�x�N�g���^^ operator/(�c�R�c�x�N�g���^^ v, double k);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ�����
/// </summary>
double operator*(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��O��
/// </summary>
�c�R�c�x�N�g���^^ operator%(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v);

/// <summary>
/// �Q�̃x�N�g���̂Ȃ��p�x
/// </summary>
double �p�x(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v);

/// <summary>
/// �Q�_�ԍ��W�̍�
/// </summary>
�c�R�c�x�N�g���^^ operator-(�c�R�c�ʒu�^^ p1, �c�R�c�ʒu�^^ p2);
