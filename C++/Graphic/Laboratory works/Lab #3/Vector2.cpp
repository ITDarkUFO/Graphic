#include "Vector2.h"

Vector2::Vector2()
{
	Point A = Point();
	Point B = Point();
	this->angle = atan2(this->B.getY() - this->A.getY(), this->B.getX() - this->A.getX());
	this->_angle = angle;
}

Vector2::Vector2(double x1, double y1, double x2, double y2)
{
	this->A = Point(x1, y1);
	this->B = Point(x2, y2);
	this->angle = atan2(this->B.getY() - this->A.getY(), this->B.getX() - this->A.getX());
	this->_angle = angle;
}

Point Vector2::getA() const
{
	return this->A;
}

Point Vector2::getB() const
{
	return this->B;
}

double Vector2::getAngle() const
{
	return this->angle;
}

double Vector2::getScale() const
{
	return this->scale;
}

void Vector2::setA(double x, double y)
{
	this->A.setX(x);
	this->A.setY(y);
}

void Vector2::setB(double x, double y)
{
	this->B.setX(x);
	this->B.setY(y);
}

void Vector2::setAngle(double angle)
{
	this->angle = angle;
}

void Vector2::setScale(double scale)
{
	this->scale = scale;
}

void Vector2::print() const
{
	cout << "A. x: " << this->A.getX() << ", y: " << this->A.getY() << "; ";
	cout << "B. x: " << this->B.getX() << ", y: " << this->B.getY() << "; ";
}

void Vector2::draw() const
{
	glPushMatrix();
	glTranslatef(this->A.getX(), this->A.getY(), 0.0);
	glRotated(angle, 0, 0, 1);
	glScalef(scale, scale, 1.0);
	glTranslatef(-this->A.getX(), -this->A.getY(), 0.0);

	glBegin(GL_LINES);
	{
		glVertex2f(this->A.getX(), this->A.getY());
		glVertex2f(this->B.getX(), this->B.getY());

		if (INCLUDE_ARROW)
		{
			glVertex2f(this->B.getX(), this->B.getY());
			glVertex2f(30 * cos(_angle - 3 * M_PI / 4) + this->B.getX(), 30 * sin(_angle - 3 * M_PI / 4) + this->B.getY());
			glVertex2f(this->B.getX(), this->B.getY());
			glVertex2f(30 * cos(_angle + 3 * M_PI / 4) + this->B.getX(), 30 * sin(_angle + 3 * M_PI / 4) + this->B.getY());
		}
	}
	glEnd();

	glPopMatrix();
	glFinish();
}

//Vector2::~Vector2()
//{
//}


//class Vector
//{
//public:
//	void setx(double input[2]);
//	void sety(double input[2]);
//	void drawVector() const;
//};