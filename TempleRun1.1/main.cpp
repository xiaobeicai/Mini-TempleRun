#include"gl/glut.h"
#include<iostream>
#include<cmath>
#include "role.h"
#include "Camera.h"
#include "Load.h"
#include "Texture.h"
#include "CheckCollision.h"
#include "Font.h"
#include "Snow.h"
#include <mmsystem.h>

#pragma comment(lib, "GLAUX.lib")
#pragma comment(lib, "Winmm.lib")

using namespace std;

const double PI = 3.1415926;
static Role myrole;
static bool leg1 = true;		/**< 机器人腿的状态，true向前，flase向后 */
static bool leg2 = false;		
static bool arm1 = true;
static bool arm2 = false;
static Vector3 coinpos[4] = {Vector3(50,0,25),Vector3(0,0,-50),Vector3(100,0,-50),Vector3(100,0,0)};
static Vector3 reshowpos(50,0,-25);
static bool showcoin[4] = {true,true,true,true};
static bool getcoin = false;
static int totalcoins = 0;
static float addspeed = 0.0;
static GLint heading = 180;//ZX平面方向角，从Z轴开始，往X轴转
static GLint turn = 0;
static GLfloat jump = 0.0f;
//static GLfloat currentMatrix[16];
static Camera camera;
static float dis = 20.0f;
static float dis2 = 60.0f;
static bool renderstop = false;
static LOAD myload;
static Texture roadTex;
static Texture skyTex;
static Texture groundTex;
static Texture zhuziTex;
static Texture coinTex;
static Texture snowTex;//
static Texture monsterTex;
static CSnow mysnow;
static CheckCollision mycheck;
static GLFont myfont;
static bool keyPress = false;
vector<glm::vec3> vertices[10];
vector<glm::vec2> uvs[10];
vector<glm::vec3> normals[10];

static GLfloat light0_ambinet[] = {1.0,1.0,1.0,1.0};
static GLfloat light0_diffuse[] = {1.0,1.0,1.0,1.0};
static GLfloat light0_specular[] = {0.5,0.5,0.5,1.0};
static GLfloat light0_position[] = {1000.0,1000.0,1000.0,1.0};
static GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
static GLfloat mat_diffuse[] = { 0.2, 0.2, 0.2, 1.0 };
static GLfloat mat_specular[] = { 0.2, 0.2, 0.2, 1.0 };
static GLfloat mat_shininess[] = {1.0};
static GLfloat road_ambient[] = {1.0,1.0,1.0,1.0};
static GLfloat road_diffuse[] = {1.0,1.0,1.0,1.0};
static GLfloat road_specular[] = {0.2,0.2,0.2,1.0};
static GLfloat wall_ambient[] = {0.5,0.5,0.5,1.0};
static GLfloat wall_diffuse[] = {1.0,1.0,1.0,1.0};
static GLfloat wall_specular[] = {0.2,0.2,0.2,1.0};


void init(void)
{

	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);											
	glDepthFunc(GL_LEQUAL);										
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0,GL_AMBIENT,light0_ambinet);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light0_diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,light0_specular);
	glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	
	myload.loadOBJ(".\\sky.obj", vertices[0], uvs[0], normals[0]);
	myload.loadOBJ(".\\ground.obj", vertices[1], uvs[1], normals[1]);
	myload.loadOBJ(".\\zhuzi.obj", vertices[2], uvs[2], normals[2]);
	myload.loadOBJ(".\\coin10.obj", vertices[3], uvs[3], normals[3]);
	myload.loadOBJ(".\\monster.obj", vertices[4], uvs[4], normals[4]);
	roadTex.LoadRoadTexture();
	skyTex.LoadSkyTexture();
	zhuziTex.LoadzhuziTexture();
	groundTex.LoadGroundTexture();
	coinTex.LoadCoinTexture();
	snowTex.LoadSnowTexture();
	//monsterTex.LoadMonsterTexture();
	mysnow.Init(1000);

