#include "Point3.h"

Point3::Point3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

Point3::Point3(float xx,float yy,float zz)
{
	x = xx;
	y = yy;
	z = zz;
}

Point3::Point3(const Point3& p)
{
	x = p.x; 
	y = p.y;
	z = p.z;
}

Point3::~Point3(){ };

void Point3::build4tuple(float v[])
{
	v[0] = x; 
	v[1] = y; 
	v[2] = z; 
	v[3] = 1.0f;
}