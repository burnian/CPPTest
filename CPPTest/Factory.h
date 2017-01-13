#pragma once
#include <iostream>

class Factory
{
public:
	~Factory() { printf("deconstruct Factory\n"); };

	virtual int factoryMethod()=0;

	virtual void show() { printf("Factory\n"); };
};

class Factory1 : public Factory
{
public:
	~Factory1() { printf("deconstruct Factory1\n"); };

	int factoryMethod() { return 0; };

	void show() { printf("Factory1\n"); };
};


class ConcreteFactory : public Factory1
{
public:
	~ConcreteFactory() { printf("deconstruct ConcreteFactory\n"); };

	static ConcreteFactory* getInstance();

	int factoryMethod();

	void show();

private:
	ConcreteFactory();

	static ConcreteFactory *_instance;

public:
};