//		for(unsigned int i = 0; i<vertices[3].size(); i++) 
//		{ 
//			cout<< vertices[3][i].x <<" "<<vertices[3][i].y << " "<<vertices[3][i].z << endl;; 
//		}
	/** 初始化字体 */
	if(!myfont.InitFont())
		MessageBox(NULL,"初始化字体失败!","错误",MB_OK);

	cout << "游戏操作指南：" << endl;
	cout << "←: turn left" << endl;
	cout << "→: turn right" << endl;
	cout << "↑: jump to get coins" << endl;
	cout << "Z/z: zoom out" << endl;
	cout << "X/x: zoom in" << endl;
	cout << "C/c: speed up" << endl;
	cout << "V/v: speed down" << endl;
	cout << "P/p: Pause" << endl; 
	cout << "R/r: Restart Game" << endl;
	cout << "Esc: exit" << endl;
	cout << "tip1: 随着金币数的增加，角色速度会不断增加" << endl;
	cout << "tip2: 角色跑到地图中央，会重新刷新金币"<< endl;
	PlaySound(".\\music.wav", NULL, SND_SYNC | SND_FILENAME | SND_ASYNC);
}
double angle2Radian(GLint angle)
{
	return angle * PI /180.0;
}
void resetCamera()
{
	camera.m_Position.x = myrole.m_rolePos.x - dis * sin(angle2Radian(heading));
	camera.m_Position.y = myrole.m_rolePos.y + 15.0;
	camera.m_Position.z = myrole.m_rolePos.z - dis * cos(angle2Radian(heading));

	camera.m_View.x = myrole.m_rolePos.x + dis2 * sin(angle2Radian(heading));
	camera.m_View.y = myrole.m_rolePos.y - 6.0;
	camera.m_View.z = myrole.m_rolePos.z + dis2 * cos(angle2Radian(heading));

}
void drawRoad()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,roadTex.texName);
		glTranslatef(0.0f,-7.5f,0.0f);
		glColor3f(1.0f,1.0f,1.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, road_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, road_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, road_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glBegin(GL_QUADS);
			glNormal3f(0.0f,0.0f,1.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(-5.0f,0.0f,30.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,0.0f,30.0f);
			glTexCoord2f(1.0f, 11.0f);	glVertex3f(5.0f,0.0f,-80.0f);
			glTexCoord2f(0.0f, 11.0f);	glVertex3f(-5.0f,0.0f,-80.0f);

			glNormal3f(0.0f,0.0f,1.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(5.0f,0.0f,-80.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,0.0f,-70.0f);
			glTexCoord2f(1.0f, 9.0f);	glVertex3f(95.0f,0.0f,-70.0f);
			glTexCoord2f(0.0f, 9.0f);	glVertex3f(95.0f,0.0f,-80.0f);

			
			glNormal3f(0.0f,0.0f,1.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(5.0f,0.0f,20.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,0.0f,30.0f);
			glTexCoord2f(1.0f, 9.0f);	glVertex3f(95.0f,0.0f,30.0f);
			glTexCoord2f(0.0f, 9.0f);	glVertex3f(95.0f,0.0f,20.0f);


			glNormal3f(0.0f,0.0f,1.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(95.0f,0.0f,30.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(105.0f,0.0f,30.0f);
			glTexCoord2f(1.0f, 11.0f);	glVertex3f(105.0f,0.0f,-80.0f);
			glTexCoord2f(0.0f, 11.0f);	glVertex3f(95.0f,0.0f,-80.0f);

			glNormal3f(0.0f,0.0f,1.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(5.0f,0.0f,-30.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(5.0f,0.0f,-20.0f);
			glTexCoord2f(1.0f, 9.0f);	glVertex3f(95.0f,0.0f,-20.0f);
			glTexCoord2f(0.0f, 9.0f);	glVertex3f(95.0f,0.0f,-30.0f);


			glNormal3f(0.0f,0.0f,1.0f);
			glTexCoord2f(0.0f, 0.0f);	glVertex3f(45.0f,0.0f,-30.0f);
			glTexCoord2f(1.0f, 0.0f);	glVertex3f(55.0f,0.0f,-30.0f);
			glTexCoord2f(1.0f, 4.0f);	glVertex3f(55.0f,0.0f,-70.0f);
			glTexCoord2f(0.0f, 4.0f);	glVertex3f(45.0f,0.0f,-70.0f);
		glEnd();	

	glPopMatrix();
}
/*
void drawBonus()
{
	glPushMatrix();
		glColor3f(1.0,1.0,0.0);
		glPushMatrix();

		glTranslatef(0.0f,8.5f,-20.0f);
		GLUquadric *pObj; 
		pObj = gluNewQuadric();
		gluCylinder(pObj,2.0f,2.0f,0.4f,32,32);
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(0.0f,0.0f,0.0f);
		for(int i=0;i<33;i++)
		{
			glVertex3f(2.0*cos(2*PI/32*i),2.0*sin(2*PI/32*i),0.0f);
		}
		glEnd();
		glPopMatrix();

	glPopMatrix();

}
*/
void drawCoin()
{
	glBindTexture(GL_TEXTURE_2D,coinTex.texName);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	if(showcoin[0])
	{
	glPushMatrix();
		glTranslatef(50.0f,10.0f,25.0f);
		glRotatef(90.0,0.0,1.0,0.0);
		glColor3f(0.0f, 1.0f, 1.0f); 
		glBegin(GL_TRIANGLES); 
		for(unsigned int i = 0; i<vertices[3].size(); i++) 
		{ 
			glNormal3f( normals[3][i].x, normals[3][i].y, normals[3][i].z); 
			glTexCoord2f(uvs[3][i].x,uvs[3][i].y);
			glVertex3f( vertices[3][i].x, vertices[3][i].y,vertices[3][i].z); 
		}
		glEnd(); 
	glPopMatrix();
	}

	if(showcoin[1])
	{
	glPushMatrix();
		glTranslatef(0.0f,10.0f,-50.0f);
		glBegin(GL_TRIANGLES); 	
		for(unsigned int i = 0; i<vertices[3].size(); i++) 
		{ 
			glNormal3f( normals[3][i].x, normals[3][i].y, normals[3][i].z); 
			glTexCoord2f(uvs[3][i].x,uvs[3][i].y);
			glVertex3f( vertices[3][i].x, vertices[3][i].y,vertices[3][i].z); 
		}
		glEnd(); 
	glPopMatrix();
	}

	if(showcoin[2])
	{
	glPushMatrix();
		glTranslatef(100.0f,10.0f,-50.0f);
		glBegin(GL_TRIANGLES); 	
		for(unsigned int i = 0; i<vertices[3].size(); i++) 
		{ 
			glNormal3f( normals[3][i].x, normals[3][i].y, normals[3][i].z); 
			glTexCoord2f(uvs[3][i].x,uvs[3][i].y);
			glVertex3f( vertices[3][i].x, vertices[3][i].y,vertices[3][i].z); 
		}
		glEnd(); 
	glPopMatrix();
	}

	if(showcoin[3])
	{
	glPushMatrix();
		glTranslatef(100.0f,10.0f,0.0f);
		glBegin(GL_TRIANGLES); 	
		for(unsigned int i = 0; i<vertices[3].size(); i++) 
		{ 
			glNormal3f( normals[3][i].x, normals[3][i].y, normals[3][i].z); 
			glTexCoord2f(uvs[3][i].x,uvs[3][i].y);
			glVertex3f( vertices[3][i].x, vertices[3][i].y,vertices[3][i].z); 
		}
		glEnd(); 
	glPopMatrix();
	}
}


void drawsky()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D,skyTex.texName);
		glColor3f(0.0f, 1.0f, 1.0f); 
		glTranslatef(0.0f,-30000.0f,0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glBegin(GL_TRIANGLES); //画三角形	

		for(unsigned int i = 0; i<vertices[0].size(); i++) 
		{ 
			glNormal3f( normals[0][i].x, normals[0][i].y, normals[0][i].z); 
			glTexCoord2f(uvs[0][i].x,uvs[0][i].y);
			glVertex3f( vertices[0][i].x, vertices[0][i].y,vertices[0][i].z); 
		}
		glEnd(); 
	glPopMatrix();

}

void drawground()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,groundTex.texName);
	glTranslatef(0.0f,-15.0f,0.0f);//-7.5
//	glScalef(0.0001,0.0001,0.0001);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glBegin(GL_TRIANGLES); //画三角形	
		for(unsigned int i = 0; i<vertices[1].size(); i++) 
		{ 
			glNormal3f( normals[1][i].x, normals[1][i].y, normals[1][i].z); 
			glTexCoord2f(0.00001*uvs[1][i].x,0.00001*uvs[1][i].y);
			glVertex3f( vertices[1][i].x, vertices[1][i].y,vertices[1][i].z); 
		}

		glEnd(); 
	glPopMatrix();
}

void drawzhuzi()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,zhuziTex.texName);
	glTranslatef(25.0f,12.0f,-50.0f);
	glScalef(0.6f,0.2f,0.6f);
//	glScalef(0.1,0.1,0.1);
//	glTranslatef(0.0f,-7.5f,0.0f);//-7.5
//		glScalef(0.0001,0.0001,0.0001);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glBegin(GL_TRIANGLES); //画三角形	
		for(unsigned int i = 0; i<vertices[2].size(); i++) 
		{ 
			glNormal3f( normals[2][i].x, normals[2][i].y, normals[2][i].z); 
			glTexCoord2f(uvs[2][i].x,uvs[2][i].y);
			glVertex3f( vertices[2][i].x, vertices[2][i].y,vertices[2][i].z); 
		}

		glEnd(); 
	glPopMatrix();

}


void drawWall()
{

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, wall_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, wall_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, wall_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glColor3f(0.0f,1.0f,0.0f);
	glTranslatef(0.0f,-7.5f,0.0f);
		glPushMatrix();
		glTranslatef(-5.5f,5.0f,-25.0f);
		glScalef(1.0f,10.0f,110.0f);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(105.5f,5.0f,-25.0f);
		glScalef(1.0f,10.0f,110.0f);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(50.0f,5.0f,30.5f);
		glScalef(112.0f,10.0f,1.0f);
		glutSolidCube(1.0);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(50.0f,5.0f,-80.5f);
		glScalef(112.0f,10.0f,1.0f);
		glutSolidCube(1.0);
		glPopMatrix();

	glPopMatrix();
}

void drawSnow()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,snowTex.texName);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		mysnow.Render();
	glPopMatrix();
}
void drawMonster()
{
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,monsterTex.texName);
		glColor3f(0.0f, 1.0f, 1.0f); 
		glTranslatef(0.0f,-30000.0f,0.0f);
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		glBegin(GL_TRIANGLES); //画三角形	

		for(unsigned int i = 0; i<vertices[4].size(); i++) 
		{ 
			glNormal3f( normals[4][i].x, normals[4][i].y, normals[4][i].z); 
			glTexCoord2f(uvs[4][i].x,uvs[4][i].y);
			glVertex3f( vertices[4][i].x, vertices[4][i].y,vertices[4][i].z); 
		}
		glEnd(); 
	glPopMatrix();

}

