#include <iostream>

#if 0
int add(int a, int b) { return a + b; }

float add(float a, float b) { return a + b; }

double add(double a, double b) { return a + b; }
#else

template <typename T>
T add(T a, T b) { return a + b; }
#endif 

int main() {
    float c = add<float>(12.3f, 34);
}