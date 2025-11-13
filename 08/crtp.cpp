#include <iostream> 

template <class T, class Base>
class PointCRTP {
    protected:
    T x, y;
    public:
    PointCRTP(T x, T y) : x(x), y(y) {}

    auto operator+(const Base&other) {
        return Base(x + other.x, y + other.y);
    }
};

template <class T> 
struct Point : public PointCRTP<T, Point<T>> {
    using PointCRTP<T, Point<T>>::PointCRTP;
};

template <class T>
class MyPoint: public PointCRTP<T, MyPoint<T>> {
    public:
    using PointCRTP<T, MyPoint<T>>::PointCRTP;

    void print() {
        std::cout << "(" << PointCRTP<T, MyPoint<T>>::x << "," << PointCRTP<T, MyPoint<T>>::y << ")";
    }
};

int main() {
    //Point<float, Point<float>> p(3,4);

    MyPoint<int> a(1,2);
    MyPoint<int> b(2,3);
    MyPoint<int> c = a + b;    
}

