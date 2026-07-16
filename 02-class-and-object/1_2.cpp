#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Point
{
private:
    // attr
    static int num;
    string FirstName;
    char lastName[20];
    double x;
    double y;

public:
    // constructor
    Point()
    {
        num++;
        this->setAll("noname", "nolastname", 0, 0);
    }
    Point(string firstName)
    {
        num++;
        this->setAll(firstName, "nolastname", 0, 0);
    }
    Point(string firstName, char *lastName)
    {
        num++;
        this->setAll(firstName, lastName, 0, 0);
    }
    Point(string firstName, char *lastName, double x)
    {
        num++;
        this->setAll(firstName, lastName, x, 0);
    }
    Point(string firstName, char *lastName, double x, double y)
    {
        num++;
        this->setAll(firstName, lastName, x, y);
    }

    ~Point()
    {
        num--;
        cout << "DEAD: " << this->FirstName << endl;
    }

    // setter
    void setFirstName(string value)
    {
        this->FirstName = value;
    }

    void setLastName(char *value)
    {
        strcpy(this->lastName, value);
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

    void setAll(string FirstName, char *lastName, double x, double y)
    {
        this->setFirstName(FirstName);
        this->setLastName(lastName);
        this->setX(x);
        this->setY(y);
    }

    // getter

    string getFirstName()
    {
        return this->FirstName;
    }

    char *getLastName()
    {
        return this->lastName;
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
        cout << "first name : " << this->FirstName << endl;
        cout << "last name : " << this->lastName << endl;
        cout << "X : " << this->x << endl;
        cout << "Y : " << this->y << endl;
    }

    static int count()
    {
        return num;
    }
};

int Point::num;

int main()
{
    cout << endl;
    cout << Point::count() << endl;
    Point p;

    // try setter
    p.setX(5.5);
    p.setY(6.6);
    p.setXY(7.7, 8.8);
    p.show();

    // try getter
    cout << "====================" << endl;
    cout << "first name : " << p.getFirstName() << endl;
    cout << "last name : " << p.getLastName() << endl;
    cout << "x : " << p.getX() << endl;
    cout << "y : " << p.getY() << endl;
    cout << "====================" << endl;

    cout << Point::count() << endl;
    {
        Point p2("stacia 01");
        Point p3("stacia 02", "moon");

        cout << Point::count() << endl;
    }

    Point p4("stacia 03", "moon", 3.3);
    Point p5("stacia 04", "moon", 3.3, 4.4);

    cout << Point::count() << endl;

    return 0;
}