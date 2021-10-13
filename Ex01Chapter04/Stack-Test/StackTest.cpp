/**
 * @file StackTest.cpp
 * @breif テンプレートスタッククラスのテスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */


 //----- インクルード
#include "StackTest.h"


//=============================================================================
// データ数の取得テスト
//=============================================================================
/**
 * @breif	スタックが空である場合のデータ数の取得テスト
 * @deteils	ID:スタック-0
 */
TEST(StackGetDataNumTest, TestGetDataNumWhenEmpty)
{
	Stack<int> stack;
	EXPECT_EQ(0, stack.GetCount());
}
/**
 * @breif	要素をプッシュした後のデータ数の取得テスト
 * @deteils	ID:スタック-1
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPush)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	EXPECT_EQ(1, stack.GetCount());
}
/**
 * @breif	要素をポップした後のデータ数の取得テスト
 * @deteils	ID:スタック-2
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPop)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	ASSERT_FALSE(stack.Pop());
	EXPECT_EQ(0, stack.GetCount());
}
/**
 * @breif	要素のプッシュに失敗した後のデータ数の取得テスト
 * @deteils	ID:スタック-3
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPushFailed)
{
	// 挿入失敗はメモリ確保失敗時のためここではスキップ
	//Stack<int> stack;
	//ASSERT_FALSE(stack.Push(0));
	//EXPECT_EQ(0, stack.GetCount());
}
/**
 * @breif	要素を2回プッシュした後のデータ数の取得テスト
 * @deteils	ID:スタック-4
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPushX2)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Push(1));
	EXPECT_EQ(2, stack.GetCount());
}
/**
 * @breif	要素を2回プッシュし、1回ポップした後のデータ数の取得テスト
 * @deteils	ID:スタック-5
 */
TEST(StackGetDataNumTest, TestGetDataNumAfterPushX2Pop)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(0));
	ASSERT_TRUE(stack.Push(1));
	ASSERT_TRUE(stack.Pop());
	EXPECT_EQ(1, stack.GetCount());
}
/**
 * @breif	スタックが空である場合にポップした後のデータ数の取得テスト
 * @deteils	ID:スタック-6
 */
TEST(StackGetDataNumTest, TestGetDataNumWhenEmptyAfterPop)
{
	Stack<int> stack;
	ASSERT_FALSE(stack.Pop());
	EXPECT_EQ(0, stack.GetCount());
}
//=============================================================================
// プッシュ時の挙動テスト
//=============================================================================
/**
 * @breif	スタックが空である時にプッシュした際の挙動テスト
 * @deteils	ID:スタック-8
 */
TEST(StackPushTest, TestPushWhenEmpty)
{
	Stack<int> stack;
	EXPECT_TRUE(stack.Push(10));
	//　挿入要素のチェック
	int check = 0;
	ASSERT_TRUE(stack.Pop(&check));
	EXPECT_EQ(check, 10);
}
/**
 * @breif	スタックに複数要素がある時にプッシュした際の挙動テスト
 * @deteils	ID:スタック-9
 */
TEST(StackPushTest, TestPush)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(10));
	ASSERT_TRUE(stack.Push(20));
	EXPECT_TRUE(stack.Push(30));
	//　挿入要素のチェック
	int checkDatas[] = { 30,20,10 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		ASSERT_TRUE(stack.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}
//=============================================================================
// ポップ時の挙動テスト
//=============================================================================
/**
 * @breif	スタックが空である時にポップした際の挙動テスト
 * @deteils	ID:スタック-11
 */
TEST(StackPopTest, TestPopWhenEmpty)
{
	Stack<int> stack;
	int check = 0;
	EXPECT_FALSE(stack.Pop(&check));
	// 受取先が何もされていないかチェック
	EXPECT_EQ(check, 0);
}
/**
 * @breif	スタックに複数要素がある時にポップした際の挙動テスト
 * @deteils	ID:スタック-12
 */
TEST(StackPopTest, TestPop)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(10));
	ASSERT_TRUE(stack.Push(20));
	ASSERT_TRUE(stack.Push(30));
	int check = 0;
	EXPECT_TRUE(stack.Pop(&check));
	// 取得要素のチェック
	EXPECT_EQ(check, 30);
}
/**
 * @breif	スタックに複数要素がある時に複数回ポップした際の挙動テスト
 * @deteils	ID:スタック-13
 */
TEST(StackPopTest, TestPopMany)
{
	Stack<int> stack;
	ASSERT_TRUE(stack.Push(10));
	ASSERT_TRUE(stack.Push(20));
	ASSERT_TRUE(stack.Push(30));
	int checkDatas[] = { 30,20,10 };
	int check = 0;
	for (int i = 0; i < 3; ++i)
	{
		EXPECT_TRUE(stack.Pop(&check));
		EXPECT_EQ(check, checkDatas[i]);
	}
}