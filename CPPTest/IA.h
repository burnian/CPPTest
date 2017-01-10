#pragma once
#include <iostream>

class IA
{
public:
	IA();
	IA(int a, char* b);
	~IA();
	IA(IA &a);

	IA* operator =(IA &a);

	void show();

private:
	int m_data = 0;
	char* m_str = "hello world";
};
