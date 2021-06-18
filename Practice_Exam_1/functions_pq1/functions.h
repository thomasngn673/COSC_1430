#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

struct _3dPoint
{
	int x;
	int y;
	int z;
};

void swap3dPoints(_3dPoint &point1, _3dPoint &point2) {
	struct _3dPoint tmp;
	tmp = point1;
	point1 = point2;
	point2 = tmp;
}

#endif
