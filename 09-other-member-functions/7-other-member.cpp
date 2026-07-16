#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Date
{
private:
    int *day;
    int *month;
    int *year;

    void init()
    {
        this->day = new int(0);
        this->month = new int(0);
        this->year = new int(0);
    }

protected:
    void copy(const Date &other)
    {
        *this->day = *other.day;
        *this->month = *other.month;
        *this->year = *other.year;
    }

public:
    // constructor
    Date()
    {
        this->init();
    }
    Date(int day, int month, int year)
    {
        this->init();
        this->set(day, month, year);
    }

    // copy
    Date(const Date &other)
    {
        this->init();
        cout << "copy: Date" << endl;
        this->copy(other);
    };

    // destructor
    ~Date()
    {
        cout << "delete: Date" << endl;
        delete this->day;
        delete this->month;
        delete this->year;
    }

    // set
    void set(int day, int month, int year)
    {
        this->setDay(day);
        this->setMonth(month);
        this->setYear(year);
    }
    void setDay(int day)
    {
        *this->day = day;
    }
    void setMonth(int month)
    {
        *this->month = month;
    }
    void setYear(int year)
    {
        *this->year = year;
    }

    // get
    int *getDay()
    {
        return this->day;
    }
    int *getMonth()
    {
        return this->month;
    }
    int *getYear()
    {
        return this->year;
    }

    // operator

    bool operator==(const Date &other)
    {
        return *this->day == *other.day && *this->month == *other.month && *this->year == *other.year;
    }

    bool operator!=(const Date &other)
    {
        return !this->operator==(other);
    }

    Date &operator=(const Date &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->copy(other);
        return *this;
    }

    Date &operator+=(const Date &other)
    {
        *this->day += *other.day;
        *this->month += *other.month;
        *this->year += *other.year;
        return *this;
    }

    void print(ostream &os)
    {
        os << "Date("
           << "day=" << *this->day << ", "
           << "month=" << *this->month << ", "
           << "year=" << *this->year << ")" << endl;
        // this->show();
    }

    void input(istream &is)
    {
        cout << "input: Date" << endl;
        cout << "Enter day: ";
        is >> *this->day;

        cout << "Enter month: ";
        is >> *this->month;

        cout << "Enter year: ";
        is >> *this->year;
    }

    // show

    void show()
    {
        this->print(cout);
        // cout << "Date("
        //      << "day=" << this->day << ", "
        //      << "month=" << this->month << ", "
        //      << "year=" << this->year << ")" << endl;
    }
};

class Address
{
private:
    string detail;
    string road;
    string district;
    string province;
    char *zipcode;

    void init()
    {
        this->zipcode = new char[10];
        strcpy(this->zipcode, "00000");
        this->detail = this->road = this->district = this->province = "none";
    }

protected:
    void copy(const Address &other)
    {
        this->detail = other.detail;
        this->road = other.road;
        this->district = other.district;
        this->province = other.province;
        strcpy(this->zipcode, other.zipcode);
    }

public:
    // constructor
    Address()
    {
        this->init();
    }
    Address(string detail, string road, string district, string province, char *zipcode)
    {
        this->init();
        this->set(detail, road, district, province, zipcode);
    }

    // copy
    Address(const Address &other)
    {
        this->init();
        cout << "copy: Address" << endl;
        this->copy(other);
    };

    // destructor
    ~Address()
    {
        cout << "delete: Address" << endl;
        delete[] this->zipcode;
    }

    // set
    void set(string detail, string road, string district, string province, char *zipcode)
    {
        this->detail = detail;
        this->road = road;
        this->district = district;
        this->province = province;
        this->setZipcode(zipcode);
    }
    void setDetail(string detail)
    {
        this->detail = detail;
    }
    void setRoad(string road)
    {
        this->road = road;
    }
    void setDistrict(string district)
    {
        this->district = district;
    }
    void setProvince(string province)
    {
        this->province = province;
    }
    void setZipcode(char *zipcode)
    {
        strcpy(this->zipcode, zipcode);
    }

    // get
    string getDetail()
    {
        return this->detail;
    }
    string getRoad()
    {
        return this->road;
    }
    string getDistrict()
    {
        return this->district;
    }
    string getProvince()
    {
        return this->province;
    }
    char *getZipcode()
    {
        return this->zipcode;
    }

