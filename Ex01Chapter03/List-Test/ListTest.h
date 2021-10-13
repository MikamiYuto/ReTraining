/**
 * @file ListTest.h
 * @breif テンプレートリストクラスのテスト定義ファイル
 * @author MikamiYuto
 * @date 2021.10.12
 */
#pragma once



//----- インクルード
#include "gtest/gtest.h"
#include "../List/List.h"
#include "../List/Iterator.h"


/** リストテスト用フィクスチャのベースクラス */
class BaseListTest : public ::testing::Test
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
/** リストのデータ数取得テスト用フィクスチャクラス */
class ListGetDataNumTest : public BaseListTest {};
/** リストの挿入時の挙動テスト用フィクスチャクラス */
class ListPushTest : public BaseListTest {};
/** リストの削除時の挙動テスト用フィクスチャクラス */
class ListEraseTest : public BaseListTest {};
/** リストの先頭イテレータ取得テスト用フィクスチャクラス */
class ListGetHeadIteratorTest : public BaseListTest {};
/** リストの先頭コンストイテレータ取得テスト用フィクスチャクラス */
class ListGetHeadConstIteratorTest : public BaseListTest {};
/** リストの末尾イテレータ取得テスト用フィクスチャクラス */
class ListGetTailIteratorTest : public BaseListTest {};
/** リストの末尾コンストイテレータ取得テスト用フィクスチャクラス */
class ListGetTailConstIteratorTest : public BaseListTest {};
