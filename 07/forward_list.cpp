#include <forward_list>
#include <iostream>

using namespace std;

int main() {
    forward_list<int> v({1,2,3,4,5,6});

    // for(auto const &value : v)
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
    cout << '\n';
}
