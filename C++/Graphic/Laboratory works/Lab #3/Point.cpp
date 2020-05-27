#include "Point.h"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

void Point::setX(double x)
{
	this->x = x;
}

void Point::setY(double y)
{
	this->y = y;
}

void Point::print() const
{
	cout << "x: " << this->x << ", y: " << this->y << "; ";
}

void Point::draw() const
{
	glBegin(GL_POINTS);
	{
		glVertex2f(this->x, this->y);
	}
	glEnd();
}

//Point::~Point()
//{
//}
