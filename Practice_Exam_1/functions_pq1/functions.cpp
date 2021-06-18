#include <stdlib.h>
#include <iostream>
#include "functions.h"

using namespace std;

int main(void)
{
	_3dPoint x, y;
	x.x = 0;
	x.y = 0;
	x.z = 0;
	y.x = 1;
	y.y = 2;
	y.z = 3;
	swap3dPoints(x, y);
	cout << x.x << " " << x.y << " " << x.z << endl;
	cout << y.x << " " << y.y << " " << y.z << endl;
}
