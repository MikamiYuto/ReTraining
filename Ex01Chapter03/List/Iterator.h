/**
 * @file List.h
 * @breif �e���v���[�g�C�e���[�^�N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.11
 */
#pragma once


//----- �C���N���[�h
#include "List.h"


/** �R���X�g�C�e���[�^�N���X */
template<class T>
class ConstIterator
{
public:
	friend class List<T>;

protected:
	typename List<T>*		m_pList;		//!< �C�e���[�^�̎Q�Ɛ惊�X�g
	typename List<T>::Node* m_pNode;		//!< �C�e���[�^���w�������m�[�h

public:
	/**
	 * @breif		�R���X�g���N�^
	 * @param[in] pList �C�e���[�^���Q�Ƃ��郊�X�g
	 * @param[in] pNode �C�e���[�^���w�������v�f
	 */
	ConstIterator(typename List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
	/**
	 * @breif �f�X�g���N�^
	 */
	virtual ~ConstIterator();

public:
	/**
	 * @breif	�O�u�C���N�������g���Z�q�̃I�[�o�[���[�h
	 * @return	�m�[�h�𖖔��ֈ���炵����̃C�e���[�^
	 * @details �m�[�h�𖖔��ֈ���炷
	 */
	ConstIterator& operator++();
	/**
	 * @breif	��u�C���N�������g���Z�q�̃I�[�o�[���[�h
	 * @return	���݂̃m�[�h���w���C�e���[�^
	 * @details �m�[�h�𖖔��ֈ���炷
	 */
	ConstIterator operator++(int);
	/**
	 * @breif	�O�u�f�N�������g���Z�q�̃I�[�o�[���[�h
	 * @return	�m�[�h��擪�ֈ���炵����̃C�e���[�^
	 * @details �m�[�h��擪�ֈ���炷
	 */
	ConstIterator& operator--();
	/**
	 * @breif	��u�f�N�������g���Z�q�̃I�[�o�[���[�h
	 * @return	���݂̃m�[�h���w���C�e���[�^
	 * @details �m�[�h��擪�ֈ���炷
	 */
	ConstIterator operator--(int);
	/**
	 * @breif	�������Z�q�̃I�[�o�[���[�h
	 * @return	������r����
	 * @details �R���X�g�C�e���[�^�̎w���Ă���m�[�h����������r����
	 */
	bool operator==(const ConstIterator& itr) const;
	/**
	 * @breif	�񓙉����Z�q�̃I�[�o�[���[�h
	 * @return	�񓙉���r����
	 * @details �R���X�g�C�e���[�^�̎w���Ă���m�[�h���񓙉�����r����
	 */
	bool operator!=(const ConstIterator& itr) const;
	/**
	 * @breif	�֐߉��Z�q�̃I�[�o�[���[�h
	 * @return	�C�e���[�^���w���v�f
	 */
	const T& operator*();
};

/** �C�e���[�^�N���X */
template<class T>
class Iterator : public ConstIterator<T>
{
public:
	/**
	 * @breif		�R���X�g���N�^
	 * @param[in] p �C�e���[�^���Q�Ƃ��郊�X�g
	 * @param[in] p �C�e���[�^���w�������m�[�h
	 */
	Iterator(typename List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
	/**
	 * @breif �f�X�g���N�^
	 */
	~Iterator();
};
#include "Iterator.inl"