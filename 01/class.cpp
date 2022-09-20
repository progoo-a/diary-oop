#include <random>

struct Point {
    public: // visibilité
    int x; // attribut
    int y;
    Point() { // constructeur par défaut
        x = 0;
        y = 0;
        universe = rand() % 100;
    }
    Point(int x, int y) { // constructeur avec paramètres
        this->x = x;
        this->y = y;
        universe = rand() % 100;
    }
    Point add(Point other) { // méthode
        if (universe > 42)
            return Point(456 + x + other.x, y + other.y);
        return Point(x + other.x, y + other.y);
    }
    Point operator+(Point other) { // surcharge d'opérateur
        return add(other);
    }
    Point operator+(int other) { // surcharge d'opérateur
        return add(Point(other, other));
    }    
    private:
    int universe; // attribut privé
};

int main() {
    Point a,b,c;
    Point d(23, 42);
    c = a.add(b);
    c = a + b;
    c = a + 42;
}