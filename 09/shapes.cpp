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

struct Shape
{
    virtual double area() = 0;
    virtual std::pair<double, double> center() = 0;
    virtual int get_num_points() = 0;
    virtual void move(double x, double y) = 0;
    virtual ~Shape() = default;
};

struct Square : public Shape
{
    double x, y;
    double edge;
    Square(double x, double y, double edge) : x{x}, y{y}, edge{edge} {}

    double area()
    {
        return edge * edge;
    }
    std::pair<double, double> center()
    {
        return std::pair<double, double>(x, y);
    }
    int get_num_points()
    {
        return 4;
    }
    void move(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};
struct Triangle : public Shape
{
    double x, y;
    double edge;
    Triangle(double x, double y, double edge) : x{x}, y{y}, edge{edge} {}

    double area()
    {
        return edge * edge / 2.; // faux le vrai truc √3/4a²
    }
    std::pair<double, double> center()
    {
        return std::pair<double, double>(x, y);
    }
    int get_num_points()
    {
        return 3;
    }
    void move(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    std::deque<std::shared_ptr<Shape>> shapes;
    shapes.emplace_back(std::make_shared<Triangle>(1,1,10));
    auto t = shapes.back();
    shapes.emplace_back(std::make_shared<Square>(1,1,10));
    for (auto &shape : shapes) {
        std::cout << shape->get_num_points() << "\n";
    }
    std::cout << t.use_count() << " (A)\n";

    std::deque<std::shared_ptr<Shape>> triangles;
    for (auto &shape : shapes) {
        if (shape->get_num_points() == 3) {
            triangles.push_back(shape);
        }
    }

    std::cout << t.use_count() << " (B)\n";

    //std::shared_ptr<Triangle>t1 = std::make_shared<Triangle>(1,1,10);
    //std::shared_ptr<Triangle>triangle = new Triangle(1,1,10);
    // auto t2 = std::make_shared<Triangle>(1,1,10);
    // shapes.push_back(t1);
    // shapes.push_back(t2);
    // auto u = shapes.back();
    // shapes.pop_back();
    // std::cout << u.use_count() << "\n";


    double x;
    int i = static_cast<int>(x);
}
