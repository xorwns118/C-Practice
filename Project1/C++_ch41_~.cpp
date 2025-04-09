#include <iostream>

#include "Arr.h"

// 변수
// 지역(스택)
// 전역, 정적, 외부 (데이터)

// 메모리 영역
// 스택
// 데이터
// ROM
// 힙heap 영역 (동적 할당)

void Test(int a)
{
	printf("%d\n", a);
}

int main9()
{
	{
		int* pInt = (int*)malloc(100); // 100byte 가 힙 영역에 만들어짐
		// void 포인터는 어떤 자료형 기준으로 볼지 모르는 상태라 강제 캐스팅이 필요
		float* pF = (float*)malloc(4);

		int* pI = (int*)pF;

		// *pF = 2.4f;
		// int i = *pI; // 이렇게 하면 부동소수점으로 표현하는 실수를 정수형 자료형으로 비트를 해석하여 전혀 다른 값이 나옴

		// 동적 할당
		// 1. 런타임 중에 대응 가능
		// 2. 사용자가 직접 메모리를 관리해야함(해제)

		Test(10);

		int iInput = 0;
		scanf_s("%d\n", &iInput);

		int* pInt2 = nullptr;

		if (100 == iInput)
		{
			pInt2 = (int*)malloc(100);
		}

		// 이렇게 프로그램 종료 전에 직접 해제 시켜주어야 함
		// 해제 안할 시 메모리 누수가 발생
		if (nullptr != pInt2)
		{
			free(pInt2); // 힙 메모리를 해제시키는 함수
		}
	}

	{
		// 가변 배열
		int a = 100;
		int iInput = 0;
		scanf_s("%d", &a);

		// 배열의 개수를 선언할 때에는 변수를 사용할 수 없다.
		// int arr[a] = {}; 값이 바뀔 수 있는 변수를 사용하게 되면 메모리를 얼마나 사용해야할지 정할 수 없기 때문에 사용하지 못함
		
		// 객체(instance) 의도한 자료형의 실질적인 데이터 ( 자료형 = 도장, 객체 = 도장으로 찍어낸 것 )
		// int,
		// int a;
	
	}


	return 0;
}