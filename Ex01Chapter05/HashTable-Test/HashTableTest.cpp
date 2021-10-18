/**
 * @file StackTest.cpp
 * @brief テンプレートスタッククラスのテスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.14
 */


 //----- インクルード
#include "HashTableTest.h"


//=============================================================================
// クラスの挙動テスト
//=============================================================================
/**
 * @brief	算出方法の異なる適切なハッシュ関数を渡したときのそれぞれの挙動テスト
 * @deteils	ID:リスト-1
 */
TEST(HashTableClassTest, TestHashTableClass)
{
	// 文字列からハッシュ値を導出する関数を渡した場合
	{
		HashTable<std::string, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
		const std::string key = "test";
		const int value = 10;
		int check = 0;
		// 各動作のチェック
		EXPECT_TRUE(hashTable.Insert(key, value));	// 挿入
		EXPECT_TRUE(hashTable.Find(key, &check));	// 検索
		EXPECT_EQ(check, value);					// 検索で取得した値
		EXPECT_TRUE(hashTable.Erase(key));			// 削除
	}
	// 整数からハッシュ値を導出する関数を渡した場合
	{
		HashTable<int, int, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
		const int key = 100;
		const int value = 10;
		int check = 0;
		// 各動作のチェック
		EXPECT_TRUE(hashTable.Insert(key, value));	// 挿入
		EXPECT_TRUE(hashTable.Find(key, &check));	// 検索
		EXPECT_EQ(check, value);					// 検索で取得した値
		EXPECT_TRUE(hashTable.Erase(key));			// 削除
	}
}
//=============================================================================
// データ数の取得テスト
//=============================================================================
/**
 * @brief	リストが空である場合のデータ数の取得テスト
 * @deteils	ID:リスト-2
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumWhenEmpty)
{
	EXPECT_EQ(m_HashTable.GetCount(), 0);
}
/**
 * @brief	要素を挿入した後のデータ数の取得テスト
 * @deteils	ID:リスト-3
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterInsert)
{
	ASSERT_TRUE(m_HashTable.Insert("test", 10));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	要素を挿入し、そのキーで削除した後のデータ数の取得テスト
 * @deteils	ID:リスト-4
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterInsertToErase)
{
	const std::string key = "test";
	ASSERT_TRUE(m_HashTable.Insert(key, 10));
	ASSERT_TRUE(m_HashTable.Erase(key));
	EXPECT_EQ(m_HashTable.GetCount(), 0);
}
/**
 * @brief	既に存在するキーで要素の挿入をし失敗した後のデータ数の取得テスト
 * @deteils	ID:リスト-5
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterInsertFailed)
{
	const std::string key = "test";
	ASSERT_TRUE(m_HashTable.Insert(key, 10));
	ASSERT_FALSE(m_HashTable.Insert(key, 20));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	要素が存在している時に存在しないキーでの削除に失敗した後のデータ数の取得テスト
 * @deteils	ID:リスト-6
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterEraseFailed)
{
	ASSERT_TRUE(m_HashTable.Insert("test", 10));
	ASSERT_FALSE(m_HashTable.Erase("check"));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	リストが空である時に削除を行った後のデータ数の取得テスト
 * @deteils	ID:リスト-7
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumAfterEraseWhenEmpty)
{
	ASSERT_FALSE(m_HashTable.Erase("test"));
	EXPECT_EQ(m_HashTable.GetCount(), 0);
}
/**
 * @brief	要素２つが内部でチェインになっていない時のデータ数の取得テスト
 * @deteils	ID:リスト-8
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumUnChain)
{
	SetUpUnChainHash();
	EXPECT_EQ(m_HashTable.GetCount(), 2);
}
/**
 * @brief	要素２つが内部でチェインになっていない時に一方を削除した後のデータ数の取得テスト
 * @deteils	ID:リスト-9
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumUnChainOtherErase)
{
	SetUpUnChainHash();
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
/**
 * @brief	要素２つが内部でチェインになっている時のデータ数の取得テスト
 * @deteils	ID:リスト-10
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumChain)
{
	SetUpChainHash();
	EXPECT_EQ(m_HashTable.GetCount(), 2);
}
/**
 * @brief	要素２つが内部でチェインになっている時に一方を削除した後のデータ数の取得テスト
 * @deteils	ID:リスト-11
 */
