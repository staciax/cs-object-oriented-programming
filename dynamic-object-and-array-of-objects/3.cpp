#include <iostream>

using namespace std;

class Queue
{
private:
    int *values;
    int maxSize;
    int currentSize;

    // init

    void init(int size)
    {
        this->maxSize = size;
        this->currentSize = 0;
        this->values = new int[size];
    }

    void del()
    {
        delete[] this->values;
    }

public:
    // constructor
    Queue()
    {
        this->maxSize = 0;
        this->currentSize = 0;
        this->values = 0;
    }
    Queue(int maxSize)
    {
        this->init(maxSize);
    }

    // destructor

    ~Queue()
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
            cout << "values[" << i << "]= " << this->values[i] << endl;
        }
    }

    // process

    void insert(int value)
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
    Queue q(5);
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);
    q.insert(5);
    q.show();
    if (q.isFull())
    {
        cout << "Queue is full" << endl;
    }
    q.remove();
    q.remove();
    cout << "count: " << q.count() << endl;
    q.show();
    q.remove();
    q.remove();
    q.remove();
    cout << "count: " << q.count() << endl;
    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }

    // overload constructor
    cout << "-----" << endl;
    Queue q2(3);
    cout << "count: " << q2.count() << endl;
    if (q2.isEmpty())
    {
        cout << "Queue 2 is empty" << endl;
    }
    if (!q2.isFull())
    {
        cout << "Queue 2 is not full" << endl;
    }

    return 0;
}