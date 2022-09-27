#include <string>
#include <iostream> 

struct Field {
    int lenght;
    int width; 
    int nanimals;

    void add_animal() {
        nanimals++;
    }
    void remove_animal() {
        nanimals--;
    }
};

struct Animal {
    std::string name;
    float height;
    float weight;
    Field &field;

    Animal(Field &field) : field(field) {
        std::cout << "New empty animal\n";
        field.add_animal();
    }

    Animal(Field &field, std::string name, float height=42, float weight=23) : 
        field(field), name(name), height(height), weight(weight) {
        std::cout << "New Animal\n";
        field.add_animal();
        // this->name = name; 
        // this->height = height; 
        // this->weight = weight;
    }

    void speak() {
        std::cout << "Hey I am " << name << std::endl;
    }

    ~Animal() {
        std::cout << "An animal died";
        field.remove_animal();
    }
};

int main() {
    Field field;
    Animal animal(field);
    Animal paul(field, "Paul", 42, 23);

    Animal foo(animal);
    //foo = paul; Opérateur d'assignation
}