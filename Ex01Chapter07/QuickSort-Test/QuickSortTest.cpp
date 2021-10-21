/**
 * @file QuickSortTest.cpp
 * @brief �N�C�b�N�\�[�g�̃e�X�g�����t�@�C��(�蓮�e�X�g���܂�
 * @author MikamiYuto
 * @date 2021.10.15
 */


 //----- �C���N���[�h
#include "QuickSortTest.h"


// �\�[�g�p�̃L�[
const auto CmpScoreAsk = [](const ScoreData& a, const ScoreData& b) {return a.score < b.score; };			// �X�R�A���L�[�Ƃ�������
const auto CmpScoreDesk = [](const ScoreData& a, const ScoreData& b) {return a.score > b.score; };			// �X�R�A���L�[�Ƃ����~��
const auto CmpUserNameAsk = [](const ScoreData& a, const ScoreData& b) {return a.userName < b.userName; };	// ���[�U�����L�[�Ƃ�������
const auto CmpUserNameDesk = [](const ScoreData& a, const ScoreData& b) {return a.userName > b.userName; };	// ���[�U�����L�[�Ƃ����~��


//=============================================================================
// �N�C�b�N�\�[�g�̋����e�X�g
//=============================================================================
INSTANTIATE_TEST_CASE_P(TestListQuickSort, ListQuickSortTest, ::testing::Values(
	CmpScoreAsk, 
	CmpScoreDesk, 
	CmpUserNameAsk, 
	CmpUserNameDesk
));
/**
 * @brief	�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-0
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenEmpty)
{
	m_List.QuickSort(GetParam());
}
/**
 * @brief	�v�f��1���������X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-1
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenOnly)
{
	m_List.Insert(m_List.begin(), ScoreData{ 1, "test" });
	m_List.QuickSort(GetParam());
}
/**
 * @brief	2�ȏ�̗v�f�������X�g�Ƀ\�[�g�����s�������̋����e�X�g
 * @deteils	ID:���X�g-2
 */
TEST_P(ListQuickSortTest, TestListQuickSort)
{
	// �K�v�ȃf�[�^�̗p��
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData setupDatas[] = { oneA, zeroC, twoB };

	// �����v�f�����関����̃��X�g��p��
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));

	// ���񏈗����s
	m_List.QuickSort(GetParam());

	// �`�F�b�N�p�f�[�^�̗p��
	const ScoreData expecteds[][3] = 
	{ 
		{ zeroC, oneA, twoB, },// �X�R�A����
		{ twoB, oneA, zeroC, },// �X�R�A�~��
		{ oneA, twoB, zeroC, },// ���[�U������
		{ zeroC, twoB, oneA, },// ���[�U���~��
	};
	const ScoreData* pExpected = expecteds[GetTestNumber()];

	// ���������񂳂�Ă��邩�`�F�b�N
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
	// �K�v�ȃf�[�^�̗p��
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData setupDatas[] = { oneA, zeroC, zeroC, twoB };

	// �d�������L�[�����镡���v�f�̖����񃊃X�g��p��
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));

	// ���񏈗����s
	m_List.QuickSort(GetParam());

	// �`�F�b�N�p�f�[�^�̗p��
	const ScoreData expecteds[][4] =
	{
		{ zeroC, zeroC, oneA, twoB },	// �X�R�A����
		{ twoB, oneA, zeroC, zeroC },	// �X�R�A�~��
		{ oneA, twoB, zeroC, zeroC },	// ���[�U������
		{ zeroC, zeroC, twoB, oneA },	// ���[�U���~��
	};						 
	const ScoreData* pExpected = expecteds[GetTestNumber()];

	// ���������񂳂�Ă��邩�`�F�b�N
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
	// �K�v�ȃf�[�^�̗p��
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData expecteds[][3] =
	{
		{ zeroC, oneA, twoB, },// �X�R�A����
		{ twoB, oneA, zeroC, },// �X�R�A�~��
		{ oneA, twoB, zeroC, },// ���[�U������
		{ zeroC, twoB, oneA, },// ���[�U���~��
	};
	const int testNumber = GetTestNumber();
	const ScoreData* pExpected = expecteds[testNumber];

	// ����σ��X�g��p��
	for (const auto& data : m_List)
	{
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
		++pExpected;
	}

	// ���񏈗����s
	m_List.QuickSort(GetParam());

	// ���Ԃ��ϓ����Ă��Ȃ����`�F�b�N
	pExpected = expecteds[testNumber];
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
	// �K�v�ȃf�[�^�̗p��
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData setupDatas[][3] =
	{
		{ zeroC, oneA, twoB, },// �X�R�A����
		{ twoB, oneA, zeroC, },// �X�R�A�~��
		{ oneA, twoB, zeroC, },// ���[�U������
		{ zeroC, twoB, oneA, },// ���[�U���~��
	};
	const int testNumber = GetTestNumber();
	const ScoreData* pSetup = setupDatas[testNumber];

	// ����σ��X�g��p��
	for (int i = 0; i < 3; ++i, ++pSetup)
		ASSERT_TRUE(m_List.Insert(m_List.end(), *pSetup));

	// ����σ��X�g�̊e���ɗv�f��}��
	const ScoreData threeF{ 3,"f" };
	const ScoreData fourE{ 4,"e" };
	const ScoreData fiveD{ 5,"d" };
	const ScoreData insertDatas[] = { threeF, fourE, fiveD };
	for (int i = 0; i < 3; ++i)
	{
		auto itr = m_List.begin();
		for (int j = 0; j < i * 2; ++j, ++itr);// �}���������̃Y����␳
		ASSERT_TRUE(m_List.Insert(itr, insertDatas[i]));
	}

	// ���񏈗����s
	m_List.QuickSort(GetParam());
	
	// �`�F�b�N�ɕK�v�ȃf�[�^�̗p��
	const ScoreData expecteds[][6] = 
	{
		{ zeroC, oneA, twoB, threeF, fourE, fiveD }, // �X�R�A����
		{ fiveD, fourE, threeF, twoB, oneA, zeroC }, // �X�R�A�~��
		{ oneA, twoB, zeroC, fiveD, fourE, threeF }, // ���[�U������
		{ threeF, fourE, fiveD, zeroC, twoB, oneA }, // ���[�U���~��
	};
	const ScoreData* pExpected = expecteds[testNumber];

	// ���������񂳂�Ă��邩�`�F�b�N
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
	// �K�v�ȃf�[�^�̗p��
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData expecteds[] = { zeroC, oneA,  };
	
	// �����v�f�����郊�X�g��p��
	for (const auto& data : expecteds)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));

	// ���񏈗����s
	m_List.QuickSort(nullptr);

	// �ςɐ��񂪂������Ă��Ȃ����`�F�b�N
	const ScoreData* pExpected = expecteds;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
//--------------------------------------------------------------------------------
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
	list.QuickSort(CmpScoreAsk);// �����ŃG���[
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
	const List<ScoreData> list;
	list.QuickSort(CmpScoreAsk);// �����ŃG���[
#endif // TEST_QUICKSORT_IS_CONST
	SUCCEED();
}