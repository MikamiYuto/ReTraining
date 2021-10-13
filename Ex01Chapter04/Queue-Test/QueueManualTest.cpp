/**
 * @file QueueManualTest.cpp
 * @breif キューのコンパイル関連手動テスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */


//----- インクルード
#include "QueueManualTest.h"


//--------------------------------------------------------------------------------
// コンパイル関連手動テスト
//--------------------------------------------------------------------------------
/**
 * @breif	データ数の取得機能について、constのメソッドであるかのテスト
 * @deteils	ID:キュー-7(手動)
 */
TEST(QueueManualTest, TestGetDataNumIsConst)
{
#if defined TEST_GET_DATA_NUM_IS_CONST
	const Queue<int> queue;
	EXPECT_EQ(queue.GetCount(), 0);
#endif // TEST_GET_DATA_NUM_IS_CONST
	SUCCEED();
}
/**
 * @breif	プッシュについて、非constのメソッドであるかのテスト
 * @deteils	ID:キュー-10(手動)
 */
TEST(QueueManualTest, TestPushIsConst)
{
#if defined TEST_PUSH_IS_CONST
	const Queue<int> queue;
	queue.Push(10);// ここでエラー
#endif // TEST_PUSH_IS_CONST
	SUCCEED();
}
/**
 * @breif	ポップについて、非constのメソッドであるかのテスト
 * @deteils	ID:キュー-14(手動)
 */
TEST(QueueManualTest, TestPopIsConst)
{
#if defined TEST_POP_IS_CONST
	const Queue<int> queue;
	queue.Pop();// ここでエラー
#endif // TEST_POP_IS_CONST
	SUCCEED();
}