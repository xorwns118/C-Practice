#include <iostream>

#include "CList.h"
#include "CArr.h"

#include <vector>
#include <list>

// using namespace std; 네임스페이스를 이것저것 다 해제하다보면 네이밍이 겹치는 부분이 모호해지는 결과를 초래할 수 있음
using std::cout; // 이렇게 네임스페이스 안에 있는 특정 기능만 해제 가능
using std::wcout;
using std::endl;
using std::cin;

using std::vector;
using std::list;

class CTest
{
public:
	int		m_i;

public:
	CTest& operator = (const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	CTest()
		: m_i(0)
	{

	}

	CTest(const CTest& _other) // 복사 생성자, 생성자 오버로딩을 했기 때문에 의도자가 원치 않는 상황을 대비해 나머지 기본 생성자를 만들어주지 않음
		: m_i(_other.m_i)      // **** 기초, 중요!!! *****
	{

	}
	
	~CTest()
	{

	}
};

int main15()
{
	CArr<int> myvector;

	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);

	CArr<int>::iterator myiter = myvector.begin();
	myiter = myvector.erase(myiter);
	int k = *myiter;

	// *myiter
	// ++(전위, 후위), --(전위, 후위), ==, !=
	for (myiter = myvector.begin(); myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}

	myiter = myvector.begin();

	//int iData = (*myiter++); // 전위는 myiter 증가 먼저 실행 된 후 iData에 대입, 후위는 iData에 대입 후 myiter 증가
							 // myiter++ (후위 연산)은 제일 마지막에 연산
	                         // 전위 연산과 후위 연산의 사용에 차이가 없다면 전위 연산을 사용하는 것이 더 효율적이다.
							 // => 후위 연산은 임시 변수를 만들어서 그 값을 저장하고 다시 대입하는 과정이 필요하기 때문

	CTest t1;
	t1.m_i = 100;

	CTest t2(t1); // 생성과 대입을 동시에 실행

	CTest t3 = t1; // 이 경우 컴파일러가 알아서 복사 생성자 호출함 **** 기초, 중요!!! *****

	cout << endl;

	myiter = myvector.begin();

	myiter++;
	myiter++;

	for (; myiter != myvector.end(); myiter--)
	{
		cout << *myiter << endl; 
	}

	// vector::erase
	vector<int> vecInt;

	vecInt.push_back(100);
	vecInt.push_back(200);
	vecInt.push_back(300);
	vecInt.push_back(400);

	vector<int>::iterator veciter = vecInt.begin();
	vecInt.erase(veciter);
	//int i = *veciter; 이미 삭제되고 난 주소를 가리키고 있는 것이기 때문에, veciter에서 유효한 값을 가져올 수 없음
	// => veciter = vecInt.begin(); 과 같이 다시 vecInt의 주소를 받아와야함

	veciter = vecInt.begin(); // or veciter = vecInt.erase(veciter);
	int i = *veciter; // 200

	vecInt.clear();

	// 1 ~ 10 을 벡터에 입력
	for (int i = 0; i < 11; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 1 ~ 5 숫자 제거
	veciter = vecInt.begin();
	for (; veciter != vecInt.end();)
	{
		if (1 <= *veciter && *veciter <= 5)
		{
			// 제거
			veciter = vecInt.erase(veciter); 
			// 매번 veciter++ 를 호출하면 vector 의 요소가 삭제됨과 동시에 다음 값이 그 자리로 넘어오기 때문에
			// 사실상 삭제한 값의 다음 요소를 검사하지 못함
		}
		else
		{
			++veciter; // 삭제하지 않은 경우 ++
		}
	} // 면접에 빈번히 나오는 질문임, ex) veciter++를 반복문에서 매번 호출할 때 문제점

	for (int i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i] << endl;
	}


	// =============
	// list iterator
	// =============
	CList<int> mylist;

	mylist.push_back(100);
	mylist.push_back(300);
	mylist.push_back(400);

	CList<int>::iterator listiter = mylist.begin();
	++listiter;

	listiter = mylist.insert(listiter, 200);
	cout << *listiter << endl;


	cout << "=============" << endl;
	cout << "list iterator" << endl;
	cout << "=============" << endl;
	for (listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
	{
		cout << *listiter << endl;
	}

	return 0;
}