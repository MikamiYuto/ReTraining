/**
 * @file List.h
 * @brief テンプレート双方向リストクラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.15
 */
#pragma once


 /**
  * @brief		双方向リストクラス
  * @tparam T	値
  */
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
		const List<T>*	m_pList;	//!< イテレータの参照先リスト
		List<T>::Node* m_pNode;		//!< イテレータが指し示すノード

	public:
		/**
		 * @brief			コンストラクタ
		 * @param[in] pList イテレータが参照するリスト
		 * @param[in] pNode イテレータが指し示す要素
		 */
		ConstIterator(const List<T>* pList = nullptr, List<T>::Node* pNode = nullptr);
		/**
		 * @brief デストラクタ
		 */
		virtual ~ConstIterator();

	public:
		/**
		 * @brief	前置インクリメント演算子のオーバーロード
		 * @return	ノードを末尾へ一つずらした後のイテレータ
		 */
		ConstIterator& operator++();
		/**
		 * @brief	後置インクリメント演算子のオーバーロード
		 * @return	現在のノードを指すイテレータ
		 */
		ConstIterator operator++(int);
		/**
		 * @brief	前置デクリメント演算子のオーバーロード
		 * @return	ノードを先頭へ一つずらした後のイテレータ
		 */
		ConstIterator& operator--();
		/**
		 * @brief	後置デクリメント演算子のオーバーロード
		 * @return	現在のノードを指すイテレータ
		 */
		ConstIterator operator--(int);
		/**
		 * @brief	等価演算子のオーバーロード
		 * @return	等価比較結果
		 */
		bool operator==(const ConstIterator& itr) const;
		/**
		 * @brief	非等価演算子のオーバーロード
		 * @return	非等価比較結果
		 */
		bool operator!=(const ConstIterator& itr) const;
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
		Iterator(const List<T>* pList = nullptr, List<T>::Node* pNode = nullptr);
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
	using CmpDataFunc = bool(*)(bool, const T&, const T&);

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
	bool Insert(ConstIterator& itr, const T& value);
	/**
	 * @brief			要素の削除
	 * @param[in] itr	削除位置
	 * @return			削除の成否、失敗の場合は何もしない
	 *					失敗ケース
	 *					・リスト未参照
	 *					・別のリストを参照している
	 *					・末尾(ダミーノード)を参照している
	 */
	bool Erase(ConstIterator& itr);
	/**
	 * @brief	先頭ノードを指すイテレータの取得
	 * @return	先頭イテレータ
	 */
	Iterator begin();
	/**
	 * @brief	先頭ノードを指すコンストイテレータの取得
	 * @return	先頭コンストイテレータ
	 */
	ConstIterator begin() const;
	/**
	 * @brief	末尾ノード(ダミー)を指すイテレータの取得
	 * @return	末尾イテレータ
	 */
	Iterator end();
	/**
	 * @brief	末尾ノード(ダミー)を指すコンストイテレータの取得
	 * @return	末尾コンストイテレータ
	 */
	ConstIterator end() const;
	/**
	 * @brief				クイックソート
	 * @param[in] isAsk		整列順の指定(true:昇順、false:降順
	 * @param[in] cmpFunc	要素比較関数、nullptrの場合は何もしない
	 */
	void QuickSort(bool isAsk, CmpDataFunc cmpFunc);

private:
	/**
	 * @brief			要素の交換
	 * @param[in] pA	交換するノードその１
	 * @param[in] pB	交換するノードその２
	 */
	void Swap(Node* pA, Node* pB);
	/**
	 * @brief		中央値の取得
	 * @param[in] a 比べる値その１
	 * @param[in] b 比べる値その２
	 * @param[in] c 比べる値その３
	 * @return		引数の中央値
	 */
	const T& Median(const T& a, const T&b, const T&c) const;
	/**
	 * @brief				要素を大小に分割(整列)する
	 * @param[in] isAsk		整列順の指定(true:昇順、false:降順
	 * @param[in] cmpFunc	要素比較関数
	 * @param[in] pivot		分割する基準値
	 * @param[in] L			整列する範囲の先頭ノード
	 * @param[in] R			整列する範囲の末尾ノード
	 * @param[out] 	ML		受取用、大小に整列した区間の境目になる先頭側ノード
	 * @param[out] 	MR		受取用、大小に整列した区間の境目になる末尾側ノード
	 */
	void Partition(bool isAsk, CmpDataFunc cmpFunc, const T& pivot, Node* L, Node* R, Node*& ML, Node*& MR);
	/**
	 * @brief				クイックソート(再帰
	 * @param[in] isAsk		整列順の指定(true:昇順、false:降順
	 * @param[in] cmpFunc	要素比較関数
	 * @param[in] L			整列する範囲の先頭ノード
	 * @param[in] R			整列する範囲の末尾ノード
	 */
	void QuickSort(bool isAsk, CmpDataFunc cmpFunc, Node* L, Node* R);
};
#include "List.inl"