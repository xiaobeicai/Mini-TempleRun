#ifndef __VECTOR3_H__
#define __VECTOR3_H__

/** 向量类 */
class Vector3
{
public:
	float x;
	float y;
	float z;
	/** 构造函数 */
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
    
	/** 成员函数 */
	inline float length();                       /**< 计算向量长度 */
	Vector3 normalize();                         /**< 单位化向量 */
	float dotProduct(const Vector3& v);          /**< 计算点积 */
	Vector3 crossProduct(const Vector3& v);      /**< 计算叉积 */
	float distance(const Vector3& v);            /**< 计算两点间距离 */

	/** 重载操作符 */
	Vector3 operator + (const Vector3& v);
	Vector3 operator - (const Vector3& v);
	Vector3 operator * (float scale);
	Vector3 operator / (float scale);
	Vector3 operator - ();

};

#endif //__VECTOR3_H__