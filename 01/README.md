# Semaine 01/16

- Paradigme
  - Impératif
  - Fonctionnel
  - Object-Oriented
  - Procédural
  - Reflectif 
- C++ et ses paradigmes
  - Paradigme Impératif
  - Paradigme Fonctionnel (Lambda, apply, ...)
  - Paradigme Object-Oriented
- Paradigme Objet
  - Objet
  - Classe 

## Classe

Une classe est un modèle ou un plan pour créer des objets. Elle définit les **attributs** (données) et les **méthodes** (comportements) que les objets de cette classe posséderont.

```cpp
struct Point {
    int x; // C'est pas une variable, c'est un attribut
    int y;

    void move(int dx, int dy) { // C'est pas une fonction, c'est une méthode
        x += dx;
        y += dy;
    }

    void display() {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }

    int length() {
        return sqrt(x * x + y * y);
    }
};
```

### Constructeur 

Un constructeur est une méthode spéciale d'une classe qui est appelée lors de la création d'un objet. Il initialise les attributs de l'objet.

```cpp
struct Foo {
    Foo() { // Constructeur par défaut
        std::cout << "Foo created!" << std::endl;    
    }

    ~Foo() { // Destructeur
        std::cout << "Foo destroyed!" << std::endl;    
    }
};
```

## Objet

Un objet est une instance d'une classe. Il regroupe des données (attributs) et des comportements (méthodes) liés à une entité spécifique.

```cpp
Point p1 = {3, 4};
p1.move(2, 3);
p1.display(); // Affiche Point(5, 7)
```

## Flux de données (*stream*)

En C++, un flux de données (ou *stream*) est une abstraction utilisée pour gérer l'entrée et la sortie de données. Les flux permettent de lire et d'écrire des données de manière séquentielle, que ce soit à partir de fichiers, de la console, ou d'autres sources.

## Exercices

### Exercice 1

- Réaliser un programme e C++ qui lit un entier de l'entrée standard et l'affiche sur la sortie standard.
- Vous pouvez modifier la valeur avant de l'afficher, par exemple la doubler.
- Utiliser les flux de données (`std::cin`, `std::cout`).

### Exercice 2

- Réaliser un programme en C++ qui récupère 10 valeurs entières sur l'entrée standard et en calcul la moyenne.
- Ces valeurs seront stockées dans un tableau dynamique (utiliser `std::vector`).

### Exercice 3

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

Voici le main: 

```cpp
int main() {
    Statistics stats;
    for (int i = 0; i < 10; ++i) {
        int value;
        std::cin >> value;
        stats.add(value);
    }

    std::cout << "Average: " << stats.average() << std::endl;
    std::cout << "Min: " << stats.min() << std::endl;
    std::cout << "Max: " << stats.max() << std::endl;
}
```