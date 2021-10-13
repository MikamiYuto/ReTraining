/**
 * @file ListTest.cpp
 * @breif テンプレートリストクラスのテスト実装ファイル
 * @author MikamiYuto
 * @date 2021.10.12
 */


//----- インクルード
#include "ListTest.h"


//=============================================================================
// データ数の取得テスト
//=============================================================================
/**
 * @breif	リストが空である場合のデータ数の取得テスト
 * @deteils	ID:リスト-0
 */
TEST_F(ListGetDataNumTest, TestGetDataNumWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(0, list.GetCount()) << "空リストからのデータ数取得失敗";
}
/**
 * @breif	リスト末尾への挿入を行った際のデータ数の取得テスト
 * @deteils	ID:リスト-1
 */
TEST_F(ListGetDataNumTest, TestGetDataNumAfterPush)
{
	List<int> list;
	Iterator<int> itr = list.GetEnd();
	ASSERT_TRUE(list.Insert(itr, 10));
	EXPECT_EQ(1, list.GetCount()) << "リスト末尾へ挿入後のデータ数取得失敗";
}
/**
 * @breif	リスト末尾への挿入が失敗した際のデータ数の取得テスト
 * @deteils	ID:リスト-2
 */
TEST_F(ListGetDataNumTest, TestGetDataNumAfterPushFailed)
{
	// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
	//List<int> list;
	//Iterator<int> itr = list.GetEnd();
	//ASSERT_FALSE(list.Insert(itr, 10));
	//EXPECT_EQ(1, list.GetCount()) << "リスト末尾へ挿入失敗後のデータ数取得失敗";
}
/**
 * @breif	データの挿入を行った際のデータ数の取得テスト
 * @deteils	ID:リスト-3
 */
TEST_F(ListGetDataNumTest, TestGetDataNumPush)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ASSERT_TRUE(list.Insert(itr, 10));
	EXPECT_EQ(1, list.GetCount()) << "リストへ要素挿入後のデータ数取得失敗";
}
/**
 * @breif	データの挿入に失敗した際のデータ数の取得テスト
 * @deteils	ID:リスト-4
 */
TEST_F(ListGetDataNumTest, TestGetDataNumPushFailed)
{
	// "挿入失敗はメモリ確保失敗時のためここではスキップ
	//List<int> list;
	//Iterator<int> itr = list.GetBegin();
	//ASSERT_TRUE(list.Insert(itr, 10));
	//EXPECT_EQ(1, list.GetCount()) << "リストへ要素挿入失敗後のデータ数取得失敗";
}
/**
 * @breif	データの削除を行った際のデータ数の取得テスト
 * @deteils	ID:リスト-5
 */
TEST_F(ListGetDataNumTest, TestGetDataNumErase)
{
	Iterator<int> itr = m_Lists[0].GetBegin();
	ASSERT_TRUE(m_Lists[0].Erase(itr));
	EXPECT_EQ(1, m_Lists[0].GetCount()) << "リストの要素削除後のデータ数取得失敗";
}
/**
 * @breif	データの削除に失敗した際のデータ数の取得テスト
 * @deteils	ID:リスト-6
 */
TEST_F(ListGetDataNumTest, TestGetDataNumEraseFailed)
{
	Iterator<int> itr = m_Lists[1].GetBegin();
	// 不正なイテレータを設定
	ASSERT_FALSE(m_Lists[0].Erase(itr));
	EXPECT_EQ(2, m_Lists[0].GetCount()) << "リストの要素削除失敗時のデータ数取得失敗";
}
/**
 * @breif	リストが空である場合に、データの削除を行った際のデータ数の取得テスト
 * @deteils	ID:リスト-7
 */
TEST_F(ListGetDataNumTest, TestGetDataNumWhenEmptyAndErase)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	ASSERT_FALSE(list.Erase(itr));
	EXPECT_EQ(0, list.GetCount()) << "空リストに対して要素削除を行った後のデータ数取得失敗";
}
//=============================================================================
// データの挿入テスト
//=============================================================================
/**
 * @breif	リストが空である場合に、データを追加した際の挙動テスト
 * @deteils	ID:リスト-9
 */
