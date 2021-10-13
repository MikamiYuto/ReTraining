/**
 * @file HashTable.h
 * @breif テンプレートハッシュテーブルクラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- インクルード
#include "List.h"
#include "Iterator.h"


// ハッシュテーブルクラス
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
class HashTable
{
private:
	/** ペア構造体 */
	struct Pair
	{
		Key		key;	//!< ハッシュのキー
		Value	value;	//!< 値
	};

private:
	List<Pair> m_Table[SIZE];			//!< ペア格納テーブル

public:
	/**
	 * @brief	コンストラクタ
	 * @details	テンプレート引数で指定されたSIZE分のリストが内部で用意されます
	 */
	HashTable();
	/**
	 * @brief	デストラクタ
	 * @details	保持していた要素を解放します
	 */
	~HashTable();

public:
	/**
	 * @brief	要素数の取得
	 * @return	要素数
	 */
	int GetCount() const;
	/**
	 * @brief			要素の挿入
	 * @param[in] key	挿入する要素のキー値
	 * @param[in] value	挿入する要素の値
	 * @return			挿入の成否
	 */
	bool Insert(const Key& key, const Value& value);
	/**
	 * @brief			要素の削除
	 * @param[in] key	削除する要素のキー値
	 * @return			削除の成否
	 */
	bool Erase(const Key& key);
	/**
	 * @brief			要素の検索
	 * @param[in] key	検索する要素のキー値
	 * @param[out] out	見つかった値の受取先
	 * @return			検索の成否
	 */
	bool Find(const Key& key, Value* out);
};