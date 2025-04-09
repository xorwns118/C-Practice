#include "Arr.h"

#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->pInt = (int*)malloc(sizeof(int)*2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

// 공간 추가 확장 (외부에 알리지 않을 함수는 .h 파일에서 제외 후 .cpp 파일에서 구현 및 사용)
void Reallocate(tArr* _pArr)
{
	// 1. 2배 더 큰 공간을 동적할당한다. (새로운 공간을 할당하지 않으면 의도치 않게 다른 heap 메모리에 접근 할 수 있어
	//  해결하기 위해 복잡한 일이 생길 수 있음) -> heap corruption 힙 손상
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사한다.
	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	_pArr->pInt = pNew;

	// 5. MaxCount 변경점 적용
	_pArr->iMaxCount *= 2;
}

void PushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간이 꽉참
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		Reallocate(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData; // 주소의 pInt값의 _iCount번째 인덱스에 _iData 를 넣고
										   // 후연산자를 통해 _iCount 값 증가
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCount);
}
