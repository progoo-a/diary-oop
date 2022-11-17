# Semaine 8/16

- [ ] Templates
- [ ] Objet Attributs
- [ ] Reduce
- [ ] Relations UML

- [ ] Allocation dynamique
- [ ] SMART Pointers

## Objet et attribut

```cpp
class Class {
    int attribute;
};

int main() {
    Class class; // objet;
}
```

## Template

```cpp

class Point {
    int x, y;
    public:
    Point(int x, int y) : x{x}, y{y} {}
    int get_x() { return x; }
    int get_y() { return y; }
};

int main() {
    Point p{3.14, 2.71};
}
```


## Project, Worker, Pen

Implémentez les classes Project, Worker et Pen.
Lorsque Bob travaille, cela affiche à l’écran : Bob is sawing .

```cpp

class Tool { // Classe abstraite : interface, puisque toutes les méthodes sont virtuelles pures
    virtual use() = 0; // Virtuelle pure
};

class Pen : public Tool {
    void use() const override {
        std::cout << "drawing";
    }
}

class Saw : public Tool {
    void use() const override {
        std::cout << "sawing";
    }
}

class Person {
    std::string name;
    public:
    Person(std::string name) name{name} {}
    std::string get_name() const { return name; }
}

class Worker : public Person {
    Tool &tool;
    public:
    Worker(std::string name, Tool &tool) : Person{name}, tool{tool} {}
    void work() {
        std::cout << "Is " << tool.use();
    }
};

class Project {
    std::vector<Worker*> workers;
    public:
    void run() {
        for(auto worker : workers)
            worker->work();
    }
    void add(Worker *worker) {
        workers.push_back(worker);
    }
};

int main() {
    Pen pen;
    Saw saw;

    Worker alice("Alice", pen);
    Worker bob("bob", saw);

    Project project;
    project.add(&alice);
    project.add(&bob);
    project.run();
}
```
