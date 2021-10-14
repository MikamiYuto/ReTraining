/**
 * @file HashTableManualTest.h
 * @brief テンプレートリストクラスのテスト定義ファイル
 * @author MikamiYuto
 * @date 2021.10.14
 */
#pragma once


//----- インクルード
#include "gtest/gtest.h"
#include "../HashTable/HashTable.h"


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
//----- マクロ定義

// ※コンパイルが通れば成功
#define TEST_GET_DATA_NUM_IS_CONST	// ID:ハッシュテーブル-12
#define TEST_FIND_IS_CONST			// ID:ハッシュテーブル-34

// ※コンパイルが通らなければ成功
//#define TEST_CLASS_HASH_FUNC		// ID:ハッシュテーブル-0
//#define TEST_INSERT_IS_CONST		// ID:ハッシュテーブル-18
//#define TEST_ERASE_IS_CONST		// ID:ハッシュテーブル-26

/** ハッシュテーブルの手動テスト用フィクスチャクラス */
class HashTableManualTest : public ::testing::Test
{
protected:
	const HashTable<std::string, int, CalcHash, DEFAULT_HASH_PACKET_SIZE> m_HashTable; //!< コンストハッシュテーブル
};