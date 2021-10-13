/**
 * @file ManualTest.cpp
 * @breif スタックのコンパイル関連手動テスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */


//----- インクルード
#include "StackManualTest.h"


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
/**
 * @breif	データ数の取得機能について、constのメソッドであるかのテスト
 * @deteils	ID:スタック-7(手動)
 */
TEST(StackManualTest, TestGetDataNumIsConst)
{
#if defined TEST_GET_DATA_NUM_IS_CONST
	const Stack<int> stack;
	EXPECT_EQ(stack.GetCount(), 0);
#endif // TEST_GET_DATA_NUM_IS_CONST
	SUCCEED();
}
/**
 * @breif	プッシュについて、非constのメソッドであるかのテスト
 * @deteils	ID:スタック-10(手動)
 */
TEST(StackManualTest, TestPushIsConst)
{
#if defined TEST_PUSH_IS_CONST
	const Stack<int> stack;
	stack.Push(10);// ここでエラー
#endif // TEST_PUSH_IS_CONST
	SUCCEED();
}
/**
 * @breif	ポップについて、非constのメソッドであるかのテスト
 * @deteils	ID:スタック-14(手動)
 */
TEST(StackManualTest, TestPopIsConst)
{
#if defined TEST_POP_IS_CONST
	const Stack<int> stack;
	stack.Pop();// ここでエラー
#endif // TEST_POP_IS_CONST
	SUCCEED();
}