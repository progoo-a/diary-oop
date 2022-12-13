# Semaine 12/16

- [ ] Les exceptions
- [ ] SFML

## SFML

Quatre options s'offrent à vous :

1. WSL 2 + Windows 11 + Driver GPU (vGPU) (peut-être que ca marche sous windows 10) + SFML
2. Windows 10 + Un compilateur C++ + Bibliothèque SFML
3. Windows 10 + Visual Studio + Bibliothèque SFML
4. Windows 10 + VcXsrv Windows X Server + SFMl

## Tentative d'explication

- On test une partie de programme qui est critique, qui peut faire crasher le programme
- Si le programme crash, on lance un message d'erreur et on le rattrappe
- Quant y'a un try, il va directement chercher un catch

## Pourquoi "evil"

1. L'overhead du à la sauvegarde et à la récupération du context
2. Souvent on les utilisent pour la mauvaise raison
   1. Les exceptions doivent uniquement être utilisées pour des raisons exceptionnelles !
   2. La question difficile : c'est quoi un cas exceptionnel : l'expérience permet de répondre à cette question
3. On risque de tout casser si c'est mal utilisé :
   1. par exemple en multithreading
   2. par exemple avec des pointeurs (on oublie le delete)


## Propagation d'erreur

```c
bool foo(int a) {
    if(a % 3)
        goto error;
    return false;
}

bool bar(int b) {
    return foo();
}
int main() {
    if (bar(42)) {
        printf("Erreur");
    }
    return 0;
    error:
        printf("Erreur");
        exit(EXIT_FAILURE);
}
