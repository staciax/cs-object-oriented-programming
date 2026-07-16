#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Point
{
private:
    // attr
    string name;
    char name2[20];
    double x;
    double y;

public:
    // setter
    void setName(string value)
    {
        this->name = value;
    }

    void setName2(string value)
    {
        strcpy(this->name2, value.c_str());
    }

    void setX(double value)
    {
        this->x = value;
    }

    void setY(double value)
    {
        this->y = value;
    }

    void setXY(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    // getter

    string getName()
    {
        return this->name;
    }

    char *getName2()
    {
        return this->name2;
    }

    double getX()
    {
        return this->x;
    }

    double getY()
    {
        return this->y;
    }

    // display
    void show()
    {
        cout << "name : " << this->name << endl;
        cout << "name2 : " << this->name2 << endl;
        cout << "X : " << this->x << endl;
        cout << "Y : " << this->y << endl;
    }
};

int main()
{
    Point p;
    p.setName("stacia");
    p.setName2("stacia");
    p.setXY(5.5, 6.6);
    p.show();

    cout << "====================" << endl;
    cout << "x : " << p.getX() << endl;
    cout << "y : " << p.getY() << endl;
    cout << "name : " << p.getName() << endl;
    cout << "name2 : " << p.getName2() << endl;

    return 0;
}