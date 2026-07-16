#include <iostream>
#include <string>

using namespace std;

class Fabric
{
    int color; // สี เช่น 1.ขาว 2.เขียว 3.น้ำตาล 4.เทา
public:
    Fabric()
    {
        this->color = 1;
    }
    Fabric(int color)
    {
        if (color >= 1 && color <= 4)
        {
            this->color = color;
        }
        else
        {
            this->color = 1;
        }
    }

    virtual ~Fabric() {}

    // set
    // void setColor(int color)
    // {
    //     if (color >= 1 && color <= 4)
    //     {
    //         this->color = color;
    //     }
    //     else
    //     {
    //         this->color = 1;
    //     }
    // }

    // get
    int getColor()
    {
        return this->color;
    }

    // show
    virtual void show() = 0;
};

class Cotton : public Fabric
{
    int number; // เบอร์เส้นด้าย เช่น 20, 32, 40
public:
    Cotton() : Fabric(3)
    {
        this->number = 20;
    }
    Cotton(int color, int number) : Fabric(color)
    {
        this->number = number;
    }

    // set
    // void setNumber(int number)
    // {
    //     this->number = number;
    // }

    // get
    int getNumber()
    {
        return this->number;
    }

    // show
    void show()
    {
        cout << "color: " << this->getColor() << endl;
        cout << "number: " << this->number << endl;
    }
};

class Linen : public Fabric
{
    int grade; // คุณภาพ เช่น 1.ดีมาก 2.ปานกลาง 3.พอใช้
public:
    Linen() : Fabric(4)
    {
        this->grade = 2;
    }
    Linen(int color, int grade) : Fabric(color)
    {
        if (grade >= 1 && grade <= 3)
        {
            this->grade = grade;
        }
        else
        {
            this->grade = 3;
        }
    }

    // set
    // void setGrade(int grade)
    // {
    //     if (grade >= 1 && grade <= 3)
    //     {
    //         this->grade = grade;
    //     }
    //     else
    //     {
    //         this->grade = 3;
    //     }
    // }

    // get
    int getGrade()
    {
        return this->grade;
    }
    // show
    void show()
    {
        cout << "color: " << this->getColor() << endl;
        cout << "grade: " << this->grade << endl;
    }
};

class Clothes
{
    static int clothesCount;
    double price;   // ราคา
    int size;       // ขนาด เช่น 1.ไซซ์ S 2.ไซซ์ M 3.ไซซ์ L
    Fabric *fabric; // พอยเตอร์ที่ชี้ไปยัง Fabric
public:
    Clothes()
    {
        clothesCount++;
        this->price = 999;
        this->size = 3;
        this->fabric = 0;
    }
    Clothes(double price, int size, Fabric *fabric)
    {
        clothesCount++;
        this->price = price;
        this->size = size; // TODO: check
        this->fabric = fabric;
    }

    virtual ~Clothes()
    {
        --clothesCount;
    }

    // set
    void setFabric(Fabric *fabric)
    {
        this->fabric = fabric;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void setSize(int size)
    {
        if (size >= 1 && size <= 3)
        {
            this->size = size;
        }
        else
        {
            this->size = 3; // default
        }
    }

    // get
    double getPrice()
    {
        return this->price;
    }
    int getSize()
    {
        return this->size;
    }
    Fabric *getFabric()
    {
        return this->fabric;
    }

    // show
    virtual void show() = 0;

    // static
    static int count()
    {
        return clothesCount;
    }
};

int Clothes::clothesCount;

class Tops : public Clothes
{
    int type; // เช่น 1.เสื้อโปโล 2.เสื้อเชิ้ต 3.เสื้อยืด
public:
    Tops() : Clothes(800, 1, 0)
    {
        this->type = 1;
    }
    Tops(double price, int size, Fabric *fabric, int type) : Clothes(price, size, fabric)
    {
        this->setType(type);
    }

    // set
    void setType(int type)
    {
        if (type >= 1 && type <= 3)
        {
            this->type = type;
        }
        else
        {
            this->type = 1; // default
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
        this->getFabric()->show();
        cout << "price: " << this->getPrice() << endl;
        cout << "size: " << this->getSize() << endl;
        cout << "type: " << this->type << endl;
    }
};

class Pants : public Clothes
{
    int length; // เช่น 1.ขาสั้น 2.ขาสามส่วน 3.ขาสี่ส่วน 4.ขายาว
public:
    Pants()
    {
        this->length = 4;
    }
    Pants(double price, int size, Fabric *fabric, int length) : Clothes(price, size, fabric)
    {
        this->setLength(length);
    }

