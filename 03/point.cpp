#include "point.hpp" 
#include <cmath>


double Point::distance(const Point &p) const {
    double sum = 0;
    for (int i = 0; i < D; i++) {
        sum += (data[i] - p.data[i]) * (data[i] - p.data[i]);
    }
    return sqrt(sum);
}

int main() {
    Point<int, 2> p1;
    Point<double, 2> p2;
    p1[0] = 42;
}