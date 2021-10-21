/**
 * @file QuickSortTest.h
 * @brief クイックソートのテスト定義ファイル(手動テストも含む
 * @author MikamiYuto
 * @date 2021.10.15
 */
#pragma once


 //----- インクルード
#include "gtest/gtest.h"
#include "../QuickSort/List.h"
#include "../QuickSort/ScoreData.h"


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
//----- マクロ定義

// ※コンパイルが通らなければ成功
//#define TEST_QUICKSORT_NOT_EXPECTED_KEY	// ID:リスト-7
//#define TEST_QUICKSORT_IS_CONST			// ID:リスト-8


/** クイックソートメソッドのテスト用フィクスチャクラス */
class ListQuickSortTest : public ::testing::TestWithParam<bool(*)(const ScoreData&,const ScoreData&)>
{
protected:
	/**
	 * @brief テスト番号の取得
	 */
	int GetTestNumber()
	{
		auto testInfo = ::testing::UnitTest::GetInstance()->current_test_info();
		const std::string& testName = testInfo->name();
		return std::stoi(testName.c_str() + testName.rfind("/") + 1);
	}

protected:
	List<ScoreData> m_List;
};