TEST_F(ListPushTest, TestPushToEmpty)
{
	// 空リストに先頭要素挿入
	{
		List<int> list;
		Iterator<int> itr = list.GetBegin();
		EXPECT_TRUE(list.Insert(itr, 10)) << "空リストの先頭へ要素挿入失敗";
		// 要素のチェック
		itr = list.GetBegin();
		EXPECT_EQ(*itr, 10);
	}
	// 空リストに末尾要素挿入
	{
		List<int> list;
		Iterator<int> itr = list.GetEnd();
		EXPECT_TRUE(list.Insert(itr, 10)) << "空リストの末尾へ要素挿入失敗";
		// 要素のチェック
		itr = list.GetBegin();
		EXPECT_EQ(*itr, 10);
	}
}
/**
 * @breif	リストに複数の要素がある場合に、先頭イテレータを渡して挿入した際の挙動テスト
 * @deteils	ID:リスト-10
 */
TEST_F(ListPushTest, TestPushToHead)
{
	Iterator<int> itr = m_Lists[0].GetBegin();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "リストに複数要素が存在する時に先頭へ要素挿入失敗";
	// 要素位置のチェック
	int checkDatas[] = { 10,0,1 };
	itr = m_Lists[0].GetBegin();
	for (int i = 0; i < 3; ++i, ++itr)
		EXPECT_EQ(*itr, checkDatas[i]) << "リストに複数要素が存在する時に先頭へ要素挿入後、リストの要素順に問題あり";
}
/**
 * @breif	リストに複数の要素がある場合に、末尾イテレータを渡して挿入した際の挙動テスト
 * @deteils	ID:リスト-11
 */
TEST_F(ListPushTest, TestPushToTail)
{
	Iterator<int> itr = m_Lists[0].GetEnd();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "リストに複数要素が存在する時に末尾へ要素挿入失敗";
	// 要素位置のチェック
	int checkDatas[] = { 0,1,10 };
	itr = m_Lists[0].GetBegin();
	for (int i = 0; i < 3; ++i, ++itr)
		EXPECT_EQ(*itr, checkDatas[i]) << "リストに複数要素が存在する時に末尾へ要素挿入後、リストの要素順に問題あり";
}
/**
 * @breif	リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動テスト
 * @deteils	ID:リスト-12
 */
TEST_F(ListPushTest, TestPushToBetween)
{
	// 先頭、中央、末尾位置へそれぞれ要素を挿入
	Iterator<int> itr = m_Lists[0].GetBegin();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "リストに複数要素が存在する時に、先頭への挿入失敗";
	itr = m_Lists[1].GetBegin();
	++itr;
	EXPECT_TRUE(m_Lists[1].Insert(itr, 10)) << "リストに複数要素が存在する時に、中間への挿入失敗";
	itr = m_Lists[2].GetEnd();
	EXPECT_TRUE(m_Lists[2].Insert(itr, 10)) << "リストに複数要素が存在する時に、末尾への挿入失敗";
	// 要素位置の確認用
	int checkDatas[][3] =
	{
		{ 10,  0,  1, }, // 先頭へ挿入したリスト要素順
		{  0, 10,  1, }, // 中央へ挿入したリスト要素順
		{  0,  1, 10, }, // 末尾へ挿入したリスト要素順
	};
	// 先頭、中央、末尾それぞれの要素順序が正しいか確認
	for (int i = 0; i < 3; ++i)
	{
		itr = m_Lists[i].GetBegin();
		for (int j = 0; j < 3; ++j, ++itr)
			EXPECT_EQ(*itr, checkDatas[i][j]) << "リストに複数要素が存在する時に要素挿入後、格納済要素に不具合発生";
	}
}
/**
 * @breif	ConstIteratorを指定して挿入を行った際の挙動テスト
 * @deteils	ID:リスト-13
 */
