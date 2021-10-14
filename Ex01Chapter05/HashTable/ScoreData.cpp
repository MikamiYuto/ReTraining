/**
 * @file ScoreData.cpp
 * @brief 成績データ構造体の実装ファイル
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


 //----- インクルード
#include "ScoreData.h"


//-----------------------------------------------------------------------------
bool ScoreData::operator==(const ScoreData& data) const
{
	return score == data.score && userName == data.userName;
}
