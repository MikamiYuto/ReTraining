/**
 * @file ManualTest.cpp
 * @breif ���X�g�̎蓮�e�X�g�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.07
 */


//------ �C���N���[�h
#include "ManualTest.h"
#include "gtest/gtest.h"
#include "../List/List.h"
#include "../List/Iterator.h"


namespace ex01
{
	namespace chapter02
	{
		//--------------------------------------------------------------------------------
		// �R���p�C���֘A�蓮�e�X�g
		//--------------------------------------------------------------------------------
		/**
		 * @breif	�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
		 * @deteils	ID:���X�g-8(�蓮)
		 */
		TEST(ListManualTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_IS_CONST
			const List<int> list;
			EXPECT_EQ(0, list.GetCount());
#endif // TT_TEST_GET_DATA_NUM_IS_CONST
			SUCCEED();
		}
		/**
		 * @breif	���X�g�̃f�[�^�ǉ��ɂ��āA��const���ۏ؂���Ă��邩�̃e�X�g
		 * @deteils	ID:���X�g-15(�蓮)
		 */
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr = list.GetConstBegin();
			list.Insert(itr, 10);//�����ŃG���[
#endif // TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	���X�g�̃f�[�^�폜�ɂ��āA��const���ۏ؂���Ă��邩�̃e�X�g
		 * @deteils	ID:���X�g-22(�蓮)
		 */
		TEST(ListManualTest, TestEraseWhenConst)
		{
#if defined TT_TEST_ERASE_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr = list.GetConstBegin();
			list.Erase(itr);//�����ŃG���[
#endif// TT_TEST_ERASE_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�擪�C�e���[�^�̎擾�ǉ��ɂ��āA��const���ۏ؂���Ă��邩�̃e�X�g
		 * @deteils	ID:���X�g-28(�蓮)
		 */
		TEST(ListManualTest, TestGetHeadIteratorWhenConst)
		{
#if defined TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			const List<int> list;
			Iterator<int> itr;
			itr = list.GetBegin(); // �����ŃG���[
#endif// TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�擪�R���X�g�C�e���[�^�̎擾�ǉ��ɂ��āAconst���ۏ؂���Ă��邩�̃e�X�g
		 * @deteils	ID:���X�g-34(�蓮)
		 */
		TEST(ListManualTest, TestGetHeadConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_HEAD_CONST_ITERATOR_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr;
			itr = list.GetConstBegin();
#endif// TT_TEST_GET_HEAD_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�����C�e���[�^�̎擾�ǉ��ɂ��āA��const���ۏ؂���Ă��邩�̃e�X�g
		 * @deteils	ID:���X�g-40(�蓮)
		 */
		TEST(ListManualTest, TestGetTailIteratorWhenConst)
		{
#if defined TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST
			const List<int> list;
			Iterator<int> itr;
			itr = list.GetEnd(); // �����ŃG���[
#endif// TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�����R���X�g�C�e���[�^�̎擾�ǉ��ɂ��āAconst���ۏ؂���Ă��邩�̃e�X�g
		 * @deteils	ID:���X�g-46(�蓮)
		 */
		TEST(ListManualTest, TestGetTailConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr;
			itr = list.GetConstEnd();
#endif// TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�R���X�g�C�e���[�^����擾�����v�f�ɑ΂��đ�����s���邩�̃e�X�g
		 * @deteils	ID:�C�e���[�^-2(�蓮)
		 */
		TEST(IteratorManualTest, TestGetIteratorWhenConst)
		{
#if defined TT_TEST_GET_ITERATOR_WHEN_CONST
			List<int> list;
			ConstIterator<int> itr;
			itr = list.GetConstBegin();
			list.Insert(itr, 10);
			itr = list.GetConstBegin();
			*itr = 100; // �����ŃG���[
#endif// TT_TEST_GET_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�R���X�g�C�e���[�^����C�e���[�^�̃R�s�[���쐬����Ȃ����̃e�X�g
		 * @deteils	ID:�C�e���[�^-17(�蓮)
		 */
		TEST(IteratorManualTest, TestIteratorCopyWhenConst)
		{
#if defined TT_TEST_ITERATOR_COPY_WHEN_CONST
			ConstIterator<int> constItr;
			Iterator<int> itr(constItr); // �����ŃG���[
#endif// TT_TEST_ITERATOR_COPY_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	�C�e���[�^�ɃR���X�g�C�e���[�^�����ł��Ȃ����̃e�X�g
		 * @deteils	ID:�C�e���[�^-19(�蓮)
		 */
		TEST(IteratorManualTest, TestIteratorAssignWhenConst)
		{
#if defined TT_TEST_ITERATOR_ASSIGN_WHEN_CONST
			Iterator<int> itr;
			ConstIterator<int> constItr;
			itr = constItr; // �����ŃG���[
#endif// TT_TEST_ITERATOR_ASSIGN_WHEN_CONST
			SUCCEED();
		}
	}
}