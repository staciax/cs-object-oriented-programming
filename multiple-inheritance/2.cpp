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

class Student : virtual public Person
{
private:
    char studentID[20];
    char faculty[30];
    char department[30];

public:
    // constructor
    Student()
    {
        this->init((char *)"0", (char *)"none", (char *)"none");
    }
    Student(char *studentID, char *faculty, char *department)
    {
        this->init(studentID, faculty, department);
    }
    Student(char *studentID, char *faculty, char *department, char *id, char *fname, char *lname, Date &date, Address &address) : Person(id, fname, lname, date, address)
    {
        this->init(studentID, faculty, department);
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
        // Person::show();
        cout << "Student("
             << "studentID=" << this->studentID << ", "
             << "falculty=" << this->faculty << ", "
             << "department=" << this->department << ")" << endl;
    }
};

class Teacher : virtual public Person
{
private:
    char teacherID[20];
    string email;

public:
    // constructor
    Teacher()
    {
        this->init((char *)"0", (char *)"none");
    }
    Teacher(char *teacherID, string email)
    {
        this->init(teacherID, email);
    }
    Teacher(char *teacherID, string email, char *id, char *fname, char *lname, Date &date, Address &address) : Person(id, fname, lname, date, address)
    {
        // Person::init(id, fname, lname, date, address);
        this->init(teacherID, email);
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
        // Person::show();
        cout << "Teacher("
             << "teacherID=" << this->teacherID << ", "
             << "email=" << this->email << ")" << endl;
    }
};

class TeachingAssistant : public Student, public Teacher // virtual public Person
{
private:
    string course;
    int bonus;
    bool active;

public:
    TeachingAssistant()
    {
        this->init("none", 1500, true);
    }
    TeachingAssistant(string course, int bonus, bool active)
    {
        this->init(course, bonus, active);
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
        this->init(course, bonus, active);
    }
    ~TeachingAssistant()
    {
        cout << "delete: TeachingAssistant "
             << "'" << getFname() << "'" << endl;
    }

    // set

    void init(string course, int bonus, bool active)
    {
        this->course = course;
        this->bonus = bonus;
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
        this->bonus = bonus;
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

    int getBonus()
    {
        return this->bonus;
    }

    // show

    void show()
    {

        // Person::show();
        // cout << "Student("
        //      << "studentID=" << this->getStudentID() << ", "
        //      << "falculty=" << this->getFaculty() << ", "
        //      << "department=" << this->getDepartment() << ")" << endl;
        Student::show();
        cout << "Teacher("
             << "teacherID=" << this->getTeacherID() << ", "
             << "email=" << Teacher::getEmail() << ")" << endl;
        cout << "TeachingAssistant("
             << "course=" << this->course << ", "
             << "bonus=" << this->bonus << ", "
             << "active=" << this->active << ")" << endl;
    }
};

int main()
{
    TeachingAssistant tad; // default

    cout << endl;

    Address address("2/38 something", "Ramkhamhaeng", "Suan Luang", "Bangkok", "10250");
    Date date(21, 01, 2003);

    TeachingAssistant ta("OOP", 3500, false,
                         "CID100001", "stacia", "moon", date, address,
                         "SID10001", "TID10000", "Science", "Alchemy of science", "stacia.teacher@university.ac.th");

    // teaching assistant
    ta.setCourse("Python programing language");
    ta.setActive(true);
    ta.setBonus(15000);

    cout << "course=" << ta.getCourse() << endl;
    cout << "active=" << (ta.isActive() ? "true" : "false") << endl;
    cout << "bonus=" << ta.getBonus() << endl;

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

    ta.show();

    return 0;
}