#include <iostream>
#include <string>

struct Foo {
    std::string name;

    Foo(std::string name) : name(name) { // Constructeur par défaut
        std::cout << "Object " << name << " created!" << std::endl;    
    }

    ~Foo() { // Destructeur
        std::cout << "Object " << name << " destroyed!" << std::endl;    
    }
};

int main() {
    {
        Foo foo("foo");
    }
    Foo bar("bar");
}