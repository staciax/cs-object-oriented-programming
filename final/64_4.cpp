#include <iostream>
#include <string>

using namespace std;

class Fruit
{
    string province; // จังหวัดที่ปลูกผลไม้
public:
    Fruit(string province)
    {
        this->province = province;
    }
    virtual ~Fruit()
    {
        cout << "delete: Fruit " << this->province << endl;
    }

    // set
    void setProvince(string province)
    {
        this->province = province;
    }

    // get
    string getProvince()
    {
        return this->province;
    }

    // show
    virtual void show() = 0;
};

class Orange : public Fruit
{
    int type; // 1.ส้มสายน้ำผึ้ง 2.ส้มเขียวหวาน
public:
    Orange(string province, int type) : Fruit(province)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
        }
        else
        {
            // maybe
            this->type = 1;
        }
    }

    // set
    void setType(int type)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
        }
    }

    // get
    int getType()
    {
        return this->type;
    }

    // show
    void show()
    {
        cout << "province: " << this->getProvince() << endl;
        cout << "type: " << this->type << endl;
    }
};

class Lime : public Fruit
{
    int size; // 1.เล็ก 2.กลาง 3.ใหญ่
public:
    Lime(string province, int size) : Fruit(province)
    {
        if (size >= 1 && size <= 3)
        {
            this->size = size;
        }
        else
        {
            // maybe
            this->size = 1;
        }
    }
    // set
    void setSize(int size)
    {
        if (size >= 1 && size <= 3)
        {
            this->size = size;
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
        cout << "province: " << this->getProvince() << endl;
        cout << "size: " << this->size << endl;
    }
};

class Mango : public Fruit
{
    int type; // 1.น้ำดอกไม้ 2.มหาชนก
public:
    Mango(string province, int type) : Fruit(province)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
        }
        else
        {
            // maybe
            this->type = 1;
        }
    }
    // set
    void setType(int type)
    {
        if (type >= 1 && type <= 3)
        {
            this->type = type;
        }
    }

    // get
    int getType()
    {
        return this->type;
    }

    // show
    void show()
    {
        cout << "province: " << this->getProvince() << endl;
        cout << "type: " << this->type << endl;
    }
};

class Drink
{
    double price; // ราคา
public:
    Drink()
    {
        this->price = 60;
    }
    Drink(double price)
    {
        this->price = price;
    }
    virtual ~Drink()
    {
        cout << "delete: Drink " << this->price << endl;
    }

    // set
    void setPrice(double price)
    {
        this->price = price;
    }

    // get
    double getPrice()
    {
        return this->price;
    }

    // show
    virtual void show() = 0;
};

class Milk : public virtual Drink
{
    int flavor; // 1.รสจืด 2.รสหวาน 3.รสช็อกโกแลต
public:
    Milk() : Drink(60)
    {
        this->flavor = 1;
    }
    Milk(int flavor)
    {
        if (flavor >= 1 && flavor <= 3)
        {
            this->flavor = flavor;
        }
        else
        {
            this->flavor = 1;
        }
    }
    Milk(double price, int flavor) : Drink(price)
    {
        this->flavor = flavor;
    }
    ~Milk()
    {
        cout << "delete Milk ";
        this->show();
    }

    // set
    void setFlavor(int flavor)
    {
        if (flavor >= 1 && flavor <= 3)
        {
            this->flavor = flavor;
        }
        else
        {
            this->flavor = 1;
        }
    }

    // get
    int getFlavor()
    {
        return this->flavor;
    }

    // show
    void show()
    {
        cout << "price: " << this->getPrice() << endl;
        cout << "flavor: " << this->flavor << endl;
    }
};

