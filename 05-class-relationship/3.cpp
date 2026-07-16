#include <iostream>

using namespace std;

class Engine
{
private:
    string brand;
    string model;

public:
    Engine()
    {
        this->init("none", "none");
    }
    Engine(string brand, string model)
    {
        this->init(brand, model);
    }
    ~Engine()
    {
        cout << "delete: Engine" << endl;
    }

    // set
    void init(string brand, string model)
    {
        this->brand = brand;
        this->model = model;
    }
    void setBrand(string brand)
    {
        this->brand = brand;
    }
    void setModel(string model)
    {
        this->model = model;
    }

    // get
    string getBrand()
    {
        return this->brand;
    }
    string getModel()
    {
        return this->brand;
    }

    // show
    void show()
    {
        cout << "Engine("
             << "brand=" << this->brand << ", "
             << "model=" << this->model << ")" << endl;
    }
};

class Body
{
private:
    string color;
    int seatingCapacity;

public:
    Body()
    {
        this->init("white", 4);
    }
    Body(string color, int seatingCapacity)
    {
        this->init(color, seatingCapacity);
    }
    ~Body()
    {
        cout << "delete: Body" << endl;
    }

    // set
    void init(string color, int seatingCapacity)
    {
        this->color = color;
        this->seatingCapacity = seatingCapacity;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    void setSeatingCapacity(int seatingCapacity)
    {
        this->seatingCapacity = seatingCapacity;
    }

    // get
    string getColor()
    {
        return this->color;
    }
    int getSeatingCapacity()
    {
        return this->seatingCapacity;
    }

    // show
    void show()
    {
        cout << "Body("
             << "color=" << this->color << ", "
             << "seatingCapacity=" << this->seatingCapacity << ")" << endl;
    }
};

class Wheel
{
private:
    int size;
    string type;

public:
    Wheel()
    {
        this->init(0, "0");
    }
    Wheel(int size, string type)
    {
        this->init(size, type);
    }
    ~Wheel()
    {
        cout << "delete: Wheel" << endl;
    }

    // set
    void init(int size, string type)
    {
        this->size = size;
        this->type = type;
    }
    void setSize(int size)
    {
        this->size = size;
    }
    void setType(string type)
    {
        this->type = type;
    }

    // get
    int getSize()
    {
        return this->size;
    }
    string getType()
    {
        return this->type;
    }

    // show
    void show()
    {
        cout << "Wheel("
             << "size=" << this->size << ", "
             << "type=" << this->type << ")" << endl;
    }
};

class Car
{
private:
    string name;
    Engine engine;
    Body body;
    Wheel wheel;

public:
    Car()
    {
        this->name = "none";
    }
    Car(string name, Engine engine, Body body, Wheel wheel)
    {
        this->init(name, engine, body, wheel);
    }
    ~Car()
    {
        cout << "delete: Cara" << endl;
    }

    // set
    void init(string name, Engine engine, Body body, Wheel wheel)
    {
        this->name = name;
        this->engine = engine;
        this->body = body;
        this->wheel = wheel;
    }

    void setEngine(Engine engine)
    {
        this->engine = engine;
    }
    void setBody(Body body)
    {
        this->body = body;
    }
    void setWheel(Wheel wheel)
    {
        this->wheel = wheel;
    }

    // get
    Engine getEngine()
    {
        return this->engine;
    }
    Body getBody()
    {
        return this->body;
    }
    Wheel getWheel()
    {
        return this->wheel;
    }

    // show
    void show()
    {
        cout << "Car(" << endl;
        cout << "  name=" << this->name << endl;
        cout << "  ";
        this->engine.show();
        cout << "  ";
        this->body.show();
        cout << "  ";
        this->wheel.show();
        cout << ")" << endl;
    }

    void drive()
    {
        cout << "driving..." << endl;
    }
    void start()
    {
        cout << "starting..." << endl;
    }
    void dispose()
    {
        cout << "disposing..." << endl;
    }
};

int main()
{
    Engine engine("Toyota", "V8");
    Body body("Black", 4);
    Wheel wheel(18, "Alloy");

    Car car("lightning mcqueen", engine, body, wheel);
    car.show();
    car.start();
    car.drive();
    car.dispose();

    return 0;
}