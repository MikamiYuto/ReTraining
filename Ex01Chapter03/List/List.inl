/**
 * @file List.inl
 * @breif テンプレート双方向リストクラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.11
 */
#pragma once


//----- インクルード
#include "List.h"
#include "Iterator.h"


//-----------------------------------------------------------------------------
template<class T>
List<T>::List()
	: m_pDummyNode(nullptr)
	, m_NodeCnt(0)
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
	// 先頭からノードを順に削除していく
	while (pNode != m_pDummyNode)
	{
		pDeleteNode = pNode;
		pNode = pNode->pBack;
		delete pDeleteNode;
	}
	delete m_pDummyNode;// 最後
	m_pDummyNode = nullptr;
}
//-----------------------------------------------------------------------------
template<class T>
int List<T>::GetCount() const
{
	return m_NodeCnt;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Insert(Iterator<T> itr, const T& value)
{
	// 不正イテレータによる挿入失敗
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;

	// 新規ノードの生成と設定
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pBack = itr.m_pNode;
	newNode->pFront = itr.m_pNode->pFront;
	// 前後のノードの接続を修正
	itr.m_pNode->pFront = newNode;
	newNode->pFront->pBack = newNode;
	// リスト要素数+1
	++m_NodeCnt;

	return true; // 挿入成功
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Insert(ConstIterator<T> itr, const T& value)
{
	// 不正イテレータによる挿入失敗
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;

	// 新規ノードの生成と設定
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pBack = itr.m_pNode;
	newNode->pFront = itr.m_pNode->pFront;
	// 前後のノードの接続を修正
	itr.m_pNode->pFront = newNode;
	newNode->pFront->pBack = newNode;
	// リスト要素数+1
	++m_NodeCnt;

	return true; // 挿入成功
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Erase(Iterator<T> itr)
{
	// 不正イテレータによる削除失敗
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;
	// ダミーノードの場合も削除失敗
	if (itr.m_pNode == m_pDummyNode) return false;

	// 前後のノードの接続を修正
	itr.m_pNode->pBack->pFront = itr.m_pNode->pFront;
	itr.m_pNode->pFront->pBack = itr.m_pNode->pBack;
	// 該当ノードを削除
	delete itr.m_pNode;
	itr.m_pNode = nullptr;
	// リスト要素数-1
	--m_NodeCnt;

	return true;	// 削除成功
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Erase(ConstIterator<T> itr)
{
	// 不正イテレータによる削除失敗
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;
	// ダミーノードの場合も削除失敗
	if (itr.m_pNode == m_pDummyNode) return false;

	// 前後のノードの接続を修正
	itr.m_pNode->pBack->pFront = itr.m_pNode->pFront;
	itr.m_pNode->pFront->pBack = itr.m_pNode->pBack;
	// 該当ノードを削除
	delete itr.m_pNode;
	itr.m_pNode = nullptr;
	// リスト要素数-1
	--m_NodeCnt;

	return true;	// 削除成功
}
//-----------------------------------------------------------------------------
template<class T>
Iterator<T> List<T>::GetBegin()
{
	return Iterator<T>(this, m_pDummyNode->pBack);
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T> List<T>::GetConstBegin() const
{
	return ConstIterator<T>(this, m_pDummyNode->pBack);
}
//-----------------------------------------------------------------------------
template<class T>
Iterator<T> List<T>::GetEnd()
{
	return Iterator<T>(this, m_pDummyNode);
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T> List<T>::GetConstEnd() const
{
	return ConstIterator<T>(this, m_pDummyNode);
}
