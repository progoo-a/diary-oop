#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Foo {
    int i;
    Foo(int i=0) : i{i} { std::cout << "Foo Created\n"; }
    ~Foo() { std::cout << "Foo Deleted\n"; }
};

struct Bar {
    std::shared_ptr<Foo> foo;
    Bar(std::shared_ptr<Foo> foo) : foo{foo} {}
};

int main() {
    vector<Bar> bars;
    {
        std::shared_ptr<Foo> f = std::make_shared<Foo>(23);
        bars.push_back(f);
        bars.push_back(f);
        bars.push_back(f);
        bars.push_back(f);
    }
    cout << bars.back().foo.use_count() << "\n";
    bars.pop_back();
    cout << bars.back().foo.use_count() << "\n";
    bars.pop_back();
    cout << bars.back().foo.use_count() << "\n";
    bars.pop_back();
    cout << bars.back().foo.use_count() << "\n";
    bars.pop_back();
    cout << "AFTER";
}
