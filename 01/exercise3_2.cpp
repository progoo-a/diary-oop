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
#include "statistics.hpp"

int main() {
    Statistics<int> stats;
    for (int i = 0; i < 10; ++i) {
        int value;
        std::cin >> value;
        stats.add(value);
    }

    std::cout << "Average: " << stats.average() << std::endl;
    std::cout << "Min: " << stats.min() << std::endl;
    std::cout << "Max: " << stats.max() << std::endl;
}

