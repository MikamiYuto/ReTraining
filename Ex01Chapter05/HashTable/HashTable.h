/**
 * @file HashTable.h
 * @brief テンプレートハッシュテーブルクラスの定義ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- インクルード
#include "List.h"
#include <string>


//----- 定数定義
constexpr int DEFAULT_HASH_PACKET_SIZE(5);


//----- プロトタイプ宣言
static int CalcHash(const int& key);
static int CalcHash(const std::string& key);


/** 
 * @brief	ハッシュテーブルクラス 
 * @param Key			キー値
 * @param Value			値
 * @param CalcHashFunc	ハッシュ値導出関数
 * @param SIZE			パケットサイズ(ハッシュ関数から導出される値を含めれる値を指定
 */
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
class HashTable
{
private:
	/** ペア構造体 */
	struct Pair
	{
		Key		key;	//!< ハッシュのキー
		Value	value;	//!< 値
	};

private:
	List<Pair>	m_Table[SIZE];			//!< ペア格納テーブル
	int			m_ElementCnt;			//!< 要素数

public:
	/**
	 * @brief	コンストラクタ
	 */
	HashTable();
	/**
	 * @brief	デストラクタ
	 */
	~HashTable();

public:
	/**
	 * @brief	要素数の取得
	 * @return	要素数
	 */
	int GetCount() const;
	/**
	 * @brief			要素の挿入
	 * @param[in] key	挿入する要素のキー値
	 * @param[in] value	挿入する要素の値
	 * @return			挿入の成否、失敗の場合は何もしない
	 *					失敗ケース
	 *					・キーの重複
	 *					・要素のメモリ確保失敗
	 */
	bool Insert(const Key& key, const Value& value);
	/**
	 * @brief			要素の削除
	 * @param[in] key	削除する要素のキー値
	 * @return			削除の成否、失敗の場合は何もしない
	 *					失敗ケース
	 *					・キーが存在しない（削除済、未挿入、空
	 */
	bool Erase(const Key& key);
	/**
	 * @brief			要素の検索
	 * @param[in] key	検索する要素のキー値
	 * @param[out] out	見つかった値の受取先
	 * @return			検索の成否、失敗の場合は何もしない
	 *					失敗ケース
	 *					・キーが存在しない（削除済、未挿入、空
	 */
	bool Find(const Key& key, Value* out = nullptr) const;

private:
	/**
	 * @brief			キーからハッシュ値が指すリストへの参照を取得する
	 *					CalcHashFuncとSIZEのいずれかに問題がある場合Assert発生
	 * @param[in] key	キー値
	 * @return			ハッシュ値
	 */
	int GetHash(const Key& key) const;
};
#include "HashTable.inl"