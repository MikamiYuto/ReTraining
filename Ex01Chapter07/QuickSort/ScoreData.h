/**
 * @file ScoreData.h
 * @breif ���уf�[�^�\���̂̒�`�t�@�C��
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
	 * @breif	������r���Z�q�I�[�o�[���[�h
	 * @return	�����o�ϐ��̃X�R�A�ƃ��[�U���̗������r���A�����ł����true��Ԃ��܂�
	 */
	bool operator==(const ScoreData& data) const;
	/**
	 * @breif	���Ȃ艉�Z�q�I�[�o�[���[�h
	 * @return	���ӂƉE�ӂŃX�R�A���r���A���ӂ����������true��Ԃ��܂�
	 */
	bool operator<(const ScoreData& data) const;
	/**
	 * @breif	��Ȃ艉�Z�q�I�[�o�[���[�h
	 * @return	���ӂƉE�ӂŃX�R�A���r���A���ӂ��傫�����true��Ԃ��܂�
	 */
	bool operator>(const ScoreData& data) const;
	/**
	 * @breif	���Ȃ�C�R�[�����Z�q�I�[�o�[���[�h
	 * @return	���ӂƉE�ӂŃX�R�A���r���A���ӂ��������A�܂��͓����ł����true��Ԃ��܂�
	 */
	bool operator<=(const ScoreData& data) const;

};
