



#include <vector>
#include <string>

using namespace std;

//vector from the same class? self growing inline in header y?



class DataStructure
{
	public:
		DataStructure();			
		void InsertWord(const string & _word); //insert word to dictionary
		const string & SearchWord(char _number,DataStructure ** _ptr);
	private:

		vector < DataStructure*  > m_classArray;		// do i need pointer next data structure
		vector<string> m_words; 				// vector of all word in this location
		vector<string>::iterator itWords;  /// change name //curent string in vector
		static string m_emptyString;
};