    // set
    void setLength(int length)
    {
        if (length >= 1 && length <= 4)
        {
            this->length = length;
        }
        else
        {
            this->length = 4; // default
        }
    }

    // get
    int getLength()
    {
        return this->length;
    }

    // show
    void show()
    {
        this->getFabric()->show();
        cout << "price: " << this->getPrice() << endl;
        cout << "size: " << this->getSize() << endl;
        cout << "length: " << this->length << endl;
    }
};

class Size
{
    int width;  // ความกว้าง
    int length; // ความยาว
    int height; // ความสูง

    int validate(int value)
    {
        if (value <= 0)
        {
            return 1;
        }
        return value;
    }

public:
    Size()
    {
        this->width = 55;
        this->length = 100;
        this->height = 180;
    }
    Size(int width, int length, int height)
    {
        this->setWidth(width);
        this->setLength(length);
        this->setHeight(height);
    }

    // set
    void setWidth(int width)
    {
        this->width = this->validate(width);
    }
    void setLength(int length)
    {
        this->length = this->validate(length);
    }
    void setHeight(int height)
    {
        this->height = this->validate(height);
    }

    // get
    int getWidth()
    {
        return this->width;
    }
    int getLength()
    {
        return this->length;
    }
    int getHeight()
    {
        return this->height;
    }

    // show
    void show()
    {
        cout << "width: " << this->width << endl;
        cout << "length: " << this->length << endl;
        cout << "height: " << this->height << endl;
    }
};

class Wardrobe
{
    Size size;         // ขนาดของตู้เสื้อผ้า
    int numDoor;       // จำนวนประตูของตู้เสื้อผ้า
    Clothes **clothes; // อาร์เรย์ขนาด num เก็บพอยเตอร์ที่ชี้ไปยัง Clothes
    int num;           // ขนาดของอาร์เรย์clothes
public:
    Wardrobe()
    {
        this->size.setWidth(60);
        this->size.setLength(80);
        // this->size.setHeight(180); // default
        this->numDoor = 2;
        this->clothes = 0;
        this->num = 0;
    }
    Wardrobe(Size size, int numDoor, int num)
    {
        this->size = size;
        this->numDoor = numDoor;
        if (num <= 0)
        {
            num = 1;
        }
        this->num = num;
        this->clothes = new Clothes *[num];
    }
    ~Wardrobe()
    {
        delete[] this->clothes;
    }

    // copy constuctor
    Wardrobe(Wardrobe &other)
    {
        this->size = other.size;
        this->num = other.numDoor;
        this->num = other.num;
        this->clothes = new Clothes *[other.num];
        for (int i = 0; i < other.num; i++)
        {
            this->clothes[i] = other.clothes[i];
        }
    }

    // set
    void setSize(Size size)
    {
        this->size = size;
    }
    void setNumDoor(int numDoor)
    {
        this->numDoor = numDoor;
    }
    void setNum(int num)
    {
        if (num <= 0)
        {
            num = 1;
        }
        if (num == this->num)
        {
            return;
        }
        delete[] this->clothes;
        this->num = num;
        this->clothes = new Clothes *[num];
    }
    void setClothes(int index, Clothes *clothes)
    {
        this->clothes[index] = clothes;
    }

    // get
    Size getSize()
    {
        return this->size;
    }
    int getNumDoor()
    {
        return this->numDoor;
    }
    int getNum()
    {
        return this->num;
    }
    Clothes *getClothes(int index)
    {
        return this->clothes[index];
    }
    int getWhite()
    {
        int total = 0;
        for (int i = 0; i < this->num; i++)
        {
            if (this->clothes[i]->getFabric()->getColor() == 1)
            {
                total++;
            }
        }
        return total;
    }

    // show
    void show()
    {
        this->size.show();
        cout << "numDoor: " << this->numDoor << endl;
        cout << "num: " << this->num << endl;
        for (int i = 0; i < this->num; i++)
        {
            this->clothes[i]->show();
        }
    }

