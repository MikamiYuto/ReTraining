/**
 * @file StackTest.h
 * @breif �e���v���[�g�X�^�b�N�N���X�̃e�X�g��`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.14
 */
#pragma once


 //----- �C���N���[�h
#include "gtest/gtest.h"
#include "../HashTable/HashTable.h"


/** �n�b�V���e�[�u���e�X�g�p�̃t�B�N�X�`���N���X */
class HashTableTest : public ::testing::Test
{
protected:
	/**
	 * @brief �d��(�`�F�C��)�����v�f�����n�b�V���e�[�u���̗p��<"one", 1><"two", 2>
	 */
	void SetUpChainHash()
	{
		ASSERT_TRUE(m_HashTable.Insert("one", 1));
		ASSERT_TRUE(m_HashTable.Insert("two", 2));
	}
	/**
	 * @brief �d��(�`�F�C��)�����ɕ����v�f�����n�b�V���e�[�u���̗p��<"zero", 0><"one", 1>
	 */
	void SetUpUnChainHash()
	{
		ASSERT_TRUE(m_HashTable.Insert("zero", 0));
		ASSERT_TRUE(m_HashTable.Insert("one", 1));
	}

protected:
	HashTable<std::string, int, CalcHash, DEFAULT_HASH_PACKET_SIZE> m_HashTable;
};
/** �f�[�^���擾�e�X�g�p */
using HashTableGetDataNumTest = HashTableTest;
/** �}�����̋����e�X�g�p */
using HashTableInsertTest = HashTableTest;
/** �폜���̋����e�X�g�p */
using HashTableEraseTest = HashTableTest;
/** �������̋����e�X�g�p */
using HashTableFindTest = HashTableTest;