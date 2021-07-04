#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

template <class T>

int findPos(T array[], int size, T variable)
{
	for(int i = 0; i < size; i++)
	{
		if(array[i] == variable)
		{
			return i;
		}
	}
	return -1;
}

#endif
