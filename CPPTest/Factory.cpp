#include "Factory.h"

ConcreteFactory *ConcreteFactory::_instance = nullptr;

ConcreteFactory::ConcreteFactory()
{
}

ConcreteFactory* ConcreteFactory::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new ConcreteFactory();
	}
	return _instance;
}

int ConcreteFactory::factoryMethod()
{
	printf("ConcreteFactory method");
	return 0;
}


void ConcreteFactory::show()
{
	printf("ConcreteFactory\n");
}

