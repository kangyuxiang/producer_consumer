#ifndef _INC_CONSUMER_H_
#define _INC_CONSUMER_H_


#include "workthreadpool.h"
#include "msg.h"

class consumer : public workthreadpool<msg*>
{
public:
	consumer();
	~consumer();
	virtual void HandleRequest(msg* req);
};

#endif // !_INC_CONSUMER_H_