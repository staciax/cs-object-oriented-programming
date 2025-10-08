#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    int idCard;
    string firstName;
    string lastName;
    int birthDay;
    int birthMonth;
    int birthYear;

public:
    // constructor

    Person()
    {
        this->init(0, "", "", 0, 0, 0);
    }
    Person(int idCard)
    {
        this->init(idCard, "", "", 0, 0, 0);
    }
    Person(int idCard, string firstName)
    {
        this->init(idCard, firstName, "", 0, 0, 0);
    }
    Person(int idCard, string firstName, string lastName)
    {
        this->init(idCard, firstName, lastName, 0, 0, 0);
    }
    Person(int idCard, string firstName, string lastName, int birthDay)
    {
        this->init(idCard, firstName, lastName, birthDay, 0, 0);
    }
    Person(int idCard, string firstName, string lastName, int birthDay, int birthMonth)
    {
        this->init(idCard, firstName, lastName, birthDay, birthMonth, 0);
    }
    Person(int idCard, string firstName, string lastName, int birthDay, int birthMonth, int birthYear)
    {
        this->init(idCard, firstName, lastName, birthDay, birthMonth, birthYear);
    }

    // destructor

    ~Person() {}

    // init
    void init(int idCard, string firstName, string lastName, int birthDay, int birthMonth, int birthYear)
    {
        this->setIdCard(idCard);
        this->setFirstName(firstName);
        this->setLastName(lastName);
        this->setBirthDay(birthDay);
        this->setBirthMonth(birthMonth);
        this->setBirthYear(birthYear);
    }

    // set

    void setIdCard(int idCard)
    {
        if (idCard < 0)
        {
            return;
        }
        this->idCard = idCard;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    void setBirthDay(int birthDay)
    {
        if (birthDay < 0)
        {
            return;
        }
        this->birthDay = birthDay;
    }
    void setBirthMonth(int birthMonth)
    {
        if (birthMonth < 0)
        {
            return;
        }
        this->birthMonth = birthMonth;
    }
    void setBirthYear(int birthYear)
    {
        if (birthYear < 0)
        {
            return;
        }
        this->birthYear = birthYear;
    }

    // get

    int getIdCard()
    {
        return this->idCard;
    }
    string getFirstName()
    {
        return this->firstName;
    }
    string getLastName()
    {
        return this->lastName;
    }
    int getBirthDay()
    {
        return this->birthDay;
    }
    int getBirthMonth()
    {
        return this->birthMonth;
    }
    int getBirthYear()
    {
        return this->birthYear;
    }

    // show

    void show()
    {
        cout << "ID: " << this->idCard << endl;
        cout << "First Name: " << this->firstName << endl;
        cout << "Last Name: " << this->lastName << endl;
        cout << "Birthday: " << this->birthDay << "/" << this->birthMonth << "/" << this->birthYear << endl;
        cout << "Age: " << this->getAge() << endl;
    }

    // process

    int getAge()
    {
        // current date
        int currentDay = 23;
        int currentMonth = 7;
        int currentYear = 2023;

        int age = currentYear - this->birthYear;
        if (currentMonth < this->birthMonth)
        {
            age--;
        }
        else if (currentMonth == this->birthMonth)
        {
            if (currentDay < this->birthDay)
            {
                age--;
            }
        }
        return age;
    }

    int *getFullBirthDay()
    {
        int *fullBirthDay = new int[3];
        fullBirthDay[0] = this->birthDay;
        fullBirthDay[1] = this->birthMonth;
        fullBirthDay[2] = this->birthYear;
        // statement?
        return fullBirthDay;
    }
};

int main()
{
    Person p;
    p.show();
    cout << "-----------" << endl;
    p.setIdCard(1);
    p.setFirstName("stacia");
    p.setLastName("moon");
    p.setBirthDay(21);
    p.setBirthMonth(1);
    p.setBirthYear(2000);
    p.show();
    cout << "-----------" << endl;
    cout << "ID: " << p.getIdCard() << endl;
    cout << "First Name: " << p.getFirstName() << endl;
    cout << "Last Name: " << p.getLastName() << endl;
    cout << "Birthday: " << p.getBirthDay() << "/" << p.getBirthMonth() << "/" << p.getBirthYear() << endl;
    cout << "Age: " << p.getAge() << endl;
    cout << "-----------" << endl;
    // full birthday
    int *fullBirthDay = p.getFullBirthDay();
    cout << "Full Birthday: " << fullBirthDay[0] << "/" << fullBirthDay[1] << "/" << fullBirthDay[2] << endl;

    Person p2(1);
    Person p3(1, "stacia_3");
    Person p4(1, "stacia_4", "moon");
    Person p5(1, "stacia_5", "moon", 21);
    Person p6(1, "stacia_6", "moon", 21, 1);
    Person p7(1, "stacia_7", "moon", 21, 1, 2000);
    return 0;
}