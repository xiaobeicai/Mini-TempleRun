#ifndef __CHECKCOLLISION_H__
#define __CHECKCOLLISION_H__

#include <math.h>
#include "Vector3.h"
#include "line.h"

class CheckCollision
{
public:
	bool isIntersect(Vector3 p, float r, Vector3 p1, Vector3 p2);  // Ô²ÓëÏß¶ÎÅö×²¼ì²â
	bool lineCheckCollision(Vector3 rpos);
	bool pointCheckCollision(Vector3 rpos,Vector3 p);
};



#endif // __CHECKCOLLISION_H__

