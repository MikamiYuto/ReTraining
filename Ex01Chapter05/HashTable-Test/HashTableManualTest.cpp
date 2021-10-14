/**
 * @file HashTableManualTest.cpp
 * @breif �e���v���[�g�n�b�V���e�[�u���N���X�̎蓮�e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.14
 */


//----- �C���N���[�h
#include "HashTableManualTest.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
/**
 * @brief	�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ���̃e�X�g
 * @deteils	ID:�n�b�V���e�[�u��-0(�蓮)
 */
TEST(HashTableManualTest, TestClassHashFunc)
{
#if defined TEST_CLASS_HASH_FUNC
	HashTable<float, int, CalcHash, DEFAULT_HASH_PACKET_SIZE> hashTable;
#endif // TEST_CLASS_HASH_FUNC
	SUCCEED();
}

/**
 * @brief	�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�n�b�V���e�[�u��-12(�蓮)
 */
TEST_F(HashTableManualTest, TestGetDataNumIsConst)
{
#if defined TEST_GET_DATA_NUM_IS_CONST
	EXPECT_EQ(m_HashTable.GetCount(), 0);
#endif // TEST_GET_DATA_NUM_IS_CONST
	SUCCEED();
}
/**
 * @brief	�}���@�\�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�n�b�V���e�[�u��-18(�蓮)
 */
TEST_F(HashTableManualTest, TestInsertIsConst)
{
#if defined TEST_INSERT_IS_CONST
	m_HashTable.Insert("test", 10);// �����ŃG���[
#endif // TEST_INSERT_IS_CONST
	SUCCEED();
}
/**
 * @brief	�폜�@�\�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�n�b�V���e�[�u��-18(�蓮)
 */
TEST_F(HashTableManualTest, TestEraseIsConst)
{
#if defined TEST_ERASE_IS_CONST
	m_HashTable.Erase("test");// �����ŃG���[
#endif // TEST_ERASE_IS_CONST
	SUCCEED();
}
/**
 * @brief	�����@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�n�b�V���e�[�u��-26(�蓮)
 */
TEST_F(HashTableManualTest, TestFindIsConst)
{
#if defined TEST_FIND_IS_CONST
	EXPECT_FALSE(m_HashTable.Find("test"));
#endif // TEST_FIND_IS_CONST
	SUCCEED();
}