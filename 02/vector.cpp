#include <vector>
#include <iostream>

// template<typename T>
// class Vector {
//     public:
//     void push(T value);
//     T pop();
// };


int main() {
    // Vector<int> a;
    // Vector<float> b;

    std::vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(15);
    std::cout << v.size();
    v[1];
    for (auto i : v) {
        std::cout << "Un élément " << i;
    }
    for (auto it = v.begin(); it != v.end(); it++) {
    
    }

    std::vector< std::vector<std::string> > w;
    w.push_back({"abc", "def", "ghi", "jkl"});
    w.push_back({"abc", "def", "ghi", "jkl"});
}