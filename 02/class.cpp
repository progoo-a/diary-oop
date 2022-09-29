#include <iostream>


class Cat {
    public:
    Cat(int year) : year{year}, lives{9} {}

    void meow() {
        std::cout << "Miiiiaaaaoooouuu!" << std::endl;
    }

    int get_year() {
        return year;
    }

    int kill() {
        return lives--;
    }

    private:
    int lives;
    int year;
};

int main() {
    Cat felix(2007);
    felix.meow();
    //felix.year = 2009; // Pas autorisé
    std::cout << felix.get_year();
}

