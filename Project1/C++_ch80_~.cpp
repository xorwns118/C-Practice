#include <iostream>

#include <map>
#include <set>

#include <string>

using std::cout;
using std::endl;

class CParent
{
protected :
	int		m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	// 가상함수
	virtual void Output()
	{
		cout << "Parent" << endl;
	}

	void NewFunc()
	{
		cout << "New Func Parent" << endl;
	}

public:
	CParent()
		: m_i(0)
	{
		cout << "부모 생성자" << endl;
	}

	CParent(int _a)
		: m_i(_a)
	{
		cout << "부모 생성자" << endl;
	}
	~CParent()
	{
		cout << "부모 소멸자" << endl;
	}
};

// parent를 상속받고 있으나 private 멤버에 접근 불가능
// => protected 를 사용함으로써 상속받는 클래스에서만 사용 가능
class CChild : public CParent 
{
private:
	float	m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
	}

	// 상속받은 부모클래스의 함수를 재정의(오버라이딩) 함 
	virtual void Output()
	{
		cout << "Child" << endl;
	}

	void NewFunc()
	{
		cout << "New Func Child" << endl;
	}

public:
	CChild()
		//: CParent() // 부모의 기본생성자 생략가능
		//: 인자를 받는 오버로딩 사용시 CParent(100) 명시해주어야함 생략 시 기본 생성자 호출
		: m_f(0.f) 
		// , m_i(0)은 초기화 시엔 각각의 클래스에서 호출되어야 하기 때문에
		// 생성자를 초기화 할 때 부모의 멤버를 초기화 하는것은 불가능
	{
		m_i = 0; // 이 부분은 초기화와 상관 없이 상속 클래스에 공개된 멤버이기 때문에 가능
		cout << "자식 생성자" << endl;
	}
	~CChild()
	{
		// 자식 클래스 소멸자에서 실행 할 것을 모두 실행 후 부모 클래스 소멸자를 호출
		cout << "자식 소멸자" << endl;

		// 제일 마지막에 부모 클래스의 소멸자를 호출하는 함수가 생략되어있음
	}
};

int main17()
{
	// 객체지향 언어 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	CParent parent;
	parent.Output();

	CChild child; // parent를 상속받고 있기 때문에 메모리엔 parent, child 순으로(상속받는 순서) 연속적으로 메모리 스택에 쌓임.
	// Child 를 초기화 했을 때 초기화 하는 주체부터 살행된 후 부모 클래스가 호출된다.
	// => 호출 순서는 Child -> Parent, 실행 순서는 Parent -> Child (단어 혼동하지 말자) => 초기화는 부모부터 초기화 되나 호출은 자식부터 호출된다.
	child.Output(); 
	// Child 클래스의 Output()과 상속받는 Parent 클래스의 Output()이 같기 때문에 자식 클래스에서 재정의 한 함수를 불러옴 : 오버라이딩

	child.CParent::Output(); // 이렇게 만들면 부모 함수 호출 가능하나 이렇게 할거면 오버라이딩 애초에 안했음

	parent.SetInt(10);
	child.SetInt(10);

	// 상속
	// 자식 or 부모 클래스는 상속 관계에서 다른 클래스의 멤버를 초기화 할 수 없다.
	// 생성자 호출 순서 : 자식 -> 부모
	// 생성자 실행 순서, 초기화 순서 : 부모 -> 자식

	// 소멸자 실행 및 호출 순서 : 자식 -> 부모

	// 오버 라이딩 (면접 때 오버로딩과의 차이를 묻는 질문이 자주 나옴)
	// 부모 클래스의 멤버 함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현 된 기능이 호출되도록 한다.

	// 상속 And 포인터

	CParent* pParent = &parent; // 가능 
	//CChild* pChild = &child; // 가능 
	//CParent* pParent = &child; // 가능 => 스택 메모리엔 부모 클래스부터 연속적으로 쌓이기 때문에 Parent 포인터를 Child 클래스의 주소로 받아와도 문제없음
	//CChild* pChild = &parent; // 불가능 => 위와 동일한 순서로, child 포인터가 parent 주소를 가리키기 때문에 문법 오류남

	pParent = nullptr;
	pParent = &parent;
	pParent->Output();
	pParent = &child;
	pParent->Output(); // child 를 가리켜도 본질인 parent 형태로 parent 를 가리키고 있기 때문에 parent 의 output을 호출함 => virtual 가상함수로 해결

	pParent = &parent;
	// † parent 에는 child 가 없기 때문에 이렇게 되면 문제가 생김
	((CChild*)pParent)->NewFunc(); 
	// C 스타일의 강제 캐스팅 형변환 => 위험할 수 있음.
	// pParent 가 parent 의 주소를 받고 있다면 문제가 발생함.

	CChild* pChild = dynamic_cast<CChild*>(pParent);
	if (pChild != nullptr)
	{
		pChild->NewFunc(); // 다이나믹 캐스트를 통해 부모 포인터에 있던 타입을 자식 포인터로 캐스팅해서 실제 child 포인터로 받음
		// 실패할 때를 대비할 수 있어 강제 캐스팅보다 안전함, 실패했을 땐 nullptr
		// 런타임 중 동적으로 할당
	} 

	// 다형성, 가상함수(virtual)
	// 부모 포인터 타입으로, 부모 클래스로부터 파생되는 자식클래스 객체들의 주소를 가리킬 수 없다.
	// 모든 객체를 부모 클래스 타입으로 인식하게 되기 때문에, 실제 객체가 무엇인지 알 수 없다.
	// virtual 키워드를 토앻서, 각 클래스는 자신만의 고유한 가상함수 테이블을 가지게 된다.
	// 각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞느 테이블을 가리키게 된다.

	// 다운 캐스팅
	// 부모 클래스에서 선언되지 않은, 오직 자식 쪽에서만 추가된 함수를 호출하고 싶을 때
	// 자식 포인터 타입으로 일시적으로 캐스팅해서 호출한다.
	// 문제가 발생할 수 있기 때문에 dynamic_cast 로 안전하게 확인해 볼 수 있다.
	// RTTI (Run Time Type Identification or Information) 런타임 중 타입의 정보를 알 수 있다.

	// 추상화
	// 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 토앻서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	// virtual, = 0 (1 개 이상의 순수 가상함수를 포함하면 추상 클래스가 된다.)

	return 0;
}