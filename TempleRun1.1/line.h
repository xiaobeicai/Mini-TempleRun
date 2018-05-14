#ifndef __LINE_H__
#define __LINE_H__

#include "Vector3.h"
#include <vector>
using namespace std;

/** 线段类 */
class line
{
public:
	Vector3 p1;
	Vector3 p2;
	/*构造函数*/
	line()  { p1=Vector3(0,0,0);p2=Vector3(0,0,0); }
	line(Vector3 pp1, Vector3 pp2)
	{
		p1=pp1;
		p2=pp2;
	}
	line(const line& l)
	{
		p1=l.p1;
		p2=l.p2;
	}
	/*析构函数*/
	~line(){}
};

class segment
{
public:
	vector<line> lines;

	segment();

	void add(line l)    { lines.push_back(l); }
};


#endif //__LINE_H__