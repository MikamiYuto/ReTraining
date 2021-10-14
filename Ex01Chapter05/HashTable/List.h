/**
 * @file List.h
 * @breif �e���v���[�g�o�������X�g�N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.08
 */
#pragma once


 /** �o�������X�g�N���X */
template<class T>
class List
{
private:
	/** ���X�g�m�[�h�\���� */
	struct Node
	{
		Node*		pFront;	//!< �O�̃m�[�h���w���|�C���^(�擪
		Node*		pBack;	//!< ��̃m�[�h���w���|�C���^(����
		T			data;	//!< �l��ێ�
	};

public:
	/** �R���X�g�C�e���[�^�N���X */
	class ConstIterator
	{
	public:
		friend class List<T>;

	protected:
		typename const List<T>*	m_pList;		//!< �C�e���[�^�̎Q�Ɛ惊�X�g
		typename List<T>::Node* m_pNode;		//!< �C�e���[�^���w�������m�[�h

	public:
		/**
		 * @breif			�R���X�g���N�^
		 * @param[in] pList �C�e���[�^���Q�Ƃ��郊�X�g
		 * @param[in] pNode �C�e���[�^���w�������v�f
		 */
		ConstIterator(typename const List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
		/**
		 * @breif �f�X�g���N�^
		 */
		virtual ~ConstIterator();
	
	public:
		/**
		 * @breif	�O�u�C���N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	�m�[�h�𖖔��ֈ���炵����̃C�e���[�^
		 */
		typename ConstIterator& operator++();
		/**
		 * @breif	��u�C���N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	���݂̃m�[�h���w���C�e���[�^
		 */
		typename ConstIterator operator++(int);
		/**
		 * @breif	�O�u�f�N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	�m�[�h��擪�ֈ���炵����̃C�e���[�^
		 */
		typename ConstIterator& operator--();
		/**
		 * @breif	��u�f�N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	���݂̃m�[�h���w���C�e���[�^
		 */
		typename ConstIterator operator--(int);
		/**
		 * @breif	�������Z�q�̃I�[�o�[���[�h
		 * @return	������r����
		 */
		bool operator==(typename const ConstIterator& itr) const;
		/**
		 * @breif	�񓙉����Z�q�̃I�[�o�[���[�h
		 * @return	�񓙉���r����
		 */
		bool operator!=(typename const ConstIterator& itr) const;
		/**
		 * @breif	�֐߉��Z�q�̃I�[�o�[���[�h
		 * @return	�C�e���[�^���w���v�f�̒l
		 */
		const T& operator*() const;
	};

public:
	/** �C�e���[�^�N���X */
	class Iterator : public ConstIterator
	{
	public:
		/**
		 * @breif			�R���X�g���N�^
		 * @param[in] pList �C�e���[�^���Q�Ƃ��郊�X�g
		 * @param[in] pNode �C�e���[�^���w�������m�[�h
		 */
		Iterator(typename const List<T>* pList = nullptr, typename List<T>::Node* pNode = nullptr);
		/**
		 * @breif �f�X�g���N�^
		 */
		~Iterator();
	
	public:
		/**
		 * @breif	�֐߉��Z�q�̃I�[�o�[���[�h
		 * @return	�C�e���[�^���w���v�f�̒l
		 */
		T& operator*();
	};

private:
	Node	m_DummyNode;	//!< �_�~�[�m�[�h
	int		m_ElementCnt;	//!< �v�f���i�_�~�[�͖��J�E���g

public:
	/**
	 * @brief	�R���X�g���N�^
	 */
	List();
	/**
	 * @brief	�f�X�g���N�^
	 */
	~List();

public:
	/**
	 * @brief	�v�f���̎擾
	 * @return	�v�f��
	 */
	int GetCount() const;
	/**
	 * @brief			�v�f�̑}��
	 * @param[in] itr	�}���ʒu
	 * @param[in] value �}������l
	 * @return			�}���̐��ہA���s�̏ꍇ�͉������Ȃ�
	 *					���s�P�[�X
	 *					�E���X�g���Q��
	 *					�E�ʂ̃��X�g���Q�Ƃ��Ă���
	 *					�E�v�f�̃������m�ێ��s
	 */
	bool Insert(typename ConstIterator& itr, const T& value);
	/**
	 * @brief			�v�f�̍폜
	 * @param[in] itr	�폜�ʒu
	 * @return			�폜�̐��ہA���s�̏ꍇ�͉������Ȃ�
	 *					���s�P�[�X
	 *					�E���X�g���Q��
	 *					�E�ʂ̃��X�g���Q�Ƃ��Ă���
	 *					�E����(�_�~�[�m�[�h)���Q�Ƃ��Ă���
	 */
	bool Erase(typename ConstIterator& itr);
	/**
	 * @brief	�擪�m�[�h���w���C�e���[�^�̎擾
	 * @return	�擪�C�e���[�^
	 */
	typename Iterator begin();
	/**
	 * @brief	�擪�m�[�h���w���R���X�g�C�e���[�^�̎擾
	 * @return	�擪�R���X�g�C�e���[�^
	 */
	typename ConstIterator begin() const;
	/**
	 * @brief	�����m�[�h(�_�~�[)���w���C�e���[�^�̎擾
	 * @return	�����C�e���[�^
	 */
	typename Iterator end();
	/**
	 * @brief	�����m�[�h(�_�~�[)���w���R���X�g�C�e���[�^�̎擾
	 * @return	�����R���X�g�C�e���[�^
	 */
	typename ConstIterator end() const;
};
#include "List.inl"