    // operator

    bool operator==(const Address &other)
    {
        return this->detail == other.detail &&
               this->road == other.road &&
               this->district == other.district &&
               this->province == other.province &&
               *this->zipcode == *other.zipcode;
    }

    bool operator!=(const Address &other)
    {
        return !this->operator==(other);
    }

    Address &operator=(const Address &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->copy(other);
        return *this;
    }

    // Address &operator+=(Address &other)
    // {
    //     return *this;
    // }

    // io

    void print(ostream &os)
    {
        os << "Address("
           << "detail=" << this->detail << ", "
           << "road=" << this->road << ", "
           << "district=" << this->district << ", "
           << "province=" << this->province << ", "
           << "zipcode=" << this->zipcode
           << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Address" << endl;
        cout << "Enter detail: ";
        is >> this->detail;
        cout << "Enter road: ";
        is >> this->road;
        cout << "Enter district: ";
        is >> this->district;
        cout << "Enter province: ";
        is >> this->province;

        char zc[10];
        cout << "Enter zipcode: ";
        is >> zc;
        this->setZipcode(zc);
    }

    // show
    void show()
    {
        this->print(cout);
        // cout << "Address("
        //      << "detail=" << this->detail << ", "
        //      << "road=" << this->road << ", "
        //      << "district=" << this->district << ", "
        //      << "province=" << this->province << ", "
        //      << "zipcode=" << this->zipcode
        //      << ")" << endl;
    }
};

class Person
{
private:
    char *id;
    char *fname;
    char *lname;
    Date date;
    Address address;

    void init()
    {
        this->id = new char[14];
        strcpy(this->id, "0000000000000");
        this->fname = this->lname = 0;
    }

protected:
    void copy(const Person &other)
    {
        // id
        strcpy(this->id, other.id);

        // fname
        if (other.fname != 0)
        {
            this->fname = new char[strlen(other.fname) + 1];
            strcpy(this->fname, other.fname);
        }
        else
        {
            this->fname = 0;
        }

        // lname
        if (other.lname != 0)
        {
            this->lname = new char[strlen(other.lname) + 1];
            strcpy(this->lname, other.lname);
        }
        else
        {
            this->lname = 0;
        }

        this->date = other.date;
        this->address = other.address;
    }

public:
    // constructor
    Person()
    {
        this->init();
    }
    Person(char *id, char *fname, char *lname, Date &date, Address &address)
    {
        this->init();
        this->set(id, fname, lname, date, address);
    }

    // copy
    Person(const Person &other)
    {
        this->init();
        cout << "copy: Person" << endl;
        this->copy(other);
    };

    // destructor
    ~Person()
    {
        cout << "delete: Person ";
        if (this->fname != 0)
        {
            cout << "'" << this->fname << "'" << endl;
        }
        else
        {
            cout << endl;
        }
        delete[] this->id;
        delete[] this->fname;
        delete[] this->lname;
    }

    // set
    void set(char *id, char *fname, char *lname, Date &date, Address &address)
    {
        this->setID(id);
        this->setName(fname, lname);
        this->date = date;
        this->address = address;
    }
    void setID(char *id)
    {
        strcpy(this->id, id);
    }
    void setName(char *fname, char *lname)
    {
        this->setFirstName(fname);
        this->setLastName(lname);
    }
    void setFirstName(char *fname)
    {
        delete[] this->fname;
        this->fname = new char[strlen(fname) + 1];
        strcpy(this->fname, fname);
    }
    void setLastName(char *lname)
    {
        delete[] this->lname;
        this->lname = new char[strlen(lname) + 1];
        strcpy(this->lname, lname);
    }

    void setDate(Date &date)
    {
        this->date = date;
    }
    void setAddress(Address &address)
    {
        this->address = address;
    }

    // get
    char *getID()
    {
        return this->id;
    }
    char *getFname()
    {
        return this->fname;
    }
    char *getLname()
    {
        return this->lname;
    }
    Date getDate()
    {
        return this->date;
    }
    Address getAddress()
    {
        return this->address;
    }

    // operator

    bool operator==(Person &other)
    {
        return *this->id == *other.id &&
               *this->fname == *other.fname &&
               *this->lname == *other.lname &&
               this->date == other.date &&
               this->address == other.address;
    }

