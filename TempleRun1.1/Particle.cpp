#include "Particle.h"

CParticle::CParticle():m_iNum(0),m_pList(nullptr)
{	
}

CParticle::~CParticle()
{
	if(m_pList != nullptr)
	{
		delete []m_pList;
		m_pList = nullptr;
	}
}

/** ���ӵĳ�ʼ�� */
bool CParticle::Init(int _num)
{
	m_iNum = _num;
	m_pList = new Particle[m_iNum];
	if(m_pList == nullptr)
		return false;
	return true;
}

/** ���ӵ���Ⱦ */
void CParticle::Render()
{
}

/** ���ӵĸ��� */
void CParticle::Update()
{
}