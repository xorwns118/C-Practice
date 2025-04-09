
#define HUNGRY  0x001
#define THIRSTY 0x002
#define TIRED   0x004
#define FIRE    0x008

#define COLD    0x010
#define POISON  0x020
#define HOT1    0x040
#define HOT2	0x080
#define HOT3	0x100
#define HOT4	0x200
#define HOT5	0x300
#define HOT6	0x400

// 1. 가독성
// 2. 유지보수

// 전역변수
int global = 0;

// 함수
int main1()
{
	// 자료형 (크기 단위, byte) Data Type
	// 정수형 : char(1), short(2), int(4), long(4), long long(8)
	// 실수형 : float(4), double(8)
	int i = 0;

	// 1 바이트로 양수만 표현
	// 256가지 -> 0 ~ 255
	unsigned char c = 0;
	c = 0;
	// c = -1; -> c = 255;
	

	// 1 바이트로 양수, 음수 둘 다 표현
	// - 128 ~ 0 ~ 127
	signed char c1 = 0;
	// c1 = 255; -> c1 = -1;

	// 음의 정수 찾기 ( 2의 보수법 )
	// 대응되는 양수의 부호를 반전 후, 1을 더한다.

	int a = 4 + (int)4.0;

	// 정수 표현 방식과 실수 표현 방식은 다르다.
	// 실수 표현 방식은 정밀도에 의존한다.
	// 따라서 double(8) 자료형이 float(4) 보다 더 아래의 소수점까지 정확하게 표현이 가능하다.

	// 정수는 정수끼리, 실수는 실수끼리 연산하되, 두 표현 방식의 피 연산자가 연산 될 경우 명시적으로 변환하자.
	float f = 10.2415f + (float)20;

	// 실수를 상수로 적을 경우 소수점 뒤에 f 를 붙이면 flaot 자료형으로, 붙이지 않으면 double 자료형으로 간주한다.
	// 0.1f; 0.1;

	// 연산자
	// 대입	연산자 : =, +=, -=, *=, /=, %=
	// 산술 연산자 : +, -, *, /, %(모듈러스, 나머지)
	// ++, -- (증감 연산자)
	// 한 단계 증가 또는 감소
	int data = 10 + 10;
	// data = data + 20;
	data += 20;
	data = (int)(10.f / 3.f);

	data = 0;
	++data; // 전위(전치)
	data++; // 후위(후치)

	// 후위 연산자로 사용하는 경우, 연산자 우선순위가 가장 나중으로 밀린다.

	data = 0;

	a = 10;
	data = a++; // data = 10, a = 11
	data = ++a; // a = 12, data = 12

	data = 0;
	data--;
	data--;

	// 논리 연산자 : &&(and), ||(or), !(not)
	// 참(true), 거짓(false)
	// 참 : 0이 아닌 모든 값, 1 ( 10이어도 참, 24여도 참, 0만 아니면 참인데, 결과값으로 반환해서 참인 결과가 나오면 1만 반환 )
	// + 0이 아닌 어떤 숫자로 만들어도 1로 저장됨.
	// 거짓 : 0
	bool truefalse = false; 
	bool IsTrue = 100; // IsTrue = 1

	IsTrue = true;
	IsTrue = !IsTrue;

	int iTrue = 0;
	iTrue = !iTrue;

	iTrue = 100 && 200; // iTrue = 1
	iTrue = 0 && 200; // iTrue = 0
	iTrue = 100 || 200; // iTrue = 1
	iTrue = 0 || 200; // iTrue = 1
	iTrue = 0 || 0; // iTrue = 0

	// 비교 연산자
	// ==, !=, >, <, >=, <=
	// 참, 거짓


	// 구문
	// if, else
	data = 0;
	if (0 && 200) // false
	{
		data = 100;
	}

	if (data == 100)
	{
		// if 가 참인 경우 실행
	}
	else
	{
		// if 가 거짓인 경우 실행
	}

	// 중간에 하나라도 걸리면 그 구문만 실행 후 종료, else 생략 가능
	/*if ()
	{

	}
	else if ()
	{

	}
	else()
	{

	}*/

	// siwtch, case if, else if 와 거의 비슷함
	int iTest = 10;
	switch (iTest)
	{
		case 10:
			break;
		case 20:
			break;
		default:
			break;
	} 
	// break 를 만나면 switch 문을 빠져나옴, break 가 없으면 다음 case 문을 실행, 
	// default 는 모든 case 가 걸리지 않을 때 실행, break 안쓰는 구문 실수 잦음

	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}

	// 삼항 연산자
	// :? (조건식) ? 참일 때 값 : 거짓일 때 값

	iTest == 20 ? iTest = 100 : iTest = 200;

	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}

	// 비트 연산자
	// 쉬프트 <<, >>
	unsigned char byte = 1;

	byte <<= 3; // 2^n배수
	byte >>= 2; // 2^n 나눈 몫

	// 비트 곱(&), 합(|), xor(^), 반전(~)
	// 비트 단위로 연산을 진행,
	// & 둘다 1인 경우 1
	// | 둘 중 하나라도 1인 경우 1
	// ^ 같으면 0, 다르면 1
	// ~ 1은 0으로, 0은 1로

	unsigned int iStatus = 0;

	// 상태 추가
	iStatus |= HUNGRY;
	iStatus |= THIRSTY;

	// 상태 확인
	if (iStatus & THIRSTY)
	{

	}

	// 특정 자리 비트 제거
	iStatus &= ~THIRSTY;

	// 변수
	// 1. 지역변수
	// 2. 전역변수
	// 3. 정적변수
	// 4. 외부변수

	// 지역변수
	int iName = 0;

	// 괄호 안에 선언된 함수 (함수, 지역)
	{
		// 변수명 규칙
		int iName = 100;

		iName; // => 100
	}

	iName; // => 0

	return 0;
}