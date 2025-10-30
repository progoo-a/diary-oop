#include <iostream>
#include <vector>
using namespace std;

class Animal
{
public:
    virtual void eat() = 0;
    virtual void speak() = 0;
    virtual int age() = 0;

    virtual ~Animal() = default;
};

class Cat : public Animal
{
    int _age = 3;

public:
    void eat() override { cout << "Cat eats\n"; }
    void speak() override { cout << "Cat speaks\n"; }
    int age() override { return _age; }
};

class Dog : public Animal
{
    int _age = 3;

public:
    void eat() override { cout << "Dog eats\n"; }
    void speak() override { cout << "Dog speaks\n"; }
    int age() override { return _age; }
};

int main()
{
    vector<Animal *> animals;
    const int n = 10;
    for (int i = 0; i < n; ++i)
    {
        Animal *animal;
        if (rand() % 2)
            animal = new Cat();
        else
            animal = new Dog();
        animals.push_back(animal);
    }

    for (auto animal : animals)
        animal->speak();
}