#include <iostream>

using namespace std;
//lazy
class Singleton
{
private:
    static bool instanceFlag;
    static Singleton *single;
    Singleton()
    {
        //private constructor
    }
public:
    static Singleton* getInstance();
    void method();
    ~Singleton()
    {
        instanceFlag = false;
    }
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! instanceFlag)
    {
	lock
        single = new Singleton();
        instanceFlag = true;
        unlock
	return single;
    }
    else
    {
        return single;
    }
}

void Singleton::method()
{
    cout << "Method of the singleton class" << endl;
}





//eager
public class Singleton {
	private: 
		static  Singleton* instance;
 
    		Singleton() {}
 
	public:
		
		static Singleton getInstance() {
        
			return instance;
    }
}
Singleton* Singleton::instance= new Singleton;







//factory

T9 
Insert word 
search word

vector <Datastructre*>
vectr<strings> words 



cetech

Datarecv 
	closexcx 
	list <strigs> hold recv 
	int fd


map 
queue
holds the data

fd listner nrew connection select all
לשלוח ל תהליכון רק בסיום העבודה לכן ה קיו 
	להכין קובץ חדש לאחר ניתוח פארסינג


