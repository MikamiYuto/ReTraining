/**
 * @file main.cpp
 * @breif メイン
 * @author MikamiYuto
 * @date 2021.10.08
 * @details 「双方向リストのテンプレート」
 */


//----- インクルード
#include "ScoreData.h"
#include "List.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int main()
{
	List<ScoreData> list;
	List<ScoreData>::Iterator itr = list.begin();
	std::ifstream ifs("scores.txt");
	if (!ifs) return -1;
	ScoreData data = {};

	std::cout << "テキストファイル読み込み開始" << std::endl;
	while (!ifs.eof())
	{
		// 外部ファイルよりデータ取得
		if (!(ifs >> data.score)) continue;
		if (!(ifs >> data.userName)) continue;
		// 取得したデータをリスト末尾へ格納
		itr = list.end();
		if (!list.Insert(itr, data))
		{
			std::cout << "データ格納失敗" << std::endl;
			return -1;
		};
	}
	std::cout << "テキストファイル読み込み成功" << std::endl;
	
	std::cout << std::endl;

	std::cout << "クイックソート開始" << std::endl;
	ScoreData key{ 20000, "cmp" };
	list.QuickSort(true, &key);
	std::cout << "クイックソート開始" << std::endl << std::endl;


	
	// 読み込んだデータを全表示
	std::cout << "読み込んだデータの表示開始" << std::endl;
	for (const auto& data : list)
		std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
	std::cout << "読み込んだデータの表示終了" << std::endl;

	return 0;
}