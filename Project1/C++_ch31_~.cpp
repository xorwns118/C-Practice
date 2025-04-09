#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�)

void Output(const int * pI)
{
	int i = *pI;
	//*pI = 100; �Ұ���
	//int* pInt = (int*)pI;
	//*pInt = 1000; // �̷��� ������ �ٲ� �� ������ �������� ����� �ƴ�
}

int main7()
{
	// 1. const => ������������ ���� �ٲ��� �ʴ� ���� �ƴ϶� ������ �ʿ�� ����. (�ظ��ؼ� ���ٲ۴�)
	const int i = 100;

	// const�� ������
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// ============
	// const ������
	// ============
	int b = 0;
	const int* pConstInt = &a;

	// *pConstInt = 100; ����� ���� ���ȭ�Ǿ� ���� x
	pConstInt = &b; // ��� ������ ����

	// ============
	// ������ const
	// ============
	int* const pIntConst = &a;

	*pIntConst = 400; // ����� ���� ���� ����
	// pIntConst = &b; ������ ����Ű�� ����� ���ȭ�Ǿ� ���� x

	// �ʱ�ȭ �� ����Ų ��� ����Ŵ, ����Ű�� ������ ���� �� �� ����
	const int* const pConstIntConst = nullptr;

	// const�� �ٴ� ����� �������� ����ϸ� ����


	int const* p = &a; // �� ���� const�� *�� ������� �پ��־� const �����Ϳ� ����

	{
		int a = 0;
		const int* pInt = &a; // �����ͷ� ������ ���� �����ϴ� ���� ������, ���� ��ü�� ����� �Ȱ��� �ƴ�
		// *pInt = 100; �̰� �ȵ�����
		a = 100; // �̷��Դ� ������

		int* p = &a;
		*p = 100;
	}

	//����
	a = 100;
	Output(&a); // �Ķ���͸� �޾ƿ� �� ������ ���� �ٲ� �ǵ��� ���ٴ� ���� �˸��� ���� const�� ����

	// void*
	// 1. ������ �ڷ����� ������ ����.
	// 2. ��� Ÿ���� ���� �ּҵ� �� ���� ����
	// 3. ������ �Ұ��� ( � �ּҴ� ������ ������ �ڷ����� ���� ������ �ؼ� �Ұ��� )
	// 4. �ּ� ���� �Ұ���

	void* pVoid = nullptr;
	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;

		// *pVoid; �Ұ���
		// pVoid + 1; �Ұ���
	}
	{
		// ����
		char c = 0;
		wchar_t wc = 49; // �޸𸮻� 49 '1' �� ����, ASCII Code �� 1�� ����. 'A' �� 65, 'a' �� 97 
		short s = 49;

		c = 1; // => \x1
		c = '1'; // => 49

		wc = 459;
		"4 59"; // space = 32 null = 0 ���� ȥ���ϸ� �ȵ�. ��ĭ�� 32�� �����

		// char(1), wchar(2)

		c = 'a';
		wc = L'a'; // => L : ���� �ϳ��� 2byte ������� ���� ���

		char szCgar[10] = "abcdef"; // �迭�� ���� ��Ÿ���� null (0) �� �� �ڸ��� �����ؾ� ��.
		wchar_t szWChar[10] = L"abcdef"; // wchar_t 2byte ������ ������ �ڷ���
		const wchar_t* pChar = L"abcdef"; // ROM�� ����Ǿ��ִ� ���� ��ü�� ������ �� ���� const �����̱� ������ const ����
										  // ���� ĳ������ ������ �ؼ� const ���ְ� �����Ϸ� ���� ���� �� ������,
										  // ���Ȼ� ū ������ �Ǿ� ���ܻ�Ȳ throw.

		szWChar[1] = 'z';
		// pChar[1] = 'z'; => *(pChar + 1) = 'z'; ROM(������ �ʱ�ȭ ����) �� ����Ǿ��ִ� ���� ��ü ���� �Ұ���


		short arrShort[10] = { 97, 98, 99, 100, 101, 102 }; // short 2byte ������ ������ �ڷ���

		int a = 0;

		// multi byte ���
		// ���� �ϳ��ϳ� ��Ʈ�� �˻��ذ��� �� byte �� ���������� üũ�ϴ� ���ŷο��� ����.
		char szTest[10] = "abc�ѱ�"; // L�� ������ �ʾ��� ���� ��� 1byte�� ǥ���Ѵٶ�� ���� ������ ���ϸ� Ʋ��.
									 // ���ڿ� ���� �������̷� ���� '��', '��' ���� ���ڰ� ����� ŭ.
									 // (�����쿡�� multi byte �� ǥ�������� ǥ������ ������� ����. ǥ�� UTF-8 ���ڵ�)
		// wide byte ��� unicode
		wchar_t szTestW[10] = L"abc�ѱ�";
	}

	return 0;
}

// ����Ű
// Ctrl + Shift + Spacebar