#include <array>
#include <vector>

template <typename T>
class Point {
    T x, y;
    public:
    Point(T x, T y) : x{x}, y{y} {}
    T get_x() { return x; }
    T get_y() { return y; }
};

int main() {
    Point<double> p{3.14, 2.71};
    Point<int> p{3, 2};

    std::vector<int> v;
    std::array<int, 10> a;
}
