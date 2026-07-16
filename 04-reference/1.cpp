#include <iostream>
#include <cstring>

using namespace std;

class Point
{
private:
    static int num;
    char name[20];
    double x;
    double y;

public:
    // constuctor
    Point()
    {
        num++;
        this->set((char *)"no_name", 0.0, 0.0);
    }
    Point(char *name)
    {
        num++;
        this->set(name, 0.0, 0.0);
    }
    Point(char *name, double x)
    {
        num++;
        this->set(name, x, 0.0);
    }
    Point(char *name, double x, double y)
    {
        num++;
        this->set(name, x, y);
    }

    // destuctor
    ~Point()
    {
        num--;
        cout << "delete Point: " << this->name << endl;
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
             << "y=" << this->y << ")" << endl;
    }

    // static

    int static count()
    {
        return num;
    }

    // more func

    // Point &midpoint(Point &p1, Point &p2)
    // {
    //     return *this;
    // }

    double dot(Point &p)
    {
        return this->x * p.x + this->y * p.y;
    };

    Point midpoint(Point &p1, Point &p2)
    {
        this->set((char *)"midpoint", (p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
        // return Point(this->name, this->x, this->y);
        // return *this;
        Point p(this->name, this->x, this->y);
        return p;
    }
};

int Point::num;

int main()
{
    Point p;
    Point p2((char *)"p2", 2, 3);
    Point p3((char *)"p3", 4, 5);

    cout << "p2.dot(p3) = " << p2.dot(p3) << endl;
    cout << "p3.dot(p2) = " << p3.dot(p2) << endl;

    p2.show();
    p3.show();

    cout << "---" << endl;

    Point pmid;
    pmid = p.midpoint(p2, p3);
    pmid.show();

    p.show();

    cout << "count: " << Point::count() << endl;

    // cout << endl;
    // cout << "count: " << Point::count() << endl;
    // p.show();
    // p.set((char *)"p", 9.4, 15.2);
    // p.show();
    // p.setName((char *)"p");
    // p.setX(1.5 * p.getX());
    // p.setY(2.2 * p.getY());
    // cout << "p.getName() = " << p.getName() << endl;
    // cout << "p.getX() = " << p.getX() << endl;
    // cout << "p.getY() = " << p.getY() << endl;
    // p.show();

    // cout << "count: " << Point::count() << endl;

    return 0;
}
