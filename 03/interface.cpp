#include <iostream> 

class CarInterface {
    public:
    int wheels;
    int doors;
    virtual ~CarInterface() = 0;
    virtual void honk() = 0;
    virtual void drive() = 0;
    virtual void stop() = 0;
};


class Driver {
    public:
    void drive(CarInterface &car) {
        car.drive();
    }
};


class FiatPanda : public CarInterface {
    public:
    FiatPanda() {
        wheels = 4;
        doors = 4;
    }
    void honk() {
        std::cout << "Grrrrrgeeggr!" << std::endl;
    }
    void drive() {
        std::cout << "Driving!" << std::endl;
    }
    void stop() {
        std::cout << "Stopping!" << std::endl;
    }
};

class Lambo : public CarInterface {
    public:
    Lambo() {
        wheels = 4;
        doors = 2;
    }
    void honk() {
        std::cout << "Beeeeeeeeep!" << std::endl;
    }
    void drive() {
        std::cout << "Driving!" << std::endl;
    }
    void stop() {
        std::cout << "Stopping!" << std::endl;
    }
};

int main() {
    Driver d;
    FiatPanda u; 
    Lambo l;
    d.drive(u);
    d.drive(l);
}