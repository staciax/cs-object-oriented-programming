#include <iostream>

using namespace std;

class Food
{
    static int foodCount;
    double price; // ราคา

public:
    Food()
    {
        price = 40;
    }
    Food(double price)
    {
        if (price >= 0)
        {
            this->price = price;
        }
    }
    ~Food() {}

    // set
    void setPrice(double price)
    {
        if (price >= 0)
        {
            this->price = price;
        }
    }

    // get
    double getPrice()
    {
        return this->price;
    }

    // show
    virtual void show() = 0;

    // count
    static int count()
    {
        return foodCount;
    }
};

int Food::foodCount;

class KaoNiew : public Food
{
    int color; // สี 1.ขาว 2.ดํา
public:
    KaoNiew() : Food(5)
    {
        this->color = 1;
    }
    KaoNiew(int color, double price) : Food(price)
    {
        if (color >= 1 && color <= 2)
        {
            this->color = color;
        }
    }

    // set
    void setColor(int color)
    {
        if (color >= 1 && color <= 2)
        {
            this->color = color;
        }
    }

    // get
    int getColor()
    {
        return this->color;
    }

    // show
    void show()
    {
        cout << "price: " << this->getPrice() << endl;
        cout << "color: " << this->color << endl;
    }
};

class KaiYang : public Food
{
    int type; // 1.ไก่ย่างนมสด 2.ไก่ย่างขมิ้น
public:
    KaiYang() : Food(80)
    {
        this->type = 1;
    }
    KaiYang(double price, int type) : Food(price)
    {
        if (type >= 1 && type <= 2)
        {
            this->type = type;
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
        cout << "price: " << this->getPrice() << endl;
        cout << "type: " << this->type << endl;
    }
};

class SomTam : public Food
{
    int chilli; // ใส่พริกกี่เม็ด
public:
    SomTam() : Food(50)
    {
        this->chilli = 3;
    }
    SomTam(double price, int chilli) : Food(price)
    {
        if (chilli >= 0)
        {
            this->chilli = chilli;
        }
        else
        {
            this->chilli = 3;
        }
    }
    // set
    void setChilli(int chilli)
    {
        if (chilli >= 0)
        {
            this->chilli = chilli;
        }
        else
        {
            this->chilli = 3;
        }
    }
    // get
    int getChilli()
    {
        return this->chilli;
    }

    // show
    void show()
    {
        cout << "price: " << this->getPrice() << endl;
        cout << "chilli: " << this->chilli << endl;
    }
};

class TumPu : public SomTam
{
    bool plara; // true: ใส่ปลาร้า false: ไม่ใส่ปลาร้า
public:
    TumPu() : SomTam(55, 4)
    {
        this->plara = false;
    }
    TumPu(double price, int chilli, bool plara) : SomTam(price, chilli)
    {
        this->plara = plara;
    }
    // set
    void setPlara(bool plara)
    {
        this->plara = plara;
    }
    // get
    bool getPlara()
    {
        return this->plara;
    }
    // show
    void show()
    {
        SomTam::show();
        cout << "plara: " << this->plara << endl;
    }
};

class TumThai : public SomTam
{
    bool peanut; // true: ใส่ถั่วลิสง false: ไม่ใส่ถั่วลิสง
public:
    TumThai() : SomTam(55, 4)
    {
        this->peanut = false;
    }
    TumThai(double price, int chilli, bool peanut) : SomTam(price, chilli)
    {
        this->peanut = peanut;
    }
    // set
    void setPeanut(bool peanut)
    {
        this->peanut = peanut;
    }

    // get
    bool getPeanut()
    {
        return this->peanut;
    }

    // show
    void show()
    {
        SomTam::show();
        cout << "peanut: " << this->peanut << endl;
    }
};

class FoodItem
{
    Food *food; // พอยเตอร์ที่ชี้ไปยัง Food (หมายถึงอาหารที่สั่ง)
    int amount; // จํานวนจาน

public:
    FoodItem()
    {
        this->food = 0;
        this->amount = 0;
    }
    FoodItem(Food *food, int amount)
    {
        if (amount >= 0)
        {
            this->amount = amount;
            this->food = food;
        }
        else
        {
            this->food = 0;
            this->amount = 0;
        }
    }

    // set
    void setFood(Food *food)
    {
        this->food = food;
    }
    void setAmount(int amount)
    {
        if (amount >= 0)
        {
            this->amount = amount;
        }
        else
        {
            this->amount = 0;
        }
    }

