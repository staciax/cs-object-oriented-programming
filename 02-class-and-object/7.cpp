#include <iostream>
#include <cmath>

using namespace std;

class Rational
{
private:
    double fraction;
    double numerator;

public:
    // constructor

    Rational()
    {
        this->set(0, 0);
    }
    Rational(double fraction, double numerator)
    {
        this->set(fraction, numerator);
    }

    // destructor

    ~Rational()
    {
        cout << "bye Rational" << endl;
    }

    // set

    void set(double fraction, double numerator)
    {
        this->fraction = fraction;
        this->numerator = numerator;
    }

    void setFraction(double fraction)
    {
        this->fraction = fraction;
    }

    void setNumerator(double numerator)
    {
        this->numerator = numerator;
    }

    // get

    double getFraction()
    {
        return this->fraction;
    }

    double getNumerator()
    {
        return this->numerator;
    }

    // show

    void show()
    {
        cout << "Rational("
             << "fraction=" << this->fraction << ", "
             << "numerator=" << this->numerator << ")" << endl;
    }

    double result()
    {
        return this->fraction / this->numerator;
    }
};

int main()
{
    Rational r;
    r.show();
    r.set(1, 2);
    r.show();
    cout << r.result() << endl;
    r.show();
}