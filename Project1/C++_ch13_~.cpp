#include <stdio.h>

int Add1(int a, int b)
{
	return a + b;
}

// 함수
int main2()
{
	int iData = Add1(100, 200);

	// 반복문
	/*for (반복자 초기화; 반복자 조건 체크; 반복자 변경)
	{

	} */

	for (int i = 0; i < 4; i++)
	{
		printf("Output Test\n");

		if (i % 2 == 1)
		{
			continue; // 뒤의 내용을 실행하지 않고, 다음 반복으로 넘어간다.
		}
	}
	
	/*while (조건 체크)
	 {

	 }*/

	int i = 0;
	while (i < 2)
	{
		printf("Output Test\n");

		++i;
	}

	int i2 = 0;

	// 콘솔 (입출력 할 수 있는 장치)
	// printf
	printf("abcdef %d  \n", 10); // 출력
	printf("abcdef %f  \n", 3.14f);

	for (int i = 0; i < 10; i++)
	{
		printf("Output i : %d\n", i);
	}

	// scanf

	int iInput = 0;
	scanf_s("%d", &iInput); // 입력 scanf_s("입력 받을 형식", &변수); scanf의 _s는 보안을 강화한 버전

	// 함수가 사용하는 메모리 영역
	// 스택 메모리 영역


	return 0;
}

// 단축키
// 지정한 구문 주석       :Ctrl + K, Ctrl + C
// 지정한 구문 주석 해제  :Ctrl + K, Ctrl + U
// Alt Drag

// 디버깅
// 디버깅 시작 : F5
// 다음 중단점 까지 실행 : F5
// 중단점 생성 및 해제 : F9
// 디버깅 중, 구문 수행 : F10
// 디버깅 중, 구문 수행(함수 진입) : F11
// 디버깅 중, 디버깅 종료 : Shift + F5