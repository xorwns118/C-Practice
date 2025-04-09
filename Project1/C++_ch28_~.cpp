#include <stdlib.h>
#include <stdio.h>

// x86 => 32bit => 한번에 처리할 수 있는 단위 4Byte
// x64 => 64bit => 한번에 처리할 수 있는 단위 8Byte

void Test(int* a)
{
	*a = 500;
}

int main6()
{
	// 포인터 변수
	// 자료형 변수명

	int* pInt = nullptr;

	// 주소를 저장

	char* pChar = nullptr; // 1byte 정수형 타입으로 보겠다.
	short* pShort = nullptr; // 2byte 정수형 타입으로 보겠다.

	// 주소를 가리키는 포인터 변수의 크기는 운영체제에 따라 다르다.
	// Byte 기준이기 때문에 포인터 변수의 크기는 x86 => 4byte, x64 => 8byte
	int iSize = sizeof(pInt); // => 현재 x64로 설정되어있어 8이 나옴

	int i = 0;
	pInt = &i; // pInt 주소가 100이라고 했을 때 다음 주소는 104, int 라는 자료형 사이즈 기준이기 때문
	pInt += 1; // 포인터의 정수 연산은 다름. 
			   // 다음 주소를 가리키는 것이기 때문에 1을 더하면 int형의 byte를 증가시킨다는 뜻으로 4가 증가함.
			   // 다른 자료형 ex) char 일 경우 1을 더하면 2가 증가.
	// pInt 는 int* 변수이기 때문에, 가리키는 곳을 int 로 해석
	// 따라서 주소값을 1 증가하는 의미는 다음 int 위치로 접근하기 위해서 sizeof(int) 단위로 증가하게 된다.

	// 포인터와 배열
	// 배열의 특징
	// 1. 메모리가 연속적인 구조다.
	// 2. 배열의 이름은 배열의 시작 주소이다.

	int iArr[10] = {};

	// int 단위로 접근
	*(iArr + 0) = 10; // iArr[0] = 10;
	*(iArr + 1) = 10; // iArr[1] = 10;

	// 포인터 이해 확인 문제
	// 문제 1.
	short sArr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 2byte 기준의 배열 한 인덱스 당 2byte의 크기를 가짐

	int* pI = (int*)sArr; // sArr 의 주소값을 int 자료형 관점으로 해석 및 저장, pl = sArr 의 주소값 = sArr 의 시작 주소값

	int iData = *((short*)(pI + 2)); // pl는 int 기준으로 해석 된 주소값으로 2를 더하게 되면 총 8이 증가,
									 // iData 는 8번째 인덱스를 가리킴 => short 형으로 보게 되면 한칸에 2개씩으로 총 4칸 뒤로 움직임.

	printf("1번 문제 정답 : %d\n", iData); // iData = 5;

	// 문제 2.
	char cArr[2] = { 1, 1 }; // 1byte 기준의 배열

	short* pS = (short*)cArr; // cArr 의 주소값을 short (2byte) 자료형 관점으로 해석 및 저장, pS = cArr 의 주소값 = cArr 의 시작 주소값

	iData = *pS; // iData 는 pS 의 시작 주소값을 가리킴 (문제 1처럼 동일한 형태의 자료로 형변환이 일어나지 않았기 때문에
				 // 현재 가리키고 있는 포인터의 자료형인 short 기준에서 봤을 때 2byte 를 기준으로 보게됨,
				 // => 1byte 에 각각 00000001, 00000001 로 표현 되지만 short 관점에선 0000000100000001로 인식하게 되어 257으로 계산
				 // 0000000011111111 => 256 ( 8bit로 표현 가능한 최대 숫자 = 256 )

	printf("2번 문제 정답 : %d\n", iData); // iData = 257

	int a = 100;

	Test(&a);

	printf("출력 : %d\n", a);

	// scanf_s("%d", &a);

	// const
	volatile const int cint = 100; // 포인터로 강제 접근해서 바꿀 수 도 있다는 예시, 
								   // 현재는 최적화로 인해 레지스터에서 기억한 상태에서 이 변수에는 미리 정해둔 값을 넣는 방식임.
								   // const 로 지정했기 때문에 다른 곳에서 강제로 바꾼다 한들 문법이 틀린 상황이라 의미 없음
								   
	// volatile : 휘발성이란 뜻으로, 레지스터 사용하지 말고 무조건 확인하는 동작, 

	// 상수화
	// r-value : 상수
	// l-value : 변수
	int ii = 10;

	pInt = (int*)&cint;
	*pInt = 300;
	printf("cint 출력 : %d\n", cint);

	return 0;
}