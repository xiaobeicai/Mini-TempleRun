#include "line.h"

segment::segment()
{
	add(line(Vector3(-5,0,30),Vector3(-5,0,-80)));
	add(line(Vector3(-5,0,30),Vector3(105,0,30)));
	add(line(Vector3(105,0,-80),Vector3(-5,0,-80)));
	add(line(Vector3(105,0,-80),Vector3(105,0,30)));

	add(line(Vector3(5,0,-70),Vector3(45,0,-70)));
	add(line(Vector3(5,0,-70),Vector3(5,0,-30)));
	add(line(Vector3(5,0,-30),Vector3(45,0,-30)));
	add(line(Vector3(45,0,-30),Vector3(45,0,-70)));

	add(line(Vector3(55,0,-70),Vector3(95,0,-70)));
	add(line(Vector3(55,0,-30),Vector3(95,0,-30)));
	add(line(Vector3(55,0,-70),Vector3(55,0,-30)));
	add(line(Vector3(95,0,-70),Vector3(95,0,-30)));

	add(line(Vector3(5,0,-20),Vector3(95,0,-20)));
	add(line(Vector3(5,0,20),Vector3(95,0,20)));
	add(line(Vector3(5,0,-20),Vector3(5,0,20)));
	add(line(Vector3(95,0,-20),Vector3(95,0,20)));
}
