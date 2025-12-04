#include <array>
#include <iostream>

using namespace std;

int main() {
    int data[8]; // plus jamais
    array<int, 8> data2({1,2,3,4,5,6});

    for (auto const el : data2) {
        cout << el;
    }
}