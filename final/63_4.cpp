#include <iostream>
#include <string>

using namespace std;

class Meat
{
    string shopName; // ชื่อร้านค้าที่ขายเนื้อสัตว์
public:
    Meat(string shopName)
    {
        this->shopName = shopName;
    }
    virtual ~Meat() {}
    // get
    string getShopName()
    {

        return this->shopName;
    }
    // show
    virtual void show() = 0;
};

class Pork : public Meat
{
    int part; // ส่วนของหมู เช่น 1.เนื้อหมู 2.ตับ 3.ซี่โครงหมู
public:
    Pork(int part, string shopName) : Meat(shopName)
    {
        if (part >= 1 && part <= 3)
        {
            this->part = part;
        }
        else
        {
            this->part = 1; // maybe default
        }
    }
    // get
    int getPart()
    {
        return this->part;
    }
    // show
    void show()
    {
        cout << " Meat(shopName: " << this->getShopName() << ")" << endl;
        cout << " Pork(part: " << this->part << ")" << endl;
    }
};

class Fish : public Meat
{
    string fishName; // ชื่อปลา
public:
    Fish(string fishName, string shopName) : Meat(shopName)
    {
        this->fishName = fishName;
    }
    // get
    string getFishName()
    {

        return this->fishName;
    }
    // show
    void show()
    {
        cout << " Meat(shopName: " << this->getShopName() << ")" << endl;
        cout << " Fish(fishName: " << this->fishName << ")" << endl;
    }
};

class Prawn : public Meat
{
    int size; // ขนาดของกุ้ง 1.เล็ก 2.กลาง 3.ใหญ่
public:
    Prawn(int size, string shopName) : Meat(shopName)
    {
        if (size >= 1 && size <= 3)
        {
            this->size = size;
        }
        else
        {
            this->size = 1;
        }
    }
    // get
    int getSize()
    {
        return this->size;
    }
    // show
    void show()
    {
        cout << " Meat(shopName: " << this->getShopName() << ")" << endl;
        cout << " Prawn(size: " << this->size << ")" << endl;
    }
};

class Squid : public Meat
{
    int size; // ขนาดของปลาหมึก 1.เล็ก 2.กลาง 3.ใหญ่
public:
    Squid(int size, string shopName) : Meat(shopName)
    {
        if (size >= 1 && size <= 3)
        {
            this->size = size;
        }
        else
        {
            this->size = 1;
        }
    }
    // get
    int getSize()
    {
        return this->size;
    }
    // show
    void show()
    {
        cout << " Meat(shopName: " << this->getShopName() << ")" << endl;
        cout << " Squid(size: " << this->size << ")" << endl;
    }
};

class KuayTeow
{
    static int KT_COUNT;

    double price;   // ราคา
    int noodle;     // เส้นก๋วยเตี๋ยว 1.เล็ก 2.หมี่ 3.ใหญ่ 4.บะหมี่ 5.วุ้นเส้น
    int spicyLevel; // ระดับความเผ็ดมี 5 ระดับคือ 1, 2, 3, 4, 5
    Meat **meat;    // อาร์เรย์ขนาด num เก็บพอยเตอร์ที่ชี้ไปยัง Meat
    int num;        // ขนาดของอาร์เรย์ meat
    void init(int num)
    {
        if (num <= 0)
        {
            this->num = 0;
            this->meat = 0;
        }
        else
        {
            this->num = num;
            this->meat = new Meat *[num];
        }
    }
    void del()
    {
        delete[] this->meat;
    }

protected:
    void copy(const KuayTeow &other)
    {
        this->price = other.price;
        this->noodle = other.noodle;
        this->spicyLevel = other.spicyLevel;
        this->num = other.num;
        this->meat = new Meat *[other.num];
        for (int i = 0; i < other.num; i++)
        {
            this->meat[i] = other.meat[i];
        }
    }

public:
    KuayTeow()
    {
        this->spicyLevel = 2;
        this->price = 0;
        this->noodle = 1;
        this->meat = 0;
        this->num = 0;
        KT_COUNT++;
    }
    KuayTeow(double price, int noodle, int spicyLevel, int num)
    {
        this->setPrice(price);
        this->setNoodle(noodle);
        this->setSpicyLevel(spicyLevel);
        this->init(num);
        KT_COUNT++;
    }
    virtual ~KuayTeow()
    {
        // this->show();
        this->del();
        KT_COUNT--;
    }
    KuayTeow(KuayTeow &other)
    {
        this->copy(other);
    }
    // set
    void setPrice(double price)
    {
        if (price >= 0)
        {
            this->price = price;
        }
        else
        {
            this->price = 0;
        }
    }
    void setNoodle(int noodle)
    {
        if (noodle >= 1 && noodle <= 5)
        {
            this->noodle = noodle;
        }
        else
        {
            this->noodle = 1; // default
        }
    }
    void setSpicyLevel(int spicyLevel)
    {
        if (spicyLevel >= 1 && spicyLevel <= 5)
        {
            this->spicyLevel = spicyLevel;
        }
        else
        {
            this->spicyLevel = 1; // default
        }
    }
    void setNum(int num)
    {
        if (num == this->num)
        {
            return;
        }
        this->del();
        this->init(num);
    }
    void setMeat(int i, Meat *meat)
    {
        this->meat[i] = meat;
    }

