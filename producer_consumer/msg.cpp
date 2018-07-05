#include "msg.h"



msg::msg()
{
	memset(this, 0, sizeof(msg));
}

msg::msg(int nReqNo, int nAge, int nSex, const char* szName)
	:m_nReqNo(nReqNo), m_nAge(nAge), m_nSex(nSex)
{
	memset(m_szName, 0, sizeof(m_szName));
	memcpy(m_szName, szName, min(strlen(szName), sizeof(m_szName)));
}

msg::~msg()
{
}
