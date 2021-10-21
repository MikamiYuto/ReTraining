/**
 * @file QuickSortTest.cpp
 * @brief クイックソートのテスト実装ファイル(手動テストも含む
 * @author MikamiYuto
 * @date 2021.10.15
 */


 //----- インクルード
#include "QuickSortTest.h"


// ソート用のキー
const auto CmpScoreAsk = [](const ScoreData& a, const ScoreData& b) {return a.score < b.score; };			// スコアをキーとした昇順
const auto CmpScoreDesk = [](const ScoreData& a, const ScoreData& b) {return a.score > b.score; };			// スコアをキーとした降順
const auto CmpUserNameAsk = [](const ScoreData& a, const ScoreData& b) {return a.userName < b.userName; };	// ユーザ名をキーとした昇順
const auto CmpUserNameDesk = [](const ScoreData& a, const ScoreData& b) {return a.userName > b.userName; };	// ユーザ名をキーとした降順


//=============================================================================
// クイックソートの挙動テスト
//=============================================================================
INSTANTIATE_TEST_CASE_P(TestListQuickSort, ListQuickSortTest, ::testing::Values(
	CmpScoreAsk, 
	CmpScoreDesk, 
	CmpUserNameAsk, 
	CmpUserNameDesk
));
/**
 * @brief	要素を持たないリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-0
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenEmpty)
{
	m_List.QuickSort(GetParam());
}
/**
 * @brief	要素を1つだけ持つリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-1
 */
TEST_P(ListQuickSortTest, TestListQuickSortWhenOnly)
{
	m_List.Insert(m_List.begin(), ScoreData{ 1, "test" });
	m_List.QuickSort(GetParam());
}
/**
 * @brief	2つ以上の要素を持つリストにソートを実行した時の挙動テスト
 * @deteils	ID:リスト-2
 */
TEST_P(ListQuickSortTest, TestListQuickSort)
{
	// 必要なデータの用意
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData setupDatas[] = { oneA, zeroC, twoB };

	// 複数要素がある未整列のリストを用意
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));

	// 整列処理実行
	m_List.QuickSort(GetParam());

	// チェック用データの用意
	const ScoreData expecteds[][3] = 
	{ 
		{ zeroC, oneA, twoB, },// スコア昇順
		{ twoB, oneA, zeroC, },// スコア降順
		{ oneA, twoB, zeroC, },// ユーザ名昇順
		{ zeroC, twoB, oneA, },// ユーザ名降順
	};
	const ScoreData* pExpected = expecteds[GetTestNumber()];

	// 正しく整列されているかチェック
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
	// 必要なデータの用意
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData setupDatas[] = { oneA, zeroC, zeroC, twoB };

	// 重複したキーがある複数要素の未整列リストを用意
	for (const auto& data : setupDatas)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));

	// 整列処理実行
	m_List.QuickSort(GetParam());

	// チェック用データの用意
	const ScoreData expecteds[][4] =
	{
		{ zeroC, zeroC, oneA, twoB },	// スコア昇順
		{ twoB, oneA, zeroC, zeroC },	// スコア降順
		{ oneA, twoB, zeroC, zeroC },	// ユーザ名昇順
		{ zeroC, zeroC, twoB, oneA },	// ユーザ名降順
	};						 
	const ScoreData* pExpected = expecteds[GetTestNumber()];

	// 正しく整列されているかチェック
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
	// 必要なデータの用意
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData expecteds[][3] =
	{
		{ zeroC, oneA, twoB, },// スコア昇順
		{ twoB, oneA, zeroC, },// スコア降順
		{ oneA, twoB, zeroC, },// ユーザ名昇順
		{ zeroC, twoB, oneA, },// ユーザ名降順
	};
	const int testNumber = GetTestNumber();
	const ScoreData* pExpected = expecteds[testNumber];

	// 整列済リストを用意
	for (const auto& data : m_List)
	{
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));
		++pExpected;
	}

	// 整列処理実行
	m_List.QuickSort(GetParam());

	// 順番が変動していないかチェック
	pExpected = expecteds[testNumber];
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
	// 必要なデータの用意
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData twoB{ 2,"b" };
	const ScoreData setupDatas[][3] =
	{
		{ zeroC, oneA, twoB, },// スコア昇順
		{ twoB, oneA, zeroC, },// スコア降順
		{ oneA, twoB, zeroC, },// ユーザ名昇順
		{ zeroC, twoB, oneA, },// ユーザ名降順
	};
	const int testNumber = GetTestNumber();
	const ScoreData* pSetup = setupDatas[testNumber];

	// 整列済リストを用意
	for (int i = 0; i < 3; ++i, ++pSetup)
		ASSERT_TRUE(m_List.Insert(m_List.end(), *pSetup));

	// 整列済リストの各所に要素を挿入
	const ScoreData threeF{ 3,"f" };
	const ScoreData fourE{ 4,"e" };
	const ScoreData fiveD{ 5,"d" };
	const ScoreData insertDatas[] = { threeF, fourE, fiveD };
	for (int i = 0; i < 3; ++i)
	{
		auto itr = m_List.begin();
		for (int j = 0; j < i * 2; ++j, ++itr);// 挿入した分のズレを補正
		ASSERT_TRUE(m_List.Insert(itr, insertDatas[i]));
	}

	// 整列処理実行
	m_List.QuickSort(GetParam());
	
	// チェックに必要なデータの用意
	const ScoreData expecteds[][6] = 
	{
		{ zeroC, oneA, twoB, threeF, fourE, fiveD }, // スコア昇順
		{ fiveD, fourE, threeF, twoB, oneA, zeroC }, // スコア降順
		{ oneA, twoB, zeroC, fiveD, fourE, threeF }, // ユーザ名昇順
		{ threeF, fourE, fiveD, zeroC, twoB, oneA }, // ユーザ名降順
	};
	const ScoreData* pExpected = expecteds[testNumber];

	// 正しく整列されているかチェック
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
	// 必要なデータの用意
	const ScoreData zeroC{ 0,"c" };
	const ScoreData oneA{ 1,"a" };
	const ScoreData expecteds[] = { zeroC, oneA,  };
	
	// 複数要素があるリストを用意
	for (const auto& data : expecteds)
		ASSERT_TRUE(m_List.Insert(m_List.end(), data));

	// 整列処理実行
	m_List.QuickSort(nullptr);

	// 変に整列がかけられていないかチェック
	const ScoreData* pExpected = expecteds;
	for (const auto& data : m_List)
	{
		EXPECT_EQ(data, *pExpected);
		++pExpected;
	}
}
//--------------------------------------------------------------------------------
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
	list.QuickSort(CmpScoreAsk);// ここでエラー
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
	const List<ScoreData> list;
	list.QuickSort(CmpScoreAsk);// ここでエラー
#endif // TEST_QUICKSORT_IS_CONST
	SUCCEED();
}