#include <iostream>
#include <string>

using namespace std;

class Cooking
{
    double time; // ระยะเวลาที่ใช้ในการปรุงอาหาร
public:
    Cooking()
    {
        time = 0;
    }
    Cooking(double t)
    {
        time = t;
    }
    virtual ~Cooking() {}

    // get
    double getTime()
    {
        return time;
    }

    // show
    virtual void show() = 0;
};

class Grill : public Cooking
{
    int stoveType; // เช่น 1.เตาอั้งโล่ 2.เตาฮิบาชิ 3.เตาปิ้งย่างไฟฟ้า
public:
    Grill() : Cooking(5)
    {
        stoveType = 3;
    }
    Grill(int type, double time) : Cooking(time)
    {
        if (type >= 1 && type <= 3)
        {
            stoveType = type;
        }
        else
        {
            stoveType = 3;
        }
    }

    // get
    int getStoveType()
    {
        return stoveType;
    }

    // show
    void show()
    {
        cout << "time: " << getTime() << endl;
        cout << "stoveType: " << stoveType << endl;
    }
};

class Fry : public Cooking
{
    bool oilFree; // true: ไม่ใช้น้ำมัน false: ใช้น้ำมัน
public:
    Fry() : Cooking(3)
    {
        oilFree = true;
    }
    Fry(bool oil, double time) : Cooking(time)
    {
        oilFree = oil;
    }

    // get
    bool getOilFree()
    {
        return oilFree;
    }

    // show
    void show()
    {
        cout << "time: " << getTime() << endl;
        cout << "oilFree: " << oilFree << endl;
    }
};

class Meat
{
    bool organic; // true: ปลอดสาร false: ไม่ปลอดสาร
public:
    Meat()
    {
        organic = false;
    }
    Meat(bool o)
    {
        organic = o;
    }

    virtual ~Meat() {}

    // get
    bool getOrganic()
    {
        return organic;
    }

    // show
    virtual void show() = 0;
};

class Pork : public Meat
{
    int part; // ส่วนของหมู เช่น 1.สันใน 2.ซี่โครงอ่อน 3.สามชั้น
public:
    Pork() : Meat(true)
    {
        part = 1;
    }
    Pork(int p, bool organic) : Meat(organic)
    {
        if (p >= 1 && p <= 3)
        {
            part = p;
        }
        else
        {
            part = 1;
        }
    }

    // get
    int getPart()
    {
        return part;
    }

    // show
    void show()
    {
        cout << "organic: " << getOrganic() << endl;
        cout << "part: " << part << endl;
    }
};

class Chicken : public Meat
{
    int type; // ชนิดของไก่ เช่น 1.ไก่บ้าน 2.ไก่เนื้อ
public:
    Chicken() : Meat(false)
    {
        type = 2;
    }
    Chicken(int t, bool organic) : Meat(organic)
    {
        if (t >= 1 && t <= 2)
        {
            type = t;
        }
        else
        {
            type = 2;
        }
    }

    // get
    int getType()
    {
        return type;
    }

    // show
    void show()
    {
        cout << "organic: " << getOrganic() << endl;
        cout << "type: " << type << endl;
    }
};

class Food
{
    static int foodCount; // นับ food

    double price;     // ราคาอาหาร
    string dishName;  // ชื่ออาหาร
    Cooking *cooking; // พอยเตอร์ที่ชี้ไปยัง Cooking
    Meat **meat;      // อาร์เรย์ขนาด num เก็บพอยเตอร์ที่ชี้ไปยัง Meat
    int num;          // ขนาดของอาร์เรย์ meat
public:
    Food()
    {
        price = 20;
        dishName = "rice";
        cooking = 0;
        meat = 0;
        num = 0;
        foodCount++;
    }
    Food(double p, string name, Cooking *ck, int n)
    {
        price = p;
        dishName = name;
        cooking = ck;
        num = n;
        meat = new Meat *[n];
        foodCount++;
    }
    Food(Food &f)
    {
        price = f.price;
        dishName = f.dishName;
        cooking = f.cooking;
        num = f.num;
        meat = new Meat *[f.num];
        for (int i = 0; i < f.num; i++)
        {
            meat[i] = f.meat[i];
        }
        foodCount++;
    }
    ~Food()
    {
        --foodCount;
        delete[] meat;
        cout << "foodCount: " << foodCount << endl;
    }

    // set

    void setMeat(int i, Meat *m)
    {
        meat[i] = m;
    }
    void setNum(int n)
    {
        if (n < 0)
        {
            n = 0;
        }
        num = n;
        delete[] meat;
        meat = new Meat *[n];
    }
    void setCooking(Cooking *c)
    {
        cooking = c;
    }

    // get
    double getPrice()
    {
        return price;
    }
    string getDishName()
    {
        return dishName;
    }
    Cooking *getCooking()
    {
        return cooking;
    }
    Meat *getMeat(int i)
    {
        return meat[i];
    }
    int getNum()
    {
        return num;
    }

    // show
    void show()
    {
        cout << "price: " << price << endl;
        cout << "dishName: " << dishName << endl;
        if (cooking != 0)
        {
            cooking->show();
        }
        for (int i = 0; i < this->num; i++)
        {
            meat[i]->show();
        }
    }