    // get
    double getPrice()
    {
        return this->price;
    }
    int getNoodle()
    {
        return this->noodle;
    }
    int getSpicyLevel()
    {
        return this->spicyLevel;
    }
    int getNum()
    {
        return this->num;
    }
    Meat *getMeat(int i)
    {
        return this->meat[i];
    }

    // show
    virtual void show() = 0;

    // static
    static int count()
    {
        return KT_COUNT;
    }

    // operator
    KuayTeow &operator=(KuayTeow &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->del();
        this->copy(other);
        return *this;
    }
};

int KuayTeow::KT_COUNT;

class KuayTeowNamtok : public virtual KuayTeow
{
    int namTokType; // สูตร 1.น้ำตกน้ำ 2.น้ำตกแห้ง

protected:
    void copy(KuayTeowNamtok &other)
    {
        this->namTokType = other.namTokType;
    }

public:
    KuayTeowNamtok() : KuayTeow(40, 1, 2, 0)
    {
        this->namTokType = 1;
    }
    KuayTeowNamtok(int namTokType, double price, int noodle, int spicyLevel, int num) : KuayTeow(price, noodle, spicyLevel, num)
    {
        this->setNamTokType(namTokType);
    }
    ~KuayTeowNamtok()
    {
        this->show();
    }
    KuayTeowNamtok(KuayTeowNamtok &other) : KuayTeow(other)
    {
        this->copy(other);
    }

    // set
    void setNamTokType(int namTokType)
    {
        if (namTokType >= 1 && namTokType <= 2)
        {
            this->namTokType = namTokType;
        }
        else
        {
            this->namTokType = 1;
        }
    }
    // get
    int getNamTokType()
    {
        return this->namTokType;
    }

    // show
    void show()
    {
        cout << "KuayTeow(" << endl;
        cout << " price: " << this->getPrice() << endl;
        cout << " noodle: " << this->getNoodle() << endl;
        cout << " spicyLevel: " << this->getSpicyLevel() << endl;
        cout << " meat: " << endl;
        for (int i = 0; i < this->getNum(); i++)
        {
            this->getMeat(i)->show();
        }
        cout << ")" << endl;

        cout << "KuayTeowNamtok(" << endl;
        cout << " namTokType: " << this->namTokType << endl;
        cout << ")" << endl;
    }

    // operator
    KuayTeowNamtok &operator=(KuayTeowNamtok &other)
    {
        if (this == &other)
        {
            return *this;
        }
        KuayTeow::operator=(other);
        this->copy(other);
        return *this;
    }
};

class KuayTeowTomYam : public virtual KuayTeow
{
    int tomYamType; // สูตร 1.พริกเผาน้ำ 2.พริกเผาแห้ง 3.น้ำใส
protected:
    void copy(KuayTeowTomYam &other)
    {
        this->tomYamType = other.tomYamType;
    }

public:
    KuayTeowTomYam() : KuayTeow(40, 1, 3, 0)
    {
        this->tomYamType = 3;
    }
    KuayTeowTomYam(int tomYamType, double price, int noodle, int spicyLevel, int num) : KuayTeow(price, noodle, spicyLevel, num)
    {
        this->setTomYamType(tomYamType);
    }
    ~KuayTeowTomYam()
    {
        this->show();
    }
    KuayTeowTomYam(KuayTeowTomYam &other) : KuayTeow(other)
    {
        this->copy(other);
    }

    // set
    void setTomYamType(int tomYamType)
    {
        if (tomYamType >= 1 && tomYamType <= 3)
        {
            this->tomYamType = tomYamType;
        }
        else
        {
            this->tomYamType = 3;
        }
    }

    // get
    int getTomYamType()
    {
        return this->tomYamType;
    }

    // show
    void show()
    {
        cout << "KuayTeow(" << endl;
        cout << " price: " << this->getPrice() << endl;
        cout << " noodle: " << this->getNoodle() << endl;
        cout << " spicyLevel: " << this->getSpicyLevel() << endl;
        cout << ")" << endl;

        cout << "KuayTeowTomYam(" << endl;
        cout << " tomYamType: " << this->tomYamType << endl;
        cout << ")" << endl;
    }

