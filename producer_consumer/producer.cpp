#include "producer.h"
#include "msg.h"
#include "model.h"
#include <unistd.h>

producer::producer()
{
	m_nSeq = 0;
}


producer::~producer()
{
}

void* producer::Run()
{
	int nSend = 5;
	while (m_bRunning && nSend > 0)
	{
		msg* req = new msg(GetReqSequence(), 18, 0, "robot");
		model::SendRequest(req);
		nSend--;
	}
}


int producer::GetReqSequence()
{
	return ++m_nSeq;
}
