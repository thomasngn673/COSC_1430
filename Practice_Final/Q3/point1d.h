#ifndef POINT1D_H
#define POINT1D_H

#include "point.h"

class Point1D : public Point // use the virtual qualifier when needed
{
   public:
      virtual int getDimension() const {return 1;};
      int getX() const {return (double)x;}
      void setX(int _x) {x = _x;}
   private:
      double x = 0;
};

#endif
