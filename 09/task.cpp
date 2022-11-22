/**
 * Exercice :
 * - Une classe qui contient une tâche (TODO)
 *   - Description (chaîne de caractère)
 *   - Priorité (urgent, normal, bas) : type enumération C++
 * - File d'attente qui contient toutes les tâches (uniqueptr)
 *   - Container de la STL : deque
 *
 * Démontrer avec petit programme que l'on peut ajouter des tâches dans la file d'attente
 * Et que ces objets sont supprimés convenablement lorsqu'ils ne sont plus utilisés
 *
 */
#include <iostream>
#include <deque>
#include <memory>
#include <assert.h>

enum Priority { LOW, NORMAL, HIGH };

struct Todo {
    std::string description;
    Priority priority;
    Todo(std::string description, Priority priority = Priority::NORMAL) :
        description{description}, priority{priority} {
            std::cout << "Task created: " << description << "\n";
        }
    ~Todo() { std::cout << "Task destroyed: " << description << "\n";}
};

int main() {
    #if 0
    std::deque<Todo> todo;
    //todo.push_back(Todo("Get milk"));
    todo.emplace_back("Get Milk");
    Todo a = todo.back(); // Crée une copie de ma tâche
    #elif 0
    std::deque<Todo*> todo;
    auto ptr = new Todo("Get Milk");
    todo.push_back(ptr);
    delete ptr;
    #elif 0
    std::deque<std::unique_ptr<Todo> > todo;
    todo.push_back(std::make_unique<Todo>("Get Milk"));
    #else
    std::deque<std::unique_ptr<Todo> > todo;
    std::unique_ptr<Todo>p = std::make_unique<Todo>("Get Milk");
    todo.push_back(std::move(p));
    assert(p == nullptr); // Vaut nullptr parce le point a été déplacé
    #endif
}
