#ifndef __POINT3_H__
#define __POINT3_H__
class Point3
{
public:
	Point3();
	Point3(float xx,float yy,float zz);
	Point3(const Point3& p);
	~Point3();
	void build4tuple(float v[]);
private:
	float x;
	float y;
	float z;
};

#endif //__POINT3_H__