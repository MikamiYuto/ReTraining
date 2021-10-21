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
	// �f�[�^�\���֐�
	auto showDataFunc = [&list]
	{
		std::cout << "�S�f�[�^�̕\���J�n" << std::endl;
		for (const auto& data : list)
			std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
		std::cout << "�S�f�[�^�̕\���I��" << std::endl;
	};
	// �\�[�g�\���֐�
	auto showSortFunc = [&list](bool(*cmpFunc)(const ScoreData&, const ScoreData&), std::string keyName)
	{
		std::cout << keyName << "���L�[�Ƃ����N�C�b�N�\�[�g�J�n" << std::endl;
		list.QuickSort(cmpFunc);
		std::cout << keyName << "���L�[�Ƃ����N�C�b�N�\�[�g�I��" << std::endl << std::endl;
	};

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

	// �X�R�A���L�[�Ƃ��ă\�[�g�����s
	{
		auto cmpFunc = [](const ScoreData& a, const ScoreData& b)
		{
			if (a.score == b.score)
				return a.userName < b.userName;
			else
				return a.score < b.score;
		};
		showSortFunc(cmpFunc, "�X�R�A");
	}
	// �f�[�^��S�\��
	showDataFunc();

	std::cout << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Enter�L�[���͂Ń��[�U�����L�[�Ƃ����\�[�g���ʂ�\�����܂�" << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cin.get();
	std::system("cls");

	// ���[�U�����L�[�Ƃ��ă\�[�g�����s
	{
		auto cmpFunc = [](const ScoreData& a, const ScoreData&b)
		{
			if (a.userName == b.userName)
				return a.score < b.score;
			else
				return a.userName < b.userName;
		};
		showSortFunc(cmpFunc, "���[�U��");
	}
	// �f�[�^��S�\��
	showDataFunc();

	return 0;
}