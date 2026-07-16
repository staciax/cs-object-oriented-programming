#include <iostream>
#include <string>

using namespace std;

class Meat
{
    int type; // 1.สด 2.ย่าง 3.ทอด
public:
    Meat()
    {
        this->type = 1;
    }
    Meat(int type)
    {
        if (type >= 1 && type <= 3)
        {
            this->type = type;
        }
        else
        {
            this->type = 1;
        }
    }
    Meat(Meat &other)
    {
        this->type = other.type;
        cout << "copy Meat" << endl;
    }
    virtual ~Meat()
    {
        cout << "\ndelete: Meat" << endl;
        this->showMeat();
    }

    // get
    int getType()
    {
        return this->type;
    }
    string getMeatType()
    {
        switch (this->type)
        {
        case 1:
            return "สด";
            break;
        case 2:
            return "ย่าง";
            break;
        case 3:
            return "ทอด";
            break;
        default:
            return "สด";
            break;
        }
    }

    // show
    void showMeat()
    {
        cout << "\nMeat" << endl;
        cout << "Meat type: " << this->getMeatType() << endl;
    }
    virtual void show() = 0;
};

class Fish : public Meat
{
    string name; // ชื่อปลา
public:
    Fish()
    {
        this->name = "Pla chon";
    }
    Fish(string name, int type) : Meat(type)
    {
        this->name = name;
    }
    Fish(Fish &other) : Meat(other)
    {
        this->name = other.name;
        cout << "copy Fish" << endl;
    }
    ~Fish()
    {
        cout << "\ndelete: Fish" << endl;
        this->showFish();
    }

    // get
    string getName()
    {
        return this->name;
    }

    // show
    void showFish()
    {
        cout << "\nFish" << endl;
        cout << "name: " << this->name << endl;
    }
    void show()
    {
        this->showFish();
        this->showMeat();
    }
};

class Chicken : virtual public Meat
{
    int type; // 1.ไก่เนื้อ 2.ไก่บ้าน
public:
    Chicken()
    {
        this->type = 1;
    }
    Chicken(int type, int meatType) : Meat(meatType)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
        }
        else
        {
            this->type = 1;
        }
    }
    Chicken(Chicken &other) : Meat(other)
    {
        this->type = other.Chicken::getType();
        cout << "copy Chicken" << endl;
    }
    ~Chicken()
    {
        cout << "\ndelete: Chicken" << endl;
        this->showChicken();
    }

    // get
    int getType()
    {
        return this->type;
    }
    string getChickenType()
    {
        switch (this->type)
        {
        case 1:
            return "ไก่เนื้อ";
            break;
        case 2:
            return "ไก่บ้าน";
            break;

        default:
            return "ไก่เนื้อ";
            break;
        }
    }

    // show
    void showChicken()
    {
        cout << "\nChicken" << endl;
        cout << "Chicken type: " << this->getChickenType() << endl;
    }
    void show()
    {
        this->showChicken();
        this->showMeat();
    }
};

class ThaiFood
{
    static int tfCount; // นับจำนวน ThaiFood
    double price;       // ราคาอาหาร
    int spicyLevel;     // ระดับความเผ็ด 1-5
    Meat *meat;         // พอยเตอร์ Meat
public:
    ThaiFood()
    {
        this->price = 0;
        this->spicyLevel = 1;
        this->meat = 0;
        ++tfCount;
    }
    ThaiFood(double price, int spicyLevel, Meat *meat)
    {
        this->setPrice(price);
        this->setSpicyLevel(spicyLevel);
        this->meat = meat;
        ++tfCount;
    }
    virtual ~ThaiFood()
    {
        this->showThaiFood();
        --tfCount;
    }

    // get
    double getPrice()
    {
        return this->price;
    }
    int SpicyLevel()
    {
        return this->spicyLevel;
    }
    Meat *getMeat()
    {
        return this->meat;
    }

    // set
    void setPrice(double price)
    {
        if (price < 0)
        {
            price = 0;
        }
        this->price = price;
    }
    void setSpicyLevel(int spicyLevel)
    {
        if (spicyLevel >= 1 && spicyLevel <= 5)
        {
            this->spicyLevel = spicyLevel;
        }
        else
        {
            this->spicyLevel = 1;
        }
    }
    void setMeat(Meat *meat)
    {
        this->meat = meat;
    }

    // show
    void showThaiFood()
    {
        cout << "\nThaiFood" << endl;
        cout << "price: " << this->price << endl;
        cout << "spicyLevel: " << this->spicyLevel << endl;
        if (this->meat != 0)
        {
            this->meat->show();
        }
    }
    virtual void show() = 0;

    // operator
    friend bool operator>(ThaiFood &tf1, ThaiFood &tf2)
    {
        return tf1.spicyLevel > tf2.spicyLevel;
    }
    virtual ThaiFood &operator!() = 0;
    virtual string operator()() = 0;

    // static
    static int getCount()
    {
        return tfCount;
    }
};

