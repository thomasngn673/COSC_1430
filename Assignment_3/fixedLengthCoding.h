#ifndef FIXEDLENGTHCODING_H
#define FIXEDLENGTHCODING_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct symbol
{
    char character;
    int frequency;
    string code;
};

class fixedLengthCoding
{
	private:
		string message = "";
		int alph_size = 0;
		struct symbol *mySymbol = nullptr;
	public:
		fixedLengthCoding();			// constructor
		~fixedLengthCoding();			// destructor
		string getMessage() const;		// getMessage
		int getAlphabetSize() const;		// getAlphabetSize
		int readFromFile(const string &); 	// readFromFile
		void createAlphabet();			// createAlphabet
		void printAlphabet() const;		// printAlphabet
		void printHistogram() const;		// printHistogram
		void printCodes() const;		// printCodes
};

#endif
