/**
 * Implémenter le design pattern `strategy` a executer sur un vecteur d'entiers
 * généré depuis l'entrée standard
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
 *   - Déviation standard
 **/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <numeric>

#include <unordered_map>

using value_type = int;
using data_type = std::vector<value_type>;

class Operation
{
public:
    virtual value_type execute(data_type &data) = 0;
    virtual std::string name() = 0;
};

class Add : public Operation
{
public:
    value_type execute(data_type &data) override
    {
        return std::accumulate(data.begin(), data.end(), 0);
    }
    std::string name() { return "add"; }
};

class Multiply : public Operation
{
public:
    value_type execute(data_type &data) override
    {
        return std::reduce(data.begin(), data.end(), 1, std::multiplies<value_type>());
    }
    std::string name() { return "multiply"; }
};

class Catalog
{
protected:
    std::unordered_map<std::string, std::shared_ptr<Operation>> strategies;
    std::string current_strategy;

public:
    value_type execute(data_type data)
    {
        return strategies[current_strategy]->execute(data);
    }

    bool set_strategy(std::string strategy)
    {
        if (strategies.find(strategy) == strategies.end())
            return true;
        current_strategy = strategy;
        return false;
    }

    void register_operation(Operation *operation)
    {
        strategies[operation->name()] = std::shared_ptr<Operation>(operation);
    }

    auto begin() { return strategies.begin(); }
    auto end() { return strategies.end(); }
};

data_type read_data(std::istream &file)
{
    data_type data;
    while (!file.eof())
    {
        int n;
        file >> n;
        data.push_back(n);
    }
    return data;
}

std::string names(Catalog &catalog)
{
    std::string names;
    for (auto &strategy : catalog)
    {
        names += strategy.first + "|";
    }
    names.pop_back();
    return names;
}

int main(int argc, char *argv[])
{
    auto data = read_data(std::cin);

    Catalog catalog;
    catalog.register_operation(new Add);
    catalog.register_operation(new Multiply);

    if (argc < 2 || catalog.set_strategy(argv[1]))
    {
        std::cerr << "Usage: "
                  << argv[0]
                  << " [" << names(catalog) << "]"
                  << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << catalog.execute(data) << std::endl;
}
