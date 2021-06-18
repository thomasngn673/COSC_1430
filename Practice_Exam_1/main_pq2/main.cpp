#include <iostream>

using namespace std;

int main()
{
    int array[6], i;
    
    for (i = 0; i < 6; ++i)
    {
	    cin >> array[i];
    }

    for (i = 0; i < 6; ++i)
    {
	    if (((array[i]) % 2) == 0)
	    {
		    cout << array[i] << " ";
	    }
    }
    return 0;
}
