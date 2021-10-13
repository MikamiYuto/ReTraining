/**
 * @file List.h
 * @breif テンプレート双方向リストクラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


template<class T>
class ConstIterator;
template<class T>
class Iterator;
 /** 双方向リストクラス */
template<class T>
class List
{
public:
	/** リストノード構造体 */
	struct Node
	{
		Node*		pFront;	//!< 前のノードを指すポインタ(先頭
		Node*		pBack;	//!< 後のノードを指すポインタ(末尾
		T			data;	//!< 値を保持
	};

private:
	Node*	m_pDummyNode;	//!< ダミーノード
	int		m_NodeCnt;		//!< 要素数（ダミーは未カウント

public:
	/**
	 * @breif	コンストラクタ
	 * @details	ダミーノードを生成します
	 */
	List();
	/**
	 * @breif	デストラクタ
	 * @details 保持していたノードを全て解放します
	 */
	~List();

public:
	/**
	 * @brief	要素数の取得
	 * @return	要素数
	 * @details リストが現在保持している要素数を返します
	 */
	int GetCount() const;
	/**
	 * @brief			要素の挿入
	 * @param[in] itr	挿入位置
	 * @param[in] value 挿入する値
	 * @return			挿入の成否
	 */
	bool Insert(Iterator<T> itr, const T& value);
	bool Insert(ConstIterator<T> itr, const T& value);
	/**
	 * @brief			要素の削除
	 * @param[in] itr	削除位置
	 * @retunr			削除の成否
	 */
	bool Erase(Iterator<T> itr);
	bool Erase(ConstIterator<T> itr);
	/**
	 * @brief	先頭ノードを指すイテレータの取得
	 * @return	先頭イテレータ
	 */
	Iterator<T> GetBegin();
	/**
	 * @brief	先頭ノードを指すコンストイテレータの取得
	 * @return	先頭コンストイテレータ
	 */
	ConstIterator<T> GetConstBegin() const;
	/**
	 * @brief	末尾ノードを指すイテレータの取得
	 * @return	末尾イテレータ
	 */
	Iterator<T> GetEnd();
	/**
	 * @brief	末尾ノードを指すコンストイテレータの取得
	 * @return	末尾コンストイテレータ
	 */
	ConstIterator<T> GetConstEnd() const;
};
#include "List.inl"