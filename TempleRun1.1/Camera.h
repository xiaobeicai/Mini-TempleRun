#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Vector3.h"             
#include"gl/glut.h"

/** ������� */
class Camera
{
public:
	Camera();
	~Camera();
	
	Vector3 getPosition()   {	return m_Position;		}
	Vector3 getView()	    {	return m_View;			}
	Vector3 getUpVector()   {	return m_UpVector;		}
	static Camera* GetCamera(void) { return m_pCamera;}

	/** �����������λ��, �۲����������� ���� */
	void setCamera(float positionX, float positionY, float positionZ,
			 	   float viewX,     float viewY,     float viewZ,
				   float upVectorX, float upVectorY, float upVectorZ);

	/** ��������� */
	void setLook();

    /** �����������Ϊ�� ��ת����� */
	void yawCamera(float angle);

public:
	static Camera  *m_pCamera;      /**< ��ǰȫ�������ָ�� */
	Vector3        m_Position;      /**< λ�� */
	Vector3        m_View;          /**< ���� */
	Vector3        m_UpVector;      /**< �������� */
};

#endif //__CAMERA_H__