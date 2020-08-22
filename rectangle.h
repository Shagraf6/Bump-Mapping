#include "windows.h"
#include <glut.h>
//#include <vector>
#include "point.h"
//using namespace std;
class  rec
{
public:
	PPoint p1, p2;
	rec()
	{
	
	}

	void drawlines_h(int max, int min, int pos)
	{
		glLineWidth(3);

		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(pos, min);
		glVertex2d(pos, max + 5);
		glEnd();
		
		glColor3f(1, 0.501, 0.447);

//		glColor3f(1, 0.9254, 0.533);

		glBegin(GL_LINE_STRIP);
		glVertex2f(pos +0.5, min);
		glVertex2f(pos+0.5, max + 5);
		glEnd();

		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(pos+1, min);
		glVertex2d(pos+1, max + 5);
		glEnd();

		glFlush();

	}
	void drawlines_v(int max, int min, int pos)
	{
		glLineWidth(3);

		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(min, pos);
		glVertex2d(max, pos);
		glEnd();

		glColor3f(1, 0.501, 0.447);

	//	glColor3f(1, 1, 0);
//		glColor3f(1, 0.9254, 0.533);

		glBegin(GL_LINE_STRIP);
		glVertex2f(min, pos + 0.5);
		glVertex2f(max ,pos + 0.5);
		glEnd();

		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(min, pos + 1);
		glVertex2d(max + 5, pos + 1);
		glEnd();

		glFlush();

	}

	void drawlines2_h(int max, int min, int pos)
	{
		glLineWidth(3);

		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(pos, min);
		glVertex2d(pos, max + 15);
		glEnd();

	
		glColor3f(1, 0.9254, 0.533);
		//glColor3f(1, 0.2509, 0.2509);
		glBegin(GL_LINE_STRIP);
		glVertex2f(pos + 20.0, min);
		glVertex2f(pos + 20.0,max + 15);
		glEnd();
		//glColor3f(1, 0.2509, 0.2509);
		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(pos + 40, min);
		glVertex2d(pos + 40, max + 15);
		glEnd();

		glFlush();

	}
	void drawlines2_v(int max, int min, int pos)
	{
		glLineWidth(3);

		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(min, pos);
		glVertex2d(max+15, pos);
		glEnd();
	//	glColor3f(1, 0.501, 0.447);
		glColor3f(1, 0.9254, 0.533);
	//	glColor3f(1, 0.2509, 0.2509);
		glBegin(GL_LINE_STRIP);
		glVertex2f(min, pos + 20.0);
		glVertex2f(max+15, pos + 20.0);
		glEnd();
	//	glColor3f(1, 0.2509, 0.2509);
		glColor3f(0, 1, 0.49);
		glBegin(GL_LINE_STRIP);
		glVertex2d(min, pos +40);
		glVertex2d(max + 15, pos +40);
		glEnd();

		glFlush();

	}

