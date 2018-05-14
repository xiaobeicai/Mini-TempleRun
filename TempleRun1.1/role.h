#ifndef __ROLE_H__
#define __ROLE_H__

#include"Vector3.h"
class Role					
{
public:
	Vector3 m_rolePos;
	float m_speed;
	Role();
	~Role();
	void	resetRole();
	void    MoveToward(float dx,float dy,float dz);
	void    DrawRole(int angle,float jump); /**< ���ƽ�ɫ */
	void	ChangeAngle(float& angle,bool& status);			/*�ı�ڶ��Ƕ�*/
	float	legAngle[2];		/**< �ȵĵ�ǰ��ת�Ƕ� */
    float	armAngle[2];      /**< �첲�ĵ�ǰ��ת�Ƕ� */
private:
	void    DrawHead(float xPos,float yPos,float zPos);    /**< ����ͷ�� */
	void    DrawTorso(float xPos, float yPos, float zPos); /**< �������� */
	void    DrawLeg(float xPos, float yPos, float zPos);   /**< ������ */
	void    DrawArm(float xPos, float yPos, float zPos);   /**< ���Ƹ첲 */
};


#endif	// __ROLE_H__