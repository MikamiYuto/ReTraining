/**
 * @file Queue.inl
 * @breif �e���v���[�g�X�^�b�N�N���X�̎����t�@�C��
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- �C���N���[�h
#include "Queue.h"


//-----------------------------------------------------------------------------
template<class T>
Queue<T>::Queue()
	: m_List()
{
}
//-----------------------------------------------------------------------------
template<class T>
Queue<T>::~Queue()
{
}
//-----------------------------------------------------------------------------
template<class T>
int Queue<T>::GetCount() const
{
	return m_List.GetCount();
}
//-----------------------------------------------------------------------------
template<class T>
bool Queue<T>::Push(const T& value)
{
	return m_List.Insert(m_List.GetEnd(), value);
}
//-----------------------------------------------------------------------------
template<class T>
bool Queue<T>::Pop(T* out)
{
	// ���o�����̂�������Ή������Ȃ�
	if (m_List.GetCount() == 0) return false;
	// �v�f�擾
	Iterator<T> itr = m_List.GetBegin();
	if (out) *out = *itr;
	// �v�f�폜
	return m_List.Erase(itr);
}
