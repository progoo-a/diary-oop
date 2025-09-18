/**
 * - Réaliser un programme en C++ qui récupère 10 valeurs 
 *   entières sur l'entrée standard et en calcul la moyenne.
 * - Ces valeurs seront stockées dans un tableau dynamique 
 *   (utiliser `std::vector`).
 */
#include <iostream>
#include <vector>

int main() {
    using value_type = int;

    constexpr int N = 10;
    std::vector<value_type> data;
    for (int i = 0; i < N; ++i) {
        value_type value;
        std::cin >> value;
        data.push_back(value);
    }

    value_type sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += data[i];
    }    
    for (auto value : data) {
        sum += value;
    }
    
    std::cout << "Moyenne : " << (float)sum / N << std::endl;
}