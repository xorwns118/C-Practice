#include <iostream>

#include "MyArray.h"

void InitMyArr(tMyArr* _pMyArr)
{
	_pMyArr->pInt = (int*)malloc(sizeof(int) * 2);
	_pMyArr->iCount = 0;
	_pMyArr->iMaxCount = 2;
}

void Reallocate(tMyArr* _pMyArr)
{
	int* newArr = (int*)malloc(_pMyArr->iMaxCount * sizeof(int) * 2);

	for (int i = 0; i < _pMyArr->iCount; i++)
	{
		newArr[i] = _pMyArr->pInt[i];
	}
	free(_pMyArr->pInt);

	_pMyArr->iMaxCount *= 2;
	_pMyArr->pInt = newArr;
}

void PushMyArr(tMyArr* _pMyArr, const int _iValue)
{
	if (_pMyArr->iMaxCount <= _pMyArr->iCount)
	{
		Reallocate(_pMyArr);
	}

	_pMyArr->pInt[_pMyArr->iCount++] = _iValue;
}

void ReleaseMemory(tMyArr* _pMyArr)
{
	free(_pMyArr->pInt);
}

void BubbleSort(tMyArr* _pMyArr)
{
	if (_pMyArr->iCount <= 1)
		return;

	for (int i = 0; i < _pMyArr->iCount; i++)
	{
		for (int j = 0; j < _pMyArr->iCount - 1; j++)
		{
			if (_pMyArr->pInt[j] > _pMyArr->pInt[j + 1])
			{
				int temp = _pMyArr->pInt[j];
				_pMyArr->pInt[j] = _pMyArr->pInt[j + 1];
				_pMyArr->pInt[j + 1] = temp;
			}
		}
	}
}