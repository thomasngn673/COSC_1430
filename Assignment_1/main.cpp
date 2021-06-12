#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int main ()
{
	// Initialize variables
	const int MAXSIZE = 100;
	int num=1, bits, msg_len, i, j, k=0, flag=0;
	char msg[MAXSIZE], buffer[msg_len]={0}, occurrences[msg_len]={0};

	// Input sequence of characters
	cin.getline(msg, MAXSIZE);

	// Display input message
	cout << "Message: " << msg << endl;

	// Specify message length
	msg_len = strlen(msg);

	// Count unique occurrences
	for (i = 1; i < msg_len; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (msg[i] == msg[j])
				break;
		}
		if (i == j)
		{
			num++;
		}
	}
	cout << "Number of symbols in the alphabet = " << num << endl;

	// Create an array of unique characters and count occurrences of each unique character
	for (i = 0; i < msg_len; i++)
	{
		for (j = 0; j < i+1; j++)
		{
			if (msg[i] == buffer[j])
			{
				(occurrences[j])++;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			buffer[k] = msg[i];
                	occurrences[k] = 1;
                	k++;
		}
		flag = 0;
	}
	
	// Print the unique characters in an array
	cout << "Characters in the alphabet = ";
	for (i = 0; i < num; i++)
	{
		if (i == (num-1))
		{
			cout << buffer[i] << endl;
			break;
		}
		cout << buffer[i] << ",";
	}

	// Find number of bits per symbol
	cout << "Number of bits per symbol = " << ceil(log2(num)) << endl;

	// Create histogram
	cout << "Histogram showing the frequency of the symbols in the alphabet: " << endl;
	for (i = 0; i < num; i++)
	{
		cout << buffer[i] << " | ";
		for (j = 0; j < occurrences[i]; j++)
		{
			cout << '*';
		}
		cout << endl;
	}
}
