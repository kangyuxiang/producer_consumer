#ifndef _INC_THREADPOOL_H_
#define _INC_THREADPOOL_H_


#include <vector>
using namespace std;
#include <pthread.h>


class threadpool
{
public:
	threadpool();
	virtual ~threadpool();
	virtual int start(int nThread);
	virtual int stop();
	static void* ThreadFunc(void* args);
	virtual void* Run() = 0;
protected:
	vector<pthread_t> m_vecThreadID;
	bool m_bRunning;
};

#endif // !_INC_THREADPOOL_H_