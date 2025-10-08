#include <iostream>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:
    Point()
    {
        this->init(0, 0);
    }
    Point(int x, int y)
    {
        this->init(x, y);
    }

    // set
    void init(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(int x)
    {
        this->x = x;
    }
    void setY(int y)
    {
        this->y = y;
    }

    // get
    int getX()
    {
        return this->x;
    }
    int getY()
    {
        return this->y;
    }

    // show
    void show()
    {
        cout << "Point("
             << "x=" << this->x << ", "
             << "y=" << this->y << ")" << endl;
    }
};

class Rectangle
{
private:
public:
    Rectangle()
    {
    }
    ~Rectangle()
    {
    }
};

int main()
{
    Point p;
    Rectangle r;
    return 0;
}