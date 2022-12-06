#include <iostream>

// Fonction générique add pour tout type T
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Spécialisation pour le type bool
template <>
bool add(bool a, bool b) {
    return a | b;
}

int main() {
    std::cout << add<bool>(0, 1);
}
