#define _USE_MATH_DEFINES
#include "Vector2.h"

double moveSpeed = 10;
double rotateSpeed = 2;
Vector2 MyVector = Vector2(200, 200, 400, 400);

// Клавиши поворота
string Key_Q = "QqЙй";
string Key_E = "EeУу";
// Клавиши перемещения
string Key_W = "WwЦц";
string Key_S = "SsЫы";
string Key_A = "AaФф";
string Key_D = "DdВв";
// Клавиши изменения размера
string Key_R = "RrКк";
string Key_T = "TtЕе";

bool FindKey(char pressKey, string keyArray)
{
	for (char key : keyArray)
		if (key == pressKey)
			return true;
	return false;
}

void VectorControl(unsigned char key, int x, int y)
{
	if (FindKey(key, Key_W))
	{
		MyVector.setA(MyVector.getA().getX(), MyVector.getA().getY() + moveSpeed);
		MyVector.setB(MyVector.getB().getX(), MyVector.getB().getY() + moveSpeed);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_S))
	{
		MyVector.setA(MyVector.getA().getX(), MyVector.getA().getY() - moveSpeed);
		MyVector.setB(MyVector.getB().getX(), MyVector.getB().getY() - moveSpeed);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_A))
	{
		MyVector.setA(MyVector.getA().getX() - moveSpeed, MyVector.getA().getY());
		MyVector.setB(MyVector.getB().getX() - moveSpeed, MyVector.getB().getY());
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_D))
	{
		MyVector.setA(MyVector.getA().getX() + moveSpeed, MyVector.getA().getY());
		MyVector.setB(MyVector.getB().getX() + moveSpeed, MyVector.getB().getY());
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_Q))
	{
		MyVector.setAngle(MyVector.getAngle() + rotateSpeed);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_E))
	{
		MyVector.setAngle(MyVector.getAngle() - rotateSpeed);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_R))
	{
		MyVector.setScale(MyVector.getScale() * 1.05);
		glutPostRedisplay();
	}
	else if (FindKey(key, Key_T))
	{
		MyVector.setScale(MyVector.getScale() * 0.95);
		glutPostRedisplay();
	}
}

void myInit()
{
	glColor3f(0, 0, 0);
	glClearColor(1, 1, 1, 0);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 640);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	MyVector.draw();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Лабораторная работа №3 | Михалев Андрей | МП-201");
	glutDisplayFunc(myDisplay);
	myInit();
	glutKeyboardFunc(VectorControl);
	glutMainLoop();
	return 0;
}