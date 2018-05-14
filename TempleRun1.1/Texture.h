#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include"gl/glut.h"
#include"gl/GLAUX.H"
#include"gl/GL.h"
#include"gl/GLU.h"


class Texture							
{
public:
	GLuint texName;
	bool    LoadRoadTexture();                  /**< ÔØÈëÎÆÀí */
	bool	LoadSkyTexture();
	bool	LoadGroundTexture();
	bool	LoadzhuziTexture();
	bool	LoadCoinTexture();
	bool	LoadSnowTexture();
	bool	LoadMonsterTexture();
};


#endif	// __TEXTURE_H__