#pragma once

#include <assert.h>

// C++ 기준 Class 와 구조체는 거의 차이가 없음 = 사실상 같다
// 차이라면, 구조체는 아무것도 적지 않았을 때 default 범위지정자가 public 임.

template<typename T>
// 강사 기준 구조체를 사용할 땐 많은 기능 없이 단순히 데이터를 묶고 저장하는 경우에 구조체 키워드를 사용함. class 써도 무방함
struct tListNode
{
	T				data;
	tListNode<T>*   pNext; 
	tListNode<T>*   pPrev;
	// 템플릿을 사용한다는 선언 내부에 있기 때문에 <T> 안붙여도 무방함. 명확하게 하려면 쓰는게 좋음

	tListNode()
		: data()
		, pNext(nullptr)
		, pPrev(nullptr)
	{

	}
	tListNode(const T& _data, tListNode<T>* _pNext, tListNode<T>* _pPrev)
		: data(_data)
		, pNext(_pNext)
		, pPrev(_pPrev)
	{

	}
};

template<typename T>
class CList
{
private:
	// 이 부분엔 <T> 를 붙이지 않았을 때 tListNode 자체는 CList와는 다른 구조체이기 때문에 
	// <T>를 선언하지 않으면 tListNode가 어떤 템플릿 인수를 사용하는지 모름.
	tListNode<T>*   m_pHead; 
	tListNode<T>*   m_pTail;
	int				m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size() { return m_iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>*	  m_pList;
		tListNode<T>* m_pNode;
		bool		  m_bValid;

	public:
		T& operator * ()
		{
			return m_pNode->data;
		}

		bool operator == (const iterator& _otheriter)
		{
			return _otheriter.m_pNode == m_pNode && _otheriter.m_pList == m_pList;
		}

		bool operator != (const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator& operator ++ ()
		{
			// end 에서 ++ 한 경우
			if (m_pNode == nullptr || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator& operator ++ (int)
		{
			iterator copyiter(*this);

			++(*this);
			
			return copyiter;
		}

		iterator& operator -- ()
		{
			// begin 에서 -- 한 경우
			if (m_pNode == nullptr || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev;

			return *this;
		}

		iterator& operator -- (int)
		{
			iterator copyiter(*this);

			--(*this);

			return copyiter;
		}

	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{

		}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (_pList != nullptr && _pNode != nullptr)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		friend class CList;
	};
};

template<typename T>
inline void CList<T>::push_back(const T& _data)
{
	//tListNode<T>* pNewNode = new tListNode<T>; // 기본 생성자로 생성
	//pNewNode->pData = _data;
	//pNewNode->pNext = nullptr;
	//pNewNode->pPrev = nullptr; 이 내용들을 인수를 받는 생성자를 오버로딩하여 아래로 함축 가능

	// 입력된 데이터를 저장할 노드를 동적할당 함
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	// 처음 입력된 데이터라면
	if (m_pHead == nullptr)
	{
		m_pHead = pNewNode;
	}
	else 
	{
		// 데이터가 1개 이상에서 입력된 경우
		// 현재 가장 마지막 데이터 (tail) 를 저장하고 있는 노드가
		// 새로 생성된 노드가 서로 가리키게 한다.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
	}
	// List 가 마지막 노드의 주소값을 새로 입력된 노드로 갱신한다.
	m_pTail = pNewNode;

	// 데이터 개수 증가
	m_iCount++;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// 새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	if (m_pHead == nullptr)
	{
		m_pTail = pNewNode;
	}
	else
	{
		// 현재 헤드노드의 이전노드 주소값을 새로 생성된 노드의 주소로 채움 
		m_pHead->pPrev = pNewNode;
		pNewNode->pNext = m_pHead;
	}

	// 리스트가 새로 생성된 노드의 주소를 새로운 헤드노드로 갱신
	m_pHead = pNewNode;

	// 데이터 개수 증가
	m_iCount++;
}

template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;

	while (pDeleteNode)
	{
		tListNode<T>* pNext = pDeleteNode->pNext;
		delete pDeleteNode;
		pDeleteNode = pNext;
	}
}

//inline 함수 내부에 코드를 복붙하여 함수의 비용을 줄이겠다. => 코드가 짧을 땐 inline 이 합리적, 코드가 길면 길수록 비효율적
template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	if (_iter == end())
	{
		assert(nullptr);
	}

	// 노드를 삭제하고 이전 노드와 다음 노드의 주소 연결
	if (_iter.m_pNode->pPrev == nullptr)
	{
		_iter.m_pNode->pNext->pPrev = nullptr;
		m_pHead = _iter.m_pNode->pNext;
	}
	else if (_iter.m_pNode->pNext == nullptr)
	{
		_iter.m_pNode->pPrev->pNext = nullptr;
		m_pTail = _iter.m_pNode->pPrev;
	}
	else
	{
		_iter.m_pNode->pPrev->pNext = _iter.m_pNode->pNext;
		_iter.m_pNode->pNext->pPrev = _iter.m_pNode->pPrev;
	}

	// 카운트 감소
	--m_iCount;

	return iterator(this, _iter.m_pNode->pNextNode);
}

template<typename T>
inline typename CList<T>::iterator CList<T>::insert(iterator& _iter, const T& _data)
{
	if (_iter == end())
	{
		assert(nullptr);
	}

	// 리스트에 추가되는 데이터를 저장 할 Node 생성
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator 가 가리키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator 가 가리키고 있는 노드의 이전으로 가서
		// 다음 노드 주소 파트를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator 가 가리키는 노드의 이전 노드를 새로운 노드로 지정
		// 새로운 노드의 pNext 를 iterator 가 가리키는 노드로 지정
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this, pNode);
}