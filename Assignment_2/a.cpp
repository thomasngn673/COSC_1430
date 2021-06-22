#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	int i=0, k=26, par1, par2, bin_len;
        while(1)
        {
                par1 = pow(2, i);
                par2 = pow(2, i+1);
                if(((k+1) > par1) && ((k+1) < par2))
                {
                        bin_len = i+1;
                        break;
                }
                i++;
        }
	cout << "bin_len is :" << bin_len << endl;
}

