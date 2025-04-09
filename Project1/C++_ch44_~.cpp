#include <iostream>
#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

void BubbleSort(int* _pData, int _iCount)
{
	// 데이터가 1개 이하이면 정렬하지 않음
	if (_iCount <= 1)
		return;

	// 오름차순 정렬
	while (true)
	{
		bool bFinish = true;
		
		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; i++)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}

		if (bFinish)
			break;
	}
}

//void Test()
//{
//
//}


int main10()
{
	/*void(*pFunc)(void) = nullptr;
	pFunc = Test;

	pFunc();*/

	int iArr[10] = { 134, 1324, 43243, 123, 3432, 14, 24, 525, 22, 91 };

	BubbleSort(iArr, 10);

	tArr s1 = {};

	InitArr(&s1);

	// 난수(랜덤)
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
	}

	printf("정렬 전\n");
	for (int i = 0; i < s1.iCount; i++)
	{
		printf("%d\n", s1.pInt[i]);
	}

	Sort(&s1, &BubbleSort);

	printf("\n");
	printf("정렬 후\n");

	for (int i = 0; i < s1.iCount; i++)
	{
		printf("%d\n", s1.pInt[i]);
	}

	ReleaseArr(&s1);

	return 0;
}

// 1. 가변배열
// 스스로 구현 가능하게 복습할 것

// 2. 가변배열 안에 넣은 데이터 정렬
// - 버블 정렬 (bubble sort)

// - 삽입 정렬 (insertion sort)
//	 두 번째 자료부터 시작하여 그 앞(왼쪽)의 자료들과 비교하여 삽입할 위치를 지정한 후 
//	 자료를 뒤로 옮기고 지정한 자리에 자료를 삽입하여 정렬하는 알고리즘

// - 선택 정렬 (selection sort)
//   해당 순서에 원소를 넣을 위치는 이미 정해져 있고, 어떤 원소를 넣을지 선택하는 알고리즘

// - 합병 정렬 (merge sort)
//   일반적인 방법으로 구현했을 때 이 정렬은 안정 정렬 에 속하며, 분할 정복 알고리즘의 하나 이다.
//   분할 정복(divide and conquer) 방법
//	 문제를 작은 2개의 문제로 분리하고 각각을 해결한 다음, 결과를 모아서 원래의 문제를 해결하는 전략이다.
//	 분할 정복 방법은 대개 순환 호출을 이용하여 구현한다.

// - 쾌속 정렬 (quick sort) -> 완전 이진 트리
//   분할 정복 알고리즘의 하나로, 평균적으로 매우 빠른 수행 속도를 자랑하는 정렬 방법
//	 합병 정렬(merge sort)과 달리 퀵 정렬은 리스트를 비균등하게 분할한다.

// - 힙 정렬 (heap sort)
//   최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법
//	 내림차순 정렬을 위해서는 최대 힙을 구성하고 오름차순 정렬을 위해서는 최소 힙을 구성하면 된다.
