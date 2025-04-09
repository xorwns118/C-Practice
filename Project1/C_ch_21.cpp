# include <stdio.h>

// 사용자 정의 자료형
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

// typedef => 타입을 재정의해줌
typedef int INT;

typedef struct _NewStruct /* => 구조체 이름 */
{
	int i;
   short s;
} StructName; /* => 재정의 할 이름 */
//구조체를 정의했을 때 ex struct _NewStruct { .. } 로 하면 선언할 떄 struct _NewStruct t; 로 해야하지만
//typedef struct _NewStruct { .. } StructName; 으로 하면 선언할 때 StructName t; 로 해도 된다.

int main4()
{
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6 };

	// 구조체
	MYST t = { 100, 3.14f };
	t.a = 10;
	t.f = 10.2312f;

	int iSize = sizeof(MYST);

	_tagMyST s;
	INT a;

	return 0;
}