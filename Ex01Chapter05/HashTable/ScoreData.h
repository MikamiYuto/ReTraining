/**
 * @file ScoreData.h
 * @brief 成績データ構造体の定義ファイル
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


//----- インクルード
#include <string>


/** 成績データ構造体 */
struct ScoreData
{
public:
	int			score;		//!< スコア
	std::string userName;	//!< ユーザ名

public:
	/**
	 * @brief	等価比較演算子オーバーロード
	 * @return	スコアとユーザ名の両方を比較し、等価であればtrueを返します
	 */
	bool operator==(const ScoreData& data) const;
};
