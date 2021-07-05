#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Point // use the virtual qualifier when needed
{
   public:
      int getDimension() const = 0;
};

#endif