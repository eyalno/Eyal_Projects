#include <iostream>
using namespace std;

#include "car_t.h"
#include "ford_t.h"
#include "subaru_t.h"

int main()
{
	int choose,	capacity, flag, brother;

	//test 1 - default CTOR
	ford_t my_ford, last_ford;
	subaru_t my_subaru, last_subaru;
	cout << "enter your choice for your car:" << endl;
	cout << "1. ford" << endl;
	cout << "2. subaru" << endl;
	cin >> choose;
	cout << "what capacity do you want?" << endl;
	cout << "1.1500cc" << endl;
	cout << "2.1800cc" << endl;
	cin >> capacity;
	cout << "what speed are you driving?" << endl;
	cout << "1. 0-20 km/h" << endl;
	cout << "2. 20-50 km/h" << endl;
	cout << "3. 50-100 km/h" << endl;
	cin >> flag;
	if (choose==1)
	{
		my_ford.setCapacity((cap) capacity);
		my_ford.setSpeed((speed) flag);
	}
	else if (choose==2)
	{
		my_subaru.setCapacity((cap) capacity);
		my_subaru.setSpeed((speed) flag);
	}
	else
	{
		cout << "wrong input" << endl;
		return 0;           // terminate the program
	}
	cout << "this is your car:";
	if (choose==1)
	{
		my_ford.print();
	}
	else if (choose==2)
	{
		my_subaru.print();
	}

	//test 2 - copy CTOR, CTOR with capacity, assignment
	cout << "now we look for a car for your brother. enter your choice:" << endl;
	cout << "1. same car like yours" << endl;
	cout << "2. ford 1500cc" << endl;
	cout << "3. ford 1800cc" << endl;
	cout << "4. subaru 1500cc" << endl;
	cout << "5. subaru 1800cc" << endl;
	cin >> brother;
	if (brother==1 && choose==1)
	{
		ford_t his_ford=my_ford;
		his_ford.print();
		last_ford=his_ford;
		last_ford.print();
	}
	else if (brother==1 && choose==2)
	{
		subaru_t his_subaru=my_subaru;
		his_subaru.print();
		last_subaru=his_subaru;
		last_subaru.print();
	}
	else if (brother==2)
	{
		ford_t his_ford(CC_1500);
		his_ford.setSpeed((speed) flag);
		last_ford=his_ford;
		last_ford.print();
	}
	else if (brother==3)
	{
		ford_t his_ford(CC_1800);
		his_ford.setSpeed((speed) flag);
		his_ford.print();
		last_ford=his_ford;
		last_ford.print();
	}
	else if (brother==4)
	{
		subaru_t his_subaru(CC_1500);
		his_subaru.setSpeed((speed) flag);
		his_subaru.print();
		last_subaru=his_subaru;
		last_subaru.print();
	}
	else if (brother==5)
	{
		subaru_t his_subaru(CC_1800);
		his_subaru.setSpeed((speed) flag);
		his_subaru.print();
		last_subaru=his_subaru;
		last_subaru.print();
	}
	
	//test 3 - comparing our cars
	cout << "answer to the questions: do I have smaller capacity?" << endl << "do we have the same car?" << endl;
	if (choose==1 && (brother==1 || brother==2 || brother==3))   //both have ford
	{
		cout << (my_ford<last_ford) << endl << my_ford.compare_name(last_ford) << endl;
	}
	else if (choose==2 && (brother==2 || brother==3))   // i have subaru, brother has ford
	{
		cout << (my_subaru<last_ford) << endl << my_subaru.compare_name(last_ford) << endl;
	}
	else if (choose==1 && (brother==4 || brother==5))   // i have ford, brother have subaru
	{
		cout << (my_ford<last_subaru) << endl << my_ford.compare_name(last_subaru) << endl;
	}
	else if (choose==2 && (brother==1 || brother==4 || brother==5))   // i have subaru, brother have subaru
	{
		cout << (my_subaru<last_subaru) << endl << my_subaru.compare_name(last_subaru) << endl;
	}

	//test 4 - using get functions
	if (choose==1)
	{
		cout << "your car is " << my_ford.getName() << endl;
		cout << "with capacity: " << my_ford.getCapacity() << endl;
		cout << "with gear: " << my_ford.getGear() << endl;
		cout << "and speed flag is: " << my_ford.getSpeed() << endl;
		cout << "and it's ID is: " << my_ford.getID() << endl;
	}
	else            //choose==2
	{
		cout << "your car is " << my_subaru.getName() << endl;
		cout << "with capacity: " << my_subaru.getCapacity() << endl;
		cout << "with gear: " << my_ford.getGear() << endl;
		cout << "and speed flag is: " << my_subaru.getSpeed() << endl;
		cout << "and it's ID is: " << my_subaru.getID() << endl;
	}
	return 0;
}