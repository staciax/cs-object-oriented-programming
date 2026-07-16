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
        int currentMonth = 7;
        int currentYear = 2023;
        int age = currentYear - this->birthYear;
        if (currentMonth < this->birthMonth)
        {
            age -= 1;
        }
        return age;
    }
};

class Student : public Person
{
private:
    string faculty;
    string department;
    int subjects_int[50];
    string subjects_string[50];
    int subjectSize;

public:
    // constructor
    Student() : Person()
    {
        this->init();
    };
    Student(int idCard) : Person(idCard)
    {
        this->init();
    };
    Student(int idCard, string firstName) : Person(idCard, firstName)
    {
        this->init();
    };
    Student(int idCard, string firstName, string lastName) : Person(idCard, firstName, lastName)
    {
        this->init();
    };
    Student(int idCard, string firstName, string lastName, int birthDay) : Person(idCard, firstName, lastName, birthDay)
    {
        this->init();
    };
    Student(int idCard, string firstName, string lastName, int birthDay, int birthMonth) : Person(idCard, firstName, lastName, birthDay, birthMonth)
    {
        this->init();
    };
    Student(int idCard, string firstName, string lastName, int birthDay, int birthMonth, int birthYear) : Person(idCard, firstName, lastName, birthDay, birthMonth, birthYear)
    {
        this->init();
    };

    void init()
    {
        this->faculty = "";
        this->department = "";
        this->subjectSize = 0;
    }

    // destructor

    ~Student() {}

    // set

    void setFaculty(string faculty)
    {
        this->faculty = faculty;
    }
    void setDepartment(string department)
    {
        this->department = department;
    }

    void addSubject(string course, int value)
    {
        int index = this->subjectSize;
        this->subjects_string[index] = course;
        this->subjects_int[index] = value;
        this->subjectSize++;
    }

    // get

    string getFaculty()
    {
        return this->faculty;
    }

    string setDepartment()
    {
        return this->department;
    }

    // show

    void show()
    {
        Person::show();
        cout << "faculty: " << this->faculty << endl;
        // cout << "department: " << this->department << endl;
        // for (int i = 0; i < this->subjectSize; i++)
        // {
        //     cout << "subject: " << this->subjects_int[i] << endl;
        // }
    }

    // process

    float gradeAverage()
    {
        int total = 0.0;
        for (int i = 0; i < this->subjectSize; i++)
        {
            total += this->subjects_int[i];
        }
        float avg = total / this->subjectSize;

        if (avg >= 80 and avg <= 100)
        {
            return 4.0;
        }
        else if (avg >= 75 and avg <= 79)
        {
            return 3.5;
        }
        else if (avg >= 70 and avg <= 74)
        {
            return 3.0;
        }
        else if (avg >= 65 and avg <= 69)
        {
            return 2.5;
        }
        else if (avg >= 60 and avg <= 64)
        {
            return 2.0;
        }
        else if (avg >= 55 and avg <= 59)
        {
            return 1.5;
        }
        else if (avg >= 50 and avg <= 54)
        {
            return 1.0;
        }
        else
        {
            return 0.0;
        }
    }
};

int main()
{

    Student p;
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
    p.addSubject("Subject1", 65);
    p.addSubject("Subject2", 85);
    p.addSubject("Subject3", 70);
    cout << "Grade Average: " << p.gradeAverage() << endl;
    p.show();

    // Student p2(1);
    // Student p3(1, "stacia_3");
    // Student p4(1, "stacia_4", "moon");
    // Student p5(1, "stacia_5", "moon", 21);
    // Student p6(1, "stacia_6", "moon", 21, 1);
    // Student p7(1, "stacia_7", "moon", 21, 1, 2000);
    return 0;
}