

/*

#include <iostream>
#include <string>
#include <sstream>

#include <vector>
#include <cassert>

using namespace std;

static void print_matrix(vector<vector<int> >& matrix)
{
	for (vector<vector<int>>::const_iterator l = matrix.begin(); l != matrix.end(); ++l)
	{
		for (vector<int>::const_iterator c = l->begin(); c != l->end(); ++c)
		{
			cout << *c;
		}
		cout << endl;
	}
}





static void transformMatrix(vector<vector<int>> & matrix)
{

	const int DIM = matrix.size();
	const int FRAME_COUNT = DIM / 2;

	for (int frame = 0; frame < FRAME_COUNT; ++frame)
	{
		const int FRAME_SIZE = DIM - frame * 2;
		const int FRAME_START = frame;
		const int FRAME_END = frame + FRAME_SIZE -1;

		int tmp_up_left = matrix[FRAME_START][FRAME_START];
		int tmp_up_right = matrix[FRAME_START][FRAME_END];
		int tmp_down_left = matrix[FRAME_END][FRAME_START];
		int tmp_down_right = matrix[FRAME_END][FRAME_END];

		for (int i = FRAME_START; i < FRAME_END; ++i)
		{
			//upper
			matrix[FRAME_START][FRAME_END - i] = matrix[FRAME_START][FRAME_END - i - 1];
			//right
			matrix[FRAME_END - i][FRAME_END] = matrix[FRAME_END - i - 1][FRAME_END];
			//down
			matrix[FRAME_END][FRAME_START + i] = matrix[FRAME_END][FRAME_START + i + 1];
			//left
			matrix[FRAME_START + i][FRAME_START] = matrix[FRAME_START + i + 1][FRAME_START];
		}
		matrix[FRAME_START][FRAME_START + 1] = tmp_up_left;
		matrix[FRAME_START + 1][FRAME_END] = tmp_up_right;
		matrix[FRAME_END][FRAME_END - 1] = tmp_down_right;
		matrix[FRAME_END - 1][FRAME_START] = tmp_down_left;

	}


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
			cout << "Number of values in line [" << line.size() << "] does not match dimention size [" << dim << "]" << endl;
			return -1;
		}

		lines.push_back(line);
	}


	assert(lines.size() == dim);

	transformMatrix(lines);

	print_matrix(lines);

	return 0;
}



*/