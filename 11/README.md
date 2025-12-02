# Comparaison tokens.cpp vs tokens2.cpp

- **Structure**  
  - `tokens.cpp` : une seule classe `Token` qui mélange nombres et opérateurs via des champs optionnels.  
  - `tokens2.cpp` : hiérarchie (`Token`, `Number`, `Operator`, `Addition`) qui sépare données et comportement.

- **Avantages de tokens.cpp**  
  - Fichier compact, moins de types à maintenir.  
  - Pas de polymorphisme ni d'allocation dynamique : copies directes dans le `std::vector`.  
  - Suffisant pour de très petits exercices ou des scripts rapides.

- **Inconvenients de tokens.cpp**  
  - Logique spécifique (priorité, associativité) entremêlée dans un constructeur générique.  
  - Ouverture à l’erreur : impossible d’empêcher la création d’un opérateur inconnu ou de forcer les champs cohérents.  
  - Difficile à étendre (nouvel opérateur = modifier la classe, viol de l’Open/Closed).  
  - Les données restent publiques (`s`), ce qui empêche de garantir les invariants.

- **Avantages de tokens2.cpp**  
  - Typage clair : `Number` et `Operator` encodent leurs invariants dans leurs constructeurs.  
  - Extensibilité naturelle : ajouter un opérateur revient à dériver `Operator` (ou injecter un functor).  
  - Encapsulation : accès via accesseurs (`getType`, `getSymbol`) et destructeur virtuel.  
  - Comportement porté par les objets (un opérateur sait calculer `apply`), mieux aligné avec l’approche objet.

- **Inconvenients de tokens2.cpp**  
  - Plus de code et de classes à gérer, coût initial plus élevé.  
  - Usage de pointeurs dans `std::vector<Token*>` : nécessite une gestion de durée de vie (raw pointers sûrs ici car objets automatiques).  
  - Nécessite de penser à la virtualisation si on ajoute des méthodes appelées via la base (ici déjà pour le destructeur).

- **Quand choisir l’un ou l’autre ?**  
  - Pour un TP court ou un parseur ultra simple : `tokens.cpp` suffit.  
  - Pour un moteur d’expression extensible ou un code produit : `tokens2.cpp` apporte la séparation de responsabilités et la sécurité de types attendues.
