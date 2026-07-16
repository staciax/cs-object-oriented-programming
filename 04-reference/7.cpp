#include <iostream>

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

    // require

    Matrix plus(Matrix &m1, Matrix &m2)
    {
        Matrix mx;
        if (m1.row != m2.row || m1.column != m2.column)
        {
            cout << "m1 and m2 must have same size" << endl;
            return mx;
        }
        mx.resize(m1.row, m1.column);
        int result;
        for (int i = 0; i < mx.row; i++)
        {
            for (int j = 0; j < mx.column; j++)
            {
                result = m1.getValue(i, j) + m2.getValue(i, j);
                mx.setValueAt(i, j, result);
            }
        }
        return mx;
    }

    Matrix minus(Matrix &m1, Matrix &m2)
    {
        Matrix mx;
        if (m1.row != m2.row || m1.column != m2.column)
        {
            cout << "m1 and m2 must have same size" << endl;
            return mx;
        }
        mx.resize(m1.row, m1.column);
        int result;
        for (int i = 0; i < mx.row; i++)
        {
            for (int j = 0; j < mx.column; j++)
            {
                result = m1.getValue(i, j) - m2.getValue(i, j);
                mx.setValueAt(i, j, result);
            }
        }
        return mx;
    }
};

int main()
{
    Matrix m1(2, 2);
    cout << "m1 set values" << endl;
    m1.setValues();
    Matrix m2(2, 2);
    cout << "m2 set values" << endl;
    m2.setValues();

    cout << "m1" << endl;
    m1.show();
    cout << "m2" << endl;
    m2.show();

    cout << "m1+m2" << endl;
    Matrix m1p2 = m1.plus(m1, m2);
    m1p2.show();
    cout << "m1-m2" << endl;
    Matrix m1m2 = m1.minus(m1, m2);
    m1m2.show();

    return 0;
}