/**
 * @file Stack.inl
 * @breif テンプレートスタッククラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- インクルード
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
	// 取り出すものが無ければ何もしない
	if (m_List.GetCount() == 0) return false;
	// 要素取得
	Iterator<T> itr = m_List.GetBegin();
	if (out) *out = *itr;
	// 要素削除
	return m_List.Erase(itr);
}
