#include <vector>
#include <iostream>

using namespace std; // Évite le std::

class Element {};

void nested() {
    vector<vector<Element>> elements;
    elements.push_back(vector<Element>());
    elements.at(0).push_back(Element());

    // Solution alternative.
    vector<vector<Element>> elements2(5, vector<Element>(5, Element()));
}

void dangerous() {
    vector<int> data({1,2,3,4,5,6});

    int *ptr = &data[5];  // store location of 6th element.
    // Très dangereux car si des éléments sont ajoutés au tableau
    // il pourrait être ralloué, et donc l'adresse pointée par ptr
    // serait invalide (exemple du jeune et de la vieille) 
}

int main() {
    vector<int> v({1,2,3,4,5,6});

    // for(auto const &value : v)
    for (auto it = v.begin(); it < v.end(); it++) {
        cout << *it << endl;
    }
    cout << '\n';
}




