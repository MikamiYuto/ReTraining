/**
 * @file main.cpp
 * @brief メイン
 * @author MikamiYuto
 * @date 2021.10.13
 * @details 課題1_5ハッシュテーブルの再実装
 */


//----- インクルード
#include "HashTable.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"


int main()
{
	HashTable<std::string, std::string, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
	List<std::string> keyList;
	List<std::string>::Iterator itr;
	std::string key;
	std::string value;
	int cmdNum = 0;
	bool isLoop = true;

	// 初期値
	hashTable.Insert("無職転生", "王道異世界転生、転スラがアニメ化されるまではなろうランキング不動の一位だった");
	hashTable.Insert("転生したらスライムだった件", "王道異世界\"人外\"転生、めっさコミカライズとかグッズ化されてる");
	hashTable.Insert("死神を食べた少女", "知る人ぞ知るダーク戦記、☆おすすめ☆");
	hashTable.Insert("盾の勇者の成り上がり", "異世界転移、Web版と書籍版で内容が結構違う");
	itr = keyList.end();
	keyList.Insert(itr, "無職転生");
	itr = keyList.end();
	keyList.Insert(itr, "転生したらスライムだった件");
	itr = keyList.end();
	keyList.Insert(itr, "死神を食べた少女");
	itr = keyList.end();
	keyList.Insert(itr, "盾の勇者の成り上がり");
	
	// ハッシュテーブル操作
	while (isLoop)
	{
		std::cout << std::endl;
		std::cout << "ハッシュの操作方法を入力してください" << std::endl;
		std::cout << "1 : 登録, 2 : 削除, 3 : 検索, 0 : 終了" << std::endl;
		std::cout << "操作入力[数値]→";
		std::cin >> cmdNum;
	
		// 画面クリア
		std::system("cls");
	
		//　キー全表示
		std::cout << "---↓現在登録されているキー↓---" << std::endl << std::endl;
		for (const auto& str : keyList)
			std::cout << str << std::endl;
		std::cout << std::endl;
		std::cout << "---↑現在登録されているキー↑---" << std::endl << std::endl;
		switch (cmdNum)
		{
		case 0:	// 終了
			isLoop = false;
			break;
		case 1:	// 登録
			std::cout << "登録する単語を入力してください" << std::endl;
			std::cout << "キー入力[文字列]→";
			std::cin >> key;
			std::cout << std::endl;
			std::cout << "登録する説明文を入力してください" << std::endl;
			std::cout << "値入力[文字列]→";
			std::cin >> value;
			if (hashTable.Insert(key, value))
			{
				std::cout << "登録成功" << std::endl;
				itr = keyList.end();
				keyList.Insert(itr, key);
			}
			else
			{
				std::cout << "削除失敗(単語重複)" << std::endl;
			}
			break;
		case 2: // 削除
			std::cout << "削除する単語を入力してください" << std::endl;
			std::cout << "キー入力[文字列]→";
			std::cin >> key;
			if (hashTable.Erase(key))
			{
				itr = keyList.begin();
				for (auto e = keyList.end(); itr != e; ++itr)
					if (*itr == key) break;
				keyList.Erase(itr);
				std::cout << "削除成功" << std::endl;
			}
			else
				std::cout << "削除失敗(単語未登録)" << std::endl;
			break;
		case 3: // 検索
			std::cout << "検索する単語を入力してください" << std::endl;
			std::cout << "キー入力[文字列]→";
			std::cin >> key;
			if (hashTable.Find(key, &value))
			{
				std::cout << std::endl;
				std::cout << "↓説明文↓" << std::endl;
				std::cout << value << std::endl;
				std::cout << "検索成功" << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "単語が登録されていません" << std::endl;
				std::cout << "検索失敗" << std::endl;
			}
			break;
		default:
			break;
		}
		key = "";
		value = "";
	}

	return 0;
}