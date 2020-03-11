#include "glut.h"
#include <iostream>

using namespace std;

class Point
{
private:
	float x;
	float y;
public:
	Point();
	Point(float ax, float ay);
	float getx();
	float gety();
	void setx(float ax);
	void sety(float ay);
	void draw();
};

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
	glPointSize(10);
	Point p1;
	p1.setx(100);
	p1.sety(130);
	p1.draw();
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

Point::Point()
{
	x = 0;
	y = 0;
}

Point::Point(float ax, float ay)
{
	x = ax;
	y = ay;
}

float Point::getx()
{
	return x;
}

float Point::gety()
{
	return y;
}

void Point::setx(float ax)
{
	x = ax;
}

void Point::sety(float ay)
{
	y = ay;
}

void Point::draw()
{
	glBegin(GL_POINTS);
	{
		glVertex2f(x, y);
	}
	glEnd();
}
