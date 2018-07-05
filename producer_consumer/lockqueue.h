#ifndef _INC_LOCKQUEUE_H_
#define _INC_LOCKQUEUE_H_



#include <queue>
using namespace std;
#include <pthread.h>


template<typename T>
class lockqueue
{
public:
	lockqueue() {}
	~lockqueue() {}
private:
	pthread_mutex_t	m_lock;
	queue<T>		m_queue;
public:
	bool push(T req)
	{
		if (pthread_mutex_lock(&m_lock) == 0)
		{
			m_queue.push(req);
			pthread_mutex_unlock(&m_lock);
			return true;
		}
		return false;
	}
	T pop()
	{
		T req = NULL;
		if (pthread_mutex_lock(&m_lock) == 0)
		{
			if (m_queue.size() > 0)
			{
				req = m_queue.front();
				m_queue.pop();
			}
			pthread_mutex_unlock(&m_lock);
		}
		return req;
	}
};

#endif // !_INC_LOCKQUEUE_H_