    bool operator!=(Person &other)
    {
        return !this->operator==(other);
    }

    Person &operator=(const Person &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] this->fname;
        delete[] this->lname;

        this->copy(other);

        return *this;
    }

    Person &operator+=(const Person &other)
    {
        this->date += other.date;
        return *this;
    }

    // io

    void print(ostream &os)
    {
        os << "Person("
           << "id=" << this->id << ", "
           << "fname=" << this->fname << ", "
           << "lname=" << this->lname << ", " << endl
           << " Date=";
        this->date.print(os);
        os << " Adress=";
        this->address.print(os);
        os << ")" << endl;
    }
    void input(istream &is)
    {
        cout << "input: Person" << endl;
        char temp[50];
        cout << "Enter id: ";
        is >> temp;
        this->setID(temp);

        cout << "Enter first name: ";
        is >> temp;
        this->setFirstName(temp);

        cout << "Enter last name: ";
        is >> temp;
        this->setLastName(temp);

        this->date.input(is);
        this->address.input(is);
    }

    // show
    void show()
    {
        this->print(cout);
        // cout << "Person("
        //      << "id=" << this->id << ", "
        //      << "fname=" << this->fname << ", "
        //      << "lname=" << this->lname << ", " << endl
        //      << " Date=";
        // this->date.show();
        // cout << " Adress=";
        // this->address.show();
        // cout << ")" << endl;
    }
};

class Student : virtual public Person
{
private:
    char *studentID;
    char *faculty;
    char *department;

    void init()
    {
        this->studentID = new char[11];
        strcpy(this->studentID, "0000000000");
        this->faculty = this->department = 0;
    }

protected:
    void copy(const Student &other)
    {

        // studentID
        strcpy(this->studentID, other.studentID);

        // faculty
        if (other.faculty != 0)
        {
            this->faculty = new char[strlen(other.faculty) + 1];
            strcpy(this->faculty, other.faculty);
        }
        else
        {
            this->faculty = 0;
        }

        // department
        if (other.department != 0)
        {
            this->department = new char[strlen(other.department) + 1];
            strcpy(this->department, other.department);
        }
        else
        {
            this->department = 0;
        }
    }

public:
    // constructor
    Student()
    {
        this->init();
    }
    Student(char *studentID, char *faculty, char *department)
    {
        this->init();
        this->set(studentID, faculty, department);
    }
    Student(char *studentID, char *faculty, char *department, char *id, char *fname, char *lname, Date &date, Address &address) : Person(id, fname, lname, date, address)
    {
        // Person::init(id, fname, lname, date, address);
        this->init();
        this->set(studentID, faculty, department);
    }

    // copy
    Student(const Student &other) : Person(other)
    {
        this->init();
        cout << "copy: Student" << endl;
        // Person::copy(other); // ข้ามการตรวจสอบ
        this->copy(other);
    };

    // destructor
    ~Student()
    {
        cout << "delete: Student ";
        if (this->getFname() != 0)
        {
            cout << "'" << this->getFname() << "'" << endl;
        }
        else
        {
            cout << endl;
        }
        delete[] this->studentID;
        delete[] this->faculty;
        delete[] this->department;
    }

    // set
    void set(char *studentID, char *faculty, char *department)
    {
        this->setStudentID(studentID);
        this->setFaculty(faculty);
        this->setDepartment(department);
    }

    void setStudentID(char *studentID)
    {
        strcpy(this->studentID, studentID);
    }
    void setFaculty(char *faculty)
    {
        delete[] this->faculty;
        this->faculty = new char[strlen(faculty) + 1];
        strcpy(this->faculty, faculty);
    }
    void setDepartment(char *department)
    {
        delete[] this->department;
        this->department = new char[strlen(department) + 1];
        strcpy(this->department, department);
    }

    // get
    char *getStudentID()
    {
        return this->studentID;
    }
    char *getFaculty()
    {
        return this->faculty;
    }
    char *getDepartment()
    {
        return this->department;
    }

    // operator

    bool operator==(Student &other)
    {
        if (Person::operator==(other) != other.Person::operator==(other))
        {
            return false;
        }
        return *this->studentID == *other.studentID &&
               *this->faculty == *other.faculty &&
               *this->department == *other.department;
    }

    bool operator!=(Student &other)
    {
        return !this->operator==(other);
    }

