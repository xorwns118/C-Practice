#include <iostream>

#include "Arr.h"

class CMy
{
	// 접근 제한 지정자
	// private, protected(상속), public
private:
	int m_i;
	float m_f;

public:
	void SetInt(int i)
	{
		this->m_i = i; // this 포인터, this 라는 키워드로 어차피 호출 될 자신의 멤버 변수를 지칭하여 사용자들의 불편함을 해소함.
					   // 밑의 C 언어 스타일에서 선언한 주소 인자는 생략 가능
	}

	// 대입 연산자
	CMy& operator = (const CMy& _Other)
	{
		m_i = _Other.m_i;
		m_f = _Other.m_f;

		return *this; // 반환 타입이 없으면 결과값은 아무것도 남지 않게 되기 때문에 에러남.
	}

	CMy& operator + (const CMy& _Other)
	{
		m_i += _Other.m_i;
		m_f += _Other.m_f;

		return *this;
	}

	/*void SetInt(CMy* _this, int i)
	{
		_this->m_i = i; => 이게 C언어 방식
	}*/

public:
	// 생성자, 객체가 만들어질 때 자동 호출
	// 이니셜라이저, 객체가 만들어짐과 동시에 멤버에 지정값으로 초기화해줌
	CMy() : m_i(100), m_f(0.f)
	{
		// m_i = 100; 이 부분은 진정한 의미의 초기화가 아님 
		//			  => 객체가 생성됨과 동시에 일어나는 일이 아닌 생성 이후 함수를 호출하는 두 단계에 걸친 작업이기 때문
	}

	// 소멸자, 함수 종료시 자동 호출
	~CMy()
	{

	}

	// 생성자, 소멸자를 만들지 않아도 C++ 문법 규칙 상 컴파일러가 자동으로 만들지만 아무 기능이 없음 
	// (default 생성자, default 소멸자)
};

int main12()
{
	// C++ 클래스 특징
	// 접근 제한 지정자
	// 클래스 내의 멤버 변수 or 멤버 함수의 접근 레벨
	
	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// CMy::SetInt(10); :: 스코프 연산자, 이렇게 해도 안되는 이유? 해당 클래스의 실제 객체가 있어야함. (변수로 객체 생성)
	// 멤버 함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달 된다.

	{
		// 레퍼런스
		// 자료형 * 변수명;	포인터 변수 선언
		// *포인터변수;		포인터 주소 역참조
		// &변수;			변수의 주소값
		// 자료형 & 변수명;	래퍼런스 변수 선언, C++ 로 넘어오면서 생김

		// C++ 에 추가된 기능
		// 포인터와 유사
		// 원본을 참조한다.
		// 참조 변수를 통해서 직접적으로 원본을 수정 할 수 있다.

		int a = 10;

		int* const p = &a;
		*p = 100;

		int& iRef = a;  // a의 주소만을 참조, 역참조 연산 없이 원본을 바로 바꿀 수 있는 장점이 생김
		iRef = 100;		// 문법적으로 주소 값을 알 수 없기 때문에 실수할 위험 요소가 줄어들음

		const int* const p2 = &a;
		// *p2 = 10;

		const int& iRefConst = a;
		// iRefConst = 10;
	}


	tArr arr = {};
	InitArr(&arr);
	PushBack(&arr, 10);

	arr.iCount = 100; // 실제 값과는 달라져 충돌이 일어남 => 접근 제한 지정자로 막아줄 수 있음

	ReleaseArr(&arr);

	CMy c;
	c.SetInt(10);

	CMy c2;
	c2.SetInt(100);

	CMy c3;
	c3.SetInt(1000);

	c3 = c2; // 대입 연산자를 직접 만들어 사용함으로써 = 라는 대입 연산자 함수를 호출한 것


	return 0; // 종료 후 CMy 객체가 모두 소멸자 함수를 호출하여 메모리 해제
}