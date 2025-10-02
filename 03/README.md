# Semaine 03/16

- Références `&`
  - C'est comme un pointeur mais la valeur ne peut pas être `nullptr`
  - Utile pour passer des paramètres par référence (évite la copie)
  - Utile pour les opérateurs (évite la copie)
  - On garde la sémantique de l'objet (pas besoin de déréférencer (`->`)
  - **Attention**: ne pas l'oublier quand on peut éviter une copie inutile
- Membres par défaut d'une classe (6)
  - Constructeur par défaut (sans paramètres)
    - `T() = default`
  - Constructeur par copie (paramètre de type `const T&`)
    - `T(const T&) = default`
  - Opérateur d'affectation (paramètre de type `const T&`)
    - `T& operator=(const T&) = default`
  - Destructeur
    - `~T() = default`
  - Opérateur d'affectation par déplacement (paramètre de type `T&&`)
    - `T& operator=(T&&) = default`
  - Constructeur par déplacement (paramètre de type `T&&`)
    - `T(T&&) = default`
- Surcharge extérieure (p.ex. `operator<<`)
  - Doit être amie de la classe si elle accède aux membres privés
    - `friend std::ostream& operator<<(std::ostream&, const T&);`
  - Doit être définie en dehors de la classe
    - `std::ostream& operator<<(std::ostream& os, const T& obj) { ... }`
  
## Exercice

- Créer une classe Point avec deux attributs x et y
- Créer un constructeur pour initialiser les attributs
- Créer un constructeur par copie explicite 
- Créer les surcharges nécessaires (+, -, <<) pour ajouter des points, les soustraire et les afficher.
- Consigner chaque appel sur la sortie standard (ex: "Constructeur par copie appelé")

```cpp
int main() {
    Point p(1,2);
    Point q = p; // Appel du constructeur par copie
    Point r; // Constructeur sans paramètres
    r = p + q; // Appel de l'opérateur +
    std::cout << r << std::endl; // Affichage du point r
}