#pragma once
#include <iostream>
#include <string>


class Test
{
public:
	Test(int param);
	Test(const Test &t);
	~Test();

	void PrintSomething();
	void myPrint();

	static int getMySelfPtr();

public:
	static Test* selfPtr;
	std::string info_extend;
	int number;
};

