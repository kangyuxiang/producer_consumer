#include <iostream>
using namespace std;
#include "threadpool.h"



threadpool::threadpool()
{
	m_bRunning = false;
}


threadpool::~threadpool()
{
}


int threadpool::start(int nThread)
{
	m_bRunning = true;
	for (int i = 0; i < nThread; i++)
	{
		pthread_t tID;
		if (pthread_create(&tID, NULL, threadpool::ThreadFunc, this) == 0)
		{
			m_vecThreadID.push_back(tID);
		}
	}
	return m_vecThreadID.size();
}


int threadpool::stop()
{
	m_bRunning = false;
	int nJoin = 0;
	for (int i = m_vecThreadID.size() - 1; i >= 0; i--)
	{
		if (pthread_join(m_vecThreadID[i], NULL) == 0)
			nJoin++;
	}
	return nJoin;
}

void* threadpool::ThreadFunc(void* args)
{
	cout << "create thread: " << pthread_self() << endl;
	threadpool* pool = (threadpool*)args;
	return pool->Run();
}
