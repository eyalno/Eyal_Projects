
/************************************************************************

		Author: 	    Eyal Noy
		Creation date: 	    1.11.12
		Last modified date: 1.11.12
		Description:        data storage header file input output and satistics about the storage implementation of inline
		Text Editor:	    gVim
		File Type:  	    header File
***********************************************************************/
#ifndef _DATA_STORAGE_H
#define _DATA_STORAGE_H


#include <iostream>
#include <cstring>

using namespace std;

#define NUM_OF_BUILDINGS 5

template <class T2>
class Street_t
{
	public:
		
		/*constuctor with size from user*/
		Street_t(const T2 &_id){m_id=_id; m_numBuildings=0};
			
		void SetStreetId(const T2& _id){m_id=_id};
		
		const T2& GetStreetId(){return m_id };
		
		AddBuilding2Street(const T1&_build)
		{
			m_buildings[m_numBuildings]=_build;				
			m_numBuildings++;
		}
		
		const T1& GetBuilding(const T1& _buildingId)const
		{
			for (int i=0; i<NUM_OF_BUILDINGS; ++i)
			{
				if (m_buildings[i] == GetBuildingId(_buildingId) )
				{
					return m_buildings[i];
				}
			}
			
		}
	private:
		
		T2 m_id;
		Building_t<T1>  m_buildings[NUM_OF_BUILDINGS];
		int m_numBuildings
};

/*inline functions*/


#endif /*_DATA_STORAGE_H */
