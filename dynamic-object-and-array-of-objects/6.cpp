#include <iostream>

using namespace std;

class Rectangle
{
private:
    double width;
    double length;

public:
    // constructor
    Rectangle()
    {
        this->set(0, 0);
    }
    Rectangle(double width, double length)
    {
        this->set(width, length);
    }

    // destructor
    ~Rectangle()
    {
        cout << "bye rectagle" << endl;
    }

    // set

    void set(double width, double length)
    {
        this->width = width;
        this->length = length;
    }

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
        cout << "Rectangle(width=" << this->width << ", "
             << "length=" << this->length << ", "
             << "area=" << this->area() << ", "
             << "perimeter=" << this->perimeter() << ")" << endl;
    }

    // func
    double area()
    {
        return (this->width * this->length);
    }

    double perimeter()
    {
        return (this->width + this->length) * 2;
    }
};

class MyRect
{
private:
    int row, column;
    Rectangle **rectangles;

    void init(int row, int column)
    {
        this->row = row;
        this->column = column;
        this->rectangles = new Rectangle *[row];
        for (int i = 0; i < row; i++)
        {
            this->rectangles[i] = new Rectangle[column];
        }
    }

    void del()
    {
        // delete colums
        for (int i = 0; i < this->row; i++)
        {
            delete[] this->rectangles[i];
        }
        // delete row
        delete[] this->rectangles;
    }

public:
    // constructor
    MyRect()
    {
        this->init(0, 0);
    }
    MyRect(int row, int column)
    {
        this->init(row, column);
    }

    // descturctor
    ~MyRect()
    {
        this->del();
        cout << "bye MyRect" << endl;
    }

    // set
    void set()
    {
        int w, l;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                cout << "ractagles[" << i << "][" << j << "] =" << endl;
                cout << "width: ";
                cin >> w;
                cout << "length: ";
                cin >> l;
                this->rectangles[i][j].set(w, l);
            }
        }
    }

    void set2(Rectangle &rectagle, int row, int column)
    {
        if (row >= this->row || column >= this->column)
        {
            cout << "row or column overflow" << endl;
            return;
        }
        this->rectangles[row][column] = rectagle;
    }

    void set3(int row, int column, double width, double length)
    {
        if (row >= this->row || column >= this->column)
        {
            cout << "row or column overflow" << endl;
            return;
        }
        this->rectangles[row][column].set(width, length);
    }

    // get

    Rectangle getRect(int row, int column)
    {
        return this->rectangles[row][column];
    }

    // show
    void show()
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                cout << "ractagles[" << i << "][" << j << "] = ";
                this->rectangles[i][j].show();
            }
        }
    }

    // reset
    void reset(int row, int column)
    {
        if (row == this->row && column == this->column)
        {
            return;
        }
        this->del();
        this->init(row, column);
    }

    // validate
};

int main()
{
    int r, c;
    double w, l;
    MyRect mrd;

    MyRect mr(2, 3);
    cout << "-- set 1 --" << endl;
    mr.set();
    mr.show();

    cout << "-- set 2 --" << endl;
    cout << "row: ";
    cin >> r;
    cout << "column: ";
    cin >> c;
    Rectangle r2(199, 299);
    mr.set2(r2, r, c);
    mr.getRect(r, c).show();

    cout << "-- set 3 --" << endl;
    cout << "row: ";
    cin >> r;
    cout << "column: ";
    cin >> c;
    cout << "width: ";
    cin >> w;
    cout << "length: ";
    cin >> l;
    mr.set3(r, c, w, l);

    cout << "-- get rect --" << endl;
    cout << "row: ";
    cin >> r;
    cout << "column: ";
    cin >> c;
    Rectangle rect = mr.getRect(r, c);
    rect.show();

    cout << "-- after reset -- " << endl;
    mr.reset(3, 2);
    mr.show();

    return 0;
}