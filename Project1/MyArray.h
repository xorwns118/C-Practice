#pragma once

typedef struct _tagMyArr
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;
}tMyArr;

// 배열 초기화
void InitMyArr(tMyArr* _pMyArr);

// 데이터 추가 (2배 늘릴 예정)
void PushMyArr(tMyArr* _pMyArr, int iValue);

// 기존 메모리 해제
void ReleaseMemory(tMyArr* _pMyArr);

// 버블 정렬
void BubbleSort(tMyArr* _pMyArr);
