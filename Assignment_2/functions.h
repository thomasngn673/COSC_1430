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

int readFromFile(string filename, string &fileContents)
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
		return 0;
	}
	else
	{
		return -1;
	}
}

int findAlphabetSize(string fileContents)
{
	int msg_len = fileContents.size();
	int uniq_num=1, i, j;
        // Count unique occurences
        // Produces: number of unique characters
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
	return uniq_num;
}

void createAlphabet(string fileContents, struct symbol alphabet[])
{
        // Find number of characters of message 
        int msg_len = fileContents.size();
	
	int i=0, j=0, k=0, flag=0, remainder;
	int occurrences[msg_len], bin_code[msg_len];
	char uniq_char[msg_len];
	string bin_code_str[msg_len];
	
	// Create array of unique characters and count occurrences of each unique character
	// Produces: (1) array containing unique characters, (2) array of occurrences of each unique character
	for(i = 0; i < msg_len; i++)
	{
		for (j = 0; j < i+1; j++)
		{
			if(fileContents[i] == uniq_char[j])
			{
				(occurrences[j])++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			uniq_char[k] = fileContents[i];
			occurrences[k] = 1;
			k++;
		}
		flag = 0;
	}

	// Assign array of unique characters to 'character' data member in struct
	for(i = 0; i < k; i++)
	{
		alphabet[i].character = uniq_char[i];
	}

	// Assign array of occurrences to 'frequency' data member in struct
	for(i = 0; i < k; i++)
	{
		alphabet[i].frequency = occurrences[i];
	}

	// Create an array of integers with length of unique characters to be converted into binary
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

	int len_bin_code_str = sizeof(bin_code_str)/sizeof(bin_code_str[0]);
	// Pad array of binary numbers with leading zeros to create fixed length
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
		alphabet[i].code = bin_code_str[i];
	}

}

void printAlphabet(struct symbol alphabet[], int arr_len)
{
	int i;
	for(i = 0; i < arr_len; i++)
	{
		if(i == (arr_len - 1))
		{
			cout << alphabet[i].character << endl;
			break;
		}
		cout << alphabet[i].character << ",";
	}
}

void printHistogram(struct symbol alphabet[], int arr_len)
{
	int i, j;
	cout << "Histogram showing the frequency of the symbols in the alphabet" << endl;
	for (i = 0; i < arr_len; i++)
	{
		cout << alphabet[i].character << " | ";
		for (j = 0; j < alphabet[i].frequency; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}

void printCodes(struct symbol alphabet [], int arr_len)
{
	int i, j;
	cout << "Fixed-lenght codes of the symbols in the alphabet" << endl;
	for(i = 0; i < arr_len; i++)
	{
		cout << alphabet[i].character << " | " << alphabet[i].code << endl;
	}
}


#endif
