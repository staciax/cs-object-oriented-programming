#include <iostream>

using namespace std;

class Animal
{
};

class Quadruped : Animal
{
};

class Biped : public Animal
{
};

class Poultry : public Biped
{
};

int main()
{
    return 0;
}