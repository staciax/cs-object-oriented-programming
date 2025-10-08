#include <iostream>

using namespace std;

class Vehicle
{
public:
    Vehicle() {}
    ~Vehicle() {}
};

class Plane : public Vehicle
{
public:
    Plane() {}
    ~Plane() {}
};

class Car : public Vehicle
{
public:
    Car() {}
    ~Car() {}
};

class Boat : public Vehicle
{
public:
    Boat() {}
    ~Boat() {}
};

int main()
{
    return 0;
}