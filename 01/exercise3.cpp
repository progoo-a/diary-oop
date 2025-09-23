/*
- Avec l'exercice 2 on a plusieurs problèmes: 
  - Problème de responsabilités : tout est dans main. 
  - Les données sont accessibles partout dans le main : pas de protection.
- Refactoriser le code en créant une classe `Statistics` qui gère les données
- La classe doit avoir les méthodes suivantes:
  - `void add(int value)` : ajoute une valeur
  - `double average() const` : calcule la moyenne
  - `int min() const` : retourne la valeur minimale
  - `int max() const` : retourne la valeur maximale
- En attributs, la classe doit avoir un `std::vector<int>` pour stocker les valeurs.
*/
#include <iostream> 
#include <vector>
#include <numeric>
#include <algorithm>
#include <ranges>

struct Statistics {
    std::vector<int> data;
    std::ranges::min_max_result<int> minmax; 

    void add(int value) { 
        data.push_back(value); 
        minmax = std::ranges::minmax(data);
    }
    double average() const {
        int sum = std::accumulate(data.begin(), data.end(), 0);
        return static_cast<double>(sum) / data.size();
    }
    int min() const {
        return minmax.min;
    }
    int max() const {
        return minmax.max;
    }
};

int main() {
    Statistics stats;
    for (int i = 0; i < 10; ++i) {
        int value;
        std::cin >> value;
        stats.add(value);
    }

    stats.data.push_back(666); // Hack!

    std::cout << "Average: " << stats.average() << std::endl;
    std::cout << "Min: " << stats.min() << std::endl;
    std::cout << "Max: " << stats.max() << std::endl;
}

