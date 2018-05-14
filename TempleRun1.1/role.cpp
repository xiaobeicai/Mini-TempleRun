#include "role.h"
#include"gl/glut.h"
static GLfloat role_specular[] = { 0.1, 0.1, 0.1, 1.0 };
static GLfloat role_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
static GLfloat role_shininess[] = {1.0};

static GLfloat head_ambient[] = { 1.0, 0.41, 0.71, 1.0 };
static GLfloat arm_ambient[] = { 1.0, 0.0, 0.0, 1.0 };
static GLfloat torso_ambient[] = { 0.0, 0.0, 1.0, 1.0 };
static GLfloat leg_ambient[] = { 1.0, 1.0, 0.0, 1.0 };


Role::Role()
{
	legAngle[0] = legAngle[1] = 0.0f;				
	armAngle[0] = armAngle[1] = 0.0f;
	m_rolePos.x = 0.0f;
	m_rolePos.y = 0.0f;
	m_rolePos.z = 0.0f;
	m_speed = 0.05f;
}

Role::~Role()
{
}

void Role::resetRole()
{
	legAngle[0] = legAngle[1] = 0.0f;				
	armAngle[0] = armAngle[1] = 0.0f;
	m_rolePos.x = 0.0f;
	m_rolePos.y = 0.0f;
	m_rolePos.z = 0.0f;
	m_speed = 0.05f;
}
void Role::MoveToward(float dx,float dy,float dz)
{
	m_rolePos.x += dx * m_speed;
	m_rolePos.y += dy * m_speed;
	m_rolePos.z += dz * m_speed;
}
void Role::DrawArm(float xPos, float yPos, float zPos)
{
	glPushMatrix();
	    glColor3f(1.0f, 0.0f, 0.0f);    /**< ��ɫ */	
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f, 4.0f, 1.0f);	    /**< �ֱ���1x4x1�������� */
		glutSolidCube(1.0);
	glPopMatrix();
}
void Role::DrawHead(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);	/**< ��ɫ */
		glTranslatef(xPos, yPos, zPos);
		glScalef(2.0f, 2.0f, 2.0f);		/**<ͷ���� 2x2x2������ */
		glutSolidCube(1.0);
	glPopMatrix();
}
void Role::DrawTorso(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);	 /**< ��ɫ */
		glTranslatef(xPos, yPos, zPos);
		glScalef(3.0f, 5.0f, 2.0f);	     /**< ������3x5x2�ĳ����� */
		glutSolidCube(1.0);
	glPopMatrix();
}
void Role::DrawLeg(float xPos, float yPos, float zPos)
{
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);	/**< ��ɫ */
		glTranslatef(xPos, yPos, zPos);
		glScalef(1.0f, 5.0f, 1.0f);		/**< ����1x5x1������ */
		glutSolidCube(1.0);
	glPopMatrix();
}
void Role::ChangeAngle(float& angle,bool& status)
{
	if(status) angle += 0.5;
	else angle -= 0.5;

	if(angle >= 15.0f) status = false;
	if(angle <= -15.0f) status = true;
}
void Role::DrawRole(int angle,float jump)
{
	glPushMatrix();	
		glTranslatef(m_rolePos.x,m_rolePos.y,m_rolePos.z);	/**< ��λ */
//?		glTranslatef(-1.0f,2.5f,0.0f);

//		glRotatef(-15.0,1.0f,0.0f,0.0f);//��б����
		glTranslatef(0.0,jump,0.0);
		glRotatef(angle,0.0f,1.0f,0.0f);
//		glutSolidSphere(0.5,20,20);//?
//		glTranslatef(0.0,jump,0.0);
	    ///���Ƹ�������
		glMaterialfv(GL_FRONT, GL_DIFFUSE, role_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, role_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, role_shininess);
//?		DrawHead(1.0f, 1.0f, -1.0f);     /**< ����ͷ�� */	
		glMaterialfv(GL_FRONT, GL_AMBIENT, head_ambient);
		DrawHead(0.0f, 3.5f, -1.0f); 
//		glutSolidSphere(0.5,20,20);
//?		DrawTorso(1.0f, -2.5f, -1.0f);   /**< �������� */
		glMaterialfv(GL_FRONT, GL_AMBIENT, torso_ambient);
		DrawTorso(0.0f, 0.0f, -1.0f);
		
		///���Ƹ첲
		glPushMatrix();
			///ƽ�Ʋ���ת����Ƹ첲
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);
//			DrawArm(3.0f, -2.0f, -1.0f);
			glMaterialfv(GL_FRONT, GL_AMBIENT, arm_ambient);
			DrawArm(2.0f, 0.5f, -1.0f);
		glPopMatrix();

		///ͬ��arm0
		glPushMatrix();
		
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);
//?			DrawArm(-1.0f, -2.0f, -1.0f);
			DrawArm(-2.0f, 0.5f, -1.0f);
		glPopMatrix();

		///�����Ȳ�
		glPushMatrix();					

			///ƽ�Ʋ���ת����Ƹ첲
			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(legAngle[0], 1.0f, 0.0f, 0.0f);
//?			DrawLeg(0.0f, -7.5f, -1.0f);
			glMaterialfv(GL_FRONT, GL_AMBIENT, leg_ambient);
			DrawLeg(-1.0f, -5.0f, -1.0f);

		glPopMatrix();

		///ͬ��leg1
		glPushMatrix();

			glTranslatef(0.0f, -0.5f, 0.0f);
			glRotatef(legAngle[1], 1.0f, 0.0f, 0.0f);
//?			DrawLeg(2.0f, -7.5f, -1.0f);
			DrawLeg(1.0f, -5.0f, -1.0f);
		glPopMatrix();
	glPopMatrix();
}