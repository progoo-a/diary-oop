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

## Exercice 

- Réaliser un programme en C++ qui récupère 10 valeurs entières sur l'entrée standard et en calcul la moyenne.
- Ces valeurs seront stockées dans un tableau dynamique (utiliser `std::vector`).