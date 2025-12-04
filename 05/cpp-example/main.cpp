#include <iostream>

extern int a(int, int);
extern int b(int, int);

int main() {

    std::cout << a(23, 42) + b(56, 88) << "\n";
}