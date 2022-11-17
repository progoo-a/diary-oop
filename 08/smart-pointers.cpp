#include <iostream>
#include <memory>
// RAII <-- C'est la responsabilité de l'objet de nettoyer après.

struct Foo {
    int i;
    Foo(int i=0) : i{i} { std::cout << "Foo Created\n"; }
    ~Foo() { std::cout << "Foo Deleted\n"; }
};
int main() {
    {
        std::shared_ptr<Foo> i(new Foo(23));
        {
            //std::unique_ptr<Foo> i(new Foo(23));
            //Foo *i = new Foo(23);
            std::shared_ptr<Foo> u = i;
        }
    }
    std::cout << "After\n";
}
