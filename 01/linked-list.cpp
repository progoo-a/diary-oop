#include <iostream> 

struct Cat {
    int age;
    int weight;
    char *name;
    Cat() {
        age = 0;
        weight = -1;
        name = "unknown";
    }
    Cat(int age, int weight, char *name) {
        this->age = age;
        this->weight = weight;
        this->name = name;
    }
};

struct Element {
    Cat &cat;
    Element *next;

    Element(Cat &cat) : cat{cat}, next{nullptr} {}
};

struct List {
    Element *first;
    Element *last;

    void push_back(Cat &cat) {
        // List empty?
        if (first == nullptr) {
            last = first = new Element(cat);
        }
        // Append 
        else {
            last->next = new Element(cat);
        }
    }

    Cat pop_front() {
        Cat cat = first->cat;
        first = first->next; 
    }
};

int main() {
    Cat a{3, 4, "Miaou"};
    Cat b{5, 6, "Garfield"};

    List list;
    list.push_back(a);
    list.push_back(b);

    for (Element *e = list.first; e != nullptr; e = e->next) {
        std::cout << e->cat.name << std::endl;
    }
}