    Student &operator=(Student &other)
    {
        if (this == &other)
        {
            return *this;
        }
        Person::operator=(other); // student is a person ช่วงจะเกิด dynamic typing
        this->copy(other);
        return *this;
    }

    Student &operator+=(Student &other)
    {
        Person::operator+=(other);
        return *this;
    }

    // io

    void print(ostream &os)
    {
        Person::print(os);
        os << "Student("
           << "studentID=" << this->studentID << ", "
           << "falculty=" << this->faculty << ", "
           << "department=" << this->department << ")" << endl;
    }
    void input(istream &is)
    {
        Person::input(is);
        cout << "input: Student" << endl;

        char temp[100];

        cout << "Enter studentID: ";
        is >> temp;
        this->setStudentID(temp);

        cout << "Enter faculty: ";
        is >> temp;
        this->setFaculty(temp);

        cout << "Enter department: ";
        is >> temp;
        this->setDepartment(temp);
    }

    // show
    void show()
    {
        this->print(cout);
        // Person::show();
        // cout << "Student("
        //      << "studentID=" << this->studentID << ", "
        //      << "falculty=" << this->faculty << ", "
        //      << "department=" << this->department << ")" << endl;
    }
};

class Teacher : virtual public Person
{
private:
    char *teacherID;
    string email;

    void init()
    {
        this->teacherID = new char[11];
        strcpy(this->teacherID, "0000000000");
        this->email = "none";
    }

protected:
    void copy(const Teacher &other)
    {

        this->email = other.email;
        strcpy(this->teacherID, other.teacherID);
    }

public:
    // constructor
    Teacher()
    {
        this->init();
    }
    Teacher(char *teacherID, string email)
    {
        this->init();
        this->set(teacherID, email);
    }
    Teacher(char *teacherID, string email, char *id, char *fname, char *lname, Date &date, Address &address) : Person(id, fname, lname, date, address)
    {
        // Person::init(id, fname, lname, date, address);
        this->init();
        this->set(teacherID, email);
    }

    // copy
    Teacher(const Teacher &other) : Person(other)
    {
        this->init();
        cout << "copy: Teacher" << endl;
        // Person::copy(other); // ข้ามการตรวจสอบ
        this->copy(other);
    };

    // destructor
    ~Teacher()
    {
        cout << "delete: Teacher ";
        if (this->getFname() != 0)
        {
            cout << "'" << this->getFname() << "'" << endl;
        }
        else
        {
            cout << endl;
        }
        delete[] this->teacherID;
    }
    // set
    void set(char *teacherID, string email)
    {
        this->setTeacherID(teacherID);
        this->email = email;
    }
    void setTeacherID(char *teacherID)
    {
        strcpy(this->teacherID, teacherID);
    }
    void setEmail(string email)
    {
        this->email = email;
    }

    // get
    char *getTeacherID()
    {
        return this->teacherID;
    }
    string getEmail()
    {
        return this->email;
    }

    // operator

    bool operator==(Teacher &other)
    {
        if (Person::operator==(other) != other.Person::operator==(other))
        {
            return false;
        }
        return *this->teacherID == *other.teacherID && this->email == other.email;
    }

    bool operator!=(Teacher &other)
    {
        return !this->operator==(other);
    }

    Teacher &operator=(const Teacher &other)
    {
        if (this == &other)
        {
            return *this;
        }
        Person::operator=(other); // teacher is a person ช่วงจะเกิด dynamic typing
        this->copy(other);
        return *this;
    }

    Teacher &operator+=(const Teacher &other)
    {
        Person::operator+=(other);
        return *this;
    }

    // io

    void print(ostream &os)
    {
        Person::print(os);
        os << "Teacher("
           << "teacherID=" << this->teacherID << ", "
           << "email=" << this->email << ")" << endl;
    }
    void input(istream &is)
    {
        Person::input(is);
        cout << "input: Teacher" << endl;

        char temp[20];

        cout << "Enter teacherID: ";
        is >> temp;
        this->setTeacherID(temp);

        cout << "Enter email: ";
        is >> email;
    }

    // show
    void show()
    {
        this->print(cout);
        // Person::show();
        // cout << "Teacher("
        //      << "teacherID=" << this->teacherID << ", "
        //      << "email=" << this->email << ")" << endl;
    }
};