    // requirements

    void set(Cooking *c)
    {
        cooking = c;
    }
    void set(Cooking *c, string name)
    {
        cooking = c;
        dishName = name;
    }
    void set(Cooking *c, string name, double p)
    {
        cooking = c;
        dishName = name;
        price = p;
    }

    static int getCount()
    {
        return foodCount;
    }
};

int Food::foodCount;

class Order
{
    Food *food;  // อาร์เรย์ขนาด num เก็บอ็อบเจกต์ของคลาส
    int num;     // ขนาดของอาร์เรย์ food
    bool member; // เป็นสมาชิกของร้าน
public:
    Order()
    {
        food = 0;
        num = 0;
        member = false;
    }
    Order(int n, bool m)
    {
        num = n;
        member = m;
        food = new Food[n];
    }
    ~Order()
    {
        delete[] food;
    }
    Order(Order &o)
    {
        num = o.num;
        member = o.member;
        food = new Food[o.num];
        for (int i = 0; i < o.num; i++)
        {
            food[i] = o.food[i];
        }
    }

    // set

    void setFood(int i, Food &f)
    {
        food[i] = f;
    }
    void setNum(int n)
    {
        if (n < 0)
        {
            n = 0;
        }
        num = n;
        delete[] food;
        food = new Food[n];
    }
    void setMember(bool m)
    {
        member = m;
    }

    // get
    int getNum()
    {
        return num;
    }
    bool getMember()
    {
        return member;
    }
    Food &getFood(int i)
    {
        return food[i];
    }
    int getOrganic()
    {
        int total = 0;
        for (int i = 0; i < num; i++)
        {
            Food *f = &food[i];
            for (int k = 0; k < f->getNum(); k++)
            {
                if (f->getMeat(k)->getOrganic())
                {
                    total++;
                }
            }
        }
        return total;
    }

    // show
    void show()
    {
        cout << "num: " << num << endl;
        cout << "member: " << member << endl;
        for (int i = 0; i < num; i++)
        {
            food[i].show();
        }
    }

    // operator
    double operator!()
    {
        double total = 0;
        for (int i = 0; i < num; i++)
        {
            total += food[i].getPrice();
        }
        return total;
    }
    bool operator()()
    {
        return member;
    }
};

// io

ostream &operator<<(ostream &os, Cooking &cooking)
{
    cooking.show();
    return os;
}

ostream &operator<<(ostream &os, Meat &meat)
{
    meat.show();
    return os;
}

ostream &operator<<(ostream &os, Food &food)
{
    food.show();
    return os;
}

ostream &operator<<(ostream &os, Order &order)
{
    order.show();
    return os;
}

int main()
{
    Cooking *c[4];
    c[0] = new Grill(1, 30);
    c[1] = new Grill(2, 25);
    c[2] = new Fry(false, 10);
    c[3] = new Fry(true, 20);

    for (int i = 0; i < 4; i++)
    {
        c[i]->show();
    }

    Meat *m[6];
    m[0] = new Chicken(2, true);
    m[1] = new Chicken(2, false);
    m[2] = new Chicken(1, true);
    m[3] = new Pork(1, true);
    m[4] = new Pork(2, true);
    m[5] = new Pork(3, true);

    for (int i = 0; i < 6; i++)
    {
        m[i]->show();
    }

    Food muTod(120, "Garlic Fried Pork", c[3], 1);
    muTod.setMeat(0, m[3]);
    muTod.show();

    muTod.setNum(2);
    muTod.setMeat(0, m[3]);
    muTod.setMeat(1, m[4]);
    muTod.setCooking(c[3]);
    muTod.show();

    Food kaiYang(100, "Kai Yang", c[0], 3);
    kaiYang.setMeat(0, m[0]);
    kaiYang.setMeat(1, m[1]);
    kaiYang.setMeat(2, m[2]);
    kaiYang.show();

    Food samChanTod(130, "Sam Chan tod", c[2], 1);
    samChanTod.setMeat(0, m[5]);
    samChanTod.show();

    Food rice;
    // rice.show();
    cout << "จำนวนอาหาร Food ของ rice = " << Food::getCount() << endl;

    Order order1(2, false);
    order1.setFood(0, rice);
    order1.setFood(1, muTod);
    order1.show();

    Order order2(4, false);
    order2.setFood(0, rice);
    order2.setFood(1, rice);
    order2.setFood(2, kaiYang);
    order2.setFood(3, samChanTod);
    order2.show();

    cout << "ราคา order1 = " << !order1 << endl;
    cout << "ราคา order2 = " << !order2 << endl;

    Order order3 = order1;
    order3.setMember(!order3.getMember());
    cout << "member order3 = " << order3() << endl;

    int order3og = order3.getOrganic();
    cout << "order3 มีเนื้อสัตว์ปลอดสารพิษ = " << order3og << endl;

    for (int i = 0; i < order3.getNum(); i++)
    {
        cout << "order3 food at: " << i << " = " << order3.getFood(i).getDishName() << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete c[i];
    }

    for (int i = 0; i < 6; i++)
    {
        delete m[i];
    }

    return 0;
}
