#pragma once

#include <assert.h>

// ���� �κе� .h ���Ͽ� �ۼ��ؾ��� : T�� �����Ǿ��ִ� �κ��� ���� Ŭ������ �ƴ� �����̱� ������
// ������ ���� �� � �ڷ����� Ÿ���� ��û���� ������ �� .cpp ���Ͽ����� �� �ڷ����� ���� �Լ���
// �����Ǿ��ִ� ���°� �ƴϱ� ����
template<typename T>
class CArr
{
private:
	T*		m_pData; // x64(64��Ʈ) ���� 8����Ʈ
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

	// CArr�� �����ȴٰ� �ѵ� iterator�� �������� ����, 
	// ex) CArr �� ��, iterator �� å���̶�� ���� �� ���� ������ �ڵ����� å���� ��������� �ʴ� �Ͱ� ����
	// inner class �� �����ϰ� �ִ� class �� private ����� ���� ����
	class iterator 
	{
	private:
		// iterator �� ����ų �����͸� �����ϴ� �����迭 �ּ�
		CArr*   m_pArr; // CArr�� ���Ҵ��� �Ͼ �ּҰ� ����Ǿ��� �� iterator�� �� �ּҸ� �˾ƾ���
		// �����͵��� ���� �ּ�
		T*		m_pData; // vector �� ���ó�� �����Ϸ��� m_pData�� ��� �� CArr�� m_pData�� ������ �ٸ��� ���ϱ� ���� �˰� �־����
						 // CArr �� �ּҿ� �ٲ� ������ ���� �Ѵٸ� �ʿ����
		// ����Ű�� �������� �ε���
		int		m_iIdx;
		// iterator ��ȿ�� üũ
		bool	m_bValid;

	public:
		T& operator * ()
		{
			// iterator �� �˰� �ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ��� (���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator �� end iterator �� ���
			if (m_pArr->m_pData != m_pData || m_iIdx == -1 || !m_bValid)
			{
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		// ++����
		iterator& operator ++()
		{
			// 2. end iterator �� ���
			// 3. iterator �� �˰� �ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ��� (���� Ȯ������ �ּҰ� �޶��� ���)
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				assert(nullptr);
			}

			// iterator �� ������ �����͸� ����Ű�� �ִ� ���
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

		// ++����
		iterator operator ++(int) // �ƹ� �ǹ� ���� ���ڸ� ������� ���� �����ڶ�� �ν���
		{
			iterator copy_iter = *this; // ���纻
			// ���Կ����ڰ� ȣ�� �� ���� �ƴ� ���� �����ڰ� ȣ�� �Ǵ� ��

			++(*this); // ���� �ּ��� ���� ������Ŵ

			return copy_iter; // ������Ű�� ���� ���� ��ȯ
		}

		// -- ����
		iterator& operator --()
		{
			// iterator �� �˰� �ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ��� (���� Ȯ������ �ּҰ� �޶��� ���)
			if (m_pArr->m_pData != m_pData)
			{
				assert(nullptr);
			}

			// iterator �� ���� ���
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

		// -- ����
		iterator operator --(int)
		{
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;
		}

		// �� ������ ==, !=
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

		friend class CArr; // CArr Ŭ������ friend �� �����������ν� private ����� ���� ����
	};
};

// class ���� ���� ���̱� ������ ��Ȯ�� ������ �����ϱ� ���� :: (������ ������) �� �����
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
	delete[] m_pData; // ���ӵ� �κ��� �� ������ �ϱ� ������ [] �ٿ�����
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	int i = 0;

	// �� ������ �Ҵ��� ������ ����
	if (m_iMaxCount <= m_iCount)
	{
		// ���Ҵ�
		resize(m_iCount * 2);
	}

	// ������ �߰�
	m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮���� �� ���� ��ġ�� �����Ϸ��� ���
	if (_iResizeCount <= m_iMaxCount)
	{
		assert(nullptr);
	}

	// 1. 2�� �� ū ������ �����Ҵ��Ѵ�.
	T* pNew = new T[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ѵ�.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pData = pNew;

	// 5. MaxCount ������ ����
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
	// ������ ����Ű�� iterator �� ���� ��ȯ����
	if (m_iCount == 0)
		return iterator(this, m_pData, -1); // �����Ͱ� ���� ���, begin() == end()
	return iterator(this, m_pData, 0); // iter�� m_pData�� CArr�� m_pData�� �־���
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// ���� ������ ����Ű�� iterator �� ���� ��ȯ����
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// iterator �� �ٸ� Arr �� ��Ҹ� ����Ű�� ���
	// iterator �� end iterator �� ���
	if (_iter.m_pArr != this || _iter == end() || _iter.m_iIdx >= m_iCount)
	{
		assert(nullptr);
	}

	// iterator �� ����Ű�� ����Ʈ�� �迭 ������ �����Ѵ�.
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}

	// ī��Ʈ ����
	--m_iCount;

	_iter.m_bValid = false;

	return iterator(this, m_pData, _iter.m_iIdx);
}
