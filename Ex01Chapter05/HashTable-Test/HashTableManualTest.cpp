/**
 * @file HashTableManualTest.cpp
 * @brief テンプレートハッシュテーブルクラスの手動テスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.14
 */


//----- インクルード
#include "HashTableManualTest.h"


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
/**
 * @brief	不適切なハッシュ関数がテンプレート引数で渡された時のテスト
 * @deteils	ID:ハッシュテーブル-0(手動)
 */
TEST(HashTableManualClassTest, TestClassHashFunc)
{
#if defined TEST_CLASS_HASH_FUNC
	HashTable<float, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
#endif // TEST_CLASS_HASH_FUNC
	SUCCEED();
}

/**
 * @brief	データ数の取得機能について、constのメソッドであるかのテスト
 * @deteils	ID:ハッシュテーブル-12(手動)
 */
TEST_F(HashTableManualTest, TestGetDataNumIsConst)
{
#if defined TEST_GET_DATA_NUM_IS_CONST
	EXPECT_EQ(m_HashTable.GetCount(), 0);
#endif // TEST_GET_DATA_NUM_IS_CONST
	SUCCEED();
}
/**
 * @brief	挿入機能について、非constのメソッドであるかのテスト
 * @deteils	ID:ハッシュテーブル-18(手動)
 */
TEST_F(HashTableManualTest, TestInsertIsConst)
{
#if defined TEST_INSERT_IS_CONST
	m_HashTable.Insert("test", 10);// ここでエラー
#endif // TEST_INSERT_IS_CONST
	SUCCEED();
}
/**
 * @brief	削除機能について、非constのメソッドであるかのテスト
 * @deteils	ID:ハッシュテーブル-18(手動)
 */
TEST_F(HashTableManualTest, TestEraseIsConst)
{
#if defined TEST_ERASE_IS_CONST
	m_HashTable.Erase("test");// ここでエラー
#endif // TEST_ERASE_IS_CONST
	SUCCEED();
}
/**
 * @brief	検索機能について、constのメソッドであるかのテスト
 * @deteils	ID:ハッシュテーブル-26(手動)
 */
TEST_F(HashTableManualTest, TestFindIsConst)
{
#if defined TEST_FIND_IS_CONST
	EXPECT_FALSE(m_HashTable.Find("test"));
#endif // TEST_FIND_IS_CONST
	SUCCEED();
}
