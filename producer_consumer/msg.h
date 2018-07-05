#ifndef _INC_MSG_H_
#define _INC_MSG_H_


#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

class msg
{
public:
	msg();
	msg(int nReqNo, int nAge, int nSex, const char* szName);
	~msg();
public:
	int m_nReqNo;
	int m_nAge;
	int m_nSex;
	char m_szName[32];
};

#endif // !_INC_MSG_H_