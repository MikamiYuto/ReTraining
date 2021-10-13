/**
 * @file HashTable.h
 * @breif �e���v���[�g�n�b�V���e�[�u���N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- �C���N���[�h
#include "List.h"
#include "Iterator.h"


// �n�b�V���e�[�u���N���X
template<class Key, class Value, int(*CalcHashFunc)(Key), int SIZE>
class HashTable
{
private:
	/** �y�A�\���� */
	struct Pair
	{
		Key		key;	//!< �n�b�V���̃L�[
		Value	value;	//!< �l
	};

private:
	List<Pair> m_Table[SIZE];			//!< �y�A�i�[�e�[�u��

public:
	/**
	 * @brief	�R���X�g���N�^
	 * @details	�e���v���[�g�����Ŏw�肳�ꂽSIZE���̃��X�g�������ŗp�ӂ���܂�
	 */
	HashTable();
	/**
	 * @brief	�f�X�g���N�^
	 * @details	�ێ����Ă����v�f��������܂�
	 */
	~HashTable();

public:
	/**
	 * @brief	�v�f���̎擾
	 * @return	�v�f��
	 */
	int GetCount() const;
	/**
	 * @brief			�v�f�̑}��
	 * @param[in] key	�}������v�f�̃L�[�l
	 * @param[in] value	�}������v�f�̒l
	 * @return			�}���̐���
	 */
	bool Insert(const Key& key, const Value& value);
	/**
	 * @brief			�v�f�̍폜
	 * @param[in] key	�폜����v�f�̃L�[�l
	 * @return			�폜�̐���
	 */
	bool Erase(const Key& key);
	/**
	 * @brief			�v�f�̌���
	 * @param[in] key	��������v�f�̃L�[�l
	 * @param[out] out	���������l�̎���
	 * @return			�����̐���
	 */
	bool Find(const Key& key, Value* out);
};