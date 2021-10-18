/**
 * @file StackTest.cpp
 * @brief �e���v���[�g�X�^�b�N�N���X�̃e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.14
 */


 //----- �C���N���[�h
#include "HashTableTest.h"


//=============================================================================
// �N���X�̋����e�X�g
//=============================================================================
/**
 * @brief	�Z�o���@�̈قȂ�K�؂ȃn�b�V���֐���n�����Ƃ��̂��ꂼ��̋����e�X�g
 * @deteils	ID:���X�g-1
 */
TEST(HashTableClassTest, TestHashTableClass)
{
	// �����񂩂�n�b�V���l�𓱏o����֐���n�����ꍇ
	{
		HashTable<std::string, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
		const std::string key = "test";
		const int value = 10;
		int check = 0;
		// �e����̃`�F�b�N
		EXPECT_TRUE(hashTable.Insert(key, value));	// �}��
		EXPECT_TRUE(hashTable.Find(key, &check));	// ����
		EXPECT_EQ(check, value);					// �����Ŏ擾�����l
		EXPECT_TRUE(hashTable.Erase(key));			// �폜
	}
	// ��������n�b�V���l�𓱏o����֐���n�����ꍇ
	{
		HashTable<int, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
		const int key = 100;
		const int value = 10;
		int check = 0;
		// �e����̃`�F�b�N
		EXPECT_TRUE(hashTable.Insert(key, value));	// �}��
		EXPECT_TRUE(hashTable.Find(key, &check));	// ����
		EXPECT_EQ(check, value);					// �����Ŏ擾�����l
		EXPECT_TRUE(hashTable.Erase(key));			// �폜
	}
}
//=============================================================================
// �f�[�^���̎擾�e�X�g
//=============================================================================
/**
 * @brief	���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-2
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumWhenEmpty)
{
	EXPECT_EQ(m_HashTable.GetCount(), 0);
}
/**
 * @brief	�v�f��}��������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-3
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterInsert)
{
	ASSERT_TRUE(m_HashTable.Insert("test", 10));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	�v�f��}�����A���̃L�[�ō폜������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-4
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterInsertToErase)
{
	const std::string key = "test";
	ASSERT_TRUE(m_HashTable.Insert(key, 10));
	ASSERT_TRUE(m_HashTable.Erase(key));
	EXPECT_EQ(m_HashTable.GetCount(), 0);
}
/**
 * @brief	���ɑ��݂���L�[�ŗv�f�̑}���������s������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-5
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterInsertFailed)
{
	const std::string key = "test";
	ASSERT_TRUE(m_HashTable.Insert(key, 10));
	ASSERT_FALSE(m_HashTable.Insert(key, 20));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	�v�f�����݂��Ă��鎞�ɑ��݂��Ȃ��L�[�ł̍폜�Ɏ��s������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-6
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterEraseFailed)
{
	ASSERT_TRUE(m_HashTable.Insert("test", 10));
	ASSERT_FALSE(m_HashTable.Erase("check"));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	���X�g����ł��鎞�ɍ폜���s������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-7
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterEraseWhenEmpty)
{
	ASSERT_FALSE(m_HashTable.Erase("test"));
	EXPECT_EQ(m_HashTable.GetCount(), 0);
}
/**
 * @brief	�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-8
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumUnChain)
{
	SetUpUnChainHash();
	EXPECT_EQ(m_HashTable.GetCount(), 2);
}
/**
 * @brief	�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ����Ɉ�����폜������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-9
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumUnChainOtherErase)
{
	SetUpUnChainHash();
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	�v�f�Q�������Ń`�F�C���ɂȂ��Ă��鎞�̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-10
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumChain)
{
	SetUpChainHash();
	EXPECT_EQ(m_HashTable.GetCount(), 2);
}
/**
 * @brief	�v�f�Q�������Ń`�F�C���ɂȂ��Ă��鎞�Ɉ�����폜������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-11
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumChainOtherErase)
{
	SetUpChainHash();
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
//=============================================================================
// �f�[�^�̑}���e�X�g
//=============================================================================
/**
 * @brief	���X�g����ł��鎞�ɑ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-13
 */
TEST_F(HashTableInsertTest, TestInsertWhenEmpty)
{
	EXPECT_TRUE(m_HashTable.Insert("test", 10));
}
/**
 * @brief	�����v�f������ꍇ�ɁA�L�[���d�����Ȃ��ő}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-14
 */
TEST_F(HashTableInsertTest, TestInsertUnDup)
{
	SetUpUnChainHash();
	EXPECT_TRUE(m_HashTable.Insert("test", 10));
}
/**
 * @brief	�����v�f������ꍇ�ɁA�L�[���d�����đ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-15
 */
TEST_F(HashTableInsertTest, TestInsertDup)
{
	SetUpUnChainHash();
	EXPECT_FALSE(m_HashTable.Insert("one", 10));
}
/**
 * @brief	�����v�f������ꍇ�ɁA�n�b�V���l�������ɂ���L�[�ő}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-16
 */
TEST_F(HashTableInsertTest, TestInsertChain)
{
	SetUpUnChainHash();
	EXPECT_TRUE(m_HashTable.Insert("two", 10));
}
/**
 * @brief	��x�}�����폜�A�����čēx�����L�[�ő}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-17
 */
TEST_F(HashTableInsertTest, TestInsertReInsert)
{
	const std::string key = "test";
	const int value = 10;
	ASSERT_TRUE(m_HashTable.Insert(key, value));
	ASSERT_TRUE(m_HashTable.Erase(key));
	EXPECT_TRUE(m_HashTable.Insert(key, value));
}
//=============================================================================
// �f�[�^�̍폜�e�X�g
//=============================================================================
/**
 * @brief	���X�g����ł��鎞�ɍ폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-19
 */
