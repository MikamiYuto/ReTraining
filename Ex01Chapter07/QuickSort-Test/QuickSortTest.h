/**
 * @file QuickSortTest.h
 * @brief �N�C�b�N�\�[�g�̃e�X�g��`�t�@�C��(�蓮�e�X�g���܂�
 * @author MikamiYuto
 * @date 2021.10.15
 */
#pragma once


 //----- �C���N���[�h
#include "gtest/gtest.h"
#include "../QuickSort/List.h"
#include "../QuickSort/ScoreData.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
//----- �}�N����`

// ���R���p�C�����ʂ�Ȃ���ΐ���
//#define TEST_QUICKSORT_NOT_EXPECTED_KEY	// ID:���X�g-7
//#define TEST_QUICKSORT_IS_CONST			// ID:���X�g-8


/** �N�C�b�N�\�[�g���\�b�h�̃e�X�g�p�t�B�N�X�`���N���X */
class ListQuickSortTest : public ::testing::TestWithParam<bool(*)(const ScoreData&,const ScoreData&)>
{
protected:
	/**
	 * @brief �e�X�g�ԍ��̎擾
	 */
	int GetTestNumber()
	{
		auto testInfo = ::testing::UnitTest::GetInstance()->current_test_info();
		const std::string& testName = testInfo->name();
		return std::stoi(testName.c_str() + testName.rfind("/") + 1);
	}

protected:
	List<ScoreData> m_List;
};