/**
 * @file Queue.h
 * @breif �e���v���[�g�L���[�N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- �C���N���[�h
#include "List.h"


/** �o�������X�g�N���X */
template<class T>
class Queue
{
private:
	List<T> m_List;

public:
	/**
	 * @brief	�R���X�g���N�^
	 * @details ���X�g��p�ӂ���
	 */
	Queue();
	/**
	 * @brief	�f�X�g���N�^
	 * @details �v�f���������
	 */
	~Queue();

public:
	/**
	 * @brief	�v�f���̎擾
	 * @return	�v�f��
	 */
	int GetCount() const;
	/**
	 * @breif			�v�f�̑}��
	 * @param[in] value �}������v�f�̒l
	 * @return			�}���̐���
	 */
	bool Push(const T& value);
	/**
	 * @breif			�v�f�̎��o��
	 * @param[in] out	���o�����l�̎���
	 * @return			���o���̐���
	 */
	bool Pop(T* out = nullptr);
};
#include "Queue.inl"