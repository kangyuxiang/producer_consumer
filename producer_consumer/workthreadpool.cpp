#include <pthread.h>
#include <sys/timeb.h>
#include "workthreadpool.h"


template<typename RT>
workthreadpool<RT>::workthreadpool()
{
	pthread_mutex_init(&m_lock, NULL);
	pthread_mutex_init(&m_ctlock, NULL);
	pthread_cond_init(&m_ct, NULL);
}

template<typename RT>
workthreadpool<RT>::~workthreadpool()
{
}


template<typename RT>
void* workthreadpool<RT>::Run()
{
	while(m_bRunning)
	{
		RT req = m_mq.pop();
		if (req != NULL)
		{
			HandleRequest(req);
		}
		else
		{
			if (pthread_mutex_lock(&m_ctlock) != 0)
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
template<typename RT>
void workthreadpool<RT>::HandleRequest(RT req)
{

}

template<typename RT>
bool workthreadpool<RT>::InsertData(RT req)
{
	if (m_mq.push(req) && pthread_mutex_lock(&m_ctlock) == 0)
	{
		pthread_cond_signal(&m_ct);
		pthread_mutex_unlock(&m_ctlock);
		return true;
	}
	return false;
}
