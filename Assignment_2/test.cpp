#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main (void)
{
        int i, remainder, bin_code[5];
	string bin_code_str[5];
	
	bin_code_str[0] = "000";
	
	// Create an array of integers with length of unique characters to be converted into binary
        for(i = 0; i < 5; i++)
        {
                bin_code[i] = i;
        }
	
        // Convert array of integers into binary and pad with zero to create fixed amount
        for(i= 0; i < 5; i++)
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
	int bin_len=3, bin_incr;
	for(i = 0; i < len_bin_code_str; i++)
	{
		while((bin_code_str[i]).size() < bin_len)
		{

			bin_incr = bin_len - ((bin_code_str[i]).size());
			bin_code_str[i] = '0' + bin_code_str[i];
		}
	}

	for (i = 0; i < 5; i++)
	{
		cout << '\n' << endl;
		cout << bin_code_str[i] << endl;
		cout << "str len at this is " << (bin_code_str[i]).size() << endl;
	}
}
