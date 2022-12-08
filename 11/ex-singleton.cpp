/**
 * Implémenter une classe `Storage` permettant de stocker des valeurs dans un
 * fichier. Les éléments sont des paires clés valeurs (`str`, `str`)
 *
 * - `store(key, value)` Sauve une donnée
 * - `retrieve(key, value)` Récupère une donnée
 *
 * A la construction de l'objet les données sont chargée du fichier et un `map`
 * est créé A la destruction de l'objet les données sont sauvegardées dans le
 * fichier
 */
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "json.hpp"

using json = nlohmann::json;

template <typename T>
class Singleton {
   public:
    static T &instance() {
        static const std::unique_ptr<T> instance{new T{token{}}};
        return *instance;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton) = delete;

   protected:
    struct token {};
    Singleton() {}
};

class Storage final : public Singleton<Storage> {
   public:
    void store(std::string key, std::string value) { data[key] = value; }

    std::string retrieve(std::string key) { return data[key]; }

    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto items() { return data.items(); }

    Storage(token) {
        std::cout << "Load\n";
        try {
            std::ifstream f("vault.json");
            data = json::parse(f);
        } catch (json::parse_error &e) {
            std::ofstream f("vault.json");
            f << "{}" << std::endl;
            data = json::parse("{}");
        }
    };
    ~Storage() {
        std::cout << "Save\n";
        std::ofstream f("vault.json");
        f << data.dump(2) << std::endl;
    };

   private:
    json data;
};

int main() {
    auto &store = Storage::instance();

    store.store("foo", "42");
    store.store("bar", "23");

    std::cout << store.retrieve("foo") << std::endl;

    for (auto &e : store.instance().items()) {
        std::cout << e.key() << " " << e.value() << std::endl;
    }
}
