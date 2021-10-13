/**
 * @file List.h
 * @breif テンプレートイテレータクラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.11
 */
#pragma once


//----- インクルード
#include "Iterator.h"
#include <cassert>


//=============================================================================
// コンストイテレータの実装
//=============================================================================
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T>::ConstIterator(const List<T>* pList, typename List<T>::Node* pNode)
	: m_pList(pList)
	, m_pNode(pNode)
{
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T>::~ConstIterator()
{
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T>& ConstIterator<T>::operator++()
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pBack);
	m_pNode = m_pNode->pBack;
	return *this;
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T> ConstIterator<T>::operator++(int)
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pBack);
	ConstIterator<T> itr = *this;
	m_pNode = m_pNode->pBack;
	return itr;
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T>& ConstIterator<T>::operator--()
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pFront);
	m_pNode = m_pNode->pFront;
	return *this;
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T> ConstIterator<T>::operator--(int)
{
	assert(m_pList);
	assert(m_pNode);
	assert(m_pNode != m_pNode->pFront);
	ConstIterator<T> itr = *this;
	m_pNode = m_pNode->pFront;
	return itr;
}
//-----------------------------------------------------------------------------
template<class T>
bool ConstIterator<T>::operator==(const ConstIterator<T>& itr) const
{
	return m_pNode == itr.m_pNode;
}
//-----------------------------------------------------------------------------
template<class T>
bool ConstIterator<T>::operator!=(const ConstIterator<T>& itr) const
{
	return m_pNode != itr.m_pNode;
}
//-----------------------------------------------------------------------------
template<class T>
const T& ConstIterator<T>::operator*()
{
	assert(m_pList);
	assert(m_pNode);
	assert(this->m_pNode != this->m_pNode->pBack);
	assert(this->m_pNode != this->m_pNode->pFront);
	return (*m_pNode).data;
}
//=============================================================================
// イテレータの実装
//=============================================================================
//-----------------------------------------------------------------------------
template<class T>
Iterator<T>::Iterator(List<T>* pList, typename List<T>::Node* pNode)
	: ConstIterator<T>(pList, pNode)
{
}
//-----------------------------------------------------------------------------
template<class T>
Iterator<T>::~Iterator()
{
}
//-----------------------------------------------------------------------------
template<class T>
inline T & Iterator<T>::operator*()
{
	assert(this->m_pList);
	assert(this->m_pNode);
	assert(this->m_pNode != this->m_pNode->pBack);
	assert(this->m_pNode != this->m_pNode->pFront);
	return (*this->m_pNode).data;
}