    // operator
    double operator()()
    {
        double total = 0;
        for (int i = 0; i < this->num; i++)
        {
            total += this->clothes[i]->getPrice();
        }
        return total;
    }
};

// io

ostream &operator<<(ostream &os, Fabric &fabric)
{
    fabric.show();
    return os;
}

ostream &operator<<(ostream &os, Clothes &clothes)
{
    clothes.show();
    return os;
}

ostream &operator<<(ostream &os, Size &size)
{
    size.show();
    return os;
}

ostream &operator<<(ostream &os, Wardrobe &wardrobe)
{
    wardrobe.show();
    return os;
}

int main()
{
    Cotton cotton1(1, 20);
    Cotton cotton2(3, 32);
    Linen linen1(4, 1);
    Linen linen2(1, 1);

    Fabric *a[4];
    a[0] = &cotton1;
    a[1] = &cotton2;
    a[2] = &linen1;
    a[3] = &linen2;

    for (int i = 0; i < 4; i++)
    {
        a[i]->show();
    }

    Clothes *m[8];
    m[0] = new Tops(400, 1, a[0], 1);
    m[1] = new Tops(400, 1, a[0], 1);
    m[2] = new Tops(400, 1, a[0], 1);
    m[3] = new Tops(400, 1, a[0], 1);
    m[4] = new Tops(400, 1, a[0], 1);
    m[5] = new Tops(400, 1, a[0], 1);
    m[6] = new Tops(400, 1, a[0], 1);
    m[7] = new Tops(400, 1, a[0], 1);

    for (int i = 0; i < 8; i++)
    {
        cout << *m[i];
    }

    Wardrobe w1(Size(60, 200, 200), 3, 4);
    w1.setClothes(0, m[0]);
    w1.setClothes(1, m[1]);
    w1.setClothes(2, m[3]);
    w1.setClothes(3, m[5]);
    cout << w1;

    Wardrobe w2(Size(60, 100, 190), 2, 4);
    w2.setClothes(0, m[2]);
    w2.setClothes(1, m[4]);
    w2.setClothes(2, m[6]);
    w2.setClothes(3, m[7]);

    if (w1() > w2())
    {
        cout << "ราคา w1 มากกว่า w2 = " << w1() << endl;
    }
    else
    {
        cout << "ราคา w2 มากกว่า w1 = " << w2() << endl;
    }

    cout << "w1 มีเสื้อขาวอยู่จำนวน " << w1.getWhite() << endl;
    cout << "w2 มีเสื้อขาวอยู่จำนวน " << w2.getWhite() << endl;

    Cotton cotton3(3, 32);
    Cotton cotton4(3, 32);
    Linen linen3(1, 1);
    cout << cotton3;
    cout << cotton4;
    cout << linen3;

    Tops s1;
    Tops s2;
    Pants s3;

    s1.setFabric(&cotton3);
    s1.setSize(1);
    s1.setPrice(1300);

    s2.setFabric(&cotton4);
    s2.setSize(1);
    s2.setPrice(1200);

    s3.setFabric(&linen3);
    s3.setLength(1);
    s3.setPrice(1300);

    Wardrobe w3(Size(70, 210, 200), 2, 3);
    w3.setClothes(0, &s1);
    w3.setClothes(2, &s2);
    w3.setClothes(1, &s3);
    w3.show();

    Wardrobe w4 = w3; // TODO: how to clear w3
    w4.setNum(2);
    w4.setClothes(0, &s1);
    w4.setClothes(1, &s3);
    w4.show();

    w1.setNum(4);
    w1.setClothes(0, m[0]);
    w1.setClothes(1, m[1]);
    w1.setClothes(2, m[3]);
    w1.setClothes(3, m[5]);
    w1.setClothes(4, &s2);
    w1.show();

    int w1sizeS = 0;
    for (int i = 0; i < w1.getNum(); i++)
    {
        if (w1.getClothes(i)->getSize() == 1)
        {
            w1sizeS++;
        }
    }
    cout << "จำนวนเสื้อขนาด S ของ w1 = " << w1sizeS << endl;

    for (int i = 0; i < w2.getNum(); i++)
    {
        if (w2.getClothes(i)->getSize() == 1)
        {
            w2.getClothes(i)->show();
        }
    }

    for (int i = 0; i < 8; i++)
    {
        delete m[i];
    }

    return 0;
}
