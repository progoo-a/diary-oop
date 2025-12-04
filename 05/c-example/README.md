# Semaine 05/16

- [ ] Fichier d'en-tête
- [ ] Introduction au labo

## Hpp

Contrairement au C, le C++ permet de définir des fonctions dans les structures. Ce qu'on appelle des méthodes.

Et il est possible de les mettre dans un fichier d'en-tête.

On trouve régulièrement des projet dit *header-only*. L'avantage est qu'on n'a pas besoin de compiler une bibliothèque séparément. L'inconvénient est que ça peut ralentir la compilation.

Parfois il est nécessaire de séparer la déclaration et la définition. Par exemple pour des raisons de dépendances circulaires.

(voir exemple `screwdriver.cpp`)