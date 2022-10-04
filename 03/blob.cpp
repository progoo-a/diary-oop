#include <iostream>
#include <vector>

using namespace std;

class Blob {
    int u;
public:
    string name;
    Blob() : u{0}, name{"Anonymous"} { cout << "Blob " << name << " created without arguments" << endl; }
    Blob(int u, string name = "Anonymous") : u{u}, name{name} { 
        cout << "Blob " << name << " created with argument : " << u << endl; }
    Blob(const Blob &other) : u{other.u}, name{other.name} { 
        cout << "Blob " << name << " created by copy" << endl; }
    Blob& operator=(const Blob &other) {
        cout << "Blob " << name << " assigned by copy" << endl;
        u = other.u;
        name = other.name;
        return *this;
    }
    ~Blob() { cout << "Blob " << name << " destroyed" << endl; }
    int slurp() {
        cout << "Blob " << name << " slurped" << endl;
        return u;
    }
};

int main()
{
    vector<Blob> v;

    v.push_back(Blob(23, "Blobby"));
    cout << "***\n";
    // a.name = "Booba";
    // v.push_back(a);

    // for (auto &blob : v) {
    //     blob.slurp();
    // }

    // Blob b = a; // Constructeur par copie
    // auto *c = new Blob{23, "Blobby"}; // Allocation dynamique
    // delete c;
    // a = b; // Opérateur d'assignation
    // b.slurp();
}