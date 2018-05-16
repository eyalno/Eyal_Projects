
typedef void* FileHandle

#define FILE_READ_MODE 1
#define FILE_WRITE_MODE 2

FileHandle OpenFile(const char * filename, int mode);
int ReadFile(FileHandle , void* buff , int size);
int WriteFile(FileHandle, void* buff, int size);
void CloseFile(FileHandle);

void Store(const vector<Shape*> & shapes, const char * filename)
{
	FileHandle OpenFile(const char * filename, int mode);

	for (auto it = shapes.begin(); it != shapes.end(); ++it)
		(*it)->Write(FileHandle);

	void CloseFile(FileHandle);
}

void Retreive(vector<Shape*> & shapes, const char * filename)
{
	FileHandle OpenFile(const char * filename, int mode);
	
	char cShape;
	int ReadFile(FileHandle, void* buff, int size);
	while (fs.read(&cShape, 1))
	{
		Shape * shape;

		switch (cShape - '0')
		{
		case TRIANGLE:
			shape = new Triangle(fs);
			break;

		case CIRCLE:
			shape = new Circle(fs);
			break;

		case SQUARE:
			shape = new Square(fs);
			break;
		default:
			return;
		}

		shapes.push_back(shape);


		char sBlock[COORD * NO_OF_PARAM + 1];
		string strBlock;

		fs.read(sBlock, TRIANGLE_SIZE);
		sBlock[TRIANGLE_SIZE] = 0;
		strBlock = sBlock;


		x1 = atoi(strBlock.substr(0, 3).c_str());
		y1 = atoi(strBlock.substr(3, 3).c_str());
		x2 = atoi(strBlock.substr(6, 3).c_str());
		y2 = atoi(strBlock.substr(9, 3).c_str());
		x3 = atoi(strBlock.substr(12, 3).c_str());
		y3 = atoi(strBlock.substr(15, 3).c_str());
		void CloseFile(FileHandle);
}


void Square::Write(fstream &fs) //could i have not write it 3 times save the enum as member?
{
	char buffer[SIZE];

	int size = sprintf(buffer, "%d%COORDd%COORDd",SQUARE, ,  );
	fs << SQUARE;
	fs << setfill('0') << setw(COORD) << x1;
	fs << setfill('0') << setw(COORD) << y1;
	fs << setfill('0') << setw(COORD) << x2;
	fs << setfill('0') << setw(COORD) << y2;

	int WriteFile(FileHandle, void* buff, int size);
}