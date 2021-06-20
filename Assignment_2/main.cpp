#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{

	string message, filename;
	// Define your alphabet variable here. You must use the given symbol structure to create an array or a vector.

	cin >> filename;
	if(/* Call the readFromFile function here */==0)
	{
	cout << "Message: " << message << endl;
	// Call the createAlphabet function here.
	cout << "Number of symbols in the alphabet = " << /*Use a variable with the alphabet size here*/ << endl;
	cout << "Characters in the alphabet = ";
	// Call the printAlphabet function here.
	cout << "Number of bits per symbol = " << ceil(log2(/*Use a variable with the alphabet size here*/) << endl;
	// Call the printHistogram function here.
	// Call the prinCodes function here.
	}
	else
    	{
        	cout << "File not found." << endl;
	}
	return 0;
}
