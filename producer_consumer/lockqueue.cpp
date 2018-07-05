#include <queue>
#include "lockqueue.h"


template<typename T>
lockqueue<T>::lockqueue()
{
}

template<typename T>
lockqueue<T>::~lockqueue()
{
	//m_queue.erase();
}


template<typename T>
bool lockqueue<T>::push(T req)
{
	if (pthread_mutex_lock(&m_lock) == 0)
	{
		m_queue.push(req);
		pthread_mutex_unlock(&m_lock);
		return true;
	}
	return false;
}

template<typename T>
T lockqueue<T>::pop()
{
	if (pthread_mutex_lock(&m_lock) == 0 && m_queue.size() > 0)
	{
		T req = m_queue.front();
		pthread_mutex_unlock(&m_lock);
		return req;
	}
	return T();
}
