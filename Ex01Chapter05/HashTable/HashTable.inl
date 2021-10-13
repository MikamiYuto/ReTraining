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
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
HashTable<Key, Value, CalcHashFunc, SIZE>::HashTable()
	: m_Table()
{
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
HashTable<Key, Value, CalcHashFunc, SIZE>::~HashTable()
{
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
int HashTable<Key, Value, CalcHashFunc, SIZE>::GetCount() const
{
	return 0;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Insert(const Key& key, const Value& value)
{
	return false;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Erase(const Key& key)
{
	return false;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Find(const Key& key, Value* out)
{
	return false;
}
