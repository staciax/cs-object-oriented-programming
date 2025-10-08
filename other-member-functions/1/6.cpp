#include <iostream>

using namespace std;

class Person
{
public:
    Person() {}
    ~Person() {}
};

class Singer : public Person
{
public:
    Singer() {}
    ~Singer() {}
};

class JaseSinger : public Singer
{
public:
    JaseSinger() {}
    ~JaseSinger() {}
};

class PopSinget : public Singer
{
public:
    PopSinget() {}
    ~PopSinget() {}
};

class RockSinger : public Singer
{
public:
    RockSinger() {}
    ~RockSinger() {}
};

int main()
{
    return 0;
}