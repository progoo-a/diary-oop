#include <iostream>
#include <vector>

// Classe de Base: Interface (contrat)
class Animal {
    protected:
    std::string avatar = "🐾";
    public:
    Animal(std::string avatar = "🐾") : avatar(avatar) {}
    // Méthode virtuelle pure (=0)
    virtual void eat() = 0;
    virtual void sleep() = 0;
    virtual void speak() = 0;
};

// Classe dérivée: On réalise un animal
class Cat : public Animal {
  public:
    Cat() : Animal("🐱") {}

    // Surcharge de méthode
    void speak() override { std::cout << avatar << " Miaoouuuu\n"; }
    void eat() override { std::cout << avatar << " Eat\n"; }
    void sleep() override { std::cout << avatar << " Zzzz\n"; }
};

class Dog : public Animal {
    public:
    Dog() : Animal("🐶") {}

    // Surcharge de méthode
    void speak() override { std::cout << avatar << " Wouufffff\n"; }
    void eat() override { std::cout << avatar << " Eat\n"; }
    void sleep() override { std::cout << avatar << " Zzzz\n"; }    
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

    // Animal animal; pas autorisé

    {
       Zoo z; 
       z.add_animal(p);
       z.add_animal(q);
       z.pet_all_animals();
    }
}