void Die()
{
	if(mycheck.lineCheckCollision(myrole.m_rolePos) == true)
	{
//		cout << "Game over！" << endl;
		//renderstop = true;
		myfont.PrintText("Game Over!", -2.0f,0.0f); 
//		cout << "Press R/r to restart the game!" << endl;
		myfont.PrintText("Press R/r to restart the game!", -6.5f,-2.0f); 
	}
}

void getCoins()
{
	for(int i=0;i<4;i++)
	{
		if(mycheck.pointCheckCollision(myrole.m_rolePos,coinpos[i])&&showcoin[i] == true)
		{
			showcoin[i] = false;
			getcoin = true;
		}
	}
}

void addCoins()
{
	if(getcoin == true)
	{
		getcoin = false;
		totalcoins += 1;
		myrole.m_speed += 0.01;
		if(myrole.m_speed < 0.03) myrole.m_speed = 0.03;
		if(myrole.m_speed > 0.5) myrole.m_speed = 0.5;
		cout << "get one coin!"<< endl;
		cout<< "total coins " << totalcoins << endl;
	}
}

void showFont()
{
	char ch[20];
	glPushAttrib(GL_CURRENT_BIT);                   /**< 保存现有颜色属性信息 */
	glColor3f(65.0f,105.0f,230.0f);                  /**< 设置文字颜色 */
	sprintf_s(ch,"金币数:%1.0d",totalcoins);        /**< 字符串赋值 */
//	myfont.PrintText("金币金额", -7.5f,7.0f);        /**< 输出字符串 */
	myfont.PrintText(ch, -7.5f,7.0f); 
	glPopAttrib();
}



