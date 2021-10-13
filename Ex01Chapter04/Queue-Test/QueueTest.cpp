/**
 * @file QueueTest.cpp
 * @breif �e���v���[�g�L���[�N���X�̃e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */


 //----- �C���N���[�h
#include "QueueTest.h"


//=============================================================================
// �f�[�^���̎擾�e�X�g
//=============================================================================
/**
 * @breif	�L���[����ł���ꍇ�̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-0
 */
TEST(QueueGetDataNumTest, TestGetDataNumWhenEmpty)
{
	Queue<int> queue;
	EXPECT_EQ(0, queue.GetCount());
}
/**
 * @breif	�v�f���v�b�V��������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-1
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPush)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	EXPECT_EQ(1, queue.GetCount());
}
/**
 * @breif	�v�f���|�b�v������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-2
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPop)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	ASSERT_FALSE(queue.Pop());
	EXPECT_EQ(0, queue.GetCount());
}
/**
 * @breif	�v�f�̃v�b�V���Ɏ��s������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-3
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPushFailed)
{
	// �}�����s�̓������m�ێ��s���̂��߂����ł̓X�L�b�v
	//Queue<int> queue;
	//ASSERT_FALSE(queue.Push(0));
	//EXPECT_EQ(0, queue.GetCount());
}
/**
 * @breif	�v�f��2��v�b�V��������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-4
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPushX2)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	ASSERT_TRUE(queue.Push(1));
	EXPECT_EQ(2, queue.GetCount());
}
/**
 * @breif	�v�f��2��v�b�V�����A1��|�b�v������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-5
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPushX2Pop)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	ASSERT_TRUE(queue.Push(1));
	ASSERT_TRUE(queue.Pop());
	EXPECT_EQ(1, queue.GetCount());
}
/**
 * @breif	�L���[����ł���ꍇ�Ƀ|�b�v������̃f�[�^���̎擾�e�X�g
 * @deteils	ID:�L���[-6
 */
TEST(QueueGetDataNumTest, TestGetDataNumWhenEmptyAfterPop)
{
	Queue<int> queue;
	ASSERT_FALSE(queue.Pop());
	EXPECT_EQ(0, queue.GetCount());
}
//=============================================================================
// �v�b�V�����̋����e�X�g
//=============================================================================
/**
 * @breif	�L���[����ł��鎞�Ƀv�b�V�������ۂ̋����e�X�g
 * @deteils	ID:�L���[-8
 */
TEST(QueuePushTest, TestPushWhenEmpty)
{
	Queue<int> queue;
	EXPECT_TRUE(queue.Push(10));
	//�@�}���v�f�̃`�F�b�N
	int check = 0;
	ASSERT_TRUE(queue.Pop(&check));
	EXPECT_EQ(check, 10);
}
/**
 * @breif	�L���[�ɕ����v�f�����鎞�Ƀv�b�V�������ۂ̋����e�X�g
 * @deteils	ID:�L���[-9
 */
TEST(QueuePushTest, TestPush)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(10));
	ASSERT_TRUE(queue.Push(20));
	EXPECT_TRUE(queue.Push(30));
	//�@�}���v�f�̃`�F�b�N
	int checkDatas[] = { 10,20,30 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		ASSERT_TRUE(queue.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}
//=============================================================================
// �|�b�v���̋����e�X�g
//=============================================================================
/**
 * @breif	�L���[����ł��鎞�Ƀ|�b�v�����ۂ̋����e�X�g
 * @deteils	ID:�L���[-11
 */
TEST(QueuePopTest, TestPopWhenEmpty)
{
	Queue<int> queue;
	int check = 0;
	EXPECT_FALSE(queue.Pop(&check));
	// ���悪��������Ă��Ȃ����`�F�b�N
	EXPECT_EQ(check, 0);
}
/**
 * @breif	�L���[�ɕ����v�f�����鎞�Ƀ|�b�v�����ۂ̋����e�X�g
 * @deteils	ID:�L���[-12
 */
TEST(QueuePopTest, TestPop)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(10));
	ASSERT_TRUE(queue.Push(20));
	ASSERT_TRUE(queue.Push(30));
	int check = 0;
	EXPECT_TRUE(queue.Pop(&check));
	// �擾�v�f�̃`�F�b�N
	EXPECT_EQ(check, 10);
}
/**
 * @breif	�L���[�ɕ����v�f�����鎞�ɕ�����|�b�v�����ۂ̋����e�X�g
 * @deteils	ID:�L���[-13
 */
TEST(QueuePopTest, TestPopMany)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(10));
	ASSERT_TRUE(queue.Push(20));
	ASSERT_TRUE(queue.Push(30));
	int checkDatas[] = { 10,20,30 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		EXPECT_TRUE(queue.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}