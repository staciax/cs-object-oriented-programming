#include <iostream>

using namespace std;

class Rectagle
{
private:
    double width;
    double length;

public:
    Rectagle()
    {
        this->setWidth(0);
        this->setLength(0);
    }
    Rectagle(double width)
    {
        this->setWidth(width);
        this->setLength(0);
    }
    Rectagle(double width, double length)
    {
        this->setWidth(width);
        this->setLength(length);
    }
    ~Rectagle()
    {
        cout << "bye Rectagle" << endl;
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
};

class QueueRectagle
{
private:
    Rectagle *values;
    int maxSize;
    int currentSize;

    // init

    void init(int size)
    {
        this->maxSize = size;
        this->currentSize = 0;
        this->values = new Rectagle[size];
    }

    void del()
    {
        delete[] this->values;
    }

public:
    // constructor
    QueueRectagle()
    {
        this->maxSize = 0;
        this->currentSize = 0;
        this->values = 0;
    }
    QueueRectagle(int maxSize)
    {
        this->init(maxSize);
    }

    // destructor

    ~QueueRectagle()
    {
        this->del();
        cout << "bye queue" << endl;
    }

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

    // process

    void insert(Rectagle &value)
    {
        if (this->isFull())
        {
            cout << "queue is full" << endl;
            return;
        }
        this->values[this->currentSize++] = value;
    }

    void remove()
    {
        if (this->isEmpty())
        {
            cout << "queue is empty" << endl;
            return;
        }
        // int remove = this->values[0];
        for (int i = 0; i < this->currentSize - 1; i++)
        {
            this->values[i] = this->values[i + 1];
        }
        this->currentSize--;
        // return remove;
    }
};

int main()
{
    QueueRectagle q(3);
    cout << "count: " << q.count() << endl;

    Rectagle r1(1, 2);
    Rectagle r2(3, 4);
    Rectagle r3(5, 6);
    Rectagle r4(7, 8);

    cout << " --- insert --- " << endl;

    q.insert(r1);
    q.insert(r2);
    cout << "count: " << q.count() << endl;
    q.insert(r3);
    q.insert(r4);

    cout << "count: " << q.count() << endl;
    q.show();

    if (q.isFull())
    {
        cout << "QueueRectagle is full" << endl;
    }

    cout << " --- remove --- " << endl;
    q.remove();
    q.remove();
    cout << "count: " << q.count() << endl;
    q.show();
    q.remove();
    q.remove(); // empty
    q.remove(); // empty
    cout << "count: " << q.count() << endl;
    if (q.isEmpty())
    {
        cout << "QueueRectagle is empty" << endl;
    }

    // // overload constructor
    cout << "-----" << endl;
    QueueRectagle q2(3);
    cout << "count: " << q2.count() << endl;
    if (q2.isEmpty())
    {
        cout << "QueueRectagle 2 is empty" << endl;
    }
    if (!q2.isFull())
    {
        cout << "QueueRectagle 2 is not full" << endl;
    }
    cout << "-----" << endl;
    return 0;
}