TEST_F(HashTableGetDataNumTest, TestGetDataNumChainOtherErase)
{
	SetUpChainHash();
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_EQ(m_HashTable.GetCount(), 1);
}
//=============================================================================
// データの挿入テスト
//=============================================================================
/**
 * @brief	リストが空である時に挿入した際の挙動テスト
 * @deteils	ID:リスト-13
 */
TEST_F(HashTableInsertTest, TestInsertWhenEmpty)
{
	EXPECT_TRUE(m_HashTable.Insert("test", 10));
}
/**
 * @brief	複数要素がある場合に、キーを重複しないで挿入した際の挙動テスト
 * @deteils	ID:リスト-14
 */
TEST_F(HashTableInsertTest, TestInsertUnDup)
{
	SetUpUnChainHash();
	EXPECT_TRUE(m_HashTable.Insert("test", 10));
}
/**
 * @brief	複数要素がある場合に、キーを重複して挿入した際の挙動テスト
 * @deteils	ID:リスト-15
 */
TEST_F(HashTableInsertTest, TestInsertDup)
{
	SetUpUnChainHash();
	EXPECT_FALSE(m_HashTable.Insert("one", 10));
}
/**
 * @brief	複数要素がある場合に、ハッシュ値が同じにあるキーで挿入した際の挙動テスト
 * @deteils	ID:リスト-16
 */
TEST_F(HashTableInsertTest, TestInsertChain)
{
	SetUpUnChainHash();
	EXPECT_TRUE(m_HashTable.Insert("two", 10));
}
/**
 * @brief	一度挿入し削除、そして再度同じキーで挿入した際の挙動テスト
 * @deteils	ID:リスト-17
 */
TEST_F(HashTableInsertTest, TestInsertReInsert)
{
	const std::string key = "test";
	const int value = 10;
	ASSERT_TRUE(m_HashTable.Insert(key, value));
	ASSERT_TRUE(m_HashTable.Erase(key));
	EXPECT_TRUE(m_HashTable.Insert(key, value));
}
//=============================================================================
// データの削除テスト
//=============================================================================
/**
 * @brief	リストが空である時に削除した際の挙動テスト
 * @deteils	ID:リスト-19
 */
TEST_F(HashTableEraseTest, TestEraseWhenEmpty)
{
	EXPECT_FALSE(m_HashTable.Erase("test"));
}
/**
 * @brief	複数要素がある場合に、存在するキーで削除した際の挙動テスト
 * @deteils	ID:リスト-20
 */
TEST_F(HashTableEraseTest, TestEraseExistKey)
{
	SetUpUnChainHash();
	EXPECT_TRUE(m_HashTable.Erase("one"));
}
/**
 * @brief	複数要素がある場合に、存在しないキーで削除した際の挙動テスト
 * @deteils	ID:リスト-21
 */
TEST_F(HashTableEraseTest, TestEraseNotExistKey)
{
	SetUpUnChainHash();
	EXPECT_FALSE(m_HashTable.Erase("test"));
}
/**
 * @brief	一度削除したキーで再度削除した際の挙動テスト
 * @deteils	ID:リスト-22
 */
TEST_F(HashTableEraseTest, TestEraseReErase)
{
	SetUpUnChainHash();
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_FALSE(m_HashTable.Erase("one"));
}
/**
 * @brief	チェインした要素のうちのキーを指定して削除した際の挙動テスト
 * @deteils	ID:リスト-23
 */
TEST_F(HashTableEraseTest, TestEraseChainOther)
{
	SetUpChainHash();
	EXPECT_TRUE(m_HashTable.Erase("one"));
}
/**
 * @brief	チェインした要素のうちのキーとハッシュ値が同じだが、存在しないキーで削除した際の挙動テスト
 * @deteils	ID:リスト-24
 */
