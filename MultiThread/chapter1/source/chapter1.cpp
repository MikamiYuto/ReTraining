//!	@file		chapter1.cpp
//!	@brief		�}���`�X���b�h�ۑ�@��1��
//! @note		Copyright (c) FromSoftware, Inc.

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <functions.h>
#include <crtdbg.h>
#include <thread>
#include <vector>
#include <mutex>

//-----------------------------------------------------------------------------
// Macro Definitions
//-----------------------------------------------------------------------------

#define N		100000
#define	MIN		1
#define	MAX		13
#define RESULT	833197		// ���̌v�Z�͂��̒l�ɂȂ�܂�

//#define SINGLE
#define MULTI

//-----------------------------------------------------------------------------
// Using Namespace
//-----------------------------------------------------------------------------
using namespace ex02_MultiThread::common;

//-----------------------------------------------------------------------------
// Implements
//-----------------------------------------------------------------------------
namespace ex02_MultiThread
{
	namespace chapter1
	{
		/**************************************************************************//**
			@brief		��Ƃ��s���܂��B
			@return		��Ƃ̌���
			@todo		���̊֐����������A�������ʂ���荂���ɕԂ���悤�ɂ��Ă��������B
		*//***************************************************************************/
		int DoWork()
		{
			// 1.�������ꂽ�p�����^�𒙂߂�R���e�i��p��
			struct Param
			{
				int x, y, z;
			};
			std::vector<Param> params(N);
			int sum = 0;

			// 2.Tarai�v�Z�̃p�����^��������
			for( int i = 0; i < N; ++i )
			{
				params[i].x = Random( MIN, MAX );
				params[i].y = Random( MIN, MAX );
				params[i].z = Random( MIN, MAX );
			}

			// 3.Tarai�v�Z�̎��s����
#if defined SINGLE
			for (int i = 0; i < N; ++i)
				sum += Tarai(params[i].x, params[i].y, params[i].z);
#elif defined MULTI
			// �e�X�g���R�[�h�Asum�����������Ȃ�
			std::mutex mtx = {};
			auto addFp = [&sum,&mtx](int add) { mtx.lock(); sum += add; mtx.unlock(); };
			std::unique_ptr<std::thread> ths[10];
			for (int i = 0; i < 10; ++i)
				ths[i].reset(new std::thread([&params, &i, &addFp] { for (int j = i * 10000; j < N; ++j) addFp(Tarai(params[j].x, params[j].y, params[j].z)); }));
			for (auto& th : ths)
				th->join();
			//std::thread th([&params, &addFp] { for (int i = 0; i < N; ++i) addFp(Tarai(params[i].x, params[i].y, params[i].z)); });
			//th.join();
#endif

			return sum;
		}
	}
}
/**************************************************************************//**
	@brief		�v���O�����J�n�֐��ł��B
*//***************************************************************************/
void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	unsigned __int64 startTime = GetCPUCounter();
	int result = ex02_MultiThread::chapter1::DoWork();
	unsigned __int64 endTime = GetCPUCounter();

	printf( "time : %f\n", (double)(endTime - startTime) / (double)GetCPUFrequency() );
	printf( "result : %d\n", result );
}