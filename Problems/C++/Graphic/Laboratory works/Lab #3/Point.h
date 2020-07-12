#include "Core.h"
class Point
{
public:
	// Конструкторы
	Point();
	Point(double x, double y);

	// Методы
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	void print() const;
	void draw() const;

	// Деструкторы
	//~Point();

private:
	double x, y;
};