class Juice : public virtual Drink
{
    static int juiceCount;
    int type;      // 1.คั้น 2.ปั่น
    Fruit **fruit; // อาร์เรย์เก็บพอยเตอร์ที่ชี้ไปยัง Fruit
    int num;       // ขนาดของอาร์เรย์fruit

public:
    Juice() : Drink(70)
    {
        this->type = 0;
        this->fruit = 0;
        this->num = 0;
        juiceCount++;
    }
    Juice(int type, int num)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
        }
        else
        {
            this->type = 1;
        }
        this->num = num;
        this->fruit = new Fruit *[num];
        juiceCount++;
    }
    Juice(double price, int type, int num) : Drink(price)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
        }
        else
        {
            this->type = 1;
        }
        this->num = num;
        this->fruit = new Fruit *[num];
        juiceCount++;
    }
    ~Juice()
    {
        if (this->fruit != 0)
        {
            cout << "delete Juice ";
            this->show();
            delete[] this->fruit;
        }
        juiceCount--;
    }

    // set
    void setType(int type)
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
    void setNum(int num)
    {
        delete[] this->fruit;
        this->fruit = new Fruit *[num];
        this->num = num;
    }
    void setFruit(int index, Fruit *fruit)
    {
        this->fruit[index] = fruit;
    }

    // get

    int getType()
    {
        return this->type;
    }
    int getNum()
    {
        return this->num;
    }
    Fruit *getFruit(int index)
    {
        return this->fruit[index];
    }

    // show
    void show() {}

    // static
    static int count()
    {
        return juiceCount;
    }
};

class JuiceMilk : public Milk, public Juice
{
    bool addHoney; // true: ใส่น้ำผึ้ง false: ไม่ใส่น้ำผึ้ง
public:
    JuiceMilk() : Drink(75), Milk(1), Juice(0, 0)
    {
        this->addHoney = false;
    }
    JuiceMilk(double price, int flavor, int type, int num, bool addHoney) : Drink(price), Milk(flavor), Juice(type, num)
    {
        this->addHoney = addHoney;
    }
    ~JuiceMilk()
    {
        cout << "delete JuiceMilk ";
        this->show();
    }

    // copy
    JuiceMilk(JuiceMilk &other) : Drink(other.getPrice()), Milk(other.getFlavor()), Juice(other.getType(), other.getNum())
    {
        this->addHoney = other.addHoney;
    }

    // set
    void setAddHoney(bool addHoney)
    {
        this->addHoney = addHoney;
    }

    // get
    bool getAddHoney()
    {
        return this->addHoney;
    }

    // show
    void show()
    {
        cout << "addHoney: " << this->addHoney << endl;
    }

    // operator
    bool operator==(JuiceMilk &other)
    {
        bool isSame = false;
        for (int i = 0; i < this->getNum(); i++)
        {
            for (int k = 0; k < other.getNum(); k++)
            {
                if (this->getFruit(i)->getProvince() == other.getFruit(k)->getProvince())
                {
                    return true;
                }
            }
        }
        return isSame;
    }

    // req

    int addFruit(Fruit *fruit)
    {
        // TODO: แปลกๆ
        // this->setFruit(++this->getNum(), fruit);
        return this->getNum();
    }
};

class Refrigerator
{
    int numOfDoor; // จำนวนประตูของตู้เย็น
    Drink **drink; // อาร์เรย์เก็บพอยเตอร์ที่ชี้ไปยัง Drink
    int numDrink;  // ขนาดของอาร์เรย์drink

public:
    Refrigerator()
    {
        this->numOfDoor = 1;
        this->drink = 0;
        this->numDrink = 0;
    }
    ~Refrigerator()
    {
        if (drink != 0)
        {
            cout << "delete: Refrigerator ";
            this->show();
            delete[] this->drink;
        }
    }

    // set
    void setNumOfDoor(int num)
    {
        this->numOfDoor = num;
    }
    void setNumDrink(int num)
    {
        delete[] this->drink;
        this->drink = new Drink *[num];
        this->numDrink = num;
    }
    void setDrink(int index, Drink *drink)
    {
        this->drink[index] = drink;
    }

    // get
    int getNumOfDoor()
    {
        return this->numOfDoor;
    }
    int getNumDrink()
    {
        return this->numDrink;
    }
    Drink *getDrink(int index)
    {
        return this->drink[index];
    }

