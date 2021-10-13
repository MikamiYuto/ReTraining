/**
 * @file QueueTest.cpp
 * @breif テンプレートキュークラスのテスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */


 //----- インクルード
#include "QueueTest.h"


//=============================================================================
// データ数の取得テスト
//=============================================================================
/**
 * @breif	キューが空である場合のデータ数の取得テスト
 * @deteils	ID:キュー-0
 */
TEST(QueueGetDataNumTest, TestGetDataNumWhenEmpty)
{
	Queue<int> queue;
	EXPECT_EQ(0, queue.GetCount());
}
/**
 * @breif	要素をプッシュした後のデータ数の取得テスト
 * @deteils	ID:キュー-1
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPush)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	EXPECT_EQ(1, queue.GetCount());
}
/**
 * @breif	要素をポップした後のデータ数の取得テスト
 * @deteils	ID:キュー-2
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPop)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	ASSERT_FALSE(queue.Pop());
	EXPECT_EQ(0, queue.GetCount());
}
/**
 * @breif	要素のプッシュに失敗した後のデータ数の取得テスト
 * @deteils	ID:キュー-3
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPushFailed)
{
	// 挿入失敗はメモリ確保失敗時のためここではスキップ
	//Queue<int> queue;
	//ASSERT_FALSE(queue.Push(0));
	//EXPECT_EQ(0, queue.GetCount());
}
/**
 * @breif	要素を2回プッシュした後のデータ数の取得テスト
 * @deteils	ID:キュー-4
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPushX2)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	ASSERT_TRUE(queue.Push(1));
	EXPECT_EQ(2, queue.GetCount());
}
/**
 * @breif	要素を2回プッシュし、1回ポップした後のデータ数の取得テスト
 * @deteils	ID:キュー-5
 */
TEST(QueueGetDataNumTest, TestGetDataNumAfterPushX2Pop)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(0));
	ASSERT_TRUE(queue.Push(1));
	ASSERT_TRUE(queue.Pop());
	EXPECT_EQ(1, queue.GetCount());
}
/**
 * @breif	キューが空である場合にポップした後のデータ数の取得テスト
 * @deteils	ID:キュー-6
 */
TEST(QueueGetDataNumTest, TestGetDataNumWhenEmptyAfterPop)
{
	Queue<int> queue;
	ASSERT_FALSE(queue.Pop());
	EXPECT_EQ(0, queue.GetCount());
}
//=============================================================================
// プッシュ時の挙動テスト
//=============================================================================
/**
 * @breif	キューが空である時にプッシュした際の挙動テスト
 * @deteils	ID:キュー-8
 */
TEST(QueuePushTest, TestPushWhenEmpty)
{
	Queue<int> queue;
	EXPECT_TRUE(queue.Push(10));
	//　挿入要素のチェック
	int check = 0;
	ASSERT_TRUE(queue.Pop(&check));
	EXPECT_EQ(check, 10);
}
/**
 * @breif	キューに複数要素がある時にプッシュした際の挙動テスト
 * @deteils	ID:キュー-9
 */
TEST(QueuePushTest, TestPush)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(10));
	ASSERT_TRUE(queue.Push(20));
	EXPECT_TRUE(queue.Push(30));
	//　挿入要素のチェック
	int checkDatas[] = { 10,20,30 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		ASSERT_TRUE(queue.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}
//=============================================================================
// ポップ時の挙動テスト
//=============================================================================
/**
 * @breif	キューが空である時にポップした際の挙動テスト
 * @deteils	ID:キュー-11
 */
TEST(QueuePopTest, TestPopWhenEmpty)
{
	Queue<int> queue;
	int check = 0;
	EXPECT_FALSE(queue.Pop(&check));
	// 受取先が何もされていないかチェック
	EXPECT_EQ(check, 0);
}
/**
 * @breif	キューに複数要素がある時にポップした際の挙動テスト
 * @deteils	ID:キュー-12
 */
TEST(QueuePopTest, TestPop)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(10));
	ASSERT_TRUE(queue.Push(20));
	ASSERT_TRUE(queue.Push(30));
	int check = 0;
	EXPECT_TRUE(queue.Pop(&check));
	// 取得要素のチェック
	EXPECT_EQ(check, 10);
}
/**
 * @breif	キューに複数要素がある時に複数回ポップした際の挙動テスト
 * @deteils	ID:キュー-13
 */
TEST(QueuePopTest, TestPopMany)
{
	Queue<int> queue;
	ASSERT_TRUE(queue.Push(10));
	ASSERT_TRUE(queue.Push(20));
	ASSERT_TRUE(queue.Push(30));
	int checkDatas[] = { 10,20,30 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		EXPECT_TRUE(queue.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}