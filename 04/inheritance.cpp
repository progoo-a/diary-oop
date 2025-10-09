#include <iostream>

class Animal {
    protected:
    std::string avatar = "🐾";
    public:
    Animal(std::string avatar = "🐾") : avatar(avatar) {}
    void eat() { std::cout << avatar << " eats\n"; }
    void sleep() { std::cout << avatar << " sleeps\n"; }
    void speak() { std::cout << avatar << " speaks\n"; }
};

class Cat : public Animal {
    public:
    Cat() : Animal("🐱") {}
    void speak() { std::cout << avatar << " Miaoouuuu\n"; }
};

int main() {
    Animal x;
    x.speak();

    Cat cat; 
    cat.speak();
}