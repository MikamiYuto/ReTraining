/**
 * @file List.h
 * @breif テンプレートイテレータクラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.11
 */
#pragma once


//----- インクルード
#include "List.h"


/** コンストイテレータクラス */
template<class T>
class ConstIterator
{
public:
	friend class List<T>;

protected:
	typename const List<T>*	m_pList;		//!< イテレータの参照先リスト
	typename List<T>::Node* m_pNode;		//!< イテレータが指し示すノード

public:
	/**
	 * @breif			コンストラクタ
	 * @param[in] pList イテレータが参照するリスト
	 * @param[in] pNode イテレータが指し示す要素
	 */
	ConstIterator(const List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
	/**
	 * @breif デストラクタ
	 */
	virtual ~ConstIterator();

public:
	/**
	 * @breif	前置インクリメント演算子のオーバーロード
	 * @return	ノードを末尾へ一つずらした後のイテレータ
	 * @details ノードを末尾へ一つずらす
	 */
	ConstIterator& operator++();
	/**
	 * @breif	後置インクリメント演算子のオーバーロード
	 * @return	現在のノードを指すイテレータ
	 * @details ノードを末尾へ一つずらす
	 */
	ConstIterator operator++(int);
	/**
	 * @breif	前置デクリメント演算子のオーバーロード
	 * @return	ノードを先頭へ一つずらした後のイテレータ
	 * @details ノードを先頭へ一つずらす
	 */
	ConstIterator& operator--();
	/**
	 * @breif	後置デクリメント演算子のオーバーロード
	 * @return	現在のノードを指すイテレータ
	 * @details ノードを先頭へ一つずらす
	 */
	ConstIterator operator--(int);
	/**
	 * @breif	等価演算子のオーバーロード
	 * @return	等価比較結果
	 * @details コンストイテレータの指しているノードが等価か比較する
	 */
	bool operator==(const ConstIterator& itr) const;
	/**
	 * @breif	非等価演算子のオーバーロード
	 * @return	非等価比較結果
	 * @details コンストイテレータの指しているノードが非等価か比較する
	 */
	bool operator!=(const ConstIterator& itr) const;
	/**
	 * @breif	関節演算子のオーバーロード
	 * @return	イテレータが指す要素
	 */
	const T& operator*();
};

/** イテレータクラス */
template<class T>
class Iterator : public ConstIterator<T>
{
public:
	/**
	 * @breif		コンストラクタ
	 * @param[in] p イテレータが参照するリスト
	 * @param[in] p イテレータが指し示すノード
	 */
	Iterator(List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
	/**
	 * @breif デストラクタ
	 */
	~Iterator();

public:
	/**
	 * @breif	関節演算子のオーバーロード
	 * @return	イテレータが指す要素
	 */
	T& operator*();
};
#include "Iterator.inl"