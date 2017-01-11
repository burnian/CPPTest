#include <iostream>
#include <chrono>
#include "IAStar.h"


//class A
//{
//public:
//	A() { printf("A construct\n"); }
//	~A() { printf("A deconstruct\n"); }
//};
//
//class B
//{
//public:
//	B() { printf("B construct\n"); }
//	~B() { printf("B deconstruct\n"); }
//};
//
//class Base
//{
//public:
//	Base() {
//		printf("Base construct\n");
//	};
//	~Base() {
//		printf("Base deconstruct\n");
//	};
//
//public:
//	B m_p;
//	A m_pro;
//};

//Base a(1, 2);
//Base *b = new Base(3, 4);
//
//a = *b;
//delete(b);
//a.show();


//typedef std::chrono::duration<int> seconds_type;
typedef std::chrono::duration<double, std::milli> milliseconds_type;
//typedef std::chrono::duration<int, std::ratio<60 * 60>> hours_type;

//hours_type hOneDay(1);
//seconds_type sOneDay(1);
//milliseconds_type msOneDay(1);
//std::cout << hOneDay.count() << std::endl;
//std::cout<< sOneDay.count() << std::endl;
//std::cout<< msOneDay.count() << std::endl;

//seconds_type sOneHour(60 * 60);
//hours_type hOneHour(std::chrono::duration_cast<hours_type>(sOneHour));
//milliseconds_type msOneHour(sOneHour);


void main()
{	
	IAStar aStar;
	std::vector<Vec2> blocks;
	blocks.push_back(Vec2(3, 0));
	blocks.push_back(Vec2(3, 2));
	blocks.push_back(Vec2(3, 3));
	blocks.push_back(Vec2(3, 4));
	blocks.push_back(Vec2(3, 1));
	blocks.push_back(Vec2(3, 5));
	//blocks.push_back(Vec2(3, 6));
	aStar.init(7, 7, blocks);

	
	std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

	std::vector<Vec2>* path = aStar.findPath(Vec2(1, 3), Vec2(5, 3));

	std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
	milliseconds_type time_span = t2 - t1;
	std::cout << "It took me " << time_span.count() << " seconds.\n\n";

	for (std::vector<Vec2>::reverse_iterator it = path->rbegin(); it != path->rend(); ++it)
	{
		printf("(%d,%d)\n", it->x, it->y);
	}
	delete(path);

	printf("\n");
	system("pause");
}














