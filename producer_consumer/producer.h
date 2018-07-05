#ifndef _INC_PRODUCER_H_
#define _INC_PRODUCER_H_


#include <atomic>
#include "threadpool.h"
using namespace std;

class producer :
	public threadpool
{
public:
	producer();
	~producer();
	void* Run();
	int GetReqSequence();
protected:
	atomic<int> m_nSeq;
};

#endif // !_INC_PRODUCER_H_