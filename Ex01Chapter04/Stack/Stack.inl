/**
 * @file Stack.inl
 * @breif �e���v���[�g�X�^�b�N�N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- �C���N���[�h
#include "Stack.h"
#include "Iterator.h"


//-----------------------------------------------------------------------------
template<class T>
Stack<T>::Stack()
	: m_List()
{
}
//-----------------------------------------------------------------------------
template<class T>
Stack<T>::~Stack()
{
}
//-----------------------------------------------------------------------------
template<class T>
int Stack<T>::GetCount() const
{
	return m_List.GetCount();
}
//-----------------------------------------------------------------------------
template<class T>
bool Stack<T>::Push(const T& value)
{
	return m_List.Insert(m_List.GetBegin(), value);
}
//-----------------------------------------------------------------------------
template<class T>
bool Stack<T>::Pop(T* out)
{
	// ���o�����̂�������Ή������Ȃ�
	if (m_List.GetCount() == 0) return false;
	// �v�f�擾
	Iterator<T> itr = m_List.GetBegin();
	if (out) *out = *itr;
	// �v�f�폜
	return m_List.Erase(itr);
}
