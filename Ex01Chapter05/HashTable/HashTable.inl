/**
 * @file HashTable.inl
 * @breif �e���v���[�g�n�b�V���e�[�u���N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


 //----- �C���N���[�h
#include "HashTable.h"


//-----------------------------------------------------------------------------
int CalcHash(const int & key)
{
	// �L�[�l��DEFALT_HASH_PACKET_SIZE�Ŋ������]����n�b�V���Ƃ���
	return key % DEFAULT_HASH_PACKET_SIZE;
}
int CalcHash(const std::string& key)
{
	// ������̒�����DEFALT_HASH_PACKET_SIZE�Ŋ������]����n�b�V���Ƃ���
	return key.length() % DEFAULT_HASH_PACKET_SIZE;
}
//=============================================================================
// �n�b�V���e�[�u���̎���
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
