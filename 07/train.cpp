#include <iostream>
#include <vector>
using namespace std;
class Person {
    std::string name;
    public:
    Person(std::string name) : name{name} {}
    virtual void speak() { cout << "I am " << name << endl; }

    std::string get_name() { return name; }
    void set_name(std::string name) { this->name = name; }
};

class Vehicle;

class Voyager: public Person {
    Vehicle *vehicle;
    int ticket;
    public:
    //using Person::Person;
    Voyager(std::string name) : ticket{0}, Person{name} {}
    void accept(Vehicle &vehicle) {
        this->vehicle = &vehicle;
    }
};

class Vehicle {
    std::vector<Voyager*> voyagers;
    public:

    virtual void honk() = 0;
    virtual void onboard(Voyager *voyager) {
        voyagers.push_back(voyager);
        voyager->accept(*this);
    }
};

class Train : public Vehicle {
    void honk() override { std::cout << "Chouchou" << std::endl; }
};

int main() {
    Train train;
    Voyager p{"Paul"};
    train.onboard(&p);
}
