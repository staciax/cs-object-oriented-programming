#include <iostream>

using namespace std;

template <class T>
void f(T value)
{
    // 12.1 - 12.2
    try
    {
        throw value;
    }
    catch (int i)
    {
        cout << "int " << i << endl;
    }
    catch (double d)
    {
        cout << "double " << d << endl;
    }
    catch (char c)
    {
        cout << "char " << c << endl;
    }
    catch (char *ca)
    {
        cout << "char* " << ca << endl;
    }
    catch (...)
    {
        cout << "other" << endl;
    }
}

int main()
{
    f(1);
    f(2.5);
    f('s');
    f((char *)"stacia");
    f(false);
    return 0;
}