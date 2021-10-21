//!	@file		chapter1.cpp
//!	@brief		マルチスレッド課題　第1章
//! @note		Copyright (c) FromSoftware, Inc.

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <functions.h>
#include <crtdbg.h>
#include <queue>
#include <list>
#include <thread>
#include <mutex>

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
			//----- 必要な変数、関数定義
			struct Param { int x, y, z; };	// パラメタ構造定義
			std::queue<Param> paramQueue;	// 生成したパラメタを蓄えるコンテナ
			std::mutex paramMtx;			// パラメタコンテナの排他制御用
			std::mutex sumMtx;				// 合計を保持する変数の排他制御用
			bool isSpawnFinish = false;		// パラメタの生成完了フラグ
			// パラメタ生成関数
			auto spawnParamFunc = [&paramQueue, &paramMtx]
			{
				std::lock_guard<std::mutex> lock(paramMtx);
				paramQueue.push(Param{ Random(MIN, MAX), Random(MIN, MAX), Random(MIN, MAX) });
			};
			// パラメタ取得関数
			auto getParamFunc = [&paramQueue, &paramMtx](std::list<Param>& out)
			{
				std::lock_guard<std::mutex> lock(paramMtx);
				if (paramQueue.empty())
					return false;
				// パラメタを1つ取得
				for (int i = 0; i < 1 && !paramQueue.empty(); ++i)
				{
					Param param = paramQueue.front();
					paramQueue.pop();
					out.push_back(param);
				}
				return true;
			};
			// 合算関数
			auto addFunc = [&sum, &sumMtx](int add)
			{
				std::lock_guard<std::mutex> lock(sumMtx);
				sum += add;
			};

			//----- 並列処理実行
			// パラメタの生成処理を行うスレッド生成
			std::thread spawnThread([&spawnParamFunc]
			{ 
				for (int i = 0; i < N; ++i) 
					spawnParamFunc(); 
			});
			
			// Tarai計算処理用のスレッド生成
			std::vector<std::thread> taraiThreads;
			const int maxThread = std::thread::hardware_concurrency();
			taraiThreads.reserve(maxThread);
			for (int i = 0; i < maxThread; ++i)
			{
				taraiThreads.emplace_back(std::thread([&getParamFunc, &addFunc, &isSpawnFinish]
				{
					std::list<Param> paramList;
					// 全てのパラメタを処理し終えるまで続行
					while (!isSpawnFinish || getParamFunc(paramList))
					{
						for(auto& param : paramList)
							addFunc(Tarai(param.x, param.y, param.z));
						paramList.clear();
					}
				}));
			}

			//----- 処理待ち
			spawnThread.join();
			isSpawnFinish = true;
			for (auto& th : taraiThreads)
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