int ThaiFood::tfCount;

class Soup : public ThaiFood
{
    bool hotPot; // true ใส่หม้อ false ใส่ชาม
public:
    Soup() : ThaiFood(25, 2, 0)
    {
        this->hotPot = false;
    }
    Soup(bool hotPot, double price, int spicyLevel, Meat *meat) : ThaiFood(price, spicyLevel, meat)
    {
        this->hotPot = hotPot;
    }
    ~Soup()
    {
        cout << "\ndelete: Soup" << endl;
        this->showSoup();
    }
    // set

    void setSoup(bool hotPot)
    {
        this->hotPot = hotPot;
    }
    void setSoup(bool hotPot, double price)
    {
        this->hotPot = hotPot;
        ThaiFood::setPrice(price);
    }

    // get
    bool getHotPot()
    {
        return this->hotPot;
    }
    string getHotPotType()
    {
        if (this->hotPot)
        {
            return "ใส่หม้อ";
        }
        else
        {
            return "ใส่ชาม";
        }
    }

    // show
    void showSoup()
    {
        cout << "\nSoup" << endl;
        cout << "Soup hotpot: " << this->getHotPotType() << endl;
    }
};

class Larb : public ThaiFood
{
    bool shallots; // true ใส่หอมแดง false ไม่ใส่หอมแดง
public:
    Larb() : ThaiFood(30, 4, 0)
    {
        this->shallots = true;
    }
    Larb(bool shallots, double price, int spicyLevel, Meat *meat) : ThaiFood(price, spicyLevel, meat)
    {
        this->shallots = shallots;
    }
    ~Larb()
    {
        cout << "\ndelete: Larb " << endl;
        this->showLarb();
    }

    // set

    void setLarb(bool shallots)
    {
        this->shallots = shallots;
    }
    void setLarb(bool shallots, int spicyLevel)
    {
        this->shallots = shallots;
        ThaiFood::setSpicyLevel(spicyLevel);
    }

    // get
    bool getShallots()
    {
        return this->shallots;
    }
    int getLarbType()
    {
        if (this->getMeat() != 0)
        {
            return this->getMeat()->getType();
        }
        else
        {
            return -1;
        }
    }
    string getShallotsType()
    {
        if (this->shallots)
        {
            return "ใส่หอมแดง";
        }
        else
        {
            return "ไม่ใส่หอมแดง";
        }
    }

    // show
    void showLarb()
    {
        cout << "\nLarb" << endl;
        cout << "Larb shallots: " << this->getShallotsType() << endl;
    }
    void show()
    {
        this->showThaiFood();
        this->showLarb();
    }

    // operator
    Larb &operator!()
    {
        this->shallots = !this->shallots;
        return *this;
    }
    string operator()()
    {
        if (this->shallots)
        {
            return "ลาบจานนี้ ใส่หอมแดง";
        }
        else
        {
            return "ลาบจานนี้ ไม่ใส่หอมแดง";
        }
    }
};

class TomYam : public Soup
{
    bool clear; // true น้ำใส false น้ำข้น
public:
    TomYam() : Soup(true, 35, 1, 0)
    {
        this->clear = false;
    }
    TomYam(bool clear, bool hotPot, double price, int spicyLevel, Meat *meat) : Soup(hotPot, price, spicyLevel, meat)
    {
        this->clear = clear;
    }
    ~TomYam()
    {
        cout << "\ndelete: TomYam " << endl;
        this->showTomYam();
    }

    // set

    void setTomYam(int clear)
    {
        this->clear = clear;
    }
    void setTomYam(int clear, Meat *meat)
    {
        this->clear = clear;
        ThaiFood::setMeat(meat);
    }
    string getTomYamType()
    {
        if (this->clear)
        {
            return "น้ำใส";
        }
        else
        {
            return "น้ำข้น";
        }
    }

    // get
    bool getClear()
    {
        return this->clear;
    }

    // show
    void showTomYam()
    {
        cout << "\nTomTam" << endl;
        cout << "Tomyam: " << this->getHotPotType() << endl;
    }
    void show()
    {
        this->showTomYam();
        this->showSoup();
        this->showThaiFood();
    }
    // operator
    TomYam &operator!()
    {
        this->clear = !this->clear;
        return *this;
    }
    string operator()()
    {
        if (this->clear)
        {
            return "ต้มยำจานนี้ น้ำใส";
        }
        else
        {
            return "ต้มยำจานนี้ น้ำข้น";
        }
    }
};

class TomKlong : public Soup
{
    bool tomato; // true ใส่มะเขือเทศ false ไม่ใส่
public:
    TomKlong() : Soup(true, 45, 1, 0)
    {
        this->tomato = false;
    }
    TomKlong(bool tomato, bool hotPot, double price, int spicyLevel, Meat *meat) : Soup(hotPot, price, spicyLevel, meat)
    {
        this->tomato = tomato;
    }
    ~TomKlong()
    {
        cout << "\ndelete: TomKlong " << endl;
        this->showTomKlong();
    }
    // set
    void setTomKlong(bool tomato)
    {
        this->tomato = tomato;
    }
    void setTomKlong(bool tomato, double price)
    {
        this->tomato = tomato;
        this->setPrice(price);
    }

