#include <iostream>

using namespace std;

class Stack
{
    int currentSize;
    int maxSize;
    int *values;

    // init

    void init(int size)
    {
        this->currentSize = 0;
        this->maxSize = size;
        this->values = new int[size];
    }

    void del()
    {
        delete[] this->values;
    }

public:
    // constructor
    Stack()
    {
        this->currentSize = 0;
        this->maxSize = 0;
        this->values = 0;
    }
    Stack(int maxSize)
    {
        this->init(maxSize);
    }

    // destructor

    ~Stack()
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
            cout << "values[" << i << "]= " << this->values[i] << endl;
        }
    }

    // func

    void push(int value)
    {
        if (this->isFull())
        {
            cout << "stack is full" << endl;
            return;
        }
        this->values[this->currentSize++] = value;
    }
    int pop()
    {
        if (this->isEmpty())
        {
            cout << "stack is empty" << endl;
            return -1;
        }
        return this->values[(this->currentSize--) - 1];
    }
};

int main()
{
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3); // full
    if (s.isFull())
    {
        cout << "Stack is full" << endl;
    }
    s.show();
    cout << "count: " << s.count() << endl;
    cout << "pop: " << s.pop() << endl;
    cout << "count: " << s.count() << endl;
    s.show();
    cout << "pop: " << s.pop() << endl;
    cout << "count: " << s.count() << endl;
    cout << "pop: " << s.pop() << endl;
    cout << "count: " << s.count() << endl;
    if (s.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    // overload constructor
    cout << "-----" << endl;
    Stack s2(3);
    cout << "count: " << s2.count() << endl;
    if (s2.isEmpty())
    {
        cout << "Stack 2 is empty" << endl;
    }
    if (!s2.isFull())
    {
        cout << "Stack 2 is not full" << endl;
    }

    return 0;
}