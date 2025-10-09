#include <iostream>
#include <vector>

// Classe de Base
class Animal {
    protected:
    std::string avatar = "🐾";
    public:
    Animal(std::string avatar = "🐾") : avatar(avatar) {}
    void eat() { std::cout << avatar << " eats\n"; }
    void sleep() { std::cout << avatar << " sleeps\n"; }
    virtual void speak() { std::cout << avatar << " speaks\n"; }
};

// Classe dérivée
class Cat : public Animal {
    public:
    Cat() : Animal("🐱") {}

    // Surcharge de méthode
    void speak() override { std::cout << avatar << " Miaoouuuu\n"; }
};

class Dog : public Animal {
    public:
    Dog() : Animal("🐶") {}

    // Surcharge de méthode
    void speak() override { std::cout << avatar << " Wouufffff\n"; }
};

class Cage {};

class Zoo {
    // Aggrégation d'animaux
    std::vector<Animal*> animals;

    // Composition de cages;
    std::vector<Cage> cages;
  public:
    // Les cages appartiennent au zoo, et seront détruites
    // si le zoo est détruit.
    Zoo() { cages.push_back(Cage()); }

    // Les animaux n'appartiennent pas au zoo, si ce dernier est
    // détruit, seul les pointeurs vers ces animaux seront détruits
    void add_animal(Animal *a) { animals.push_back(a); }

    void pet_all_animals() {
        for (auto *animal : animals) {
            animal->speak();
        }
    }
};

int main() {
    Animal *p = new Cat();
    Animal *q = new Dog();

    {
       Zoo z; 
       z.add_animal(p);
       z.add_animal(q);
       z.pet_all_animals();
    }
}