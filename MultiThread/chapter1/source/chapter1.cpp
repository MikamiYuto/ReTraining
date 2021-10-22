//!	@file		chapter1.cpp
//!	@brief		�}���`�X���b�h�ۑ�@��1��
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

#define N		1000000
#define	MIN		1
#define	MAX		9
#define RESULT	5651388		// ���̌v�Z�͂��̒l�ɂȂ�܂�

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
			//----- �K�v�ȕϐ��A�֐���`
			struct Param { int x, y, z; };	// �p�����^�\����`
			std::queue<Param> paramQueue;	// ���������p�����^��~����R���e�i
			std::mutex paramMtx;			// �p�����^�R���e�i�̔r������p
			std::mutex sumMtx;				// ���v��ێ�����ϐ��̔r������p
			bool isSpawnFinish = false;		// �p�����^�̐��������t���O
			// �p�����^�����֐�
			auto spawnParamFunc = [&paramQueue, &paramMtx]
			{
				std::lock_guard<std::mutex> lock(paramMtx);
				paramQueue.push(Param{ Random(MIN, MAX), Random(MIN, MAX), Random(MIN, MAX) });
			};
			// �p�����^�擾�֐�
			auto getParamFunc = [&paramQueue, &paramMtx](std::list<Param>& out)
			{
				std::lock_guard<std::mutex> lock(paramMtx);
				if (paramQueue.empty())
					return false;
				// �p�����^��1�擾
				for (int i = 0; i < 10 && !paramQueue.empty(); ++i)
				{
					Param param = paramQueue.front();
					paramQueue.pop();
					out.push_back(param);
				}
				return true;
			};
			// ���Z�֐�
			auto addFunc = [&sum, &sumMtx](int add)
			{
				std::lock_guard<std::mutex> lock(sumMtx);
				sum += add;
			};

			//----- ���񏈗����s
			// �p�����^�̐����������s���X���b�h����
			std::thread spawnThread([&spawnParamFunc]
			{ 
				for (int i = 0; i < N; ++i) 
					spawnParamFunc(); 
			});
			
			// Tarai�v�Z�����p�̃X���b�h����
			std::vector<std::thread> taraiThreads;
			const int maxThread = std::thread::hardware_concurrency();
			taraiThreads.reserve(maxThread);
			for (int i = 0; i < maxThread; ++i)
			{
				taraiThreads.emplace_back(std::thread([&getParamFunc, &addFunc, &isSpawnFinish]
				{
					std::list<Param> paramList;
					// �S�Ẵp�����^���������I����܂ő��s
					while (!isSpawnFinish || getParamFunc(paramList))
					{
						int tempSum = 0;
						for(auto& param : paramList)
							tempSum += Tarai(param.x, param.y, param.z);
						addFunc(tempSum);
						paramList.clear();
					}
				}));
			}

			//----- �����҂�
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