//!	@file		chapter1.cpp
//!	@brief		マルチスレッド課題　第1章
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
#define RESULT	833197		// この計算はこの値になります
std::mutex mtx;

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
			@brief		作業を行います。
			@return		作業の結果
			@todo		この関数を改造し、同じ結果をより高速に返せるようにしてください。
		*//***************************************************************************/
		int DoWork()
		{
			struct Param { int x, y, z; };
			int sum = 0;
			std::vector<Param> params;
			std::vector<std::thread> ths;
			params.reserve(N);
			ths.reserve(std::thread::hardware_concurrency());
			auto spawnParamFunc = [&params]
			{
				std::lock_guard<std::mutex> lock(mtx);
				Param param{ Random(MIN, MAX), Random(MIN, MAX), Random(MIN, MAX) };
				params.emplace_back(param);
				return param;
			};
			auto addFunc = [&sum](int add)
			{
				std::lock_guard<std::mutex> lock(mtx);
				sum += add;
			};

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
			for (auto& th : ths)
				th.join();

			return sum;
		}
	}
}
/**************************************************************************//**
	@brief		プログラム開始関数です。
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