TEST_F(ListPushTest, TestPushToConstIterator)
{
	// 先頭、中央、末尾位置へそれぞれ要素を挿入
	ConstIterator<int> itr = m_Lists[0].GetConstBegin();
	EXPECT_TRUE(m_Lists[0].Insert(itr, 10)) << "リストに複数要素が存在する時に、先頭への挿入失敗(コンストイテレータver)";;
	itr = m_Lists[1].GetConstBegin();
	++itr;
	EXPECT_TRUE(m_Lists[1].Insert(itr, 10)) << "リストに複数要素が存在する時に、中間への挿入失敗(コンストイテレータver)";
	itr = m_Lists[2].GetConstEnd();
	EXPECT_TRUE(m_Lists[2].Insert(itr, 10)) << "リストに複数要素が存在する時に、末尾への挿入失敗(コンストイテレータver)";
	// 要素位置の確認用
	int checkDatas[][3] =
	{
		{ 10,  0,  1, }, // 先頭へ挿入したリスト要素順
		{  0, 10,  1, }, // 中央へ挿入したリスト要素順
		{  0,  1, 10, }, // 末尾へ挿入したリスト要素順
	};
	// 先頭、中央、末尾それぞれの要素順序が正しいか確認
	for (int i = 0; i < 3; ++i)
	{
		itr = m_Lists[i].GetConstBegin();
		for (int j = 0; j < 3; ++j, ++itr)
			EXPECT_EQ(*itr, checkDatas[i][j]) << "リストに複数要素が存在する時に要素挿入後、格納済要素に不具合発生(コンストイテレータver)";
	}
}
/**
 * @breif	不正なイテレータを渡して挿入した際の挙動テスト
 * @deteils	ID:リスト-14
 */
TEST_F(ListPushTest, TestPushToErrorIterator)
{
	// リストへの参照がないのイテレータで挿入を試した場合
	{
		List<int> list;
		Iterator<int> itr;
		EXPECT_FALSE(list.Insert(itr, 10)) << "不正イテレータ(未参照イテレータ)での挿入成功";
	}
	// 別のリストのイテレータで挿入を試した場合
	{
		List<int> list;
		List<int> listOther;
		Iterator<int> itr = listOther.GetBegin();
		EXPECT_FALSE(list.Insert(itr, 10)) << "不正イテレータ(別リスト参照イテレータ)での挿入成功";
	}
}
//=============================================================================
// データの削除テスト
//=============================================================================
/**
 * @breif	リストが空である場合に、削除を行った際の挙動テスト
 * @deteils	ID:リスト-16
 */
TEST_F(ListEraseTest, TestEraseToEmpty)
{
	// 空リストの先頭削除
	{
		List<int> list;
		Iterator<int> itr = list.GetBegin();
		EXPECT_FALSE(list.Erase(itr)) << "空リストへの先頭イテレータでの削除成功";
	}
	// 空リストの末尾削除
	{
		List<int> list;
		Iterator<int> itr = list.GetEnd();
		EXPECT_FALSE(list.Erase(itr)) << "空リストへの末尾イテレータでの削除成功";
	}
}
/**
 * @breif	リストに複数の要素がある場合に、先頭イテレータを渡して削除した際の挙動テスト
 * @deteils	ID:リスト-17
 */
TEST_F(ListEraseTest, TestEraseToHead)
{
	// 先頭削除
	Iterator<int> itr = m_Lists[0].GetBegin();
	EXPECT_TRUE(m_Lists[0].Erase(itr)) << "リストの要素存在時に、先頭イテレータでの削除失敗";
	// リスト内要素位置チェック
	itr = m_Lists[0].GetBegin();
	EXPECT_EQ(*itr, 1) << "リストに複数要素が存在し、先頭イテレータで削除した際、リスト内の要素にエラー";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "リストに複数要素が存在し、先頭イテレータで削除した際、リスト内の要素にエラー";
}
/**
 * @breif	リストに複数の要素がある場合に、末尾イテレータを渡して削除した際の挙動テスト
 * @deteils	ID:リスト-18
 */
TEST_F(ListEraseTest, TestEraseToTail)
{
	// 末尾削除(何も起こらないはず
	Iterator<int> itr = m_Lists[0].GetEnd();
	EXPECT_FALSE(m_Lists[0].Erase(itr)) << "リストの要素存在時に、末尾イテレータでの削除成功";
	// リスト内要素位置チェック
	itr = m_Lists[0].GetBegin();
	EXPECT_EQ(*itr, 0) << "リストに複数要素が存在し、末尾イテレータで削除した際、リスト内の要素にエラー";
	++itr;
	EXPECT_EQ(*itr, 1) << "リストに複数要素が存在し、末尾イテレータで削除した際、リスト内の要素にエラー";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "リストに複数要素が存在し、末尾イテレータで削除した際、リスト内の要素にエラー";
}
/**
 * @breif	リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動テスト
 * @deteils	ID:リスト-19
 */
