/**
 * @file List.inl
 * @breif �e���v���[�g�o�������X�g�N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.11
 */
#pragma once


//----- �C���N���[�h
#include "List.h"
#include "Iterator.h"


//-----------------------------------------------------------------------------
template<class T>
List<T>::List()
	: m_pDummyNode(nullptr)
	, m_NodeCnt(0)
{
	m_pDummyNode = new Node;
	m_pDummyNode->pFront = m_pDummyNode;
	m_pDummyNode->pBack = m_pDummyNode;
}
//-----------------------------------------------------------------------------
template<class T>
List<T>::~List()
{
	Node* pNode = m_pDummyNode->pBack;
	Node* pDeleteNode = nullptr;
	// �擪����m�[�h�����ɍ폜���Ă���
	while (pNode != m_pDummyNode)
	{
		pDeleteNode = pNode;
		pNode = pNode->pBack;
		delete pDeleteNode;
	}
	delete m_pDummyNode;// �Ō�
	m_pDummyNode = nullptr;
}
//-----------------------------------------------------------------------------
template<class T>
int List<T>::GetCount() const
{
	return m_NodeCnt;
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Insert(Iterator<T> itr, const T& value)
{
	// �s���C�e���[�^�ɂ��}�����s
	if (!itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;

	// �V�K�m�[�h�̐����Ɛݒ�
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pBack = itr.m_pNode;
	newNode->pFront = itr.m_pNode->pFront;
	// �O��̃m�[�h�̐ڑ����C��
	itr.m_pNode->pFront = newNode;
	newNode->pFront->pBack = newNode;
	// ���X�g�v�f��+1
	++m_NodeCnt;

	return true; // �}������
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Insert(ConstIterator<T> itr, const T& value)
{
	// �s���C�e���[�^�ɂ��}�����s
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;

	// �V�K�m�[�h�̐����Ɛݒ�
	Node* newNode = new Node;
	newNode->data = value;
	newNode->pBack = itr.m_pNode;
	newNode->pFront = itr.m_pNode->pFront;
	// �O��̃m�[�h�̐ڑ����C��
	itr.m_pNode->pFront = newNode;
	newNode->pFront->pBack = newNode;
	// ���X�g�v�f��+1
	++m_NodeCnt;

	return true; // �}������
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Erase(Iterator<T> itr)
{
	// �s���C�e���[�^�ɂ��폜���s
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;
	// �_�~�[�m�[�h�̏ꍇ���폜���s
	if (itr.m_pNode == m_pDummyNode) return false;

	// �O��̃m�[�h�̐ڑ����C��
	itr.m_pNode->pBack->pFront = itr.m_pNode->pFront;
	itr.m_pNode->pFront->pBack = itr.m_pNode->pBack;
	// �Y���m�[�h���폜
	delete itr.m_pNode;
	itr.m_pNode = nullptr;
	// ���X�g�v�f��-1
	--m_NodeCnt;

	return true;	// �폜����
}
//-----------------------------------------------------------------------------
template<class T>
bool List<T>::Erase(ConstIterator<T> itr)
{
	// �s���C�e���[�^�ɂ��폜���s
	if (itr.m_pList != this) return false;
	if (!itr.m_pNode) return false;
	// �_�~�[�m�[�h�̏ꍇ���폜���s
	if (itr.m_pNode == m_pDummyNode) return false;

	// �O��̃m�[�h�̐ڑ����C��
	itr.m_pNode->pBack->pFront = itr.m_pNode->pFront;
	itr.m_pNode->pFront->pBack = itr.m_pNode->pBack;
	// �Y���m�[�h���폜
	delete itr.m_pNode;
	itr.m_pNode = nullptr;
	// ���X�g�v�f��-1
	--m_NodeCnt;

	return true;	// �폜����
}
//-----------------------------------------------------------------------------
template<class T>
Iterator<T> List<T>::GetBegin()
{
	return Iterator<T>(this, m_pDummyNode->pBack);
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T> List<T>::GetConstBegin() const
{
	return ConstIterator<T>(this, m_pDummyNode->pBack);
}
//-----------------------------------------------------------------------------
template<class T>
Iterator<T> List<T>::GetEnd()
{
	return Iterator<T>(this, m_pDummyNode);
}
//-----------------------------------------------------------------------------
template<class T>
ConstIterator<T> List<T>::GetConstEnd() const
{
	return ConstIterator<T>(this, m_pDummyNode);
}
