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
			// �p�����^��`
			struct Param { int x, y, z; };
			int sum = 0;
			// �p�����^��~����R���e�i�ƃX���b�h��p��
			std::vector<Param> params;
			std::vector<std::thread> ths;
			params.reserve(N);
			ths.reserve(std::thread::hardware_concurrency());
			// �r������p
			std::mutex mtx;
			// �p�����^�����֐�
			auto spawnParamFunc = [&params, &mtx]
			{
				std::lock_guard<std::mutex> lock(mtx);
				Param param{ Random(MIN, MAX), Random(MIN, MAX), Random(MIN, MAX) };
				params.emplace_back(param);
				return param;
			};
			// ���Z�֐�
			auto addFunc = [&sum, &mtx](int add)
			{
				std::lock_guard<std::mutex> lock(mtx);
				sum += add;
			};
			// ����p�ɃX���b�h����
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