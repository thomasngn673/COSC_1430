#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

template <typename T>
void reverseArray(T array[], int size)
{
	T temp;
	int i = 0;
	int j = size-1;
	while(i < size/2)
	{
		temp = array[i];
		array[i] = array[j]; // first element has value of last element
		array[j] = temp; // last element has value of first element
		i++;
		j--;
	}
}

template <typename T>
void printArray(T array[], int size)
{
	for(int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

#endif
