#ifndef POINT2D_H
#define POINT2D_H

#include "point1d.h"

class Point2D : public Point1D // use the virtual qualifier when needed
{
   public:
      virtual int getDimension() const {return 2;};
      int getY() const {return (double)y;}
      void setY(int _y) {y = _y;}
   private:
      double y = 0;
};

#endif
