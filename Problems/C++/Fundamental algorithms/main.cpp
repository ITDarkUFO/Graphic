#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x;
    double y;

    Point()
    {
        this->x = 0;
        this->y = 0;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

double getSegmentLength(Point a, Point b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double getRectanglePerimeter(Point a, Point b, Point c, Point d)
{
    double ab = getSegmentLength(a, b);
    double bc = getSegmentLength(b, c);
    return 2 * (ab + bc);

}

int main() {
    system("chcp 65001");
    double x, y;

    cin >> x >> y;
    Point A = Point(x, y);
    cin >> x >> y;
    Point B = Point(x, y);
    cin >> x >> y;
    Point C = Point(x, y);
    cin >> x >> y;
    Point D = Point(x, y);

    cout << getRectanglePerimeter(A, B, C, D);

    system("pause");
    return 0;
}