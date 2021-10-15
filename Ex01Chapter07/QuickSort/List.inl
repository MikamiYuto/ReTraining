/**
 * @file List.inl
 * @brief �e���v���[�g�o�������X�g�N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.11
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
List<T>::ConstIterator::ConstIterator(typename const List<T>* pList, typename List<T>::Node* pNode)
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
	typename List<T>::ConstIterator itr = *this;
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
	typename List<T>::ConstIterator itr = *this;
	m_pNode = m_pNode->pFront;
	return itr;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::ConstIterator::operator==(typename const ConstIterator& itr) const
{
	return m_pNode == itr.m_pNode;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::ConstIterator::operator!=(typename const ConstIterator& itr) const
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
List<T>::Iterator::Iterator(typename const List<T>* pList, typename List<T>::Node* pNode)
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
bool List<T>::Insert(typename List<T>::ConstIterator& itr, const T& value)
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
bool List<T>::Erase(typename List<T>::ConstIterator& itr)
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
template<class T>
void List<T>::QuickSort(bool isAsk, const T* pKey)
{
}