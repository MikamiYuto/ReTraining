/**
 * @file List.h
 * @brief テンプレート双方向リストクラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


 /** 双方向リストクラス */
template<class T>
class List
{
private:
	/** リストノード構造体 */
	struct Node
	{
		Node*		pFront;	//!< 前のノードを指すポインタ(先頭
		Node*		pBack;	//!< 後のノードを指すポインタ(末尾
		T			data;	//!< 値を保持
	};

public:
	/** コンストイテレータクラス */
	class ConstIterator
	{
	public:
		friend class List<T>;

	protected:
		typename const List<T>*	m_pList;		//!< イテレータの参照先リスト
		typename List<T>::Node* m_pNode;		//!< イテレータが指し示すノード

	public:
		/**
		 * @brief			コンストラクタ
		 * @param[in] pList イテレータが参照するリスト
		 * @param[in] pNode イテレータが指し示す要素
		 */
		ConstIterator(typename const List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
		/**
		 * @brief デストラクタ
		 */
		virtual ~ConstIterator();
	
	public:
		/**
		 * @brief	前置インクリメント演算子のオーバーロード
		 * @return	ノードを末尾へ一つずらした後のイテレータ
		 */
		typename ConstIterator& operator++();
		/**
		 * @brief	後置インクリメント演算子のオーバーロード
		 * @return	現在のノードを指すイテレータ
		 */
		typename ConstIterator operator++(int);
		/**
		 * @brief	前置デクリメント演算子のオーバーロード
		 * @return	ノードを先頭へ一つずらした後のイテレータ
		 */
		typename ConstIterator& operator--();
		/**
		 * @brief	後置デクリメント演算子のオーバーロード
		 * @return	現在のノードを指すイテレータ
		 */
		typename ConstIterator operator--(int);
		/**
		 * @brief	等価演算子のオーバーロード
		 * @return	等価比較結果
		 */
		bool operator==(typename const ConstIterator& itr) const;
		/**
		 * @brief	非等価演算子のオーバーロード
		 * @return	非等価比較結果
		 */
		bool operator!=(typename const ConstIterator& itr) const;
		/**
		 * @brief	関節演算子のオーバーロード
		 * @return	イテレータが指す要素の値
		 */
		const T& operator*() const;
	};

public:
	/** イテレータクラス */
	class Iterator : public ConstIterator
	{
	public:
		/**
		 * @brief			コンストラクタ
		 * @param[in] pList イテレータが参照するリスト
		 * @param[in] pNode イテレータが指し示すノード
		 */
		Iterator(typename const List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
		/**
		 * @brief デストラクタ
		 */
		~Iterator();
	
	public:
		/**
		 * @brief	関節演算子のオーバーロード
		 * @return	イテレータが指す要素の値
		 */
		T& operator*();
	};

private:
	Node*	m_pDummyNode;	//!< ダミーノード
	int		m_ElementCnt;	//!< 要素数（ダミーは未カウント

public:
	/**
	 * @brief	コンストラクタ
	 */
	List();
	/**
	 * @brief	デストラクタ
	 */
	~List();

public:
	/**
	 * @brief	要素数の取得
	 * @return	要素数
	 */
	int GetCount() const;
	/**
	 * @brief			要素の挿入
	 * @param[in] itr	挿入位置
	 * @param[in] value 挿入する値
	 * @return			挿入の成否、失敗の場合は何もしない
	 *					失敗ケース
	 *					・リスト未参照
	 *					・別のリストを参照している
	 *					・要素のメモリ確保失敗
	 */
	bool Insert(typename ConstIterator& itr, const T& value);
	/**
	 * @brief			要素の削除
	 * @param[in] itr	削除位置
	 * @return			削除の成否、失敗の場合は何もしない
	 *					失敗ケース
	 *					・リスト未参照
	 *					・別のリストを参照している
	 *					・末尾(ダミーノード)を参照している
	 */
	bool Erase(typename ConstIterator& itr);
	/**
	 * @brief	先頭ノードを指すイテレータの取得
	 * @return	先頭イテレータ
	 */
	typename Iterator begin();
	/**
	 * @brief	先頭ノードを指すコンストイテレータの取得
	 * @return	先頭コンストイテレータ
	 */
	typename ConstIterator begin() const;
	/**
	 * @brief	末尾ノード(ダミー)を指すイテレータの取得
	 * @return	末尾イテレータ
	 */
	typename Iterator end();
	/**
	 * @brief	末尾ノード(ダミー)を指すコンストイテレータの取得
	 * @return	末尾コンストイテレータ
	 */
	typename ConstIterator end() const;
};
#include "List.inl"