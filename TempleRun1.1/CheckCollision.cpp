#include "CheckCollision.h"

//p��P1P2�ľ����Ƿ�С��r
bool CheckCollision::isIntersect(Vector3 p, float r, Vector3 p1, Vector3 p2)
{
	Vector3 v1 = p-p1;
	Vector3 v2 = p2-p1;

	// len = v2.length()
	float len = v2.length();

	// v2.normalize()
	v2 = v2.normalize();

	// u = v1.dot(v2)
	// u is the vector projection length of vector v1 onto vector v2.
	float u = v1.dotProduct(v2);

	// determine the nearest point on the lineseg
	Vector3 p0(0,0,0);
	if (u <= 0)
	{
		p0=p1;
	}
	else if (u >= len)
	{
		p0=p2;
	}
	else
	{
		p0 = p1 + v2 * u;
	}
	return p0.distance(p) <= r;
}

bool CheckCollision::lineCheckCollision(Vector3 rpos)//�Ƿ�ײ��·�ߣ�
{
	segment s;
	const float d=1.5;
	bool flag = false;
	for(unsigned int i=0; i<s.lines.size(); i++)
	{
		flag = isIntersect(rpos, d, s.lines[i].p1, s.lines[i].p2);
		if(flag == true) break;
	}
	return flag;
}

bool CheckCollision::pointCheckCollision(Vector3 rpos,Vector3 p)
{
	const float d=2.0;
	return abs(rpos.x-p.x)<d && abs(rpos.z-p.z)<d;
}