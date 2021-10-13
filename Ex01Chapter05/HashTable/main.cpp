/**
 * @file main.cpp
 * @breif メイン
 * @author MikamiYuto
 * @date 2021.10.13
 * @details 課題1_5ハッシュテーブルの再実装
 */


//----- インクルード
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>


int main()
{
	//HashTable hashTable;
	//std::string key;
	//std::string value;
	//int cmdNum = 0;
	//bool isLoop = true;

	//// 初期値
	//hashTable.Push(HashWord("国語", "まぁまぁ"));
	//hashTable.Push(HashWord("数学", "やや苦手、三角関数辺りから苦手意識が"));
	//hashTable.Push(HashWord("理科", "得意だった"));
	//hashTable.Push(HashWord("社会", "ぼちぼち"));
	//hashTable.Push(HashWord("英語", "単語だけなら…"));

	//// ハッシュテーブル操作
	//while (isLoop)
	//{
	//	std::cout << std::endl;
	//	std::cout << "ハッシュの操作方法を入力してください" << std::endl;
	//	std::cout << "1 : 登録, 2 : 削除, 3 : 検索, 0 : 終了" << std::endl;
	//	std::cout << "操作入力[数値]→";
	//	std::cin >> cmdNum;

	//	// 画面クリア
	//	std::system("cls");

	//	//　キー全表示
	//	hashTable.DrawKeyList();
	//	switch (cmdNum)
	//	{
	//	case 0:	// 終了
	//		isLoop = false;
	//		break;
	//	case 1:	// 登録
	//		std::cout << "登録する単語を入力してください" << std::endl;
	//		std::cout << "キー入力[文字列]→";
	//		std::cin >> key;
	//		std::cout << std::endl;
	//		std::cout << "登録する説明文を入力してください" << std::endl;
	//		std::cout << "値入力[文字列]→";
	//		std::cin >> value;
	//		hashTable.Push(HashWord(key, value));
	//		std::cout << "登録完了" << std::endl;
	//		break;
	//	case 2: // 削除
	//		std::cout << "削除する単語を入力してください" << std::endl;
	//		std::cout << "キー入力[文字列]→";
	//		std::cin >> key;
	//		hashTable.Erase(key);
	//		std::cout << "削除完了" << std::endl;
	//		break;
	//	case 3: // 検索
	//		std::cout << "検索する単語を入力してください" << std::endl;
	//		std::cout << "キー入力[文字列]→";
	//		std::cin >> key;
	//		value = hashTable.Find(key);
	//		std::cout << std::endl;
	//		std::cout << "↓説明文↓" << std::endl;
	//		std::cout << value << std::endl;
	//		std::cout << "検索完了" << std::endl;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	//// 終了
	//hashTable.Clear();

	return 0;
}