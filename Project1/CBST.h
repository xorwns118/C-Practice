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
	tBSTNode<T1, T2>*	m_pRoot; // 루트 노드 주소
	int					m_iCount; // 데이터 개수

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
		tBSTNode<T1, T2>*	m_pNode; // null 인 경우 end iterator

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
			// m_pNode nullptr 체크(end iterator 인지 아닌지)
			assert(m_pNode);

			return m_pNode->pair;
		}

		const tPair<T1, T2>* operator -> ()
		{
			// m_pNode nullptr 체크(end iterator 인지 아닌지)
			assert(m_pNode);

			return &m_pNode->pair; // 반환값이 포인터이기 때문에 주소에서 참조 받아와야함
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

	// 첫번째 데이터 라면
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
				// 같을 경우 중복 데이터가 생기기 때문에 예외처리 해야함. 
				// 중복 키가 있는지 확인해야함.
				// 중복이 허용되는 컨테이너는 multimap 이 따로 있음
				// => 같은 키값에 여러 데이터들을 또 연결짓는 방식 (이진 탐색 트리의 효율이 의미가 사라짐)
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

	// 데이터 개수 증가
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode) // 중위 후속자
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	// 1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서, 왼쪽 자식이 없을 때 까지 왼쪽으로 내려감
	if (_pNode->arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	
	// 2. 부모로부터 왼쪽 자식일 때 까지 위로 올라감
	//	  그 때 부모가 후속자
	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			// 더이상 위쪽으로 갈 수 없다. ==> 마지막 노드
			if (pSuccessor->IsRoot())
			{
				return nullptr;
			}

			// 부모로부터 왼쪽 자식인지 체크
			if (pSuccessor->IsLeftChild())
			{
				// 그 때 부모가 후속자
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
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode) // 중위 선행자
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;

	// 선행자 만들어보기
	
	return pSuccessor;
}

// 반환타입이 inner class 인 경우 typename 명시해줘야함
// 헤더에 구현하는 경우 inline 생략 가능
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
			break; // 같은 값 찾음

		if (pNode->arrNode[(int)node_type] == nullptr)
		{
			// 못찾음 pNode = nullptr => end iterator
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
	assert(this == _iter.m_pBST); // _iter.m_pBST 는 private 선언되어있기 때문에 iterator 에서 CBST<T1, T2> 를 friend 선언 해주어야 접근 가능


	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline typename tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	// 삭제시킬 노드의 후속자 노드를 찾아둔다.
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. 자식이 하나도 없는 경우
	if (_pTargetNode->IsLeaf())
	{
		// 삭제할 노드가 루트 노드(자식이 없고, 루트 => BST 안에 데이터가 1개밖에 없다)
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			// 부모 노드로 접근, 삭제될 노드의 자식을 가리키는 포인터를 nullptr 로 만든다.
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		}

		delete _pTargetNode;

		--m_iCount;
	}
	// 2. 자식이 2개인 경우
	else if(_pTargetNode->IsFull())
	{
		// 삭제 될 자리에 중위 후속자 값을 복사시킨다.
		_pTargetNode->pair = pSuccessor->pair;

		// 중위 후속자 노드를 삭제한다.
		DeleteNode(pSuccessor);

		// 삭제할 노드가 중위 후속자가 된다.
		pSuccessor = _pTargetNode; // 이건 위에 재귀함수라 삭제해도 될거같음
	}
	// 3. 자식이 1개인 경우
	else
	{
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		// 삭제될 노드의 부모와, 삭제될 노드의 자식을 연결해준다.
		if (_pTargetNode == m_pRoot)
		{
			// 자식노드 (1개) 를 루트로 만든다.
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else
		{
			// 삭제될 노드의 부모와, 삭제될 노드의 자식을 연결해준다.
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
