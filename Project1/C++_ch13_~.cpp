#include <stdio.h>

int Add1(int a, int b)
{
	return a + b;
}

// �Լ�
int main2()
{
	int iData = Add1(100, 200);

	// �ݺ���
	/*for (�ݺ��� �ʱ�ȭ; �ݺ��� ���� üũ; �ݺ��� ����)
	{

	} */

	for (int i = 0; i < 4; i++)
	{
		printf("Output Test\n");

		if (i % 2 == 1)
		{
			continue; // ���� ������ �������� �ʰ�, ���� �ݺ����� �Ѿ��.
		}
	}
	
	/*while (���� üũ)
	 {

	 }*/

	int i = 0;
	while (i < 2)
	{
		printf("Output Test\n");

		++i;
	}

	int i2 = 0;

	// �ܼ� (����� �� �� �ִ� ��ġ)
	// printf
	printf("abcdef %d  \n", 10); // ���
	printf("abcdef %f  \n", 3.14f);

	for (int i = 0; i < 10; i++)
	{
		printf("Output i : %d\n", i);
	}

	// scanf

	int iInput = 0;
	scanf_s("%d", &iInput); // �Է� scanf_s("�Է� ���� ����", &����); scanf�� _s�� ������ ��ȭ�� ����

	// �Լ��� ����ϴ� �޸� ����
	// ���� �޸� ����


	return 0;
}

// ����Ű
// ������ ���� �ּ�       :Ctrl + K, Ctrl + C
// ������ ���� �ּ� ����  :Ctrl + K, Ctrl + U
// Alt Drag

// �����
// ����� ���� : F5
// ���� �ߴ��� ���� ���� : F5
// �ߴ��� ���� �� ���� : F9
// ����� ��, ���� ���� : F10
// ����� ��, ���� ����(�Լ� ����) : F11
// ����� ��, ����� ���� : Shift + F5