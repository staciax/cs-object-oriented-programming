#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
public:
    virtual ~Shape()
    {
        cout << "delete: Shape" << endl;
    };
    virtual double area() = 0;
    virtual void show() = 0;
    virtual void input(istream &is) = 0;
    virtual void print(ostream &os) = 0;
};

class TwoDimensional : public Shape
{
};

class ThreeDimensional : public Shape
{
public:
    virtual double volume() = 0;
};

class Rectangle : public TwoDimensional
{
    double width, length;

public:
    Rectangle()
    {
        this->width = this->length = 0;
    }
    Rectangle(double width, double length)
    {
        this->width = width;
        this->length = length;
    }
    ~Rectangle()
    {
        cout << "delete: Rectangle" << endl;
    }

    // set
    void setWidth(double width)
    {
        this->width = width;
    }
    void setLength(double length)
    {
        this->length = length;
    }

    // get

    double getWidth()
    {
        return this->width;
    }
    double getLength()
    {
        return this->length;
    }

    double area()
    {
        return this->width * this->length;
    }

    // show
    void show()
    {
        this->print(cout);
    }

    // io

    void print(ostream &os)
    {
        os << "Rectangle(width=" << this->width << ", length=" << this->length << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Rectangle" << endl;
        cout << "Enter width: ";
        is >> this->width;
        cout << "Enter length: ";
        is >> this->length;
    }
};

class Triangle : public TwoDimensional
{
    double base, height;

public:
    Triangle()
    {
        this->base = this->height = 0;
    }
    Triangle(double base, double height)
    {
        this->base = base;
        this->height = height;
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
    void setHeight(double height)
    {
        this->height = height;
    }

    // get

    double getBase()
    {
        return this->base;
    }
    double getHeight()
    {
        return this->height;
    }

    double area()
    {
        return 0.5 * (this->base * this->height);
    }

    // show
    void show()
    {
        this->print(cout);
    }

    // io
    void print(ostream &os)
    {
        os << "Triangle(base=" << this->base << ", height=" << this->height << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Triangle" << endl;
        cout << "Enter base: ";
        is >> this->base;
        cout << "Enter height: ";
        is >> this->height;
    }
};

class Circle : public TwoDimensional
{
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
        return 3.14 * pow(this->radius, 0);
    }

    // show
    void show()
    {
        this->print(cout);
    }

    // io

    void print(ostream &os)
    {
        os << "Circle(radius=" << this->radius << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Circle" << endl;
        cout << "Enter radius: ";
        is >> this->radius;
    }
};

class Cylinder : public ThreeDimensional
{
    double radius, height;

public:
    Cylinder()
    {
        this->radius = this->height = 0;
    }
    Cylinder(double radius, double height)
    {
        this->radius = radius;
        this->height = height;
    }
    ~Cylinder()
    {
        cout << "delete: Cylinder" << endl;
    }

    // set
    void setRadius(double radius)
    {
        this->radius = radius;
    }
    void setHeight(double height)
    {
        this->height = height;
    }

    // get
    double getRadius()
    {
        return this->radius;
    }
    double getHeight()
    {
        return this->height;
    }

    double area()
    {
        return (2 * 3.14 * this->radius * this->height) + (2 * 3.14 * pow(this->radius, 2));
    }
    double volume()
    {
        return 3.14 * pow(this->radius, 2) * this->height;
    }

    // show
    void show()
    {
        this->print(cout);
    }

    // io
    void print(ostream &os)
    {
        os << "Cylinder(radius=" << this->radius << ", height=" << this->height << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Cylinder" << endl;
        cout << "Enter radius: ";
        is >> this->radius;
        cout << "Enter height: ";
        is >> this->height;
    }
};

class Sphere : public ThreeDimensional
{
    double radius;

public:
    Sphere()
    {
        this->radius = 0;
    }
    Sphere(double radius)
    {
        this->radius = radius;
    }
    ~Sphere()
    {
        cout << "delete: Sphere" << endl;
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
        return 4 * 3.14 * pow(this->radius, 2);
    }
    double volume()
    {
        return (4 / 3) * 3.13 * pow(this->radius, 3);
    }

    // show
    void show()
    {
        this->print(cout);
    }

    // io
    void print(ostream &os)
    {
        os << "Sphere(radius=" << this->radius << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Sphere" << endl;
        cout << "Enter radius: ";
        is >> this->radius;
    }
};

ostream &operator<<(ostream &os, Shape &shape)
{
    shape.print(os);
    return os;
}
istream &operator>>(istream &is, Shape &shape)
{
    shape.input(is);
    return is;
}

int main()
{
    // shape
    Shape *shape[5];
    shape[0] = new Rectangle;
    shape[1] = new Triangle;
    shape[2] = new Circle;
    shape[3] = new Cylinder;
    shape[4] = new Sphere;

    for (int i = 0; i < 5; i++)
    {
        cin >> *shape[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << *shape[i];
    }
    for (int i = 0; i < 5; i++)
    {
        delete shape[i];
    }

    // 2d
    TwoDimensional *two[3];
    two[0] = new Rectangle;
    two[1] = new Triangle;
    two[2] = new Circle;

    for (int i = 0; i < 3; i++)
    {
        cin >> *two[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout << *two[i];
        cout << " area=" << two[i]->area() << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        delete two[i];
    }

    // 3d
    ThreeDimensional *three[2];
    three[0] = new Cylinder;
    three[1] = new Sphere;

    for (int i = 0; i < 2; i++)
    {
        cin >> *three[i];
    }
    for (int i = 0; i < 2; i++)
    {
        cout << *three[i];
        cout << " area=" << three[i]->area() << endl;
        cout << " volume=" << three[i]->volume() << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        delete three[i];
    }
    return 0;
}