/**
 * @file List.inl
 * @brief �e���v���[�g�o�������X�g�N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.15
 */
#pragma once


 //----- �C���N���[�h
#include "List.h"
#include <cassert>


//=============================================================================
// �R���X�g�C�e���[�^�̎���
//=============================================================================
//-----------------------------------------------------------------------------
template<class T>
List<T>::ConstIterator::ConstIterator(const List<T>* pList, List<T>::Node* pNode)
	: m_pList(pList)
	, m_pNode(pNode)
{
}
//-----------------------------------------------------------------------------
template<class T>
List<T>::ConstIterator::~ConstIterator()
{
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pBack);
	m_pNode = m_pNode->pBack;
	return *this;
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++(int)
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pBack);
	List<T>::ConstIterator itr = *this;
	m_pNode = m_pNode->pBack;
	return itr;
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::ConstIterator& List<T>::ConstIterator::operator--()
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pFront);
	m_pNode = m_pNode->pFront;
	return *this;
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--(int)
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pFront);
	List<T>::ConstIterator itr = *this;
	m_pNode = m_pNode->pFront;
	return itr;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::ConstIterator::operator==(const ConstIterator& itr) const
{
	return m_pNode == itr.m_pNode;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::ConstIterator::operator!=(const ConstIterator& itr) const
{
	return m_pNode != itr.m_pNode;
}
//-----------------------------------------------------------------------------
template<class T>
const T& List<T>::ConstIterator::operator*() const
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pBack);
	assert(m_pNode != m_pNode->pFront);
	return (*m_pNode).data;
}
//=============================================================================
// �C�e���[�^�̎���
//=============================================================================
//-----------------------------------------------------------------------------
template<class T>
List<T>::Iterator::Iterator(const List<T>* pList, List<T>::Node* pNode)
	: ConstIterator(pList, pNode)
{
}
//-----------------------------------------------------------------------------
template<class T>
List<T>::Iterator::~Iterator()
{
}
//-----------------------------------------------------------------------------
template<class T>
T& List<T>::Iterator::operator*()
{
	assert(this->m_pList);
	assert(this->m_pNode);
	assert(this->m_pNode != this->m_pNode->pBack);
	assert(this->m_pNode != this->m_pNode->pFront);
	return (*this->m_pNode).data;
}
//=============================================================================
// ���X�g�̎���
//=============================================================================
//-----------------------------------------------------------------------------
template<class T>
List<T>::List()
	: m_pDummyNode()
	, m_ElementCnt(0)
{
	m_pDummyNode = new Node;
	m_pDummyNode->pFront = m_pDummyNode;
	m_pDummyNode->pBack = m_pDummyNode;
}
//-----------------------------------------------------------------------------
template<class T>
List<T>::~List()
{
	Node* pNode = m_pDummyNode->pBack;
	Node* pDeleteNode = nullptr;
	// �擪����m�[�h�����ɍ폜���Ă���
	while (pNode != m_pDummyNode)
	{
		pDeleteNode = pNode;
		pNode = pNode->pBack;
		delete pDeleteNode;
	}
	delete m_pDummyNode;
}
//-----------------------------------------------------------------------------
template<class T>
int List<T>::GetCount() const
{
	return m_ElementCnt;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Insert(List<T>::ConstIterator& itr, const T& value)
{
	// �s���C�e���[�^(�ʃ��X�g�Q��)�ɂ��}�����s
	if (itr.m_pList != this) return false;
	// �s���C�e���[�^(�m�[�h���Q��)�ɂ��}�����s
	if (!itr.m_pNode) return false;

	// �V�K�m�[�h�̐����Ɛݒ�
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pBack = itr.m_pNode;
	newNode->pFront = itr.m_pNode->pFront;
	// �O��̃m�[�h�̐ڑ����C��
	itr.m_pNode->pFront = newNode;
	newNode->pFront->pBack = newNode;
	// ���X�g�v�f��+1
	++m_ElementCnt;

	return true; // �}������
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Erase(List<T>::ConstIterator& itr)
{
	// �s���C�e���[�^(�ʃ��X�g�Q��)�ɂ��폜���s
	if (itr.m_pList != this) return false;
	// �s���C�e���[�^(�m�[�h���Q��)�ɂ��폜���s
	if (!itr.m_pNode) return false;
	// �_�~�[�m�[�h�̏ꍇ���폜���s
	if (itr.m_pNode == m_pDummyNode) return false;

	// �O��̃m�[�h�̐ڑ����C��
	itr.m_pNode->pBack->pFront = itr.m_pNode->pFront;
	itr.m_pNode->pFront->pBack = itr.m_pNode->pBack;
	// �Y���m�[�h���폜
	delete itr.m_pNode;
	itr.m_pNode = nullptr;
	// ���X�g�v�f��-1
	--m_ElementCnt;

	return true; // �폜����
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::Iterator List<T>::begin()
{
	return Iterator(this, m_pDummyNode->pBack);
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::ConstIterator List<T>::begin() const
{
	return List<T>::ConstIterator(this, m_pDummyNode->pBack);
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::Iterator List<T>::end()
{
	return Iterator(this, m_pDummyNode);
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::ConstIterator List<T>::end() const
{
	return List<T>::ConstIterator(this, m_pDummyNode);
}
//-----------------------------------------------------------------------------
//=============================================================================
// �N�C�b�N�\�[�g�Q�lURL
// https://cod-aid.com/library-quick-sort ����{�I�ȃA���S���Y�����Q�l
// https://bi.biopapyrus.jp/cpp/algorithm/sort/quick-sort.html ��Partition�ӂ���Q�l
// https://ufcpp.net/study/algorithm/sort_quick.html �������l�ӂ���Q�l
//-----------------------------------------------------------------------------
template<class T>
void List<T>::QuickSort(CmpDataFunc cmpFunc)
{
	// �L�[���ݒ肳��Ă��Ȃ���Ή������Ȃ�
	if (!cmpFunc) return;
	// �v�f����A�܂���1�����Ȃ瑦���^�[�� 
	if (m_pDummyNode->pBack == m_pDummyNode->pFront) return;

	// �ċA�J�n
	QuickSort(cmpFunc, m_pDummyNode->data, m_pDummyNode->pBack, m_pDummyNode->pFront);
}
//-----------------------------------------------------------------------------
template<class T>
void List<T>::Swap(typename Node* pA, typename Node* pB)
{
	T temp = std::move(pA->data);
	pA->data = std::move(pB->data);
	pB->data = std::move(temp);
	// �ڑ���ς���p�^�[��������
}
//-----------------------------------------------------------------------------
template<class T>
const T& List<T>::Median(CmpDataFunc cmpFunc, const T& a, const T& b, const T& c) const
{
	// 3�̒l�̒����璆���̒l�����߂�
	bool ab = cmpFunc(a, b);
	bool bc = cmpFunc(b, c);
	bool ac = cmpFunc(a, c);
	if (ab && bc || !bc && !ab)
		return b;
	else if (!ab && ac || !ac && ab)
		return a;
	else
		return c;
}
//-----------------------------------------------------------------------------
template<class T>
typename List<T>::Node List<T>::Partition(CmpDataFunc cmpFunc, const T& pivot, typename Node* L, typename Node* R)
{
	// ��l�����ɑ召�֕�������
	while (true)
	{
		// ��l�𒴂���m�[�h��T��
		while (cmpFunc(L->data, pivot)) L = L->pBack;
		while (cmpFunc(pivot, R->data)) R = R->pFront;

		// �������Ă���m�[�h������������I��
		if (L == R || L->pFront == R) break;

		// �l����
		Swap(L, R);
		
		// ���̗v�f���瑖�����n�߂�
		L = L->pBack;
		R = R->pFront;
	}

	// ���̐����Ԃ�ԋp
	Node M;
	M.pFront = L->pFront;
	M.pBack = R->pBack;
	return M;
}
//-----------------------------------------------------------------------------
template<class T>
void List<T>::QuickSort(CmpDataFunc cmpFunc, const T& prePivot, typename Node* L, typename Node* R)
{
	// ����ɗp�����l�𐮗��Ԃ̐擪�A�����A��������̌��̒l����I��
	const T& pivot = Median(cmpFunc, L->data, R->data, prePivot);
	
	// ��l�����ɐ����Ԃ̃��X�g�v�f��召�ɕ���
	Node M = Partition(cmpFunc, pivot, L, R);

	// �ċA�I�ɏ���
	if (!(L == M.pFront || L->pFront == M.pFront)) QuickSort(cmpFunc, pivot, L, M.pFront);
	if (!(R == M.pBack || R->pBack == M.pBack)) QuickSort(cmpFunc, pivot, M.pBack, R);
}