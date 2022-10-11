# Semaine 03/16

## Exercice

- Une classe `Blob`
  - Constructeur sans argument
  - Constructeur avec argument
    - Liste d'initialisation `: a(a), b(b) {}`
  - Constructeur par copie
  - Destructeur
  - Méthode
  - Operateur d'assignation

```cpp
std::cout << "La classe Blob a été construite"

int main() {
    Blob b;

}
```

## Most Vexing parse

Note: quand on utilise les accolades on a un check de narrowing ! 
```cpp
class Foo { Foo(int a) : a{a} {} int a;};
int main() {
    Foo a{42}; // Utiliser les accolades pour éviter l'ambiguité
}
```

## Narrowing 

```cpp 
int main() {
    int i(3.14);

}
```


