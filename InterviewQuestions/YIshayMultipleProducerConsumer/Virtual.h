#include <iostream>

class a
{
public:
	a(){
		_iL = new int(5);
		cout << " new _iL" << endl;
	}

	virtual ~a(){
		delete _iL;
		cout << "delete _iL" << endl;
	}

private:
	int *_iL;
};


class b : public a
{
public:
	b(){
		_iL2 = new int(6);
		cout << " new _iL2" << endl;
	}

	virtual ~b(){
		delete _iL2;
		cout << "delete _iL2" << endl;
	}

private:
	int *_iL2;
};



void test()
{



	a* q = new b;

	delete q;
}