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


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
//----- �}�N����`

// ���R���p�C�����ʂ�Ȃ���ΐ���
//#define TEST_QUICKSORT_NOT_EXPECTED_KEY	// ID:���X�g-7
//#define TEST_QUICKSORT_IS_CONST			// ID:���X�g-8


/** �N�C�b�N�\�[�g���\�b�h�̃e�X�g�p�t�B�N�X�`���N���X */
class ListQuickSortTest : public ::testing::TestWithParam<bool>
{
protected:
	virtual void SetUp()
	{
		m_CmpFunc = [](bool isAsk, const int& a, const int& b) { return isAsk ? a < b : a > b; };
	}


protected:
	List<int> m_List;
	bool(*m_CmpFunc)(bool, const int&, const int&);
};