void reshowCoin()
{
	if(mycheck.pointCheckCollision(myrole.m_rolePos,reshowpos))
	{
		showcoin[0] = true;
		showcoin[1] = true;
		showcoin[2] = true;
		showcoin[3] = true;
	}
}

void restartGame()
{
	myrole.resetRole();
	totalcoins = 0;
}




void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	resetCamera();
	glLoadIdentity();
	camera.setLook();


	glPushMatrix();
		drawsky();
	glPopMatrix();

	glPushMatrix();
		//drawground();
	glPopMatrix();

	glPushMatrix();
		drawRoad();
	glPopMatrix();

	glPushMatrix();
		drawzhuzi();
	glPopMatrix();


	glPushMatrix();
		drawWall();
	glPopMatrix();

	glPushMatrix();
		drawCoin();
	glPopMatrix();

	glPushMatrix();
		drawSnow();
	glPopMatrix();

	glPushMatrix();
		drawMonster();
	glPopMatrix();

	glPushMatrix();
		myrole.ChangeAngle(myrole.armAngle[0],arm1);
		myrole.ChangeAngle(myrole.armAngle[1],arm2);
		myrole.ChangeAngle(myrole.legAngle[0],leg1);
		myrole.ChangeAngle(myrole.legAngle[1],leg2);
		myrole.DrawRole(heading-180,jump);
	glPopMatrix();
	showFont();
	Die();
	reshowCoin();
	glutSwapBuffers();
	myrole.MoveToward(sin(angle2Radian(heading)),0.0,cos(angle2Radian(heading)));

	if(!renderstop)
	glutPostRedisplay();

}
void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(78.0,(GLdouble)w/(GLdouble)h,0.01,999999);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.setLook();
}

