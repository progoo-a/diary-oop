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

    std::vector<Cat> v; 
    for (int i = 0; i < 10; i++) {
        v.push_back(Cat(i));
    }
    
}