    // operator
    KuayTeowTomYam &operator=(KuayTeowTomYam &other)
    {
        if (this == &other)
        {
            return *this;
        }
        KuayTeow::operator=(other);
        this->copy(other);
        return *this;
    }
};

class KuayTeowTomYamNamTok : public KuayTeowNamtok, public KuayTeowTomYam
{
    bool chiliSauce; // true: ใส่ซอสพริก false: ไม่ใส่ซอสพริก
protected:
    void copy(KuayTeowTomYamNamTok &other)
    {
        this->chiliSauce = other.chiliSauce;
    }

public:
    KuayTeowTomYamNamTok() : KuayTeow(50, 1, 3, 0) // you can call constructor
    {
        this->chiliSauce = false;
        this->setNamTokType(1);
        this->setTomYamType(1);
    }
    KuayTeowTomYamNamTok(bool chiliSauce, int namTokType, int tomYamType, double price, int noodle, int spicyLevel, int num) : KuayTeow(price, noodle, spicyLevel, num)
    {
        this->chiliSauce = chiliSauce;
        this->setNamTokType(namTokType);
        this->setTomYamType(tomYamType);
    }
    ~KuayTeowTomYamNamTok()
    {
        this->show();
    }
    KuayTeowTomYamNamTok(KuayTeowTomYamNamTok &other) : KuayTeow(other), KuayTeowNamtok(other), KuayTeowTomYam(other)
    {
        this->copy(other);
    }

    // set
    void setShiliSauce(bool chiliSauce)
    {
        this->chiliSauce = chiliSauce;
    }

    // get
    bool getShiliSauce()
    {
        return this->chiliSauce;
    }

    // show
    void show()
    {
        KuayTeowNamtok::show();

        cout << "KuayTeowTomYam(" << endl;
        cout << " tomYamType: " << this->getTomYamType() << endl;
        cout << ")" << endl;

        cout << "KuayTeowTomYamNamTok(" << endl;
        cout << " chiliSauce: " << this->chiliSauce << endl;
        cout << ")" << endl;
    }

    // operator
    KuayTeowTomYamNamTok &operator=(KuayTeowTomYamNamTok &other)
    {
        if (this == &other)
        {
            return *this;
        }
        KuayTeowNamtok::operator=(other); // KuayTeowNamtok -> KuayTeow
        KuayTeowTomYam::copy(other);      // Only KuayTeowTomYam
        this->copy(other);
        return *this;
    }

    // req
    void set(double price)
    {
        this->setPrice(price);
    }
    void set(double price, int namTokType)
    {
        this->setPrice(price);
        this->setNamTokType(namTokType);
    }
    void set(double price, int namTokType, bool chiliSauce)
    {
        this->setPrice(price);
        this->setNamTokType(namTokType);
        this->chiliSauce = chiliSauce;
    }
};

class Order
{
    KuayTeow **kuayTeow; // อาร์เรย์ขนาด num เก็บพอยเตอร์ที่ชี้ไปยังอ็อบเจกต์ของคลาส KuayTeow
    int num;             // ขนาดของอาร์เรย์kuayTeow
    int tableNo;         // หมายเลขโต๊ะ
    void init(int num)
    {
        this->num = num;
        this->kuayTeow = new KuayTeow *[num];
    }
    void del()
    {
        delete[] this->kuayTeow;
    }

public:
    Order()
    {
        this->num = 0;
        this->tableNo = 0;
        this->kuayTeow = 0;
    }
    Order(int tableNo, int num)
    {
        this->tableNo = tableNo;
        this->init(num);
    }
    ~Order()
    {
        this->del();
    }

    // set
    void setNum(int num)
    {
        if (num == this->num)
        {
            return;
        }
        this->del();
        this->init(num);
    }
    void setTableNo(int tableNo)
    {
        this->tableNo = tableNo;
    }
    void setKuayTeow(int i, KuayTeow *kt)
    {
        this->kuayTeow[i] = kt;
    }

    // get
    int getNum()
    {
        return this->num;
    }
    int getTableNo()
    {
        return this->tableNo;
    }
    KuayTeow *getKuayTeow(int i)
    {
        return this->kuayTeow[i];
    }
    int getNum(string name)
    {
        int total = 0;
        for (int i = 0; i < this->num; i++)
        {
            KuayTeow *kt = this->kuayTeow[i];
            for (int k = 0; k < kt->getNum(); k++)
            {
                if (kt->getMeat(k)->getShopName() == name)
                {
                    total++;
                }
            }
        }
        return total;
    }

