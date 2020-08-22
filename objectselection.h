#include<windows.h>
#include <glut.h>
#include "button.h"


//#include "rectangle.h"
//#include "RGBA.h"
class object
{
public:
	
	int i = 730;
	button b1;
	button b2;
	button b3;
	button b4;
	//RGBApixmap pic[2];
	rec extent;
	rec extent2;
	rec extent3;

	/*vector<Point> pp3;
	vector<Point> pp2;

	vector<Point> pp;
	*/
	PPoint A;
	PPoint p1[2];
	PPoint p2[3];
	PPoint p3[4];

	void setheight()
	{
		b1.setheight(730);
		b2.setheight(730);
		b3.setheight(730);

	}
	
	void drawBitmapText(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);//define position on the screen where to draw text.

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}
void init()
{
	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_EQUAL, 1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
	glClearColor(0.109f, 0.109f, 0.109f, 1.0f);

	//glClearColor(0.0f, 0.0f, 0.1f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 1350, 730);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1350, 0, 730);
}

void drawBitmapText1(char *string, float x, float y, float z)
{
	char *c;
	glRasterPos3f(x, y, z);//define position on the screen where to draw text.

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
	}
}

void key_Display()
{

	setheight();
	init();
	glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();
	//glRasterPos2f(0, 0);
	//this->pic[0].mDraw();
	glColor3f(1.0f, 1.0f, 0.0f);
	drawBitmapText1("BUMP MAPPING    ", 550, 670, 0);
	drawBitmapText1(".*.________________________.*.    ", 460, 668, 0);

	drawBitmapText("  Project assigned by:", 40, 100, 0);
	drawBitmapText("  Sir Asim     ", 40, 70, 0);

	b4.draw(580, 110, 730, 70);

	A.set(415.0f, 545.0f);
	p1[0] = A;
	A.set(880.0f, 150.0f);
	p1[1] = A;
	extent.drawextentrec(p1, 2);
	extent.drawlines2_h(730, 0, 1180);
	extent.drawlines2_v(1350, 0, 600);
	
//	glColor3f(1, 0.2509, 0.2509);
	//glColor3f(1, 0.854, 0.725);
		//glColor3f(0.109, 0.109, 0.109);
	//glColor3f(0.109, 0.109, 0.109);
		glColor3f(1, 0.2509, 0.2509);
		glBegin(GL_POLYGON);
		glVertex2d(150, 500);
	//	glColor3f(1, 0.2509, 0.2509);
		glColor3f(0.109, 0.109, 0.109);
		glVertex2d(350, 500);
//		glColor3f(1, 0.854, 0.725);
	glVertex2d(350, 430);
	//glColor3f(0.109, 0.109, 0.109);
//		glColor3f(1, 0.2509, 0.2509);
	glVertex2d(150, 430);
glEnd();
glColor3f(1, 1, 0.7);
drawBitmapText("(PRESS \"2\")", 200, 410, 0);
drawBitmapText("NORMAL MAP", 190, 460, 0);
//drawBitmapText1(".____________.", 160, 455, 0);

//glColor3f(0, 1, 0.7);
//glColor3f(0.109, 0.109, 0.109);
//glColor3f(1, 0.854, 0.725);
//glColor3f(1, 0.854, 0.725);
glColor3f(1, 0.2509, 0.2509);
glBegin(GL_POLYGON);
glVertex2d(150, 300);
glColor3f(0.109, 0.109, 0.109);
glVertex2d(350, 300);
glColor3f(0.109, 0.109, 0.109);
//glColor3f(1, 0.854, 0.725);
//glColor3f(1, 0.854, 0.725);
glVertex2d(350, 230);
///glColor3f(0.109, 0.109, 0.109);
glVertex2d(150, 230);
glEnd();
glColor3f(1, 1, 0.7);

drawBitmapText("(PRESS \"3\")", 200, 210, 0);
drawBitmapText("TEXTURE MAP", 190, 260, 0);

//glColor3f(0, 1, 0.7);
//glColor3f(1, 0.2509, 0.2509);
//glColor3f(0.372, 0.19, 0.627);
glColor3f(0.109, 0.109, 0.109);
glBegin(GL_POLYGON);
glVertex2d(930, 500);
//glColor3f(0.109, 0.109, 0.109);
glVertex2d(1120, 500);
//glColor3f(0.184, 0.309, 0.309);
//glColor3f(0.184, 0.309, 0.309);
glColor3f(0.109, 0.109, 0.109);
glColor3f(1, 0.2509, 0.2509);
glVertex2d(1120, 430);
glColor3f(0.109, 0.109, 0.109);
//glColor3f(1, 0.2509, 0.2509);
glVertex2d(930, 430);
glEnd();
glColor3f(1, 1, 0.7);
drawBitmapText("(PRESS \"1\")", 980, 410, 0);
drawBitmapText("BUMP MAP", 970, 460, 0);

//glColor3f(0, 1, 0.7);
//glColor3f(1, 0.854, 0.725);
//glColor3f(0.109, 0.109, 0.109);
glColor3f(0.109, 0.109, 0.109);
glBegin(GL_POLYGON);
glVertex2d(930, 300);
//glColor3f(1, 0.854, 0.725);
glVertex2d(1120, 300);
//glColor3f(1, 0.854, 0.725);
glColor3f(1, 0.2509, 0.2509);
glVertex2d(1120, 230);
glColor3f(0.109, 0.109, 0.109);
glVertex2d(930, 230);
glEnd();
glColor3f(1, 1, 0.7);

drawBitmapText("(PRESS \"4\")", 980, 210, 0);
drawBitmapText("FULL SCREEN", 970, 260, 0);

	glutSwapBuffers();
}
void display()
{
	setheight();
	init();
	glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
	glLoadIdentity();
	//glRasterPos2f(0, 0);
	//this->pic[0].mDraw();
glColor3f(1.0f, 1.0f, 0.0f);
drawBitmapText1("BUMP MAPPING    ", 555, 650, 0);
drawBitmapText1(".*.________________________.*.    ", 460, 638, 0);

	drawBitmapText("  Project assigned by:", 40, 100, 0);
	drawBitmapText("  Sir Asim     ", 40, 70, 0);

	/*b1.draw(400, 550, 555, 500);
	b2.draw(400, 380, 555, 330);
	b3.draw(400, 210, 555, 160);
*/
	b1.draw(240, 250, 400, 200);
	b2.draw(590, 250, 740, 200);
	b3.draw(930, 250, 1080, 200);

	drawBitmapText("       TRIANGLE", 230, 300, 0);
	drawBitmapText("        SQUARE", 580, 300, 0);
	drawBitmapText("        RHOMBUS", 920, 300, 0);
	drawBitmapText(".*.______________.*.", 230, 290, 0);
	drawBitmapText(".*.______________.*.", 580, 290, 0);
	drawBitmapText(".*.______________*.", 920, 290, 0);
	///*drawBitmapText("      > > >  ", 650, 510, 0);
	/*drawBitmapText("      > > >    ", 650, 350, 0);
	
	drawBitmapText("      > > >    ", 650, 180, 0);
	*/
	glBegin(GL_POLYGON);
	glColor3f(0.3f, 0.0f, 0.3f);

	glVertex2f(315.0f, 500.0f);
	A.set(330.0f, 500.0f);
	p2[0] = A;
	//pp.push_back(A);
	glColor3f(0.3f, 0.0f, 0.3f);

	glVertex2f(430.0f, 350.0f);
	glColor3f(0.0f, 2.0f, 2.0f);

	A.set(430.0f, 340.0f);
	p2[1] = A;

	glVertex2f(200.0f, 350.0f);

	A.set(200.0f, 350.0f);
	p2[2] = A;

	glEnd();
	extent.drawextentrec3(p2, 3);
	//pp.pop_back();
	//pp.pop_back();
	//pp.pop_back();

/*	glBegin(GL_LINE_STRIP);
	glColor3f(0.0f, 2.0f, 2.0f);
	glVertex2d(830.0f, 300.0f);
	glVertex2d(970.0f, 400.0f);
	glVertex2d(900.0f, 350.0f);
	glVertex2d(970.0f, 350.0f);
	glEnd();
	*/
	glColor3f(0.6f, 0.0f, 0.2f);
	glRecti(570, 500, 760, 350);
	A.set(565.0f, 505.0f);
//	pp2.push_back(A);
	p1[0] = A;

	A.set(765.0f, 345.0f);
	//pp2.push_back(A);
	p1[1] = A;
	extent.drawextentrec(p1, 2);
//	glBegin(GL_QUADS);
//	glColor3f(0.7f, 0.0f, 0.2f);
//	glVertex2f(900.0f, 250.0f);
//	glColor3f(1.0f, 1.0f, 0.5f);
//	glVertex2f(800.0f, 200.0f);
//	glColor3f(0.7f, 0.0f, 0.2f);
//	glVertex2f(900.0f, 150.0f);
//	glColor3f(1.0f, 1.0f, 0.5f);
//	glVertex2f(1000.0f, 200.0f);
//	//	glVertex2f(900.0f, 150.0f);
//	glEnd();
////	pp.pop_back();
	//pp.pop_back();
//	pp.pop_back();

	glBegin(GL_POLYGON);
	glColor3f(0.7f, 0.0f, 0.2f);
	glVertex2d(900, 425);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex2d(1000, 350);
	glColor3f(0.7f, 0.0f, 0.2f);
	glVertex2d(1100, 420);
	glColor3f(1.0f, 1.0f, 0.5f);
	glVertex2d(1000, 500);
	glEnd();
	A.set(890.0f, 425.0f);
	//pp3.push_back(A);
	p3[0] = A;

	A.set(1000.0f, 340.0f);
//	pp3.push_back(A);
	p3[1] = A;

	A.set(1110.0f, 420.0f);
//	pp3.push_back(A);
	p3[2] = A;
	A.set(1000.0f, 500.0f);
	//pp3.push_back(A);
	p3[3] = A;

	extent.drawextentrec4(p3, 4);
	extent.drawlines2_h(730, 0, 1180);
	extent.drawlines2_v(1350, 0, 560);


	//	glFlush();
	glutSwapBuffers();
	//glFlush();
}