void keyboard(unsigned char key,int x,int y)
{
	if(!keyPress)
	switch (key)
	{
	case 'z':
	case 'Z':
		dis += 5.0f;
		if(dis > 30.0f) dis = 30.0f;
		keyPress = true;
		break;
	case 'x':
	case 'X':
		dis -= 5.0f;
		if(dis < 15.0f) dis = 15.0f;
		keyPress = true;
		break;
	case 'p':
	case 'P':
		renderstop = !renderstop;
		if(!renderstop)
			glutPostRedisplay();
		keyPress = true;
		break;
	case 'c':
	case 'C':
		addspeed = 0.01;
		keyPress = true;
		break;
	case 'v':
	case 'V':
		addspeed = -0.01;
		keyPress = true;
		break;
	case 'r':
	case 'R':
		restartGame();
		keyPress = true;
		break;
	case 27:
		exit(0);
		keyPress = true;
		break;
	default:
		keyPress = true;
		break;
	}
}

void upkeyboard(unsigned char key,int x,int y)
{
	switch (key)
	{
	case 'c':
	case 'C':
	case 'v':
	case 'V':
		myrole.m_speed += addspeed;
		if(myrole.m_speed < 0.03) myrole.m_speed = 0.03;
		if(myrole.m_speed > 0.5) myrole.m_speed = 0.5;
		keyPress = false;
		break;
	default:
		keyPress = false;
		break;
	}

}


void specialKeys(int key,int x,int y)//键盘方向键
{
	if(keyPress) jump = 0.0f;
	if(!keyPress)
	switch (key)
	{
		case GLUT_KEY_LEFT:
			turn = 90;
			heading += turn;
			keyPress = true;
			break;
		case GLUT_KEY_RIGHT:
			turn = -90;
			heading += turn;
			keyPress = true;
			break;
		case GLUT_KEY_UP:
			jump = 8.5f;
			getCoins();
			addCoins();
			keyPress = true;
			break;
	default:
		keyPress = true;
		break;
	}
}

void upSpecialKeyboard(int key,int x,int y)//按键松开
{
		switch (key)
	{
		case GLUT_KEY_LEFT:
			turn = 0;
			keyPress = false;
			break;
		case GLUT_KEY_RIGHT:
			turn = 0;
			keyPress = false;
			break;
		case GLUT_KEY_UP:
			jump = 0.0f;
			keyPress = false;
			break;
	default:
		keyPress = false;
		break;
	}
}


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	mysnow.Update();
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(upkeyboard);
	glutSpecialFunc(specialKeys);//方向键来控制移动
	glutSpecialUpFunc(upSpecialKeyboard);//松开按键
	glutMainLoop();
	return 0;

}