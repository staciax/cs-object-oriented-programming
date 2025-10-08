#include <iostream>

using namespace std;

class Vehicle
{
    int speed;
    string color;

public:
    Vehicle()
    {
        this->init(40, "white");
    }
    Vehicle(int speed, string color)
    {
        this->init(speed, color);
    }
    ~Vehicle()
    {
        cout << "delete: Vehicle" << endl;
    }

    // set
    void init(int speed, string color)
    {
        this->speed = speed;
        this->color = color;
    }
    void setSpeed(int speed)
    {
        this->speed = speed;
    }
    void setColor(string color)
    {
        this->color = color;
    }

    // get
    int getSpeed()
    {
        return this->speed;
    }
    string getColor()
    {
        return this->color;
    }

    // show
    void show()
    {
        cout << "Vehicle("
             << "speed=" << this->speed << " ,"
             << "color=" << this->color << ")" << endl;
    }
};

class Bogie
{
    string station;
    int type; // 1, 2

public:
    Bogie()
    {
        this->init("none", 1);
    }
    Bogie(string station, int type)
    {
        this->init(station, type);
    }
    ~Bogie()
    {
        cout << "delete: Bogie " << this->station << endl;
    }

    // set
    void init(string station, int type)
    {
        this->station = station;
        this->type = type;
    }
    void setStation(string station)
    {
        this->station = station;
    }
    void setType(int type)
    {
        this->type = type;
    }

    // get
    string getStation()
    {
        return this->station;
    }
    int getType()
    {
        return this->type;
    }

    // show
    void show()
    {
        cout << "Bogie("
             << "station=" << this->station << ", "
             << "type=" << this->type << ")" << endl;
    }
};

class Train : public Vehicle
{
    int count;
    Bogie *bogies;

    void init(int bogieCount)
    {
        this->bogies = new Bogie[bogieCount];
        this->count = bogieCount;
    }
    void clear()
    {
        delete[] this->bogies;
    }

public:
    Train()
    {
        this->init(1);
    }
    Train(int speed, string color, int bogieCount) : Vehicle(speed, color)
    {
        this->init(bogieCount);
    }
    ~Train()
    {
        this->clear();
        cout << "delete: Train" << endl;
    }

    // set
    void setBogieAt(int index, string station, int type)
    {
        if (index > (this->count - 1))
        {
            return;
        }
        this->bogies[index].init(station, type);
    }

    void reset(int count)
    {
        this->clear();
        this->init(count);
    }

    // get
    int getBogieCount()
    {
        return this->count;
    }
    Bogie *getBogies()
    {
        return this->bogies;
    }

    // show
    void show()
    {
        Vehicle::show();
        cout << "Train(" << endl;
        for (int i = 0; i < this->count; i++)
        {
            cout << " ";
            this->bogies[i].show();
        }
        cout << ")" << endl;
    }
};

class Bus : public Vehicle
{
private:
    int floor;

public:
    Bus()
    {
        this->floor = 1;
    }
    Bus(int speed, string color, int floor) : Vehicle(speed, color)
    {
        this->floor = floor;
    }
    ~Bus()
    {
        cout << "delete: Bus" << endl;
    }

    // set
    void setFloor(int floor)
    {
        this->floor = floor;
    }

    // get
    int getFloor()
    {
        return this->floor;
    }

    // show
    void show()
    {
        Vehicle::show();
        cout << "Bus("
             << "floor=" << this->floor << ")" << endl;
    }
};

int main()
{
    Train t(120, "blue", 5);
    t.setBogieAt(0, "A", 1);
    t.setBogieAt(1, "B", 2);
    t.setBogieAt(2, "C", 1);
    t.setBogieAt(3, "D", 2);
    t.setBogieAt(4, "E", 1);
    t.show();
    t.reset(1);
    t.setBogieAt(0, "F", 1);
    t.show();

    Bus b(80, "white", 2);
    b.show();

    return 0;
}