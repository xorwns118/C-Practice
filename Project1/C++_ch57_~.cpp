#include <iostream>

#include "CList.h"
#include "CArr.h"

#include <vector>
#include <list>

namespace MYSPACE
{
	int g_int;
}

namespace OTHERSPACE
{
	int g_int;
}

// using namespace std; 네임스페이스를 이것저것 다 해제하다보면 네이밍이 겹치는 부분이 모호해지는 결과를 초래할 수 있음
using std::cout; // 이렇게 네임스페이스 안에 있는 특정 기능만 해제 가능
using std::wcout;
using std::endl;
using std::cin;
using std::vector;
using std::list;

void MyEndL()
{
	wprintf(L"\n");
}

class CMyOStream
{
public:
	CMyOStream& operator << (int _idata)
	{
		wprintf(L"%d", _idata);
		return *this;
	}

	CMyOStream& operator << (const wchar_t* _iString)
	{
		wprintf(L"%s", _iString);
		return *this;
	}

	CMyOStream& operator << (void(*_pFunc)(void))
	{
		_pFunc();
		return *this;
	}

	CMyOStream& operator >> (int& _idata)
	{
		scanf_s("%d", &_idata);
		return *this;
	}
};
CMyOStream mycout;

int main14()
{
	CList<float> List;

	for (int i = 0; i < 4; i++)
	{
		List.push_back(i);
	}

	//// C printf
	//cout << "안녕" << 10 << endl; // std::endl == \n

	//// C scanf
	//int iInput = 0;
	//cin >> iInput;

	//MYSPACE::g_int = 0;
	//OTHERSPACE::g_int = 0;
	
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	// 아스키코드 대응표를 한글쪽으로 맞춤

	mycout << 10 << 20 << 30;
	mycout << L"안녕";

	int a = 0;
	mycout >> a;
	mycout << 10 << L" " << 20 << L" " << L"문자열" << MyEndL;

	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100;
	// vecInt.at(1) => vecInt[1]
	a = vecInt.at(0); // 인덱스(parameter) 값
	int* v_pInt = vecInt.data(); // 시작 주소값
	a = vecInt.size(); // 현재 입력되어있는 갯수
	a = vecInt.capacity(); // 현재 입력할 수 있는 범위

	for (size_t i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt.at(i) /*vecInt[i]*/ << endl;
	}


	vector<int>::iterator veciter = vecInt.begin(); // 시작 주소값
	// *veciter; => vecInt[0];
	*veciter = 100;
	vecInt[0] = 100;

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(100);
	a = listInt.size();
	// listInt[1]; 구현할 수 있지만 Array와 같이 연속된 구조라고 오해할 여지가 있어 구현해놓지 않음.

	// iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	int iData = *iter; // 역참조 operator, iter 가 가리키고 있는 주소의 값을 return
	++iter; // 다음 주소값
	iData = *iter;

	for (iter = listInt.begin(); iter != listInt.end(); iter++) // end()는 마지막 주소값의 다음 주소를 가르키고 있음 (아무것도 없는)
	{
		cout << *iter << endl;
	}

	return 0;
}