# Semaine 04/16

- [ ] Héritage


## Vocabulaire

- **Classe de base**: La classe dont une autre classe hérite.
- **Classe dérivée**: La classe qui hérite d'une autre classe.
- **Méthode virtuelle**: Une méthode dans une classe de base qui peut être redéfinie dans une classe dérivée.
- **Méthode virtuelle pure**: Une méthode virtuelle qui n'a pas d'implémentation dans la classe de base et doit être implémentée dans une classe dérivée.
- **Surcharge de méthode**: La redéfinition d'une méthode virtuelle dans une classe dérivée.
- **Interface**: Une classe qui ne contient que des méthodes virtuelles pures.

## Points importants

- Une classe de base est une **interface** si elle ne contient que des méthodes virtuelles pures (méthodes déclarées avec `= 0`).
- Une méthode virtuelle pure est une méthode qui n'a pas d'implémentation dans la classe de base.
- Une méthode dérivée doit implémenter toutes les méthodes virtuelles pures de la classe de base pour être instanciable.
- Une méthode dérivée est une méthode qui surcharge une méthode virtuelle de la classe de base.