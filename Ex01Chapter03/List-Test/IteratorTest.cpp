/**
 * @file IteratorTest.cpp
 * @breif テンプレートイテレータのテスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.143
 */

 //----- インクルード
#include "IteratorTest.h"


//=============================================================================
// イテレータの指す要素取得テスト
//=============================================================================
/**
 * @breif	リストの参照がない状態で呼び出した際の取得テスト
 * @deteils	ID:イテレータ-0
 */
TEST(GetIteratorDeathTest, TestGetIteratorWhenNotRefCall)
{
	// イテレータver
	{
		Iterator<int> itr;
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr;
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
}
/**
 * @breif	イテレータから取得した要素に対して値の代入を行えるかをテスト
 * @deteils	ID:イテレータ-1
 */
TEST(GetIteratorDeathTest, TestGetIteratorToAssign)
{
	List<int> list;
	Iterator<int> itr;
	// リストの要素を準備
	itr = list.GetBegin();
	ASSERT_TRUE(list.Insert(itr, 10));
	// リストから要素を指すイテレータを取得し、イテレータから値を代入
	itr = list.GetBegin();
	*itr = 100;
	EXPECT_EQ(*itr, 100) << "イテレータからの代入失敗";
}
/**
 * @breif	リストが空の際の先頭イテレータに対して呼び出した際の挙動テスト
 * @deteils	ID:イテレータ-3
 */
TEST(GetIteratorDeathTest, TestGetIteratorWhenEmptyToHeadCall)
{
	List<int> list;
	// イテレータver
	{
		Iterator<int> itr = list.GetBegin();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = list.GetConstBegin();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
}
/**
 * @breif	末尾イテレータに対して呼び出した際の挙動テスト
 * @deteils	ID:イテレータ-4
 */
TEST(GetIteratorDeathTest, TestGetIteratorTailToCall)
{
	List<int> list;
	// イテレータver
	{
		Iterator<int> itr = list.GetEnd();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = list.GetConstEnd();
		EXPECT_DEATH(*itr, "Assertion failed.*");
	}
}
//=============================================================================
// イテレータをリストの末尾に向けて一つ進める挙動テスト
//=============================================================================
/**
 * @breif	リストの参照がない状態でイテレータを末尾に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-5
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementWhenNotRef)
{
	Iterator<int> itr;
	ConstIterator<int> constItr;
	EXPECT_DEATH(++itr, "Assertion failed.*");
	EXPECT_DEATH(++constItr, "Assertion failed.*");
}
/**
 * @breif	リストが空の際の先頭イテレータを末尾に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-6
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementWhenEmptyForHead)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ConstIterator<int> constItr = list.GetConstBegin();
	EXPECT_DEATH(itr++, "Assertion failed.*");
	EXPECT_DEATH(constItr++, "Assertion failed.*");
}
/**
 * @breif	末尾イテレータに対して末尾に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-7
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementForTail)
{
	List<int> list;
	Iterator<int> itr = list.GetEnd();
	ConstIterator<int> constItr = list.GetConstEnd();
	EXPECT_DEATH(itr++, "Assertion failed.*");
	EXPECT_DEATH(constItr++, "Assertion failed.*");
}
/**
 * @breif	リストに二つ以上の要素がある場合に末尾に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-8
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrement)
{
	int checkDatas[] = { 0,1 };
	// イテレータver
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		Iterator<int> endItr = m_Lists[0].GetEnd();
		for (int i = 0; itr != endItr; ++i, ++itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "末尾へ進めたイテレータが指す要素が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ConstIterator<int> endItr = m_Lists[0].GetConstEnd();
		for (int i = 0; itr != endItr; ++i, ++itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "末尾へ進めたコンストイテレータが指す要素が異なります";
	}
}
/**
 * @breif	前置インクリメントを行った際の挙動テスト
 * @deteils	ID:イテレータ-9
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementPrefix)
{
	int checkDatas[] = { 0,1 };
	// イテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*++itr, checkDatas[1]) << "イテレータの前置インクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[1]) << "イテレータの前置インクリメント実行後の値が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*++itr, checkDatas[1]) << "コンストイテレータの前置インクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[1]) << "コンストイテレータの前置インクリメント実行後の値が異なります";
	}
}
/**
 * @breif	後置インクリメントを行った際の挙動テスト
 * @deteils	ID:イテレータ-10
 */
TEST_F(IteratorIncrementTest, TestIteratorIncrementPostfix)
{
	int checkDatas[] = { 0,1 };
	// イテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*itr++, checkDatas[0]) << "イテレータの後置インクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[1]) << "イテレータの後置インクリメント実行後の値が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		EXPECT_EQ(*itr++, checkDatas[0]) << "コンストイテレータの後置インクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[1]) << "コンストイテレータの後置インクリメント実行後の値が異なります";
	}
}
//=============================================================================
// イテレータをリストの先頭に向けて一つ進める挙動テスト
//=============================================================================
/**
 * @breif	リストの参照がない状態でイテレータを先頭に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-11
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementWhenNotRef)
{
	Iterator<int> itr;
	ConstIterator<int> constItr;
	EXPECT_DEATH(itr--, "Assertion failed.*");
	EXPECT_DEATH(constItr--, "Assertion failed.*");
}
/**
 * @breif	リストが空の際の末尾イテレータを先頭に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-12
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementWhenEmptyForTail)
{
	List<int> list;
	Iterator<int> itr = list.GetEnd();
	ConstIterator<int> constItr = list.GetConstEnd();
	EXPECT_DEATH(itr--, "Assertion failed.*");
	EXPECT_DEATH(constItr--, "Assertion failed.*");
}
/**
 * @breif	先頭イテレータに対して先頭に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-13
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementForHead)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ConstIterator<int> constItr = list.GetConstBegin();
	EXPECT_DEATH(itr--, "Assertion failed.*");
	EXPECT_DEATH(constItr--, "Assertion failed.*");
}
/**
 * @breif	リストに二つ以上の要素がある場合に先頭に向けて進めた際の挙動テスト
 * @deteils	ID:イテレータ-14
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrement)
{
	int checkDatas[] = { 1,0 };
	// イテレータver
	{
		Iterator<int> itr = m_Lists[0].GetEnd();
		Iterator<int> endItr = m_Lists[0].GetBegin();
		--itr;
		for (int i = 0; itr != endItr; ++i, --itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "先頭へ進めたイテレータが指す要素が異なります";
		EXPECT_EQ(*itr, *endItr) << "先頭へ進めたイテレータが指す要素が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		ConstIterator<int> endItr = m_Lists[0].GetConstBegin();
		--itr;
		for (int i = 0; itr != endItr; ++i, --itr)
			EXPECT_EQ(*itr, checkDatas[i]) << "先頭へ進めたコンストイテレータが指す要素が異なります";
		EXPECT_EQ(*itr, *endItr) << "先頭へ進めたコンストイテレータが指す要素が異なります";
	}
}
/**
 * @breif	前置デクリメントを行った際の挙動テスト
 * @deteils	ID:イテレータ-15
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementPrefix)
{
	int checkDatas[] = { 0,1 };
	// イテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*--itr, checkDatas[0]) << "イテレータの後置デクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[0]) << "イテレータの後置デクリメント実行後の値が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*--itr, checkDatas[0]) << "コンストイテレータの後置デクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[0]) << "コンストイテレータの後置デクリメント実行後の値が異なります";
	}
}
/**
 * @breif	後置デクリメントを行った際の挙動テスト
 * @deteils	ID:イテレータ-16
 */
TEST_F(IteratorDecrementTest, TestIteratorDecrementPostfix)
{
	int checkDatas[] = { 0,1 };
	// イテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*itr--, checkDatas[1]) << "イテレータの後置デクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[0]) << "イテレータの後置デクリメント実行後の値が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr = m_Lists[0].GetConstEnd();
		--itr;
		EXPECT_EQ(*itr--, checkDatas[1]) << "コンストイテレータの後置デクリメント呼び出し時の値が異なります";
		EXPECT_EQ(*itr, checkDatas[0]) << "コンストイテレータの後置デクリメント実行後の値が異なります";
	}
}
//=============================================================================
// イテレータのコピーを行った際の挙動テスト
//=============================================================================
/**
 * @breif	イテレータのコピーコンストラクタ後の値がコピー元と等しいかテスト
 * @deteils	ID:イテレータ-18
 */
