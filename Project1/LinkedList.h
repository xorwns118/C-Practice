#pragma once

typedef struct _tagNode
{
	int				  iData;
	struct _tagNode*  pNextNode;
}tNode;

typedef struct _tagList
{
	tNode*  pHeadNode;
	int		iCount;
}tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);
void MyPushFront(tLinkedList* _pList, int _iData); // 과제 : 새로운 데이터를 앞에 추가하는 함수 구현하기
void PushFront(tLinkedList* _pList, int _iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);