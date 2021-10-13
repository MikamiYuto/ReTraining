/**
 * @file main.cpp
 * @breif ���C��
 * @author MikamiYuto
 * @date 2021.10.13
 * @details �e���v���[�g�L���[
 */


//----- �C���N���[�h
#include "Queue.h"
#include "ScoreData.h"
#include <iostream>
#include <iomanip>
#include <fstream>


int main()
{
	Queue<ScoreData> queue;
	std::ifstream ifs("Scores.txt");
	if (!ifs) return -1;
	ScoreData data = {};

	// �f�[�^�ǂݍ���
	while (!ifs.eof())
	{
		// �ǂݍ��݁i�v�b�V��)
		{
			int num = 0;
			std::cout << "�f�[�^�ǂݍ��ݐ�(Push)����́�";
			std::cin >> num;
			std::cout << std::endl;
			std::cout << "Push�J�n" << std::endl;
			for (int i = 0; i < num; ++i)
			{
				if (!(ifs >> data.score)) continue;
				if (!(ifs >> data.userName)) continue;
				if (!queue.Push(data))
				{
					std::cout << "�L���[�ւ̃f�[�^�i�[���s" << std::endl;
					return -1;
				}
				std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
			}
			std::cout << "Push�I��" << std::endl << std::endl;
		}
		// ���o���i�|�b�v�j
		{
			int	num = 0;
			std::cout << "�f�[�^�o�͐�(Pop)����́�";
			std::cin >> num;
			std::cout << std::endl;
			std::cout << "Pop�J�n" << std::endl;
			for (int i = 0; i < num; ++i)
			{
				if (!queue.Pop(&data))
				{
					std::cout << "�L���[���̃f�[�^����ɂȂ�܂���" << std::endl;
					break;
				}
				std::cout << "Score: " << std::setw(5) << data.score << " --- UserName: " << data.userName << std::endl;
			}
			std::cout << "Pop�I��" << std::endl << std::endl;
		}
	}

	if (!ifs.eof())
	{
		std::cout << "�t�@�C���f�[�^���S�ēǂݍ��܂�܂���" << std::endl;
		std::cout << "�A�v�����I�����܂�" << std::endl;
	}

	return 0;
}