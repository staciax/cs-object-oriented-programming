#include <iostream>

using namespace std;

template <class T>
class Array
{
    T *data;
    int size;

    void init(int size)
    {
        this->size = size;
        this->data = new T[size];
    }

public:
    Array()
    {
        this->init(0);
    }
    Array(int size)
    {
        this->init(size);
    }
    ~Array()
    {
        delete[] this->data;
    }

    // set
    void setSize(int size)
    {
        delete[] this->data;
        this->init(size);
    }
    void add(int index, T value)
    {
        this->data[index] = value;
    }

    // get
    int getSize()
    {
        return this->size;
    }
    T get(int index)
    {
        return this->data[index];
    }

    // show
    void show()
    {
        for (int i = 0; i < this->n; i++)
        {
            cout << "data at: " << i << " = " << this->data[i] << endl;
        }
    }

    T max()
    {
        T max = this->data[0];
        if (this->size == 0)
            return max;
        for (int i = 1; i < this->size; i++)
            if (this->data[i] > max)
                max = this->data[i];
        return max;
    }
    T min()
    {
        T min = this->data[0];
        if (this->size == 0)
            return min;
        for (int i = 1; i < this->size; i++)
            if (this->data[i] < min)
                min = this->data[i];
        return min;
    }
};

int main()
{
    // string
    Array<string> arr(5);
    arr.add(0, "one");
    arr.add(1, "x");
    arr.add(2, "zo");
    arr.add(3, "got");
    arr.add(4, "x");
    cout << "string max: " << arr.max() << endl;
    cout << "string min: " << arr.min() << endl;

    // int
    Array<int> arr2(5);
    arr2.add(0, 12);
    arr2.add(1, 2);
    arr2.add(2, 9);
    arr2.add(3, 20);
    arr2.add(4, 5);
    cout << "int max: " << arr2.max() << endl;
    cout << "int min: " << arr2.min() << endl;

    // double
    Array<double> arr3(5);
    arr3.add(0, 10.1);
    arr3.add(1, 12.2);
    arr3.add(2, 24.3);
    arr3.add(3, 35.4);
    arr3.add(4, 19.5);
    cout << "double max: " << arr3.max() << endl;
    cout << "double min: " << arr3.min() << endl;
    return 0;
}