# Semaine 02/16

- Instance (objet)
    ```c 
    typedef struct Biere { char name[32]; } Biere;
    int i;
    Biere plage;
    ```
- Classe
  - Surcharge
  - Héritage 
  - Polymorphisme
- Construire un objet : c'est créer une instance à partir d'une classe
  - Cela appelle le constructeur de la classe.

## Trucs chelous en C++

- Une classe possède toujours: 
  - Un constructeur par défaut, qui est supprimé si d'autres constructeurs sont définis
  - Un constructeur par copie
  - Un opertateur d'assignation, qui est supprimé si d'autres constructeurs sont définis
  - Un destructeur


