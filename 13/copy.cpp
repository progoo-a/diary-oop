
struct B {
    int a,b;
};
struct C {
    B *b;
    C(const C& other) = default;
};