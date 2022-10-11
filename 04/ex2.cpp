#include <iostream>
#include <string> 

class Animal {
    public:
    std::string name;
    void eat() {
        std::cout << name << " is eating" << std::endl;
    }
};

class Mouse : public Animal {
    public:
    Mouse(std::string name) {
        this->name = name;
    }
};

class Cat : public Animal {
    public:
    Cat(std::string name) { this->name = name; }
    void eat(Mouse &m) {
        std::cout << name << " eats " << m.name << std::endl;
    }
};

int main() {
    Mouse m{"Jerry"};
    Cat c{"Tom"};
    c.eat(m);
    //c.eat();
    m.eat();
}