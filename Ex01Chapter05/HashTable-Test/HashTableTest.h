/**
 * @file StackTest.h
 * @brief テンプレートスタッククラスのテスト定義ファイル
 * @author MikamiYuto
 * @date 2021.10.14
 */
#pragma once


 //----- インクルード
#include "gtest/gtest.h"
#include "../HashTable/HashTable.h"


/** ハッシュテーブルテスト用のフィクスチャクラス */
class HashTableTest : public ::testing::Test
{
protected:
	/**
	 * @brief 重複(チェイン)した要素を持つハッシュテーブルの用意<"one", 1><"two", 2>
	 */
	void SetUpChainHash()
	{
		ASSERT_TRUE(m_HashTable.Insert("one", 1));
		ASSERT_TRUE(m_HashTable.Insert("two", 2));
	}
	/**
	 * @brief 重複(チェイン)せずに複数要素を持つハッシュテーブルの用意<"zero", 0><"one", 1>
	 */
	void SetUpUnChainHash()
	{
		ASSERT_TRUE(m_HashTable.Insert("zero", 0));
		ASSERT_TRUE(m_HashTable.Insert("one", 1));
	}

protected:
	HashTable<std::string, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> m_HashTable;
};
/** データ数取得テスト用 */
using HashTableGetDataNumTest = HashTableTest;
/** 挿入時の挙動テスト用 */
using HashTableInsertTest = HashTableTest;
/** 削除時の挙動テスト用 */
using HashTableEraseTest = HashTableTest;
/** 検索時の挙動テスト用 */
using HashTableFindTest = HashTableTest;