    // show
    void show()
    {
        cout << "numOfDoor: " << this->numOfDoor << endl;
        cout << "numDrink: " << this->numDrink << endl;
    }

    // operator

    bool operator>(Refrigerator &other)
    {
        return this->getNumDrink() > other.getNumDrink();
    }
    double operator!()
    {
        double total = 0;
        for (int i = 0; i < this->numDrink; i++)
        {
            total += this->drink[i]->getPrice();
        }
        return total;
    }
    friend double operator+(Refrigerator &r1, Refrigerator &r2)
    {
        return !r1 + !r2;
    }
    friend ostream &operator<<(ostream &os, const Refrigerator &refrigerator);
};

int Juice::juiceCount;

// io

ostream &operator<<(ostream &os, Fruit &fruit)
{
    fruit.show();
    return os;
}

ostream &operator<<(ostream &os, Drink &drink)
{
    drink.show();
    return os;
}

ostream &operator<<(ostream &os, Refrigerator &refrigerator)
{
    return os;
}

int main()
{
    Orange orange1("Sukthothai", 2);
    Orange orange2("Chaingrai", 1);
    Lime lime1("Sukthothai", 1);
    Lime lime2("Petchburi", 2);
    Lime lime3("Petchburi", 3);
    Mango mango1("Sakao", 1);
    Mango mango2("Lamphun", 2);

    Juice d1(80, 2, 2);
    d1.setFruit(0, &orange1);
    d1.setFruit(1, &lime1);

    Milk d2(40, 3);

    JuiceMilk d3(90, 1, 2, 2, true);
    // TODO: call add fruit
    d3.Juice::setFruit(0, &lime2);
    d3.Juice::setFruit(1, &lime2);

    JuiceMilk d4(120, 12, 2, 3, false);
    d4.Juice::setFruit(0, &orange2);
    d4.Juice::setFruit(1, &lime3);
    d4.Juice::setFruit(2, &mango2);

    Refrigerator r[2];
    r[0].setNumOfDoor(2);
    r[0].setNumDrink(3);
    r[0].setDrink(0, &d1);
    r[0].setDrink(1, &d2);
    r[0].setDrink(2, &d3);

    r[1].setNumOfDoor(1);
    r[1].setNumDrink(1);
    r[1].setDrink(0, &d4);

    // ราคา r1 r2 อันไหนมากกว่า
    if (r[0] > r[1])
    {
        cout << "ราคา r1 มากกว่า r2 = " << (!r[0]) << endl;
    }
    else
    {
        cout << "ราคา r2 มากกว่า r1 = " << (!r[1]);
    }

    int milkCount = 0;
    for (int i = 0; i < r[0].getNumDrink(); i++)
    {
        Drink *d = r[0].getDrink(i);
        if ((typeid(*d) != typeid(Juice)) && (typeid(*d) != typeid(JuiceMilk)))
        {
            milkCount++;
        }
    }
    for (int i = 0; i < r[1].getNumDrink(); i++)
    {
        Drink *d = r[1].getDrink(i);
        if ((typeid(*d) != typeid(Juice)) && (typeid(*d) != typeid(JuiceMilk)))
        {
            milkCount++;
        }
    }
    cout << "จำนวน Milk ไม่ใช่ Juice, JuiceMilk ใน r1 r2 = " << milkCount << endl;

    if (d3 == d3)
    {
        cout << "Hello" << endl;
    }
    else
    {
        cout << "Bye" << endl;
    }

    for (int i = 0; i < r[0].getNumDrink(); i++)
    {
        Drink *d = r[0].getDrink(i);
        if (d->getPrice() > 50)
        {
            cout << *d;
        }
    }

    double total = 0;
    for (int i = 0; i < r[0].getNumDrink(); i++)
    {
        Drink *d = r[0].getDrink(i);
        total += d->getPrice();
    }
    for (int i = 0; i < r[1].getNumDrink(); i++)
    {
        Drink *d = r[1].getDrink(i);
        total += d->getPrice();
    }
    cout << "ราคารวม r1 r2 = " << total << endl;

    return 0;
}