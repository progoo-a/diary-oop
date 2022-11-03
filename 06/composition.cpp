#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Wheel {
    public:
    string brand;
    Wheel(string brand) : brand{brand} { cout << "New Wheel" << endl; }
    ~Wheel() { cout << "Has died!" << endl; }
    Wheel(const Wheel &s) {
        cout << "Wheel cloned" << endl;
        brand = s.brand;
    }
};

class Car {
    public:
    Car(int nwheels, string brand = "Michelin") {
        for (int i = 0; i < nwheels; i++)
            wheels.push_back(Wheel(brand));
    }
    vector<Wheel> wheels;
};

int main() {

    {
        Car _1000tipla(4);
    }
    cout << "end of program" << endl;
}
