#include "Test.h"

Test::Test(int param = 0) {
	number = param;
	std::cout << "Test: " << number << std::endl;
}

Test::Test(const Test &t) {
	std::cout << "copy ctor " << number << std::endl;
	number = t.number;
	info_extend = t.info_extend;
}

Test::~Test() {
	std::cout << "~Test: " << number << std::endl;
}

void Test::myPrint()
{
	std::cout << "hello" << std::endl;
	int *p = new int[10];
}

void Test::PrintSomething()
{
	std::cout << "PrintSomething: " << this->info_extend.c_str() << std::endl;
}

int Test::getMySelfPtr()
{
	return 1;
}