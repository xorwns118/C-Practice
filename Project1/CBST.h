#pragma once

#include <assert.h>

enum class NODE_TYPE
{
	PARENT, // 0
	LCHILD, // 1
	RCHILD, // 2
	END,	// 3
};

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{ _first, _second };
}

template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2>		pair;
	tBSTNode<T1, T2>*	arrNode[(int)NODE_TYPE::END];

	bool IsRoot()
	{
		return arrNode[(int)NODE_TYPE::PARENT] == nullptr;
	}

	bool IsLeftChild()
	{
		return arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this;
	}

	bool IsRightChild()
	{
		return arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this;
	}

	bool IsLeaf()
	{
		return arrNode[(int)NODE_TYPE::LCHILD] == nullptr && arrNode[(int)NODE_TYPE::RCHILD] == nullptr;
	}

	bool IsFull()
	{
		return arrNode[(int)NODE_TYPE::LCHILD] != nullptr && arrNode[(int)NODE_TYPE::RCHILD] != nullptr;
	}

	tBSTNode()
		: pair()
		, arrNode{}
	{}

	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode<T1, T2>* _pParent, tBSTNode<T1, T2>* _pLChild, tBSTNode<T1, T2>* _pRChild)
		: pair(_pair)
		, arrNode{ _pParent, _pLChild, _pRChild }
	{}
};


// T1 : Key T2 : Value
template<typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>*	m_pRoot; // ��Ʈ ��� �ּ�
	int					m_iCount; // ������ ����

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode);


	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);

private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}

	class iterator
	{
	private:
		CBST<T1, T2>*		m_pBST;
		tBSTNode<T1, T2>*	m_pNode; // null �� ��� end iterator

	public:
		bool operator == (const iterator& _other)
		{
			return m_pBST == _other.m_pBST && m_pNode == _other.m_pNode;
		}

		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}

		const tPair<T1, T2>& operator * ()
		{
			// m_pNode nullptr üũ(end iterator ���� �ƴ���)
			assert(m_pNode);

			return m_pNode->pair;
		}

		const tPair<T1, T2>* operator -> ()
		{
			// m_pNode nullptr üũ(end iterator ���� �ƴ���)
			assert(m_pNode);

			return &m_pNode->pair; // ��ȯ���� �������̱� ������ �ּҿ��� ���� �޾ƿ;���
		}

		iterator& operator ++ ()
		{
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}

	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{}

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{}

		friend class CBST<T1, T2>;
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	// ù��° ������ ���
	if (m_pRoot == nullptr)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
			{
				node_type = NODE_TYPE::RCHILD;
			}
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				node_type = NODE_TYPE::LCHILD;
			}
			else
			{
				// ���� ��� �ߺ� �����Ͱ� ����� ������ ����ó�� �ؾ���. 
				// �ߺ� Ű�� �ִ��� Ȯ���ؾ���.
				// �ߺ��� ���Ǵ� �����̳ʴ� multimap �� ���� ����
				// => ���� Ű���� ���� �����͵��� �� �������� ��� (���� Ž�� Ʈ���� ȿ���� �ǹ̰� �����)
				return false;
			}
				
			if (pNode->arrNode[(int)node_type] == nullptr)
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	// ������ ���� ����
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode) // ���� �ļ���
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ����, ���� �ڽ��� ���� �� ���� �������� ������
	if (_pNode->arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	
	// 2. �θ�κ��� ���� �ڽ��� �� ���� ���� �ö�
	//	  �� �� �θ� �ļ���
	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			// ���̻� �������� �� �� ����. ==> ������ ���
			if (pSuccessor->IsRoot())
			{
				return nullptr;
			}

			// �θ�κ��� ���� �ڽ����� üũ
			if (pSuccessor->IsLeftChild())
			{
				// �� �� �θ� �ļ���
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
		}
	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode) // ���� ������
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	// ������ ������
	
	return pSuccessor;
}

// ��ȯŸ���� inner class �� ��� typename ����������
// ����� �����ϴ� ��� inline ���� ����
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
			break; // ���� �� ã��

		if (pNode->arrNode[(int)node_type] == nullptr)
		{
			// ��ã�� pNode = nullptr => end iterator
			pNode = nullptr;
			break;
		}
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{
	assert(this == _iter.m_pBST); // _iter.m_pBST �� private ����Ǿ��ֱ� ������ iterator ���� CBST<T1, T2> �� friend ���� ���־�� ���� ����


	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline typename tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	// ������ų ����� �ļ��� ��带 ã�Ƶд�.
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. �ڽ��� �ϳ��� ���� ���
	if (_pTargetNode->IsLeaf())
	{
		// ������ ��尡 ��Ʈ ���(�ڽ��� ����, ��Ʈ => BST �ȿ� �����Ͱ� 1���ۿ� ����)
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			// �θ� ���� ����, ������ ����� �ڽ��� ����Ű�� �����͸� nullptr �� �����.
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		}

		delete _pTargetNode;

		--m_iCount;
	}
	// 2. �ڽ��� 2���� ���
	else if(_pTargetNode->IsFull())
	{
		// ���� �� �ڸ��� ���� �ļ��� ���� �����Ų��.
		_pTargetNode->pair = pSuccessor->pair;

		// ���� �ļ��� ��带 �����Ѵ�.
		DeleteNode(pSuccessor);

		// ������ ��尡 ���� �ļ��ڰ� �ȴ�.
		pSuccessor = _pTargetNode; // �̰� ���� ����Լ��� �����ص� �ɰŰ���
	}
	// 3. �ڽ��� 1���� ���
	else
	{
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		// ������ ����� �θ��, ������ ����� �ڽ��� �������ش�.
		if (_pTargetNode == m_pRoot)
		{
			// �ڽĳ�� (1��) �� ��Ʈ�� �����.
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else
		{
			// ������ ����� �θ��, ������ ����� �ڽ��� �������ش�.
			if (_pTargetNode->IsLeftChild())
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}
			else
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}

			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}

		delete _pTargetNode;

		--m_iCount;
	}

	return pSuccessor;
}
