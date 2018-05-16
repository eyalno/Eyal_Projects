/**************************************************************************************
    Author : Sarah Pinto
    Creation date :      29.10.12
    Date last modified :
    Description : Tree header file - interface.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "building.h"
#include "street.h"
#include "city.h"

using namespace std;

/************************************************main***********************************************************************/


int main( int argc ,const char** argv)
{

	
	City_t<int,int,int>  city(111);

	Street_t<int, int>  street(22);

	Building_t<int> b1(3);
	Building_t<int> b2(4);

	

	street.AddBuilding2Street(b1);
	street.AddBuilding2Street(b2);

	cout<<"The ID of building1 is:"<< b1.getBuildingID()<<endl;
	cout<<"The ID of building2 is:"<< b2.getBuildingID()<<endl;
	cout<<"The ID of street is:"<< street.getStreetID()<<endl;
	cout<<"The ID of city is :"<< city.getCityID()<<endl;
	
	

	city.AddStreet(street);
	

	return 0 ;
}

	
