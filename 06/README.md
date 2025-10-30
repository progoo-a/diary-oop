# Semaine 06/16

- [ ] Polymorphisme statique avec les templates
- [ ] Polymorphisme dynamique avec les méthodes virtuelles
- [ ] Virtual vs Virtual pure
- [ ] Vtable et overhead mémoire
- [ ] Exercice: Animaux polymorphes

## Types de polymorphismes

### Polymorphisme statique

La surcharge paramétrique: 

```cpp
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

add(42, 3.14); // Erreur: ne sait pas résoudre l'appel
add(3,4); // OK
```

Les templates:

```cpp
template <typename T>
T add(T a, T b) { return a + b; }

add(42, 3.14); // Erreur: ne sait pas résoudre l'appel
add<int>(42, 3.14); // OK: force T à être int
```

## Théorie

Le polymorphisme dynamique est un concept clé de la programmation orientée objet qui permet à une méthode d'avoir plusieurs implémentations en fonction du type d'objet qui l'appelle. En C++, cela est généralement réalisé à l'aide de méthodes virtuelles.

## Rappels

### Constantes

En C comme en C++ le mot clé `const` ne permet pas de créer une "constante" au sens strict du terme. Il permet de déclarer des variables dont la valeur ne peut pas être modifiée après leur initialisation.

```cpp
const int MAX_SIZE = 100; 
```

En C++ il est également possible de définir des constantes au niveau de la classe avec `constexpr`.

```cpp
class MyClass {
   static constexpr int VALUE=10;
};
```

### Interfaces

Une interface est une classe comportant uniquement des méthodes virtuelles pures (méthodes sans corps) et des constantes. Elle définit un contrat que les classes dérivées doivent respecter en implémentant toutes les méthodes déclarées dans l'interface.

### Virtual 

Le mot clé virtual demande au compilateur de stocker avec l'instance une table de pointeurs vers les fonctions virtuelles (vtable). Cela permet de déterminer à l'exécution quelle méthode doit être appelée en fonction du type réel de l'objet pointé, et non du type du pointeur.

L'inconvénient est que chaque instance d'une classe avec des méthodes virtuelles occupe plus de mémoire (pour stocker la vtable) et que l'appel aux méthodes virtuelles est légèrement plus lent (car il nécessite une indirection via la vtable).

### Terminologie

Une **méthode** est une fonction membre d'une classe. Elle manipule l'état de l'objet auquel elle appartient et s'appelle sur une instance (ou statiquement pour une `static`).

Une **méthode virtuelle** (mot clé `virtual`) est une méthode dont la résolution se fait dynamiquement à l'exécution. Lorsqu'on l'appelle via un pointeur ou une référence vers la classe de base, le type réel de l'objet détermine la version exécutée.

Une **méthode virtuelle pure** s'écrit avec `= 0` dans la déclaration (`virtual void speak() = 0;`). Elle n'a pas d'implémentation dans la classe de base et oblige les classes dérivées à fournir leur propre définition. Une classe contenant au moins une méthode virtuelle pure est abstraite et ne peut pas être instanciée.

Différences principales :
- méthode classique : résolution statique, pas de surcoût, disponible dans toutes les classes simples ;
- méthode virtuelle : résolution dynamique via la vtable, permet le polymorphisme à l'exécution ;
- méthode virtuelle pure : introduit un contrat obligatoire pour les classes dérivées et rend la classe de base abstraite.

## Exercice : Polymorphisme

Créer une **interface** `Animal` avec une méthode `speak`/`eat`.
Créer des classes dérivées comme `Dog`, `Cat` qui implémentent l'interface `Animal`.

Créer une collection de N d'animaux aléatoire et itérer dessus pour appeler la méthode `speak`/`eat` de chaque animal.