    // get
    bool getTomato()
    {
        return this->tomato;
    }
    string getTomKlongType()
    {
        if (this->tomato)
        {
            return "ใส่มะเขือเทศ";
        }
        else
        {
            return "ไม่ใส่มะเขือเทศ";
        }
    }

    // show
    void showTomKlong()
    {
        cout << "\nTomKlong" << endl;
        cout << "TomKlong: " << this->getTomKlongType() << endl;
    }
    void show()
    {
        this->showTomKlong();
        this->showSoup();
        this->showThaiFood();
    }

    // operator
    TomKlong &operator!()
    {
        this->tomato = !this->tomato;
        return *this;
    }
    string operator()()
    {
        if (this->tomato)
        {
            return "ต้มโคล้งจานนี้ ใส่มะเขือเทศ";
        }
        else
        {
            return "ต้มโคล้งจานนี้ ไม่ใส่มะเขือเทศ";
        }
    }
};

// io

ostream &operator<<(ostream &os, Meat &meat)
{
    meat.show();
    return os;
}

ostream &operator<<(ostream &os, ThaiFood &thaifood)
{
    thaifood.show();
    return os;
}

int main()
{
    Meat *a[4];
    a[0] = new Chicken(1, 1);
    a[1] = new Chicken(2, 2);
    a[2] = new Fish("Pla kapong", 3);
    a[3] = new Fish("Pla Kang", 1);

    for (int i = 0; i < 4; i++)
    {
        cout << *a[i] << endl;
    }

    // ------

    Chicken c;
    Fish f;
    c.show();
    f.show();

    // ------

    Meat *b[2];
    b[0] = new Chicken(c);
    b[1] = new Fish(f);
    for (int i = 0; i < 2; i++)
    {
        b[i]->show();
    }

    // ------

    ThaiFood **menuA;
    menuA = new ThaiFood *[3];
    menuA[0] = new Larb(true, 80, 4, b[1]);
    menuA[1] = new TomYam(false, true, 120, 3, &c);
    menuA[2] = new TomKlong(true, true, 130, 5, a[1]);

    for (int i = 0; i < 3; i++)
    {
        cout << *menuA[i];
    }

    // ------

    for (int i = 0; i < 3; i++)
    {
        cout << "MenuA ที่ " << i << " ใช้วิธี " << menuA[i]->getMeat()->getMeatType() << endl;
    }

    // ------

    Larb myLarb(false, 65, 2, a[0]);
    if (myLarb.getMeat()->getType() == 1)
    {
        myLarb.getMeat()->show();
    }

    // ------

    TomYam myTomYam(false, true, 180, 1, a[3]);
    if (myTomYam > *menuA[0])
    {
        cout << "myTomYam เผ็ดมากกว่า menusA[0]" << endl;
    }
    else
    {
        cout << "myTomYam เผ็ดน้อยกว่า menusA[0]" << endl;
    }

    // ------

    ThaiFood *menuB[2];
    menuB[0] = &myLarb;
    menuB[1] = &myTomYam;

    for (int i = 0; i < 2; i++)
    {
        cout << (*menuB[i])() << endl;
    }

    // ------

    ThaiFood **allMenu[2];
    allMenu[0] = menuA;
    allMenu[1] = menuB;

    // ------

    double total = 0;
    for (int i = 0; i < 3; i++)
    {
        total += (*allMenu[0][i]).getPrice();
    }
    for (int i = 0; i < 2; i++)
    {
        total += (*allMenu[1][i]).getPrice();
    }
    cout << "ราคา allMenu = " << total << endl;

    // ------

    for (int i = 0; i < 3; i++)
    {
        !(*allMenu[0][i]);
    }
    for (int i = 0; i < 2; i++)
    {
        !(*allMenu[1][i]);
    }

    for (int i = 0; i < 3; i++)
    {
        (*allMenu[0][i]).show();
    }
    for (int i = 0; i < 2; i++)
    {
        (*allMenu[1][i]).show();
    }

    // ------

    myLarb.setMeat(0);
    myTomYam.setMeat(0);

    for (int i = 0; i < 3; i++)
    {
        delete menuA[i];
    }

    delete[] menuA;

    for (int i = 0; i < 4; i++)
    {
        delete a[i];
    }

    for (int i = 0; i < 2; i++)
    {
        delete b[i];
    }

    // ------

    cout << "ThaiFoodCount: " << ThaiFood::getCount() << endl;

    return 0;
}

// ---- final LAB

// test on
// MacOS 13.6.1
// gcc Apple clang version 15.0.0 (clang-1500.0.40.1)
// 08/11/2023
