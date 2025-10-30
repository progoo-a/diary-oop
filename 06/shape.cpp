
#include <iostream>
using namespace std;

struct Shape {
    virtual double area() {
        return 42;
    }
};

struct Triangle : public Shape {
    int data = 23;
    double area() override {
        return data;
    }
};

int main() {
    Shape* shape = new Triangle();
    cout << shape->area() << "\n";
}