TEST(IteratorCopyConstructerTest, TestIteratorCopyConstructerEqual)
{
	// イテレータver
	{
		Iterator<int> itr;
		Iterator<int> copyItr(itr);
		EXPECT_EQ(itr, copyItr) << "コピーコンストラクタ後のイテレータとコピー元の値が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr;
		ConstIterator<int> copyItr(itr);
		EXPECT_EQ(itr, copyItr) << "コピーコンストラクタ後のコンストイテレータとコピー元の値が異なります";
	}
}
//=============================================================================
// イテレータの代入を行った際の挙動テスト
//=============================================================================
/**
 * @breif	代入後の値がコピー元と等しいかテスト
 * @deteils	ID:イテレータ-20
 */
TEST(IteratorAssignTest, TestIteratorAssignEqual)
{
	// イテレータver
	{
		Iterator<int> itr;
		Iterator<int> copyItr;
		copyItr = itr;
		EXPECT_EQ(itr, copyItr) << "代入後のイテレータとコピー元の値が異なります";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr;
		ConstIterator<int> copyItr;
		copyItr = itr;
		EXPECT_EQ(itr, copyItr) << "代入後のコンストイテレータとコピー元の値が異なります";
	}
}
//=============================================================================
// 二うのイテレータが同一のものであるか等価比較テスト
//=============================================================================
/**
 * @breif	空リスト時の先頭イテレータと末尾イテレータの比較をした際の挙動テスト
 * @deteils	ID:イテレータ-21
 */
