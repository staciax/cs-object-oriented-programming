#include <iostream>
#include <string>

using namespace std;

class Rectagle
{
private:
    static int num;
    double width;
    double length;

public:
    Rectagle()
    {
        num++;
        this->setWidth(0);
        this->setLength(0);
    }
    Rectagle(double width)
    {
        num++;
        this->setWidth(width);
        this->setLength(0);
    }
    Rectagle(double width, double length)
    {
        num++;
        this->setWidth(width);
        this->setLength(length);
    }
    ~Rectagle()
    {
        num--;
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

    // show

    void show()
    {
        cout << "Rectagle("
             << "width=" << this->width << ", "
             << "length=" << this->length << ")" << endl;
    }

    // process

    double perimeter()
    {
        return (this->width + this->length) * 2;
    }

    double area()
    {
        return this->width * this->length;
    }

    // static

    static int count()
    {
        return num;
    }
};

int Rectagle::num;

int main()
{
    cout << endl;
    cout << Rectagle::count() << endl;

    Rectagle sq;
    sq.setWidth(7.5);
    sq.setLength(10.8);

    cout << "width: " << sq.getWidth() << endl;
    cout << "length: " << sq.getWidth() << endl;
    cout << "perimeter : " << sq.perimeter() << endl;
    cout << "area : " << sq.area() << endl;
    cout << "====================" << endl;
    sq.show();

    {
        Rectagle sq2(5);
        Rectagle sq3(5, 10);
        cout << Rectagle::count() << endl;
    }
    cout << Rectagle::count() << endl;
    return 0;
}