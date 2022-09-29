# Semaine 02/16

- [x] Flux
  - [x] `<<` `>>`
  - [x] `cin`, `cout`, `cerr`
  - [x] `cin.getline()`, `getline`
  - [x] `cin.ignore(1, '#')`
  - [x] `cin.peek()`
  - [x] `cin.putback('a')`
- [x] Fichier
  - [x] `#include <ifstream>`
- [ ] Namespace
  - [ ] Des containers à choses... On les accèdent avec ::
- [ ] Classes et les structures
  - [ ] `class` : tout est privé par défaut
  - [ ] `struct` : tout est public par défaut

```c++
int main() {
  int u;
  std::cout << "Hello" << std::endl << std::endl;
  std::cin >> u;
}
```
- Instance (objet)
    ```c 
    typedef struct Biere { char name[32]; } Biere;
    int i;
    Biere plage;
    ```
- Classe
  - Surcharge
  - Héritage 
  - Polymorphisme
- Construire un objet : c'est créer une instance à partir d'une classe
  - Cela appelle le constructeur de la classe.

## Trucs chelous en C++

- Une classe possède toujours: 
  - Un constructeur par défaut, qui est supprimé si d'autres constructeurs sont définis
  - Un constructeur par copie
  - Un opertateur d'assignation, qui est supprimé si d'autres constructeurs sont définis
  - Un destructeur


