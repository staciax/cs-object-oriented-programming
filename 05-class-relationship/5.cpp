#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Circle;

class Point
{
private:
    double x;
    double y;
    char name[20];

public:
    // constructor

    Point()
    {
        this->set((char *)"none", 0.0, 0.0);
    }
    Point(char *name, double x, double y)
    {
        this->set(name, x, y);
    }

    // destuctor

    ~Point()
    {
        cout << endl;
        cout << "detete: Point " << this->name;
    }

    // set

    void set(char *name, double x, double y)
    {
        strcpy(this->name, name);
        this->x = x;
        this->y = y;
    }

    void setName(char *name)
    {
        strcpy(this->name, name);
    }
    void setX(double x)
    {
        this->x = x;
    }
    void setY(double y)
    {
        this->y = y;
    }

    // get

    char *getName()
    {
        return this->name;
    }
    double getX()
    {
        return this->x;
    }
    double getY()
    {
        return this->y;
    }

    // show

    void show()
    {
        cout << "Point(name="
             << "'" << this->name << "'"
             << ", "
             << "x=" << this->x << ", "
             << "y=" << this->y << ")";
    }

    // friend
    friend bool isInsideCircle(const Point &p, const Circle &circle);
};

class Circle
{
private:
    double radius;
    Point center;

    void init(double radius, Point &center)
    {
        this->radius = radius;
        this->center = center;
    }

public:
    // constructor

    Circle()
    {
        this->radius = 0;
    }

    Circle(double radius, Point &center)
    {
        this->init(radius, center);
    }

    // destructor

    ~Circle()
    {
        cout << endl;
        cout << "delete: Circle";
    }

    // set

    void setRadius(double radius)
    {
        this->radius = radius;
    }

    void setCenter(Point &center)
    {
        this->center = center;
        // this->center.setName((char *)"center");
    }

    // get

    double getRadius()
    {
        return this->radius;
    }

    Point getCenter()
    {
        return this->center;
    }

    // show

    void show()
    {
        cout << endl;
        cout << "Circle(radius=" << this->radius << ", center=";
        this->center.show();
        cout << ")" << endl;
    }

    // friend
    friend bool isInsideCircle(const Point &p, const Circle &circle);
};

bool isInsideCircle(const Point &p, const Circle &c)
{
    double d = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));
    return d <= c.radius;
}

int main()
{
    Point p((char *)"P", 5.5, 7.7);
    Point q((char *)"Q", 3.7, 8.7);
    Point r((char *)"R", 10.5, 12.8);

    Circle c;
    c.show();
    cout << endl;

    Circle c2(5.5, p);
    c2.show();

    // get
    cout << "radius: " << c.getRadius() << endl;
    cout << "center: ";
    c2.getCenter().show();
    cout << endl;

    // set
    c2.setRadius(5.5);
    c2.setCenter(p);
    c2.show();
    cout << endl;

    // check point inside circle
    cout << "p is " << (isInsideCircle(p, c2) ? "inside" : "outside") << " circle" << endl;
    cout << "q is " << (isInsideCircle(q, c2) ? "inside" : "outside") << " circle" << endl;
    cout << "r is " << (isInsideCircle(r, c2) ? "inside" : "outside") << " circle" << endl;

    cout << "-------------" << endl;

    return 0;
}