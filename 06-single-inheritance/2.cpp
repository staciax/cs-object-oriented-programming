#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
private:
    double height;
    double width;

public:
    Shape()
    {
        this->init(0, 0);
    }
    Shape(double height, double width)
    {
        this->init(height, width);
    }
    ~Shape()
    {
        cout << "delete: Shape" << endl;
    }

    // set
    void init(double height, double width)
    {
        this->height = height;
        this->width = width;
    }
    void setHeight(double height)
    {
        this->height = height;
    }
    void setWidth(double width)
    {
        this->width = width;
    }

    // get
    double getHeight()
    {
        return this->height;
    }
    double getWidth()
    {
        return this->width;
    }

    // show
    void show()
    {
        cout << "Shape("
             << "height=" << this->height << ", "
             << "width=" << this->width << ")" << endl;
    }
};

class Rectagle : public Shape
{
private:
    double length;

public:
    Rectagle()
    {
        this->init(0, 0);
    }
    Rectagle(double width, double length) : Shape(0, width)
    {
        this->length = length;
    }
    ~Rectagle()
    {
        cout << "delete: Rectagle" << endl;
    }

    // set
    void setLength(double length)
    {
        this->length = length;
    }

    // get
    double getLength()
    {
        return this->length;
    }

    double perimeter()
    {
        return (this->getWidth() + this->length) * 2;
    }

    double area()
    {
        return this->getWidth() * this->length;
    }

    // show
    void show()
    {
        cout << "Rectagle"
             << "width=" << this->getHeight() << ", "
             << "length=" << this->length << ")" << endl;
    }
};

class Triangle : public Shape
{
private:
    double base;

public:
    Triangle()
    {
        this->base = 0;
    }
    Triangle(double base, double height) : Shape(height, 0)
    {
        this->base = base;
    }
    ~Triangle()
    {
        cout << "delete: Triangle" << endl;
    }

    // set

    void setBase(double base)
    {
        this->base = base;
    }

    // get

    double getBase()
    {
        return this->base;
    }

    double area()
    {
        return 0.5 * this->base * this->getHeight();
    }

    // show
    void show()
    {
        cout << "Triangle("
             << "base=" << this->base << ", "
             << "height=" << this->getHeight() << ")" << endl;
    }
};

class Circle
{
private:
    double radius;

public:
    Circle()
    {
        this->radius = 0;
    }
    Circle(double radius)
    {
        this->radius = radius;
    }
    ~Circle()
    {
        cout << "delete: Circle" << endl;
    }

    // set

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    // get

    double getRadius()
    {
        return this->radius;
    }

    double area()
    {
        return 3.14 * pow(this->radius, 2);
    }

    // show

    void show()
    {
        cout << "Circle("
             << "radius=" << this->radius << ")" << endl;
    }
};

int main()
{
    Rectagle r(10, 15);
    cout << r.area() << endl;
    r.show();

    Triangle t(10, 15);
    cout << t.area() << endl;
    t.show();

    Circle c(20);
    cout << c.area() << endl;
    c.show();

    return 0;
}