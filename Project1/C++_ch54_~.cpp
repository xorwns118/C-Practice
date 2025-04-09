#include <iostream>

#include "Arr.h"
#include "CArr.h"

class CTest 
{
private:
	int a;

public:
	CTest()
	{

	}
};


template<typename T> // typename �� class�� ��� ���������� ��� �˰� �ִ� class �ʹ� �ٸ�
T Add(T a, T b)
{
	return a + b;
}

int main13()
{
	// ����ü --> Ŭ����

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ
	// ����� �����ϱ� ���� �ʿ��� ��� ����, ����, ���м�
	// ��� �Լ���

	// 2. ���

	// 3. ������

	// 4. �߻�ȭ

	// ����ü ���� �����迭 --> Ŭ���� ����

	// C++ �����Ҵ� new, delete
	CTest* pTest = new CTest;
	delete pTest;

	// CArr ����
	tArr arr = {};
	InitArr(&arr);

	PushBack(&arr, 10);
	PushBack(&arr, 20);
	PushBack(&arr, 30);

	ReleaseArr(&arr);

	CArr<float> carr;
	carr.push_back(3.14f);
	carr.push_back(6.28f);
	carr.push_back(30.444f);

	float iData = carr[1];

	// �Լ� ���ø�
	int i = Add<int>(10, 20); // �Լ��� �Լ� ���ø��� ������ �ٸ� <int> �κ��� ���ڰ� int �̰� ������ �ڷ����� int �� ����
							  // �����Ϸ��� �˰� �ֱ� ������ ��������

	return 0;
}