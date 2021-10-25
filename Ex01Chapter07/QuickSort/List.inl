/**
 * @file List.inl
 * @brief テンプレート双方向リストクラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.15
 */
#pragma once


 //----- インクルード
#include "List.h"
#include <cassert>


//=============================================================================
// コンストイテレータの実装
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
// イテレータの実装
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
// リストの実装
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
	// 先頭からノードを順に削除していく
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
	// 不正イテレータ(別リスト参照)による挿入失敗
	if (itr.m_pList != this) return false;
	// 不正イテレータ(ノード未参照)による挿入失敗
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
	++m_ElementCnt;

	return true; // 挿入成功
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Erase(List<T>::ConstIterator& itr)
{
	// 不正イテレータ(別リスト参照)による削除失敗
	if (itr.m_pList != this) return false;
	// 不正イテレータ(ノード未参照)による削除失敗
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
	--m_ElementCnt;

	return true; // 削除成功
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
// クイックソート参考URL
// https://cod-aid.com/library-quick-sort ←基本的なアルゴリズムを参考
// https://bi.biopapyrus.jp/cpp/algorithm/sort/quick-sort.html ←Partition辺りを参考
// https://ufcpp.net/study/algorithm/sort_quick.html ←中央値辺りを参考
//-----------------------------------------------------------------------------
template<class T>
void List<T>::QuickSort(CmpDataFunc cmpFunc)
{
	// キーが設定されていなければ何もしない
	if (!cmpFunc) return;
	// 要素が空、または1つだけなら即リターン 
	if (m_pDummyNode->pBack == m_pDummyNode->pFront) return;

	// 再帰開始
	QuickSort(cmpFunc, m_pDummyNode->pBack, m_pDummyNode->pFront);
}
//-----------------------------------------------------------------------------
template<class T>
void List<T>::Swap(typename Node* pA, typename Node* pB)
{
#if 1
	// 値を交換するパターン
	T temp = std::move(pA->data);
	pA->data = std::move(pB->data);
	pB->data = std::move(temp);
#else
	// 接続を変えるパターン
	if (pA->pBack == pB)
	{// 隣接する場合(?-A-B-?
		pB->pFront = pA->pFront;
		pA->pFront = pB;
		pA->pBack = pB->pBack;
		pB->pBack = pA;
		pA->pBack->pFront = pA;
		pB->pFront->pBack = pB;
	}
	else if (pA->pFront == pB)
	{// 隣接する場合(?-B-A-?
		pA->pFront = pB->pFront;
		pB->pFront = pA;
		pB->pBack = pA->pBack;
		pA->pBack = pB;
		pB->pBack->pFront = pB;
		pA->pFront->pBack = pA;
	}
	else
	{// 離れている場合
		Node* temp = pA->pFront;
		pA->pFront = pB->pFront;
		pB->pFront = temp;
		temp = pA->pBack;
		pA->pBack = pB->pBack;
		pB->pBack = temp;
		pA->pFront->pBack = pA;
		pA->pBack->pFront = pA;
		pB->pFront->pBack = pB;
		pB->pBack->pFront = pB;
	}
#endif
}
//-----------------------------------------------------------------------------
template<class T>
const T& List<T>::Median(CmpDataFunc cmpFunc, const T& a, const T& b, const T& c) const
{
	// 3つの値の中から中央の値を求める
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
	// 基準値を元に大小へ分割する
	while (true)
	{
		// 基準値を超えるノードを探索
		while (cmpFunc(L->data, pivot)) L = L->pBack;
		while (cmpFunc(pivot, R->data)) R = R->pFront;

		// 走査しているノードが交差したら終了
		if (L == R || L->pFront == R) break;

		// 次の要素から走査を始める
		L = L->pBack;
		R = R->pFront;
		
		// 値交換
		Swap(L->pFront, R->pBack);
	}

	// 次の整列区間を返却
	Node M;
	M.pFront = L->pFront;
	M.pBack = R->pBack;
	return M;
}
//-----------------------------------------------------------------------------
template<class T>
void List<T>::QuickSort(CmpDataFunc cmpFunc, typename Node* L, typename Node* R)
{
	// 整列に用いる基準値を整列区間の先頭、末尾前、末尾からの中央値を選択
	// 参照の場合、値交換により整列中に基準値が変わるため不可(接続交換なら参照でも行けそうだけど、修正箇所が多くなりそうなため断念
	const T pivot = Median(cmpFunc, L->data, R->pFront->data, R->data);
	
	// 基準値を元に整列区間のリスト要素を大小に分割
	Node M = Partition(cmpFunc, pivot, L, R);

	// 再帰的に処理
	if (!(L == M.pFront || L->pFront == M.pFront)) QuickSort(cmpFunc, L, M.pFront);
	if (!(R == M.pBack || R->pBack == M.pBack)) QuickSort(cmpFunc, M.pBack, R);
}