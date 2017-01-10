#include <iostream>
#include <windows.h>


class Base
{
public:
	Base(int a, int b){
		m_pro[0] = a;
		m_pro[1] = b;
		printf("cons %d %d\n", m_pro[0], m_pro[1]);
	};
	~Base() {
		printf("decs %d %d\n", m_pro[0], m_pro[1]);
	};

	void show()
	{
		printf("show %d %d\n", m_pro[0], m_pro[1]);
	}
public:
	int m_pro[2];
};



struct MyStruct
{
	int a;
	int b;
	~MyStruct()
	{
		printf("%d no\n", a);
	}
};

MyStruct* f(MyStruct* p)
{
	MyStruct a;
	a.a = 99;
	a.b = 88;

	*p = a;
	return &a;
}


void main()
{	
	//typedef std::chrono::duration<int> seconds_type;
	//typedef std::chrono::duration<int, std::milli> milliseconds_type;
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


	

	Base a(1,2);
	Base *b = new Base(3,4);

	a = *b;
	delete(b);
	a.show();




	printf("\n");
	system("pause");
}



//bool isSpecNumber(int n, int m)
//{
//	return n%10 == m || (n && isSpecNumber(n/10, m));
//}











