#include <iostream>

#include "LinkedList.h"

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	// 데이터 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서,
		// 해당 노드의 pNext 를 생성시킨 노드의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (pCurFinalNode->pNextNode) // pNextNode 가 nullptr이 아닌 경우
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
	pNode->pNextNode = nullptr; // 기존 _pList 의 pHeadNode 값이 들어가기 때문에 필요 없음.
								// 제일 처음의 Node 는 자연스럽게 nullptr이 들어가고 
								// HeadNode는 제일 처음의 노드 주소값으로 변경되기 때문

	if (_pList->iCount != 0)
	{
		pNode->pNextNode = _pList->pHeadNode;
	}

	_pList->pHeadNode = pNode;
	_pList->iCount++;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	// 새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* pNewNode = (tNode*)malloc(sizeof(tNode));
	pNewNode->iData = _iData;
	pNewNode->pNextNode = _pList->pHeadNode;

	// 리스트의 헤드노드 포인터를 갱신한다.
	_pList->pHeadNode = pNewNode;

	// 데이터 카운트 증가
	++_pList->iCount;
}

void Release(tNode* _pNode)
{
	if (_pNode->pNextNode == nullptr)
		return;

	Release(_pNode->pNextNode);

	free(_pNode);
} // 재귀함수 버전, 외부에 알리지 않음, 데이터가 많아질 수록 효율이 떨어짐

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
