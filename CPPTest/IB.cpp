#include "IB.h"

extern int test1;
int IB::m_nTest = 33;

IB::IB()
{
}


IB::~IB()
{
}

void IB::_show()
{
	std::cout << test1 << std::endl;
}

void IB::show()
{
	std::cout << m_nTest << std::endl;
}