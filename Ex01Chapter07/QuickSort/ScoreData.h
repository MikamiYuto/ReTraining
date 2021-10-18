/**
 * @file ScoreData.h
 * @breif 成績データ構造体の定義ファイル
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
	 * @breif	等価比較演算子オーバーロード
	 * @return	メンバ変数のスコアとユーザ名の両方を比較し、等価であればtrueを返します
	 */
	bool operator==(const ScoreData& data) const;
	/**
	 * @breif	小なり演算子オーバーロード
	 * @return	左辺と右辺でスコアを比較し、左辺が小さければtrueを返します
	 */
	bool operator<(const ScoreData& data) const;
	/**
	 * @breif	大なり演算子オーバーロード
	 * @return	左辺と右辺でスコアを比較し、左辺が大きければtrueを返します
	 */
	bool operator>(const ScoreData& data) const;
	/**
	 * @breif	小なりイコール演算子オーバーロード
	 * @return	左辺と右辺でスコアを比較し、左辺が小さい、または等価であればtrueを返します
	 */
	bool operator<=(const ScoreData& data) const;

};
