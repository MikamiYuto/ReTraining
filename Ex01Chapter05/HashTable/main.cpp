/**
 * @file main.cpp
 * @breif ���C��
 * @author MikamiYuto
 * @date 2021.10.13
 * @details �ۑ�1_5�n�b�V���e�[�u���̍Ď���
 */


//----- �C���N���[�h
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <string>


int main()
{
	//HashTable hashTable;
	//std::string key;
	//std::string value;
	//int cmdNum = 0;
	//bool isLoop = true;

	//// �����l
	//hashTable.Push(HashWord("����", "�܂��܂�"));
	//hashTable.Push(HashWord("���w", "�����A�O�p�֐��ӂ肩����ӎ���"));
	//hashTable.Push(HashWord("����", "���ӂ�����"));
	//hashTable.Push(HashWord("�Љ�", "�ڂ��ڂ�"));
	//hashTable.Push(HashWord("�p��", "�P�ꂾ���Ȃ�c"));

	//// �n�b�V���e�[�u������
	//while (isLoop)
	//{
	//	std::cout << std::endl;
	//	std::cout << "�n�b�V���̑�����@����͂��Ă�������" << std::endl;
	//	std::cout << "1 : �o�^, 2 : �폜, 3 : ����, 0 : �I��" << std::endl;
	//	std::cout << "�������[���l]��";
	//	std::cin >> cmdNum;

	//	// ��ʃN���A
	//	std::system("cls");

	//	//�@�L�[�S�\��
	//	hashTable.DrawKeyList();
	//	switch (cmdNum)
	//	{
	//	case 0:	// �I��
	//		isLoop = false;
	//		break;
	//	case 1:	// �o�^
	//		std::cout << "�o�^����P�����͂��Ă�������" << std::endl;
	//		std::cout << "�L�[����[������]��";
	//		std::cin >> key;
	//		std::cout << std::endl;
	//		std::cout << "�o�^�������������͂��Ă�������" << std::endl;
	//		std::cout << "�l����[������]��";
	//		std::cin >> value;
	//		hashTable.Push(HashWord(key, value));
	//		std::cout << "�o�^����" << std::endl;
	//		break;
	//	case 2: // �폜
	//		std::cout << "�폜����P�����͂��Ă�������" << std::endl;
	//		std::cout << "�L�[����[������]��";
	//		std::cin >> key;
	//		hashTable.Erase(key);
	//		std::cout << "�폜����" << std::endl;
	//		break;
	//	case 3: // ����
	//		std::cout << "��������P�����͂��Ă�������" << std::endl;
	//		std::cout << "�L�[����[������]��";
	//		std::cin >> key;
	//		value = hashTable.Find(key);
	//		std::cout << std::endl;
	//		std::cout << "����������" << std::endl;
	//		std::cout << value << std::endl;
	//		std::cout << "��������" << std::endl;
	//		break;
	//	default:
	//		break;
	//	}
	//}

	//// �I��
	//hashTable.Clear();

	return 0;
}