#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
	string message, filename;
	struct symbol alphabet[10];
	int arr_len = sizeof(alphabet) / sizeof(alphabet[0]);

	cin >> filename;
	if(readFromFile(filename, message) == 0)
	{
		cout << "Message: " << message << endl;
		createAlphabet(message, alphabet);
/*		cout << "Number of symbols in the alphabet = " << arr_len << endl;
		cout << "Characters in the alphabet = ";
		printAlphabet(alphabet, arr_len);
		cout << "Number of bits per symbol = " << ceil(log2(arr_len)) << endl;
		printHistogram(alphabet, arr_len);
		printCodes(alphabet, arr_len); */
	}
	else
    	{
        	cout << "File not found." << endl;
	}
	return 0;
}

