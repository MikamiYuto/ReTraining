/**
 * @file main.cpp
 * @breif ���C��
 * @author MikamiYuto
 * @date 2021.10.08
 * @details �u�o�������X�g�̃e���v���[�g�v
 */


//----- �C���N���[�h
#include "ScoreData.h"
#include "List.h"
#include "Iterator.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int main()
{
	List<ScoreData> list;
	ConstIterator<ScoreData> itr;
	std::ifstream ifs("scores.txt");
	if (!ifs) return -1;
	ScoreData data = {};
	
	std::cout << "�e�L�X�g�t�@�C���ǂݍ��݊J�n" << std::endl;
	while (!ifs.eof())
	{
		// �O���t�@�C�����f�[�^�擾
		if (!(ifs >> data.score)) continue;
		if (!(ifs >> data.userName)) continue;
		// �擾�����f�[�^�����X�g�����֊i�[
		itr = list.GetEnd();
		if (!list.Insert(itr, data))
		{
			std::cout << "�f�[�^�i�[���s" << std::endl;
			return -1;
		};
	}
	std::cout << "�e�L�X�g�t�@�C���ǂݍ��ݐ���" << std::endl;
	
	std::cout << std::endl;
	
	// �ǂݍ��񂾃f�[�^��S�\��
	std::cout << "�ǂݍ��񂾃f�[�^�̕\���J�n" << std::endl;
	for (Iterator<ScoreData> itr = list.GetBegin(), endItr = list.GetEnd(); itr != endItr; ++itr)
		std::cout << "Score: " << std::setw(5) << (*itr).score << " --- UserName: " << (*itr).userName << std::endl;
	std::cout << "�ǂݍ��񂾃f�[�^�̕\���I��" << std::endl;

	return 0;
}