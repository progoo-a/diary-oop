#include <iostream>

class Human {
    int age;
    std::string name;
public:
    Human(std::string name, int age = 0) {
        this->age = age;
        this->name = name;
    }
};

class Relationship {
    Human &a, &b;
  public:
    Relationship(Human &a, Human &b) : a(a), b(b) {}
};

int main() {
    auto bob = Human("Bob", 42);
    auto alice = Human("Alice", 30);

    Relationship r = Relationship(bob, alice);
}