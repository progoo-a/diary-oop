#include <iostream>

class Swimmable {
    public:
    virtual void swim() = 0;
};

class Flyable {
    public:
    virtual void fly() = 0;
};

class SuperBird : public Swimmable, public Flyable {
};

class Cormoran : public SuperBird {
    public:
    void swim() {
        std::cout << "I am swimming" << std::endl;
    }
    void fly() {
        std::cout << "I am flying" << std::endl;
    }
}

int main() {
    std::vector<SuperBird*> sb;
    for (auto *s : sb) {
        sb->fly();
        sb->swim();
    }
}
