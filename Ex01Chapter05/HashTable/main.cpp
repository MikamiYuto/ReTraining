/**
 * @file main.cpp
 * @brief ���C��
 * @author MikamiYuto
 * @date 2021.10.13
 * @details �ۑ�1_5�n�b�V���e�[�u���̍Ď���
 */


//----- �C���N���[�h
#include "HashTable.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"


int main()
{
	HashTable<std::string, std::string, CalcHash, DEFAULT_HASH_BUCKET_SIZE> hashTable;
	List<std::string> keyList;
	List<std::string>::Iterator itr;
	std::string key;
	std::string value;
	int cmdNum = 0;
	bool isLoop = true;

	// �����l
	hashTable.Insert("���E�]��", "�����ِ��E�]���A�]�X�����A�j���������܂ł͂Ȃ낤�����L���O�s���̈�ʂ�����");
	hashTable.Insert("�]��������X���C����������", "�����ِ��E\"�l�O\"�]���A�߂����R�~�J���C�Y�Ƃ��O�b�Y������Ă�");
	hashTable.Insert("���_��H�ׂ�����", "�m��l���m��_�[�N��L�A���������߁�");
	hashTable.Insert("���̗E�҂̐���オ��", "�ِ��E�]�ځAWeb�łƏ��Дłœ��e�����\�Ⴄ");
	itr = keyList.end();
	keyList.Insert(itr, "���E�]��");
	itr = keyList.end();
	keyList.Insert(itr, "�]��������X���C����������");
	itr = keyList.end();
	keyList.Insert(itr, "���_��H�ׂ�����");
	itr = keyList.end();
	keyList.Insert(itr, "���̗E�҂̐���オ��");
	
	// �n�b�V���e�[�u������
	while (isLoop)
	{
		std::cout << std::endl;
		std::cout << "�n�b�V���̑�����@����͂��Ă�������" << std::endl;
		std::cout << "1 : �o�^, 2 : �폜, 3 : ����, 0 : �I��" << std::endl;
		std::cout << "�������[���l]��";
		std::cin >> cmdNum;
	
		// ��ʃN���A
		std::system("cls");
	
		//�@�L�[�S�\��
		std::cout << "---�����ݓo�^����Ă���L�[��---" << std::endl << std::endl;
		for (const auto& str : keyList)
			std::cout << str << std::endl;
		std::cout << std::endl;
		std::cout << "---�����ݓo�^����Ă���L�[��---" << std::endl << std::endl;
		switch (cmdNum)
		{
		case 0:	// �I��
			isLoop = false;
			break;
		case 1:	// �o�^
			std::cout << "�o�^����P�����͂��Ă�������" << std::endl;
			std::cout << "�L�[����[������]��";
			std::cin >> key;
			std::cout << std::endl;
			std::cout << "�o�^�������������͂��Ă�������" << std::endl;
			std::cout << "�l����[������]��";
			std::cin >> value;
			if (hashTable.Insert(key, value))
			{
				std::cout << "�o�^����" << std::endl;
				itr = keyList.end();
				keyList.Insert(itr, key);
			}
			else
			{
				std::cout << "�폜���s(�P��d��)" << std::endl;
			}
			break;
		case 2: // �폜
			std::cout << "�폜����P�����͂��Ă�������" << std::endl;
			std::cout << "�L�[����[������]��";
			std::cin >> key;
			if (hashTable.Erase(key))
			{
				itr = keyList.begin();
				for (auto e = keyList.end(); itr != e; ++itr)
					if (*itr == key) break;
				keyList.Erase(itr);
				std::cout << "�폜����" << std::endl;
			}
			else
				std::cout << "�폜���s(�P�ꖢ�o�^)" << std::endl;
			break;
		case 3: // ����
			std::cout << "��������P�����͂��Ă�������" << std::endl;
			std::cout << "�L�[����[������]��";
			std::cin >> key;
			if (hashTable.Find(key, &value))
			{
				std::cout << std::endl;
				std::cout << "����������" << std::endl;
				std::cout << value << std::endl;
				std::cout << "��������" << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "�P�ꂪ�o�^����Ă��܂���" << std::endl;
				std::cout << "�������s" << std::endl;
			}
			break;
		default:
			break;
		}
		key = "";
		value = "";
	}

	return 0;
}