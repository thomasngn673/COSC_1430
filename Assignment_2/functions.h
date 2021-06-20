#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct symbol
{
    char character;
    int frequency;
    string code;
};

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
		return -1;
	}
}

#endif
