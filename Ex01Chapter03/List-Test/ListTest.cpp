/**
 * @file ListTest.cpp
 * @breif �e���v���[�g���X�g�N���X�̃e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.12
 */


//----- �C���N���[�h
#include "ListTest.h"


//=============================================================================
// �f�[�^���̎擾�e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ꍇ�̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-0
 */
TEST_F(ListGetDataNumTest, TestGetDataNumWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(0, list.GetCount()) << "�󃊃X�g����̃f�[�^���擾���s";
}
/**
 * @breif	���X�g�����ւ̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-1
 */
TEST_F(ListGetDataNumTest, TestGetDataNumAfterPush)
{
	List<int> list;
	Iterator<int> itr = list.GetEnd();
	ASSERT_TRUE(list.Insert(itr, 10));
	EXPECT_EQ(1, list.GetCount()) << "���X�g�����֑}����̃f�[�^���擾���s";
}
/**
 * @breif	���X�g�����ւ̑}�������s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-2
 */
TEST_F(ListGetDataNumTest, TestGetDataNumAfterPushFailed)
{
	// "�����ւ�"�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
	//List<int> list;
	//Iterator<int> itr = list.GetEnd();
	//ASSERT_FALSE(list.Insert(itr, 10));
	//EXPECT_EQ(1, list.GetCount()) << "���X�g�����֑}�����s��̃f�[�^���擾���s";
}
/**
 * @breif	�f�[�^�̑}�����s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-3
 */
TEST_F(ListGetDataNumTest, TestGetDataNumPush)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ASSERT_TRUE(list.Insert(itr, 10));
	EXPECT_EQ(1, list.GetCount()) << "���X�g�֗v�f�}����̃f�[�^���擾���s";
}
/**
 * @breif	�f�[�^�̑}���Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-4
 */
TEST_F(ListGetDataNumTest, TestGetDataNumPushFailed)
{
	// "�}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
	//List<int> list;
	//Iterator<int> itr = list.GetBegin();
	//ASSERT_TRUE(list.Insert(itr, 10));
	//EXPECT_EQ(1, list.GetCount()) << "���X�g�֗v�f�}�����s��̃f�[�^���擾���s";
}
/**
 * @breif	�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-5
 */
TEST_F(ListGetDataNumTest, TestGetDataNumErase)
{
	Iterator<int> itr = m_Lists[0].GetBegin();
	ASSERT_TRUE(m_Lists[0].Erase(itr));
	EXPECT_EQ(1, m_Lists[0].GetCount()) << "���X�g�̗v�f�폜��̃f�[�^���擾���s";
}
/**
 * @breif	�f�[�^�̍폜�Ɏ��s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-6
 */
TEST_F(ListGetDataNumTest, TestGetDataNumEraseFailed)
{
	Iterator<int> itr = m_Lists[1].GetBegin();
	// �s���ȃC�e���[�^��ݒ�
	ASSERT_FALSE(m_Lists[0].Erase(itr));
	EXPECT_EQ(2, m_Lists[0].GetCount()) << "���X�g�̗v�f�폜���s���̃f�[�^���擾���s";
}
/**
 * @breif	���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̃f�[�^���̎擾�e�X�g
 * @deteils	ID:���X�g-7
 */
TEST_F(ListGetDataNumTest, TestGetDataNumWhenEmptyAndErase)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ASSERT_FALSE(list.Erase(itr));
	EXPECT_EQ(0, list.GetCount()) << "�󃊃X�g�ɑ΂��ėv�f�폜���s������̃f�[�^���擾���s";
}
//=============================================================================
// �f�[�^�̑}���e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ꍇ�ɁA�f�[�^��ǉ������ۂ̋����e�X�g
 * @deteils	ID:���X�g-9
 */
TEST_F(ListPushTest, TestPushToEmpty)
{
	// �󃊃X�g�ɐ擪�v�f�}��
	{
		List<int> list;
		Iterator<int> itr = list.GetBegin();
		EXPECT_TRUE(list.Insert(itr, 10)) << "�󃊃X�g�̐擪�֗v�f�}�����s";
		// �v�f�̃`�F�b�N
		itr = list.GetBegin();
		EXPECT_EQ(*itr, 10);
	}
	// �󃊃X�g�ɖ����v�f�}��
	{
		List<int> list;
		Iterator<int> itr = list.GetEnd();
		EXPECT_TRUE(list.Insert(itr, 10)) << "�󃊃X�g�̖����֗v�f�}�����s";
		// �v�f�̃`�F�b�N
		itr = list.GetBegin();
		EXPECT_EQ(*itr, 10);
	}
}
/**
 * @breif	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���đ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-10
 */
