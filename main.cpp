//////////////////////////////////////////////////////////////////////////////////////////
//	Simple Bumpmapping
//	Accompanies a tutorial found on my site
//	Downloaded from: www.paulsprojects.net
//	Created:	6th December 2002
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#define WIN32_LEAN_AND_MEAN

#include <windows.h>  // for MS Windows
#include <stdlib.h>
#include <stdio.h>
#include<glut.h>
#include "math.h"
#include <glext.h>
//#include "wav.h"
#include "mainpage.h"
#include "objectselection.h"
#include "map.h"
//#include "wav.h"
//#include "rectangle.h"
//#include "button.h"
//#include "RGBPixMap.h"
//Our OBJECT

mainpage m;
mainpage m2;

//bump_map b_map;
object o;
bump_map b_map;
int chk = 0;
int windowWidth = 450;     // Windowed mode's width
int windowHeight = 350;     // Windowed mode's height
int windowPosX = 430;      // Windowed mode's top-left corner x
int windowPosY = 250;      // Windowed mode's top-left corner y

void init()
{
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0

	glClearColor(0.0f, 0.0f, 0.1f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 1350, 730);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1350, 0, 730);
}

GLfloat x = -7.0f;
int chk2 = 0;
void display3()
{
	o.display();
}
void idle() {
	glutPostRedisplay();   // Post a re-paint request to activate display()
}

//void display3()
//{
//	glClearColor(2.0f, 1.0f, 0.1f, 1.0f); // Set background color to black and opaque
//	glutSwapBuffers();
//}
void setmain()
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Enable double buffered mode
	glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
	glutInitWindowSize(1350, 730);   // Set the window's initial width & height
	glutCreateWindow("MMS PROJECT");
	//	PlayBackgroundSound("force.wav");
}
void setmain2()
{

	glutInitWindowPosition(422, 217);
	glutInitWindowSize(450, 350);
	//glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Simple Bumpmapping");
}
void setmain_again()
{

	glutInitWindowPosition(422, 217); 
	//glutInitWindowPosition(430, 250);
	glutInitWindowSize(450, 350);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Enable double buffered mode
	glutCreateWindow("MMS2 PROJECT");
	//glutIdleFunc(idle);       // In main() - Register callback handler if no other event
	//m2.x = -0.7f;
}


void setmain3()
{
	glutInitWindowPosition(430, 250);
	glutInitWindowSize(1150, 750);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Enable double buffered mode
	glutCreateWindow("MMS2 PROJECT");
	//glutIdleFunc(idle);       // In main() - Register callback handler if no other event
	//m2.x = -0.7f;
}
void display1()
{
	if (m.x == 0)
	{
		m.displaymain();
	}
}

void Init2b()
{
	b_map.Init();

	//b_map.init1();

}
void Init2c()
{
	b_map.Init();

//	b_map.init2();

}
void display5()
{
	o.key_Display();
}

void display4()
{
	//b_map.Init();
//	b_map.Display2();
	b_map.init1();
	b_map.Display();
}
void display7()
{
	//b_map.Init();
	//	b_map.Display2();
	b_map.init2();
	b_map.Display();
}
//void mouse2(int button, int state, int x, int y) {
//	int d1 = o.b1.choice(button, state, x, y);
//	int d2 = o.b2.choice(button, state, x, y);
//	int d3 = o.b3.choice(button, state, x, y);
//	//int d2 = b1[1].choice(button, state, x, y);
//	if (d1 == 1)
//		b_map.choice = 1;
//	if (d2 == 1)
//		b_map.choice = 2;
//	if (d3 == 1)
//		b_map.choice = 3;
//
//	if (d1 == 1 || d2 == 1 || d3 == 1)
//	{
//
//		setmain2();
//		Init2();
//		glutDisplayFunc(display4);
//		glutReshapeFunc(Reshape);
//		glutKeyboardFunc(Keyboard);
//		glutMainLoop();
//		//glutMouseFunc(mouse2);   // Register callback handler for mouse event
//		//glutMainLoop();
//
//	}
//}

