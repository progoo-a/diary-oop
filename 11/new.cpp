#include <iostream>
#include <exception>

class FooException: public std::exception {};

struct Foo {
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
    int use() { 
        throw FooException();
    }
};

void useFoo() {
    auto *foo = new Foo;
    foo->use();
    delete foo;
}

int main() {
    try {
        useFoo();
    }
    catch(FooException) {
        std::cout << "FooException!\n";
    }
    catch(std::exception) {
        std::cout << "OOps\n";
    }
}