TEST_F(ListEraseTest, TestEraseToBetween)
{
	// 中間要素を削除
	Iterator<int> itr = m_Lists[0].GetBegin();
	++itr;
	EXPECT_TRUE(m_Lists[0].Erase(itr)) << "リスト要素存在時、中間イテレータでの削除失敗";
	// 要素位置の確認(先頭にのみデータがあるはず
	itr = m_Lists[0].GetBegin();
	EXPECT_EQ(*itr, 0) << "中間イテレータでの要素削除後、格納済要素に不具合発生";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "中間イテレータでの要素削除後、末尾イテレータ取得に失敗";
}
/**
 * @breif	ConstIteratorを指定して削除を行った際の挙動テスト
 * @deteils	ID:リスト-20
 */
TEST_F(ListEraseTest, TestEraseToConstIterator)
{
	// 中間要素を削除
	ConstIterator<int> itr = m_Lists[0].GetConstBegin();
	++itr;
	EXPECT_TRUE(m_Lists[0].Erase(itr)) << "リスト要素存在時、中間コンストイテレータでの削除失敗";
	// 要素位置の確認(先頭にのみデータがあるはず
	itr = m_Lists[0].GetConstBegin();
	EXPECT_EQ(*itr, 0) << "中間コンストイテレータでの要素削除後、格納済要素に不具合発生";
	++itr;
	EXPECT_EQ(itr, m_Lists[0].GetEnd()) << "中間コンストイテレータでの要素削除後、末尾コンストイテレータ取得に失敗";
}
/**
 * @breif	不正なイテレータを渡して挿入した際の挙動テスト
 * @deteils	ID:リスト-21
 */
TEST_F(ListEraseTest, TestEraseToErrorIterator)
{
	// リストへの参照がないのイテレータで削除を試した場合
	{
		List<int> list;
		Iterator<int> itr = list.GetBegin();
		EXPECT_FALSE(list.Erase(itr)) << "不正イテレータ(未参照)での要素削除成功";
	}
	// 別のリストのイテレータで削除を試した場合
	{
		List<int> list;
		List<int> listOther;
		Iterator<int> itr = listOther.GetBegin();
		EXPECT_FALSE(listOther.Erase(itr)) << "不正イテレータ(別リスト参照)での要素削除成功";
	}
}
//=============================================================================
// 先頭イテレータの取得テスト
//=============================================================================
/**
 * @breif	リストが空である際の先頭イテレータの取得テスト
 * @deteils	ID:リスト-23
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetBegin(), list.GetEnd()) << "空リスト時、先頭イテレータの取得失敗";
}
/**
 * @breif	リストに要素が一つある場合の先頭イテレータの取得テスト
 * @deteils	ID:リスト-24
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorWhenOnly)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	// 要素が一つのリストを準備
	ASSERT_TRUE(list.Insert(itr, 10));
	// 先頭イテレータが指す要素を確認
	EXPECT_EQ(*list.GetBegin(), 10) << "リストに要素が一つ存在時、先頭イテレータの取得失敗";
}
/**
 * @breif	リストに二つ以上要素がある場合の先頭イテレータの取得テスト
 * @deteils	ID:リスト-25
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIterator)
{
	// 先頭イテレータが指す要素を確認
	EXPECT_EQ(*m_Lists[0].GetBegin(), 0) << "リストに複数要素が存在時、先頭イテレータの取得失敗";
}
/**
 * @breif	データを挿入した際の先頭イテレータの取得テスト
 * @deteils	ID:リスト-26
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorAfterPush)
{
	// 先頭、中間、末尾へそれぞれ挿入
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// 先頭、中央、末尾へ要素挿入した後のリストの先頭要素が持つ値
	int checkDatas[] = { 10,0,0 };
	for (int i = 0; i < 3; ++i)
	{// 要素挿入後の先頭イテレータ取得テスト
		EXPECT_EQ(*m_Lists[i].GetBegin(), checkDatas[i]) << "複数要素を持つリストへの要素挿入後、先頭イテレータの取得失敗";
	}
}
/**
 * @breif	データを削除した際の先頭イテレータの取得テスト
 * @deteils	ID:リスト-27
 */
