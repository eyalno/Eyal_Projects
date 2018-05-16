#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

static int findDuplicates(vector<vector<int>> & matrix , int k)
{
	const int DIM = matrix.size();

	for (int row = 0; row < DIM; ++row)
	{
		for (int col = 0; col < DIM; ++col)
		{
			bool b1 = false;
			bool b2 = false;
			bool b3 = false;
			bool b4 = false;
			
			// for each member i check all the different combinations of the indices 
			//with parameters check
			//e.g. indices 3 : 3-0 2-1 1-2 0-3
			for (int i = 0,   j = k; i <= k; ++i, --j)
			{
				 int rowUp = row + i;
				 int rowDown = row - i;
				 int colUp = col + j;
				 int colDown = col - j;
				
				if (rowUp < DIM && colUp < DIM)
					b1 = (matrix[row][col] == matrix[rowUp][colUp]) ?   true : false;

				if (rowUp < DIM && colDown >= 0)
					b2 = (matrix[row][col] == matrix[rowUp][colDown]) ? true : false;

				if (rowDown >= 0 && colUp < DIM)
					b3 = (matrix[row][col] == matrix[rowDown][colUp]) ? true : false;

				if (rowDown >= 0 && colDown >= 0)
					b4 = (matrix[row][col] == matrix[rowDown][colDown]) ? true : false;

			}

			if (b1||b2||b3||b4)
				return 1;

		}
		
	}
	return 0;
}


int main(int argc, char ** argv)
{

	int dim;

	cin >> dim;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (cin.bad() || dim < 0)
	{
		cout << "Invalid matrix dimension:" << dim << endl;
		return -1;
	}

	vector<vector<int>> lines;

	for (int row = 0; row < dim; ++row)
	{

		string strLine;

		getline(cin, strLine);

		if (cin.bad())
		{
			cout << "Failed to read line from user input" << endl;
			return -1;
		}

		stringstream ss(strLine);

		vector<int> line;
		int var;
		while (ss >> var)
		{
			if (ss.bad())
			{
				cout << "Failed to read integer from user, invalid input" << endl;
				return -1;
			}
			line.push_back(var);
		}

		if (line.size() != dim)
		{
			cout << "Number of values in line [" << line.size() << "] does not match dimension size [" << dim << "]" << endl;
			return -1;
		}

		lines.push_back(line);
	}

	assert(lines.size() == dim);

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (cin.bad() || k <= 0)
	{
		cout << "Invalid Indices:" << k << endl;
		return -1;
	}


	if (findDuplicates(lines, k))
		cout << "YES" <<endl;
	else
		cout << "NO" << endl;

	return 0;
}