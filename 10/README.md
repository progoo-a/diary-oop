# Semaine 10/16

- [ ] STL
- [ ] Hmap

## STL

- La STL est composées de Templates
- La STL = Standard Template Library
- Elle contient des containers
  - Associatifs (map, unordered_map)
  - Sequentiels (array, vector, list)

## Hashage

Une fonction de hachage est une transformation non bijective
d'un ensemble de départ très grand à un ensemble d'arrivée plus petit.

Fonction de hachage usuelles :

- MD5
- SHA256 (`sha256sum`)
- SHA512

Exemple d'un programme de chiffrement très efficace
utilisant une table de hachage (correspondance lettre vers lettre).

```c
char m[] = "xyhpmkoicbrnafsuegvljqwdzt";
char text[] = "bonjour";

for (int i = 0; i < strlen(text); i++) {
    printf("%c", m[text[i] - 'a']); // O(1)
}
```

On peut stocker des valeurs plus complexes comme des contacts:

```cpp
Contact* phone[] = {{793452367, "John Doe"}, {781123467, "Bob"}, {769874542, "Alice"}}

phone[769874542 % 10]
```

On peut faire l'inverse mais il faut alors convertir le nom
en un indice de tableau. Par exemple avec une fonction chksum
name[h(contact.name) % 10]

```cpp
int32_t checksum(std::string text) {
    int32_t chk = 0;
    int32_t i = 0;
    for (auto &c : text) {
        chk ^= c + (i++);
    }
    return chk;
}
```

## DB

Dans une base de données les mots de passe sont jamais stockés
en clair, ils sont haché avec une fonction non bijective.

User
  - name
  - id
  - email
  - password    ababdbebfbb3b3b1babdbe

```c
assert(h("secret") == "ababdbebfbb3b3b1babdbe")
```
