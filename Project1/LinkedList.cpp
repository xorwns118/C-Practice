#include <iostream>

#include "LinkedList.h"

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	// ������ ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ�,
		// �ش� ����� pNext �� ������Ų ����� �ּҷ� ä��
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode) // pNextNode �� nullptr�� �ƴ� ���
		{
			pCurFinalNode = pCurFinalNode->pNextNode;
		}

		pCurFinalNode->pNextNode = pNode;
	}

	++_pList->iCount;
}

void MyPushFront(tLinkedList* _pList, int _iData)
{
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr; // ���� _pList �� pHeadNode ���� ���� ������ �ʿ� ����.
								// ���� ó���� Node �� �ڿ������� nullptr�� ���� 
								// HeadNode�� ���� ó���� ��� �ּҰ����� ����Ǳ� ����

	if (_pList->iCount != 0)
	{
		pNode->pNextNode = _pList->pHeadNode;
	}

	_pList->pHeadNode = pNode;
	_pList->iCount++;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// ���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;

	// ����Ʈ�� ����� �����͸� �����Ѵ�.
	_pList->pHeadNode = pNewNode;

	// ������ ī��Ʈ ����
	++_pList->iCount;
}

void Release(tNode* _pNode)
{
	if (_pNode->pNextNode == nullptr)
		return;

	Release(_pNode->pNextNode);

	free(_pNode);
} // ����Լ� ����, �ܺο� �˸��� ����, �����Ͱ� ������ ���� ȿ���� ������

void ReleaseList(tLinkedList* _pList)
{
	//Release(_pList->pHeadNode);

	tNode* pDeleteNode = _pList->pHeadNode;

	while (pDeleteNode)
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