TEST_F(ListGetHeadIteratorTest, TestGetHeadIteratorAfterErase)
{
	// 先頭、中間、末尾をそれぞれ削除
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// 先頭、中央、末尾の要素削除した後のリストの先頭要素が持つ値
	int checkDatas[] = { 1,0,0 };
	for (int i = 0; i < 3; ++i)
	{// 要素削除後の先頭イテレータ取得テスト
		EXPECT_EQ(*m_Lists[i].GetBegin(), checkDatas[i]) << "複数要素を持つリストへの要素削除後、先頭イテレータの取得失敗";
	}
}
//=============================================================================
// 先頭コンストイテレータの取得テスト
//=============================================================================
/**
 * @breif	リストが空である際の先頭コンストイテレータの取得テスト
 * @deteils	ID:リスト-29
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetConstBegin(), list.GetConstEnd()) << "空リスト時、先頭コンストイテレータの取得失敗";
}
/**
 * @breif	リストに要素が一つある場合の先頭コンストイテレータの取得テスト
 * @deteils	ID:リスト-30
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorWhenOnly)
{
	List<int> list;
	ConstIterator<int> itr = list.GetConstBegin();
	// 要素が一つのリストを準備
	ASSERT_TRUE(list.Insert(itr, 10));
	// 先頭コンストイテレータが指す要素を確認
	EXPECT_EQ(*list.GetConstBegin(), 10) << "リストに要素が一つ存在時、先頭イテレータの取得失敗";
}
/**
 * @breif	リストに二つ以上要素がある場合の先頭コンストイテレータの取得テスト
 * @deteils	ID:リスト-31
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIterator)
{
	// 先頭コンストイテレータが指す要素を確認
	EXPECT_EQ(*m_Lists[0].GetConstBegin(), 0) << "リストに複数要素が存在時、先頭コンストイテレータの取得失敗";
}
/**
 * @breif	データを挿入した際の先頭コンストイテレータの取得テスト
 * @deteils	ID:リスト-32
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorAfterPush)
{
	// 先頭、中間、末尾へそれぞれ挿入
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// 先頭、中央、末尾へ要素挿入した後のリストの先頭要素が持つ値
	int checkDatas[] = { 10,0,0 };
	for (int i = 0; i < 3; ++i)
	{// 要素挿入後の先頭コンストイテレータ取得テスト
		EXPECT_EQ(*m_Lists[i].GetConstBegin(), checkDatas[i]) << "複数要素を持つリストへの要素挿入後、先頭コンストイテレータの取得失敗";
	}
}
/**
 * @breif	データを削除した際の先頭コンストイテレータの取得テスト
 * @deteils	ID:リスト-33
 */
TEST_F(ListGetHeadConstIteratorTest, TestGetHeadConstIteratorAfterErase)
{
	// 先頭、中間、末尾をそれぞれ削除
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// 先頭、中央、末尾の要素削除した後のリストの先頭要素が持つ値
	int checkDatas[] = { 1,0,0 };
	for (int i = 0; i < 3; ++i)
	{// 要素削除後の先頭コンストイテレータ取得テスト
		EXPECT_EQ(*m_Lists[i].GetConstBegin(), checkDatas[i]) << "複数要素を持つリストへの要素削除後、先頭コンストイテレータの取得失敗";
	}
}
//=============================================================================
// 末尾イテレータの取得テスト
//=============================================================================
/**
 * @breif	リストが空である際の末尾イテレータの取得テスト
 * @deteils	ID:リスト-35
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetEnd(), list.GetBegin()) << "空リスト時、末尾イテレータの取得失敗";
}
/**
 * @breif	リストに要素が一つある場合の末尾イテレータの取得テスト
 * @deteils	ID:リスト-36
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorWhenOnly)
{
	List<int> list;
	Iterator<int> itr = list.GetBegin();
	// 要素が一つのリストを準備
	ASSERT_TRUE(list.Insert(itr, 10));
	// 末尾イテレータを確認
	EXPECT_EQ(*--list.GetEnd(), 10) << "リストに要素が一つ存在時、末尾イテレータの取得失敗";
}
/**
 * @breif	リストに二つ以上要素がある場合の末尾イテレータの取得テスト
 * @deteils	ID:リスト-37
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIterator)
{
	// 末尾イテレータが指す要素を確認
	EXPECT_EQ(*--m_Lists[0].GetEnd(), 1) << "リストに複数要素が存在時、末尾イテレータの取得失敗";
}
/**
 * @breif	データを挿入した際の末尾イテレータの取得テスト
 * @deteils	ID:リスト-38
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorAfterPush)
{
	// 先頭、中間、末尾へそれぞれ挿入
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// 先頭、中央、末尾へ要素挿入した後のリストの末尾要素が持つ値
	int checkDatas[] = { 1,1,10 };
	for (int i = 0; i < 3; ++i)
	{// 要素挿入後の末尾イテレータ取得テスト
		EXPECT_EQ(*--m_Lists[i].GetEnd(), checkDatas[i]) << "複数要素を持つリストへの要素挿入後、末尾イテレータの取得失敗";
	}
}
/**
 * @breif	データを削除した際の末尾イテレータの取得テスト
 * @deteils	ID:リスト-39
 */
