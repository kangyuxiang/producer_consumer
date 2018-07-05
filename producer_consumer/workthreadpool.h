#ifndef _INC_WORKTHREADPOOL_H_
#define _INC_WORKTHREADPOOL_H_

#include <sys/timeb.h>
#include "threadpool.h"
#include "lockqueue.h"

template<typename RT>
class workthreadpool :
	public threadpool
{
public:
	workthreadpool()
	{
		pthread_mutex_init(&m_lock, NULL);
		pthread_mutex_init(&m_ctlock, NULL);
		pthread_cond_init(&m_ct, NULL);
	}
	~workthreadpool()
	{}
	virtual void* Run()
	{
		while (m_bRunning)
		{
			RT req = m_mq.pop();
			if (req != NULL)
			{
				HandleRequest(req);
			}
			else
			{
				if (pthread_mutex_lock(&m_ctlock) == 0)
				{
					timeb tp;
					timespec timeout;
					ftime(&tp);
					timeout.tv_sec = tp.time + 1;
					timeout.tv_nsec = tp.millitm * 1000000;
					int nRet = pthread_cond_timedwait(&m_ct, &m_ctlock, &timeout);
					//if (nRet == ETIMEOUT)
					//{
					//}
					pthread_mutex_unlock(&m_ctlock);
				}
			}
		}
		return nullptr;
	}
protected:
	pthread_mutex_t	m_lock;
	pthread_cond_t	m_ct;
	pthread_mutex_t	m_ctlock;
	lockqueue<RT>	m_mq;
public:
	virtual void HandleRequest(RT req) = 0;
	virtual bool InsertData(RT req)
	{
		if (m_mq.push(req) && pthread_mutex_lock(&m_ctlock) == 0)
		{
			pthread_cond_signal(&m_ct);
			pthread_mutex_unlock(&m_ctlock);
			return true;
		}
		return false;
	}
};

#endif // !_INC_WORKTHREADPOOL_H_