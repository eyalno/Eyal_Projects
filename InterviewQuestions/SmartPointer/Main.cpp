#include "Person.h"
#include "SmartPointer.h"

void main()
{
	
	SP<Person> p(new Person("Scott", 25));
	p->Display();
	{
		SP<Person> q = p;
		q->Display();
		// Destructor of q will be called here..

		SP<Person> r;
		r = p;
		r->Display();
		// Destructor of r will be called here..
	}
	p->Display();
	// Destructor of p will be called here 
	// and Person pointer will be deleted
}