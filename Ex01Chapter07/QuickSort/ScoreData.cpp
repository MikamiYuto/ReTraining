/**
 * @file ScoreData.cpp
 * @breif ���уf�[�^�\���̂̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


 //----- �C���N���[�h
#include "ScoreData.h"


//-----------------------------------------------------------------------------
bool ScoreData::operator==(const ScoreData& data) const
{
	return score == data.score && userName == data.userName;
}
//-----------------------------------------------------------------------------
bool ScoreData::operator<(const ScoreData& data) const
{
	return score < data.score;
}
//-----------------------------------------------------------------------------
bool ScoreData::operator>(const ScoreData& data) const
{
	return score > data.score;
}
//-----------------------------------------------------------------------------
bool ScoreData::operator<=(const ScoreData& data) const
{
	return score <= data.score;
}