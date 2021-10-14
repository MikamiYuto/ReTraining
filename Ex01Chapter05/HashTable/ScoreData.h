/**
 * @file ScoreData.h
 * @brief ���уf�[�^�\���̂̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


//----- �C���N���[�h
#include <string>


/** ���уf�[�^�\���� */
struct ScoreData
{
public:
	int			score;		//!< �X�R�A
	std::string userName;	//!< ���[�U��

public:
	/**
	 * @brief	������r���Z�q�I�[�o�[���[�h
	 * @return	�X�R�A�ƃ��[�U���̗������r���A�����ł����true��Ԃ��܂�
	 */
	bool operator==(const ScoreData& data) const;
};
