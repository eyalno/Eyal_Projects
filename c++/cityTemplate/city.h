
/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    1.11.12
		Last modified date: 1.11.12
		Description:        data storage header file input output and satistics about the storage implementation of i:nline
		Text Editor:	    gVim
		File Type:  	    header File
***********************************************************************/
#ifndef _DATA_STORAGE_H
#define _DATA_STORAGE_H


#include <iostream>
#include <cstring>

#define NUM_OF_STREETS 5

template <class T3>
class City_t
{
	public:
		
		/*constuctor with size from user*/
		City_t(const T3 &_id){m_id=_id; m_numCities=0};
			
		void SetCityId(const T3& _id){m_id=_id};
		
		const T3& GetCityId(){return m_id };
		
		AddStreet2City(const T2& _street)
		{
			m_streets[m_numBuildings]=_street;				
			m_numCities++;
		}
		
		const T2& GetStreet(const T2& _streetId)const
		{
			for (int i=0; i<NUM_OF_STREETS; ++i)
			{
				if (m_streets[i] == GetStreetId(_streetId) )
				{
					return m_streets[i];
				}
			}
			
		}
	private:
		
		T3 m_id;
		Street_t<T2>  m_streets[NUM_OF_CITIES];
		int m_numCities;
};
/*inline functions*/


#endif /*_DATA_STORAGE_H */
