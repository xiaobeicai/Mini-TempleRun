#ifndef  __SNOW_H__
#define  __SNOW_H__

#include "Particle.h"
#include"gl/glut.h"

/** 雪花渲染类 */
class CSnow : public CParticle
{

public:
	CSnow()  {};
	~CSnow() {};
	bool		Init(int num);  /** 初始化过程 */
	void		Render();        /**< 渲染过程 */
	void		Update();        /**< 更新过程 */
}; 

#endif //__SNOW_H__