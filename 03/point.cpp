/*
- Créer une classe Point avec deux attributs x et y
- Créer un constructeur pour initialiser les attributs
- Créer un constructeur par copie explicite
- Créer les surcharges nécessaires (+, -, <<) pour ajouter des points, les
soustraire et les afficher.
- Consigner chaque appel sur la sortie standard (ex: "Constructeur par copie
appelé")
*/
#include <iostream>
#include <sstream>

class Point {
    double x, y;
  public:
    Point(double x, double y) : x(x), y(y) {}
    Point() : x(0), y(0) {}
    Point operator+(Point& other) { return Point(x + other.x, y + other.y); }
    Point& operator=(const Point& other) {
        x = other.x;
        y = other.y;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "Point(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p(1, 2);
    Point q = p;                  // Appel du constructeur par copie
    Point r;                      // Constructeur sans paramètres
    r = p + q;                    // Appel de l'opérateur +
    std::cout << r << std::endl;  // Affichage du point r
}
