/**
 * @file HashTableManualTest.h
 * @brief �e���v���[�g���X�g�N���X�̃e�X�g��`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.14
 */
#pragma once


//----- �C���N���[�h
#include "gtest/gtest.h"
#include "../HashTable/HashTable.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
//----- �}�N����`

// ���R���p�C�����ʂ�ΐ���
#define TEST_GET_DATA_NUM_IS_CONST	// ID:�n�b�V���e�[�u��-12
#define TEST_FIND_IS_CONST			// ID:�n�b�V���e�[�u��-34

// ���R���p�C�����ʂ�Ȃ���ΐ���
//#define TEST_CLASS_HASH_FUNC		// ID:�n�b�V���e�[�u��-0
//#define TEST_INSERT_IS_CONST		// ID:�n�b�V���e�[�u��-18
//#define TEST_ERASE_IS_CONST		// ID:�n�b�V���e�[�u��-26

/** �n�b�V���e�[�u���̎蓮�e�X�g�p�t�B�N�X�`���N���X */
class HashTableManualTest : public ::testing::Test
{
protected:
	const HashTable<std::string, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> m_HashTable; //!< �R���X�g�n�b�V���e�[�u��
};