    // operator
    int operator()(int level)
    {
        int total = 0;
        for (int i = 0; this->num; i++)
        {
            if (this->kuayTeow[i]->getSpicyLevel() == level)
            {
                total++;
            }
        }
        return total;
    }
    Order &operator=(Order &other)
    {
        if (this == &other)
        {
            return *this;
        }
        this->num = other.num;
        this->tableNo = other.tableNo;
        this->del();
        this->init(other.num);
        for (int i = 0; i < other.num; i++)
        {
            this->kuayTeow[i] = other.kuayTeow[i];
        }
        return *this;
    }
    int operator+(Order &other)
    {
        int total = 0;
        for (int i; i < this->num; i++)
        {
            total += this->kuayTeow[i]->getPrice();
        }
        for (int i; i < other.getNum(); i++)
        {
            total += other.kuayTeow[i]->getPrice();
        }
        return total;
    }
    friend int operator+(int n, Order &o)
    {

        int total = 0;
        for (int i; i < o.getNum(); i++)
        {
            total += o.kuayTeow[i]->getPrice();
        }
        return n + total;
    }
};

ostream &operator<<(ostream &os, Order &order)
{
    os << "num: " << order.getNum() << endl;
    os << "tableNo: " << order.getTableNo() << endl;
    for (int i = 0; i < order.getNum(); i++)
    {
        order.getKuayTeow(i)->show();
    }
    return os;
}

int main()
{
    Pork pork1(1, "A");
    Pork pork2(1, "A");
    Pork pork3(1, "A");
    Fish fish("plakrapong", "B");
    Prawn prawn(2, "C");
    Squid squid(3, "C");

    Order order1(1, 3);

    KuayTeowNamtok k1(1, 60, 1, 4, 3);
    k1.setMeat(0, &pork1);
    k1.setMeat(1, &pork2);
    k1.setMeat(2, &pork3);

    KuayTeowNamtok k2(2, 55, 2, 5, 2);
    k2.setMeat(0, &pork1);
    k2.setMeat(1, &pork2);

    KuayTeowTomYam k3(2, 65, 2, 5, 4);
    k3.setMeat(0, &pork1);
    k3.setMeat(1, &pork2);
    k3.setMeat(2, &prawn);
    k3.setMeat(3, &squid);

    order1.setKuayTeow(0, &k1);
    order1.setKuayTeow(1, &k2);
    order1.setKuayTeow(2, &k3);

    cout << order1 << endl;

    Order order2(2, 2);

    KuayTeowTomYam k4(2, 60, 2, 2, 1);
    k4.setMeat(0, &fish);

    KuayTeowTomYamNamTok k5(false, 1, 1, 70, 1, 4, 3);
    k5.setMeat(0, &pork1);
    k5.setMeat(1, &pork2);
    k5.setMeat(2, &pork3);

    order2.setKuayTeow(0, &k4);
    order2.setKuayTeow(1, &k5);

    cout << order2 << endl;

    Order order3(3, 1);

    KuayTeowTomYamNamTok k6(false, 1, 1, 80, 1, 3, 3);
    k6.setMeat(0, &fish);
    k6.setMeat(1, &prawn);
    k6.setMeat(2, &squid);

    order3.setKuayTeow(0, &k6);

    cout << order3 << endl;

    KuayTeowTomYamNamTok k7 = k6;
    k7.setSpicyLevel(2);
    k7.show();

    order3.setNum(2);
    order3.setKuayTeow(0, &k6);
    order3.setKuayTeow(1, &k7);

    int totalSpicy4 = 0;
    for (int i; i < order1.getNum(); i++)
    {
        if (order1.getKuayTeow(i)->getSpicyLevel() == 4)
        {
            totalSpicy4++;
        }
    }
    for (int i; i < order2.getNum(); i++)
    {
        if (order2.getKuayTeow(i)->getSpicyLevel() == 4)
        {
            totalSpicy4++;
        }
    }
    for (int i; i < order3.getNum(); i++)
    {
        if (order3.getKuayTeow(i)->getSpicyLevel() == 4)
        {
            totalSpicy4++;
        }
    }
    cout << "order1 order2 order3 มีก๋วยเตี๋ยวเผ็ดระดับ 4 จำนวน: " << totalSpicy4 << endl;
    cout << "ราคารวม order1 order2 order3: " << order1 + order2 + order3 << endl;

    int totalA = order1.getNum("A") + order2.getNum("A") + order3.getNum("A");
    int totalB = order1.getNum("B") + order2.getNum("B") + order3.getNum("B");
    int totalC = order1.getNum("C") + order2.getNum("C") + order3.getNum("C");

    cout << "วัตถุดิบจากร้าน A จำนวน: " << totalA << endl;
    cout << "วัตถุดิบจากร้าน B จำนวน: " << totalB << endl;
    cout << "วัตถุดิบจากร้าน C จำนวน: " << totalC << endl;

    return 0;
}