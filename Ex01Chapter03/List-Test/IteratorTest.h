/**
 * @file IteratorTest.h
 * @breif テンプレートイテレータクラスのテスト定義ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


 //----- インクルード
#include "gtest/gtest.h"
#include "../List/List.h"
#include "../List/Iterator.h"


/** イテレータテスト用フィクスチャのベースクラス */
class BaseIteratorTest : public ::testing::Test
{
protected:
	/**
	 * @brief	初期化
	 * @details 各テスト項目の実行前に、複数要素を持つリストを用意する
	 */
	virtual void SetUp()
	{
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				Iterator<int> itr = m_Lists[i].GetEnd();
				m_Lists[i].Insert(itr, j);
			}
		}
	}

protected:
	List<int>	m_Lists[3];		//!< 複数要素を持つリスト(要素数2,各要素はその要素位置が値として格納
};
/** イテレータをリストの末尾に向けて一つ進める挙動テスト用フィクスチャクラス */
class IteratorIncrementTest : public BaseIteratorTest {};
/** イテレータをリストの先頭に向けて一つ進める挙動テスト用フィクスチャクラス */
class IteratorDecrementTest : public BaseIteratorTest {};
