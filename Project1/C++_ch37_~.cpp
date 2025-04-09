#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <assert.h>

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�)

// �Լ� �����ε�
// �Լ� �������̵��� ȥ���� �� ����. �����ؼ� �����ϴ°� ��õ
//void Test(int a) 
//{
//
//}
//
//void Test(float a)
//{
//
//}
// ��ó�� ���ڸ� �ٸ� ���� �̸��� ���� �Լ��� �����ε��̶�� ��

typedef struct _tagMyST
{
	int a; // ���
	float f;
}MYST;

unsigned int GetLength(const wchar_t* _pStr)
{
	// ���� ���� üũ �뵵
	int i = 0;

	/* while (true)
	{
		wchar_t c = _pStr[i]; // => *(_pStr + i);
		if ('\0' == c ) => c == '\0' �� �ݴ�� �ۼ��� ������ c = '0' ���� �񱳿����� �ƴ� ������ �ϴ� �Ǽ��� �����ϱ� ����.
						   ������ �� ��� c�� '\0'�� �������� ��� �׻� false �� ���� ���� ���� �ɸ� �� ����
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

	if (_iBufferSize < iDestLen + iSrcLen + 1)  // Null ���ڱ��� ���
	{
		assert(nullptr);
	}
	
	// ������ �ܼ��ؼ� �������� ���߿� ������ �Լ��� ����� �Ǹ� �߰��� ������ �ȵǼ� �ð� ������ ��찡 ����.
	// �̸��̸� �� �ؾ����� �����ϰ� �����ؾ� ���� ���ϰ� ���� ����.
	
	// ���ڿ� �̾� ���̱�
	// 1. Dets ���ڿ��� ���� Ȯ�� ( ���ڿ��� �̾���� ���� ��ġ )
	// 2. �ݺ������� Src ���ڿ��� Dest �� ��ġ�� �����ϱ�
	// 3. Src ���ڿ��� ���� ������ �ݺ� ����

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

// ����
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

	// ���ڿ� �̾� ���̱�
	wcscat_s(szString, 10, L"def");
	//       ������, ������ ũ��, �̾���� ���� �ּ�

	StrCat(szString, 10, L"def");

	int iRet = wcscmp(L"abc", L"abc"); //������ ��ġ�ϸ� 0, �������� ���������� �� ������ 1, ������ �� ������ -1

	int solution = MyCompareStr(L"abc", L"abc");
	
	iRet = StrCmp(L"abc", L"abc");

	printf("wcscmp �� �� : %d\n MyCompareStr �� �� : %d", iRet, solution);

	// ����ü�� ������
	MYST s = {}; // ����� ������ �ƴ�. s�� ����

	MYST* pST = &s;
	// pST + 1;  int�� float���� �����Ǿ��� ������ 8byte �� ���

	(*pST).a = 100;
	(*pST).f = 3.14f;

	pST->a = 100; // ���� ������ ���
	pST->f = 3.14f;

	return 0;
}

// ����
// wcscmp �Լ� ���� ������ ����
// 1. �Լ� ���� ����
// 2. ��� ��� (�������, �ٸ����)