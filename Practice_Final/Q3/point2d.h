#ifndef POINT2D_H
#define POINT2D_H

#include "point1d.h"

class Point2D : public Point1D // use the virtual qualifier when needed
{
   public:
      int getDimension() const {/*write your implementation here*/};
      int getY() const {/*write your implementation here*/}
      void setY(int y) { /*write your implementation here*/}
   private:
      double y = 0;
};

#endif