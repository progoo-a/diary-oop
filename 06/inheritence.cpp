#include <iostream>
#include <string>

using namespace std;

// Quant toutes les méthodes sont virtuelle pures : c'est une interface
class Animal {
    string name;
    int age;
    public:
    Animal(string name, int age) : name{name}, age{age} {}
    virtual void eat() = 0;
};

class Cat : public Animal {
    public:
    Cat(string name, int age) : Animal{name, age} {}
    void eat() override {}
};

int main() {
    Cat felix{"felix", 7}; // Protege contre le narrowing
    felix.eat();

    //Animal animal; // Interdit parce que Animal est une classe abstraite
}
