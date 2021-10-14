/**
 * @file HashTable.h
 * @brief �e���v���[�g�n�b�V���e�[�u���N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- �C���N���[�h
#include "List.h"
#include <string>


//----- �萔��`
constexpr int DEFAULT_HASH_PACKET_SIZE(5);


//----- �v���g�^�C�v�錾
static int CalcHash(const int& key);
static int CalcHash(const std::string& key);


/** 
 * @brief	�n�b�V���e�[�u���N���X 
 * @param Key			�L�[�l
 * @param Value			�l
 * @param CalcHashFunc	�n�b�V���l���o�֐�
 * @param SIZE			�p�P�b�g�T�C�Y(�n�b�V���֐����瓱�o�����l���܂߂��l���w��
 */
template<class Key, class Value, int(*CalcHashFunc)(const Key&), int SIZE>
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
	List<Pair>	m_Table[SIZE];			//!< �y�A�i�[�e�[�u��
	int			m_ElementCnt;			//!< �v�f��

public:
	/**
	 * @brief	�R���X�g���N�^
	 */
	HashTable();
	/**
	 * @brief	�f�X�g���N�^
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
	 * @return			�}���̐��ہA���s�̏ꍇ�͉������Ȃ�
	 *					���s�P�[�X
	 *					�E�L�[�̏d��
	 *					�E�v�f�̃������m�ێ��s
	 */
	bool Insert(const Key& key, const Value& value);
	/**
	 * @brief			�v�f�̍폜
	 * @param[in] key	�폜����v�f�̃L�[�l
	 * @return			�폜�̐��ہA���s�̏ꍇ�͉������Ȃ�
	 *					���s�P�[�X
	 *					�E�L�[�����݂��Ȃ��i�폜�ρA���}���A��
	 */
	bool Erase(const Key& key);
	/**
	 * @brief			�v�f�̌���
	 * @param[in] key	��������v�f�̃L�[�l
	 * @param[out] out	���������l�̎���
	 * @return			�����̐��ہA���s�̏ꍇ�͉������Ȃ�
	 *					���s�P�[�X
	 *					�E�L�[�����݂��Ȃ��i�폜�ρA���}���A��
	 */
	bool Find(const Key& key, Value* out = nullptr) const;

private:
	/**
	 * @brief			�L�[����n�b�V���l���w�����X�g�ւ̎Q�Ƃ��擾����
	 *					CalcHashFunc��SIZE�̂����ꂩ�ɖ�肪����ꍇAssert����
	 * @param[in] key	�L�[�l
	 * @return			�n�b�V���l
	 */
	int GetHash(const Key& key) const;
};
#include "HashTable.inl"