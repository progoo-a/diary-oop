#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

int main() {
    std::vector<int> v;

    for (int i = 0; i < 10; i++ ) {
        v.push_back(i);
    }

    // Sucre syntaxique
    for (auto &u : v) {
        std::cout << u;
    }

    // Implémentation du sucre
    for (auto u = v.begin(); u != v.end(); u++) {
        std::cout << *u;
    }

    // Faire la somme des éléments
    int sum = 0;
    for (auto &u : v) {
        sum += u;
    }
    std::cout << sum;

    // Faire la somme en utilisant la STL
    std::cout << std::accumulate(v.begin(), v.end(), 0);

    // Parcourir tous les éléments via une lambda
    int sum2 = 0;
    std::for_each(v.begin(), v.end(), [&sum2](auto value){
        sum2 += value;
    });

    std::vector<int>::size_type
}
