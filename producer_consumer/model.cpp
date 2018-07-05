#include "model.h"
#include "producer.h"
#include "consumer.h"

producer prod;
consumer cons;

namespace model
{
	bool SendRequest(msg* req)
	{
		return cons.InsertData(req);
	}

	int start(int nProducer, int nConsumer)
	{
		int nCons = cons.start(nConsumer);
		cout << "start consumer num: " << nCons << endl;
		int nProd = prod.start(nProducer);
		cout << "start producer num: " << nProd << endl;
	}

	void stop()
	{
		int nStop = prod.stop();
		cout << "stop producer num: " << nStop << endl;
		nStop = cons.stop();
		cout << "stop consumer num: " << nStop << endl;
	}
}