GLfloat x2 = -0.0000f;
GLfloat angle2 = 1.0f;  // rotational angle of the shapes

void init2()
{

	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_EQUAL, 1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
	glClearColor(0.0f, 0.0f, 0.1f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 800, 600);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}


void displayL2()
{
	init2();
	//glRasterPos2f(-10, -10);
	//this->pix[1].mDraw();
	glColor3f(1.0f, 1.0f, 0.0f);
	drawBitmapText("TEXTURE MAPPING    ", -3, 7, 0);

	drawBitmapText("  Project assigned by:", -8, -8, 0);
	drawBitmapText("  Sir Asim     ", -8, -9, 0);

	glColor3f(1.0f, 1.0f, 0.0f);
	drawBitmapText("Loading....    ", 5, -5, 0);

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectd(-8, -3.5, 8, -2);

	glColor3f(0.0f, 1.0f, 0.0f);
	glRectd(-8, -3.5, x2, -2);
	glPushMatrix();                     // Save model-view matrix setting
	glRotatef(angle2, 0.0f, 0.1f, 0.0f); // rotate by angle in degrees
	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.2f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glColor3f(.2f, .23f, 0.0f);

	glVertex2f(0.70710f, 0.70710f);
	//glColor3f(1.0f, 1.0f, 0.45f);

	glVertex2f(0.0f, 1.0f);
	glColor3f(0.34f, 0.56f, 1.0f);

	glVertex2f(-0.70710f, 0.70710f);
	//glColor3f(1.0f, 0.8f, 0.64f);

	glVertex2f(-1.0f, 0.0f);
	glColor3f(1.0f, 0.89f, 0.23f);

	glVertex2f(-0.70710f, -0.70710f);
	//glColor3f(0.23f, 1.0f, 0.12f);

	glVertex2f(0.0f, -1.0f);
	glColor3f(1.0f, 0.2f, 0.0f);

	glVertex2f(0.70710f, -0.70710f);
	glEnd();

	glPopMatrix();                      // Restore the model-view matrix
	//glutSwapBuffers();   // Double buffered - swap the front and back buffers

	// Change the rotational angle after each display()
	angle2 += 2.0f;
	x2 += 00.00000000001f;

	glutSwapBuffers();

}


};