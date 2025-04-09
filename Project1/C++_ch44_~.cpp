#include <iostream>
#include <time.h>

#include "Arr.h"
#include "LinkedList.h"

void BubbleSort(int* _pData, int _iCount)
{
	// �����Ͱ� 1�� �����̸� �������� ����
	if (_iCount <= 1)
		return;

	// �������� ����
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

	// ����(����)
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
	}

	printf("���� ��\n");
	for (int i = 0; i < s1.iCount; i++)
	{
		printf("%d\n", s1.pInt[i]);
	}

	Sort(&s1, &BubbleSort);

	printf("\n");
	printf("���� ��\n");

	for (int i = 0; i < s1.iCount; i++)
	{
		printf("%d\n", s1.pInt[i]);
	}

	ReleaseArr(&s1);

	return 0;
}

// 1. �����迭
// ������ ���� �����ϰ� ������ ��

// 2. �����迭 �ȿ� ���� ������ ����
// - ���� ���� (bubble sort)

// - ���� ���� (insertion sort)
//	 �� ��° �ڷ���� �����Ͽ� �� ��(����)�� �ڷ��� ���Ͽ� ������ ��ġ�� ������ �� 
//	 �ڷḦ �ڷ� �ű�� ������ �ڸ��� �ڷḦ �����Ͽ� �����ϴ� �˰���

// - ���� ���� (selection sort)
//   �ش� ������ ���Ҹ� ���� ��ġ�� �̹� ������ �ְ�, � ���Ҹ� ������ �����ϴ� �˰���

// - �պ� ���� (merge sort)
//   �Ϲ����� ������� �������� �� �� ������ ���� ���� �� ���ϸ�, ���� ���� �˰����� �ϳ� �̴�.
//   ���� ����(divide and conquer) ���
//	 ������ ���� 2���� ������ �и��ϰ� ������ �ذ��� ����, ����� ��Ƽ� ������ ������ �ذ��ϴ� �����̴�.
//	 ���� ���� ����� �밳 ��ȯ ȣ���� �̿��Ͽ� �����Ѵ�.

// - ��� ���� (quick sort) -> ���� ���� Ʈ��
//   ���� ���� �˰����� �ϳ���, ��������� �ſ� ���� ���� �ӵ��� �ڶ��ϴ� ���� ���
//	 �պ� ����(merge sort)�� �޸� �� ������ ����Ʈ�� ��յ��ϰ� �����Ѵ�.

// - �� ���� (heap sort)
//   �ִ� �� Ʈ���� �ּ� �� Ʈ���� ������ ������ �ϴ� ���
//	 �������� ������ ���ؼ��� �ִ� ���� �����ϰ� �������� ������ ���ؼ��� �ּ� ���� �����ϸ� �ȴ�.
