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

// 과제
// 1. 연결형 리스트 PushFront 함수 구현해보기

// 가변배열 순서 변경 시간 복잡도 O(n)
// 연결형 리스트 순서 변경 시간 복잡도 O(1) -> 시간 복잡도가 없음.
// 즉, 배열의 순서를 바꿔야 할 일이 있으면 LinkedList 가 압도적으로 빠름
// 반면, 데이터를 검색 할 때는 배열의 주소연산 방식이 먹히지 않기 때문에
// O(n) 만큼의 시간 복잡도를 가지게 되어 가변 배열이 더 빠름.

// 지금까지는 C 스타일로 만든 것, class에 대한 설명 (ch51) 부터 C++ 스타일로 만들것임. -> 둘의 차이점을 명확히 알면 좋을듯