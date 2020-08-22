#include <glut.h>
#include "button.h"
class mainpage
{
public:
	GLfloat x= 0.0f;
//	GLfloat x2 = -7.0f;
	//GLfloat angle2 = 1.0f;  // rotational angle of the shapes
	button b7;
	GLfloat angle = 1.0f;  // rotational angle of the shapes
	//RGBApixmap pix[2];
	rec lines;
	void init2()
	{
		
		//glEnable(GL_ALPHA_TEST);
		//glAlphaFunc(GL_EQUAL, 1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
		//glClearColor(0.545f, 0.411f, 0.411f, 1.0f); // Set background color to black and opaque
	//	glClearColor(0.184, 0.309, 0.309, 1.0f); 
		glClearColor(0.109f, 0.109f, 0.109f, 1.0f);
		//glColor3f(0.184, 0.309, 0.309);

		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, 800, 600);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	}
	void init3()
	{

		//glEnable(GL_ALPHA_TEST);
		//glAlphaFunc(GL_EQUAL, 1.0); // accept fragment if fragment alpha = reference alpha i.e. 1.0
		glClearColor(0.0f, 0.0f, 0.1f, 1.0f); // Set background color to black and opaque
		glClear(GL_COLOR_BUFFER_BIT);
		glViewport(0, 0, 410, 450);
		//glViewport(100, 100, 450, 350);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(-7.0, 6.0, -7.0, 6.0);
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
	void drawBitmapText2(char *string, float x, float y, float z)
	{
		char *c;
		glRasterPos3f(x, y, z);//define position on the screen where to draw text.
		for (c = string; *c != '\0'; c++)
		{
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
			//glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
		}
	}
	
	void displaymain()
	{
//		b7.setheight(600);
		init2();
		//glRasterPos2f(-10,-10);
		//this->pix[0].mDraw();

		glColor3f(1.0f, 1.0f, 0.0f);
//		drawBitmapText2("TEXTURE MAPPING    ", -3, 7, 0);
		drawBitmapText2("BUMP MAPPING    ", -2.5, 7, 0);
		drawBitmapText2(".*._______________________.*.    ", -4.5, 6.5, 0);

		drawBitmapText("  Project assigned by:", -10, -4.5, 0);
		drawBitmapText("  Sir Asim     ", -8.5, -5.5, 0);
		drawBitmapText("  Project Members :", -10, -6.5, 0);
		drawBitmapText("  Sidra Rashid     ", -8.5, -7.5, 0);
		drawBitmapText("  Zeenat Abbasi    ", -8.5, -8.5, 0);
		drawBitmapText("  Shagraf Nasheet     ", -8.5, -9.5, 0);
		//glFlush();
		glPushMatrix();                     // Save model-view matrix setting
		glRotatef(angle, 1.0f, 0.0f, 0.4f); // rotate by angle in degrees
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
		angle += 2.0f;

		//b7.setheight(600);
		glLineWidth(2);
		glColor3f(0.0f, 0.0f, 0.1f); // Blue
		glRectd(-2, -3, 2, -2);
		glColor3f(1.0f, 1.0f, 0.5f);
		drawBitmapText("   NEXT", -1, -2.7, 0);

		glColor3f(0.0f, 3.0f, 2.0f);
			//glColor3f(0.7f,0.1f,0.2f );
			glBegin(GL_LINE_STRIP);
			glVertex2f(-2.3, -1.7);
			glVertex2f(2.3, -1.7);
			glVertex2f(2.3, -3.3);
			glVertex2f(-2.3, -3.3);
			glVertex2f(-2.3, -1.7);

			glEnd();
			glColor3f(0.545, 0.188, 0.188);
			//glColor3f(1, 0.2509, 0.2509);
			glBegin(GL_LINE_STRIP);
			glVertex2d(-2.5, -1.5);
			glVertex2d(2.5, -1.5);
			glVertex2d(2.5, -3.5);
			glVertex2d(-2.5, -3.5);
			glVertex2d(-2.5, -1.5);

			glEnd();

			lines.drawlines_h(10, -10, 6);
			lines.drawlines_v(10, -10, 4);
			//		

		glutSwapBuffers();
		
	}
void displayL()
	{
		init2();
		//glRasterPos2f(-10, -10);
		//this->pix[1].mDraw();
		glColor3f(1.0f, 1.0f, 0.0f);
		drawBitmapText2("BUMP MAPPING    ", -2.5, 7, 0);
		drawBitmapText2(".*._______________________.*.    ", -4.5, 6.5, 0);

		drawBitmapText("  Project assigned by:", -8, -8, 0);
		drawBitmapText("  Sir Asim     ", -8, -9, 0);

		glColor3f(1.0f, 1.0f, 0.0f);
		drawBitmapText("Loading....    ", 4, -5, 0);
		lines.drawlines_h(10, -10, 6);
		lines.drawlines_v(10, -10, 4);

		glColor3f(1.0f, 1.0f, 1.0f);
		glRectd(-8, -3.5, 8, -2);

		glColor3f(0.0f, 1.0f, 0.0f);
		glRectd(-8, -3.5, x, -2);
		glPushMatrix();                     // Save model-view matrix setting
		glRotatef(angle, 1.0f, 0.0f, 0.4f); // rotate by angle in degrees
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
		angle += 2.0f;
		x += 0.004f;
		
		glutSwapBuffers();

	}
void displayL2()
{
	init3();
	//glRasterPos2f(-10, -10);
	//this->pix[1].mDraw();
	//glColor3f(1.0f, 1.0f, 0.0f);
	//drawBitmapText2("TEXTURE MAPPING    ", -3, 7, 0);

	//drawBitmapText("  Project assigned by:", -8, -8, 0);
	//drawBitmapText("  Sir Asim     ", -8, -9, 0);

	glColor3f(1.0f, 1.0f, 0.0f);
	drawBitmapText("Loading....    ", 3, -5, 0);

	glColor3f(1.0f, 1.0f, 1.0f);
	glRectd(-6, -3.0, 6, -2);

	glColor3f(0.0f, 1.0f, 0.0f);
	glRectd(-6, -3.0, x, -2);
	glPushMatrix();                     // Save model-view matrix setting
	glRotatef(angle, 0.0f, 0.1f, 0.0f); // rotate by angle in degrees
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
	angle += 0.1f;
	x += 0.0001f;

	glutSwapBuffers();

}
};
