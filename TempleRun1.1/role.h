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
	void    DrawRole(int angle,float jump); /**< 绘制角色 */
	void	ChangeAngle(float& angle,bool& status);			/*改变摆动角度*/
	float	legAngle[2];		/**< 腿的当前旋转角度 */
    float	armAngle[2];      /**< 胳膊的当前旋转角度 */
private:
	void    DrawHead(float xPos,float yPos,float zPos);    /**< 绘制头部 */
	void    DrawTorso(float xPos, float yPos, float zPos); /**< 绘制躯干 */
	void    DrawLeg(float xPos, float yPos, float zPos);   /**< 绘制腿 */
	void    DrawArm(float xPos, float yPos, float zPos);   /**< 绘制胳膊 */
};


#endif	// __ROLE_H__