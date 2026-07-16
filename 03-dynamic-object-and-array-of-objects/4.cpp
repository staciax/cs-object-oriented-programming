#include <iostream>
#include <cmath>

using namespace std;

class Matrix
{
private:
    int column, row;
    int **values;

    void init(int column, int row)
    {
        this->column = column;
        this->row = row;

        // set up row
        this->values = new int *[row];

        // set up colums
        for (int i = 0; i < row; i++)
        {
            this->values[i] = new int[column];
        }
    }

    void del()
    {
        // delete column
        for (int i = 0; i < this->row; i++)
        {
            delete[] this->values[i];
        }

        // delete row
        delete[] this->values;
    }

public:
    // constructor
    Matrix()
    {
        this->init(0, 0);
    }
    Matrix(int column, int row)
    {
        this->init(column, row);
    }

    // destructor
    ~Matrix()
    {
        if (this->values == 0)
        {
            return;
        }

        this->del();
    }

    // set

    void setValueAt(int row, int column, int value)
    {
        this->values[row][column] = value;
    }

    void setValues()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                cout << "Input values[" << i << "][" << j << "] = ";
                cin >> this->values[i][j];
            }
        }
    }

    // get

    int getValue(int column, int row)
    {
        if (column > this->column)
        {
            return -1;
        }
        if (row > this->row)
        {
            return -1;
        }
        return this->values[column][row];
    }

    // show

    void show()
    {
        cout << endl;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                cout << "values[" << i << "][" << j << "] = " << this->values[i][j] << endl;
            }
        }
    }

    // func

    void reset()
    {
        delete[] this->values;
        this->init(this->column, this->row);
    }

    int trace()
    {
        int sum = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                sum += this->values[i][j];
            }
        }
        return sum;
    }

    void resize(int row, int column)
    {
        this->del();
        this->init(row, column);
    }
};

int main()
{
    Matrix x(2, 3);
    x.setValues();
    x.show();
    cout << "trace: " << x.trace() << endl;
    x.reset();

    cout << "after reset: " << endl;
    x.show();

    // overload constructor
    cout << "-----" << endl;
    Matrix x2(2, 3);
    x2.show();

    return 0;
}
