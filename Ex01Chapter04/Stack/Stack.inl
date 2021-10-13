/**
 * @file Stack.inl
 * @breif テンプレートスタッククラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- インクルード
#include "Stack.h"


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
	return 0;
}
//-----------------------------------------------------------------------------
template<class T>
bool Stack<T>::Push(const T& value)
{
	return false;
}
//-----------------------------------------------------------------------------
template<class T>
bool Stack<T>::Pop(T* out)
{
	return false;
}
