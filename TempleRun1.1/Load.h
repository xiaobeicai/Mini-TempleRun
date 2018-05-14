#ifndef __LOAD_H__
#define __LOAD_H__
#include <stdlib.h> 
#include"glm\glm.hpp"
#include<vector>
#include<string>

#define inline__inline
#define j2h(x) (3.1415926*(x)/180.0)
#define h2j(x) (180.0*(x)/3.1415926)

using namespace std;

const int SCREEN_WIDTH = 800; 
const int SCREEN_HEIGHT =800; 
const int SCREEN_BPP = 32; 
const int width = 800;
const int height = 800;

class LOAD
{
public:
	bool loadOBJ(
	const char* path,
	std::vector<glm::vec3> & out_vertices,
	std::vector<glm::vec2> & out_uvs,
	std::vector<glm::vec3> & out_normals
	);
};

#endif //__LOAD_H__