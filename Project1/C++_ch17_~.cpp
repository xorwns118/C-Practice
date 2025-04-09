#include <stdio.h>

// 함수
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

// 재귀함수
// 가독성, 구현의 용이성
// 단점, 속도가 느리다

// 재귀함수 팩토리얼
int Factorial_Re(int _iNum)
{ 
	// 7! = 7 * 6!
	if (_iNum == 1)
	{
		return 1;
	}

	return _iNum * Factorial_Re(_iNum - 1);
}

// 피보나치 수열
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

// 꼬리재귀
int Fibonacci_Re(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}
	return Fibonacci_Re(_iNum - 1) + Fibonacci_Re(_iNum - 2); 
	// 예시일 뿐, _iNum 값이 조금만 커져도 이렇게 하면 진짜 개느림 (약간 DFS 느낌?)
}

int main3()
{
	int iValue = Factorial(4);
	iValue = Factorial(10);
	iValue = Factorial_Re(10);

	iValue = Fibonacci(10);
	iValue = Fibonacci_Re(10);

	// 배열
	// 메모리가 연속적
	int iArray[10] = { };

	iArray[9] = 10;
	// ex) iArray[12] 처럼 인덱스를 벗어났을 때 그 메모리 주소가 다른 변수의 메모리 주소를 가리킬 수 있어 조심해야 함.

	int iData = 0;

	int iArray2[100] = { };

	return iValue;
}