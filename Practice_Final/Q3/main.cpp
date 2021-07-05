#include "point1d.h"
#include "point2d.h"
#include "point3d.h"

void read(Point* points[], int n) 
{

}

void print(Point* points[], int n)
{

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

