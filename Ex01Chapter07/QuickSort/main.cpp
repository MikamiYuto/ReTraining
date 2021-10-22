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
	// データ表示関数
	auto showDataFunc = [&list]
	{
		std::cout << "全データの表示開始" << std::endl;
		for (const auto& data : list)
			std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
		std::cout << "全データの表示終了" << std::endl;
	};
	// ソート表示関数
	auto showSortFunc = [&list](bool(*cmpFunc)(const ScoreData&, const ScoreData&), std::string keyName)
	{
		std::cout << keyName << "をキーとしたクイックソート開始" << std::endl;
		list.QuickSort(cmpFunc);
		std::cout << keyName << "をキーとしたクイックソート終了" << std::endl << std::endl;
	};

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

	// スコアをキーとしてソートを実行
	{
		auto cmpFunc = [](const ScoreData& a, const ScoreData& b)
		{
			if (a.score == b.score)
				return a.userName < b.userName;
			else
				return a.score < b.score;
		};
		showSortFunc(cmpFunc, "スコア");
	}
	// データを全表示
	showDataFunc();

	std::cout << std::endl;

	// ユーザ名をキーとしてソートを実行
	{
		auto cmpFunc = [](const ScoreData& a, const ScoreData& b)
		{
			if (a.userName == b.userName)
				return a.score < b.score;
			else
				return a.userName < b.userName;
		};
		showSortFunc(cmpFunc, "ユーザ名");
	}
	// データを全表示
	showDataFunc();

	return 0;
}