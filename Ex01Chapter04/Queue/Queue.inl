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
	return 0;
}
//-----------------------------------------------------------------------------
template<class T>
bool Queue<T>::Push(const T& value)
{
	return false;
}
//-----------------------------------------------------------------------------
template<class T>
bool Queue<T>::Pop(T* out)
{
	return false;
}
