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
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


int main()
{
	List<ScoreData> list;
	List<ScoreData>::Iterator itr = list.begin();
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
		itr = list.end();
		if (!list.Insert(itr, data))
		{
			std::cout << "�f�[�^�i�[���s" << std::endl;
			return -1;
		};
	}
	std::cout << "�e�L�X�g�t�@�C���ǂݍ��ݐ���" << std::endl;
	
	std::cout << std::endl;

	std::cout << "�N�C�b�N�\�[�g�J�n" << std::endl;
	auto cmpFunc = [](bool isAsk, const ScoreData& a, const ScoreData&b) { return isAsk ? a.score < b.score : a.score > b.score; };
	list.QuickSort(true, cmpFunc);
	std::cout << "�N�C�b�N�\�[�g�I��" << std::endl << std::endl;


	
	// �ǂݍ��񂾃f�[�^��S�\��
	std::cout << "�ǂݍ��񂾃f�[�^�̕\���J�n" << std::endl;
	for (const auto& data : list)
		std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
	std::cout << "�ǂݍ��񂾃f�[�^�̕\���I��" << std::endl;

	return 0;
}