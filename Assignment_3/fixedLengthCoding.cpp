#include <fstream>
#include <cmath>
#include <string>
#include "fixedLengthCoding.h"

using namespace std;

fixedLengthCoding::fixedLengthCoding()
{
	// Initialize all private members
	alph_size = 0;
	message = "";
	mySymbol = new struct symbol[alph_size];
}

fixedLengthCoding::~fixedLengthCoding()
{
	// Destroy all pointers
	delete[] mySymbol;
}

string fixedLengthCoding::getMessage() const
{
	return message;
}

int fixedLengthCoding::getAlphabetSize() const
{
	return alph_size;
}

int fixedLengthCoding::readFromFile(const string& filename)
{
	string line, fileContents;
        ifstream myFile;
	int uniq_num=1, i, j;

	// Open file
        myFile.open(filename);
        if(myFile.is_open())
        {
                while(getline(myFile, line))
                {
			fileContents = line;
                }
		
		// Find the number of unique occurrences in the file
		int msg_len = fileContents.size();
		for(i = 1; i < msg_len; i++)
		{
			for(j = 0; j < i; j++)
			{
				if(fileContents[i] == fileContents[j])
				{
					break;
				}
			}
			if(i == j)
			{
				uniq_num++;
			}
        	}
		alph_size = uniq_num;		// assign size of alphabet to alph_size
		message = fileContents;		// assign fileContents to message
                
		return 0;
        }
        else
        {
                return -1;
        }
}

void fixedLengthCoding::createAlphabet() 
{
        // Initialize variables 
        int msg_len = message.size();
        int i, j, k=0, flag=0, remainder;
        int occurrences[msg_len], bin_code[msg_len];
        char uniq_char[msg_len];
        string bin_code_str[msg_len];

	// Initialize dynamic array (required for using string in struct)
	mySymbol = new struct symbol[alph_size];

	// (1) array containing unique characters
	// (2) array of occurrences of each unique character
        for(i = 0; i < msg_len; i++)
        {
                for (j = 0; j < i+1; j++)
                {
                        if(message[i] == uniq_char[j])
                        {
                                (occurrences[j])++;
                                flag = 1;
                        }
                }
                if (flag == 0)
                {
                        uniq_char[k] = message[i];
                        occurrences[k] = 1;
                        k++;
                }
                flag = 0;
        }

        // Assign array of unique characters to 'character' data member in struct
        for(i = 0; i < k; i++)
        {
                mySymbol[i].character = uniq_char[i];
        }
        
	// Assign array of occurrences to 'frequency' data member in struct
        for(i = 0; i < k; i++)
        {
                mySymbol[i].frequency = occurrences[i];
        }

        // Create array of integers with length of unique chars to be converted to binary
        for(i = 0; i < k; i++)
        {
                bin_code[i] = i;
        }

        // Determine maximum number of bits needed given the amount of uniq characters
        int bin_len, par1, par2;
        i = 0;
        while(1)
        {
                par1 = pow(2, i);
                par2 = pow(2, i+1);
                if((k > par1) && (k < par2))
                {
                        bin_len = i+1;
                        break;
                }
                i++;
        }

        // Initialize bin_code_str
        bin_code_str[0] = "";
        for(i = 0; i < bin_len; i++)
        {
                bin_code_str[0] = "0" + bin_code_str[0];
        }

        // Convert array of integers into binary
        // bin_code_str is an array that contains the binary number strings
        for(i = 0; i < k; i++)
        {
                while(bin_code[i] > 0)
                {
                        remainder = bin_code[i] % 2;
                        bin_code_str[i] = to_string(remainder) + bin_code_str[i];
                        bin_code[i] = bin_code[i] / 2;
                }
        }

        // Pad array of binary numbers with leading zeros to create fixed length
        int len_bin_code_str = sizeof(bin_code_str)/sizeof(bin_code_str[0]);
	int bin_incr;
        for(i = 0; i < len_bin_code_str; i++)
        {
                while((bin_code_str[i]).size() < bin_len)
                {

                        bin_incr = bin_len - ((bin_code_str[i]).size());
                        bin_code_str[i] = '0' + bin_code_str[i];
                }
        }

        // Assign binary codes array to 'code' data member in struct
	for(i = 0; i < k; i++)
        {
                mySymbol[i].code = bin_code_str[i];
        }
}

void fixedLengthCoding::printAlphabet() const
{
	int i;
        for(i = 0; i < alph_size; i++)
        {
                if(i == (alph_size - 1))
                {
                        cout << mySymbol[i].character << endl;
                        break;
                }
                cout << mySymbol[i].character << ",";
        }
}

void fixedLengthCoding::printHistogram() const
{
	int i, j;
        cout << "Histogram showing the frequency of the symbols in the alphabet" << endl;
        for (i = 0; i < alph_size; i++)
        {
                cout << mySymbol[i].character << " | ";
                for (j = 0; j < mySymbol[i].frequency; j++)
                {
                        cout << '*';
                }
                cout << endl;
        }
}

void fixedLengthCoding::printCodes() const
{
	int i, j;
        cout << "Fixed-lenght codes of the symbols in the alphabet" << endl;
        for(i = 0; i < alph_size; i++)
        {
                cout << mySymbol[i].character << " | " << mySymbol[i].code << endl;
        }
}
