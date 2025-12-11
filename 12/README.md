# Semaine 12/16

- [x] Packaging avec VCPKG et CMake
- [x] Philosophie de l'enseignement (parenthèse)
- [x] Polymorphisme dynamique
- [x] Fonctions Lambdas

## Fonctions anonymes, closures et Lambdas

Les fonctions anonymes, également appelées fonctions lambda, sont des fonctions définies sans nom. De manière générale, elles sont utilisées pour des opérations simples et courtes, souvent comme arguments de fonctions de plus haut niveau (comme les algorithmes de la bibliothèque standard). Elles existent dans de nombreux langages de programmation, y compris C++, Python, JavaScript, etc.

En Python: 

```python
add = lambda x, y: x + y
print(add(2, 3))  # Affiche 5

# Comme elle n'a pas de nom, je peux la passer directement en argument
numbers = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x**2, numbers))
print(squared)  # Affiche [1, 4, 9, 16
```

En C++ on a le même concept avec une syntaxe un peu différente :

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    auto add = [](int x, int y) { return x + y; };
    std::cout << add(2, 3) << std::endl; // Affiche 5

    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::for_each(numbers.begin(), numbers.end(), [](int n) {
        std::cout << n << " ";
    });
    std::cout << std::endl;}
```

La syntaxe est donc la suivante :

```cpp
[](){} 
[](int a){ return a; }
[](int a) -> int { return a; }

[capture](parameters) -> return_type { comportement }
```

Pour comprendre la capture faut comprendre le concept de closure. Une closure est une fonction qui "capture" des variables de son environnement lexical, c'est-à-dire les variables qui sont accessibles dans le scope où la fonction est définie. Cela permet à la fonction d'accéder à ces variables même lorsqu'elle est appelée en dehors de ce scope.

```cpp

int foo(int x) {
    // Foo ne voit pas y directement
    return x;
}

int a() {
    int y = 42;
    foo(23);
}

int b() {
    int y = 42;
    auto lambda = []() { return y; }; // Erreur : y n'est pas capturé

    auto lambda2 = [y](int u) { return u + y; }; // Correct : y est capturé par valeur

    lambda2(10); // Retourne 52 
}
```

Les différents types de captures sont: 

- Par valeur `[x, y]` : La lambda fait une copie des variables capturées. Les modifications apportées à ces variables à l'intérieur de la lambda n'affectent pas les variables originales.
- Par référence `[&x, &y]` : La lambda capture les variables par référence. Les modifications apportées à ces variables à l'intérieur de la lambda affectent les variables originales.
- Tout capturer par valeur `[=]` : Toutes les variables utilisées dans la lambda sont capturées par valeur.
- Tout capturer par référence `[&]` : Toutes les variables utilisées dans la lambda sont capturées par référence.

### Exemple en JavaScript

```javascript
function makeCounter() {
    let count = 0; // Variable locale à makeCounter
    return function() { // Fonction anonyme (closure)
        count += 1; // Accède à la variable count de makeCounter
        return count;
    };
}
const counter = makeCounter();
console.log(counter()); // Affiche 1
console.log(counter()); // Affiche 2
console.log(counter()); // Affiche 3

// Exemple de fonction arrow
const add = (x) => {
    return (y) => {
        return x + y; // Accède à la variable x de add
    };
};
const add5 = add(5);
console.log(add5(3)); // Affiche 8
```

## Polymorphisme 

Le polymorphisme est un concept fondamental de la programmation orientée objet qui permet à des objets de différentes classes d'être traités comme des objets d'une classe commune. En C++, le polymorphisme dynamique est réalisé à l'aide de fonctions virtuelles et de l'héritage.

### Polymorphisme static 

La surcharge de fonctions sont des exemples de polymorphisme statique, où la résolution de la fonction à appeler est faite à la compilation en fonction des types des arguments.

```cpp
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int main() {
    add(2,3) // Appelle la version int
    add(2.5,3.5) // Appelle la version double
    add(2, 3.5) // Erreur de compilation : ambiguïté
}
```

On peut aussi utiliser les templates pour réaliser du polymorphisme statique :

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    add(2,3) // Appelle la version int
    add(2.5,3.5) // Appelle la version double
    add(2LL, 3LL) // Appelle la version long long
    add<double>(2, 3.5) // Spécifie le type double explicitement
}
```

La surcharge d'opérateurs est un autre exemple de polymorphisme statique :

```cpp
#include <iostream>

class Vector2D {
public:
    float x, y;
    Vector2D(float x, float y) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
};
```

### Polymorphisme dynamique

Par exemple aux échecs, on peut avoir une classe de base `Piece` avec une méthode virtuelle `move()`, et des classes dérivées comme `Rook`, `Bishop`, et `Knight` qui implémentent cette méthode de manière spécifique.

```cpp
#include <iostream>
#include <memory>
#include <vector>
class Piece {
public:
    virtual void move() const = 0; // Méthode virtuelle pure
    virtual ~Piece() = default; // Destructeur virtuel
};

class Rook : public Piece {
public:
    void move() const override {
        std::cout << "Rook moves in straight lines." << std::endl;
    }
};

class Bishop : public Piece {
public:
    void move() const override {
        std::cout << "Bishop moves diagonally." << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Piece>> pieces;
    pieces.push_back(std::make_unique<Rook>());
    pieces.push_back(std::make_unique<Bishop>());

    for (const auto& piece : pieces) {
        piece->move(); // Appelle la méthode appropriée selon le type réel de l'objet
    }
}
```

### RTTI (Run-Time Type Information)

Le RTTI est un mécanisme qui permet de déterminer le type réel d'un objet à l'exécution. En C++, cela est principalement réalisé à l'aide de l'opérateur `dynamic_cast` et de la fonction `typeid`.

On ne l'aime pas trop car cela peut indiquer un mauvais design orienté objet, surtout en embarqué. Selon MISRA C++: "Avoid using RTTI. Design your class hierarchies and interfaces so that RTTI is not needed." est une règle de base qui interdit l'utilisation de `dynamic_cast` et `typeid`. 

Pourquoi c'est pas bien vu ? Parce que si on se retrouve à devoir vérifier le type d'un objet à l'exécution, c'est souvent le signe qu'on n'a pas bien conçu son système de classes et qu'on aurait dû utiliser le polymorphisme correctement dès le départ. Mais surtout c'est que l'utilisation de RTTI peut introduire des surcoûts en termes de performance et de taille binaire, ce qui est particulièrement problématique dans les systèmes embarqués où les ressources sont limitées.

Voici un exemple avec des animaux d'utilisation de la RTTI en C++ :

```cpp
#include <iostream>
#include <typeinfo>
class Animal {
public:
    virtual ~Animal() = default; // Destructeur virtuel
};  

class Dog : public Animal {
public:
    void bark() const {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void meow() const {
        std::cout << "Meow!" << std::endl;
    }
};

void makeSound(Animal* animal) {
    if (Dog* dog = dynamic_cast<Dog*>(animal)) {
        dog->bark();
    } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
        cat->meow();
    } else {
        std::cout << "Unknown animal!" << std::endl;
    }
}
int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    makeSound(myDog); // Affiche "Woof!"
    makeSound(myCat); // Affiche "Meow!"

    delete myDog;
    delete myCat;
    return 0;
}
```