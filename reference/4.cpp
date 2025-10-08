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
        cout << "bye Vector" << endl;
    }

    // destructor

    ~Vector()
    {
        this->del();
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

    // require

    Vector static plus(Vector &v1, Vector &v2)
    {
        cout << v1.length();
        Vector vp(v1.length());
        for (int i = 0; i < v1.length(); i++)
        {
            vp.setValueAt(i, v1.getValue(i) + v2.getValue(i));
        }
        return vp;
    }
    Vector static minus(Vector &v1, Vector &v2)
    {
        cout << v1.length();
        Vector vm(v1.length());
        for (int i = 0; i < v1.length(); i++)
        {
            vm.setValueAt(i, v1.getValue(i) - v2.getValue(i));
        }
        return vm;
    }
};

int main()
{
    Vector v;
    Vector v1(3);
    v1.setValues();
    Vector v2(3);
    v2.setValues();

    cout << "v1+v2" << endl;
    Vector v3 = Vector::plus(v1, v2);
    v3.show();
    cout << "v1-v2" << endl;
    Vector v4 = Vector::minus(v1, v2);
    v4.show();

    return 0;
}