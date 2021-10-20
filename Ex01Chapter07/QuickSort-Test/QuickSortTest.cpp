/**
 * @file QuickSortTest.cpp
 * @brief クイックソートのテスト実装ファイル(手動テストも含む
 * @author MikamiYuto
 * @date 2021.10.15
 */


 //----- インクルード
#include "QuickSortTest.h"



//=============================================================================
// クイックソートの挙動テスト
//=============================================================================
INSTANTIATE_TEST_CASE_P(TestListQuickSort, ListQuickSortTest, testing::Bool());
/**
 * @brief	要素を持たないリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-0
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenEmpty)
{
	m_List.QuickSort(GetParam(), m_CmpFunc);
}
/**
 * @brief	要素を1つだけ持つリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-1
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenOnly)
{
	m_List.Insert(m_List.begin(), 1);
	m_List.QuickSort(GetParam(), m_CmpFunc);
}
/**
 * @brief	2つ以上の要素を持つリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-2
 */
TEST_P(ListQuickSortTest, TestListQuickSort)
{
	const bool isAsk = GetParam();

	// 複数要素がある未整列のリストを用意
	const int setupDatas[] = { 0, 2, 1 };
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
	// 整列処理実行
	m_List.QuickSort(isAsk, m_CmpFunc);
	// 正しく整列されているかチェック
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
 * @brief	同じキーを持つ要素があるリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-3
 */
TEST_P(ListQuickSortTest, TestListQuickSortDupKey)
{
	const bool isAsk = GetParam();

	// 重複したキーがある複数要素の未整列リストを用意
	const int setupDatas[] = { 0, 2, 1, 1 };
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
	// 整列処理実行
	m_List.QuickSort(isAsk, m_CmpFunc);
	// 正しく整列されているかチェック
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
 * @brief	整列済みリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-4
 */
TEST_P(ListQuickSortTest, TestListQuickSortAfterSort)
{
	const bool isAsk = GetParam();
	// 整列済リストを用意
	const int expectedAsk[] = { 0, 1, 2 };
	const int expectedDesk[] = { 2, 1, 0 };
	const int* pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
		++pExpected;
	}
	// 整列処理実行
	m_List.QuickSort(isAsk, m_CmpFunc);
	// 順番が変動していないかチェック
	pExpected = isAsk ? expectedAsk : expectedDesk;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
/**
 * @brief	一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動テスト
 * @deteils	ID:リスト-5
 */
TEST_P(ListQuickSortTest, TestListQuickSortAfterSortInsert)
{
	const bool isAsk = GetParam();
	// 整列済リストを用意
	const int setupAsk[] = { 0, 10, 100 };
	const int setupDesk[] = { 100, 10, 0 };
	const int* pSetup = isAsk ? setupAsk : setupDesk;
	for (int i = 0; i < 3; ++i, ++pSetup)
		ASSERT_TRUE(m_List.Insert(m_List.end(), *pSetup));
	// 整列済リストの各所に要素を挿入
	const int insertDatas[] = { 50, 5, 500 };
	for (int i = 0; i < 3; ++i)
	{
		List<int>::Iterator itr = m_List.begin();
		for (int j = 0; j < i * 2; ++j, ++itr);// 挿入した分のズレを補正
		ASSERT_TRUE(m_List.Insert(itr, insertDatas[i]));
	}
	// 整列処理実行
	m_List.QuickSort(isAsk, m_CmpFunc);
	// 正しく整列されているかチェック
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
 * @brief	キー指定をしなかった(nullptr)時にソートを実行した時の挙動テスト
 * @deteils	ID:リスト-6
 */
TEST_P(ListQuickSortTest, TestListQuickSortNullPtrKey)
{
	const int expected[] = { 1, 0, 2 };
	for (int i = 0; i < 3; ++i)
		ASSERT_TRUE(m_List.Insert(m_List.end(), expected[i]));
	// 整列処理実行
	m_List.QuickSort(GetParam(), nullptr);
	// 変に整列がかけられていないかチェック
	const int* pExpected = expected;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
/**
 * @brief	型などが不適切なキーが引数で渡された時にソートを実行した時の挙動テスト
 * @deteils	ID:リスト-7(手動)
 */
TEST(ListQuickSortManualTest, TestListQuickSortNotExpectedKey)
{
#if defined TEST_QUICKSORT_NOT_EXPECTED_KEY
	List<int> list;
	auto cmpFunc = [](bool isAsk, const float& a, const float& b) { return isAsk ? a < b : a > b; };
	list.QuickSort(true, cmpFunc);// ここでエラー
#endif // TEST_QUICKSORT_NOT_EXPECTED_KEY
	SUCCEED();
}
/**
 * @brief	クイックソートメソッドについて、非constのメソッドであるかのテスト
 * @deteils	ID:リスト-8(手動)
 */
TEST(ListQuickSortManualTest, TestListQuickSortIsConst)
{
#if defined TEST_QUICKSORT_IS_CONST
	const List<int> list;
	auto cmpFunc = [](bool isAsk, const int& a, const int& b) { return isAsk ? a < b : a > b; };
	list.QuickSort(true, cmpFunc);// ここでエラー
#endif // TEST_QUICKSORT_IS_CONST
	SUCCEED();
}