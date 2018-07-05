#ifndef _INC_MODEL_H_
#define _INC_MODEL_H_


class msg;
namespace model
{
	bool SendRequest(msg* req);
	int start(int nProducer, int nConsumer);
	void stop();
};

#endif // !_INC_MODEL_H_