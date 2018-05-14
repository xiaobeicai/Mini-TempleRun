#include "Snow.h"
#include <cstdlib>

/** 雪花的初始化 */
bool CSnow::Init(int num)
{
	/** 初始化粒子数目为num个 */
	if(CParticle::Init(num))
	{
		for(int i=0; i<m_iNum; i++)
		{
			/** 初始化位置 */
			float x,y,z,vx,vy,vz;

			x = 50.0f + 0.1f * (rand() % 550);			
			y = 15.0f + 0.1f * (rand() % 80);
			z = -25.0f + 0.1f * (rand() % 550);

			m_pList[i].position = Vector3(x,y,z);

			/** 初始化速度 */
			vx = 0.0001 * (rand()%100);
			vy = 0.000002 * (rand()%28000);
			vz = 0.0001 * (rand()%100);
			m_pList[i].velocity = Vector3(vx,vy,vz);

			/** 初始化加速度 */
			m_pList[i].acceleration = Vector3(0.0,0.000005f,0.0);

			/** 初始化粒子生命时间 */
			m_pList[i].lifetime = 100;
			
			/** 初始化粒子的尺寸 */
			m_pList[i].size = 0.01f;

			/** 初始化粒子的消失速度 */
			m_pList[i].dec = 0.005 * (rand()%50);

			/** 初始化粒子的颜色 */
			m_pList[i].color[0] = 255;
			m_pList[i].color[1] = 255;
			m_pList[i].color[2] = 255;

		}
		return true;
	}
	else
		return false;
}

/** 雪花的渲染 */
void CSnow::Render()
{
	/** 绑定纹理 */
	
	/** 开始渲染雪花 */
	for(int i=0; i<m_iNum; ++i)
	{
		float x = m_pList[i].position.x;
		float y = m_pList[i].position.y;
		float z = m_pList[i].position.z;
		float size = m_pList[i].size;

		/** 如果该粒子消失或生命结束则跳出 */
		if (y <= -1 || m_pList[i].lifetime <= 0)
			break;
		
		glColor3fv(m_pList[i].color);
		glNormal3f(0.0f,0.0f,1.0f);     /**< 定义法线方向 */
		
		/** 画出粒子 */
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f);glVertex3f(x-size,y-size,z);
			glTexCoord2f(1.0f,0.0f);glVertex3f(x-size,y+size,z);
			glTexCoord2f(1.0f,1.0f);glVertex3f(x+size,y+size,z);
			glTexCoord2f(0.0f,1.0f);glVertex3f(x+size,y-size,z);
		glEnd();
				
	}
	
	/** 更新粒子属性 */
	Update();
}

/** 雪花的更新 */
void CSnow::Update()
{
	for(int i = 0; i<m_iNum; ++i)
	{
		/** 更新位置 */
		m_pList[i].position.x += m_pList[i].velocity.x * 5;
		m_pList[i].position.y -= m_pList[i].velocity.y;
		if(m_pList[i].position.x > 105.0)
			m_pList[i].position.x = -5.0;
		if(m_pList[i].position.z > 30.0)
			m_pList[i].position.x = -80.0;

		/** 更新速度 */
		m_pList[i].velocity.y += m_pList[i].acceleration.y;

		/** 更新生存时间 */
		m_pList[i].lifetime -= m_pList[i].dec;

		/** 如果粒子消失或生命结束 */
		if (m_pList[i].position.y <= -1 || m_pList[i].lifetime <= 0)
		{
			/** 初始化位置 */
			float x,y,z,vx,vy,vz;
			x = 50.0f + 0.1f * (rand() % 550);			
			y = 15.0f + 0.1f * (rand() % 80);
			z = -25.0f + 0.1f * (rand() % 550);
			m_pList[i].position = Vector3(x,y,z);

			/** 初始化速度 */
			vx = 0.0001 * (rand()%100);
			vy = 0.000002 * (rand()%28000);
			vz = 0.0001 * (rand()%100);
			m_pList[i].velocity = Vector3(vx,vy,vz);

			/** 初始化加速度 */
			m_pList[i].acceleration = Vector3(0.0,0.000005f,0.0);

			/** 初始化生命时间 */
			m_pList[i].lifetime = 100;

			/** 初始化消失速度 */
			m_pList[i].dec = 0.005*(rand()%50);
		}

	}
	
}
