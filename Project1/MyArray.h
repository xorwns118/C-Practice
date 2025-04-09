#pragma once

typedef struct _tagMyArr
{
	int*	pInt;
	int		iCount;
	int		iMaxCount;
}tMyArr;

// �迭 �ʱ�ȭ
void InitMyArr(tMyArr* _pMyArr);

// ������ �߰� (2�� �ø� ����)
void PushMyArr(tMyArr* _pMyArr, int iValue);

// ���� �޸� ����
void ReleaseMemory(tMyArr* _pMyArr);

// ���� ����
void BubbleSort(tMyArr* _pMyArr);
