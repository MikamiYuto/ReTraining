/**
 * @file HashTable.inl
 * @brief �e���v���[�g�n�b�V���e�[�u���N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


 //----- �C���N���[�h
#include "HashTable.h"


//=============================================================================
// �n�b�V���l���o�֐��̎���
//=============================================================================
//-----------------------------------------------------------------------------
int CalcHash(const int & key)
{
	// �L�[�l��DEFALT_HASH_PACKET_SIZE�Ŋ������]����n�b�V���Ƃ���
	return key % DEFAULT_HASH_PACKET_SIZE;
}
//-----------------------------------------------------------------------------
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
	// �n�b�V���l����i�[�ʒu�̃��X�g���擾
	List<Pair>& list = m_Table[GetHash(key)];
	// �L�[�̏d���`�F�b�N
	typename List<Pair>::ConstIterator itr = list.begin();
	for (typename List<Pair>::ConstIterator e = list.end(); itr != e; ++itr)
		if ((*itr).key == key) return false;// ���ɑ}���\��̃L�[������
	// �v�f�}��
	if (!list.Insert(itr, Pair{ key,value })) return false;
	// �v�f��+1
	++m_ElementCnt;

	return true;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Erase(const Key& key)
{
	// �n�b�V���l����i�[�ʒu�̃��X�g���擾
	List<Pair>& list = m_Table[GetHash(key)];
	// �폜�v�f�̒T��
	typename List<Pair>::ConstIterator itr = list.begin();
	for (typename List<Pair>::ConstIterator e = list.end(); itr != e; ++itr)
		if ((*itr).key == key) break;
	// �v�f�폜
	if (!list.Erase(itr)) return false;
	// �v�f��-1
	--m_ElementCnt;

	return true;
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
bool HashTable<Key, Value, CalcHashFunc, SIZE>::Find(const Key& key, Value* out) const
{
	// �n�b�V���l����i�[�ʒu�̃��X�g���擾
	const List<Pair>& list = m_Table[GetHash(key)];
	// �����v�f�̒T��
	typename List<Pair>::ConstIterator itr = list.begin();
	for (typename List<Pair>::ConstIterator e = list.end(); itr != e; ++itr)
		if ((*itr).key == key)
		{
			// �v�f�����l��ԋp
			if (out) *out = (*itr).value;
			return true;
		}

	return false;// �������s
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
int HashTable<Key, Value, CalcHashFunc, SIZE>::GetHash(const Key& key) const
{
	// �L�[����n�b�V���l�Z�o
	const int hash = CalcHashFunc(key);
	// �n�b�V���l������Ȓl�͈͓̔���
	assert(0 <= hash && hash < SIZE);
	return hash;
}