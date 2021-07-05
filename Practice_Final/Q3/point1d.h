#ifndef POINT1D_H
#define POINT1D_H

#include "point.h"

class Point1D : public Point // use the virtual qualifier when needed
{
   public:
      int getDimension() const {/*write your implementation here*/};
      int getX() const {/*write your implementation here*/}
      void setX(int x) {/*write your implementation here*/}
   private:
      double x = 0;
};

#endif