#include <iostream>
#include <string>
#include <exception>

using namespace std;

// 12.6
class RoException : public exception
{
public:
    const char *what() const throw()
    {
        return "ro exception";
    }
};

class Novice
{
public:
    Novice()
    {
        cout << "new: Novice" << endl;
    }
    virtual ~Novice()
    {
        cout << "delete: Novice" << endl;
    }
    virtual void attack()
    {
        throw 10;
    }
    virtual void buff()
    {
        throw "novice buff";
    }
    virtual void move(double meter)
    {
        throw meter;
    }
    void buffMoveAttack()
    {
        // 12.4
        try
        {
            this->buff();
            try
            {
                this->move(5);
                try
                {
                    this->attack();
                }
                catch (int i)
                {
                    cout << i << endl;
                }
            }
            catch (double d)
            {
                cout << d << endl;
            }
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }

    virtual void teleport()
    {
        throw RoException();
    }
};

class Alchemist : public Novice
{
public:
    Alchemist()
    {
        cout << "new: Alchemist" << endl;
    }
    ~Alchemist()
    {
        cout << "delete: Alchemist" << endl;
    }
    void attack() throw()
    {
        throw 16.7;
    }
    void buff()
    {
        throw "alchemist buff";
    }
    void move()
    {
        throw "alchemist buff";
    }
    void teleport()
    {
        cout << "teleport to prontera" << endl;
    }
};

int main()
{
    // 12.3
    try
    {
        Alchemist alchemist;
        throw alchemist;
    }
    catch (Alchemist)
    {
        cout << "catch Alchemist" << endl;
    }
    catch (Novice)
    {
        cout << "catch Novice" << endl;
    }
    catch (...)
    {
        cout << "no catch" << endl;
    }

    // ลองสลับ Novice -> Alchemist
    try
    {
        Alchemist alchemist;
        throw alchemist;
    }
    catch (Novice)
    {
        cout << "catch Novice" << endl;
    }
    catch (Alchemist)
    {
        cout << "catch Alchemist" << endl;
    }
    catch (...)
    {
        cout << "no catch" << endl;
    }

    // 12.6

    Novice *n[2];
    n[0] = new Novice();
    n[1] = new Alchemist();

    for (int i = 0; i < 2; i++)
    {
        try
        {
            n[i]->teleport();
        }
        catch (RoException e)
        {
            cout << e.what();
            cout << endl;
        }
    }

    return 0;
}