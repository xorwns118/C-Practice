#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드)

void Output(const int * pI)
{
	int i = *pI;
	//*pI = 100; 불가능
	//int* pInt = (int*)pI;
	//*pInt = 1000; // 이렇게 억지로 바꿀 수 있지만 정상적인 방법은 아님
}

int main7()
{
	// 1. const => 무조건적으로 값이 바뀌지 않는 것은 아니라 조심할 필요는 있음. (왠만해선 못바꾼다)
	const int i = 100;

	// const와 포인터
	int a = 0;
	int* pInt = &a;

	*pInt = 1;
	pInt = nullptr;

	// ============
	// const 포인터
	// ============
	int b = 0;
	const int* pConstInt = &a;

	// *pConstInt = 100; 대상의 값이 상수화되어 변경 x
	pConstInt = &b; // 대상 변경은 가능

	// ============
	// 포인터 const
	// ============
	int* const pIntConst = &a;

	*pIntConst = 400; // 대상의 값은 변경 가능
	// pIntConst = &b; 변수가 가리키는 대상이 상수화되어 변경 x

	// 초기화 시 가리킨 대상만 가리킴, 가리키는 원본을 수정 할 수 없음
	const int* const pConstIntConst = nullptr;

	// const가 붙는 대상을 기준으로 기억하면 편함


	int const* p = &a; // 이 경우는 const가 *을 대상으로 붙어있어 const 포인터와 같음

	{
		int a = 0;
		const int* pInt = &a; // 포인터로 원본의 값에 접근하는 것을 막은것, 원본 자체가 상수가 된것이 아님
		// *pInt = 100; 이건 안되지만
		a = 100; // 이렇게는 가능함

		int* p = &a;
		*p = 100;
	}

	//예시
	a = 100;
	Output(&a); // 파라미터를 받아올 때 원본의 값을 바꿀 의도가 없다는 것을 알리기 위해 const로 선언

	// void*
	// 1. 원본의 자료형을 정하지 않음.
	// 2. 어떠한 타입의 변수 주소든 다 저장 가능
	// 3. 역참조 불가능 ( 어떤 주소던 받지만 정해진 자료형이 없기 때문에 해석 불가능 )
	// 4. 주소 연산 불가능

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

		// *pVoid; 불가능
		// pVoid + 1; 불가능
	}
	{
		// 문자
		char c = 0;
		wchar_t wc = 49; // 메모리상 49 '1' 로 저장, ASCII Code 로 1을 뜻함. 'A' 는 65, 'a' 는 97 
		short s = 49;

		c = 1; // => \x1
		c = '1'; // => 49

		wc = 459;
		"4 59"; // space = 32 null = 0 으로 혼동하면 안됨. 빈칸은 32로 저장됨

		// char(1), wchar(2)

		c = 'a';
		wc = L'a'; // => L : 문자 하나당 2byte 단위라는 것을 명시

		char szCgar[10] = "abcdef"; // 배열은 끝을 나타내는 null (0) 이 들어갈 자리도 생각해야 함.
		wchar_t szWChar[10] = L"abcdef"; // wchar_t 2byte 단위의 문자형 자료형
		const wchar_t* pChar = L"abcdef"; // ROM에 저장되어있는 문자 자체를 변경할 수 없는 const 형태이기 때문에 const 선언
										  // 강제 캐스팅을 억지로 해서 const 없애고 컴파일러 오류 피할 수 있지만,
										  // 보안상 큰 문제가 되어 예외상황 throw.

		szWChar[1] = 'z';
		// pChar[1] = 'z'; => *(pChar + 1) = 'z'; ROM(데이터 초기화 영역) 에 저장되어있는 문자 자체 변경 불가능


		short arrShort[10] = { 97, 98, 99, 100, 101, 102 }; // short 2byte 단위의 정수형 자료형

		int a = 0;

		// multi byte 방식
		// 문자 하나하나 비트를 검사해가며 몇 byte 의 문자인지를 체크하는 번거로움이 있음.
		char szTest[10] = "abc한글"; // L을 붙이지 않았을 때는 모두 1byte로 표현한다라는 것은 엄밀히 말하면 틀림.
									 // 문자에 따라 가변길이로 대응 '한', '글' 각각 숫자가 상당히 큼.
									 // (윈도우에선 multi byte 로 표현하지만 표준으로 사용하진 않음. 표준 UTF-8 인코딩)
		// wide byte 방식 unicode
		wchar_t szTestW[10] = L"abc한글";
	}

	return 0;
}

// 단축키
// Ctrl + Shift + Spacebar