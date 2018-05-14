#include "Snow.h"
#include <cstdlib>

/** ѩ���ĳ�ʼ�� */
bool CSnow::Init(int num)
{
	/** ��ʼ��������ĿΪnum�� */
	if(CParticle::Init(num))
	{
		for(int i=0; i<m_iNum; i++)
		{
			/** ��ʼ��λ�� */
			float x,y,z,vx,vy,vz;

			x = 50.0f + 0.1f * (rand() % 550);			
			y = 15.0f + 0.1f * (rand() % 80);
			z = -25.0f + 0.1f * (rand() % 550);

			m_pList[i].position = Vector3(x,y,z);

			/** ��ʼ���ٶ� */
			vx = 0.0001 * (rand()%100);
			vy = 0.000002 * (rand()%28000);
			vz = 0.0001 * (rand()%100);
			m_pList[i].velocity = Vector3(vx,vy,vz);

			/** ��ʼ�����ٶ� */
			m_pList[i].acceleration = Vector3(0.0,0.000005f,0.0);

			/** ��ʼ����������ʱ�� */
			m_pList[i].lifetime = 100;
			
			/** ��ʼ�����ӵĳߴ� */
			m_pList[i].size = 0.01f;

			/** ��ʼ�����ӵ���ʧ�ٶ� */
			m_pList[i].dec = 0.005 * (rand()%50);

			/** ��ʼ�����ӵ���ɫ */
			m_pList[i].color[0] = 255;
			m_pList[i].color[1] = 255;
			m_pList[i].color[2] = 255;

		}
		return true;
	}
	else
		return false;
}

/** ѩ������Ⱦ */
void CSnow::Render()
{
	/** ������ */
	
	/** ��ʼ��Ⱦѩ�� */
	for(int i=0; i<m_iNum; ++i)
	{
		float x = m_pList[i].position.x;
		float y = m_pList[i].position.y;
		float z = m_pList[i].position.z;
		float size = m_pList[i].size;

		/** �����������ʧ���������������� */
		if (y <= -1 || m_pList[i].lifetime <= 0)
			break;
		
		glColor3fv(m_pList[i].color);
		glNormal3f(0.0f,0.0f,1.0f);     /**< ���巨�߷��� */
		
		/** �������� */
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f,0.0f);glVertex3f(x-size,y-size,z);
			glTexCoord2f(1.0f,0.0f);glVertex3f(x-size,y+size,z);
			glTexCoord2f(1.0f,1.0f);glVertex3f(x+size,y+size,z);
			glTexCoord2f(0.0f,1.0f);glVertex3f(x+size,y-size,z);
		glEnd();
				
	}
	
	/** ������������ */
	Update();
}

/** ѩ���ĸ��� */
void CSnow::Update()
{
	for(int i = 0; i<m_iNum; ++i)
	{
		/** ����λ�� */
		m_pList[i].position.x += m_pList[i].velocity.x * 5;
		m_pList[i].position.y -= m_pList[i].velocity.y;
		if(m_pList[i].position.x > 105.0)
			m_pList[i].position.x = -5.0;
		if(m_pList[i].position.z > 30.0)
			m_pList[i].position.x = -80.0;

		/** �����ٶ� */
		m_pList[i].velocity.y += m_pList[i].acceleration.y;

		/** ��������ʱ�� */
		m_pList[i].lifetime -= m_pList[i].dec;

		/** ���������ʧ���������� */
		if (m_pList[i].position.y <= -1 || m_pList[i].lifetime <= 0)
		{
			/** ��ʼ��λ�� */
			float x,y,z,vx,vy,vz;
			x = 50.0f + 0.1f * (rand() % 550);			
			y = 15.0f + 0.1f * (rand() % 80);
			z = -25.0f + 0.1f * (rand() % 550);
			m_pList[i].position = Vector3(x,y,z);

			/** ��ʼ���ٶ� */
			vx = 0.0001 * (rand()%100);
			vy = 0.000002 * (rand()%28000);
			vz = 0.0001 * (rand()%100);
			m_pList[i].velocity = Vector3(vx,vy,vz);

			/** ��ʼ�����ٶ� */
			m_pList[i].acceleration = Vector3(0.0,0.000005f,0.0);

			/** ��ʼ������ʱ�� */
			m_pList[i].lifetime = 100;

			/** ��ʼ����ʧ�ٶ� */
			m_pList[i].dec = 0.005*(rand()%50);
		}

	}
	
}
