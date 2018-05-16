#include <iostream>
using namespace std;

#include "animal_t.h"
#include "chicken_t.h"
#include "duck_t.h"
#include "cow_t.h"

animal_t *createAn(int i)
{
	animal_t *p;
	if (i==1)
	{
		p=new duck_t;
	}
	else if (i==2)
	{
		p=new cow_t;
	}
	else
	{
		p=new chicken_t;
	}
	return p;
}

int main()
{
	int choose;
	duck_t my_duck;
	cow_t my_cow;
	chicken_t my_chicken;
	do {
		cout << "what do you want?" << endl;
		cout << "1. duck" << endl << "2. 100 cows" << endl << "3. 10 chickens" << endl << "0. exit" << endl;
		cin >> choose;
		if (choose==1)
		{
			duck_t my_duck;
			my_duck.show();
			duck_t his_duck=my_duck;
			cout << "do my duck  to his duck? " << (my_duck==his_duck);
			cout << " does it bigger than his duck? " << (my_duck>his_duck);
			cout << " and opposite? " << (his_duck>my_duck) << endl;
			his_duck.show();
			his_duck.makeSound();
		}
		else if (choose==2)
		{
			cow_t my_cow[100];
			my_cow[15].show();
			cow_t his_cow=my_cow[17];
			his_cow.show();
			his_cow.makeSound();
			my_cow[9]=my_cow[38];
			my_cow[9].show();
			cout << "do cow 15 equals to cow 23?\t" << (my_cow[15]==my_cow[23]);
			cout << " does it bigger than cow 23?\t " << (my_cow[15]>my_cow[23]);
			cout << " and opposite?\t" << (my_cow[23]>my_cow[15]) << endl;
		}
		else if (choose==3)
		{
			chicken_t my_chicken[10];
			my_chicken[4].show();
			chicken_t his_chicken=my_chicken[6];
			his_chicken.show();
			his_chicken.makeSound();
		}
	} while(choose!=0);

	cout << "now lets compare" << endl;
	cout << "do duck equals to cow?    \t" << (my_duck==my_cow) << " does it bigger than cow?\t " << (my_duck>my_cow) << endl;
	cout << "do duck equals to chicken?\t" << (my_duck==my_chicken) << " does it bigger than chicken?\t " << (my_duck>my_chicken) << endl;
	cout << "do chicken equals to cow? \t" << (my_chicken==my_cow) << " does it bigger than cow?\t " << (my_chicken>my_cow) << endl;
	cout << "do chicken equals to duck?\t" << (my_chicken==my_duck) << " does it bigger than duck?\t " << (my_chicken>my_duck) << endl;
	cout << "do cow equals to chicken? \t" << (my_cow==my_chicken) << " does it bigger than chicken?\t " << (my_cow>my_chicken) << endl;
	cout << "do cow equals to duck?    \t" << (my_cow==my_duck) << " does it bigger than duck?\t " << (my_cow>my_duck) << endl;

	animal_t *c1, *c2;
	c1=createAn(2);
	c2=createAn(3);
	c2=c1;
	c1->show();
	c2->show();

	/*cout << "now you can create your own animal!" << endl;
	cout << "1. duck" << endl << "2. cow" << endl << "3. chicken" << endl << "0. exit" << endl;
	cin >> choose;
	animal_t *my_animal, *your_animal;
	my_animal=createAn(choose);
	my_animal->show();
	cout << "now you can create an animal for your brother!" << endl;
	cout << "1. duck" << endl << "2. cow" << endl << "3. chicken" << endl << "0. exit" << endl;
	cin >> choose;
	your_animal=createAn(choose);
	your_animal->show();
	cout << "now you should have the same" << endl;
	your_animal=my_animal;
	your_animal->show();*/

	return 0;
}