# Semaine 11/16

- [ ] Labo Shunting Yard
- [ ] Exceptions
- [ ] Smart Pointers

## Exceptions

Une exception est un mécanisme de gestion des erreurs qui permet de séparer le code normal du code de gestion des erreurs. En C++, les exceptions sont lancées avec le mot-clé `throw` et capturées avec `try` et `catch`. En C++ la bibliothèque standard définit plusieurs types d'exceptions, comme `std::runtime_error`, `std::invalid_argument`, etc. 
Elles sont utilisées pour signaler des erreurs qui ne peuvent pas être gérées localement, comme des erreurs de mémoire, des erreurs de logique, ou des erreurs d'entrée/sortie.
Par exemple la méthode `.at` d'un `std::vector` lance une exception `std::out_of_range` si l'index demandé est hors des limites du vecteur. Ou alors, lorsqu'une fonction reçoit un argument invalide, elle peut lancer une `std::invalid_argument`.

Exemble d'utilisation des exceptions en C++ :

```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

double divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return a / b;
}

int main() {
    try {
        std::cout << divide(10, 2) << std::endl; // Affiche 5
        std::cout << divide(10, 0) << std::endl; // Lance une exception
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Gère l'exception
    }
    return 0;
}
```

## Smart Pointers

Les smart pointers (pointeurs intelligents) sont des classes qui gèrent automatiquement la durée de vie des objets dynamiques en C++. Ils permettent d'éviter les fuites de mémoire et les erreurs de gestion de mémoire en s'assurant que la mémoire est libérée lorsque l'objet n'est plus utilisé. Les smart pointers les plus couramment utilisés en C++ sont `std::unique_ptr`, `std::shared_ptr` et `std::weak_ptr`.

Ils permettent de gérer la mémoire de manière plus sûre et plus efficace, en évitant les erreurs courantes telles que les fuites de mémoire, les doubles libérations et les accès à des objets déjà détruits.

C'est le concept de RAII (Resource Acquisition Is Initialization) : la ressource est acquise lors de la création de l'objet et libérée lors de sa destruction.

Un **shared_ptr** permet à plusieurs pointeurs de partager la propriété d'un même objet. L'objet est détruit lorsque le dernier `shared_ptr` qui le pointe est détruit ou réassigné.

Un **unique_ptr** est un pointeur qui possède la propriété exclusive d'un objet. Il ne peut pas être copié, mais peut être déplacé. L'objet est détruit lorsque le `unique_ptr` est détruit ou réassigné.

```cpp
#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass() { std::cout << "MyClass constructor" << std::endl; }
    ~MyClass() { std::cout << "MyClass destructor" << std::endl ; }
    void greet() { std::cout << "Hello from MyClass!" << std::endl; }
};

int main() {
    // Utilisation de unique_ptr
    {
        std::unique_ptr<MyClass> ptr1 = std::make_unique<MyClass>();
        ptr1->greet();
        // ptr1 est détruit automatiquement à la fin de ce bloc
    } // MyClass destructor est appelé ici  
    // Utilisation de shared_ptr
    {
        std::shared_ptr<MyClass> ptr2 = std::make_shared<MyClass>();
        {
            std::shared_ptr<MyClass> ptr3 = ptr2; // Partage la propriété
            ptr3->greet();
            std::cout << "Reference count: " << ptr2.use_count() << std::endl; // Affiche 2
        } // ptr3 est détruit ici, mais l'objet MyClass n'est pas détruit car ptr2 le possède encore
        std::cout << "Reference count: " << ptr2.use_count() << std::endl; // Affiche 1
    } // MyClass destructor est appelé ici, car ptr2 est détruit
    return 0;
}
```

## Comparaison tokens.cpp vs tokens2.cpp

- **Structure**  
  - `tokens.cpp` : une seule classe `Token` qui mélange nombres et opérateurs via des champs optionnels.  
  - `tokens2.cpp` : hiérarchie (`Token`, `Number`, `Operator`, `Addition`) qui sépare données et comportement.

- **Avantages de tokens.cpp**  
  - Fichier compact, moins de types à maintenir.  
  - Pas de polymorphisme ni d'allocation dynamique : copies directes dans le `std::vector`.  
  - Suffisant pour de très petits exercices ou des scripts rapides.

- **Inconvenients de tokens.cpp**  
  - Logique spécifique (priorité, associativité) entremêlée dans un constructeur générique.  
  - Ouverture à l’erreur : impossible d’empêcher la création d’un opérateur inconnu ou de forcer les champs cohérents.  
  - Difficile à étendre (nouvel opérateur = modifier la classe, viol de l’Open/Closed).  
  - Les données restent publiques (`s`), ce qui empêche de garantir les invariants.

- **Avantages de tokens2.cpp**  
  - Typage clair : `Number` et `Operator` encodent leurs invariants dans leurs constructeurs.  
  - Extensibilité naturelle : ajouter un opérateur revient à dériver `Operator` (ou injecter un functor).  
  - Encapsulation : accès via accesseurs (`getType`, `getSymbol`) et destructeur virtuel.  
  - Comportement porté par les objets (un opérateur sait calculer `apply`), mieux aligné avec l’approche objet.

- **Inconvenients de tokens2.cpp**  
  - Plus de code et de classes à gérer, coût initial plus élevé.  
  - Usage de pointeurs dans `std::vector<Token*>` : nécessite une gestion de durée de vie (raw pointers sûrs ici car objets automatiques).  
  - Nécessite de penser à la virtualisation si on ajoute des méthodes appelées via la base (ici déjà pour le destructeur).

- **Quand choisir l’un ou l’autre ?**  
  - Pour un TP court ou un parseur ultra simple : `tokens.cpp` suffit.  
  - Pour un moteur d’expression extensible ou un code produit : `tokens2.cpp` apporte la séparation de responsabilités et la sécurité de types attendues.
