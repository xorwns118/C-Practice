#include <iostream>

#include "CList.h"
#include "CArr.h"

#include <vector>
#include <list>

// using namespace std; ���ӽ����̽��� �̰����� �� �����ϴٺ��� ���̹��� ��ġ�� �κ��� ��ȣ������ ����� �ʷ��� �� ����
using std::cout; // �̷��� ���ӽ����̽� �ȿ� �ִ� Ư�� ��ɸ� ���� ����
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

	CTest(const CTest& _other) // ���� ������, ������ �����ε��� �߱� ������ �ǵ��ڰ� ��ġ �ʴ� ��Ȳ�� ����� ������ �⺻ �����ڸ� ��������� ����
		: m_i(_other.m_i)      // **** ����, �߿�!!! *****
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
	// ++(����, ����), --(����, ����), ==, !=
	for (myiter = myvector.begin(); myiter != myvector.end(); ++myiter)
	{
		cout << *myiter << endl;
	}

	myiter = myvector.begin();

	//int iData = (*myiter++); // ������ myiter ���� ���� ���� �� �� iData�� ����, ������ iData�� ���� �� myiter ����
							 // myiter++ (���� ����)�� ���� �������� ����
	                         // ���� ����� ���� ������ ��뿡 ���̰� ���ٸ� ���� ������ ����ϴ� ���� �� ȿ�����̴�.
							 // => ���� ������ �ӽ� ������ ���� �� ���� �����ϰ� �ٽ� �����ϴ� ������ �ʿ��ϱ� ����

	CTest t1;
	t1.m_i = 100;

	CTest t2(t1); // ������ ������ ���ÿ� ����

	CTest t3 = t1; // �� ��� �����Ϸ��� �˾Ƽ� ���� ������ ȣ���� **** ����, �߿�!!! *****

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
	//int i = *veciter; �̹� �����ǰ� �� �ּҸ� ����Ű�� �ִ� ���̱� ������, veciter���� ��ȿ�� ���� ������ �� ����
	// => veciter = vecInt.begin(); �� ���� �ٽ� vecInt�� �ּҸ� �޾ƿ;���

	veciter = vecInt.begin(); // or veciter = vecInt.erase(veciter);
	int i = *veciter; // 200

	vecInt.clear();

	// 1 ~ 10 �� ���Ϳ� �Է�
	for (int i = 0; i < 11; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 1 ~ 5 ���� ����
	veciter = vecInt.begin();
	for (; veciter != vecInt.end();)
	{
		if (1 <= *veciter && *veciter <= 5)
		{
			// ����
			veciter = vecInt.erase(veciter); 
			// �Ź� veciter++ �� ȣ���ϸ� vector �� ��Ұ� �����ʰ� ���ÿ� ���� ���� �� �ڸ��� �Ѿ���� ������
			// ��ǻ� ������ ���� ���� ��Ҹ� �˻����� ����
		}
		else
		{
			++veciter; // �������� ���� ��� ++
		}
	} // ������ ����� ������ ������, ex) veciter++�� �ݺ������� �Ź� ȣ���� �� ������

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