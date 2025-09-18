#include <stdio.h>

struct Circle {
    double radius;
    
    void doubleRadius() {
        radius *= 2;
    }
};

int main() {
    Circle a = {42};

    printf("%f\n", a.radius);
    a.doubleRadius();
    printf("%f\n", a.radius);
}