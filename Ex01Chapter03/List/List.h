/**
 * @file List.h
 * @breif �e���v���[�g�o�������X�g�N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


template<class T>
class ConstIterator;
template<class T>
class Iterator;
 /** �o�������X�g�N���X */
template<class T>
class List
{
public:
	/** ���X�g�m�[�h�\���� */
	struct Node
	{
		Node*		pFront;	//!< �O�̃m�[�h���w���|�C���^(�擪
		Node*		pBack;	//!< ��̃m�[�h���w���|�C���^(����
		T			data;	//!< �l��ێ�
	};

private:
	Node*	m_pDummyNode;	//!< �_�~�[�m�[�h
	int		m_NodeCnt;		//!< �v�f���i�_�~�[�͖��J�E���g

public:
	/**
	 * @breif	�R���X�g���N�^
	 * @details	�_�~�[�m�[�h�𐶐����܂�
	 */
	List();
	/**
	 * @breif	�f�X�g���N�^
	 * @details �ێ����Ă����m�[�h��S�ĉ�����܂�
	 */
	~List();

public:
	/**
	 * @brief	�v�f���̎擾
	 * @return	�v�f��
	 * @details ���X�g�����ݕێ����Ă���v�f����Ԃ��܂�
	 */
	int GetCount() const;
	/**
	 * @brief			�v�f�̑}��
	 * @param[in] itr	�}���ʒu
	 * @param[in] value �}������l
	 * @return			�}���̐���
	 */
	bool Insert(Iterator<T> itr, const T& value);
	bool Insert(ConstIterator<T> itr, const T& value);
	/**
	 * @brief			�v�f�̍폜
	 * @param[in] itr	�폜�ʒu
	 * @retunr			�폜�̐���
	 */
	bool Erase(Iterator<T> itr);
	bool Erase(ConstIterator<T> itr);
	/**
	 * @brief	�擪�m�[�h���w���C�e���[�^�̎擾
	 * @return	�擪�C�e���[�^
	 */
	Iterator<T> GetBegin();
	/**
	 * @brief	�擪�m�[�h���w���R���X�g�C�e���[�^�̎擾
	 * @return	�擪�R���X�g�C�e���[�^
	 */
	ConstIterator<T> GetConstBegin() const;
	/**
	 * @brief	�����m�[�h���w���C�e���[�^�̎擾
	 * @return	�����C�e���[�^
	 */
	Iterator<T> GetEnd();
	/**
	 * @brief	�����m�[�h���w���R���X�g�C�e���[�^�̎擾
	 * @return	�����R���X�g�C�e���[�^
	 */
	ConstIterator<T> GetConstEnd() const;
};
#include "List.inl"