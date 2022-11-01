# Semaine 04/16

 - [ ] Héritage
   - [ ] `class Cat : public Animal`
   - [ ] Une flèche blanche pour l'héritage sur un diagramme UML de classe
 - [ ] Surcharge 
   - [ ] Les méthodes visant à être surchargée dans une classe **dérivée** seront marquée `virtual`
   - [ ] Les méthodes surchargeant une classe de **base** seront marquée `override`
 - [ ] Interface et classes abstraites 
   - [ ] `= 0`
## Héritage avec Surcharge 

```cpp
class Base {
  public:
  Base() = default;
  virtual int foo() {}
};
class Child : public Base {
  public: 
  Child() : Base{} {};
  int foo() override {}
}
```

## Exercices

### Exercice 1

- Écrire une class comportant 
  - un attribut public, 
  - un attribut privé
  - un constructeur avec arguments et arguments par défaut
- Dans le main montrer toutes les possibilités de construire un objet.

Durée 10 min. (mais en fait c'était beaucoup plus long)

### Exercice 2

- Écrire une classe d'interface "Animal"
  - Qui contient une méthode "Eat" qui écrit "An animal is eating..."
- Écrire une classe "Cat" qui est un "Animal"
- Écrire une classe "Mouse" qui est un "Animal"

```cpp
int main() {
    Cat cat;
    cat.eat() // Appelle la méthode eat de Animal
}
```