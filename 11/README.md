# Semaine 11/16

- [ ] Specialisation (pour définir un comportement spécifique à un certain type dans une template)
- [ ] Iterateurs (pour parcourir les éléments)
  - [ ] `std::for_each`
  - [ ] `std::accumulate`
- [ ] C'est quoi un allocateur !
  - [ ] Exemple de l'allocateur par défaut
- [ ] Design Pattern

## Design Pattern (Patron de conception)

- [ ] Singleton
- [ ] Observer
- [ ] Visitor
- [ ] MVC

## Exercices

- 3 groupes de 3 personnes
- 30 minutes de développement
- Le code est publié sur Git
- Un autre groupe récupère le code d'un autre groupe fait des tests et propose un code review

### 1 Strategy

Implémenter le design pattern `strategy` a executer sur un vecteur d'entiers généré depuis l'entrée standard

```console
echo "4 8 15 16 23 42" | ./a.out add
108
```

- Les stratégies disponibles utilisent les algorithmes de la STL si possible
  - Somme
  - Produit
  - Max
  - Min
  - Déviation standard

### 2 Singleton

Implémenter une classe `Storage` permettant de stocker des valeurs dans un fichier. Les éléments sont des paires clés valeurs (`str`, `str`)

- `store(key, value)` Sauve une donnée
- `retrieve(key, value)` Récupère une donnée

A la construction de l'objet les données sont chargée du fichier et un `map` est créé
A la destruction de l'objet les données sont sauvegardées dans le fichier

### 3 Observer

Une classe `User` peut s'abonner à un flux d'information `News`. Lorsqu'une nouvelle est publiée les utilisateurs sont notifiés:

- `User` est un `Subscriber` qui dispose d'une méthode `update()`
- `News` est un `Publisher` qui dispose d'une méthode `subscribe()` et `notifySubscribers()`
- `News` dispose d'une méthode `publish(std::string news)` qui insert une nouvelle information et notifie tous les abonnés.


