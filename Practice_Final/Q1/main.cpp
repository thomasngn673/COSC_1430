#include <iostream>
#include "GenericArray.h"
using namespace std;
int main()
{
	GenericArray<int> array1(10);
	array1.push_back(10);
	array1.push_back(20);
	array1.push_back(30);
	array1.push_back(40);
	GenericArray<string> array2(4);
	array2.push_back("FName");
	array2.push_back("MName");
	array2.push_back("LName");
	array1.print();
	array2.print();
}
