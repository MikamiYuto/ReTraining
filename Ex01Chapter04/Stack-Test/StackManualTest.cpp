/**
 * @file ManualTest.cpp
 * @breif �X�^�b�N�̃R���p�C���֘A�蓮�e�X�g�����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */


//----- �C���N���[�h
#include "StackManualTest.h"


//--------------------------------------------------------------------------------
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
/**
 * @breif	�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�X�^�b�N-7(�蓮)
 */
TEST(StackManualTest, TestGetDataNumIsConst)
{
#if defined TEST_GET_DATA_NUM_IS_CONST
	const Stack<int> stack;
	EXPECT_EQ(stack.GetCount(), 0);
#endif // TEST_GET_DATA_NUM_IS_CONST
	SUCCEED();
}
/**
 * @breif	�v�b�V���ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�X�^�b�N-10(�蓮)
 */
TEST(StackManualTest, TestPushIsConst)
{
#if defined TEST_PUSH_IS_CONST
	const Stack<int> stack;
	stack.Push(10);// �����ŃG���[
#endif // TEST_PUSH_IS_CONST
	SUCCEED();
}
/**
 * @breif	�|�b�v�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:�X�^�b�N-14(�蓮)
 */
TEST(StackManualTest, TestPopIsConst)
{
#if defined TEST_POP_IS_CONST
	const Stack<int> stack;
	stack.Pop();// �����ŃG���[
#endif // TEST_POP_IS_CONST
	SUCCEED();
}