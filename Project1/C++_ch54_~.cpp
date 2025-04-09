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


template<typename T> // typename 은 class로 적어도 무방하지만 평소 알고 있는 class 와는 다름
T Add(T a, T b)
{
	return a + b;
}

int main13()
{
	// 구조체 --> 클래스

	// 객체지향 언어 특징
	// 1. 캡슐화
	// 기능을 수행하기 위해 필요한 멤버 선언, 묶음, 은닉성
	// 멤버 함수들

	// 2. 상속

	// 3. 다형성

	// 4. 추상화

	// 구조체 버전 가변배열 --> 클래스 버전

	// C++ 동적할당 new, delete
	CTest* pTest = new CTest;
	delete pTest;

	// CArr 예시
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

	// 함수 템플릿
	int i = Add<int>(10, 20); // 함수와 함수 템플릿은 엄연히 다름 <int> 부분은 인자가 int 이고 변수의 자료형이 int 인 것을
							  // 컴파일러가 알고 있기 때문에 생략가능

	return 0;
}