/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    
		Last modified date: 27.11.2012
		Description:        generic container list or vector
		File Type:  	    cpp File
***********************************************************************/


/* standard libaries */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>

/*local libaries*/
#include "container.h"

using namespace std;

int main()
{
	Tcontainer_t<int,vector> container;
	int item;
	
	//Tcontainer_t<int,vector> container;
	//Tcontainer_t<int,list<int*> > container;


	do
	{
		int option;
		cout<<"1. is empty"<<endl;
		cout<<"2. size"<<endl;
		cout<<"3. insert end"<<endl;
		cout<<"4. first element"<<endl;
		cout<<"5. last elemen"<<endl;
		cout<<"6. find"<<endl;
		cout<<"7. remove"<<endl;
		cout<<"8. remove all"<<endl;
		cout<<"9. delete "<<endl;
		cout<<"10. delete all"<<endl;
		cout<<"11. []"<<endl<<endl;
		cout<<"112. exit"<<endl<<endl;
		cout<<"enter option:"<<endl;

		cin>>option;

		switch (option)
		{
			case 1 :
				container.IsEmpty()? cout<< "empty"<<endl:cout<<"not empty"<<endl ;
				break;
			case 2 :
				cout<<container.Size()<<endl;
				break;
			case 3 :
				cout<<"enter number"<<endl;
				cin>>item;
				container.InsertEnd(&item);
				break;
			case 4 :
				cout<<*container.FirstElement()<<endl;
				break;
			case 5 :
				cout<<*container.LastElement()<<endl;
				break;
			case 6 :
				cout<<"enter number"<<endl;
				cin>>item;
				container.Find(item)?cout<< "found"<<endl:cout<<"not found"<<endl ;
				break;
			case 7 :
				cout<<"enter number"<<endl;
				cin>>item;
				container.RemoveElement(item);
				break;
			case 8:
				container.RemoveAll();	
					break;
			case 9 :
				cout<<"enter number"<<endl;
				cin>>item;
				container.DeleteElement(item);
				break;
			case 10 :
				container.DeleteAll();
				break;
			case 11 :
				cout<<"enter number"<<endl;
				cin>>item;
				cout<< *container[item]<<endl;

					break;
			case 12 :
				return 0;

			default :
				break;
		}

	}
	while(1);



	return 0;
}
