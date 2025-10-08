#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
private:
    double x;
    double y;

public:
    // constuctor
    Complex()
    {
        this->set(0.0, 0.0);
    }
    Complex(double x, double y)
    {
        this->set(x, y);
    }

    // destructor

    ~Complex()
    {
        cout << "bye complex" << endl;
    }

    // set

    void set(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    void setX(double value)
    {
        this->x = value;
    }
    void setY(double value)
    {
        this->y = value;
    }

    // get

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
        cout << "Complex("
             << "x=" << this->x << ", "
             << "y=" << this->y << ")" << endl;
    }

    // any

    double number()
    {
        return sqrt(pow(this->x, 2) + pow(this->y, 2));
    }
};

int main()
{
    Complex c(1, 2);
    cout << c.number() << endl;
    return 0;
}