TEST_F(ListPushTest, TestPushToHead)
{
	Iterator<int> itr = m_Lists[0].GetBegin();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɐ擪�֗v�f�}�����s";
	// �v�f�ʒu�̃`�F�b�N
	int checkDatas[] = { 10,0,1 };
	itr = m_Lists[0].GetBegin();
	for (int i = 0; i < 3; ++i, ++itr)
		EXPECT_EQ(*itr, checkDatas[i]) << "���X�g�ɕ����v�f�����݂��鎞�ɐ擪�֗v�f�}����A���X�g�̗v�f���ɖ�肠��";
}
/**
 * @breif	���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���đ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-11
 */
TEST_F(ListPushTest, TestPushToTail)
{
	Iterator<int> itr = m_Lists[0].GetEnd();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɖ����֗v�f�}�����s";
	// �v�f�ʒu�̃`�F�b�N
	int checkDatas[] = { 0,1,10 };
	itr = m_Lists[0].GetBegin();
	for (int i = 0; i < 3; ++i, ++itr)
		EXPECT_EQ(*itr, checkDatas[i]) << "���X�g�ɕ����v�f�����݂��鎞�ɖ����֗v�f�}����A���X�g�̗v�f���ɖ�肠��";
}
/**
 * @breif	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-12
 */
TEST_F(ListPushTest, TestPushToBetween)
{
	// �擪�A�����A�����ʒu�ւ��ꂼ��v�f��}��
	Iterator<int> itr = m_Lists[0].GetBegin();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɁA�擪�ւ̑}�����s";
	itr = m_Lists[1].GetBegin();
	++itr;
	EXPECT_TRUE(m_Lists[1].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɁA���Ԃւ̑}�����s";
	itr = m_Lists[2].GetEnd();
	EXPECT_TRUE(m_Lists[2].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɁA�����ւ̑}�����s";
	// �v�f�ʒu�̊m�F�p
	int checkDatas[][3] =
	{
		{ 10,  0,  1, }, // �擪�֑}���������X�g�v�f��
		{  0, 10,  1, }, // �����֑}���������X�g�v�f��
		{  0,  1, 10, }, // �����֑}���������X�g�v�f��
	};
	// �擪�A�����A�������ꂼ��̗v�f���������������m�F
	for (int i = 0; i < 3; ++i)
	{
		itr = m_Lists[i].GetBegin();
		for (int j = 0; j < 3; ++j, ++itr)
			EXPECT_EQ(*itr, checkDatas[i][j]) << "���X�g�ɕ����v�f�����݂��鎞�ɗv�f�}����A�i�[�ϗv�f�ɕs�����";
	}
}
/**
 * @breif	ConstIterator���w�肵�đ}�����s�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-13
 */
