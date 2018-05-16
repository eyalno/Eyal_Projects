#ifndef __ANIMAL_T_H__
#define __ANIMAL_T_H__

class animal_t
{
public:
	animal_t();
	animal_t(const animal_t &animal1);   //copy CTOR
	virtual ~animal_t();

	virtual const animal_t &operator=(const animal_t &animal1)=0;
	bool operator>(const animal_t &animal1) const;
	bool operator==(const animal_t &animal1) const;
	
	virtual void makeSound() const=0;
	virtual void show() const=0;
protected:
	animal_t(const string str, const int _ID);   //CTOR from details

	const int getID() const;
	const string getName() const;
private:
	string name;
	const int ID;
};

#endif /*#ifndef __ANIMAL_T_H__*/