#include <vector> // Tableaux dynamiques 
#include <list>
#include <iostream> // Nouvelle manière de faire des printf

int main() {
    std::vector<int> numbers;
    std::list<int> myList;

    myList.push_back(42);
    
    numbers.push_back(42); 
    int value = numbers.back();
    numbers.pop_back();
}
