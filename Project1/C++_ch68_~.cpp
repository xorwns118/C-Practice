// Ʈ�� ���
// ���� Ʈ�� : �ڽ��� ������ 2�� ������ Ʈ��

// Level : ���� ���� ��(��Ʈ ���) ���� (���� ���)������ �� ��ȣ

// ���� ���� Ʈ�� : ��Ʈ���κ��� ���������� �ڽ��� ������ ��� 2���� Ʈ�� 
// -> �迭�� ǥ�� ���� 
// 2k + 1, 2k + 2 (k = �θ� ��� && ���� 1, 2�� �ڽ� ���)
// �ݴ�� ����ϸ� �ڽ� ���� ���� �θ� ��带 �� �� ����

// ���� Ž�� Ʈ�� (Binary Search Tree) : Ž���� ���� ���ϵ� ���� Ʈ�� (�־��� ��찡 log��n => O(logN))
// �Է��� �� ������ ���ĵǾ� �ִ� ���¿��� Ʈ���� ���� �� ���� ����
// �ð� ���⵵ ���� O(1) < O(logN) < O(N) < O(nlogN) < O(N��)
// 1. �����Ͱ� ���ĵǾ� �־����. (������ ���� ���)
// 2. ������ �������� ������ ������� Ž���� ������.
// 3. ���� �ڽ� ���� �θ� ��庸�� �۰�, ������ �ڽ� ���� �θ� ��庸�� ŭ
// �����͸� �Է��� �� �ð��� ���� �� �ɸ� �� ������, Ž���� �� �� �е����� ȿ���� ������
// ���� Ž�� Ʈ���� ���� ��ȸ��.
// ���� ��ȸ (In Order) : ���� �ڽ� ��� -> �θ� ��� -> ������ �ڽ� ��� ������ Ž����
// ���� ��ȸ (Pre Order) : �θ� ��� -> ���� �ڽ� ��� -> ������ �ڽ� ��� ������ Ž����
// ���� ��ȸ (Post Order) : ���� �ڽ� ��� -> ������ �ڽ� ��� -> �θ� ��� ������ Ž����

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

// ������
// #define �� ����� ���� ����. => ��ó���� ���� ������� �������� ������ ����� �� �����س��� ������� ������ �� �� ����.
// �ٸ� ���������� �ߺ��� ���� ��ȣ�� ��찡 �߻��� �� ����, => enum class ���
// ���� �ٸ� Ÿ���� enum Ŭ������ ����� �ٸ� enum Ÿ�԰��� �ߺ��� ������
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
	// ���� Ž��
	// 1. ���� �Ǿ��ִ� �����Ϳ� ���� ����, Ʈ�������� ������ ���� �ƴϱ⿡ Ʈ���� ������

	// ���� Ž�� Ʈ��
	// 1. ���� Ž���� ��� �� �� �ְ� ��ȵ� ���� Ʈ��
	// 2. ������ �Է� �� O(logN) ȿ��
	// 3. Ž�� ȿ���� O(logN)
	// 4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	//	- �ڰ����� ��� �ʿ� (AVL, Red/Black)

	// ����/�� Ʈ���� ����� �����̳�
	// ���� ���� ������ ����, ���� ���Ǵ� �����̳ʴ� map
	set<int> setInt;

	setInt.insert(100);
	setInt.insert(50);
	setInt.insert(150);

	const wchar_t* pStr = L"���ڿ�";

	map<const wchar_t*, tStdInfo> mapData;
	// wchar_t* �� ã�� ���ڿ��� ��ǻ� Ʈ���� ã�� ���� �ƴ� ���� Ÿ������ ���ڿ��� �ּҷ� ���� ã����
	// => �ٸ� ������ ���ڿ� ������ �����ϰ� ���� ���ڿ��� �Է��� �� �� ������ ã����� �ϸ� �ּҰ� �ٸ��� ������ ã�� �� ����.

	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert(make_pair(L"ȫ�浿", info));
	mapData.insert(make_pair(L"������", info2));

	map<const wchar_t*, tStdInfo>::iterator mapiter;
	mapiter = mapData.find(L"������");

	_wsetlocale(LC_ALL, L"korean");

	// ã�� ���ߴ�.
	if (mapiter == mapData.end())
	{
		wcout << L"�����͸� ã�� �� �����ϴ�." << endl;
	}
	else
	{
		wcout << L"�̸� : " << mapiter->second.szName << endl;
		wcout << L"���� : " << mapiter->second.age << endl;
		if (mapiter->second.gender == MAN)
		{
			wcout << L"���� : ����" << endl;
		}
		else if(mapiter->second.gender == WOMAN)
		{
			wcout << L"���� : ����" << endl;
		}
		else
		{
			wcout << L"���� : �� �� ����" << endl;
		}
	}

	map<wstring, tStdInfo> mapStdInfo;

	// ���ڿ��� �ּҸ� �������� ���� �ƴ� ��ü���� ������ ���ڿ��� ������.
	// ����� vector<wchar_t> �� ���� ������
	wstring str;
	str = L"abcdef";
	str += L"ghijk";
	str += L"lmnop";
	str[1] = L'c';

	str = L"abcdefghijklmnopqrstuvwxyz";

	wstring str2;
	
	// wstring ������ �� ������ ������, �ּҿ����� �ƴ� ���ڿ��� ��
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
	// �ڽ��� ���� ��� : ������ �ϸ� ��
	// �ڽ��� �ϳ��� �ִ� ��� : ���� �� �ڸ��� �ڽ����� ��ü
	// �ڽ��� ���� ��� : ���� ������ Ȥ�� ���� �ļ��ڷ� ��ü

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