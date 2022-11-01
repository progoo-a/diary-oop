#include <iostream>

class A {
    public:
    int foo;
    A() { std::cout << "A built" << std::endl; }
    ~A() { std::cout << "A destroyed" << std::endl; }
    virtual void bar(int, int) = 0; // Methode Abstraite
};

class B : public virtual A {
    public:
    B() { std::cout << "B built" << std::endl; }
    ~B() { std::cout << "B destroyed" << std::endl; }
};

class C : public virtual A {
    public:
    C() { std::cout << "C built" << std::endl; foo = 23; }
    ~C() { std::cout << "C destroyed" << std::endl; }
};

class D : public B, public C {
    public:
    D() { std::cout << "D built" << std::endl;}
    ~D() { std::cout << "D destroyed" << std::endl; }
};

int main() {
    D d;
    std::cout << d.foo;
    // auto *d = new D;
    // delete(d);
}
