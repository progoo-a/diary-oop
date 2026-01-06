
```cpp
class C {
    C() = default;  // Réactiver le constructeur par défaut
    C() = delete;   // Supprimer le constructeur par défaut
    C(int a) {}
}

int main() {
    C c;
}
```

## Problème 2

### a

Donner un exemple d'interface en C++ possédant une méthode et une classe qui la réalise: 

```cpp
class Animal {
    virtual void speak() = 0;
};

class Cat : public Animal {
    void speak() override {}
};
```

Une interface animal possède une méthode virtuelle pure speak rendant cette classe abstraite. Une autre classe Cat réalise cette interface en surchargeant la méthode virtuelle pure speak avec le mot clé override.

### b

Citez trois patrons de conception que vous connaissez et expliquez brièvement leur utilité.

1. **Singleton**: est un mécanisme permettant d'éviter la constrution multiple d'une classe en rendant son constructeur privé. Par exemple pour avoir une référence sur une seule base de données utilisées dans le code.

```cpp
class DB {
    private:
    DB();

    public: 
    DB get_instance() {
        if (instance == null) {
            instance = new DB();
        }
        return instance;
    }

    private:
    DB *instance;
}
```

2. MCV (Modèle, Contrôleur, Vue). Dans un site internet par exemple, on a le modèle de données, c'est la base données, la liste des utilisateurs. On a le contrôleur qui gère la logique d'accès au modèle par la vue. On a la vue qui est la couche de présentation des données, souvent ce qui est affiché dans le navigateur. Par exemple dans un jeu de démineur, le modèle contient la grille et les attributs de chaque cellule, le contrôleur gère la logique de jeu et la vue gère l'affichage pour l'utilisateur.

3. Strategy. Permet d'encapsuler des algorithmes dans des classes. Par exemple: On a une base de données et on aimerait plusieurs types de filtres différents. 


```cpp
#include <iostream>
#include <vector>
#include <string>

struct Filter {
    virtual bool search(const std::string& name, int age) const = 0;
};

class FilterByMinAge : public Filter {
    int minAge;
public:
    FilterByMinAge(int age) : minAge(age) {}
    bool search(const std::string&, int age) const override {
        return age >= minAge;
    }
};

class FilterByName : public Filter {
    std::string wanted;
public:
    FilterByName(const std::string& name) : wanted(name) {}
    bool search(const std::string& name, int) const override {
        return name == wanted;
    }
};

// -------- Context --------
class Database {
    std::vector<std::pair<std::string, int>> data{
        {"Alice", 30},
        {"Bob", 20},
        {"Charlie", 40}
    };

public:
    void query(const Filter& filter) const {
        for (const auto& [name, age] : data) {
            if (filter.search(name, age)) {
                std::cout << name << " (" << age << ")\n";
            }
        }
    }
};

// -------- Usage --------
int main() {
    Database db;

    FilterByMinAge ageFilter(25);
    FilterByName nameFilter("Bob");

    std::cout << "Age >= 25:\n";
    db.query(ageFilter);

    std::cout << "\nName == Bob:\n";
    db.query(nameFilter);
}
```

#### Autres patrons de conceptions

- Observer*
- Visiteur*
- Modèle Vue Contrôleur
- Singleton*
- Strategy

### c

Soit une collection de vecteurs 2D. Comment calculer la somme de tous les vecteurs de cette collection en utilisant `std::for_each()` ?

```cpp
std::vector<int> data({1,2,3,4,5,6,7});

std::for_each(data.begin(), data.end(), [](int el){ return el * 10});

int sum = 0;
std::for_each(data.begin(), data.end(), [&sum](int el) { sum += el });
```

### d

On souhaite créer un réseau de neurones simple. Chaque neurone possède un poids `weight`qui est un nombre réel. Le neurone possède une référence vers son neurone parent, celui qui est connecté à lui. Il possède également des pointeurs vers ses neurones enfants. Il possède jusqu'à 8 enfants. Écrire la classe `Neuron`qui représente un neurone telle qu'elle est décrite ci-dessus. Ne pas oublier le constructeur.

```cpp
class Neuron {
    double weight;
    Neuron &parent;
    std::array<std::unique_ptr<Neuron>, 8> children;
    public:
    Neuron(Neuron &parent) : parent{parent} {}
};
```

Il serait préférable d'avoir un pointeur vers le parent et non référence afin de pouvoir créer une racine à notre arbre.

## Exemple Django MCV

Voici un **mini-exemple MVC/MCV** (en Django on parle plutôt de **MTV** : *Model–Template–View*, mais l’idée “séparation des rôles” est la même). Objectif : **le minimum de lignes** pour voir comment tout s’emboîte.

## 1) Modèle (M) — `app/models.py`

```python
from django.db import models

class Post(models.Model):
    title = models.CharField(max_length=100)
```

## 2) Vue / Contrôleur (V/C) — `app/views.py`

* En Django, la “View” fait souvent le rôle de contrôleur (récupère les données, décide quoi afficher).

```python
from django.shortcuts import render
from .models import Post

def home(request):
    return render(request, "home.html", {"posts": Post.objects.all()})
```

## 3) Template (T) — `app/templates/home.html`

```html
<h1>Posts</h1>
<ul>
  {% for p in posts %}<li>{{ p.title }}</li>{% empty %}<li>Rien</li>{% endfor %}
</ul>
```

## 4) Routing — `app/urls.py`

```python
from django.urls import path
from .views import home

urlpatterns = [path("", home)]
```

## 5) Brancher l’app — `project/urls.py`

```python
from django.urls import path, include

urlpatterns = [path("", include("app.urls"))]
```

### Comment ça circule (MCV)

1. **URL** `/` → `home` (routing)
2. `home` récupère les **données** via `Post.objects.all()` (Model)
3. `home` rend `home.html` avec `posts` (Template)

---

### Pour le faire tourner (ultra court)

```bash
django-admin startproject project
cd project
python manage.py startapp app
```

Dans `project/settings.py` ajoute `app` dans `INSTALLED_APPS`, puis :

```bash
python manage.py makemigrations
python manage.py migrate
python manage.py runserver
```

---

Si tu veux, je peux te donner une version encore plus “compacte” (sans base de données : juste une liste en dur) pour comprendre le flux **sans migrations**.
