#include <iostream>
#include <cstring>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    // constructor
    Date()
    {
        this->init(0, 0, 0);
    }
    Date(int day, int month, int year)
    {
        this->init(day, month, year);
    }

    // destructor
    ~Date()
    {
        cout << "delete: Date" << endl;
    }

    // set
    void init(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    void setMonth(int month)
    {
        this->month = month;
    }
    void setYear(int year)
    {
        this->year = year;
    }

    // get
    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear()
    {
        return this->year;
    }

    // show

    void show()
    {
        cout << "Date("
             << "day=" << this->day << ", "
             << "month=" << this->month << ", "
             << "year=" << this->year << ")" << endl;
    }
};

class Address
{
private:
    string detail;
    string road;
    string district;
    string province;
    char zipcode[5];

public:
    // constructor
    Address()
    {
        this->init("none", "none", "none", "road", (char *)"00000");
    }
    Address(string detail, string road, string district, string province, char *zipcode)
    {
        this->init(detail, road, district, province, zipcode);
    }

    // destructor
    ~Address()
    {
        cout << "delete: Address" << endl;
    }

    // set
    void init(string detail, string road, string district, string province, char *zipcode)
    {
        this->detail = detail;
        this->road = road;
        this->district = district;
        this->province = province;
        strcpy(this->zipcode, zipcode);
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

    // show
    void show()
    {
        cout << "Address("
             << "detail=" << this->detail << ", "
             << "road=" << this->road << ", "
             << "district=" << this->district << ", "
             << "province=" << this->province << ", "
             << "zipcode=" << this->zipcode
             << ")" << endl;
    }
};

class Person
{
private:
    char id[13];
    char fname[20];
    char lname[20];
    Date date;
    Address address;

public:
    // constructor
    Person()
    {
        strcpy(this->id, (char *)"none");
        this->setName((char *)"firstname", (char *)"lastname");
    }
    Person(char *id, char *fname, char *lname, Date &date, Address &address)
    {
        this->init(id, fname, lname, date, address);
    }

    // destructor
    ~Person()
    {
        cout << "delete: Person "
             << "'" << this->getFname() << "'" << endl;
    }

    // set
    void init(char *id, char *fname, char *lname, Date &date, Address &address)
    {
        strcpy(this->id, id);
        strcpy(this->fname, fname);
        strcpy(this->lname, lname);
        this->date = date;
        this->address = address;
    }
    void setID(char *id)
    {
        strcpy(this->id, id);
    }
    void setName(char *fname, char *lname)
    {
        strcpy(this->fname, fname);
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

    // show
    void show()
    {
        cout << "Person("
             << "id=" << this->id << ", "
             << "fname=" << this->fname << ", "
             << "lname=" << this->lname << ", " << endl
             << " Date=";
        this->date.show();
        cout << " Adress=";
        this->address.show();
        cout << ")" << endl;
    }
};

class Student : public Person
{
private:
    char studentID[20];
    char faculty[30];
    char department[30];

public:
    // constructor
    Student()
    {
        this->init("0", "none", "none");
    }
    Student(char *studentID, char *faculty, char *department, char *id, char *fname, char *lname, Date &date, Address &address) : Person(id, fname, lname, date, address)
    {
        this->init(studentID, faculty, department);

        // this->setID(id);
        // this->setName(fname, lname);
        // this->setDate(date);
        // this->setAddress(address);

        // Person::init(id, fname, lname, date, address);
    }

    // destructor
    ~Student()
    {
        cout << "delete: Student "
             << "'" << this->getFname() << "'" << endl;
    }

    // set
    void init(char *studentID, char *faculty, char *department)
    {
        strcpy(this->studentID, studentID);
        strcpy(this->faculty, faculty);
        strcpy(this->department, department);
    }

    void setStudentID(char *studentID)
    {
        strcpy(this->studentID, studentID);
    }
    void setFaculty(char *faculty)
    {
        strcpy(this->faculty, faculty);
    }
    void setDepartment(char *department)
    {
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

    // show
    void show()
    {
        Person::show();
        cout << "Student("
             << "studentID=" << this->studentID << ", "
             << "falculty=" << this->faculty << ", "
             << "department=" << this->department << ")" << endl;
    }
};

class Teacher : public Person
{
private:
    char teacherID[20];
    string email;

public:
    // constructor
    Teacher()
    {
        this->init("0", "none");
    }
    Teacher(char *teacherID, string email, char *id, char *fname, char *lname, Date &date, Address &address) : Person(id, fname, lname, date, address)
    {
        this->init(teacherID, email);

        // this->setID(id);
        // this->setName(fname, lname);
        // this->setDate(date);
        // this->setAddress(address);

        // Person::init(id, fname, lname, date, address);
    }

    // destructor
    ~Teacher()
    {
        cout << "delete: Teacher "
             << "'" << this->getFname() << "'" << endl;
    }
    // set
    void init(char *teacherID, string email)
    {
        strcpy(this->teacherID, teacherID);
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

    // show
    void show()
    {
        Person::show();
        cout << "Teacher("
             << "teacherID=" << this->teacherID << ", "
             << "email=" << this->email << ")" << endl;
    }
};

int main()
{
    cout << " - " << endl;

    Address ads("2/38 something", "Ramkhamhaeng", "Suan Luang", "Bangkok", "10250");
    Date date(21, 01, 2003);

    cout << " -- person --" << endl;

    Person p("1000", "Stacia", "person", date, ads);
    p.show();
    cout << endl;

    cout << " -- student --" << endl;

    Student s("0000001", "Science", "Computer of science", "1001", "Asuna", "student", date, ads);
    s.show();
    cout << endl;

    cout << " -- teacher --" << endl;

    Teacher t; // call default constructor
    Address tads("1/99 <3", "Road something", "Khlong toei", "Bangkok", "10110");
    Date tdate(19, 8, 1999);

    // set
    t.setID("1002");
    t.setName("Yuuki", "Knight");
    t.setDate(tdate);
    t.setAddress(tads);
    t.setTeacherID("100004");
    t.setEmail("yuuki@test.ac.th");

    // get
    cout << "ID: " << t.getID() << endl;
    cout << "first name: " << t.getFname() << endl;
    cout << "last name: " << t.getLname() << endl;
    t.getAddress().show();
    t.getDate().show();
    cout << "teacher ID: " << t.getTeacherID() << endl;
    cout << "email ID: " << t.getEmail() << endl;
    cout << endl;
    t.show();

    cout << endl;

    cout << " -- teacher call person show --" << endl;
    t.Person::show();

    return 0;
}