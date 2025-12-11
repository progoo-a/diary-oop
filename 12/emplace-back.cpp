#include <iostream>
#include <vector>

class Pair {
    int a, b;
public:
    Pair(int a, int b) : a(a), b(b) {
        std::cout << "Build Pair with a=" << a << ", b=" << b << "\n";
    }
    Pair(const Pair &other) : a(other.a), b(other.b) {
        std::cout << "Build (Copy) Pair with a=" << a << ", b=" << b << "\n";
    }
    ~Pair() {
        std::cout << "Delete Pair with a=" << a << ", b=" << b << "\n";
    }
};

int main() {
    std::vector<Pair> pairs; 
    #if 0
    /*
    On note que le constructeur est appelé deux fois: 

    Build Pair with a=23, b=42
    Build (Copy) Pair with a=23, b=42
    Delete Pair with a=23, b=42
    Delete Pair with a=23, b=42
    */
    pairs.push_back(Pair(23, 42));
    #else 
    pairs.emplace_back(23, 42);
    #endif 
}
