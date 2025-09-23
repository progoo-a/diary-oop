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
  private: 
    std::vector<int> data;
    int max_value = 0; 
    int min_value = std::numeric_limits<int>::min();

    /**
     * Don't forget to call this method everytime you
     * modify data.
     */
    void update_statistics(int value) {
        min_value = std::min(min_value, value);
        max_value = std::max(max_value, value);
    }

  public: 
    void add(int value) { 
        data.push_back(value); 
        update_statistics(value);
    }
    double average() const {
        int sum = std::accumulate(data.begin(), data.end(), 0);
        return static_cast<double>(sum) / data.size();
    }
    int min() const {
        return min_value;
    }
    int max() const {
        return max_value;
    }
};

int main() {
    Statistics stats;
    for (int i = 0; i < 10; ++i) {
        int value;
        std::cin >> value;
        stats.add(value);
    }
    
    std::cout << "Average: " << stats.average() << std::endl;
    std::cout << "Min: " << stats.min() << std::endl;
    std::cout << "Max: " << stats.max() << std::endl;
}

