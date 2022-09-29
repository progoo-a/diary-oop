#include <iostream>

int main() {
    char buffer[1024] = {};
    std::cin.getline(buffer, sizeof(buffer) - 1);

    std::string str;
    std::getline(std::cin, str);

    std::cin.putback('a');
    std::cin.putback('b');
    char c = std::cin.peek();
    std::cout << c;

}