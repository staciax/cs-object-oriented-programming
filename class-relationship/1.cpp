#include <iostream>

using namespace std;

class Driver
{
private:
public:
    Driver()
    {
    }
    ~Driver()
    {
    }
};

class Truck
{
private:
    Driver driver;

public:
    Truck()
    {
    }
    ~Truck()
    {
    }
};

int main()
{
    Truck truck;
    return 0;
}