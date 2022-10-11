#include "point.hpp"
#include <iostream> 

int main() {
    Point<double, 3> p1({{1, 2, 3}});
    Point<double, 3> p2({{4, 5, 6}});
    std::cout << p1.distance(p2) << std::endl;
    return 0;
}