TEST_F(HashTableEraseTest, TestEraseChainEqualHashAndNotExistKey)
{
	SetUpChainHash();
	EXPECT_FALSE(m_HashTable.Erase("six"));
}
/**
 * @brief	チェインになっている要素を順に削除した際の挙動テスト
 * @deteils	ID:リスト-25
 */
TEST_F(HashTableEraseTest, TestEraseChainAll)
{
	SetUpChainHash();
	EXPECT_TRUE(m_HashTable.Erase("one"));
	EXPECT_TRUE(m_HashTable.Erase("two"));
}
//=============================================================================
// データの検索テスト
//=============================================================================
/**
 * @brief	リストが空である時に検索した際の挙動テスト
 * @deteils	ID:リスト-27
 */
TEST_F(HashTableFindTest, TestFindWhenEmpty)
{
	int check = 0;
	EXPECT_FALSE(m_HashTable.Find("test", &check));
	// 受取先に変な値が代入されていないかチェック
	EXPECT_EQ(check, 0);
}
/**
 * @brief	複数要素がある時に存在するキーで検索した際の挙動テスト
 * @deteils	ID:リスト-28
 */
TEST_F(HashTableFindTest, TestFindExistKey)
{
	SetUpUnChainHash();
	int check = 0;
	EXPECT_TRUE(m_HashTable.Find("one", &check));
	// 取得した値をチェック
	EXPECT_EQ(check, 1);
}
/**
 * @brief	複数要素がある時に存在しないキーで検索した際の挙動テスト
 * @deteils	ID:リスト-29
 */
TEST_F(HashTableFindTest, TestFindNotExistKey)
{
	SetUpUnChainHash();
	int check = 0;
	EXPECT_FALSE(m_HashTable.Find("test", &check));
	// 受取先に変な値が代入されていないかチェック
	EXPECT_EQ(check, 0);
}
/**
 * @brief	複数要素がある時に存在するキーで2回連続検索した際の挙動テスト
 * @deteils	ID:リスト-30
 */
TEST_F(HashTableFindTest, TestFindExistKeyX2)
{
	SetUpUnChainHash();
	const std::string key = "one";
	int check = 0;
	EXPECT_TRUE(m_HashTable.Find(key, &check));
	EXPECT_EQ(check, 1);
	// ２回目のチェック
	check = 0;
	EXPECT_TRUE(m_HashTable.Find(key, &check));
	EXPECT_EQ(check, 1);
}
/**
 * @brief	既に削除されたキーで検索した際の挙動テスト
 * @deteils	ID:リスト-31
 */
TEST_F(HashTableFindTest, TestFindEraseKey)
{
	SetUpUnChainHash();
	const std::string key = "one";
	int check = 0;
	ASSERT_TRUE(m_HashTable.Erase(key));
	EXPECT_FALSE(m_HashTable.Find(key, &check));
	// 変な値が代入されていないかチェック
	EXPECT_EQ(check, 0);
}
/**
 * @brief	チェインした要素がある時に、そのうちの1つのを検索した際の挙動テスト
 * @deteils	ID:リスト-32
 */
TEST_F(HashTableFindTest, TestFindChain)
{
	SetUpChainHash();
	int check = 0;
	EXPECT_TRUE(m_HashTable.Find("one", &check));
	// 取得した値をチェック
	EXPECT_EQ(check, 1);
}
/**
 * @brief	チェインした要素がある時に、そのうちの1つを削除し残っている要素を検索した際の挙動テスト
 * @deteils	ID:リスト-33
 */
TEST_F(HashTableFindTest, TestFindChainOtherErase)
{
	SetUpChainHash();
	int check = 0;
	ASSERT_TRUE(m_HashTable.Erase("one"));
	EXPECT_TRUE(m_HashTable.Find("two", &check));
	// 取得した値をチェック
	EXPECT_EQ(check, 2);
}