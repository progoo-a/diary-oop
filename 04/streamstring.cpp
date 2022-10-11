#include <iostream>
#include <string> 
#include <iomanip>

class Zorglub {
    int zorg;
    float glub;
    public:
    Zorglub(int z, float g) : zorg{z}, glub{g} {}
    std::string to_string() {
        std::stringstream ss;
        ss << "Zorglub(" << std::setprecision(4) << zorg << ", " << glub << ")";
        return ss.str();
    }

    // Optionnel si vous avez besoin d'accéder à des attributs privés de Zorglub
    friend std::ostream &operator<<(std::ostream &os, Zorglub &z);
};

std::ostream &operator<<(std::ostream &os, Zorglub &z) {
    std::cerr << "Debug:" << z.glub; // Besoin de friend pour accéder à glub
    return os << z.to_string();
}

int main() {
    Zorglub z{23, 42.125};
    std::cout << z.to_string();
    std::cout << z;
}