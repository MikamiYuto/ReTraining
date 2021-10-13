/**
 * @file IteratorTest.h
 * @breif �e���v���[�g�C�e���[�^�N���X�̃e�X�g��`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


 //----- �C���N���[�h
#include "gtest/gtest.h"
#include "../List/List.h"
#include "../List/Iterator.h"


/** �C�e���[�^�e�X�g�p�t�B�N�X�`���̃x�[�X�N���X */
class BaseIteratorTest : public ::testing::Test
{
protected:
	/**
	 * @brief	������
	 * @details �e�e�X�g���ڂ̎��s�O�ɁA�����v�f�������X�g��p�ӂ���
	 */
	virtual void SetUp()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				Iterator<int> itr = m_Lists[i].GetEnd();
				m_Lists[i].Insert(itr, j);
			}
		}
	}

protected:
	List<int>	m_Lists[3];		//!< �����v�f�������X�g(�v�f��2,�e�v�f�͂��̗v�f�ʒu���l�Ƃ��Ċi�[
};
/** �C�e���[�^�����X�g�̖����Ɍ����Ĉ�i�߂鋓���e�X�g�p�t�B�N�X�`���N���X */
class IteratorIncrementTest : public BaseIteratorTest {};
/** �C�e���[�^�����X�g�̐擪�Ɍ����Ĉ�i�߂鋓���e�X�g�p�t�B�N�X�`���N���X */
class IteratorDecrementTest : public BaseIteratorTest {};
