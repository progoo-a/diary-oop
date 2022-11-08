#include <vector>

using namespace std;

class Foo {
    int f;
    public:
    Foo(int f) : f{f} {}
};

int main() {
    vector<Foo> foos;

    foos.push_back(Foo{42}); // Avant C11 (crée une copie inutile temporaire)
    foos.emplace_back(23);   // Après C11 (délègue la création du Foo au vecteur)
}
