#pragma once
#include <malloc.h>
#include <windows.h>  // for MS Windows
#include<glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
#include "rectangle.h"


class button{

public://void display2();

	PPoint corner[4];
	int x1, x2, y1, y2;
	int screenh;
	int screenw;
	int counter;
	rec extent;
	PPoint p[2];

	PPoint A;
	button()
	{

		this->counter = 0;
		screenh = 730;
		screenw = 1350;

	}
	void setheight(int height)
	{
		this->screenh = height;
	}void drawBitmapText(char *string, float x, float y, float z)
	{
		char *c;
		glRasterPos3f(x, y, z);//define position on the screen where to draw text.

		for (c = string; *c != '\0'; c++)
		{
			glColor3f(1.0f, 1.0f, 0.5f);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
		}
	}
	void draw(int x1, int y1, int x2, int y2)
	{
	
		A.set(x1, y1);
	//	pp.push_back(A);
		p[0] = A;
		A.set(x2, y2);
	//	pp.push_back(A);
		p[1] = A;
		extent.drawextentrec(p,2);
		glColor3f(0.0f, 0.0f, 0.1f); // Blue
		glRecti(x1, y1, x2, y2);
		glColor3f(1.0f, 1.0f, 0.5f);
	//	glColor3f(0, 1, 0.49);
		//glColor3f(1, 0.2509, 0.2509);

		drawBitmapText("        SELECT ", x1, y1 +(y2-y1)/2-10, 0);
		//pp.pop_back();
		//pp.pop_back();
		//corner[0] = new Point2();
		this->corner[0].x = x1;
		this->corner[0].y = y1;
		//		this->counter++;
		this->corner[1].x = x2;
		this->corner[1].y = y2;
	}
	int choice(int button, int state, int x, int y)
	{
		double x1 = x;
		double  yy = screenh - y;
		int d = 0;
		//	display2 d;
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ // Pause/resume
			{
				if ((x > this->corner[0].x && x <this->corner[1].x) && (yy>this->corner[1].y && yy <this->corner[0].y))
				{
					d = 1;

				}
			}
		}
		return d;
	}

};


