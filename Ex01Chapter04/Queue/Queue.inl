/**
 * @file Queue.inl
 * @breif テンプレートスタッククラスの実装ファイル
 * @author MikamiYuto
 * @date 2021.10.13
 */
#pragma once


//----- インクルード
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
	// 取り出すものが無ければ何もしない
	if (m_List.GetCount() == 0) return false;
	// 要素取得
	Iterator<T> itr = m_List.GetBegin();
	if (out) *out = *itr;
	// 要素削除
	return m_List.Erase(itr);
}
