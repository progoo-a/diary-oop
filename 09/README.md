# Semaine 09/16

- [ ] Smart pointers
- [ ] STL
- [ ] Labo

## Exercices

### Unique ptr

Soit :

- Une classe qui contient une tâche (TODO)
  - Description (chaîne de caractère)
  - Priorité (urgent, normal, bas) : type enumération C++
- File d'attente qui contient toutes les tâches (uniqueptr)
  - Container de la STL : deque

Démontrer avec petit programme que l'on peut ajouter des tâches dans la file d'attente
Et que ces objets sont supprimés convenablement lorsqu'ils ne sont plus utilisés

### Animaux

Soit :

- Une interface `Shape` représentant une forme géométrique et disposant de:
  - `area() : double`
  - `center() : pair<double, double>`
  - `get_num_points(): int` Nombre de points de la forme
  - `move(x: double, y: double)` Pour déplacer la forme
- Un carré `Square` et un triangle `Triangle` dérivent de `Shape`
  - `Square(x: double, y: double, edge: double)`
  - `Triangle(x: double, y: double, edge: double)`

Réaliser un conteneur de formes contenant des formes en utilisant `sharedptr`.
Puisque les objets à stocker sont polymorphiques, ils ne peuvent être stockés que par pointeurs.
Démontrer le fonctionnement dans le main.

```cpp
std::vector< std::shared_ptr<Shape> > shapes
```
