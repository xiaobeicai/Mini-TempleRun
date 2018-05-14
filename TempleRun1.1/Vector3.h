#ifndef __VECTOR3_H__
#define __VECTOR3_H__

/** ������ */
class Vector3
{
public:
	float x;
	float y;
	float z;
	/** ���캯�� */
	Vector3()  { x = 0.0; y = 0.0; z = 0.0; }
	Vector3( float xx, float yy, float zz)
	{
		x = xx;
		y = yy;
		z = zz;
	}
	Vector3(const Vector3& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
	~Vector3(){}
    
	/** ��Ա���� */
	inline float length();                       /**< ������������ */
	Vector3 normalize();                         /**< ��λ������ */
	float dotProduct(const Vector3& v);          /**< ������ */
	Vector3 crossProduct(const Vector3& v);      /**< ������ */
	float distance(const Vector3& v);            /**< ������������ */

	/** ���ز����� */
	Vector3 operator + (const Vector3& v);
	Vector3 operator - (const Vector3& v);
	Vector3 operator * (float scale);
	Vector3 operator / (float scale);
	Vector3 operator - ();

};

#endif //__VECTOR3_H__