#include <iostream>

using namespace std;

class Fridge
{
private:
public:
    Fridge()
    {
    }
    ~Fridge()
    {
    }
};

class Stove
{
private:
public:
    Stove()
    {
    }
    ~Stove()
    {
    }
};

class Microwave
{
private:
public:
    Microwave()
    {
    }
    ~Microwave()
    {
    }
};

class Pot
{
private:
public:
    Pot()
    {
    }
    ~Pot()
    {
    }
};

class Kitchen
{
private:
    Fridge fridge;
    Stove stove;
    Microwave microwave;
    Pot pot;

public:
    Kitchen()
    {
    }
    ~Kitchen()
    {
    }
};

int main()
{
    Kitchen kitchen;

    return 0;
}