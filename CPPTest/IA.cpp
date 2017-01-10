#include "IA.h"

int test1 = 100;
static int test2 = 99;


IA::IA() {
	static int test3 = 88;
	std::cout << "IA constructor " << test3 << std::endl;
}

IA::IA(int a, char* b) :
	m_data(a)
	, m_str(b)
{
	std::cout << "constructor" << std::endl;
	std::cout << "m_data = " << m_data << std::endl;
	std::cout << "m_str = " << m_str << std::endl;
}

IA::~IA()
{
	std::cout << "deconstructor" << std::endl;
}

IA::IA(IA &a)
{
	std::cout << "copy constructor" << std::endl;
	m_data = a.m_data;
	m_str = a.m_str;
	std::cout << "m_data = " << m_data << std::endl;
	std::cout << "m_str = " << m_str << std::endl;
}

IA* IA::operator =(IA &a)
{
	m_data = a.m_data;
	m_str = a.m_str;
	return this;
}


void IA::show()
{
	std::cout << "IA show " << std::endl;
}
