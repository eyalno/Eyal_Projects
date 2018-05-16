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

#define MAX_NUM_OF_BUILDINGS 20

#ifndef _STREET_H
#define _STREET_H


/************************************************class***********************************************************************/



template< class T1,class T2>
class Street_t
{

	public:

		Street_t<T1,T2>(){}

		Street_t<T1,T2>(const T1& _id):m_id(_id){}
	

		Street_t<T1,T2>( const Street_t<T1,T2>& _street ){}

		virtual ~Street_t<T1,T2>(){}


		Street_t<T1,T2>& operator=( const Street_t<T1,T2>& _street ){}

		void setStreetID( const T1& _id){m_id = _id;}

		const T1& getStreetID() const {return m_id;}

		void AddBuilding2Street( const Building_t<T2>& _building){ arrBuildings[_building.getBuildingID()] = _building;}

		const Building_t<T2>& getBuilding( const T2& _bid ) const{ return arrBuildings[_bid];} 

	private:

		T1 m_id;

		Building_t<T2> arrBuildings[MAX_NUM_OF_BUILDINGS];
	

			

};

#endif/*_BUILDING_H*/





		
