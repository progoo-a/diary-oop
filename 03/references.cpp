#include <cmath>
#include <iostream> 

struct Point {
    int x, y, z;
};

double length(const Point &p) {
    return std::sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

int main() {
    Point p(1,2,3);
    std::cout << length(p);
}