TEST_F(HashTableEraseTest, TestEraseWhenEmpty)
{
	EXPECT_FALSE(m_HashTable.Erase("test"));
}
/**
 * @brief	�����v�f������ꍇ�ɁA���݂���L�[�ō폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-20
 */
TEST_F(HashTableEraseTest, TestEraseExistKey)
{
	SetUpUnChainHash();
	EXPECT_TRUE(m_HashTable.Erase("one"));
}
/**
 * @brief	�����v�f������ꍇ�ɁA���݂��Ȃ��L�[�ō폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-21
 */
TEST_F(HashTableEraseTest, TestEraseNotExistKey)
{
	SetUpUnChainHash();
	EXPECT_FALSE(m_HashTable.Erase("test"));
}
/**
 * @brief	��x�폜�����L�[�ōēx�폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-22
 */
TEST_F(HashTableEraseTest, TestEraseReErase)
{
	SetUpUnChainHash();
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_FALSE(m_HashTable.Erase("one"));
}
/**
 * @brief	�`�F�C�������v�f�̂����̃L�[���w�肵�č폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-23
 */
TEST_F(HashTableEraseTest, TestEraseChainOther)
{
	SetUpChainHash();
	EXPECT_TRUE(m_HashTable.Erase("one"));
}
/**
 * @brief	�`�F�C�������v�f�̂����̃L�[�ƃn�b�V���l�����������A���݂��Ȃ��L�[�ō폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-24
 */
TEST_F(HashTableEraseTest, TestEraseChainEqualHashAndNotExistKey)
{
	SetUpChainHash();
	EXPECT_FALSE(m_HashTable.Erase("six"));
}
/**
 * @brief	�`�F�C���ɂȂ��Ă���v�f�����ɍ폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-25
 */
TEST_F(HashTableEraseTest, TestEraseChainAll)
{
	SetUpChainHash();
	EXPECT_TRUE(m_HashTable.Erase("one"));
	EXPECT_TRUE(m_HashTable.Erase("two"));
}
//=============================================================================
// �f�[�^�̌����e�X�g
//=============================================================================
/**
 * @brief	���X�g����ł��鎞�Ɍ��������ۂ̋����e�X�g
 * @deteils	ID:���X�g-27
 */
TEST_F(HashTableFindTest, TestFindWhenEmpty)
{
	int check = 0;
	EXPECT_FALSE(m_HashTable.Find("test", &check));
	// ����ɕςȒl���������Ă��Ȃ����`�F�b�N
	EXPECT_EQ(check, 0);
}
/**
 * @brief	�����v�f�����鎞�ɑ��݂���L�[�Ō��������ۂ̋����e�X�g
 * @deteils	ID:���X�g-28
 */
TEST_F(HashTableFindTest, TestFindExistKey)
{
	SetUpUnChainHash();
	int check = 0;
	EXPECT_TRUE(m_HashTable.Find("one", &check));
	// �擾�����l���`�F�b�N
	EXPECT_EQ(check, 1);
}
/**
 * @brief	�����v�f�����鎞�ɑ��݂��Ȃ��L�[�Ō��������ۂ̋����e�X�g
 * @deteils	ID:���X�g-29
 */
TEST_F(HashTableFindTest, TestFindNotExistKey)
{
	SetUpUnChainHash();
	int check = 0;
	EXPECT_FALSE(m_HashTable.Find("test", &check));
	// ����ɕςȒl���������Ă��Ȃ����`�F�b�N
	EXPECT_EQ(check, 0);
}
/**
 * @brief	�����v�f�����鎞�ɑ��݂���L�[��2��A�����������ۂ̋����e�X�g
 * @deteils	ID:���X�g-30
 */
TEST_F(HashTableFindTest, TestFindExistKeyX2)
{
	SetUpUnChainHash();
	const std::string key = "one";
	int check = 0;
	EXPECT_TRUE(m_HashTable.Find(key, &check));
	EXPECT_EQ(check, 1);
	// �Q��ڂ̃`�F�b�N
	check = 0;
	EXPECT_TRUE(m_HashTable.Find(key, &check));
	EXPECT_EQ(check, 1);
}
/**
 * @brief	���ɍ폜���ꂽ�L�[�Ō��������ۂ̋����e�X�g
 * @deteils	ID:���X�g-31
 */
TEST_F(HashTableFindTest, TestFindEraseKey)
{
	SetUpUnChainHash();
	const std::string key = "one";
	int check = 0;
	ASSERT_TRUE(m_HashTable.Erase(key));
	EXPECT_FALSE(m_HashTable.Find(key, &check));
	// �ςȒl���������Ă��Ȃ����`�F�b�N
	EXPECT_EQ(check, 0);
}
/**
 * @brief	�`�F�C�������v�f�����鎞�ɁA���̂�����1�̂����������ۂ̋����e�X�g
 * @deteils	ID:���X�g-32
 */
TEST_F(HashTableFindTest, TestFindChain)
{
	SetUpChainHash();
	int check = 0;
	EXPECT_TRUE(m_HashTable.Find("one", &check));
	// �擾�����l���`�F�b�N
	EXPECT_EQ(check, 1);
}
/**
 * @brief	�`�F�C�������v�f�����鎞�ɁA���̂�����1���폜���c���Ă���v�f�����������ۂ̋����e�X�g
 * @deteils	ID:���X�g-33
 */
TEST_F(HashTableFindTest, TestFindChainOtherErase)
{
	SetUpChainHash();
	int check = 0;
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_TRUE(m_HashTable.Find("two", &check));
	// �擾�����l���`�F�b�N
	EXPECT_EQ(check, 2);
}