#include <iostream> 
#include <string>

class C {
    public:
    std::string name;
    C(std::string v="default") : name(v) {
        std::cout << "Constructeur de " << name << " avec 1 paramètre\n";
    } // Supprime le constructeur par défaut
    C(std::string a, std::string b) : name(a+b) {
        std::cout << "Constructeur de " << name << " avec 2 paramètres\n";
    }
    C(C &other) : name(other.name) {
        std::cout << "Constructeur de " << name << " par copie\n";
    }
    C& operator=(C &other) { 
        std::cout << "Opérateur de " << name << " d'affectation\n";
        name = other.name; return *this; }

    C operator+(C &other) {
        std::cout << "Opérateur d'addition de " << name << "\n";
        return C(name + other.name);
    }
    C operator+(int other) {
        std::cout << "Opérateur d'addition avec int de " << name << "\n";
        return C(name + std::to_string(other));
    }
    // Constructeur par déplacement
    // Opérateur de déplacement

    ~C() {
        std::cout << "Destructeur de " << name << "\n";
    } // Destructeur
};


int operator+(int a, C &other) {
    std::cout << "Surcharge + pour int et C\n";
    return a + other.name.size();
}

std::ostream& operator<<(std::ostream &os, C &other) {
    std::cout << "Surcharge << pour ostream et C\n";
    return os << other.name;
}

int main() {
    C ca("ca");
    C cb("c", "b");
    C cc = ca; // Constructeur par copie
    cb = ca;   // L'opérateur d'affectation
    cb + cc;
    cb + 42;
    42 + cb;

    int ia(3);
    int ib;
    int ic = 42;
    int id = ib = ia;
}