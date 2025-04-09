#include <iostream>

#include "LinkedList.h"

int main11()
{
	tLinkedList list = { };
	 
	InitList(&list);

	/*PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);*/

	/*for (int i = 0; i < 10; i++)
	{
		MyPushFront(&list, (i + 1) * 100);
	}*/

	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	tNode* pNode = list.pHeadNode;

	for (int i = 0; i < list.iCount; i++)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}

// ����
// 1. ������ ����Ʈ PushFront �Լ� �����غ���

// �����迭 ���� ���� �ð� ���⵵ O(n)
// ������ ����Ʈ ���� ���� �ð� ���⵵ O(1) -> �ð� ���⵵�� ����.
// ��, �迭�� ������ �ٲ�� �� ���� ������ LinkedList �� �е������� ����
// �ݸ�, �����͸� �˻� �� ���� �迭�� �ּҿ��� ����� ������ �ʱ� ������
// O(n) ��ŭ�� �ð� ���⵵�� ������ �Ǿ� ���� �迭�� �� ����.

// ���ݱ����� C ��Ÿ�Ϸ� ���� ��, class�� ���� ���� (ch51) ���� C++ ��Ÿ�Ϸ� �������. -> ���� �������� ��Ȯ�� �˸� ������