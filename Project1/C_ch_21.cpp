# include <stdio.h>

// ����� ���� �ڷ���
typedef struct _tagMyST
{
	int a;
	float f;
}MYST;

typedef struct _tagBig
{
	MYST k;
	int i;
	char c;
}BIG;

// typedef => Ÿ���� ����������
typedef int INT;

typedef struct _NewStruct /* => ����ü �̸� */
{
	int i;
   short s;
} StructName; /* => ������ �� �̸� */
//����ü�� �������� �� ex struct _NewStruct { .. } �� �ϸ� ������ �� struct _NewStruct t; �� �ؾ�������
//typedef struct _NewStruct { .. } StructName; ���� �ϸ� ������ �� StructName t; �� �ص� �ȴ�.

int main4()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6 };

	// ����ü
	MYST t = { 100, 3.14f };
	t.a = 10;
	t.f = 10.2312f;

	int iSize = sizeof(MYST);

	_tagMyST s;
	INT a;

	return 0;
}