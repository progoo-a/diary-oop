/**
 * Exercice Shapes:
 *   - Une interface `Shape` représentant une forme géométrique et disposant de:
 *   - `area() : double`
 *   - `center() : pair<double, double>`
 *   - `get_num_points(): int` Nombre de points de la forme
 *   - `move(x: double, y: double)` Pour déplacer la forme
 * - Un carré `Square` et un triangle `Triangle` dérivent de `Shape`
 *   - `Square(x: double, y: double, edge: double)`
 *   - `Triangle(x: double, y: double, edge: double)`
 *
 * Réaliser un conteneur de formes contenant des formes en utilisant `sharedptr`.
 * Puisque les objets à stocker sont polymorphiques, ils ne peuvent être stockés que par pointeurs.
 * Démontrer le fonctionnement dans le main.
*/
#include <iostream>
#include <memory>
#include <deque>

struct Shape {
    virtual double area() = 0;
    virtual std::pair<double, double> center() = 0;
    virtual int get_num_points() = 0;
    virtual void move(double x, double y) = 0;
};

std::pair<int, int> foo() {
    auto u = std::pair<int, int>(23, 42);
    std::cout << "(" << u.first << "," << u.second << ")\n";
    return u;
}
int main() {
    std::deque<std::shared_ptr<Shape> >shapes;
}
