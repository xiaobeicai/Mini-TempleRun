#ifndef  __SNOW_H__
#define  __SNOW_H__

#include "Particle.h"
#include"gl/glut.h"

/** ѩ����Ⱦ�� */
class CSnow : public CParticle
{

public:
	CSnow()  {};
	~CSnow() {};
	bool		Init(int num);  /** ��ʼ������ */
	void		Render();        /**< ��Ⱦ���� */
	void		Update();        /**< ���¹��� */
}; 

#endif //__SNOW_H__