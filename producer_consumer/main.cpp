#include <iostream>
#include "threadpool.h"
#include "model.h"
#include "unistd.h"

int main()
{
	model::start(2, 1);
	getchar();
	cout << "program will stop!" << endl;
	model::stop();
	return 0;
}