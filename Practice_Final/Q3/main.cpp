#include "point1d.h"
#include "point2d.h"
#include "point3d.h"
#include <iostream>

using namespace std;

void read(Point* points[], int n) 
{	
	string x
	for(int i = 0; i < n; i++)
	{
		cin >> 
}

void print(Point* points[], int n)
{
	cout << "#1D = " << pointsPtr[n].getX();
	cout << ", #2D = " << pointsPtr[n].getY();
	cout << ", #3D = " << pointsPtr[n].getZ();
}

// Do not modify the main function

int main(int argc, char **argv)
{
    switch (argv[1][0])
    {
        case '1':   
        {
                Point* points[7];
                read(points,7);
                print(points,7);
                break;
        }
        case '2':
        {
		Point* points[4];
		read(points,4);
		print(points,4);
		break;
        }
    }
    return 0;
}

