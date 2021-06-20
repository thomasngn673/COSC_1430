#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int readFromfile(string filename, string fileContents)
{
	string line;
	ifstream myFile;

	myFile.open(filename);
	if(myFile.is_open())
	{	
		while(getline(myFile, line))
		{
			fileContents = line;
		}
		cout << "stuff in file: " << fileContents << endl;
		return 0;
	}

	else
	{
		cout << "file name not found" << endl;
		return -1;
	}
}

int main()
{
	string filename, filecontents;
	cin >> filename;
	readFromfile(filename, filecontents);
	return 0;
}
