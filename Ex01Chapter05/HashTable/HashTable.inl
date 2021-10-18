/**
 * @file HashTable.inl
 * @brief テンプレートハッシュテーブルクラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


 //----- インクルード
#include "HashTable.h"


//=============================================================================
// ハッシュ値導出関数の実装
//=============================================================================
//-----------------------------------------------------------------------------
int CalcHash(const int & key)
{
	// キー値をDEFALT_HASH_BUCKET_SIZEで割った余りをハッシュとする
	return key % DEFAULT_HASH_BUCKET_SIZE;
}
//-----------------------------------------------------------------------------
int CalcHash(const std::string& key)
{
	// 文字列の長さをDEFALT_HASH_BUCKET_SIZEで割った余りをハッシュとする
	return key.length() % DEFAULT_HASH_BUCKET_SIZE;
}
//=============================================================================
// ハッシュテーブルの実装
//=============================================================================
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
HashTable<Key, Value, CalcHashFunc, SIZE>::HashTable()
	: m_Table()
	, m_ElementCnt(0)
{
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
HashTable<Key, Value, CalcHashFunc, SIZE>::~HashTable()
{
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
int HashTable<Key, Value, CalcHashFunc, SIZE>::GetCount() const
{
	return m_ElementCnt;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Insert(const Key& key, const Value& value)
{
	// ハッシュ値から格納位置のリストを取得
	List<Pair>& list = m_Table[GetHash(key)];
	// キーの重複チェック
	auto itr = list.begin();
	for (auto e = list.end(); itr != e; ++itr)
		if ((*itr).key == key) return false;// 既に挿入予定のキーが存在
	// 要素挿入
	if (!list.Insert(itr, Pair{ key,value })) return false;
	// 要素数+1
	++m_ElementCnt;

	return true;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Erase(const Key& key)
{
	// ハッシュ値から格納位置のリストを取得
	List<Pair>& list = m_Table[GetHash(key)];
	// 削除要素の探索
	auto itr = list.begin();
	for (auto e = list.end(); itr != e; ++itr)
		if ((*itr).key == key) break;
	// 要素削除
	if (!list.Erase(itr)) return false;
	// 要素数-1
	--m_ElementCnt;

	return true;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Find(const Key& key, Value* out) const
{
	// ハッシュ値から格納位置のリストを取得
	const List<Pair>& list = m_Table[GetHash(key)];
	// 検索要素の探索
	auto itr = list.begin();
	for (auto e = list.end(); itr != e; ++itr)
		if ((*itr).key == key)
		{
			// 要素が持つ値を返却
			if (out) *out = (*itr).value;
			return true;
		}

	return false;// 検索失敗
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key &), int SIZE>
int HashTable<Key, Value, CalcHashFunc, SIZE>::GetHash(const Key & key) const
{
	// 算出されたハッシュ値をバケットサイズ内に納めてから返す
	return CalcHashFunc(key) % SIZE;
}