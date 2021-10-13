/**
 * @file ListTest.h
 * @breif �e���v���[�g���X�g�N���X�̃e�X�g��`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.12
 */
#pragma once



//----- �C���N���[�h
#include "gtest/gtest.h"
#include "../List/List.h"
#include "../List/Iterator.h"


/** ���X�g�e�X�g�p�t�B�N�X�`���̃x�[�X�N���X */
class BaseListTest : public ::testing::Test
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
/** ���X�g�̃f�[�^���擾�e�X�g�p�t�B�N�X�`���N���X */
class ListGetDataNumTest : public BaseListTest {};
/** ���X�g�̑}�����̋����e�X�g�p�t�B�N�X�`���N���X */
class ListPushTest : public BaseListTest {};
/** ���X�g�̍폜���̋����e�X�g�p�t�B�N�X�`���N���X */
class ListEraseTest : public BaseListTest {};
/** ���X�g�̐擪�C�e���[�^�擾�e�X�g�p�t�B�N�X�`���N���X */
class ListGetHeadIteratorTest : public BaseListTest {};
/** ���X�g�̐擪�R���X�g�C�e���[�^�擾�e�X�g�p�t�B�N�X�`���N���X */
class ListGetHeadConstIteratorTest : public BaseListTest {};
/** ���X�g�̖����C�e���[�^�擾�e�X�g�p�t�B�N�X�`���N���X */
class ListGetTailIteratorTest : public BaseListTest {};
/** ���X�g�̖����R���X�g�C�e���[�^�擾�e�X�g�p�t�B�N�X�`���N���X */
class ListGetTailConstIteratorTest : public BaseListTest {};
