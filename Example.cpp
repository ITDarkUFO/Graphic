#include "stdafx.h"
#include "glut.h"
#include <iostream>
using namespace std;

void myInit()
{
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(4);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	{
		glVertex2f(600, 15);
		glVertex2f(220, 600);
		glVertex2f(15, 68);
	}
	glEnd();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutCreateWindow("OpenGL Example");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
