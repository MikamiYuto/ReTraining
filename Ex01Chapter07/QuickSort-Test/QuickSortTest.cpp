/**
 * @file QuickSortTest.cpp
 * @brief �N�C�b�N�\�[�g�̃e�X�g�����t�@�C��(�蓮�e�X�g���܂�
 * @author MikamiYuto
 * @date 2021.10.15
 */


 //----- �C���N���[�h
#include "QuickSortTest.h"



//=============================================================================
// �N�C�b�N�\�[�g�̋����e�X�g
//=============================================================================
INSTANTIATE_TEST_CASE_P(TestListQuickSort, ListQuickSortTest, testing::Bool());
/**
 * @brief	�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-0
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenEmpty)
{
	m_List.QuickSort(GetParam(), m_CmpFunc);
}
/**
 * @brief	�v�f��1���������X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-1
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenOnly)
{
	m_List.Insert(m_List.begin(), 1);
	m_List.QuickSort(GetParam(), m_CmpFunc);
}
/**
 * @brief	2�ȏ�̗v�f�������X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-2
 */
TEST_P(ListQuickSortTest, TestListQuickSort)
{
	const bool isAsk = GetParam();

	// �����v�f�����関����̃��X�g��p��
	const int setupDatas[] = { 0, 2, 1 };
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
	// ���񏈗����s
	m_List.QuickSort(isAsk, m_CmpFunc);
	// ���������񂳂�Ă��邩�`�F�b�N
	const int expectedAsk[] = { 0, 1, 2 };
	const int expectedDesk[] = { 2, 1, 0 };
	const int* pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
/**
 * @brief	�����L�[�����v�f�����郊�X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-3
 */
TEST_P(ListQuickSortTest, TestListQuickSortDupKey)
{
	const bool isAsk = GetParam();

	// �d�������L�[�����镡���v�f�̖����񃊃X�g��p��
	const int setupDatas[] = { 0, 2, 1, 1 };
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
	// ���񏈗����s
	m_List.QuickSort(isAsk, m_CmpFunc);
	// ���������񂳂�Ă��邩�`�F�b�N
	const int expectedAsk[] = { 0, 1, 1, 2 };
	const int expectedDesk[] = { 2, 1, 1, 0 };
	const int* pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
/**
 * @brief	����ς݃��X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-4
 */
TEST_P(ListQuickSortTest, TestListQuickSortAfterSort)
{
	const bool isAsk = GetParam();
	// ����σ��X�g��p��
	const int expectedAsk[] = { 0, 1, 2 };
	const int expectedDesk[] = { 2, 1, 0 };
	const int* pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
		++pExpected;
	}
	// ���񏈗����s
	m_List.QuickSort(isAsk, m_CmpFunc);
	// ���Ԃ��ϓ����Ă��Ȃ����`�F�b�N
	pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
/**
 * @brief	��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-5
 */
TEST_P(ListQuickSortTest, TestListQuickSortAfterSortInsert)
{
	const bool isAsk = GetParam();
	// ����σ��X�g��p��
	const int setupAsk[] = { 0, 10, 100 };
	const int setupDesk[] = { 100, 10, 0 };
	const int* pSetup = isAsk ? setupAsk : setupDesk;
	for (int i = 0; i < 3; ++i, ++pSetup)
		ASSERT_TRUE(m_List.Insert(m_List.end(), *pSetup));
	// ����σ��X�g�̊e���ɗv�f��}��
	const int insertDatas[] = { 50, 5, 500 };
	for (int i = 0; i < 3; ++i)
	{
		List<int>::Iterator itr = m_List.begin();
		for (int j = 0; j < i * 2; ++j, ++itr);// �}���������̃Y����␳
		ASSERT_TRUE(m_List.Insert(itr, insertDatas[i]));
	}
	// ���񏈗����s
	m_List.QuickSort(isAsk, m_CmpFunc);
	// ���������񂳂�Ă��邩�`�F�b�N
	const int expectedAsk[] = { 0, 5, 10, 50, 100, 500 };
	const int expectedDesk[] = { 500, 100, 50, 10, 5, 0 };
	const int* pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
/**
 * @brief	�L�[�w������Ȃ�����(nullptr)���Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-6
 */
TEST_P(ListQuickSortTest, TestListQuickSortNullPtrKey)
{
	const int expected[] = { 1, 0, 2 };
	for (int i = 0; i < 3; ++i)
		ASSERT_TRUE(m_List.Insert(m_List.end(), expected[i]));
	// ���񏈗����s
	m_List.QuickSort(GetParam(), nullptr);
	// �ςɐ��񂪂������Ă��Ȃ����`�F�b�N
	const int* pExpected = expected;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
// �R���p�C���֘A�蓮�e�X�g
//--------------------------------------------------------------------------------
/**
 * @brief	�^�Ȃǂ��s�K�؂ȃL�[�������œn���ꂽ���Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-7(�蓮)
 */
TEST(ListQuickSortManualTest, TestListQuickSortNotExpectedKey)
{
#if defined TEST_QUICKSORT_NOT_EXPECTED_KEY
	List<int> list;
	auto cmpFunc = [](bool isAsk, const float& a, const float& b) { return isAsk ? a < b : a > b; };
	list.QuickSort(true, cmpFunc);// �����ŃG���[
#endif // TEST_QUICKSORT_NOT_EXPECTED_KEY
	SUCCEED();
}
/**
 * @brief	�N�C�b�N�\�[�g���\�b�h�ɂ��āA��const�̃��\�b�h�ł��邩�̃e�X�g
 * @deteils	ID:���X�g-8(�蓮)
 */
TEST(ListQuickSortManualTest, TestListQuickSortIsConst)
{
#if defined TEST_QUICKSORT_IS_CONST
	const List<int> list;
	auto cmpFunc = [](bool isAsk, const int& a, const int& b) { return isAsk ? a < b : a > b; };
	list.QuickSort(true, cmpFunc);// �����ŃG���[
#endif // TEST_QUICKSORT_IS_CONST
	SUCCEED();
}