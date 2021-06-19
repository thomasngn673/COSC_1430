#include <iostream>
#include <cmath>

using namespace std;

long long int charArraytoInt(char myValue[])
{
	long long int total = 0;
	int i, len;
	// Check if input char is negative
	if (myValue[0] == '-')
	{
		return -1;
	}

	else
	{
		// Find length of array
		while(myValue[i] != '\0')
		{
			i++;
		}
		len = i;

		for(i = 0; i < len; ++i)
		{
			if(isdigit(myValue[i]) == 0)
			{
				return -1;
			}
		}

		// Convert char to int
		for(i = 0; i < len; ++i)
		{
			myValue[i] = myValue[i] - '0';
		}

		// Add up digits to return final number
		for(i = 0; i < len; ++i)
		{
			total = total + (myValue[i] * pow(10, (len-1-i)));
		}
	}
	return total;
}

int main()
{
   const int MAX_SIZE = 100;
   char myNumber[MAX_SIZE];
   cin >> myNumber;
   cout << charArraytoInt(myNumber);
}
