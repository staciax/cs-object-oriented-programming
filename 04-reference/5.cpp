#include <iostream>

using namespace std;

class Point
{
private:
    char name[20];
    double x;
    double y;

public:
    // constuctor
    Point()
    {
        this->set((char *)"no_name", 0.0, 0.0);
    }
    Point(char *name)
    {
        this->set(name, 0.0, 0.0);
    }
    Point(char *name, double x)
    {
        this->set(name, x, 0.0);
    }
    Point(char *name, double x, double y)
    {
        this->set(name, x, y);
    }

    // destuctor
    ~Point()
    {
        cout << "delete Point: " << this->name << endl;
    }

    // set

    void set(char *name, double x, double y)
    {
        strcpy(this->name, name);
        this->x = x;
        this->y = y;
        // return *this;
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

    // more func

    double dot(Point &p) // pass by ref
    {
        p.x += 10.5;
        p.y += 7.8;
        return this->x * p.x + this->y * p.y;
    };

    Point midpoint(Point &p1, Point &p2)
    {
        return Point((char *)"midpoint", (p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
    }
};

class StackPoint
{
    int currentSize;
    int maxSize;
    Point *values;

    // init

    void init(int size)
    {
        this->currentSize = 0;
        this->maxSize = size;
        this->values = new Point[size];
    }

    void del()
    {
        delete[] this->values;
    }

public:
    // constructor
    StackPoint()
    {
        this->currentSize = 0;
        this->maxSize = 0;
        this->values = 0;
    }
    StackPoint(int maxSize)
    {
        this->init(maxSize);
    }

    // destructor

    ~StackPoint()
    {
        this->del();
        cout << "bye Stack" << endl;
    }

    // set

    // void set(int size)
    // {
    //     if (this->values != 0)
    //     {
    //         cout << "stack alreadly set" << endl;
    //         return;
    //     }
    //     this->init(size);
    // }

    // get

    bool isFull()
    {
        return this->currentSize == this->maxSize;
    }
    bool isEmpty()
    {
        return this->currentSize == 0;
    }

    int count()
    {
        return this->currentSize;
    }

    // show
    void show()
    {
        for (int i = 0; i < this->currentSize; i++)
        {
            cout << "values[" << i << "] = ";
            this->values[i].show();
        }
    }

    // func

    void push(Point &value)
    {
        if (this->isFull())
        {
            cout << "stack is full" << endl;
            return;
        }
        this->values[this->currentSize++] = value;
    }
    Point pop()
    {
        if (this->isEmpty())
        {
            cout << "stack is empty" << endl;
            return Point((char *)"out of stack");
        }
        return this->values[(this->currentSize--) - 1];
    }
};

int main()
{
    StackPoint ss(3);
    Point p1((char *)"p1", 1, 2);
    Point p2((char *)"p2", 3, 4);
    Point p3((char *)"p3", 5, 6);

    cout << "count: " << ss.count() << endl;

    cout << "push" << endl;
    ss.push(p1);
    cout << "count: " << ss.count() << endl;
    ss.push(p2);
    ss.push(p3);

    cout << "count: " << ss.count() << endl;
    ss.show();

    cout << "pop" << endl;
    Point pop1 = ss.pop();
    pop1.show();
    Point pop2 = ss.pop();
    pop2.show();

    cout << "count: " << ss.count() << endl;
    Point pop3 = ss.pop();
    pop3.show();
    Point pop4 = ss.pop();
    pop4.show();

    cout << "count: " << ss.count() << endl;

    ss.show();

    return 0;
}