TEST_F(ListGetTailIteratorTest, TestGetTailIteratorAfterErase)
{
	// 先頭、中間、末尾をそれぞれ削除
	{
		Iterator<int> itr = m_Lists[0].GetBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// 先頭、中央、末尾の要素削除した後のリストの先頭要素が持つ値
	int checkDatas[] = { 1,0,1 };
	for (int i = 0; i < 3; ++i)
	{// 要素削除後の末尾イテレータ取得テスト
		EXPECT_EQ(*--m_Lists[i].GetEnd(), checkDatas[i]) << "複数要素を持つリストへの要素削除後、末尾イテレータの取得失敗";
	}
}
//=============================================================================
// 末尾コンストイテレータの取得テスト
//=============================================================================
/**
 * @breif	リストが空である際の末尾コンストイテレータの取得テスト
 * @deteils	ID:リスト-41
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorWhenEmpty)
{
	List<int> list;
	EXPECT_EQ(list.GetConstEnd(), list.GetConstBegin()) << "空リスト時、末尾コンストイテレータの取得失敗";
}
/**
 * @breif	リストに要素が一つある場合の末尾コンストイテレータの取得テスト
 * @deteils	ID:リスト-42
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorWhenOnly)
{
	List<int> list;
	ConstIterator<int> itr = list.GetConstBegin();
	// 要素が一つのリストを準備
	ASSERT_TRUE(list.Insert(itr, 10));
	// 末尾コンストイテレータが指す要素を確認
	EXPECT_EQ(*--list.GetConstEnd(), 10) << "リストに要素が一つ存在時、末尾イテレータの取得失敗";
}
/**
 * @breif	リストに二つ以上要素がある場合の末尾コンストイテレータの取得テスト
 * @deteils	ID:リスト-43
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIterator)
{
	// 末尾コンストイテレータが指す要素を確認
	EXPECT_EQ(*--m_Lists[0].GetConstEnd(), 1) << "リストに複数要素が存在時、末尾コンストイテレータの取得失敗";
}
/**
 * @breif	データを挿入した際の末尾コンストイテレータの取得テスト
 * @deteils	ID:リスト-44
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorAfterPush)
{
	// 先頭、中間、末尾へそれぞれ挿入
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Insert(itr, 10));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Insert(itr, 10));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_TRUE(m_Lists[2].Insert(itr, 10));
	}
	// 先頭、中央、末尾へ要素挿入した後のリストの先頭要素が持つ値
	int checkDatas[] = { 1,1,10 };
	for (int i = 0; i < 3; ++i)
	{// 要素挿入後の末尾コンストイテレータ取得テスト
		EXPECT_EQ(*--m_Lists[i].GetConstEnd(), checkDatas[i]) << "複数要素を持つリストへの要素挿入後、末尾コンストイテレータの取得失敗";
	}
}
/**
 * @breif	データを削除した際の末尾コンストイテレータの取得テスト
 * @deteils	ID:リスト-45
 */
TEST_F(ListGetTailConstIteratorTest, TestGetTailConstIteratorAfterErase)
{
	// 先頭、中間、末尾をそれぞれ削除
	{
		ConstIterator<int> itr = m_Lists[0].GetConstBegin();
		ASSERT_TRUE(m_Lists[0].Erase(itr));
		itr = m_Lists[1].GetConstBegin();
		++itr;
		ASSERT_TRUE(m_Lists[1].Erase(itr));
		itr = m_Lists[2].GetConstEnd();
		ASSERT_FALSE(m_Lists[2].Erase(itr));
	}
	// 先頭、中央、末尾の要素削除した後のリストの先頭要素が持つ値
	int checkDatas[] = { 1,0,1 };
	for (int i = 0; i < 3; ++i)
	{// 要素削除後の末尾コンストイテレータ取得テスト
		EXPECT_EQ(*--m_Lists[i].GetConstEnd(), checkDatas[i]) << "複数要素を持つリストへの要素削除後、末尾コンストイテレータの取得失敗";
	}
}
