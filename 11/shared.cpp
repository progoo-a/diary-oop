#include <iostream>
#include <memory>

struct Foo {
    int value;
    Foo(int value) : value(value) { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
};

int main() {
    std::shared_ptr<Foo> a = std::make_shared<Foo>(42);
    std::shared_ptr<Foo> b = a;
    std::cout << "Count: " << a.use_count() << "\n";
}
