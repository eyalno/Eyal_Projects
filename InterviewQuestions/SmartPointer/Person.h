#include <stdio.h>

class Person
{
	int age;
	char* pName;

public:
	Person() : pName(0), age(0)
	{
	}
	Person(char* pName, int age) : pName(pName), age(age)
	{
	}
	~Person()
	{
	}

	void Display()
	{
		printf("Name = %s Age = %d \n", pName, age);
	}
	void Shout()
	{
		printf("Ooooooooooooooooo");
	}
};