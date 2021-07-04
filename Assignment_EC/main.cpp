#include <iostream>
#include <string>
#include "functions.h"


int main(int argc, char **argv)
{
    int pos;
    int intArray[]={1,2,3,4,5,10,12,0,13};
    std::string stringArray[]={"COSC","1430","SUMMER","2021"};
    double doubleArray[]={1.1,2.2,3.3};

    char option = argv[1][0];

    switch(option)
    {
        case '1':   pos = findPos(intArray,9,13);
                    break;
        case '2':   pos = findPos(stringArray,4,std::string("1430"));
                    break;
        case '3':   pos = findPos(doubleArray,3,1.0);
                    break;
    }
    if (pos!= -1)
        std::cout << "Pos = " << pos <<std::endl;
    else
        std::cout << "The value is not in the array" << std::endl;
    return 0;
}