    // get
    Food *getFood()
    {
        return this->food;
    }
    int getAmount()
    {
        return this->amount;
    }
};

class Order
{
    static int current;
    FoodItem **items; // อาร์เรย์ขนาด num เก็บพอยเตอร์ที่ชี้ไปยัง FoodItem
    int num;          // จำนวนสมาชิกในอาร์เรย์ items
    int queueNumber;  // หมายเลขคิว
public:
    Order()
    {
        this->items = 0;
        this->num = 0;
        this->queueNumber = ++current;
    }
    Order(int num)
    {
        if (num >= 0)
        {
            this->num = num;
            this->queueNumber = ++current;
            this->items = new FoodItem *[num];
        }
        else
        {
            this->items = 0;
            this->num = 0;
            this->queueNumber = ++current;
        }
    }
    ~Order()
    {
        delete[] this->items;
    }

    // set
    void setItem(int i, FoodItem *f)
    {
        this->items[i] = f;
    }
    void setNum(int num)
    {
        if (num < 0)
        {
            num = 0;
        }
        if (this->num == num)
        {
            return;
        }
        delete[] this->items;
        this->items = new FoodItem *[num];
    }

    // get
    FoodItem *getItems(int i)
    {
        return this->items[i];
    }
    int getNum()
    {
        return this->num;
    }
    int getQueueNumber()
    {
        return this->queueNumber;
    }

    // show

    void show()
    {
        cout << "queueNumber: " << this->queueNumber << endl;
        cout << "num: " << this->num << endl;
        for (int i = 0; i < this->num; i++)
        {
            this->items[i]->getFood()->show();
        }
    }

    // operator

    bool operator>=(Order &b)
    {
        return this->totalPrice() > b.totalPrice();
    }

    double operator+(Order &b)
    {
        return this->totalPrice() + b.totalPrice();
    }

    friend double operator+(double a, Order &b)
    {
        return a + b.totalPrice();
    }

    void operator()()
    {
        for (int i = 0; i < this->num; i++)
        {
            this->items[i]->getFood()->show();
        }
    }
    void operator()(int i)
    {
        this->items[i]->getFood()->show();
    }

    double operator[](int i)
    {
        FoodItem *item = this->items[i];
        return item->getFood()->getPrice() * item->getAmount();
    }

    // req
    double totalPrice()
    {
        double total;
        for (int i = 0; i < this->num; i++)
        {

            FoodItem *item = this->items[i];
            total += item->getFood()->getPrice() * item->getAmount();
        }
        return total;
    }
};

int Order::current;

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
    KaoNiew kaoniewDam(1, 5);
    KaoNiew kaoniewKao(2, 5);

    KaiYang kaiyangNomsod(160, 1);
    KaiYang kaiyangKamin(180, 2);

    TumPu somtumPu(60, 3, false);
    TumPu somtumPuPlara(70, 4, true);
    TumThai somtumThai(60, 4, true);
    TumThai somtumThaiNoPeanut(60, 55, false);

    Order order1(3);
    order1.setItem(0, new FoodItem(&somtumPu, 2));
    order1.setItem(1, new FoodItem(&kaoniewDam, 3));
    order1.setItem(2, new FoodItem(&kaiyangNomsod, 1));
    cout << order1 << endl;

    Order order2(4);
    order2.setItem(0, new FoodItem(&somtumThai, 1));
    order2.setItem(1, new FoodItem(&kaoniewKao, 3));
    order2.setItem(2, new FoodItem(&kaiyangNomsod, 2));
    order2.setItem(3, new FoodItem(&kaiyangKamin, 1));
    cout << order2 << endl;

    Order order3(1);
    order3.setItem(0, new FoodItem(&somtumThaiNoPeanut, 1));

    order3.setNum(2);
    order3.setItem(0, new FoodItem(&somtumThaiNoPeanut, 1));
    order3.setItem(1, new FoodItem(&somtumPuPlara, 1));
    cout << order3 << endl;

    if (order1 >= order2 && order1 >= order3)
    {
        cout << "order1 >= order2 && order1 >= order3" << endl;
    }
    else if (order2 >= order1 && order2 >= order3)
    {
        cout << "order2 >= order1 && order2 >= order3" << endl;
    }
    else
    {
        cout << "order3 >= order1 && order3 >= order2" << endl;
    }

    order1();
    order1(0);

    for (int i = 0; i < order2.getNum(); i++)
    {
        cout << "order2[" << i << "] ราคารวม = " << order2[i] << endl;
    }

    for (int i = 0; i < order2.getNum(); i++)
    {
        cout << "order2[" << i << "] ราคารวม = " << order2.getItems(i)->getFood()->getPrice() * order2.getItems(i)->getAmount() << endl;
    }

    cout << "order1+order2+order3 = " << order1 + order2 + order3 << endl;
    cout << "จำนวนจาน order1 order2 order3 = " << order1.getNum() + order2.getNum() + order3.getNum() << endl;

    return 0;
}