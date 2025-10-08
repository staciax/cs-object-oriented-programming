#include <iostream>

using namespace std;

class Animal
{
public:
    Animal() {}
    ~Animal() {}
};

class Quadruped : Animal
{
public:
    Quadruped() {}
    ~Quadruped() {}
};

class Biped : public Animal
{
public:
    Biped() {}
    ~Biped() {}
};

class Poultry : public Biped
{
public:
    Poultry() {}
    ~Poultry() {}
};

int main()
{
    return 0;
}