void Reshape(int w, int h)
{
	//w = 1450;
	//h = 750;
	//Set viewport
	if (h == 0)
		h = 1;

	glViewport(w/2, h/2, 0, 0);
	glLoadIdentity();
	//Set up projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
	gluOrtho2D(45.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void display6()
{
	/*
	if (m.x != 8.0f || m.x < 8.0f)
	{
*/
		//setmain_again();
		//m.x += 0.004f;
		//	m.x += 0.04f;
		//	glutSwapBuffers();

		if (m.x == 6.0f || m.x>6.0f)

		{
			//	m.x = 0.0f;
				setmain2();
				Init2b();
			glutDisplayFunc(display4);
		//    glutReshapeFunc(Reshape);
			glutKeyboardFunc(Keyboard);
			glutMainLoop();
		}
		else
		{
			m.displayL2();

		}
		glutPostRedisplay();
		//glutMainLoop();
	
	
}
//Called on window resize


void mouse3(int button, int state, int x, int y)
{
	//float yy = 600 - y;
	int d1 = o.b4.choice(button, state, x, y);
	
	//o.x2 = -0.7;
	m.x = 5.5f;
	if (d1 == 1)
	{
		//o.x2 = -7.0f;
		setmain_again();
		glutDisplayFunc(display6);
		//glutPostRedisplay();
		//glutIdleFunc(idle);       // In main() - Register callback handler if no other event
		glutMainLoop();
	}
//		m.x2 == -7.0f;
	//	m.angle = 1.0f;
	//..else 
}

void mouse2(int button, int state, int x, int y) {
	int d1 = o.b1.choice(button, state, x, y);
	int d2 = o.b2.choice(button, state, x, y);
	int d3 = o.b3.choice(button, state, x, y);
	//int d2 = b1[1].choice(button, state, x, y);
	if (d1 == 1)
		b_map.choice = 1;
	if (d2 == 1)
		b_map.choice = 2;
	if (d3 == 1)
		b_map.choice = 3;

	if (d1 == 1 || d2 == 1 || d3 == 1)
	{

//		setmain2();
	//	Init2();
		glutDisplayFunc(display5);
		glutMouseFunc(mouse3);  
		// Register callback handler for mouse event
		//glutReshapeFunc(Reshape);
		//glutKeyboardFunc(Keyboard);
		glutMainLoop();
		//glutMainLoop();

	}
}

void display2()
{
	if (m.x == 8.0f || m.x > 8.0f)
	{
		//m.x = 0.0f;
		//m.angle = 0.01;
		setmain();
		glutDisplayFunc(display3);
		glutMouseFunc(mouse2);
		glutMainLoop();
	}
	else
	{
		m.displayL();
	}
}
void mouse1(int button, int state, int x, int y)
{
	float yy = 600 - y;
	if ((x>320 && x<480) && (yy>210 && yy<240))
	{
		m.x == -7.0f;
		glutDisplayFunc(display2);
		glutMainLoop();
	}
}




//bmp





//Called when a key is pressed
void Keyboard(unsigned char key, int x, int y)
{
	//If escape is pressed, exit
	if(key==27)
		exit(0);

	//'1' draws both passes
	if(key=='1')
	{
		b_map.drawBumps=true;
		b_map.drawColor = true;
	}

	//'2' draws only bumps
	if(key=='2')
	{
		b_map.drawBumps = true;
		b_map.drawColor = false;
	}

	//'3' draws only color
	if(key=='3')
	{
		b_map.drawBumps = false;
		b_map.drawColor = true;
	}
	if (key == '4')
	{
	setmain3();
		Init2c();
		glutDisplayFunc(display7);
		//glutReshapeFunc(Reshape);
		glutFullScreen();
		//glutReshapeFunc(Reshape);
		glutKeyboardFunc(Keyboard);
		glutMainLoop();
}

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);        // Create a window with the given title
	glutInitWindowPosition(300, 50);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); // Enable double buffered mode
	glutCreateWindow(" PROJECT");
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_EQUAL, 1.0);
	//PlayBackgroundSound("force.wav");
	//b_map.decalImage.Load("back3.bmp");
	//b_map.normalMapImage.Load("bmp3.bmp");

	glutDisplayFunc(display1);
	glutMouseFunc(mouse1);   // Register callback handler for mouse even
	glutIdleFunc(idle);       // In main() - Register callback handler if no other event
	glutMainLoop();

	
	return 0;
}