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


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
//----- マクロ定義

// ※コンパイルが通らなければ成功
//#define TEST_QUICKSORT_NOT_EXPECTED_KEY	// ID:リスト-7
//#define TEST_QUICKSORT_IS_CONST			// ID:リスト-8


/** クイックソートメソッドのテスト用フィクスチャクラス */
class ListQuickSortTest : public ::testing::TestWithParam<bool>
{
protected:
	virtual void SetUp()
	{
		m_CmpFunc = [](bool isAsk, const int& a, const int& b) { return isAsk ? a < b : a > b; };
	}


protected:
	List<int> m_List;
	bool(*m_CmpFunc)(bool, const int&, const int&);
};