#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Vector3.h"             
#include"gl/glut.h"

/** 摄像机类 */
class Camera
{
public:
	Camera();
	~Camera();
	
	Vector3 getPosition()   {	return m_Position;		}
	Vector3 getView()	    {	return m_View;			}
	Vector3 getUpVector()   {	return m_UpVector;		}
	static Camera* GetCamera(void) { return m_pCamera;}

	/** 设置摄像机的位置, 观察点和向上向量 参数 */
	void setCamera(float positionX, float positionY, float positionZ,
			 	   float viewX,     float viewY,     float viewZ,
				   float upVectorX, float upVectorY, float upVectorZ);

	/** 放置摄像机 */
	void setLook();

    /** 以摄像机向上为轴 旋转摄像机 */
	void yawCamera(float angle);

public:
	static Camera  *m_pCamera;      /**< 当前全局摄像机指针 */
	Vector3        m_Position;      /**< 位置 */
	Vector3        m_View;          /**< 朝向 */
	Vector3        m_UpVector;      /**< 向上向量 */
};

#endif //__CAMERA_H__