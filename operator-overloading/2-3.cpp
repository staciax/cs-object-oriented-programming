#include <iostream>

using namespace std;

class Rectangle
{
private:
    double width;
    double length;

public:
    // constructor
    Rectangle()
    {
        this->init(1, 1);
    }
    Rectangle(double width, double length)
    {
        this->init(width, length);
    }

    Rectangle(double width)
    {
        this->init(width, 1);
    }

    // destructor
    ~Rectangle()
    {
        cout << "delete: ";
        this->show();
    }

    // set

    void init(double width, double length)
    {
        this->width = width;
        this->length = length;
    }

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
        cout << "Rectagle("
             << "width=" << this->width << ", "
             << "length=" << this->length << ")" << endl;
    }

    // operator 8.2

    Rectangle operator++()
    {
        this->length++;
        return *this;
    }

    Rectangle operator++(int)
    {
        this->width++;
        return *this;
    }

    friend Rectangle operator--(Rectangle &self)
    {
        if (self.length > 1)
        {
            self.length--;
        }
        return self;
    }

    friend Rectangle operator--(Rectangle &self, int)
    {
        if (self.width > 1)
        {
            self.width--;
        }
        return self;
    }

    // operator 8.3

    bool operator<(Rectangle &other)
    {
        return this->area() < other.area();
    }

    bool operator<=(Rectangle &other)
    {
        return this->area() <= other.area();
    }

    bool operator>(Rectangle &other)
    {
        return this->area() > other.area();
    }

    bool operator>=(Rectangle &other)
    {
        return this->area() >= other.area();
    }

    bool operator==(Rectangle &other)
    {
        return this->area() == other.area();
    }

    bool operator!=(Rectangle &other)
    {
        return !this->operator==(other);
    }

    // spacials

    double operator[](int index)
    {
        switch (index)
        {
        case 0:
            return this->width;
        case 1:
            return this->length;
        default:
            break;
        }
        return 0;
    }

    double operator()()
    {
        return this->area();
    }
    double operator()(double width)
    {
        this->width = width;
        return this->area();
    }
    double operator()(double width, double length)
    {
        this->width = width;
        this->length = length;
        return this->area();
    }

    operator double()
    {
        return this->area();
    }
};

int main()
{
    Rectangle r(5, 10);
    double temp;

    r.show();

    // 8.1 unary

    cout << r++ << endl; //  จะไปเรียกตัวฟังชั่นที่สามารถ cast แล้ว สามารถ cout ออกมาได้ ข้างต้นมีแค่ operator double
    cout << ++r << endl;

    r.show();

    cout << r-- << endl;
    cout << --r << endl;

    r.show();

    r = ++r;
    r = --r;
    r = r++;
    r = r--;

    r.show();

    Rectangle r2(1, 1), r3;

    cout << "r2=";
    r2.show();

    // 8.2 binary

    cout << "r2 < r3 is " << (r2 < r3 ? "true" : "false") << endl;
    cout << "r2 <= r3 is " << (r2 <= r3 ? "true" : "false") << endl;
    cout << "r2 > r3 is " << (r2 > r3 ? "true" : "false") << endl;
    cout << "r2 >= r3 is " << (r2 >= r3 ? "true" : "false") << endl;
    cout << "r2 != r3 is " << (r2 != r3 ? "true" : "false") << endl;
    cout << "r2 == r3 is " << (r2 == r3 ? "true" : "false") << endl;

    double x, y, z;

    // Rectangle to double

    x = r;
    y = r2;
    z = r3;

    cout << "x=" << x << ", "
         << "y=" << y << ", "
         << "z=" << z << endl;

    // double to Rectangle

    Rectangle r4 = x;
    Rectangle r5 = y;
    Rectangle r6 = z;

    // spacial

    cout << "r[0]=" << r[0] << endl;
    cout << "r[1]=" << r[1] << endl;
    cout << "r[2]=" << r[2] << endl;

    cout << "r()=" << r() << endl;
    r.show();
    cout << "r(int)=" << r(7.1) << endl;
    r.show();
    cout << "r(int, int)=" << r(8, 15.4) << endl;
    r.show();

    cout << "---" << endl;
    return 0;
}