TEST(IteratorEqualTest, TestIteratorEqualHeadAndTail)
{
	List<int> list;
	EXPECT_TRUE(list.GetBegin() == list.GetEnd()) << "空リスト時の先頭と末尾イテレータが異なります";
	EXPECT_TRUE(list.GetConstBegin() == list.GetConstEnd()) << "空リスト時の先頭と末尾コンストイテレータが異なります";
}
/**
 * @breif	同一のイテレータを比較した際の挙動テスト
 * @deteils	ID:イテレータ-22
 */
TEST(IteratorEqualTest, TestIteratorEqualSame)
{
	// イテレータver
	{
		Iterator<int> itr;
		EXPECT_TRUE(itr == itr) << "同一イテレータを等価比較した結果、違うものと判定されました";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr;
		EXPECT_TRUE(itr == itr) << "同一コンストイテレータを等価比較した結果、違うものと判定されました";
	}
}
/**
 *@breif	異なるイテレータを比較した際の挙動テスト
 * @deteils	ID:イテレータ-23
 */
TEST(IteratorEqualTest, TestIteratorEqualOther)
{
	List<int> list1;
	List<int> list2;
	// イテレータver
	{
		Iterator<int> itr1 = list1.GetBegin();
		Iterator<int> itr2 = list2.GetBegin();
		EXPECT_FALSE(itr1 == itr2) << "異なるイテレータを等価比較した結果、同じものと判定されました";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr1 = list1.GetConstBegin();
		ConstIterator<int> itr2 = list2.GetConstBegin();
		EXPECT_FALSE(itr1 == itr2) << "異なるコンストイテレータを等価比較した結果、同じものと判定されました";
	}
}
//=============================================================================
// 二うのイテレータが異なるものであるか非等価比較テスト
//=============================================================================
/**
 * @breif	空リスト時の先頭イテレータと末尾イテレータの比較をした際の挙動テスト
 * @deteils	ID:イテレータ-24
 */
TEST(IteratorNotEqualTest, TestIteratorNotEqualHeadAndTail)
{
	List<int> list;
	EXPECT_FALSE(list.GetBegin() != list.GetEnd()) << "空リスト時の先頭と末尾イテレータが異なります";
	EXPECT_FALSE(list.GetConstBegin() != list.GetConstEnd()) << "空リスト時の先頭と末尾コンストイテレータが異なります";
}
/**
 * @breif	同一のイテレータを比較した際の挙動テスト
 * @deteils	ID:イテレータ-25
 */
TEST(IteratorNotEqualTest, TestIteratorNotEqualSame)
{
	// イテレータver
	{
		Iterator<int> itr;
		EXPECT_FALSE(itr != itr) << "同一イテレータを非等価比較した結果、違うものと判定されました";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr;
		EXPECT_FALSE(itr != itr) << "同一コンストイテレータを非等価比較した結果、違うものと判定されました";
	}
}
/**
 *@breif	異なるイテレータを比較した際の挙動テスト
 * @deteils	ID:イテレータ-26
 */
TEST(IteratorNotEqualTest, TestIteratorNotEqualOther)
{
	List<int> list1;
	List<int> list2;
	// イテレータver
	{
		Iterator<int> itr1 = list1.GetBegin();
		Iterator<int> itr2 = list2.GetBegin();
		EXPECT_TRUE(itr1 != itr2) << "異なるイテレータを非等価比較した結果、同じものと判定されました";
	}
	// コンストイテレータver
	{
		ConstIterator<int> itr1 = list1.GetConstBegin();
		ConstIterator<int> itr2 = list2.GetConstBegin();
		EXPECT_TRUE(itr1 != itr2) << "異なるコンストイテレータを非等価比較した結果、同じものと判定されました";
	}
}

