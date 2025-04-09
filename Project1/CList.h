#pragma once

#include <assert.h>

// C++ ���� Class �� ����ü�� ���� ���̰� ���� = ��ǻ� ����
// ���̶��, ����ü�� �ƹ��͵� ���� �ʾ��� �� default ���������ڰ� public ��.

template<typename T>
// ���� ���� ����ü�� ����� �� ���� ��� ���� �ܼ��� �����͸� ���� �����ϴ� ��쿡 ����ü Ű���带 �����. class �ᵵ ������
struct tListNode
{
	T				data;
	tListNode<T>*   pNext; 
	tListNode<T>*   pPrev;
	// ���ø��� ����Ѵٴ� ���� ���ο� �ֱ� ������ <T> �Ⱥٿ��� ������. ��Ȯ�ϰ� �Ϸ��� ���°� ����

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
	// �� �κп� <T> �� ������ �ʾ��� �� tListNode ��ü�� CList�ʹ� �ٸ� ����ü�̱� ������ 
	// <T>�� �������� ������ tListNode�� � ���ø� �μ��� ����ϴ��� ��.
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
			// end ���� ++ �� ���
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
			// begin ���� -- �� ���
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
	//tListNode<T>* pNewNode = new tListNode<T>; // �⺻ �����ڷ� ����
	//pNewNode->pData = _data;
	//pNewNode->pNext = nullptr;
	//pNewNode->pPrev = nullptr; �� ������� �μ��� �޴� �����ڸ� �����ε��Ͽ� �Ʒ��� ���� ����

	// �Էµ� �����͸� ������ ��带 �����Ҵ� ��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	// ó�� �Էµ� �����Ͷ��
	if (m_pHead == nullptr)
	{
		m_pHead = pNewNode;
	}
	else 
	{
		// �����Ͱ� 1�� �̻󿡼� �Էµ� ���
		// ���� ���� ������ ������ (tail) �� �����ϰ� �ִ� ��尡
		// ���� ������ ��尡 ���� ����Ű�� �Ѵ�.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
	}
	// List �� ������ ����� �ּҰ��� ���� �Էµ� ���� �����Ѵ�.
	m_pTail = pNewNode;

	// ������ ���� ����
	m_iCount++;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// ���� ������ ����� ������ ���� ������� �ּҰ����� ä��
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);

	if (m_pHead == nullptr)
	{
		m_pTail = pNewNode;
	}
	else
	{
		// ���� ������� ������� �ּҰ��� ���� ������ ����� �ּҷ� ä�� 
		m_pHead->pPrev = pNewNode;
		pNewNode->pNext = m_pHead;
	}

	// ����Ʈ�� ���� ������ ����� �ּҸ� ���ο� ������ ����
	m_pHead = pNewNode;

	// ������ ���� ����
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

//inline �Լ� ���ο� �ڵ带 �����Ͽ� �Լ��� ����� ���̰ڴ�. => �ڵ尡 ª�� �� inline �� �ո���, �ڵ尡 ��� ����� ��ȿ����
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

	// ��带 �����ϰ� ���� ���� ���� ����� �ּ� ����
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

	// ī��Ʈ ����
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

	// ����Ʈ�� �߰��Ǵ� �����͸� ���� �� Node ����
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator �� ����Ű�� ��尡 ������� ���
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator �� ����Ű�� �ִ� ����� �������� ����
		// ���� ��� �ּ� ��Ʈ�� ���� ������ ���� ����
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator �� ����Ű�� ����� ���� ��带 ���ο� ���� ����
		// ���ο� ����� pNext �� iterator �� ����Ű�� ���� ����
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	++m_iCount;

	return iterator(this, pNode);
}