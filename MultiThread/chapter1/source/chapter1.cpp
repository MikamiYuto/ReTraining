//!	@file		chapter1.cpp
//!	@brief		マルチスレッド課題　第1章
//! @note		Copyright (c) FromSoftware, Inc.

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <functions.h>
#include <crtdbg.h>
#include <thread>
#include <vector>

//-----------------------------------------------------------------------------
// Macro Definitions
//-----------------------------------------------------------------------------

#define N		100000
#define	MIN		1
#define	MAX		13
#define RESULT	833197		// この計算はこの値になります

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
			@brief		作業を行います。
			@return		作業の結果
			@todo		この関数を改造し、同じ結果をより高速に返せるようにしてください。
		*//***************************************************************************/
		int DoWork()
		{
			// 1.生成されたパラメタを貯めるコンテナを用意
			struct Param
			{
				int x, y, z;
			};
			std::vector<Param> params(N);
			int sum = 0;

			// 2.Tarai計算のパラメタ生成処理
			for( int i = 0; i < N; ++i )
			{
				params[i].x = Random( MIN, MAX );
				params[i].y = Random( MIN, MAX );
				params[i].z = Random( MIN, MAX );
			}

			// 3.Tarai計算の実行処理
#if defined SINGLE
			for (int i = 0; i < N; ++i)
				sum += Tarai(params[i].x, params[i].y, params[i].z);
#elif defined MULTI
			// テスト中コード、sumがおかしくなる
			//std::unique_ptr<std::thread> ths[10];
			//for (int i = 0; i < 10; ++i)
			//	ths[i].reset(new std::thread([&sum, &params, &i] { for (int j = i * 10000; j < N; ++j) sum += Tarai(params[j].x, params[j].y, params[j].z); }));
			//for (auto& th : ths)
			//	th->join();
			std::thread th([&sum, &params] { for (int i = 0; i < N; ++i) sum += Tarai(params[i].x, params[i].y, params[i].z); });
			th.join();
#endif

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