typedef struct Point {
    int x; 
    int y;
    // Pointeur de fonction
    struct Point (*add)(struct Point self, struct Point other);
} Point;

/* En C la fonction doit être séparée, elle n'a pas de lien
 * avec la structure (classe), c'est parce que le C n'est pas objet
 * il ne supporte pas ce paradigme de programmation.
 */
struct Point point_add(struct Point self, struct Point other) {
  return (Point){.x = self.x + other.x, .y = self.y + other.y};
}

int main() {
    Point a,b,c;
    c = a.add(a, b);
}