	void drawextentrec(PPoint pp[2],int count)
	{
		glLineWidth(3);

		p1.x = p2.x = pp[0].x;
		p1.y = p2.y = pp[0].y;
		for (int i = 0; i < count ; i++)
		{
			if (p1.x > pp[i].x)
				p1.x = pp[i].x;

			if (p1.y > pp[i].y)
				p1.y = pp[i].y;

			if (p2.x < pp[i].x)
				p2.x = pp[i].x;

			if (p2.y < pp[i].y)
				p2.y = pp[i].y;
		}
		glColor3f(0.0f, 3.0f, 2.0f);
			//glColor3f(0.7f,0.1f,0.2f );
		glBegin(GL_LINE_STRIP);
			glVertex2d(p1.x - 5, p1.y - 5);
			glVertex2d(p2.x + 5, p1.y - 5);
			glVertex2d(p2.x + 5, p2.y + 5);
			glVertex2d(p1.x - 5, p2.y + 5);
			glVertex2d(p1.x - 5, p1.y - 5);

			glEnd();
			//glLineWidth(25);
		//	glColor3f(1, 0.2509, 0.2509);
					glColor3f(0.545, 0.188, 0.188);
			glBegin(GL_LINE_STRIP);
			glVertex2d(p1.x - 10, p1.y - 10);
			glVertex2d(p2.x + 10, p1.y - 10);
			glVertex2d(p2.x + 10,p2.y + 10);
			glVertex2d(p1.x - 10, p2.y + 10);
			glVertex2d(p1.x - 10, p1.y - 10);

			glEnd();
	//			glRectf(p1.x - 0.2, p1.y - 0.2, p2.x + 0.2, p2.y + 0.2);
			glFlush();
	}
	void drawextentrec3(PPoint pp[3], int count)
	{
		glLineWidth(3);

		p1.x = p2.x = pp[0].x;
		p1.y = p2.y = pp[0].y;
		for (int i = 0; i < count; i++)
		{
			if (p1.x > pp[i].x)
				p1.x = pp[i].x;

			if (p1.y > pp[i].y)
				p1.y = pp[i].y;

			if (p2.x < pp[i].x)
				p2.x = pp[i].x;

			if (p2.y < pp[i].y)
				p2.y = pp[i].y;
		}
		glColor3f(0.0f, 3.0f, 2.0f);
		//glColor3f(0.7f,0.1f,0.2f );
		glBegin(GL_LINE_STRIP);
		glVertex2d(p1.x - 5, p1.y - 5);
		glVertex2d(p2.x + 5, p1.y - 5);
		glVertex2d(p2.x + 5, p2.y + 5);
		glVertex2d(p1.x - 5, p2.y + 5);
		glVertex2d(p1.x - 5, p1.y - 5);

		glEnd();
		glColor3f(0.545, 0.188, 0.188);
		//glColor3f(1, 0.2509, 0.2509);

		glBegin(GL_LINE_STRIP);
		glVertex2d(p1.x - 10, p1.y - 10);
		glVertex2d(p2.x + 10, p1.y - 10);
		glVertex2d(p2.x + 10, p2.y + 10);
		glVertex2d(p1.x - 10, p2.y + 10);
		glVertex2d(p1.x - 10, p1.y - 10);

		glEnd();
		//			glRectf(p1.x - 0.2, p1.y - 0.2, p2.x + 0.2, p2.y + 0.2);
		glFlush();
	}void drawextentrec4(PPoint pp[4], int count)
	{
		glLineWidth(3);
		p1.x = p2.x = pp[0].x;
		p1.y = p2.y = pp[0].y;
		for (int i = 0; i < count; i++)
		{
			if (p1.x > pp[i].x)
				p1.x = pp[i].x;

			if (p1.y > pp[i].y)
				p1.y = pp[i].y;

			if (p2.x < pp[i].x)
				p2.x = pp[i].x;

			if (p2.y < pp[i].y)
				p2.y = pp[i].y;
		}
		glColor3f(0.0f, 3.0f, 2.0f);
		//glColor3f(0.7f,0.1f,0.2f );
		glBegin(GL_LINE_STRIP);
		glVertex2d(p1.x - 5, p1.y - 5);
		glVertex2d(p2.x + 5, p1.y - 5);
		glVertex2d(p2.x + 5, p2.y + 5);
		glVertex2d(p1.x - 5, p2.y + 5);
		glVertex2d(p1.x - 5, p1.y - 5);

		glEnd();
	//	glColor3f(1, 0.2509, 0.2509);

			glColor3f(0.545, 0.188, 0.188);
		glBegin(GL_LINE_STRIP);
		glVertex2d(p1.x - 10, p1.y - 10);
		glVertex2d(p2.x + 10, p1.y - 10);
		glVertex2d(p2.x + 10, p2.y + 10);
		glVertex2d(p1.x - 10, p2.y + 10);
		glVertex2d(p1.x - 10, p1.y - 10);

		glEnd();
		//			glRectf(p1.x - 0.2, p1.y - 0.2, p2.x + 0.2, p2.y + 0.2);
		glFlush();
	}

//private:

};

/* rec:: rec()
{
}

 rec::~ rec()
{
}*/