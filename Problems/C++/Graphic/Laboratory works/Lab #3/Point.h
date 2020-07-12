#include "Core.h"
class Point
{
public:
	// ������������
	Point();
	Point(double x, double y);

	// ������
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	void print() const;
	void draw() const;

	// �����������
	//~Point();

private:
	double x, y;
};

