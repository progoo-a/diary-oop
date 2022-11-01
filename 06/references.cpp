#include <iostream>

int foo(int a) {
    a += 2;
    return a;
}

int bar(int &a) {
    a += 2;
    return a;
}

int baz(int *a) {
    (*a) += 2;
    return (*a);
}

int main() {
    int i = 42;
    std::cout << i << std::endl;
    std::cout << foo(i) << std::endl;
    std::cout << i << std::endl;
    std::cout << bar(i) << std::endl;
    std::cout << i << std::endl;
    std::cout << baz(i) << std::endl;
    std::cout << i << std::endl;

    baz(nullptr);
    bar(nullptr);
}
