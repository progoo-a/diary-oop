#include <iostream>
#include <string> 
#include <random> 

class Animal {
    public:
    std::string name;
    Animal(std::string name) : name{name} {}
    virtual void eat() {
        std::cout << name << " is eating" << std::endl;
    }
    virtual void speak() { std::cout << "Animal " << name << " speaks!" << std::endl; }
};

class Mouse : public Animal {
    public:
    Mouse(std::string name): Animal{name} {}
    void speak() override { std::cout << "🐭 " << name << " speaks!" << std::endl; }
};

class Cat : public Animal {
    public:
    Cat(std::string name) : Animal{name} {}
    void eat(Mouse &m) {
        std::cout << name << " eats " << m.name << std::endl;
    }
    void speak() { std::cout << "🐱 " << name << " speaks!" << std::endl; }
};

class Ghost : public Animal {
    public: 
    Ghost(std::string name) : Animal{name} {}
};

int main() {

    std::vector<Animal *> zoo;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        if (rand() % 2) 
            zoo.push_back(new Cat{"Tom"});
        else 
            zoo.push_back(new Mouse{"Jerry"});
    }

    for (auto *animal: zoo)
        animal->speak();
}