/**
 * @file IteratorTest.cpp
 * @breif �e���v���[�g�C�e���[�^�̃e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.143
 */

 //----- �C���N���[�h
#include "IteratorTest.h"


//=============================================================================
// �C�e���[�^�̎w���v�f�擾�e�X�g
//=============================================================================
/**
 * @breif	���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̎擾�e�X�g
 * @deteils	ID:�C�e���[�^-0
 */
TEST(GetIteratorDeathTest, TestGetIteratorWhenNotRefCall)
{
	// �C�e���[�^ver
	{
		Iterator<int> itr;
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr;
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
}
/**
 * @breif	�C�e���[�^����擾�����v�f�ɑ΂��Ēl�̑�����s���邩���e�X�g
 * @deteils	ID:�C�e���[�^-1
 */
TEST(GetIteratorDeathTest, TestGetIteratorToAssign)
{
	List<int> list;
	Iterator<int> itr;
	// ���X�g�̗v�f������
	itr = list.GetBegin();
	ASSERT_TRUE(list.Insert(itr, 10));
	// ���X�g����v�f���w���C�e���[�^���擾���A�C�e���[�^����l����
	itr = list.GetBegin();
	*itr = 100;
	EXPECT_EQ(*itr, 100) << "�C�e���[�^����̑�����s";
}
/**
 * @breif	���X�g����̍ۂ̐擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-3
 */
TEST(GetIteratorDeathTest, TestGetIteratorWhenEmptyToHeadCall)
{
	List<int> list;
	// �C�e���[�^ver
	{
		Iterator<int> itr = list.GetBegin();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = list.GetConstBegin();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
}
/**
 * @breif	�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-4
 */
TEST(GetIteratorDeathTest, TestGetIteratorTailToCall)
{
	List<int> list;
	// �C�e���[�^ver
	{
		Iterator<int> itr = list.GetEnd();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = list.GetConstEnd();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
}
//=============================================================================
// �C�e���[�^�����X�g�̖����Ɍ����Ĉ�i�߂鋓���e�X�g
//=============================================================================
/**
 * @breif	���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^�𖖔��Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-5
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementWhenNotRef)
{
	Iterator<int> itr;
	ConstIterator<int> constItr;
	EXPECT_DEATH(++itr, "Assertion failed.*");
	EXPECT_DEATH(++constItr, "Assertion failed.*");
}
/**
 * @breif	���X�g����̍ۂ̐擪�C�e���[�^�𖖔��Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-6
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementWhenEmptyForHead)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ConstIterator<int> constItr = list.GetConstBegin();
	EXPECT_DEATH(itr++, "Assertion failed.*");
	EXPECT_DEATH(constItr++, "Assertion failed.*");
}
/**
 * @breif	�����C�e���[�^�ɑ΂��Ė����Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-7
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementForTail)
{
	List<int> list;
	Iterator<int> itr = list.GetEnd();
	ConstIterator<int> constItr = list.GetConstEnd();
	EXPECT_DEATH(itr++, "Assertion failed.*");
	EXPECT_DEATH(constItr++, "Assertion failed.*");
}
/**
 * @breif	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɖ����Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-8
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrement)
{
	int checkDatas[] = { 0,1 };
	// �C�e���[�^ver
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		Iterator<int> endItr = m_Lists[0].GetEnd();
		for (int i = 0; itr != endItr; ++i, ++itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "�����֐i�߂��C�e���[�^���w���v�f���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ConstIterator<int> endItr = m_Lists[0].GetConstEnd();
		for (int i = 0; itr != endItr; ++i, ++itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "�����֐i�߂��R���X�g�C�e���[�^���w���v�f���قȂ�܂�";
	}
}
/**
 * @breif	�O�u�C���N�������g���s�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-9
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementPrefix)
{
	int checkDatas[] = { 0,1 };
	// �C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*++itr, checkDatas[1]) << "�C�e���[�^�̑O�u�C���N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[1]) << "�C�e���[�^�̑O�u�C���N�������g���s��̒l���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*++itr, checkDatas[1]) << "�R���X�g�C�e���[�^�̑O�u�C���N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[1]) << "�R���X�g�C�e���[�^�̑O�u�C���N�������g���s��̒l���قȂ�܂�";
	}
}
/**
 * @breif	��u�C���N�������g���s�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-10
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementPostfix)
{
	int checkDatas[] = { 0,1 };
	// �C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*itr++, checkDatas[0]) << "�C�e���[�^�̌�u�C���N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[1]) << "�C�e���[�^�̌�u�C���N�������g���s��̒l���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*itr++, checkDatas[0]) << "�R���X�g�C�e���[�^�̌�u�C���N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[1]) << "�R���X�g�C�e���[�^�̌�u�C���N�������g���s��̒l���قȂ�܂�";
	}
}
//=============================================================================
// �C�e���[�^�����X�g�̐擪�Ɍ����Ĉ�i�߂鋓���e�X�g
//=============================================================================
/**
 * @breif	���X�g�̎Q�Ƃ��Ȃ���ԂŃC�e���[�^��擪�Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-11
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementWhenNotRef)
{
	Iterator<int> itr;
	ConstIterator<int> constItr;
	EXPECT_DEATH(itr--, "Assertion failed.*");
	EXPECT_DEATH(constItr--, "Assertion failed.*");
}
/**
 * @breif	���X�g����̍ۂ̖����C�e���[�^��擪�Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-12
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementWhenEmptyForTail)
{
	List<int> list;
	Iterator<int> itr = list.GetEnd();
	ConstIterator<int> constItr = list.GetConstEnd();
	EXPECT_DEATH(itr--, "Assertion failed.*");
	EXPECT_DEATH(constItr--, "Assertion failed.*");
}
/**
 * @breif	�擪�C�e���[�^�ɑ΂��Đ擪�Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-13
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementForHead)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ConstIterator<int> constItr = list.GetConstBegin();
	EXPECT_DEATH(itr--, "Assertion failed.*");
	EXPECT_DEATH(constItr--, "Assertion failed.*");
}
/**
 * @breif	���X�g�ɓ�ȏ�̗v�f������ꍇ�ɐ擪�Ɍ����Đi�߂��ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-14
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrement)
{
	int checkDatas[] = { 1,0 };
	// �C�e���[�^ver
	{
		Iterator<int> itr = m_Lists[0].GetEnd();
		Iterator<int> endItr = m_Lists[0].GetBegin();
		--itr;
		for (int i = 0; itr != endItr; ++i, --itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "�擪�֐i�߂��C�e���[�^���w���v�f���قȂ�܂�";
		EXPECT_EQ(*itr, *endItr) << "�擪�֐i�߂��C�e���[�^���w���v�f���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		ConstIterator<int> endItr = m_Lists[0].GetConstBegin();
		--itr;
		for (int i = 0; itr != endItr; ++i, --itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "�擪�֐i�߂��R���X�g�C�e���[�^���w���v�f���قȂ�܂�";
		EXPECT_EQ(*itr, *endItr) << "�擪�֐i�߂��R���X�g�C�e���[�^���w���v�f���قȂ�܂�";
	}
}
/**
 * @breif	�O�u�f�N�������g���s�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-15
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementPrefix)
{
	int checkDatas[] = { 0,1 };
	// �C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*--itr, checkDatas[0]) << "�C�e���[�^�̌�u�f�N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[0]) << "�C�e���[�^�̌�u�f�N�������g���s��̒l���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*--itr, checkDatas[0]) << "�R���X�g�C�e���[�^�̌�u�f�N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[0]) << "�R���X�g�C�e���[�^�̌�u�f�N�������g���s��̒l���قȂ�܂�";
	}
}
/**
 * @breif	��u�f�N�������g���s�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-16
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementPostfix)
{
	int checkDatas[] = { 0,1 };
	// �C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*itr--, checkDatas[1]) << "�C�e���[�^�̌�u�f�N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[0]) << "�C�e���[�^�̌�u�f�N�������g���s��̒l���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*itr--, checkDatas[1]) << "�R���X�g�C�e���[�^�̌�u�f�N�������g�Ăяo�����̒l���قȂ�܂�";
		EXPECT_EQ(*itr, checkDatas[0]) << "�R���X�g�C�e���[�^�̌�u�f�N�������g���s��̒l���قȂ�܂�";
	}
}
//=============================================================================
// �C�e���[�^�̃R�s�[���s�����ۂ̋����e�X�g
//=============================================================================
/**
 * @breif	�C�e���[�^�̃R�s�[�R���X�g���N�^��̒l���R�s�[���Ɠ��������e�X�g
 * @deteils	ID:�C�e���[�^-18
 */
TEST(IteratorCopyConstructerTest, TestIteratorCopyConstructerEqual)
{
	// �C�e���[�^ver
	{
		Iterator<int> itr;
		Iterator<int> copyItr(itr);
		EXPECT_EQ(itr, copyItr) << "�R�s�[�R���X�g���N�^��̃C�e���[�^�ƃR�s�[���̒l���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr;
		ConstIterator<int> copyItr(itr);
		EXPECT_EQ(itr, copyItr) << "�R�s�[�R���X�g���N�^��̃R���X�g�C�e���[�^�ƃR�s�[���̒l���قȂ�܂�";
	}
}
//=============================================================================
// �C�e���[�^�̑�����s�����ۂ̋����e�X�g
//=============================================================================
/**
 * @breif	�����̒l���R�s�[���Ɠ��������e�X�g
 * @deteils	ID:�C�e���[�^-20
 */
TEST(IteratorAssignTest, TestIteratorAssignEqual)
{
	// �C�e���[�^ver
	{
		Iterator<int> itr;
		Iterator<int> copyItr;
		copyItr = itr;
		EXPECT_EQ(itr, copyItr) << "�����̃C�e���[�^�ƃR�s�[���̒l���قȂ�܂�";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr;
		ConstIterator<int> copyItr;
		copyItr = itr;
		EXPECT_EQ(itr, copyItr) << "�����̃R���X�g�C�e���[�^�ƃR�s�[���̒l���قȂ�܂�";
	}
}
//=============================================================================
// �񂤂̃C�e���[�^������̂��̂ł��邩������r�e�X�g
//=============================================================================
/**
 * @breif	�󃊃X�g���̐擪�C�e���[�^�Ɩ����C�e���[�^�̔�r�������ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-21
 */
TEST(IteratorEqualTest, TestIteratorEqualHeadAndTail)
{
	List<int> list;
	EXPECT_TRUE(list.GetBegin() == list.GetEnd()) << "�󃊃X�g���̐擪�Ɩ����C�e���[�^���قȂ�܂�";
	EXPECT_TRUE(list.GetConstBegin() == list.GetConstEnd()) << "�󃊃X�g���̐擪�Ɩ����R���X�g�C�e���[�^���قȂ�܂�";
}
/**
 * @breif	����̃C�e���[�^���r�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-22
 */
TEST(IteratorEqualTest, TestIteratorEqualSame)
{
	// �C�e���[�^ver
	{
		Iterator<int> itr;
		EXPECT_TRUE(itr == itr) << "����C�e���[�^�𓙉���r�������ʁA�Ⴄ���̂Ɣ��肳��܂���";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr;
		EXPECT_TRUE(itr == itr) << "����R���X�g�C�e���[�^�𓙉���r�������ʁA�Ⴄ���̂Ɣ��肳��܂���";
	}
}
/**
 *@breif	�قȂ�C�e���[�^���r�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-23
 */
TEST(IteratorEqualTest, TestIteratorEqualOther)
{
	List<int> list1;
	List<int> list2;
	// �C�e���[�^ver
	{
		Iterator<int> itr1 = list1.GetBegin();
		Iterator<int> itr2 = list2.GetBegin();
		EXPECT_FALSE(itr1 == itr2) << "�قȂ�C�e���[�^�𓙉���r�������ʁA�������̂Ɣ��肳��܂���";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr1 = list1.GetConstBegin();
		ConstIterator<int> itr2 = list2.GetConstBegin();
		EXPECT_FALSE(itr1 == itr2) << "�قȂ�R���X�g�C�e���[�^�𓙉���r�������ʁA�������̂Ɣ��肳��܂���";
	}
}
//=============================================================================
// �񂤂̃C�e���[�^���قȂ���̂ł��邩�񓙉���r�e�X�g
//=============================================================================
/**
 * @breif	�󃊃X�g���̐擪�C�e���[�^�Ɩ����C�e���[�^�̔�r�������ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-24
 */
TEST(IteratorNotEqualTest, TestIteratorNotEqualHeadAndTail)
{
	List<int> list;
	EXPECT_FALSE(list.GetBegin() != list.GetEnd()) << "�󃊃X�g���̐擪�Ɩ����C�e���[�^���قȂ�܂�";
	EXPECT_FALSE(list.GetConstBegin() != list.GetConstEnd()) << "�󃊃X�g���̐擪�Ɩ����R���X�g�C�e���[�^���قȂ�܂�";
}
/**
 * @breif	����̃C�e���[�^���r�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-25
 */
TEST(IteratorNotEqualTest, TestIteratorNotEqualSame)
{
	// �C�e���[�^ver
	{
		Iterator<int> itr;
		EXPECT_FALSE(itr != itr) << "����C�e���[�^��񓙉���r�������ʁA�Ⴄ���̂Ɣ��肳��܂���";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr;
		EXPECT_FALSE(itr != itr) << "����R���X�g�C�e���[�^��񓙉���r�������ʁA�Ⴄ���̂Ɣ��肳��܂���";
	}
}
/**
 *@breif	�قȂ�C�e���[�^���r�����ۂ̋����e�X�g
 * @deteils	ID:�C�e���[�^-26
 */
TEST(IteratorNotEqualTest, TestIteratorNotEqualOther)
{
	List<int> list1;
	List<int> list2;
	// �C�e���[�^ver
	{
		Iterator<int> itr1 = list1.GetBegin();
		Iterator<int> itr2 = list2.GetBegin();
		EXPECT_TRUE(itr1 != itr2) << "�قȂ�C�e���[�^��񓙉���r�������ʁA�������̂Ɣ��肳��܂���";
	}
	// �R���X�g�C�e���[�^ver
	{
		ConstIterator<int> itr1 = list1.GetConstBegin();
		ConstIterator<int> itr2 = list2.GetConstBegin();
		EXPECT_TRUE(itr1 != itr2) << "�قȂ�R���X�g�C�e���[�^��񓙉���r�������ʁA�������̂Ɣ��肳��܂���";
	}
}

