#include <iostream>

class MyData {
    static const int data_[5];

public:
    class Iterator {
        const int* ptr_; // pointeur vers l’élément courant
    public:
        // Constructeur
        explicit Iterator(const int* p) : ptr_(p) {}

        // Opérateurs classiques d’itérateur
        int operator*() const { return *ptr_; }         // déréférencement
        Iterator& operator++() { ++ptr_; return *this; } // pré-incrément
        Iterator operator++(int) { Iterator tmp = *this; ++ptr_; return tmp; } // post-incrément

        // Comparaison
        bool operator==(const Iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const Iterator& other) const { return !(*this == other); }
    };

    // --- Accès à l’itérateur ---
    static Iterator begin() { return Iterator(data_); }
    static Iterator end()   { return Iterator(data_ + 5); }
};

// --- Définition du tableau statique ---
const int MyData::data_[5] = { 10, 20, 30, 40, 50 };

// --- Exemple d’utilisation ---
int main() {
    for (auto it = MyData::begin(); it != MyData::end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Ou encore plus moderne :
    for (int x : MyData()) { // si on ajoute les bons begin/end globaux
        std::cout << x << " ";
    }
}
