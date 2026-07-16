#include <iostream>

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

    // require

    double plus(Rational &r1, Rational &r2)
    {
        return r1.result() + r2.result();
    }
    double minus(Rational &r1, Rational &r2)
    {
        return r1.result() - r2.result();
    }
};

int main()
{
    Rational r;
    r.show();
    Rational r1(1, 2);
    r.show();
    Rational r2(2, 3);
    r1.show();
    cout << "r1 = " << r1.result() << endl;
    cout << "r2 = " << r2.result() << endl;
    cout << "r1+r2 = " << r1.plus(r1, r2) << endl;
    cout << "r1-r2 = " << r1.minus(r1, r2) << endl;
    return 0;
}