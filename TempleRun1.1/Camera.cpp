#include<iostream>
#include"gl/glut.h"
#include<cmath>
#include "Camera.h"                    /**< 包含摄像机头文件 */
#include "Vector3.h"                    /**< 包含向量类 */

const double PI = 3.14159265;
Camera* Camera::m_pCamera = NULL;
Camera::Camera()
{
//	m_Position	= Vector3(0.0, 3.0, 10.0);	
	m_Position  = Vector3(0.0, 15.0, 20.0);
//	m_View		= Vector3(0.0, 0.0, -10.0);		
	m_View		= Vector3(0.0, -6.0, -70.0);
	m_UpVector	= Vector3(0.0, 1.0, 0.0);
//	m_UpVector	= Vector3(0.0, 10.0, -3.0);
	m_pCamera = this;
}
Camera::~Camera()
{
}

/** 设置摄像机的位置,朝向和向上向量 */
void Camera::setCamera( float positionX, float positionY, float positionZ,
				  		float viewX,     float viewY,     float viewZ,
						float upVectorX, float upVectorY, float upVectorZ)
{
	m_Position = Vector3(positionX, positionY, positionZ);
	m_View     = Vector3(viewX, viewY, viewZ);		
	m_UpVector = Vector3(upVectorX, upVectorY, upVectorZ);
}
/** 设置视点 */
void Camera::setLook()
{
	gluLookAt(m_Position.x, m_Position.y, m_Position.z,	
			  m_View.x,	 m_View.y,     m_View.z,	
			  m_UpVector.x, m_UpVector.y, m_UpVector.z);
}
void Camera::yawCamera(float angle)
{
	float cosValue = cos(angle * PI / 180.0);
	float sinValue = sin(angle * PI / 180.0);

//	float viewX = m_View.x * cosValue - m_View.z * sinValue;
//	float viewZ = m_View.z * cosValue + m_View.x * sinValue;	
//	m_View.x = viewX;
//	m_View.z = viewZ;

	


	this->setLook();
}