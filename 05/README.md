# Semaine 05/16

## Excercice 

Faire un diagramme d'architecture pour un parking de véhicule.

## Héritage de classes

- `public` : tout le monde peut accéder aux méthodes et attributs
- `protected` : même chose que privé, mais les classes dérivées peuvent accéder aux méthodes et attributs
- `private` : personne de l'extérieur de la classe ne peut accéder aux méthodes et attributs

## Héritage avec méthode virtuelle

```cpp
class Base {
    public:
    Base() : {}
    virtual void foo() { }
    ~Base() {}
}

class Derived : public Base {
    public: 
    Derived() : Base{} {}
    void toto() {}
    void foo() override {} // Je surcharge la méthode de la classe Base
}
```

## Prototype

```cpp
# .h
class Base {
    public: 
    virtual void foo();
}
# .c
Base::foo() {

}
```

## Prototype

```cpp
class Vehicule {
    public: 
    virtual void horn() = 0; // Méthode virtuelle "PURE"
}

class Lambo : public Vehicule {
    public:
    void horn() override {
        ...
    }
}
```

## Exemple de la table pour la liste d'appel

Notation hongroise pour les interfaces est courante : `IFormatter`. 

```cpp
// Lorsqu'une classe ne contient que des méthodes virutelles pures, c'est une interface.
class GenericTableFormatter {
    public: 
    virtual void addRow() = 0;
    virtual void addColumn() = 0;
    virtual void display() = 0;
};

class TableFormatter : public GenericFormatter {
    void addRow();
    void addColumn();
    void display() {
        cout << '-----'
    }
}

class ExcelFormatter : public GenericFormatter {
    void addRow();
    void addColumn();
    void save() {
        cout << '-----'
    }
}
class List {
    private: 
    GenericFormatter *table;
    //void attacheTable(GenericFormatter &table);
    List() {
        table = new TableFormatter;
    }
    void display() {
        table.display;
    }
}

class ExcelList: public List {
    MyList() {
        table = new ExcelFormtter;
    }
}

class List {
    private: 
    GenericFormatter *table;
    //void attacheTable(GenericFormatter &table);
    List(GenericFormatter *formatter) : table{formatter} {
       
    }
    void display() {
        table.display;
    }
}

list = List(new ExcelFormatter(2022));

```

- Driver Model 
  - File
  - StaticArray
  - Vector
  - List
  