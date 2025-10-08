#include <iostream>

using namespace std;

class Animal
{
public:
    Animal() {}
};

class Lion : public Animal
{
public:
    Lion() {}
    ~Lion() {}
};

class Goat : public Animal
{
public:
    Goat() {}
    ~Goat() {}
};

class Snake : public Animal
{
public:
    Snake() {}
    ~Snake() {}
};

int main()
{
    return 0;
}