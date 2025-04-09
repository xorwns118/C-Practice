#pragma once

#include <assert.h>

// 구현 부분도 .h 파일에 작성해야함 : T로 지정되어있는 부분은 실제 클래스가 아닌 원형이기 때문에
// 컴파일 했을 때 어떤 자료형의 타입이 요청으로 들어왔을 때 .cpp 파일에서는 그 자료형에 대한 함수가
// 구현되어있는 상태가 아니기 때문
template<typename T>
class CArr
{
private:
	T*		m_pData; // x64(64비트) 기준 8바이트
	int		m_iCount;
	int		m_iMaxCount;

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx);

	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

	void clear() { m_iCount = 0; }

public:
	CArr();
	~CArr();

	// CArr가 생성된다고 한들 iterator는 생성되지 않음, 
	// ex) CArr 가 집, iterator 가 책상이라고 했을 때 집을 지으면 자동으로 책상이 만들어지지 않는 것과 같음
	// inner class 를 포함하고 있는 class 의 private 멤버에 접근 가능
	class iterator 
	{
	private:
		// iterator 가 갈이킬 데이터를 관리하는 가변배열 주소
		CArr*   m_pArr; // CArr에 재할당이 일어나 주소가 변경되었을 때 iterator도 그 주소를 알아야함
		// 데이터들의 시작 주소
		T*		m_pData; // vector 의 방식처럼 구현하려면 m_pData를 기록 후 CArr의 m_pData와 같은지 다른지 비교하기 위해 알고 있어야함
						 // CArr 의 주소와 바뀌어도 문제가 없게 한다면 필요없음
		// 가리키는 데이터의 인덱스
		int		m_iIdx;
		// iterator 유효성 체크
		bool	m_bValid;

	public:
		T& operator * ()
		{
			// iterator 가 알고 있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우 (공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator 인 경우
			if (m_pArr->m_pData != m_pData || m_iIdx == -1 || !m_bValid)
			{
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		// ++전위
		iterator& operator ++()
		{
			// 2. end iterator 인 경우
			// 3. iterator 가 알고 있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우 (공간 확장으로 주소가 달라진 경우)
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				assert(nullptr);
			}

			// iterator 가 마지막 데이터를 가리키고 있는 경우
			if (m_pArr->size() -1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++후위
		iterator operator ++(int) // 아무 의미 없는 인자를 기반으로 후위 연산자라고 인식함
		{
			iterator copy_iter = *this; // 복사본
			// 대입연산자가 호출 된 것이 아닌 복사 생성자가 호출 되는 것

			++(*this); // 원본 주소의 값을 증가시킴

			return copy_iter; // 증가시키기 전의 값을 반환
		}

		// -- 전위
		iterator& operator --()
		{
			// iterator 가 알고 있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우 (공간 확장으로 주소가 달라진 경우)
			if (m_pArr->m_pData != m_pData)
			{
				assert(nullptr);
			}

			// iterator 가 없는 경우
			if (m_pArr->size() == 0)
			{
				m_iIdx = -1;
			}
			else
			{
				--m_iIdx;
			}

			return *this;
		}

		// -- 후위
		iterator operator --(int)
		{
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;
		}

		// 비교 연산자 ==, !=
		bool operator == (const iterator& _otheriter)
		{
			return m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{

		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)
		{
			if (_pArr != nullptr && _iIdx >= 0)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		friend class CArr; // CArr 클래스의 friend 로 지정해줌으로써 private 멤버에 접근 가능
	};
};

// class 선언 범위 밖이기 때문에 정확한 범위를 지정하기 위해 :: (스코프 연산자) 를 사용함
template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData; // 연속된 부분을 다 지워야 하기 때문에 [] 붙여야함
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	int i = 0;

	// 힙 영역에 할당한 공간이 꽉참
	if (m_iMaxCount <= m_iCount)
	{
		// 재할당
		resize(m_iCount * 2);
	}

	// 데이터 추가
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// 현재 최대 수용량보다 더 적은 수치로 설정하려는 경우
	if (_iResizeCount <= m_iMaxCount)
	{
		assert(nullptr);
	}

	// 1. 2배 더 큰 공간을 동적할당한다.
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사한다.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	m_pData = pNew;

	// 5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// 시작을 가리키는 iterator 를 만들어서 반환해줌
	if (m_iCount == 0)
		return iterator(this, m_pData, -1); // 데이터가 없는 경우, begin() == end()
	return iterator(this, m_pData, 0); // iter의 m_pData에 CArr의 m_pData를 넣어줌
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// 끝의 다음을 가리키는 iterator 를 만들어서 반환해줌
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// iterator 가 다른 Arr 쪽 요소를 가리키는 경우
	// iterator 가 end iterator 인 경우
	if (_iter.m_pArr != this || _iter == end() || _iter.m_iIdx >= m_iCount)
	{
		assert(nullptr);
	}

	// iterator 가 가리키는 데이트를 배열 내에서 제거한다.
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}

	// 카운트 감소
	--m_iCount;

	_iter.m_bValid = false;

	return iterator(this, m_pData, _iter.m_iIdx);
}
