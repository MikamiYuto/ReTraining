/**
 * @file HashTable.inl
 * @breif テンプレートハッシュテーブルクラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


 //----- インクルード
#include "HashTable.h"


//-----------------------------------------------------------------------------
int CalcHash(const int & key)
{
	// キー値をDEFALT_HASH_PACKET_SIZEで割った余りをハッシュとする
	return key % DEFAULT_HASH_PACKET_SIZE;
}
int CalcHash(const std::string& key)
{
	// 文字列の長さをDEFALT_HASH_PACKET_SIZEで割った余りをハッシュとする
	return key.length() % DEFAULT_HASH_PACKET_SIZE;
}
//=============================================================================
// ハッシュテーブルの実装
//=============================================================================
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
HashTable<Key, Value, CalcHashFunc, SIZE>::HashTable()
	: m_Table()
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
	return 0;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Insert(const Key& key, const Value& value)
{
	return false;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Erase(const Key& key)
{
	return false;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Find(const Key& key, Value* out) const
{
	return false;
}