TEST_F(ListPushTest, TestPushToConstIterator)
{
	// �擪�A�����A�����ʒu�ւ��ꂼ��v�f��}��
	ConstIterator<int> itr = m_Lists[0].GetConstBegin();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɁA�擪�ւ̑}�����s(�R���X�g�C�e���[�^ver)";;
	itr = m_Lists[1].GetConstBegin();
	++itr;
	EXPECT_TRUE(m_Lists[1].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɁA���Ԃւ̑}�����s(�R���X�g�C�e���[�^ver)";
	itr = m_Lists[2].GetConstEnd();
	EXPECT_TRUE(m_Lists[2].Insert(itr, 10)) << "���X�g�ɕ����v�f�����݂��鎞�ɁA�����ւ̑}�����s(�R���X�g�C�e���[�^ver)";
	// �v�f�ʒu�̊m�F�p
	int checkDatas[][3] =
	{
		{ 10,  0,  1, }, // �擪�֑}���������X�g�v�f��
		{  0, 10,  1, }, // �����֑}���������X�g�v�f��
		{  0,  1, 10, }, // �����֑}���������X�g�v�f��
	};
	// �擪�A�����A�������ꂼ��̗v�f���������������m�F
	for (int i = 0; i < 3; ++i)
	{
		itr = m_Lists[i].GetConstBegin();
		for (int j = 0; j < 3; ++j, ++itr)
			EXPECT_EQ(*itr, checkDatas[i][j]) << "���X�g�ɕ����v�f�����݂��鎞�ɗv�f�}����A�i�[�ϗv�f�ɕs�����(�R���X�g�C�e���[�^ver)";
	}
}
/**
 * @breif	�s���ȃC�e���[�^��n���đ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-14
 */
TEST_F(ListPushTest, TestPushToErrorIterator)
{
	// ���X�g�ւ̎Q�Ƃ��Ȃ��̃C�e���[�^�ő}�����������ꍇ
	{
		List<int> list;
		Iterator<int> itr;
		EXPECT_FALSE(list.Insert(itr, 10)) << "�s���C�e���[�^(���Q�ƃC�e���[�^)�ł̑}������";
	}
	// �ʂ̃��X�g�̃C�e���[�^�ő}�����������ꍇ
	{
		List<int> list;
		List<int> listOther;
		Iterator<int> itr = listOther.GetBegin();
		EXPECT_FALSE(list.Insert(itr, 10)) << "�s���C�e���[�^(�ʃ��X�g�Q�ƃC�e���[�^)�ł̑}������";
	}
}
//=============================================================================
// �f�[�^�̍폜�e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-16
 */
TEST_F(ListEraseTest, TestEraseToEmpty)
{
	// �󃊃X�g�̐擪�폜
	{
		List<int> list;
		Iterator<int> itr = list.GetBegin();
		EXPECT_FALSE(list.Erase(itr)) << "�󃊃X�g�ւ̐擪�C�e���[�^�ł̍폜����";
	}
	// �󃊃X�g�̖����폜
	{
		List<int> list;
		Iterator<int> itr = list.GetEnd();
		EXPECT_FALSE(list.Erase(itr)) << "�󃊃X�g�ւ̖����C�e���[�^�ł̍폜����";
	}
}
/**
 * @breif	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���č폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-17
 */
TEST_F(ListEraseTest, TestEraseToHead)
{
	// �擪�폜
	Iterator<int> itr = m_Lists[0].GetBegin();
	EXPECT_TRUE(m_Lists[0].Erase(itr)) << "���X�g�̗v�f���ݎ��ɁA�擪�C�e���[�^�ł̍폜���s";
	// ���X�g���v�f�ʒu�`�F�b�N
	itr = m_Lists[0].GetBegin();
	EXPECT_EQ(*itr, 1) << "���X�g�ɕ����v�f�����݂��A�擪�C�e���[�^�ō폜�����ہA���X�g���̗v�f�ɃG���[";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "���X�g�ɕ����v�f�����݂��A�擪�C�e���[�^�ō폜�����ہA���X�g���̗v�f�ɃG���[";
}
/**
 * @breif	���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���č폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-18
 */
TEST_F(ListEraseTest, TestEraseToTail)
{
	// �����폜(�����N����Ȃ��͂�
	Iterator<int> itr = m_Lists[0].GetEnd();
	EXPECT_FALSE(m_Lists[0].Erase(itr)) << "���X�g�̗v�f���ݎ��ɁA�����C�e���[�^�ł̍폜����";
	// ���X�g���v�f�ʒu�`�F�b�N
	itr = m_Lists[0].GetBegin();
	EXPECT_EQ(*itr, 0) << "���X�g�ɕ����v�f�����݂��A�����C�e���[�^�ō폜�����ہA���X�g���̗v�f�ɃG���[";
	++itr;
	EXPECT_EQ(*itr, 1) << "���X�g�ɕ����v�f�����݂��A�����C�e���[�^�ō폜�����ہA���X�g���̗v�f�ɃG���[";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "���X�g�ɕ����v�f�����݂��A�����C�e���[�^�ō폜�����ہA���X�g���̗v�f�ɃG���[";
}
/**
 * @breif	���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-19
 */
TEST_F(ListEraseTest, TestEraseToBetween)
{
	// ���ԗv�f���폜
	Iterator<int> itr = m_Lists[0].GetBegin();
	++itr;
	EXPECT_TRUE(m_Lists[0].Erase(itr)) << "���X�g�v�f���ݎ��A���ԃC�e���[�^�ł̍폜���s";
	// �v�f�ʒu�̊m�F(�擪�ɂ̂݃f�[�^������͂�
	itr = m_Lists[0].GetBegin();
	EXPECT_EQ(*itr, 0) << "���ԃC�e���[�^�ł̗v�f�폜��A�i�[�ϗv�f�ɕs�����";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "���ԃC�e���[�^�ł̗v�f�폜��A�����C�e���[�^�擾�Ɏ��s";
}
/**
 * @breif	ConstIterator���w�肵�č폜���s�����ۂ̋����e�X�g
 * @deteils	ID:���X�g-20
 */
TEST_F(ListEraseTest, TestEraseToConstIterator)
{
	// ���ԗv�f���폜
	ConstIterator<int> itr = m_Lists[0].GetConstBegin();
	++itr;
	EXPECT_TRUE(m_Lists[0].Erase(itr)) << "���X�g�v�f���ݎ��A���ԃR���X�g�C�e���[�^�ł̍폜���s";
	// �v�f�ʒu�̊m�F(�擪�ɂ̂݃f�[�^������͂�
	itr = m_Lists[0].GetConstBegin();
	EXPECT_EQ(*itr, 0) << "���ԃR���X�g�C�e���[�^�ł̗v�f�폜��A�i�[�ϗv�f�ɕs�����";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "���ԃR���X�g�C�e���[�^�ł̗v�f�폜��A�����R���X�g�C�e���[�^�擾�Ɏ��s";
}
/**
 * @breif	�s���ȃC�e���[�^��n���đ}�������ۂ̋����e�X�g
 * @deteils	ID:���X�g-21
 */
TEST_F(ListEraseTest, TestEraseToErrorIterator)
{
	// ���X�g�ւ̎Q�Ƃ��Ȃ��̃C�e���[�^�ō폜���������ꍇ
	{
		List<int> list;
		Iterator<int> itr = list.GetBegin();
		EXPECT_FALSE(list.Erase(itr)) << "�s���C�e���[�^(���Q��)�ł̗v�f�폜����";
	}
	// �ʂ̃��X�g�̃C�e���[�^�ō폜���������ꍇ
	{
		List<int> list;
		List<int> listOther;
		Iterator<int> itr = listOther.GetBegin();
		EXPECT_FALSE(listOther.Erase(itr)) << "�s���C�e���[�^(�ʃ��X�g�Q��)�ł̗v�f�폜����";
	}
}
//=============================================================================
// �擪�C�e���[�^�̎擾�e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ۂ̐擪�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-23
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetBegin(), list.GetEnd()) << "�󃊃X�g���A�擪�C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɗv�f�������ꍇ�̐擪�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-24
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorWhenOnly)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	// �v�f����̃��X�g������
	ASSERT_TRUE(list.Insert(itr, 10));
	// �擪�C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*list.GetBegin(), 10) << "���X�g�ɗv�f������ݎ��A�擪�C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɓ�ȏ�v�f������ꍇ�̐擪�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-25
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIterator)
{
	// �擪�C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*m_Lists[0].GetBegin(), 0) << "���X�g�ɕ����v�f�����ݎ��A�擪�C�e���[�^�̎擾���s";
}
/**
 * @breif	�f�[�^��}�������ۂ̐擪�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-26
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorAfterPush)
{
	// �擪�A���ԁA�����ւ��ꂼ��}��
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// �擪�A�����A�����֗v�f�}��������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 10,0,0 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�}����̐擪�C�e���[�^�擾�e�X�g
		EXPECT_EQ(*m_Lists[i].GetBegin(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�}����A�擪�C�e���[�^�̎擾���s";
	}
}
/**
 * @breif	�f�[�^���폜�����ۂ̐擪�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-27
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorAfterErase)
{
	// �擪�A���ԁA���������ꂼ��폜
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// �擪�A�����A�����̗v�f�폜������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 1,0,0 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�폜��̐擪�C�e���[�^�擾�e�X�g
		EXPECT_EQ(*m_Lists[i].GetBegin(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�폜��A�擪�C�e���[�^�̎擾���s";
	}
}
//=============================================================================
// �擪�R���X�g�C�e���[�^�̎擾�e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ۂ̐擪�R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-29
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetConstBegin(), list.GetConstEnd()) << "�󃊃X�g���A�擪�R���X�g�C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɗv�f�������ꍇ�̐擪�R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-30
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorWhenOnly)
{
	List<int> list;
	ConstIterator<int> itr = list.GetConstBegin();
	// �v�f����̃��X�g������
	ASSERT_TRUE(list.Insert(itr, 10));
	// �擪�R���X�g�C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*list.GetConstBegin(), 10) << "���X�g�ɗv�f������ݎ��A�擪�C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɓ�ȏ�v�f������ꍇ�̐擪�R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-31
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIterator)
{
	// �擪�R���X�g�C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*m_Lists[0].GetConstBegin(), 0) << "���X�g�ɕ����v�f�����ݎ��A�擪�R���X�g�C�e���[�^�̎擾���s";
}
/**
 * @breif	�f�[�^��}�������ۂ̐擪�R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-32
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorAfterPush)
{
	// �擪�A���ԁA�����ւ��ꂼ��}��
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// �擪�A�����A�����֗v�f�}��������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 10,0,0 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�}����̐擪�R���X�g�C�e���[�^�擾�e�X�g
		EXPECT_EQ(*m_Lists[i].GetConstBegin(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�}����A�擪�R���X�g�C�e���[�^�̎擾���s";
	}
}
/**
 * @breif	�f�[�^���폜�����ۂ̐擪�R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-33
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorAfterErase)
{
	// �擪�A���ԁA���������ꂼ��폜
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// �擪�A�����A�����̗v�f�폜������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 1,0,0 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�폜��̐擪�R���X�g�C�e���[�^�擾�e�X�g
		EXPECT_EQ(*m_Lists[i].GetConstBegin(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�폜��A�擪�R���X�g�C�e���[�^�̎擾���s";
	}
}
//=============================================================================
// �����C�e���[�^�̎擾�e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ۂ̖����C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-35
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetEnd(), list.GetBegin()) << "�󃊃X�g���A�����C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɗv�f�������ꍇ�̖����C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-36
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorWhenOnly)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	// �v�f����̃��X�g������
	ASSERT_TRUE(list.Insert(itr, 10));
	// �����C�e���[�^���m�F
	EXPECT_EQ(*--list.GetEnd(), 10) << "���X�g�ɗv�f������ݎ��A�����C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɓ�ȏ�v�f������ꍇ�̖����C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-37
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIterator)
{
	// �����C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*--m_Lists[0].GetEnd(), 1) << "���X�g�ɕ����v�f�����ݎ��A�����C�e���[�^�̎擾���s";
}
/**
 * @breif	�f�[�^��}�������ۂ̖����C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-38
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorAfterPush)
{
	// �擪�A���ԁA�����ւ��ꂼ��}��
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// �擪�A�����A�����֗v�f�}��������̃��X�g�̖����v�f�����l
	int checkDatas[] = { 1,1,10 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�}����̖����C�e���[�^�擾�e�X�g
		EXPECT_EQ(*--m_Lists[i].GetEnd(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�}����A�����C�e���[�^�̎擾���s";
	}
}
/**
 * @breif	�f�[�^���폜�����ۂ̖����C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-39
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorAfterErase)
{
	// �擪�A���ԁA���������ꂼ��폜
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// �擪�A�����A�����̗v�f�폜������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 1,0,1 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�폜��̖����C�e���[�^�擾�e�X�g
		EXPECT_EQ(*--m_Lists[i].GetEnd(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�폜��A�����C�e���[�^�̎擾���s";
	}
}
//=============================================================================
// �����R���X�g�C�e���[�^�̎擾�e�X�g
//=============================================================================
/**
 * @breif	���X�g����ł���ۂ̖����R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-41
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetConstEnd(), list.GetConstBegin()) << "�󃊃X�g���A�����R���X�g�C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɗv�f�������ꍇ�̖����R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-42
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorWhenOnly)
{
	List<int> list;
	ConstIterator<int> itr = list.GetConstBegin();
	// �v�f����̃��X�g������
	ASSERT_TRUE(list.Insert(itr, 10));
	// �����R���X�g�C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*--list.GetConstEnd(), 10) << "���X�g�ɗv�f������ݎ��A�����C�e���[�^�̎擾���s";
}
/**
 * @breif	���X�g�ɓ�ȏ�v�f������ꍇ�̖����R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-43
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIterator)
{
	// �����R���X�g�C�e���[�^���w���v�f���m�F
	EXPECT_EQ(*--m_Lists[0].GetConstEnd(), 1) << "���X�g�ɕ����v�f�����ݎ��A�����R���X�g�C�e���[�^�̎擾���s";
}
/**
 * @breif	�f�[�^��}�������ۂ̖����R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-44
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorAfterPush)
{
	// �擪�A���ԁA�����ւ��ꂼ��}��
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// �擪�A�����A�����֗v�f�}��������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 1,1,10 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�}����̖����R���X�g�C�e���[�^�擾�e�X�g
		EXPECT_EQ(*--m_Lists[i].GetConstEnd(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�}����A�����R���X�g�C�e���[�^�̎擾���s";
	}
}
/**
 * @breif	�f�[�^���폜�����ۂ̖����R���X�g�C�e���[�^�̎擾�e�X�g
 * @deteils	ID:���X�g-45
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorAfterErase)
{
	// �擪�A���ԁA���������ꂼ��폜
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// �擪�A�����A�����̗v�f�폜������̃��X�g�̐擪�v�f�����l
	int checkDatas[] = { 1,0,1 };
	for (int i = 0; i < 3; ++i)
	{// �v�f�폜��̖����R���X�g�C�e���[�^�擾�e�X�g
		EXPECT_EQ(*--m_Lists[i].GetConstEnd(), checkDatas[i]) << "�����v�f�������X�g�ւ̗v�f�폜��A�����R���X�g�C�e���[�^�̎擾���s";
	}
}
