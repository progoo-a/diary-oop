/**
 * Implémenter le design pattern `strategy` a executer sur un vecteur d'entiers généré depuis l'entrée standard
 *
 * ```console
 * echo "4 8 15 16 23 42" | ./a.out add
 * 108
 * ```
 *
 * - Les stratégies disponibles utilisent les algorithmes de la STL si possible
 *   - Somme
 *   - Produit
 *   - Max
 *   - Min
 *   - Déviation standar
 **/
#include <iostream>
#include <string>
#include <vector>
#include <map>

template <class InputIterator, class T>
class Operation {
    public:
        virtual T execute(InputIterator first, InputIterator last) = 0;
        virtual std::string name() = 0;
};

template <class InputIterator, class T>
class Add : public Operation {
    public:
        T execute(InputIterator first, InputIterator last) override {
            T sum = 0;
            for (auto it = first; first != last; it++) {
                sum += *it;
            }
            return sum;
        }
        std::string name() { return "add"; }
};

template <class InputIterator, class T>
class Mul : public Operation {
    public:
        T execute(InputIterator first, InputIterator last) override {
            T sum = 0;
            for (auto it = first; first != last; it++) {
                sum += *it;
            }
            return sum;
        }
        std::string name() { return "multiply"; }
};

using value_type = int;
using data_type = std::vector<value_type>;

class Catalog {

    std:unordered_map<std::string, Strategy> strategies;

    value_type execute(std::string strategy, data_type data) {
        return strategies[strategy].execute(data.begin(), data.end());
    }

    void register_strategy(Strategy &strategy) {
        strategies[strategy.name(), strategy];
    }
};

int main(int argc, char* argv) {
    // Read data
    std::vector<int> data;
    while(!std::cin.eof()) {
        int n;
        std::cin >> n;
        data.push_back(n);
    }

    Catalog catalog;
    catalog.register_strategy(AddStrategy);
    catalog.register_strategy(MultiplyStrategy);

    if (argc < 2) return 1;
    if (catalog.set_strategy(argv[1])) return 2;
    catalog.execute(data);
}
