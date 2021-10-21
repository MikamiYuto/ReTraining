//!	@file		chapter1.cpp
//!	@brief		�}���`�X���b�h�ۑ�@��1��
//! @note		Copyright (c) FromSoftware, Inc.

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <functions.h>
#include <crtdbg.h>
#include <vector>
#include <thread>
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
			int sum = 0;

#if defined SINGLE
			for (int i = 0; i < N; ++i)
			{
				int x = Random(MIN, MAX);
				int y = Random(MIN, MAX);
				int z = Random(MIN, MAX);
				sum += Tarai(x, y, z);
			}
#elif defined MULTI
			// �p�����^��`
			struct Param { int x, y, z; };
			// �p�����^��~����R���e�i�ƃX���b�h��p��
			std::vector<Param> params;
			std::vector<std::thread> ths;
			params.reserve(N);
			ths.reserve(std::thread::hardware_concurrency());
			// �r������p
			std::mutex paramMtx;
			std::mutex sumMtx;
			// �p�����^�����֐�
			auto spawnParamFunc = [&params, &paramMtx]
			{
				std::lock_guard<std::mutex> lock(paramMtx);
				Param param{ Random(MIN, MAX), Random(MIN, MAX), Random(MIN, MAX) };
				params.emplace_back(param);
				return param;
			};
			// ���Z�֐�
			auto addFunc = [&sum, &sumMtx](int add)
			{
				std::lock_guard<std::mutex> lock(sumMtx);
				sum += add;
			};
			// ����p�ɃX���b�h����(hardware_concurrency()�œ�����l�ȏ�̃X���b�h�͐������Ă����ʂȂ�����
			for (int i = 0; i < 10; ++i)
			{
				ths.emplace_back(std::thread([&spawnParamFunc, &addFunc, &params]
				{
					for (int i = 0; i < 10000; ++i)
					{
						Param param = spawnParamFunc();
						addFunc(Tarai(param.x, param.y, param.z));
					}
				}));
			}
			// �����҂�
			for (auto& th : ths)
				th.join();
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