#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
	string message, filename;

	cin >> filename;
	if(readFromFile(filename, message) == 0)
	{
		cout << "Message: " << message << endl;
		int alp_size = findAlphabetSize(message);
		struct symbol alphabet[alp_size];
		createAlphabet(message, alphabet);
		cout << "Number of symbols in the alphabet = " << alp_size << endl;
		cout << "Characters in the alphabet = ";
		printAlphabet(alphabet, alp_size);
		cout << "Number of bits per symbol = " << ceil(log2(alp_size)) << endl;
		printHistogram(alphabet, alp_size);
		printCodes(alphabet, alp_size);
	}
	else
    	{
        	cout << "File not found." << endl;
	}
	return 0;
}

