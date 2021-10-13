/**
 * @file main.cpp
 * @breif メイン
 * @author MikamiYuto
 * @date 2021.10.13
 * @details テンプレートスタック
 */


//----- インクルード
#include "Stack.h"
#include "ScoreData.h"
#include <iostream>
#include <iomanip>
#include <fstream>


int main()
{
	Stack<ScoreData> stack;
	std::ifstream ifs("Scores.txt");
	if (!ifs) return -1;
	ScoreData data = {};
	
	// データ読み込み
	while (!ifs.eof())
	{
		// 読み込み（プッシュ)
		{
			int num = 0;
			std::cout << "データ読み込み数(Push)を入力→";
			std::cin >> num;
			std::cout << std::endl;
			std::cout << "Push開始" << std::endl;
			for (int i = 0; i < num; ++i)
			{
				if (!(ifs >> data.score)) continue;
				if (!(ifs >> data.userName)) continue;
				if (!stack.Push(data))
				{
					std::cout << "スタックへのデータ格納失敗" << std::endl;
					return -1;
				}
				std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
			}
			std::cout << "Push終了" << std::endl << std::endl;
		}
		// 取り出し（ポップ）
		{
			int	num = 0;
			std::cout << "データ出力数(Pop)を入力→";
			std::cin >> num;
			std::cout << std::endl;
			std::cout << "Pop開始" << std::endl;
			for (int i = 0; i < num; ++i)
			{
				if (!stack.Pop(&data))
				{
					std::cout << "スタック内のデータが空になりました" << std::endl;
					break;
				}
				std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
			}
			std::cout << "Pop終了" << std::endl << std::endl;
		}
	}

	if (!ifs.eof())
	{
		std::cout << "ファイルデータが全て読み込まれました" << std::endl;
		std::cout << "アプリを終了します" << std::endl;
	}


	return 0;
}