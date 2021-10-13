/**
 * @file StackTest.cpp
 * @breif �e���v���[�g�X�^�b�N�N���X�̃e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */


 //----- �C���N���[�h
#include "StackTest.h"


//=============================================================================
// �f�[�^���̎擾�e�X�g
//=============================================================================
/**
 * @breif	�X�^�b�N����ł���ꍇ�̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-0
 */
TEST(StackGetDataNumTest, TestGetDataNumWhenEmpty)
{
	Stack<int> stack;
	EXPECT_EQ(0, stack.GetCount());
}
/**
 * @breif	�v�f���v�b�V��������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-1
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPush)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	EXPECT_EQ(1, stack.GetCount());
}
/**
 * @breif	�v�f���|�b�v������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-2
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPop)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Pop());
	EXPECT_EQ(0, stack.GetCount());
}
/**
 * @breif	�v�f�̃v�b�V���Ɏ��s������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-3
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPushFailed)
{
	// �}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
	//Stack<int> stack;
	//ASSERT_FALSE(stack.Push(0));
	//EXPECT_EQ(0, stack.GetCount());
}
/**
 * @breif	�v�f��2��v�b�V��������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-4
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPushX2)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Push(1));
	EXPECT_EQ(2, stack.GetCount());
}
/**
 * @breif	�v�f��2��v�b�V�����A1��|�b�v������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-5
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPushX2Pop)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Push(1));
	ASSERT_TRUE(stack.Pop());
	EXPECT_EQ(1, stack.GetCount());
}
/**
 * @breif	�X�^�b�N����ł���ꍇ�Ƀ|�b�v������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�X�^�b�N-6
 */
TEST(StackGetDataNumTest, TestGetDataNumWhenEmptyAfterPop)
{
	Stack<int> stack;
	ASSERT_FALSE(stack.Pop());
	EXPECT_EQ(0, stack.GetCount());
}
//=============================================================================
// �v�b�V�����̋����e�X�g
//=============================================================================
/**
 * @breif	�X�^�b�N����ł��鎞�Ƀv�b�V�������ۂ̋����e�X�g
 * @deteils	ID:�X�^�b�N-8
 */
TEST(StackPushTest, TestPushWhenEmpty)
{
	Stack<int> stack;
	EXPECT_TRUE(stack.Push(10));
	//�@�}���v�f�̃`�F�b�N
	int check = 0;
	ASSERT_TRUE(stack.Pop(&check));
	EXPECT_EQ(check, 10);
}
/**
 * @breif	�X�^�b�N�ɕ����v�f�����鎞�Ƀv�b�V�������ۂ̋����e�X�g
 * @deteils	ID:�X�^�b�N-9
 */
TEST(StackPushTest, TestPush)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(10));
	ASSERT_TRUE(stack.Push(20));
	EXPECT_TRUE(stack.Push(30));
	//�@�}���v�f�̃`�F�b�N
	int checkDatas[] = { 30,20,10 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		ASSERT_TRUE(stack.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}
//=============================================================================
// �|�b�v���̋����e�X�g
//=============================================================================
/**
 * @breif	�X�^�b�N����ł��鎞�Ƀ|�b�v�����ۂ̋����e�X�g
 * @deteils	ID:�X�^�b�N-11
 */
TEST(StackPopTest, TestPopWhenEmpty)
{
	Stack<int> stack;
	int check = 0;
	EXPECT_FALSE(stack.Pop(&check));
	// ���悪��������Ă��Ȃ����`�F�b�N
	EXPECT_EQ(check, 0);
}
/**
 * @breif	�X�^�b�N�ɕ����v�f�����鎞�Ƀ|�b�v�����ۂ̋����e�X�g
 * @deteils	ID:�X�^�b�N-12
 */
TEST(StackPopTest, TestPop)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(10));
	ASSERT_TRUE(stack.Push(20));
	ASSERT_TRUE(stack.Push(30));
	int check = 0;
	EXPECT_TRUE(stack.Pop(&check));
	// �擾�v�f�̃`�F�b�N
	EXPECT_EQ(check, 30);
}
/**
 * @breif	�X�^�b�N�ɕ����v�f�����鎞�ɕ�����|�b�v�����ۂ̋����e�X�g
 * @deteils	ID:�X�^�b�N-13
 */
TEST(StackPopTest, TestPopMany)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(10));
	ASSERT_TRUE(stack.Push(20));
	ASSERT_TRUE(stack.Push(30));
	int checkDatas[] = { 30,20,10 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		EXPECT_TRUE(stack.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}