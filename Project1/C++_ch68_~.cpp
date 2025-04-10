// 트리 용어
// 이진 트리 : 자식의 갯수가 2개 이하인 트리

// Level : 제일 상위 층(루트 노드) 부터 (리프 노드)까지의 층 번호

// 완전 이진 트리 : 루트노드로부터 리프노드까지 자식의 갯수가 모두 2개인 트리 
// -> 배열로 표현 가능 
// 2k + 1, 2k + 2 (k = 부모 노드 && 뒤의 1, 2는 자식 노드)
// 반대로 계산하면 자식 노드로 부터 부모 노드를 알 수 있음

// 이진 탐색 트리 (Binary Search Tree) : 탐색을 위해 보완된 이진 트리 (최악의 경우가 log₂n => O(logN))
// 입력할 때 순서가 정렬되어 있는 상태에서 트리를 만들 때 제일 느림
// 시간 복잡도 순서 O(1) < O(logN) < O(N) < O(nlogN) < O(N²)
// 1. 데이터가 정렬되어 있어야함. (면접때 자주 물어봄)
// 2. 문제를 절반으로 나누는 방식으로 탐색을 진행함.
// 3. 왼쪽 자식 노드는 부모 노드보다 작고, 오른쪽 자식 노드는 부모 노드보다 큼
// 데이터를 입력할 땐 시간이 조금 더 걸릴 수 있으나, 탐색을 할 땐 압도적인 효율을 보여줌
// 이진 탐색 트리는 중위 순회함.
// 중위 순회 (In Order) : 왼쪽 자식 노드 -> 부모 노드 -> 오른쪽 자식 노드 순서로 탐색함
// 전위 순회 (Pre Order) : 부모 노드 -> 왼쪽 자식 노드 -> 오른쪽 자식 노드 순서로 탐색함
// 후위 순회 (Post Order) : 왼쪽 자식 노드 -> 오른쪽 자식 노드 -> 부모 노드 순서로 탐색함

#include <iostream>

#include <map>
#include <set>

#include <string>

#include "CBST.h"

using std::wcout;
using std::endl;

using std::map;
using std::make_pair;

using std::set;

using std::wstring;

// 열거형
// #define 과 비슷한 면이 있음. => 전처리에 의해 상수값이 정해지기 때문에 디버깅 시 지정해놓은 상수값이 얼마인지 알 수 없음.
// 다른 열거형과의 중복에 의한 모호한 경우가 발생할 수 있음, => enum class 사용
// 각각 다른 타입의 enum 클래스를 만들어 다른 enum 타입과의 중복을 방지함
enum class MY_TYPE
{
	TYPE_1, // 0
	TYPE_2, // 1
	TYPE_3, // 2
	TYPE_4, // 4
	TYPE_5 = 100,
	TYPE_6, // 101
};

enum class OTHER_TYPE
{
	TYPE_1,
};

#define MAN		1
#define WOMAN	2

struct tStdInfo
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo()
		: szName{}
		, age(0)
		, gender(0)
	{

	}
	tStdInfo(const wchar_t* _pName, unsigned _age, unsigned _gender)
		: szName{}
		, age(_age)
		, gender(_gender)
	{
		wcscpy_s(szName, _pName);
	}
};

struct pair
{
	wchar_t* first;
	tStdInfo second;
};

int main() // 16
{
	// 이진 탐색
	// 1. 정렬 되어있는 데이터에 적용 가능, 트리에서만 가능한 것이 아니기에 트리와 무관함

	// 이진 탐색 트리
	// 1. 이진 탐색을 사용 할 수 있게 고안된 이진 트리
	// 2. 데이터 입력 시 O(logN) 효율
	// 3. 탐색 효율은 O(logN)
	// 4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	//	- 자가균형 기능 필요 (AVL, Red/Black)

	// 레드/블랙 트리를 사용한 컨테이너
	// 실제 자주 사용되지 않음, 자주 사용되는 컨테이너는 map
	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	const wchar_t* pStr = L"문자열";

	map<const wchar_t*, tStdInfo> mapData;
	// wchar_t* 로 찾은 문자열은 사실상 트리로 찾은 것이 아닌 직접 타이핑한 문자열의 주소로 가서 찾은것
	// => 다른 임의의 문자열 변수를 생성하고 같은 문자열을 입력한 뒤 그 변수로 찾으라고 하면 주소가 다르기 때문에 찾을 수 없음.

	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert(make_pair(L"홍길동", info));
	mapData.insert(make_pair(L"이지혜", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"이지혜");

	_wsetlocale(LC_ALL, L"korean");

	// 찾지 못했다.
	if (mapiter == mapData.end())
	{
		wcout << L"데이터를 찾을 수 없습니다." << endl;
	}
	else
	{
		wcout << L"이름 : " << mapiter->second.szName << endl;
		wcout << L"나이 : " << mapiter->second.age << endl;
		if (mapiter->second.gender == MAN)
		{
			wcout << L"성별 : 남자" << endl;
		}
		else if(mapiter->second.gender == WOMAN)
		{
			wcout << L"성별 : 여자" << endl;
		}
		else
		{
			wcout << L"성별 : 알 수 없음" << endl;
		}
	}

	map<wstring, tStdInfo> mapStdInfo;

	// 문자열의 주소를 가져오는 것이 아닌 자체적인 공간에 문자열을 저장함.
	// 방식은 vector<wchar_t> 와 거의 유사함
	wstring str;
	str = L"abcdef";
	str += L"ghijk";
	str += L"lmnop";
	str[1] = L'c';

	str = L"abcdefghijklmnopqrstuvwxyz";

	wstring str2;
	
	// wstring 끼리의 비교 연산이 가능함, 주소연산이 아닌 문자열을 비교
	if (str == str2)
	{

	}

	CBST<int, int> bstint;

	bstint.insert(make_bstpair(100, 0));
	bstint.insert(make_bstpair(150, 0));
	bstint.insert(make_bstpair(50, 0));

	CBST<int, int>::iterator Iter = bstint.begin();

	Iter = bstint.find(50);

	(*Iter).first;
	Iter->first;

	(*Iter).second;
	Iter->second;

	tPair<int, int> pair;

	tPair<int, int>* pPair = &pair;
	pPair->first;
	pPair->second;

	for (Iter = bstint.begin(); Iter != bstint.end(); ++Iter)
	{
		wcout << Iter->first << " " << Iter->second << endl;
	}

	// erase 
	// 자식이 없는 경우 : 삭제만 하면 끝
	// 자식이 하나만 있는 경우 : 삭제 된 자리에 자식으로 대체
	// 자식이 둘인 경우 : 중위 선행자 혹은 중위 후속자로 대체

	bstint.insert(make_bstpair(25, 0));		//            100
	bstint.insert(make_bstpair(75, 0));		//		  50        150
	bstint.insert(make_bstpair(125, 0));	//      25   75  125   175
	bstint.insert(make_bstpair(175, 0));

	Iter = bstint.find(150);
	Iter = bstint.erase(Iter);

	Iter = bstint.find(100);
	Iter = bstint.erase(Iter);

	return 0;
}