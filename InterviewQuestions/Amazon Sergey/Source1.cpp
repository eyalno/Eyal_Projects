


/*
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;



static void transform_matrix(vector<vector<int> >& matrix)
{
	const int DIM = matrix.size();
	const int FRAME_COUNT = DIM / 2;
	for (int frame = 0; frame < FRAME_COUNT; ++frame)
	{
		const int FRAME_SIZE = DIM - 2 * frame;
		const int FRAME_START = frame;
		const int FRAME_LAST = frame + FRAME_SIZE - 1;
		int temp_upper_left = matrix[FRAME_START][FRAME_START];
		int temp_upper_right = matrix[FRAME_START][FRAME_LAST];
		int temp_lower_right = matrix[FRAME_LAST][FRAME_LAST];
		int temp_lower_left = matrix[FRAME_LAST][FRAME_START];

		for (int i = FRAME_START; i < FRAME_LAST; ++i)
		{
			// Upper pane
			matrix[FRAME_START][DIM - i - 1] = matrix[FRAME_START][DIM - i - 2];
			// Right pane
			matrix[DIM - i - 1][FRAME_LAST] = matrix[DIM - i - 2][FRAME_LAST];
			// Lower pane
			matrix[FRAME_LAST][i] = matrix[FRAME_LAST][i + 1];
			// Left pane
			matrix[i][FRAME_START] = matrix[i + 1][FRAME_START];
		}
		// Note: Based on the order of the lines above, one of the following
		// assignments is technically not needed but it is safer to do it
		// anyway just in case someone changes the orders of the lines above
		// and forget to fix this part.
		// EYAL: Putting this comment in the code, or saying it verbally to
		// tester shows that you understand that you did an extra step, that it
		// has no performance impact, and that you made a concious decision to
		// keep it, not because you did not want to put the effort of figuring
		// out which line it is, but for keep the code in working condition
		// even if someone changes it in the future
		matrix[FRAME_START][FRAME_START + 1] = temp_upper_left;
		matrix[FRAME_START + 1][FRAME_LAST] = temp_upper_right;
		matrix[FRAME_LAST][FRAME_LAST - 1] = temp_lower_right;
		matrix[FRAME_LAST - 1][FRAME_START] = temp_lower_left;
	}
}

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

int main(int argc, char **argv)
{
	int dim;
	vector<vector<int> > lines;

	cin >> dim;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (cin.bad() || dim < 0)
	{
		cout << "Invalid matrix dimention size: " << dim << endl;
		return -1;
	}
	for (int row = 0; row < dim; ++row)
	{
		string line_str;
		vector<int> line;

		getline(cin, line_str);
		if (cin.bad())
		{
			cout << "Failed to read line from user input" << endl;
			return -1;
		}

		istringstream ss(line_str);

		int var;
		while ((ss >> var))
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

	transform_matrix(lines);

	print_matrix(lines);
	return 0;
}


*/