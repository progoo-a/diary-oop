#include <stdio.h>
#include <string> 

struct Cat {
    const std::string name;
    const int initialWeight;
    int weight;
    int remainingLives = 9;

    Cat(std::string name, int initialWeight) : name(name), initialWeight(initialWeight) {
        weight = initialWeight;
    }

    void purr() {
        printf("RrrrrrRrrrrRrrr\n");
    }

    void eat() {
        weight += 1;
        if (weight > 30) {
            kill();
        }
    }

    void kill() {
        printf("Gleuarap!!!\n");
        remainingLives--;
        weight = initialWeight;
    }

    void sleep() {
        printf("Zzzzzzzzzzzz\n");
    }

    void display() {
        printf("Cat %s weights %d (%d lives)\n", name.c_str(), weight, remainingLives);
    }
};


int main() {
    Cat felix("Felix", 5);
    felix.display();

    felix.kill();
    for (int i = 0; i < 100; i++) {
        felix.eat();
    }
    felix.purr();
    felix.display();
}