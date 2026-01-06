#include <iostream>
#include <assert.h>

struct A {
    int foo;
    A() : foo(rand() % 100){ std::cout << "A constructor called" << std::endl; }
    ~A() { std::cout << "A destructor called" << std::endl; }
};
struct B : virtual public A {
    B() { std::cout << "B constructor called" << std::endl; }
    ~B() { std::cout << "B destructor called" << std::endl; }
    auto getFooFromB() { return foo; }    
};
struct C : virtual public A {
    C() { std::cout << "C constructor called" << std::endl; }
    ~C() { std::cout << "C destructor called" << std::endl; }
    auto getFooFromC() { return foo; }
};
struct D : public B, public C {
    D() { std::cout << "D constructor called" << std::endl; }
    ~D() { std::cout << "D destructor called" << std::endl; }
};

int main() {
    D d;
    assert(d.getFooFromB() == d.getFooFromC());
}
