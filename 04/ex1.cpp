#include <iostream>
#include <string>
#include <queue>
#include <random>
class Cat {
public:
    std::string name;
    Cat() { std::cout << "Cat created." << std::endl; }
    Cat(int age, std::string name="Unnamed") : age{age}, name{name} {
        if (name == "") {
            std::cout << "A "<< age << " years old cat with no name was found in the wild." << std::endl;        
        } else {
            std::cout << "A "<< age << " years old cat named " << name << " was found in the wild." << std::endl;
        }
    }
    Cat(const Cat &other) {
        std::cout << "Cat " << other.name << " is cloned" << std::endl;
        name = other.name;
        age = other.age;
    }
    void speak() { std::cout << name << " says Meow!" << std::endl; }
    ~Cat() {
        std::cout << "Sadly, a " << age << "years old cat named " << name << " was killed by a computer" << std::endl;
    }
    private: 
        int age;        
};

Cat cat_factory() {
    std::string names[] = {"Felix", "Bobby", "Anna"};
    return Cat{rand() % 10, names[rand() % 3]};
}

int main() {
    // On the Stack
    Cat garfield(32, "Garfield");
    Cat felix{};
    Cat hobbes = garfield; 
    hobbes.name = "Hobbes";
    Cat foo(3);
    Cat blob(foo);
    Cat looping;
    Cat licorne{22, "Roger"};
    Cat bar{5};
    garfield.speak();
    
    // On the heap
    Cat *var = new Cat{4, "Vary"};
    var->speak();
    delete var;
    //var->speak(); // Segmentation fault

    std::queue<Cat*> mcdo_queue; 
    std::cout << "------\n";
    mcdo_queue.push(&garfield);
    mcdo_queue.push(var);
}