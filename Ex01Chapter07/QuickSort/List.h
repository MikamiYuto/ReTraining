/**
 * @file List.h
 * @brief �e���v���[�g�o�������X�g�N���X�̒�`�t�@�C��
 * @author MikamiYuto
 * @date 2021.10.15
 */
#pragma once


 /**
  * @brief		�o�������X�g�N���X
  * @tparam T	�l
  */
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
		const List<T>*	m_pList;	//!< �C�e���[�^�̎Q�Ɛ惊�X�g
		List<T>::Node* m_pNode;		//!< �C�e���[�^���w�������m�[�h

	public:
		/**
		 * @brief			�R���X�g���N�^
		 * @param[in] pList �C�e���[�^���Q�Ƃ��郊�X�g
		 * @param[in] pNode �C�e���[�^���w�������v�f
		 */
		ConstIterator(const List<T>* pList = nullptr, List<T>::Node* pNode = nullptr);
		/**
		 * @brief �f�X�g���N�^
		 */
		virtual ~ConstIterator();

	public:
		/**
		 * @brief	�O�u�C���N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	�m�[�h�𖖔��ֈ���炵����̃C�e���[�^
		 */
		ConstIterator& operator++();
		/**
		 * @brief	��u�C���N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	���݂̃m�[�h���w���C�e���[�^
		 */
		ConstIterator operator++(int);
		/**
		 * @brief	�O�u�f�N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	�m�[�h��擪�ֈ���炵����̃C�e���[�^
		 */
		ConstIterator& operator--();
		/**
		 * @brief	��u�f�N�������g���Z�q�̃I�[�o�[���[�h
		 * @return	���݂̃m�[�h���w���C�e���[�^
		 */
		ConstIterator operator--(int);
		/**
		 * @brief	�������Z�q�̃I�[�o�[���[�h
		 * @return	������r����
		 */
		bool operator==(const ConstIterator& itr) const;
		/**
		 * @brief	�񓙉����Z�q�̃I�[�o�[���[�h
		 * @return	�񓙉���r����
		 */
		bool operator!=(const ConstIterator& itr) const;
		/**
		 * @brief	�֐߉��Z�q�̃I�[�o�[���[�h
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
		 * @brief			�R���X�g���N�^
		 * @param[in] pList �C�e���[�^���Q�Ƃ��郊�X�g
		 * @param[in] pNode �C�e���[�^���w�������m�[�h
		 */
		Iterator(const List<T>* pList = nullptr, List<T>::Node* pNode = nullptr);
		/**
		 * @brief �f�X�g���N�^
		 */
		~Iterator();

	public:
		/**
		 * @brief	�֐߉��Z�q�̃I�[�o�[���[�h
		 * @return	�C�e���[�^���w���v�f�̒l
		 */
		T& operator*();
	};

private:
	using CmpDataFunc = bool(*)(bool, const T&, const T&);

private:
	Node*	m_pDummyNode;	//!< �_�~�[�m�[�h
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
	bool Insert(ConstIterator& itr, const T& value);
	/**
	 * @brief			�v�f�̍폜
	 * @param[in] itr	�폜�ʒu
	 * @return			�폜�̐��ہA���s�̏ꍇ�͉������Ȃ�
	 *					���s�P�[�X
	 *					�E���X�g���Q��
	 *					�E�ʂ̃��X�g���Q�Ƃ��Ă���
	 *					�E����(�_�~�[�m�[�h)���Q�Ƃ��Ă���
	 */
	bool Erase(ConstIterator& itr);
	/**
	 * @brief	�擪�m�[�h���w���C�e���[�^�̎擾
	 * @return	�擪�C�e���[�^
	 */
	Iterator begin();
	/**
	 * @brief	�擪�m�[�h���w���R���X�g�C�e���[�^�̎擾
	 * @return	�擪�R���X�g�C�e���[�^
	 */
	ConstIterator begin() const;
	/**
	 * @brief	�����m�[�h(�_�~�[)���w���C�e���[�^�̎擾
	 * @return	�����C�e���[�^
	 */
	Iterator end();
	/**
	 * @brief	�����m�[�h(�_�~�[)���w���R���X�g�C�e���[�^�̎擾
	 * @return	�����R���X�g�C�e���[�^
	 */
	ConstIterator end() const;
	/**
	 * @brief				�N�C�b�N�\�[�g
	 * @param[in] isAsk		���񏇂̎w��(true:�����Afalse:�~��
	 * @param[in] cmpFunc	�v�f��r�֐��Anullptr�̏ꍇ�͉������Ȃ�
	 */
	void QuickSort(bool isAsk, CmpDataFunc cmpFunc);

private:
	/**
	 * @brief			�v�f�̌���
	 * @param[in] pA	��������m�[�h���̂P
	 * @param[in] pB	��������m�[�h���̂Q
	 */
	void Swap(Node* pA, Node* pB);
	/**
	 * @brief		�����l�̎擾
	 * @param[in] a ��ׂ�l���̂P
	 * @param[in] b ��ׂ�l���̂Q
	 * @param[in] c ��ׂ�l���̂R
	 * @return		�����̒����l
	 */
	const T& Median(CmpDataFunc cmpFunc, const T& a, const T&b, const T&c) const;
	/**
	 * @brief				�v�f��召�ɕ���(����)����
	 * @param[in] isAsk		���񏇂̎w��(true:�����Afalse:�~��
	 * @param[in] cmpFunc	�v�f��r�֐�
	 * @param[in] pivot		���������l
	 * @param[in] L			���񂷂�͈͂̐擪�m�[�h
	 * @param[in] R			���񂷂�͈̖͂����m�[�h
	 * @param[out] 	ML		���p�A�召�ɐ��񂵂���Ԃ̋��ڂɂȂ�擪���m�[�h
	 * @param[out] 	MR		���p�A�召�ɐ��񂵂���Ԃ̋��ڂɂȂ閖�����m�[�h
	 */
	void Partition(bool isAsk, CmpDataFunc cmpFunc, const T& pivot, Node* L, Node* R, Node*& ML, Node*& MR);
	/**
	 * @brief				�N�C�b�N�\�[�g(�ċA
	 * @param[in] isAsk		���񏇂̎w��(true:�����Afalse:�~��
	 * @param[in] cmpFunc	�v�f��r�֐�
	 * @param[in] L			���񂷂�͈͂̐擪�m�[�h
	 * @param[in] R			���񂷂�͈̖͂����m�[�h
	 */
	void QuickSort(bool isAsk, CmpDataFunc cmpFunc, Node* L, Node* R);
};
#include "List.inl"