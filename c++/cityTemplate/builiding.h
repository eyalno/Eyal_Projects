
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

using namespace std;


template <class T1>
class Building_t
{
	public:
		
		/*constuctor with size from user*/
		Building_t(const T1 &_id){m_id=_id};
			
		void SetBuildingId(const T1& _id){m_id=_id};
		const T1& GetBuildingId(){return m_id };
	
	private:
	
		T1 m_id;

		
};

/*inline functions*/


#endif /*_DATA_STORAGE_H */
