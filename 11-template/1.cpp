#include <iostream>

using namespace std;

class Point
{
    double x, y;

public:
    Point()
    {
        this->x = this->y = 1;
    }

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Point(int x)
    {
        this->x = x;
        this->y = 1;
    }

    double area()
    {
        return this->x * this->y;
    }

    // operator

    bool operator<(Point &p)
    {
        return (this->x < p.x & this->y < p.y);
    }

    bool operator>(Point &p)
    {
        return this->area() > p.area();
    }

    operator double()
    {
        return this->area();
    }
};

template <class T, class U, class V>
T max(T a, U b, V c)
{
    if ((a > b) && (a > c))
        return a;
    else if ((b > a) && (b > c))
        return b;
    else
        return c;
}

int main()
{
    Point p1(4, 5), p2(3, 4);

    cout << "max: " << max(1, 'a', 3.14) << endl;
    cout << "max: " << max(true, 1.5, p1) << endl;
    cout << "max: " << max(p2, 5.2, 'x') << endl;
    return 0;
}