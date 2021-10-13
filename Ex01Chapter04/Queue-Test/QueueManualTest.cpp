/**
 * @file QueueManualTest.cpp
 * @breif �L���[�̃R���p�C���֘A�蓮�e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */


//----- �C���N���[�h
#include "QueueManualTest.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
/**
 * @breif	�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�L���[-7(�蓮)
 */
TEST(QueueManualTest, TestGetDataNumIsConst)
{
#if defined TEST_GET_DATA_NUM_IS_CONST
	const Queue<int> queue;
	EXPECT_EQ(queue.GetCount(), 0);
#endif // TEST_GET_DATA_NUM_IS_CONST
	SUCCEED();
}
/**
 * @breif	�v�b�V���ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�L���[-10(�蓮)
 */
TEST(QueueManualTest, TestPushIsConst)
{
#if defined TEST_PUSH_IS_CONST
	const Queue<int> queue;
	queue.Push(10);// �����ŃG���[
#endif // TEST_PUSH_IS_CONST
	SUCCEED();
}
/**
 * @breif	�|�b�v�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�L���[-14(�蓮)
 */
TEST(QueueManualTest, TestPopIsConst)
{
#if defined TEST_POP_IS_CONST
	const Queue<int> queue;
	queue.Pop();// �����ŃG���[
#endif // TEST_POP_IS_CONST
	SUCCEED();
}