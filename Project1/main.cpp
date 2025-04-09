
#define HUNGRY  0x001
#define THIRSTY 0x002
#define TIRED   0x004
#define FIRE    0x008

#define COLD    0x010
#define POISON  0x020
#define HOT1    0x040
#define HOT2	0x080
#define HOT3	0x100
#define HOT4	0x200
#define HOT5	0x300
#define HOT6	0x400

// 1. ������
// 2. ��������

// ��������
int global = 0;

// �Լ�
int main1()
{
	// �ڷ��� (ũ�� ����, byte) Data Type
	// ������ : char(1), short(2), int(4), long(4), long long(8)
	// �Ǽ��� : float(4), double(8)
	int i = 0;

	// 1 ����Ʈ�� ����� ǥ��
	// 256���� -> 0 ~ 255
	unsigned char c = 0;
	c = 0;
	// c = -1; -> c = 255;
	

	// 1 ����Ʈ�� ���, ���� �� �� ǥ��
	// - 128 ~ 0 ~ 127
	signed char c1 = 0;
	// c1 = 255; -> c1 = -1;

	// ���� ���� ã�� ( 2�� ������ )
	// �����Ǵ� ����� ��ȣ�� ���� ��, 1�� ���Ѵ�.

	int a = 4 + (int)4.0;

	// ���� ǥ�� ��İ� �Ǽ� ǥ�� ����� �ٸ���.
	// �Ǽ� ǥ�� ����� ���е��� �����Ѵ�.
	// ���� double(8) �ڷ����� float(4) ���� �� �Ʒ��� �Ҽ������� ��Ȯ�ϰ� ǥ���� �����ϴ�.

	// ������ ��������, �Ǽ��� �Ǽ����� �����ϵ�, �� ǥ�� ����� �� �����ڰ� ���� �� ��� ��������� ��ȯ����.
	float f = 10.2415f + (float)20;

	// �Ǽ��� ����� ���� ��� �Ҽ��� �ڿ� f �� ���̸� flaot �ڷ�������, ������ ������ double �ڷ������� �����Ѵ�.
	// 0.1f; 0.1;

	// ������
	// ����	������ : =, +=, -=, *=, /=, %=
	// ��� ������ : +, -, *, /, %(��ⷯ��, ������)
	// ++, -- (���� ������)
	// �� �ܰ� ���� �Ǵ� ����
	int data = 10 + 10;
	// data = data + 20;
	data += 20;
	data = (int)(10.f / 3.f);

	data = 0;
	++data; // ����(��ġ)
	data++; // ����(��ġ)

	// ���� �����ڷ� ����ϴ� ���, ������ �켱������ ���� �������� �и���.

	data = 0;

	a = 10;
	data = a++; // data = 10, a = 11
	data = ++a; // a = 12, data = 12

	data = 0;
	data--;
	data--;

	// �� ������ : &&(and), ||(or), !(not)
	// ��(true), ����(false)
	// �� : 0�� �ƴ� ��� ��, 1 ( 10�̾ ��, 24���� ��, 0�� �ƴϸ� ���ε�, ��������� ��ȯ�ؼ� ���� ����� ������ 1�� ��ȯ )
	// + 0�� �ƴ� � ���ڷ� ���� 1�� �����.
	// ���� : 0
	bool truefalse = false; 
	bool IsTrue = 100; // IsTrue = 1

	IsTrue = true;
	IsTrue = !IsTrue;

	int iTrue = 0;
	iTrue = !iTrue;

	iTrue = 100 && 200; // iTrue = 1
	iTrue = 0 && 200; // iTrue = 0
	iTrue = 100 || 200; // iTrue = 1
	iTrue = 0 || 200; // iTrue = 1
	iTrue = 0 || 0; // iTrue = 0

	// �� ������
	// ==, !=, >, <, >=, <=
	// ��, ����


	// ����
	// if, else
	data = 0;
	if (0 && 200) // false
	{
		data = 100;
	}

	if (data == 100)
	{
		// if �� ���� ��� ����
	}
	else
	{
		// if �� ������ ��� ����
	}

	// �߰��� �ϳ��� �ɸ��� �� ������ ���� �� ����, else ���� ����
	/*if ()
	{

	}
	else if ()
	{

	}
	else()
	{

	}*/

	// siwtch, case if, else if �� ���� �����
	int iTest = 10;
	switch (iTest)
	{
		case 10:
			break;
		case 20:
			break;
		default:
			break;
	} 
	// break �� ������ switch ���� ��������, break �� ������ ���� case ���� ����, 
	// default �� ��� case �� �ɸ��� ���� �� ����, break �Ⱦ��� ���� �Ǽ� ����

	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}

	// ���� ������
	// :? (���ǽ�) ? ���� �� �� : ������ �� ��

	iTest == 20 ? iTest = 100 : iTest = 200;

	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}

	// ��Ʈ ������
	// ����Ʈ <<, >>
	unsigned char byte = 1;

	byte <<= 3; // 2^n���
	byte >>= 2; // 2^n ���� ��

	// ��Ʈ ��(&), ��(|), xor(^), ����(~)
	// ��Ʈ ������ ������ ����,
	// & �Ѵ� 1�� ��� 1
	// | �� �� �ϳ��� 1�� ��� 1
	// ^ ������ 0, �ٸ��� 1
	// ~ 1�� 0����, 0�� 1��

	unsigned int iStatus = 0;

	// ���� �߰�
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	// ���� Ȯ��
	if (iStatus & THIRSTY)
	{

	}

	// Ư�� �ڸ� ��Ʈ ����
	iStatus &= ~THIRSTY;

	// ����
	// 1. ��������
	// 2. ��������
	// 3. ��������
	// 4. �ܺκ���

	// ��������
	int iName = 0;

	// ��ȣ �ȿ� ����� �Լ� (�Լ�, ����)
	{
		// ������ ��Ģ
		int iName = 100;

		iName; // => 100
	}

	iName; // => 0

	return 0;
}