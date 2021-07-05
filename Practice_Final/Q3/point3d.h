#ifndef POINT3D_H
#define POINT3D_H

#include "point2d.h"

class Point3D : public Point2D // use the virtual qualifier when needed 
{
   public:
      int getDimension() const {/*write your implementation here*/};
      int getZ() const {/*write your implementation here*/}
      void setZ(int z) {/*write your implementation here*/}
   private:
      double z = 0;
};

#endif