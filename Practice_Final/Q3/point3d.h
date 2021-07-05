#ifndef POINT3D_H
#define POINT3D_H

#include "point2d.h"

class Point3D : public Point2D // use the virtual qualifier when needed 
{
   public:
      virtual int getDimension() const {return 3;};
      int getZ() const {return (double)z;}
      void setZ(int _z) {z = _z;}
   private:
      double z = 0;
};

#endif
