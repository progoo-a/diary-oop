#include <iostream>
#include <cassert>

struct Foo {
    int a; 
    int b;
    Foo(int a, int b) : a{a}, b{b} {}
    Foo operator<<(Foo &b) {
        return Foo(a, b.b);
    }
};

int main() {
    Foo u(23,42);
    Foo v(3,4);
    Foo w = u << v;
    assert(w.a == u.a && w.b == v.b);
}