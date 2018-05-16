#include <iostream>
#include <vector> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <algorithm>

using namespace std;

void MyMethod(vector<int> &bar)
{
	vector<int>::iterator it;
	bar.clear();

	for (int i = 0; i < 6; )
	{
		int num = rand() % 37 + 1;
		it = find(bar.begin(), bar.end(), num);
		
		if (it == bar.end())
		{
			++i;
			bar.push_back(num);
		}
		
	}
	
	sort(bar.begin(), bar.end());
	
	bar.push_back(rand() % 7 + 1);

	cout << "numbers:";
	for (it = bar.begin(); it != bar.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';
}





int main(){
	
	srand(time(NULL));

	vector<int> bar;
	


	MyMethod(bar);
	MyMethod(bar);
	

	return 0;
}