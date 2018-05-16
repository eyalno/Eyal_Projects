/**************************************************************************************
    Author : Sarah Pinto
    Creation date :      29.10.12
    Date last modified :
    Description : Tree header file - interface.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "building.h"
#include "street.h"

#define MAX_NUM_OF_STREETS 100

#ifndef _CITY_H
#define _CITY_H


/************************************************class***********************************************************************/



template< class T1,class T2 , class T3>
class City_t
{

	public:

		City_t<T1,T2,T3>(){}

		City_t<T1,T2,T3>(const T1& _id):m_id(_id){}
		

		City_t<T1,T2,T3>( const City_t<T1,T2,T3>& _city ){}

		virtual ~City_t<T1,T2,T3>(){}


		City_t<T1,T2,T3>& operator=( const City_t<T1,T2,T3>& _city ){}

		void setCityID( const T1& _id){m_id = _id;}

		const T1& getCityID() const {return m_id;}

		void AddStreet( const Street_t<T2,T3>& _street)
		{
		
		 	arrStreets[_street.getStreetID()] = _street;
		}

		const Street_t<T2,T3>& getStreet( const T2& _sid ) const{ return arrStreets[_sid] ;} 

	private:

		T1 m_id;

		Street_t<T2,T3>  arrStreets[MAX_NUM_OF_STREETS];

		

};

#endif/*_BUILDING_H*/




		
