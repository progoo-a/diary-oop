# Semaine 02/16

## Visibilité

En C++, la visibilité des membres d'une classe (attributs et méthodes) est contrôlée par des spécificateurs d'accès. Les trois principaux sont :

- `public` : Les membres sont accessibles de n'importe où.
- `private` : Les membres sont accessibles uniquement à l'intérieur de la classe.
- (`protected`) : Les membres sont accessibles dans la classe et dans les classes dérivées.

```cpp
struct Example {
  public:
    int foo;
    int bar;
    void doSomething();

  private:
    int secret;
    void hiddenMethod();
};
```

```cpp
struct Example {
    int foo;
    int bar;
    void doSomething();

  private:
    int secret;
    void hiddenMethod();
};
```

```cpp
class Example {
    int secret;
    void hiddenMethod();

  public:
    int foo;
    int bar;
    void doSomething();

};
```

On constate que par défaut, les membres d'une `struct` sont `public`, tandis que ceux d'une `class` sont `private`. C'est la seule différence entre `struct` et `class` en C++.