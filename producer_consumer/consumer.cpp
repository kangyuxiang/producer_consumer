#include "msg.h"
#include "workthreadpool.h"
#include "consumer.h"



consumer::consumer() : workthreadpool<msg*>()
{
}


consumer::~consumer()
{
}


void consumer::HandleRequest(msg* req)
{
	if (req)
	{
		char szBuf[128] = { 0 };
		snprintf(szBuf, 128, "no: %d, name: %s, age: %d, sex: %d", req->m_nReqNo, req->m_szName, req->m_nAge, req->m_nSex);
		cout << szBuf << endl;
		delete req;
	}
	return;
}
