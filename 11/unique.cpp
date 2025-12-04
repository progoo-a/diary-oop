#include <iostream>
#include <exception>
#include <memory>
#include <assert.h>

class FooException: public std::exception {};

struct Foo {
    int data;
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
    int use() { 
        throw FooException();
        return data;
    }
};

void useFoo() {
    //std::unique_ptr<Foo> foo(new Foo);
    std::unique_ptr<Foo> foo = std::make_unique<Foo>();

    std::unique_ptr<Foo> bar;
    assert(foo.get() != nullptr);
    bar = std::move(foo);
    assert(foo.get() == nullptr);
    foo->use();
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