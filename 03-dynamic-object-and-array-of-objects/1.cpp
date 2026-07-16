#include <iostream>

using namespace std;

class Vector
{
private:
    int size;
    int *values;

    // init

    void init(int size)
    {
        this->size = size;
        this->values = new int[size];
    }

    void del()
    {
        delete[] this->values;
    }

public:
    // constructor
    Vector()
    {
        this->size = 0;
        this->values = 0;
    }
    Vector(int size)
    {
        this->init(size);
    }

    // destructor

    ~Vector()
    {
        this->del();
        cout << "bye Vector" << endl;
    }

    // set

    void setValueAt(int index, int value)
    {
        this->values[index] = value;
    }

    void setValues()
    {
        cout << "Enter: " << endl;
        for (int i = 0; i < this->size; i++)
        {
            cout << "values[" << i << "]= ";
            cin >> this->values[i];
        }
    }

    // get

    int getValue(int index)
    {
        if (index > this->size)
        {
            return -1;
        }
        return this->values[index];
    }

    int length()
    {
        // int len;
        // for (int i = 0; i < this->size; i++)
        // {
        //     if (this->values[i] != 0)
        //     {
        //         len++;
        //     }
        // }
        // return len;
        return this->size;
    }

    // show

    void show()
    {
        cout << "Show: " << endl;
        for (int i = 0; i < this->size; i++)
        {
            cout << "values[" << i << "]= " << this->values[i] << endl;
        }
    }

    // process

    void resize(int newSize)
    {
        this->del();
        this->init(newSize);
        // for (int i = 0; i < this->size; ++i)
        //     newArray[i] = this->values[i];
    }
};

int main()
{
    Vector v(5);
    v.setValues();
    cout << "----" << endl;
    v.show();
    cout << "length: " << v.length() << endl;
    cout << "----" << endl;
    cout << "resize from 5 to 2" << endl;
    v.resize(2);
    cout << "length: " << v.length() << endl;
    cout << "----" << endl;
    v.show();
    cout << "----" << endl;
    cout << "resize from 2 to 10" << endl;
    v.resize(10);
    v.show();

    // constructor overload
    Vector v2(10);
    v2.setValues();
    v2.show();

    return 0;
}