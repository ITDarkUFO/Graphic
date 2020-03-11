#include "glut.h"
#include <iostream>

using namespace std;

class Point
{
private:
	float x;
	float y;
	int size;
	unsigned char r;
	unsigned char g;
	unsigned char b;

public:
	Point();
	Point(float x, float y, int size = 1, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);
	float getx() const;
	float gety() const;
	void setx(float x);
	void sety(float y);
	void draw() const;
	void setPt(int size = 1, float r = 0, float g = 0, float b = 0);
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
	Point p1;
	p1.setPt(15);
	p1.setx(100);
	p1.sety(130);
	p1.draw();
	Point p2(350.5, 240);
	p2.setPt(20, 255, 67.5, 112.5);
	p2.draw();
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
	r = 0;
	g = 0;
	b = 0;
	size = 1;
}

Point::Point(float x, float y, int size, unsigned char r, unsigned char g, unsigned char b)
{
	this->x = x;
	this->y = y;
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}

float Point::getx() const
{
	return x;
}

float Point::gety() const
{
	return y;
}

void Point::setx(float x)
{
	this->x = x;
}

void Point::sety(float y)
{
	this->y = y;
}

void Point::draw() const
{
	glColor3ub(r, g, b);
	glPointSize(size);
	glBegin(GL_POINTS);
	{
		glVertex2f(x, y);
	}
	glEnd();
}

void Point::setPt(int size, float r, float g, float b)
{
	this->size = size;
	this->r = r;
	this->g = g;
	this->b = b;
}
