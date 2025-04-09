#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)

// 함수 오버로딩
// 함수 오버라이딩과 혼용할 수 있음. 구분해서 정리하는거 추천
//void Test(int a) 
//{
//
//}
//
//void Test(float a)
//{
//
//}
// 위처럼 인자만 다른 같은 이름의 여러 함수를 오버로딩이라고 함

typedef struct _tagMyST
{
	int a; // 멤버
	float f;
}MYST;

unsigned int GetLength(const wchar_t* _pStr)
{
	// 문자 개수 체크 용도
	int i = 0;

	/* while (true)
	{
		wchar_t c = _pStr[i]; // => *(_pStr + i);
		if ('\0' == c ) => c == '\0' 의 반대로 작성한 이유는 c = '0' 으로 비교연산이 아닌 대입을 하는 실수를 방지하기 위함.
						   대입을 할 경우 c에 '\0'을 대입했을 경우 항상 false 로 나와 무한 루프 걸릴 수 있음
		{
			break;
		}
		++i;
	} */

	while (_pStr[i] != '\0')
	{
		++i;
	}

	return i;
}

void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1)  // Null 문자까지 계산
	{
		assert(nullptr);
	}
	
	// 지금은 단순해서 괜찮지만 나중에 복잡한 함수를 만들게 되면 중간에 정리가 안되서 시간 날리는 경우가 있음.
	// 미리미리 뭐 해야할지 정리하고 시행해야 나도 편하고 남도 편함.
	
	// 문자열 이어 붙이기
	// 1. Dets 문자열의 끝을 확인 ( 문자열이 이어붙을 시작 위치 )
	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	// 3. Src 문자열의 끝을 만나면 반복 종료

	for (int i = 0; i < iSrcLen + 1; i++)
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int BiggerValue(const wchar_t l, const wchar_t r)
{
	if (l > r)
	{
		return 1;
	}
	else if (l < r)
	{
		return -1;
	}
}

// 과제
int MyCompareStr(const wchar_t* _lStr, const wchar_t* _rStr)
{
	int lStrLen = GetLength(_lStr);
	int rStrLen = GetLength(_rStr);

	if (lStrLen < rStrLen)
	{
		for (int i = 0; i < lStrLen; i++)
		{
			if(_lStr[i] != _rStr[i])
				return BiggerValue(_lStr[i], _rStr[i]);
		}
		return -1;
	}
	else if (lStrLen > rStrLen)
	{
		for (int i = 0; i < rStrLen; i++)
		{
			if (_lStr[i] != _rStr[i])
				return BiggerValue(_lStr[i], _rStr[i]);
		}
		return 1;
	}

	for (int i = 0; i < lStrLen; i++)
	{
		if (_lStr[i] != _rStr[i])
			return BiggerValue(_lStr[i], _rStr[i]);
	}
	return 0;
}

int StrCmp(const wchar_t* _left, const wchar_t* _right)
{
	int leftLen = GetLength(_left);
	int rightLen = GetLength(_right);

	int iLoop = leftLen;
	int iReturn = 0;

	if (leftLen < rightLen)
	{
		iLoop = leftLen;
		iReturn = -1;
	}
	else if(leftLen > rightLen)
	{
		iLoop = rightLen;
		iReturn = 1;
	}

	for (int i = 0; i < iLoop; i++)
	{
		if (_left[i] < _right[i])
		{
			return -1;
		}
		else if(_left[i] > _right[i])
		{
			return 1;
		}
	}

	return iReturn;
}

int main8()
{
	wchar_t szName[10] = L"Raimond";

	int iLen = wcslen(szName);

	iLen = GetLength(szName);

	/*Test(10);
	Test(3.14f);*/

	wchar_t szString[10] = L"abc";

	// 문자열 이어 붙이기
	wcscat_s(szString, 10, L"def");
	//       목적지, 목적지 크기, 이어붙일 문자 주소

	StrCat(szString, 10, L"def");

	int iRet = wcscmp(L"abc", L"abc"); //양쪽이 일치하면 0, 오른쪽이 사전순으로 더 먼저면 1, 왼쪽이 더 먼저면 -1

	int solution = MyCompareStr(L"abc", L"abc");
	
	iRet = StrCmp(L"abc", L"abc");

	printf("wcscmp 의 값 : %d\n MyCompareStr 의 값 : %d", iRet, solution);

	// 구조체와 포인터
	MYST s = {}; // 멤버는 변수가 아님. s가 변수

	MYST* pST = &s;
	// pST + 1;  int와 float으로 구성되었기 때문에 8byte 씩 계산

	(*pST).a = 100;
	(*pST).f = 3.14f;

	pST->a = 100; // 위와 동일한 기능
	pST->f = 3.14f;

	return 0;
}

// 과제
// wcscmp 함수 직접 구현해 보기
// 1. 함수 구현 사진
// 2. 결과 장면 (같은경우, 다른경우)