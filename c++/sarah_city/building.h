/**************************************************************************************
    Author : Sarah Pinto
    Creation date :      29.10.12
    Date last modified :
    Description : Tree header file - interface.
***************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef _BUILDING_H
#define _BUILDING_H



/************************************************class***********************************************************************/

template< class T>
class Building_t
{

	public:

		Building_t<T>(){}

		Building_t<T>(const T& _id):m_id(_id){}
		
		Building_t<T>( const Building_t<T>& _building ){}

		virtual ~Building_t<T>(){}

		Building_t<T>& operator=( const Building_t<T>& _building ){}

		void setBuildingID( const T& _id){ m_id = _id;}

		const T& getBuildingID() const { return m_id;}

	private:

		T m_id;
		
};

#endif/*_BUILDING_H*/





		
