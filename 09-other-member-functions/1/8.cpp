#include <iostream>

using namespace std;

class Animal
{
public:
    Animal() {}
    ~Animal() {}
};

class Fish : public Animal
{
public:
    Fish() {}
    ~Fish() {}
};

class Seahorse : public Fish
{
public:
    Seahorse() {}
    ~Seahorse() {}
};

class Horse : public Animal
{
public:
    Horse() {}
    ~Horse() {}
};

int main()
{
    return 0;
}