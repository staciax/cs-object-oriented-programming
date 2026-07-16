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

    Complex plus(Complex &a, Complex &b, Complex &c, Complex &d)
    {
        // (a,b)+(c,d)=(a+c,b+d)
        return Complex(a.number() + c.number(), d.number() + d.number());
    }

    Complex times(Complex &a, Complex &b, Complex &c, Complex &d)
    {
        // (a,b)*(c,d)=(ac-bd,ad+bc)
        double x = a.number() * c.number() - b.number() * d.number(); // ac-bd
        double y = a.number() * d.number() + b.number() * c.number(); // ad+bc
        return Complex(x, y);
    }
};

int main()
{
    Complex c(1, 2);
    c.set(3, 4);
    cout << "c X: " << c.getX() << endl;
    cout << "c Y: " << c.getY() << endl;
    c.show();
    cout << c.number() << endl;
    return 0;
}