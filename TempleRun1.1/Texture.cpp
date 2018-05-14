#include "Texture.h"


/** 载入纹理数据 */
bool Texture::LoadRoadTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\roadtex.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

bool Texture::LoadSkyTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\sky1024.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

bool Texture::LoadGroundTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\groundtex.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

bool Texture::LoadzhuziTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\rock.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

bool Texture::LoadCoinTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\coin512.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

bool Texture::LoadSnowTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\snow512.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

bool Texture::LoadMonsterTexture()
{
	AUX_RGBImageRec* TextureImage[1];
	TextureImage[0]=auxDIBImageLoad(".\\colors.bmp");
	glGenTextures(1,&texName);
	glBindTexture(GL_TEXTURE_2D,texName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeX, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
//	glTexImage2D(GL_TEXTURE_2D,0,3,TextureImage[0]->sizeX,TextureImage[0]->sizeX,0,GL_RGB,GL_UNSIGNED_BYTE,TextureImage[0]->data);
	glEnable(GL_TEXTURE_2D);
  	return true;
}

