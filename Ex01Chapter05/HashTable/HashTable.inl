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
	// �L�[�l��DEFALT_HASH_BUCKET_SIZE�Ŋ������]����n�b�V���Ƃ���
	return key % DEFAULT_HASH_BUCKET_SIZE;
}
//-----------------------------------------------------------------------------
int CalcHash(const std::string& key)
{
	// ������̒�����DEFALT_HASH_BUCKET_SIZE�Ŋ������]����n�b�V���Ƃ���
	return key.length() % DEFAULT_HASH_BUCKET_SIZE;
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
	auto itr = list.begin();
	for (auto e = list.end(); itr != e; ++itr)
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
	auto itr = list.begin();
	for (auto e = list.end(); itr != e; ++itr)
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
	auto itr = list.begin();
	for (auto e = list.end(); itr != e; ++itr)
		if ((*itr).key == key)
		{
			// �v�f�����l��ԋp
			if (out) *out = (*itr).value;
			return true;
		}

	return false;// �������s
}
//-----------------------------------------------------------------------------
template<class Key, class Value, int(*CalcHashFunc)(const Key &), int SIZE>
int HashTable<Key, Value, CalcHashFunc, SIZE>::GetHash(const Key & key) const
{
	// �Z�o���ꂽ�n�b�V���l���o�P�b�g�T�C�Y���ɔ[�߂Ă���Ԃ�
	return CalcHashFunc(key) % SIZE;
}