class TeachingAssistant : public Student, public Teacher
{
private:
    string course;
    int *bonus;
    bool active;

    void init()
    {
        this->bonus = new int(1500);
        this->course = "none";
        this->active = false;
    }

protected:
    void copy(const TeachingAssistant &other)
    {
        this->course = other.course;
        this->active = other.active;
        *this->bonus = *other.bonus;
    }

public:
    TeachingAssistant()
    {
        this->init();
    }
    TeachingAssistant(string course, int bonus, bool active)
    {
        this->init();
        this->set(course, bonus, active);
    }
    TeachingAssistant(string course, int bonus, bool active,
                      char *id, char *fname, char *lname, Date &date, Address &address,
                      char *studentID, char *teacherID,
                      char *faculty, char *department, string email) : Person(id, fname, lname, date, address),
                                                                       Student(studentID, faculty, department),
                                                                       Teacher(teacherID, email)
    {
        // Person::init(id, fname, lname, date, address);
        // Student::init(studentID, faculty, department);
        // Teacher::init(teacherID, email);
        this->init();
        this->set(course, bonus, active);
    }

    // copy
    TeachingAssistant(TeachingAssistant &other) : Person(other), Student(other), Teacher(other)
    {
        this->init();
        cout << "copy: TeachingAssistant" << endl;
        // Student::operator=(other); // teaching assistant is a student (+person) ช่วงจะเกิด dynamic typing
        // Teacher::copy(other); // teacher assistant is a teacher ช่วงจะเกิด dynamic typing
        this->copy(other);
    };

    // destructor
    ~TeachingAssistant()
    {
        cout << "delete: TeachingAssistant ";
        if (getFname() != 0)
        {
            cout << "'" << getFname() << "'" << endl;
        }
        else
        {
            cout << endl;
        }
        delete this->bonus;
    }

    // set

    void set(string course, int bonus, bool active)
    {
        this->course = course;
        this->setBonus(bonus);
        this->active = active;
    }

    void setCourse(string course)
    {
        this->course = course;
    }

    void setActive(bool active)
    {
        this->active = active;
    }

    void setBonus(int bonus)
    {
        *this->bonus = bonus;
    }

    // get

    string getCourse()
    {
        return this->course;
    }

    bool isActive()
    {
        return this->active;
    }

    int *getBonus()
    {
        return this->bonus;
    }

    // operator

    bool operator==(TeachingAssistant &other)
    {
        if (Person::operator==(other) != other.Person::operator==(other))
        {
            return false;
        }
        if (Student::operator==(other) != other.Student::operator==(other))
        {
            return false;
        }
        if (Teacher::operator==(other) != other.Teacher::operator==(other))
        {
            return false;
        }
        return this->course == other.course && *this->bonus == *other.bonus && this->active == other.active;
    }

    bool operator!=(TeachingAssistant &other)
    {
        return !this->operator==(other);
    }

    TeachingAssistant &operator=(TeachingAssistant &other)
    {
        if (this == &other)
        {
            return *this;
        }
        // Person::operator=(other);
        Student::operator=(other); // student -> person
        Teacher::copy(other);      // only copy teacher
        this->copy(other);
        return *this;
    }

    TeachingAssistant &operator+=(TeachingAssistant &other)
    {
        return *this;
    }

    // io

    void print(ostream &os)
    {
        Student::print(os);
        os << "Teacher("
           << "teacherID=" << this->getTeacherID() << ", "
           << "email=" << Teacher::getEmail() << ")" << endl;
        os << "TeachingAssistant("
           << "course=" << this->course << ", "
           << "bonus=" << *this->bonus << ", "
           << "active=" << this->active << ")" << endl;
    }
    void input(istream &is)
    {
        Student::input(is);

        cout << "input: Teacher" << endl;
        char temp[50];
        string stemp;
        cout << "Enter teacherID: ";
        is >> temp;
        Teacher::setTeacherID(temp);
        cout << "Enter email: ";
        is >> stemp;
        Teacher::setEmail(stemp);

        cout << "input: TeachingAssistant" << endl;
        cout << "Enter course: ";
        is >> course;

        cout << "Enter bonus: ";
        is >> *this->bonus;

        cout << "Enter active(0/1): ";
        is >> active;
    }

