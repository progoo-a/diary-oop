
namespace A {
    int u;
    void test(int a) {}
}

namespace B {
    int u;
    void test(int a) {}

    namespace D {
        int u;
    }
}

using namespace B;

int main() {
    u = 23;
    A::u = 42;
    B::D::u = 23;
}