#include <stdio.h>

// �Լ�
// Factorial

int Factorial(int _iNum)
{
	int iValue = 1;

	for (int i = 0; i < _iNum - 1; i++)
	{
		iValue *= (i + 2);
	}

	return iValue;
}

// ����Լ�
// ������, ������ ���̼�
// ����, �ӵ��� ������

// ����Լ� ���丮��
int Factorial_Re(int _iNum)
{ 
	// 7! = 7 * 6!
	if (_iNum == 1)
	{
		return 1;
	}

	return _iNum * Factorial_Re(_iNum - 1);
}

// �Ǻ���ġ ����
// 1 1 2 3 5 8 13 21 34 55.....

int Fibonacci(int _iNum)
{
	int before = 1;
	int after = 1;

	int count = 0;

	for (int i = 0; i < _iNum - 2; i++)
	{
		count = before + after;
		before = after;
		after = count;
	}

	return count;
}

// �������
int Fibonacci_Re(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}
	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2); 
	// ������ ��, _iNum ���� ���ݸ� Ŀ���� �̷��� �ϸ� ��¥ ������ (�ణ DFS ����?)
}

int main3()
{
	int iValue = Factorial(4);
	iValue = Factorial(10);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(10);
	iValue = Fibonacci_Re(10);

	// �迭
	// �޸𸮰� ������
	int iArray[10] = { };

	iArray[9] = 10;
	// ex) iArray[12] ó�� �ε����� ����� �� �� �޸� �ּҰ� �ٸ� ������ �޸� �ּҸ� ����ų �� �־� �����ؾ� ��.

	int iData = 0;

	int iArray2[100] = { };

	return iValue;
}