#pragma once

#include <array>

template <typename T, int D>
class Point {
    std::array<T, D> data;
    public:
    Point() = default;
    Point(std::array<T, D> data) : data(data) {}
    T& operator[](int i) { return data[i]; }
    double distance(const Point &p) const;
    void move(std::array<T, D> &v);
    void print() const;
    void set_x(T x) { data[0] = x; }
};
