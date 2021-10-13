/**
 * @file ManualTest.cpp
 * @breif リストの手動テストファイル
 * @author MikamiYuto
 * @date 2021.10.07
 */


//------ インクルード
#include "ManualTest.h"
#include "gtest/gtest.h"
#include "../List/List.h"
#include "../List/Iterator.h"


namespace ex01
{
	namespace chapter02
	{
		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**
		 * @breif	データ数の取得機能について、constのメソッドであるかのテスト
		 * @deteils	ID:リスト-8(手動)
		 */
		TEST(ListManualTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_IS_CONST
			const List<int> list;
			EXPECT_EQ(0, list.GetCount());
#endif // TT_TEST_GET_DATA_NUM_IS_CONST
			SUCCEED();
		}
		/**
		 * @breif	リストのデータ追加について、非constが保証されているかのテスト
		 * @deteils	ID:リスト-15(手動)
		 */
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr = list.GetConstBegin();
			list.Insert(itr, 10);//ここでエラー
#endif // TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	リストのデータ削除について、非constが保証されているかのテスト
		 * @deteils	ID:リスト-22(手動)
		 */
		TEST(ListManualTest, TestEraseWhenConst)
		{
#if defined TT_TEST_ERASE_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr = list.GetConstBegin();
			list.Erase(itr);//ここでエラー
#endif// TT_TEST_ERASE_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	先頭イテレータの取得追加について、非constが保証されているかのテスト
		 * @deteils	ID:リスト-28(手動)
		 */
		TEST(ListManualTest, TestGetHeadIteratorWhenConst)
		{
#if defined TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			const List<int> list;
			Iterator<int> itr;
			itr = list.GetBegin(); // ここでエラー
#endif// TT_TEST_GET_HEAD_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	先頭コンストイテレータの取得追加について、constが保証されているかのテスト
		 * @deteils	ID:リスト-34(手動)
		 */
		TEST(ListManualTest, TestGetHeadConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_HEAD_CONST_ITERATOR_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr;
			itr = list.GetConstBegin();
#endif// TT_TEST_GET_HEAD_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	末尾イテレータの取得追加について、非constが保証されているかのテスト
		 * @deteils	ID:リスト-40(手動)
		 */
		TEST(ListManualTest, TestGetTailIteratorWhenConst)
		{
#if defined TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST
			const List<int> list;
			Iterator<int> itr;
			itr = list.GetEnd(); // ここでエラー
#endif// TT_TEST_GET_TAIL_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	末尾コンストイテレータの取得追加について、constが保証されているかのテスト
		 * @deteils	ID:リスト-46(手動)
		 */
		TEST(ListManualTest, TestGetTailConstIteratorWhenConst)
		{
#if defined TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST
			const List<int> list;
			ConstIterator<int> itr;
			itr = list.GetConstEnd();
#endif// TT_TEST_GET_TAIL_CONST_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	コンストイテレータから取得した要素に対して代入が行えるかのテスト
		 * @deteils	ID:イテレータ-2(手動)
		 */
		TEST(IteratorManualTest, TestGetIteratorWhenConst)
		{
#if defined TT_TEST_GET_ITERATOR_WHEN_CONST
			List<int> list;
			ConstIterator<int> itr;
			itr = list.GetConstBegin();
			list.Insert(itr, 10);
			itr = list.GetConstBegin();
			*itr = 100; // ここでエラー
#endif// TT_TEST_GET_ITERATOR_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	コンストイテレータからイテレータのコピーが作成されないかのテスト
		 * @deteils	ID:イテレータ-17(手動)
		 */
		TEST(IteratorManualTest, TestIteratorCopyWhenConst)
		{
#if defined TT_TEST_ITERATOR_COPY_WHEN_CONST
			ConstIterator<int> constItr;
			Iterator<int> itr(constItr); // ここでエラー
#endif// TT_TEST_ITERATOR_COPY_WHEN_CONST
			SUCCEED();
		}
		/**
		 * @breif	イテレータにコンストイテレータを代入できないかのテスト
		 * @deteils	ID:イテレータ-19(手動)
		 */
		TEST(IteratorManualTest, TestIteratorAssignWhenConst)
		{
#if defined TT_TEST_ITERATOR_ASSIGN_WHEN_CONST
			Iterator<int> itr;
			ConstIterator<int> constItr;
			itr = constItr; // ここでエラー
#endif// TT_TEST_ITERATOR_ASSIGN_WHEN_CONST
			SUCCEED();
		}
	}
}