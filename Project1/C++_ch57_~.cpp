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

// using namespace std; ���ӽ����̽��� �̰����� �� �����ϴٺ��� ���̹��� ��ġ�� �κ��� ��ȣ������ ����� �ʷ��� �� ����
using std::cout; // �̷��� ���ӽ����̽� �ȿ� �ִ� Ư�� ��ɸ� ���� ����
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
	//cout << "�ȳ�" << 10 << endl; // std::endl == \n

	//// C scanf
	//int iInput = 0;
	//cin >> iInput;

	//MYSPACE::g_int = 0;
	//OTHERSPACE::g_int = 0;
	
	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean");
	// �ƽ�Ű�ڵ� ����ǥ�� �ѱ������� ����

	mycout << 10 << 20 << 30;
	mycout << L"�ȳ�";

	int a = 0;
	mycout >> a;
	mycout << 10 << L" " << 20 << L" " << L"���ڿ�" << MyEndL;

	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100;
	// vecInt.at(1) => vecInt[1]
	a = vecInt.at(0); // �ε���(parameter) ��
	int* v_pInt = vecInt.data(); // ���� �ּҰ�
	a = vecInt.size(); // ���� �ԷµǾ��ִ� ����
	a = vecInt.capacity(); // ���� �Է��� �� �ִ� ����

	for (size_t i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt.at(i) /*vecInt[i]*/ << endl;
	}


	vector<int>::iterator veciter = vecInt.begin(); // ���� �ּҰ�
	// *veciter; => vecInt[0];
	*veciter = 100;
	vecInt[0] = 100;

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(100);
	a = listInt.size();
	// listInt[1]; ������ �� ������ Array�� ���� ���ӵ� ������� ������ ������ �־� �����س��� ����.

	// iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	int iData = *iter; // ������ operator, iter �� ����Ű�� �ִ� �ּ��� ���� return
	++iter; // ���� �ּҰ�
	iData = *iter;

	for (iter = listInt.begin(); iter != listInt.end(); iter++) // end()�� ������ �ּҰ��� ���� �ּҸ� ����Ű�� ���� (�ƹ��͵� ����)
	{
		cout << *iter << endl;
	}

	return 0;
}