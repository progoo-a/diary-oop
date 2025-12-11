#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// Exemple chat et souris avec polymorphisme dynamique.
class Animal {
public:
    explicit Animal(std::string name) : name_(std::move(name)) {}
    virtual ~Animal() = default;

    virtual void speak() const = 0;

protected:
    const std::string &name() const { return name_; }

private:
    std::string name_;
};

class Cat : public Animal {
public:
    using Animal::Animal;

    void speak() const override { std::cout << "🐱 " << name() << '\n'; }
};

class Mouse : public Animal {
public:
    using Animal::Animal;

    void speak() const override { std::cout << "🐭 " << name() << '\n'; }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(std::make_unique<Cat>("Minou"));
    animals.emplace_back(std::make_unique<Mouse>("Speedy"));
    animals.emplace_back(std::make_unique<Cat>("Felix"));

    for (const auto &animal : animals) {
        animal->speak(); // Dispatch dynamique via pointeur de base.
    }
}