    // show

    void show()
    {
        this->print(cout);
        // Person::show();
        // cout << "Student("
        //      << "studentID=" << this->getStudentID() << ", "
        //      << "falculty=" << this->getFaculty() << ", "
        //      << "department=" << this->getDepartment() << ")" << endl;
        // Student::show();
        // cout << "Teacher("
        //      << "teacherID=" << this->getTeacherID() << ", "
        //      << "email=" << Teacher::getEmail() << ")" << endl;
        // cout << "TeachingAssistant("
        //      << "course=" << this->course << ", "
        //      << "bonus=" << *this->bonus << ", "
        //      << "active=" << this->active << ")" << endl;
    }
};

// Date io
ostream &operator<<(ostream &os, Date &date)
{
    date.print(os);
    return os;
}
istream &operator>>(istream &is, Date &date)
{
    date.input(is);
    return is;
}

// Address io
ostream &operator<<(ostream &os, Address &address)
{
    address.print(os);
    return os;
}
istream &operator>>(istream &is, Address &address)
{
    address.input(is);
    return is;
}

// Person io
ostream &operator<<(ostream &os, Person &person)
{
    person.print(os);
    return os;
}
istream &operator>>(istream &is, Person &person)
{
    person.input(is);
    return is;
}

// Student io
ostream &operator<<(ostream &os, Student &student)
{
    student.print(os);
    return os;
}
istream &operator>>(istream &is, Student &student)
{
    student.input(is);
    return is;
}

// Teacher io
ostream &operator<<(ostream &os, Teacher &teacher)
{
    teacher.print(os);
    return os;
}
istream &operator>>(istream &is, Teacher &teacher)
{
    teacher.input(is);
    return is;
}

// TeachingAssistant io
ostream &operator<<(ostream &os, TeachingAssistant &ta)
{
    ta.print(os);
    return os;
}
istream &operator>>(istream &is, TeachingAssistant &ta)
{
    ta.input(is);
    return is;
}

int main()
{
    // Date
    Date date;
    cin >> date;
    cout << date;

    Date date2 = date;
    cout << date2;
    cout << "date == date2 is " << (date == date2 ? "true" : "false") << endl;

    date2 += date2;
    cout << date2;

    // Address
    Address address;
    cin >> address;
    cout << address;

    Address address2 = address;
    cout << address2;

    cout << "address == address2 is " << (address == address2 ? "true" : "false") << endl;

    // Person

    Person p;
    cin >> p;
    cout << p;

    Person p2 = p;
    cout << p2;

    cout << "p == p2 is " << (p == p2 ? "true" : "false") << endl;

    // Student

    Student s;
    cin >> s;
    cout << s;

    Student s2 = s;
    cout << s2;

    cout << "s == s2 is " << (s == s2 ? "true" : "false") << endl;

    // Teacher

    Teacher t;
    cin >> t;
    t.show();

    Teacher t2 = t;
    t2.show();

    cout << "t == t2 is " << (t == t2 ? "true" : "false") << endl;

    // TeachingAssistant

    TeachingAssistant ta;
    cin >> ta;
    cout << ta;

    TeachingAssistant ta2 = ta;
    ta2.show();

    cout << "ta == ta2 is " << (ta == ta2 ? "true" : "false") << endl;

    cout << "---" << endl;

    // // teaching assistant
    // ta.setCourse("Python programing language");
    // ta.setActive(true);
    // ta.setBonus(15000);

    // cout << "course=" << ta.getCourse() << endl;
    // cout << "active=" << (ta.isActive() ? "true" : "false") << endl;
    // cout << "bonus=" << ta.getBonus() << endl;

    // person

    // ta.Person::show();

    // ta.Person::setID("CID200000");
    // ta.Person::setAddress(address);
    // ta.Person::setDate(date);
    // ta.Person::setName("yuuki", "sleeping");

    // student

    // ta.Student::show();

    // ta.Student::setFaculty("Faculty of science");
    // ta.Student::setDepartment("Computer of science");
    // ta.Student::setStudentID("SID660001");

    // teacher

    // ta.Teacher::show();

    // ta.Teacher::setTeacherID("TID10000");
    // ta.Teacher::setEmail("stacia.teacher@test.ac.th");

    // cout << "---" << endl;

    // ta.show();

    return 0;
}