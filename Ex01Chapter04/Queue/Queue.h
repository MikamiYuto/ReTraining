/**
 * @file Queue.h
 * @breif テンプレートキュークラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- インクルード
#include "List.h"


/** 双方向リストクラス */
template<class T>
class Queue
{
private:
	List<T> m_List;

public:
	/**
	 * @brief	コンストラクタ
	 * @details リストを用意する
	 */
	Queue();
	/**
	 * @brief	デストラクタ
	 * @details 要素を解放する
	 */
	~Queue();

public:
	/**
	 * @brief	要素数の取得
	 * @return	要素数
	 */
	int GetCount() const;
	/**
	 * @breif			要素の挿入
	 * @param[in] value 挿入する要素の値
	 * @return			挿入の成否
	 */
	bool Push(const T& value);
	/**
	 * @breif			要素の取り出し
	 * @param[in] out	取り出した値の受取先
	 * @return			取り出しの成否
	 */
	bool Pop(T* out);
};
#include "Queue.inl"